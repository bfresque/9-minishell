/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:44:17 by abonnefo          #+#    #+#             */
/*   Updated: 2023/11/20 10:00:52 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_pwd(t_command *current)
{
	if (ft_strcmp_minishell(current->command, "pwd") == 0
		|| ft_strncmp(current->command, "pwd ", 4) == 0)
	{
		ft_builtin_pwd(STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	check_echo(t_command *current, t_env *env)
{
	char	**tab;

	if (ft_strcmp_minishell(current->command, "echo") == 0
		|| ft_strncmp(current->command, "echo ", 5) == 0
		|| ft_strncmp(current->command, "echo	", 5) == 0)
	{
		tab = parse_input_quote_echo(env, current->command);
		ft_builtin_echo(tab);
		ft_free_tab(tab);
		return (1);
	}
	return (0);
}

int	check_cd(t_command *current)
{
	if (ft_strcmp_minishell(current->command, "cd") == 0
		|| ft_strncmp(current->command, "cd ", 3) == 0)
	{
		if (current->nb_pipes != 0)
			return (1);
		return (1);
	}
	return (0);
}
