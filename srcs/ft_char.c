/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:35:21 by jwander           #+#    #+#             */
/*   Updated: 2021/10/08 17:07:13 by jwander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_shirt *args)
{
	ft_putchar_fd(va_args(args->arg, int), 1);
	args->counter++;
}

void	ft_string(t_shirt *args)
{
	int		len;
	char	*str;

	str = va_args(args->arg, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		args->counter += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		args->counter += len;
	}
}
