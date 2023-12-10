/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:48:31 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/01 15:43:30 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*allocate_var_name(void)
{
	char	*var_name;

	var_name = malloc(sizeof(char) * SIZE);
	if (!var_name)
		return (NULL);
	ft_memset(var_name, '\0', SIZE);
	return (var_name);
}

char	*extract_var_name_cd(t_env *env, char *ret, int *i, int *m)
{
	char	*var_name;
	int		j;
	int		k;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	var_name = allocate_var_name();
	j = pass_find_var_name(env, var_name, i, j);
	if (j != -1)
	{
		while (env->cpy_env[j][k] != '=')
			k++;
		if (env->cpy_env[j][k] == '=')
			k++;
		while (env->cpy_env[j][k])
			var_name[l++] = env->cpy_env[j][k++];
		var_name[l] = '\0';
		l = 0;
		while (var_name[l])
			ret[(*m)++] = var_name[l++];
	}
	return (free(var_name), ret);
}

char	*check_expander(t_env *env)
{
	int		i;
	int		m;
	char	*ret;

	i = 0;
	m = 0;
	ret = malloc(sizeof(char) * SIZE);
	if (!ret)
		return (NULL);
	ft_memset(ret, '\0', SIZE);
	while (env->path_to_change[i])
	{
		if (env->path_to_change[i] == '$')
		{
			i++;
			extract_var_name_cd(env, ret, &i, &m);
		}
		ret[m++] = env->path_to_change[i++];
	}
	ret[m] = '\0';
	return (ret);
}

int	ft_builtin_cd(char **args, t_env *env)
{
	char	*home;

	if (args[1] == NULL || ft_strcmp_minishell(args[1], "~") == 0)
	{
		home = ft_get_env("HOME", env);
		if (!home)
		{
			write(2, "minishell: cd: HOME not set\n", 29);
			g_exit_status = 1;
			return (g_exit_status);
		}
		env->path_to_change = home;
	}
	else
		env->path_to_change = args[1];
	update_env_oldpwd(env);
	env->path_to_change = check_expander(env);
	if (chdir(env->path_to_change) == -1)
		return (print_error_cd(env, 1), 1);
	env->new_directory = getcwd(NULL, 0);
	if (env->new_directory)
		print_error_cd(env, 2);
	free(env->path_to_change);
	return (g_exit_status);
}
