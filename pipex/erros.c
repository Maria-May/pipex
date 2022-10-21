/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:19:25 by mdaryn            #+#    #+#             */
/*   Updated: 2022/02/15 15:19:27 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_msg(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	ft_msg_errors(char *error)
{
	perror(error);
	exit(1);
}
