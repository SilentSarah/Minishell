/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:11:01 by hmeftah           #+#    #+#             */
/*   Updated: 2023/05/30 13:13:37 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_error(void)
{
	perror(strerror(errno));
	return (1);
}

int	builtins_exit(t_general *g_master, int status)
{
	g_master->e_status = status;
	return (status);
}

char	*get_env_value(char *name, t_env *env)
{
	t_env	*found;

	found = get_env(name, env);
	if (found)
		return (found->value);
	else
		return (NULL);
	return (NULL);
}
