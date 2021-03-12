/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:28:14 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/12 20:59:58 by seungyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	char *arr;

	if (!(arr = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_strlcpy(arr, s, ft_strlen(s) + 1);
	return (arr);
}
