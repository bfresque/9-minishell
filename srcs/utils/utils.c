/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:32:38 by bfresque          #+#    #+#             */
/*   Updated: 2023/11/15 17:36:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_and_set_pipes(char *input, t_command *current)
{
	int		count;
	int		i;
	bool	single_quotes;
	bool	double_quotes;

	count = 0;
	i = 0;
	single_quotes = false;
	double_quotes = false;
	while (input[i])
	{
		if (input[i] == '\'')
			single_quotes = !single_quotes;
		else if (input[i] == '\"')
			double_quotes = !double_quotes;
		if ((!double_quotes && !single_quotes) && input[i] == '|')
			count++;
		i++;
	}
	while (current)
	{
		current->nb_pipes = count;
		current = current->next;
	}
}

void	ft_close_fd(void)
{
	int	fd;

	fd = 3;
	while (fd < 100)
	{
		close(fd);
		fd++;
	}
}

void	ft_close_all_fd(void)
{
	int	fd;

	fd = 0;
	while (fd < 100)
	{
		close(fd);
		fd++;
	}
}

int	is_empty_or_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}
