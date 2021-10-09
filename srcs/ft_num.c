/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:31:09 by jwander           #+#    #+#             */
/*   Updated: 2021/10/09 14:08:33 by jwander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countnbr(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	ft_unisgnedinttochar(unsigned int n)
{
	char	*rtn;
	int		len;

	len = ft_countnbr(n);
	rtn = (char *)malloc(len + 1 * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	rtn[len] = '\0';
	while (len > 0)
	{
		rtn[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (rtn);
}

void	ft_integer(t_shirt *args)
{
	char	*str;

	str = ft_itoa((int)va_args(args->arg, int));
	ft_putstr_fd(str, 1);
	args->counter += ft_strlen(str);
	free(str);
}

void	ft_unsignedint(t_shirt *args)
{
	char	*str;

	str = ft_unsignedinttochar((int)var_args(args->arg, unsigned int));
	ft_putstr_fd(str, 1);
	args->counter += ft_strlen(str);
	free(str);
}
