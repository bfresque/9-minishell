/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_file_in_and_out.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:06:26 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/06 13:01:15 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*epur_file_two(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(str) * (ft_strlen(str) + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*verif_file_name(t_process_data *data, t_env *env, t_token *token)
{
	char	*file_name;

	file_name = NULL;
	if (token->next->split_value[0] == '\"'
		|| token->next->split_value[0] == '\'')
		file_name = epur_filename(data->current->token_head);
	else
	{
		file_name = epur_file_two(token->next->split_value);
		if (check_valid_caractere_filename(file_name[0]) == 1)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
			ft_putchar_fd(file_name[0], 2);
			ft_putstr_fd("\n", 2);
			ft_free_tab(data->command->command_arg_main);
			free_child(data, env);
			exit(g_exit_status = 2);
		}
	}
	return (file_name);
}

int	redirect_file_out(t_process_data *data, t_env *env, t_token *token)
{
	char	*filename;

	if (data->current->fd_out != 1)
		close(data->current->fd_out);
	filename = verif_file_name(data, env, token);
	data->current->fd_out = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->current->fd_out == -1)
	{
		write(1, "minishell: ", 12);
		perror(filename);
		if (filename)
			free(filename);
		ft_free_tab(data->command->command_arg_main);
		free_child(data, env);
		exit(g_exit_status = 1);
	}
	if (filename)
		free(filename);
	return (0);
}

int	redirect_file_in(t_process_data *data, t_env *env, t_token *token)
{
	char	*filename;

	if (data->current->fd_in != 0)
		close(data->current->fd_in);
	filename = verif_file_name(data, env, token);
	data->current->fd_in = open(filename, O_RDONLY);
	if (data->current->fd_in == -1)
	{
		write(1, "minishell: ", 12);
		perror(filename);
		if (filename)
			free(filename);
		ft_free_tab(data->command->command_arg_main);
		free_child(data, env);
		exit(g_exit_status = 1);
	}
	if (filename)
		free(filename);
	return (0);
}

int	redirect_append_file_out(t_process_data *data, t_env *env, t_token *token)
{
	char	*filename;

	if (data->current->fd_out != 1)
		close(data->current->fd_out);
	filename = verif_file_name(data, env, token);
	data->current->fd_out = open(filename, O_APPEND | O_WRONLY, 0644);
	if (data->current->fd_out == -1)
	{
		write(1, "minishell: ", 12);
		perror(filename);
		if (filename)
			free(filename);
		ft_free_tab(data->command->command_arg_main);
		free_child(data, env);
		exit(g_exit_status = 1);
	}
	if (filename)
		free(filename);
	return (0);
}
