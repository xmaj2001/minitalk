/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:03:01 by hbaddrul          #+#    #+#             */
/*   Updated: 2024/06/20 15:29:53 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_intlen(int n)
{
	int			idx;
	long long	tmp;

	tmp = n;
	idx = 1;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		idx++;
	}
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		idx++;
	}
	return (idx);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	len = ft_intlen(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = (n % 10) + '0';
		else
			ret[--len] = (n % 10 * -1) + '0';
		n /= 10;
	}
	return (ret);
}
