/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:16:25 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/17 12:49:14 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir *create_redir(char *op, char *file) {
    t_redir *r = malloc(sizeof(t_redir));
    if (!r)
        return NULL;

    r->file_name = strdup(file);
    r->fd = -1;
    r->next = NULL;

    if (strcmp(op, ">") == 0) {
        r->type = OUTPUT;
    } else if (strcmp(op, ">>") == 0) {
        r->type = APPEND;
    } else if (strcmp(op, "<") == 0) {
        r->type = INPUT;
    } else if (strcmp(op, "<<") == 0) {
        r->type = HEREDOC;
        r->fd = -2;
    }

    return r;
}

// --- Main Parser Function ---
t_cmds *parse_command_line(char *line) {
    t_cmds *head = NULL, *last = NULL;

    char *cmd_str = strtok(line, "|");
    while (cmd_str) {
        t_cmds *cmd = calloc(1, sizeof(t_cmds));
        if (!cmd)
            return NULL;

        cmd->input = -1;
        cmd->output = -1;
        cmd->pid = -1;
        cmd->redirection = NULL;
        cmd->next = NULL;

        char *tokens[100] = {NULL};
        int i = 0;
        char *word = strtok(cmd_str, " \t\n");

        while (word) {
            if (strcmp(word, ">") == 0 || strcmp(word, ">>") == 0 ||
                strcmp(word, "<") == 0 || strcmp(word, "<<") == 0) {
                
                char *op = word;
                word = strtok(NULL, " \t\n"); // get file name

                if (!word) break; // avoid crash

                t_redir *new_r = create_redir(op, word);

                if (!cmd->redirection)
                    cmd->redirection = new_r;
                else {
                    t_redir *tmp = cmd->redirection;
                    while (tmp->next) tmp = tmp->next;
                    tmp->next = new_r;
                }
            } else {
                tokens[i++] = word;
            }

            word = strtok(NULL, " \t\n");
        }
        tokens[i] = NULL;

        cmd->cmds = calloc(i + 1, sizeof(char *));
        for (int j = 0; j < i; j++)
            cmd->cmds[j] = strdup(tokens[j]);

        if (!head)
            head = cmd;
        else
            last->next = cmd;
        last = cmd;

        cmd_str = strtok(NULL, "|");
    }

    return head;
}
t_cmds *parsing_line(char *line)
{
    t_cmds *tmp;
    t_cmds *cmd;
    int     i;
    char    **splited;
    i = 0;
    
    splited = ft_split(line, '|');
    tmp = parse_command_line(splited[i]);
    cmd = tmp;
    i++;
    while (splited[i])
    {
        tmp->next = parse_command_line(splited[i]);
        tmp = tmp->next;
        i++;
    }
    free(line);
    line = NULL;
    return (cmd);
}