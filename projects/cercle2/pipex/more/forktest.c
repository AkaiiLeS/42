#include <unistd.h>
#include <stdio.h>

//int main(void)
//{
    //pid_t pid;
    //printf("Je viens de fork\n");
    //pid = fork();
//
    //if (pid == -1)
        //return (1);
    //else if (pid == 0)
            //printf("Je suis le fils et mon pid est %d\n", pid);
    //else if (pid > 0)
            //printf("je suis le pere et mon pid est %d\n", pid);
    //return (0);
//}

//void    appel_fils(pid_t pid, int *nb)
//{
    //printf("Je suis le fils. Mon PID recu de fork est %d\n", pid);
    //printf("Le nombre est %d\n", *nb);
//}
//
//void    appel_pere(pid_t pid, int *nb)
//{
    //printf("Je suis le pere. Mon PID recu de fork est %d\n", pid);
    //printf("Le nombre est %d\n", *nb);
    //*nb *=2;
    //printf("Le nombre modifiee est %d\n", *nb);
//}
//
//int main(void)
//{
    //pid_t   pid;
    //int nb;
//
    //nb = 42;
    //printf("Avant de fork nb est egal a %d\n", nb);
    //pid = fork();
    //if (pid == -1)
        //return (1);
    //else if (pid == 0)
            //appel_fils(pid, &nb);
    //else if (pid > 0)
            //appel_pere(pid, &nb);
    //return (0);
//}

//#include <fcntl.h>
//#include <stdio.h>
//#include <unistd.h>
//
//int main(void)
//{
    //pid_t pid;
//
    //pid = fork();
    //if (pid == -1)
       //return (1);
    //if (pid == 0)
    //{
        //printf("Fils, pid = %d. \n", pid);
        //sleep(1);
        //printf("process fils terminé\n");
    //}
    //else if (pid > 0)
    //{
        //printf("Père,  pid = %d\n", pid);
        //printf("process père terminé\n");
    //}
    //return (0);
//}
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
        printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
        printf("Fils : Termine !\n");
    }
    else if (pid > 0)
    {
        printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
        while (1) // Boucle infinie, le père ne termine jamais !
            usleep(1);
    }
    return (0);
}
