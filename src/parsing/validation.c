#include "../../minirt.h"

bool	check_identifier(t_data *data, int i)
{
	int		j;
	char	*v_identifiers[] = {"A", "L", "C", "sp", "cy", "pl", "bx","cn", NULL};

	j = 0;
	while (v_identifiers[j])
	{
		if (ft_strcmp(v_identifiers[j], data->objects[i].object[0]) == 0)
		{
			return (true);
		}
		j++;
	}
	return (false);
}

bool	identifiers_validation(t_data *data)
{
	int	i;

	i = 0;
	while (data->objects[i].object)
	{
		if (!check_identifier(data, i))
		{
			ft_putstr_fd(data->objects[i].object[0], 2);
			ft_putstr_fd(" is invlaid identifier \n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	validation(t_data *data)
{
	if (!identifiers_validation(data))
		return (false);
	return (true);
}