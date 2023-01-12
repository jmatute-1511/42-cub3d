
#include "includes/cub3d.h"

char	*resized_row(char **row, t_env *env)
{
	int		dif;
	int		it;
	char	*fill_space;
	char	*aux;

	it = 0;
	dif = env->width - ft_strlen(*row);
	if (dif == 0)
		return (*row);
	fill_space = malloc(sizeof(char) * dif + 1);
	while (it < dif)
	{
		fill_space[it] = ' ';
		it++;
	}
	fill_space[it] = '\0';
	aux = ft_strjoin((*row), fill_space);
	free(*row);
	return (aux);
}

void	resized_map(t_env **d_env)
{
	t_env	*env;
	int		it;

	it = 0;
	env = (*d_env);
	while (env->map[it] != NULL)
	{
		env->map[it] = resized_row(&env->map[it], env);
		it++;
	}
}
