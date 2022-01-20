/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:53:21 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:54:19 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_err(char *msg)
{
	printf("%s", msg);
	return (1);
}

void	err_handle(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}
