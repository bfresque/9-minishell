/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:29:45 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/05 12:32:48 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ctrl_c_main(int signal)
{
	(void)signal;
	g_exit_status = 130;
	rl_on_new_line();
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_redisplay();
}

int	ctrl_d_heredoc(char *input, int i, char *delimiter)
{
	if (!input)
	{
		write(1, "minishell: warning: here-document at line ", 43);
		ft_putnbr_fd(i, STDOUT_FILENO);
		write(1, " delimited by end-of-file (wanted \'", 36);
		ft_putstr_fd(delimiter, STDOUT_FILENO);
		write(1, "')\n", 4);
		return (45);
	}
	return (0);
}

void	ctrl_c_heredoc(int signal)
{
	t_process_data	*data;
	t_env			*env;

	data = return_data(NULL);
	env = return_env(NULL);
	if (signal == SIGINT)
	{
		write(2, "\n", 1);
		free(data->delimiter);
		ft_free_tab(data->command->command_arg_main);
		free_child(data, env);
		g_exit_status = 24;
		exit(g_exit_status);
	}
}

void	ctrl_c_manage(int signal)
{
	if (signal == SIGINT)
	{
		g_exit_status = 24;
		return ;
	}
}

void	verif_ctrl_c(t_process_data *data, t_env *env)
{
	if (g_exit_status == 24)
	{
		free(data->delimiter);
		ft_free_tab(data->command->command_arg_main);
		free_child(data, env);
		exit(g_exit_status);
	}
}
