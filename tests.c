#include "minishell.h"

t_cmds test1()
{

//sleep 3 | cat << i | ls >> file.txt
    t_cmds *cmd1 = malloc(sizeof(t_cmds));
    cmd1->cmps = (char *[]){"sleep", "3", NULL};
    cmd1->input = 0; // stdin
    cmd1->output = -1; // pipe will be created later
    cmd1->pid = -1;
    cmd1->enum_cmd = PIPE;  // because `sleep 3 |`
    cmd1->redirction = NULL;

    // -----------------------------

    t_cmds *cmd2 = malloc(sizeof(t_cmds));
    cmd2->cmps = (char *[]){"cat", NULL};
    cmd2->input = -1;  // input will be set to the heredoc
    cmd2->output = -1; // pipe to next
    cmd2->pid = -1;
    cmd2->enum_cmd = HERE_DOC;  // << i

    t_redir_s *redir2 = malloc(sizeof(t_redir_s));
    redir2->file_name = "i";   // limiter for heredoc
    redir2->type = HER_DOC;
    redir2->fd = -1;  // will be set when creating heredoc temp file
    redir2->next = NULL;

    cmd2->redirction = redir2;
    cmd1->next = cmd2;

    // -----------------------------

    t_cmds *cmd3 = malloc(sizeof(t_cmds));
    cmd3->cmps = (char *[]){"ls", NULL};
    cmd3->input = -1;  // will receive from previous pipe
    cmd3->output = -1; // will be set to the fd of file.txt
    cmd3->pid = -1;
    cmd3->enum_cmd = REDIR;  // >> file.txt

    t_redir_s *redir3 = malloc(sizeof(t_redir_s));
    redir3->file_name = "file.txt";
    redir3->type = APPEND;   // >> means append
    redir3->fd = -1;         // will be set when open()
    redir3->next = NULL;

    cmd3->redirction = redir3;
    cmd2->next = cmd3;
    cmd3->next = NULL;
    return (cmd1);
}

t_cmds test0()
{
    //ls > file.txt > ii | cat file.txt 
	t_cmds *cmd1 = malloc(sizeof(t_cmds));
	cmd1->cmps = ["ls", NULL];  // command and arguments
	cmd1->input = 0;           // default input (stdin)
	cmd1->output = -1;         // will change to file descriptor of file.txt
	cmd1->pid = -1;            // not executed yet
	cmd1->enum_cmd = REDIR;    // has a redirection
	//////////////////////////////////////////----------->>>>>>>>
	t_redir_s *redir1 = malloc(sizeof(t_redir_s));
	redir1->file_name = "file.txt";
	redir1->type = OUTPUT;   // because of >
	redir1->fd = -1;         // will be set after `open()`
	redir1->next = NULL;
	//////////////////////////////////////////-------------->>>>>>
	t_cmds *cmd2 = malloc(sizeof(t_cmds));
	cmd2->cmps = ["cat", "file.txt", NULL];  // command and arguments
	cmd2->input = -1;        // input will come from the PIPE
	cmd2->output = 1;        // stdout
	cmd2->pid = -1;          // not executed yet
	cmd2->enum_cmd = PIPE;   // because this is part of a pipeline
	cmd2->redirction = NULL; // no redirection here
	cmd2->next = NULL;
	//////////////////////////////////////////-------------->>>>>>>
	cmd1->redirction = redir1;
	cmd1->next = cmd2;  // link to next command
    return (cmd1);
}
t_cmds test3()
{
//ls <> file.txt | rev << i << jj << jj | cat < file.txt | echo hello world > file2.txt
    // First Command: ls <> file.txt
t_cmds *cmd1 = malloc(sizeof(t_cmds));
cmd1->cmps = (char *[]){"ls", NULL};
cmd1->input = 0; // stdin or will be replaced by file
cmd1->output = -1;
cmd1->pid = -1;
cmd1->enum_cmd = REDIR;
t_redir_s *redir1 = malloc(sizeof(t_redir_s));
redir1->file_name = "file.txt";
redir1->type = INPUT;  // first part of <>
redir1->fd = -1;
t_redir_s *redir1_out = malloc(sizeof(t_redir_s));
redir1_out->file_name = "file.txt";
redir1_out->type = OUTPUT;  // second part of <>
redir1_out->fd = -1;
redir1_out->next = NULL;
redir1->next = redir1_out;
cmd1->redirction = redir1;
// -----------------------------------------
// Second Command: rev << i << jj << jj
t_cmds *cmd2 = malloc(sizeof(t_cmds));
cmd2->cmps = (char *[]){"rev", NULL};
cmd2->input = -1;
cmd2->output = -1;
cmd2->pid = -1;
cmd2->enum_cmd = HERE_DOC;

t_redir_s *r2_1 = malloc(sizeof(t_redir_s));
r2_1->file_name = "i";
r2_1->type = HER_DOC;
r2_1->fd = -1;

t_redir_s *r2_2 = malloc(sizeof(t_redir_s));
r2_2->file_name = "jj";
r2_2->type = HER_DOC;
r2_2->fd = -1;

t_redir_s *r2_3 = malloc(sizeof(t_redir_s));
r2_3->file_name = "jj";
r2_3->type = HER_DOC;
r2_3->fd = -1;
r2_3->next = NULL;

r2_2->next = r2_3;
r2_1->next = r2_2;
cmd2->redirction = r2_1;

cmd1->next = cmd2;
// ------------------------------------------
// Third Command: cat < file.txt
t_cmds *cmd3 = malloc(sizeof(t_cmds));
cmd3->cmps = (char *[]){"cat", NULL};
cmd3->input = -1;
cmd3->output = -1;
cmd3->pid = -1;
cmd3->enum_cmd = REDIR;

t_redir_s *r3 = malloc(sizeof(t_redir_s));
r3->file_name = "file.txt";
r3->type = INPUT;
r3->fd = -1;
r3->next = NULL;

cmd3->redirction = r3;
cmd2->next = cmd3;
// ------------------------------------------
// Fourth Command: echo hello world > file2.txt
t_cmds *cmd4 = malloc(sizeof(t_cmds));
cmd4->cmps = (char *[]){"echo", "hello", "world", NULL};
cmd4->input = -1;
cmd4->output = -1;
cmd4->pid = -1;
cmd4->enum_cmd = REDIR;

t_redir_s *r4 = malloc(sizeof(t_redir_s));
r4->file_name = "file2.txt";
r4->type = OUTPUT;
r4->fd = -1;
r4->next = NULL;

cmd4->redirction = r4;
cmd3->next = cmd4;
cmd4->next = NULL;
return (cmd1);
}

t_cmds *create_pipeline()
{
    //cat file.txt | grep zakaria | rev > file
    // First Command: cat file.txt
    t_cmds *cmd1 = malloc(sizeof(t_cmds));
    cmd1->cmps = (char *[]){"cat", "file.txt", NULL};
    cmd1->input = 0;  // stdin
    cmd1->output = -1; // pipe
    cmd1->pid = -1;
    cmd1->enum_cmd = PIPE;
    cmd1->redirction = NULL;
    // ---------------------------------
    // Second Command: grep zakaria
    t_cmds *cmd2 = malloc(sizeof(t_cmds));
    cmd2->cmps = (char *[]){"grep", "zakaria", NULL};
    cmd2->input = -1;  // will be pipe input
    cmd2->output = -1; // pipe output
    cmd2->pid = -1;
    cmd2->enum_cmd = PIPE;
    cmd2->redirction = NULL;
    cmd1->next = cmd2;
    // ---------------------------------
    // Third Command: rev > file
    t_cmds *cmd3 = malloc(sizeof(t_cmds));
    cmd3->cmps = (char *[]){"rev", NULL};
    cmd3->input = -1;  // from pipe
    cmd3->output = -1; // will become file descriptor
    cmd3->pid = -1;
    cmd3->enum_cmd = REDIR;

    t_redir_s *redir3 = malloc(sizeof(t_redir_s));
    redir3->file_name = "file";
    redir3->type = OUTPUT;
    redir3->fd = -1;
    redir3->next = NULL;

    cmd3->redirction = redir3;
    cmd2->next = cmd3;
    cmd3->next = NULL;

    // return head of the list
    return cmd1;
}