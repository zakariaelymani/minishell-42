/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:14:11 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/09 09:46:43 by zel-yama         ###   ########.fr       */
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
		joined_val = ft_strjoin(old_val, tmp_val + 1);

	free(new_val);
	free(old_val);
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
	free(old_val);
	free(new_val);
	return (return_val);
	
}


//check is var is the change value of that var 
int modify_var(char *input, t_env **env)
{
	t_env	*tmp;
	char	*new_key;
	int 	status;

	new_key = extract_key(input);
	tmp = (*env);
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
//should create function that take val and var name and this func will change that val 
//

int	export(t_env **env, char **splited)
{
	int		i;
	int		status;
	
    if (!splited[1])
    { 
		export_without(*env);
		return (0);
    }
	i = 1;
	status = 0;
	while (splited[i])
	{
		if (modify_var(splited[i], env) == 0)
		{
			status = check_name(splited[i]); ///parse name of var key 
			if (status == 0)
				ft_lstadd_back(env, node(splited[i]));
			else
				return (1);
		}
		i++;
	}
	return (0);
}
