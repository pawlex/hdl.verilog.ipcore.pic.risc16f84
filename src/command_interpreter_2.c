void func_aa(char args[11]);
void func_cc(char args[11]);
void func_xy(char args[11]);

struct command {
    char *name;
    void (*cmd_func)(char args[11]);
} command_tbl[] = {
    { "AA", func_aa },
    { "CC", func_cc },
    { "XY", func_xy }
};

#define N_CMDS (sizeof command_tbl / sizeof command_tbl[0])

static int comp_cmd(const void *c1, const void *c2)
{
    const struct command *cmd1 = c1, *cmd2 = c2;

    return memcmp(cmd1->name, cmd2->name, 2);
}

static struct command *get_cmd(char *name)
{
    struct command target = { name, NULL };

    return bsearch(&target, command_tbl, N_CMDS, sizeof command_tbl[0], comp_cmd);
}

Then if you have command_str pointing to a string from the serial port, you'd do this to dispatch the right function:

struct command *cmd = get_cmd(command_str + 1);

if (cmd)
    cmd->cmd_func(command_str);
