/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:14:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 11:01:49 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"



//check if you find after key  += you take val you after this and joined with val of oringinal val of that var but if find the = you should change that  val if found 
//not thing you should return 
int determing_status(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '+' && input[i + 1] == '=')
			return (1); 
		else if (input[i] == '=' && input[i - 1] != '+')
			return (0);
		i++;
	}
	return (-1);
}
char *append_mode_to_env_var(char *new_val, char *old_val, int *status)
{
	char *tmp_val;
	char *joined_val;
	
	tmp_val = ft_strchr(new_val, '=');
	*status = 1;
	if (*(tmp_val + 1) == '\0')
	{
		free(new_val);
		return (old_val);	
	}
	else
		joined_val = free_and_join(old_val, tmp_val + 1, 1);
	free(new_val);
	return (joined_val);
}
char *set_val_to_env_var(char *old_val, char *new_val, int *status)
{
	char *tmp_val;
	char *return_val;
	
	tmp_val = ft_strchr(new_val, '=');
	*status = 1;
	if (*(tmp_val + 1) == '\0')
	{
		free(old_val);
		free(new_val);
		return (ft_strdup("="));
	}
	return_val = ft_strdup(tmp_val);
	free(tmp_val);//new
	free(old_val);
	free(new_val);
	return (return_val);
}

int modify_var(char *input, t_env **env)
{
	t_env	*tmp;
	char	*new_key;
	int 	status;

	new_key = extract_key(input);
	tmp = (*env)->next;
	while (tmp)
	{
		
		if (compare(new_key, tmp->key) == 0)
		{
			status  = determing_status(input);
			if (status == -1)
				return (1);
			else if (status == 1)
				tmp->value = append_mode_to_env_var(input, tmp->value , &tmp->status);
			else if (status == 0)
				tmp->value = set_val_to_env_var(tmp->value, input, &tmp->status);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	export(t_env **env, char **splited)
{
	int		i; 
	int		status;
	int 	stu;
	
    if (!splited[1])
    { 
		export_without(*env);
		return (0);
    }
	i = 1;
	status = 0;
	stu = 0;
	while (splited[i])
	{
		if (modify_var(splited[i], env) == 0)
		{
			status = check_name(splited[i]);
			if (status == 0)
				ft_lstadd_back(env, node(splited[i], 0));
			else 
				stu = status;
		}
		i++;
	}
	return (stu);
}
