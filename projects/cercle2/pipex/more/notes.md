#   Pipex

## Qu’est ce qu’un processus ?

 Les programmes qu'on fait c’est un ensemble d’instructions et d’opérations qui vont être exec par l’ordinateur. Ce programme est save sur un DD et est en « sommeil », il ne fait rien. Quand un programme s’execute , via une commande shell, sur lequel on double clic, ou qui s’execute automatiquement au démarrage, le système charge les instructions sur la RAM et les executes les unes après les autres. Quand ce programme est en cours d’executions, on l’appel « processus ».

Un programme est sur DD, un process sur memoire vive (RAM).

L’OS gère tout les process et alloue a chaque process une zone de la memoire vive; sa propre stack, sa propre heap, sont propre ptr d’instruction etc. Ca veut dire qu’un process va difficilement avoir  accès à la mémoire ou aux instructions d’un autre process. Chaque process est donc une entité distincte.

### Hiérarchie des process.

Si on lance la commande ps -e , on peut voir tous les process actifs sur un système Unix. On peut voir que chaque process à un PID (Process IDentifier)
C’est un entier positif unique a chaque processus. On peut voir le pid de n’importe quel process avec ‘’pidof’’
Mais ce n’est pas le seul pid que possède les process. Ils ont aussi le PPID(Parent Process IDentifier), qui fait référence à leur processeur père. Par example, on peut voir le PID et le PPID du shell de notre terminal avec la commande : echo ‘’PID = $$; PPID = $PPID’’

### Les process sont organisés de manière hiérarchique avec :

* Des processus père ( parent), qui engendrent des processus fils.
* Des processus fils (child) crées par leur processus père et qui peuvent à leur tour engender d’autres fils.

Quand on lance la commande ls dans le terminal, le process shell créer un process fils qui va exec le programme ls. Si le shell exécutait directement le programme ls sans créer de fils, le process ls remplacerait celui de shell, et on pourrait plus rien faire dans le shell.

Au démarrage d’un système Unix, il n’y a qu’un seul process, « init », qui a le PID 1. Celui ci est le parent direct ou indirect de tous les autres processus lancés sur le système.

## FORK : Donner naissance à un processus fils

L’appel système « fork » va permettre au process courant de donner naissance à un nouveau processus qui sera sa copie conforme et qui sera exécuté en parallèle. Notre processus sera donc le père du nouveau process fils. Le nom même de la fonction, fork fait référence à la fourche d’un arbre généalogique.

Le prototype de fork de la bibliothèque <unistd.h> est le suivant
```c
pid_t fork(void);
```

### Différencier processus père et fils

Le fils est un clone du parent, il va donc avoir exactement le même code que le process père. Pourtant, on va souvent vouloir donner des instructions differentes au fils. La valeur de retour de fork est un nombre de type pid_t, et le père retourne une voleur différente du fils, c’est comme ça qu’on fera la différence. Les valeurs de retour possibles sont:


* Le père reçoit en retour le PID du fils,
* Le fils reçoit 0,
* Et en cas d’erreur, fork renvoie -1.

Donc, si on voit 0 comme retour du fork, c’est le process fils, si on voit un PID (nombre suppérieur à 0), on sait que c’est le père. Il faut aussi savoir que le fils reçoit le ptr d’instruction (‘’programme counter’’ ou ‘’instruction pointer’’) du père. Le pointeur d’instruction, c’est un registre qui contient l’adresse mémoire de l’instruction en cours d’exécution. Il est automatiquement incrémenté pour pointer sur l’instruction suivante. Cela veut dire que quand on fork le fils, il en sera au même endroit dans le code que le père : le fils ne recommences pas toutes les instructions depuis le début !!

Comme dit avant, le fils est la copie conforme du père, au moment de la création du fils les deux process sont parfaitement identique, même code, memes FD, même données en memoire etc. Mais cette mémoire, même si identique, n’est pas partagée entre les process. Ça veut dire que si le process père change la valeur d’une variable après avoir créé son process fils, le fils ne verra pas le changement s’il consulte la même variable.

Avec un code assez simple on peut voir que le fils ne voit pas les changement qui s’opèrent dans le process père.

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    appel_fils(pid_t pid, int *nb)
{
    printf("Je suis le fils. Mon PID est %d\n", pid);
    printf("Le nombre est %d\n", *nb);
}

void    appel_pere(pid_t pid, int *nb)
{
    printf("Je suis le père. Mon PID est %d\n", pid);
    printf("Le nombre est %d\n", *nb);
    *nb *=2;
    printf("Le nombre modifiee est %d\n", *nb);
}

int main(void)
{
    pid_t   pid;
    int nb;

    nb = 42;
    printf("Avant de fork nb est egal a %d\n", nb);
    pid = fork();
    if (pid == -1)
        return (EXIT_FAILURE);
    else if (pid == 0)
            appel_fils(pid, &nb);
    else if (pid > 0)
            appel_pere(pid, &nb);
    return (EXIT_SUCCESS);
}
```
On aurrait un retour dans ce genre
```Avant de fork nb est egal a 42
Je suis le père. Mon PID recu de fork est 30818
Le nombre est 42
Le nombre modifiee est 84
Je suis le fils. Mon PID recu de fork est 0
Le nombre est 42
```
On double la valeur du processus  père, mais le fils imprime l'ancienne valeur ce qui montre bien
que l'adresse mémoire des deux process n'est pas partagée, donc il ne sait pas ce qui passe chez le
père.

Il y a des moyens pour permettre la communication entre les process, avec les pipes notamment, les
semaphores et les signaux. Mais le process fils peut communiquer avec son père pour lui dire qu'il a
mis fin a son process, mais pour ca il faut savoir ce que le père attends de ses fils.

### Wait

Le process père ne s'occupe pas forcement de ses fils (meme en code les pères c'est des chiens des
fois). On peut voir dans cet exemple comment le process fils est forcé à attendre 1 seconde avant de
terminer, par contre le process père lui peut finir immédiatement.

```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
       return (1);
    if (pid == 0)
    {
        printf("Fils, pid = %d. \n", pid);
        sleep(1);
        printf("process fils terminé\n");
    }
    else if (pid > 0)
    {
        printf("Père,  pid = %d\n", pid);
        printf("process père terminé\n");
    }
    return (0);
}
```
On a un retour assez bizzare:
```
Père,  pid = 30977
process père terminé
Fils, pid = 0.
➜  more git:(main) ✗ process fils terminé
```
On a la nouvelle ligne d'invit de commande avant la fin du process fils. Ça c'est parce que le shell
est focus sur le process père (qui est son fils), et attends donc la fin du process père, il ne se
soucie pas du process fils (petit-fils du shell). Donc, le père se termine sans attendre son fils,
le fils devient donc un *process orphelin*.Le process *init* adopte cet orphelin (sont PPID devient 1)
et il est éliminé du système instantanément.

### Comment éviter les mort-vivants ?

Un *processus zombie*, c'est un proces qui  a terminé sa tâche mais qui rest présent en attendant que
le père viennent le voir. Le système par contre il attend pas, il va désalloué ses ressources (code, données,
pile d'exécution) sans attendre que le père prenne en compte la situation du fils (décidemment il
est vraiment nul se daron), mais il va conserver son bloc de contrôle, dont le PID.

En soi, c'est pas si d'avoir un zombie, tant que le procces P réceptionne son état. Le zombie ne
consomme pas d'énergie, pas de place dans la mémoire, et s'ils deviennent orphelins ils sont automatiquement
éliminés par **init** qui devient le père adoptif. **PAR CONTRE**, si le père est un process qui
prend beaucoup de temps pour s'arrêter, ou même qui ne termine jamais (serveurs, etc.) et qu'il
engendre des fils sans jamais attendre le retours, la table des proccessus du système va saturer, ce
qui va bloquer le système, et donc il ne pourra plus créer de nouveaux process.

Donc faudrait que ce proccess P s'occupe un peu de ses fils ! Pour ça il faut utiliser les appels
système wait et waitpid.

### Wait et Waitpid:

Pour mettre en pause l'exec du proccess P

