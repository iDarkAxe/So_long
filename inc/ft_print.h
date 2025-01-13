/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft                                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:31 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 18:14:55 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stddef.h>
# include <unistd.h>

// PRINT related functions
ssize_t	ft_putnbr_fd(long long n, int fd);
ssize_t	ft_putpointer_fd(unsigned long ptr);

#endif
