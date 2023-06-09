/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:15:32 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/10 16:30:55 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Finds Variables in export list,
returns a pointer to the variable if found, returns NULL if else*/
t_env	*get_env(const char *name, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (!name)
		return (NULL);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	**parse_variable(char *arg)
{
	int		i;
	char	**result;

	i = 0;
	if (!arg || (arg[0] != '_' && !ft_isalpha(arg[0])))
		return (NULL);
	result = export_split(arg);
	while (result[0][++i])
	{
		if (arg[i] != '_' && !ft_isalnum(result[0][i]))
			return (NULL);
	}
	return (result);
}

int	check_variable_validity(char *arg)
{
	if (!ft_strchr(arg, '='))
		return (0);
	else
		return (1);
	return (1);
}

int	insert_to_export(t_env **exp, char **var, char *arg)
{
	t_env	*node;

	node = create_var(var[0], var[1]);
	node->single = true;
	if (ft_strchr(arg, '='))
		node->single = false;
	add_back(exp, node);
	return (0);
}

int	insert_to_env(t_env **en, char **var, char *arg)
{
	t_env	*node;

	node = create_var(var[0], var[1]);
	node->single = true;
	if (ft_strchr(arg, '='))
		node->single = false;
	add_back(en, node);
	return (0);
}
