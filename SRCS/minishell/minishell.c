/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:18:33 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/06/10 13:47:30 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_general	g_gen;

/*
Initializes an environment and copy env to en->env_vars variable
Also sets the lexer and expander pointers to NULL.
@param en The environment struct to initialize.
@param env An array of environment variable strings.
@param lexer A pointer to a linked list representing the lexer.
@param expander A pointer to a linked list representing the expander.
*/
void	fry_init_all(char **env, t_list **lexer, t_table **expander)
{
	g_gen.ev = create_env(env);
	g_gen.exp = create_env(env);
	g_gen.e_status = 0;
	g_gen.f_open = 0;
	g_gen.c_procs = NULL;
	g_gen.line = NULL;
	g_gen.u_exec = false;
	*lexer = NULL;
	*expander = NULL;
	init_signal_handler();
}

int	main(int ac, char **av, char **envp)
{
	t_list	*lexer;
	t_table	*expander;

	(void)ac;
	(void)av;
	fry_init_all(envp, &lexer, &expander);
	while (true)
	{
		g_gen.line = readline(GREEN"fry@shell ~ :"WHITE);
		if (!g_gen.line)
			kill_shell();
		lexer = fry_lexer(g_gen.line);
		expander = fry_expander(lexer);
		executer(expander);
		free (g_gen.line);
	}
	return (0);
}
