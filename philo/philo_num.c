/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:53:56 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:53:57 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	left(int n, int amount)
{
	if ((n + 1) % amount == 0)
		return (amount);
	return ((n + 1) % amount);
}

int	right(int n, int amount)
{
	if ((n - 1) % amount == 0)
		return (amount);
	return ((n - 1) % amount);
}
