/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:34:07 by jwander           #+#    #+#             */
/*   Updated: 2021/10/08 16:11:13 by jwander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	getflag(const char c, t_shirt *args)
{
	if (c == 'c')
		ft_char(args);
	else if (c == 's')
		ft_string(args);
	else if (c == 'd' || c == 'i')
		ft_interger(args);
	else if (c == 'u')
		ft_unsignedint(args);
	else if (c == 'x' || c == 'X')
		ft_hex(args, c);
	else if (c == 'p')
		ft_pointer(args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		args->counter++;
	}
}

static t_shirt	*initialise(void)
{
	t_shirt	args;

	args = (t_shirt *)malloc(sizeof(t_shirt));
	if (args == NULL)
		return (NULL);
	args->counter = 0;
	return (args);
}

int	ft_printf(const char *str, ...)
{
	t_shirt	*args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	args = initialise();
	va_start(args->arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			args->counter++;
		}
		else if (str[i] == '%')
			getflag(str[++i], args);
		i++;
	}
	count = args->counter;
	va_end(args->arg);
	free(args);
	return (count);
}
