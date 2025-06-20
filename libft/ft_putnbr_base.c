/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:59:21 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/01 19:59:24 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *len)
{
	long int	nb;

	nb = nbr;
	if (nb < 0)
		nb = (unsigned int)nb;
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base, len);
		ft_putnbr_base(nb % 16, base, len);
	}
	else
		*len += write(1, &base[nb], 1);
}
