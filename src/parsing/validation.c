#include "../../minirt.h"

bool	check_identifier(t_data *data, int i)
{
	int		j;
	char	*v_identifiers[] = {"A", "L", "C", "sp", "cy", "pl", NULL};
	// char	*v_identifiers[] = {"A", "L", "C", "sp", "cy", "pl", "bx","cn", NULL}; //for BONUS

	j = 0;
	while (v_identifiers[j])
	{
		if (ft_strcmp(v_identifiers[j], data->lines[i].line[0]) == 0)
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
	while (data->lines[i].line)
	{
		if (!check_identifier(data, i))
		{
			ft_putstr_fd(data->lines[i].line[0], 2);
			ft_putstr_fd(" is invlaid identifier \n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}


bool check_identifier_repeat(t_data *data, char identifier)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while(data->lines[i].line)
	{
		if(data->lines[i].line[0][0] == identifier)
			counter++;
		i++;
	}
	if (counter != 1)
		return (false);
	return (true);
}


bool check_identifiers_numbers(t_data *data)
{
	if (!check_identifier_repeat(data, 'A'))
		return (ft_putstr_fd("only one A is valid",2), false);
	if (!check_identifier_repeat(data, 'C'))
		return (ft_putstr_fd("only one C is valid",2), false);
	/* this one NOT for BONUS part only*/
	if (!check_identifier_repeat(data, 'L'))
		return (ft_putstr_fd("only one L is valid",2), false);
	/* this one fNOT for BONUS part only*/
	return (true);
}

bool	validation(t_data *data)
{
	if (!identifiers_validation(data))
		return (false);
	if(!check_identifiers_numbers(data))
		return (false);
	return (true);
}
