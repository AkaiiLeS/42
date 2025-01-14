
return {
    {
        "L3MON4D3/LuaSnip",
        -- follow latest release.
        version = "v2.*", -- Replace <CurrentMajor> by the latest released major (first number of latest release)
        -- install jsregexp (optional!).
        build = "make install_jsregexp",

        dependencies = { "rafamadriz/friendly-snippets" },

        config = function()
            require("luasnip.loaders.from_vscode").lazy_load()
--            require("luasnip").add_snippets("c", {
--                s("main", {
--                    t("int  main(int ac, char **av) {"),
--                    t({"", "\t"}),
--                    i(0),
--                                   t({"", "\treturn (0);", "}"}),
--                }),
--            })
        end,
   },
}
