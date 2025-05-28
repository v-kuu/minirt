/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:13:48 by vkuusela          #+#    #+#             */
/*   Updated: 2025/05/28 17:46:58 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int character)
{
	if (character >= 48 && character <= 57)
		return (1);
	else
		return (0);
}

int	ft_isfloat(int character)
{
	if ((character >= 48 && character <= 57) || character == 46)
		return (1);
	else
		return (0);
}
