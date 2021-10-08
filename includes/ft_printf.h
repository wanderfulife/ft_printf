/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:29:33 by jwander           #+#    #+#             */
/*   Updated: 2021/10/08 14:31:18 by jwander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_shirt
{
	va_list	arg;
	int		counter;
}	t_shirt;

int		ft_printf(const char *str, ...);
void	ft_char(t_shirt *args);
void	ft_string(t_shirt *args);
void	ft_integer(t_shirt *args);
void	ft_unsignedint(t_shirt *args);
void	ft_hex(t_shirt *args);
void	ft_pointer(t_shirt args);

#endif
