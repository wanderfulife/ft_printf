/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:11:42 by jwander           #+#    #+#             */
/*   Updated: 2021/10/09 17:29:57 by jwander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strsize(unsigned long num, int *i)
{
	char	*str;

	while (num >= 16)
	{
		num = num / 16;
		*i += 1;
	}
	str = (char *)malloc((*i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*i] = '\0';
	return (str);
}

void	ft_hex(t_shirt *args, char c)
{
	unsigned int	n;
	int				i;
	char			*str;

	n = va_arg(args->arg, unsigned int);
	i = 1;
	str = ft_strsize(n, &i);
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else if (c == 'x')
			str[i] = 'a' - 10 + (n % 16);
		else
			str[i] = 'A' - 10 + (n % 16);
		n = n / 16;
		i--;
		args->counter += 1;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ft_pointer(t_shirt *args)
{
	unsigned long	n;
	int				i;
	char			*str;

	n = va_arg(args->arg, unsigned long);
	i = 1;
	str = ft_strsize(n, &i);
	ft_putstr_fd("0x", 1);
	args->counter += 2;
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else
			str[i] = 'a' - 10 + (n % 16);
		n = n / 16;
		i--;
		args->counter += 1;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
