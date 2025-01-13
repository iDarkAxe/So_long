/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:03:57 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 18:31:28 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static ssize_t	ft_putnbr_hex_pointer(unsigned long nbr, const char *base)
{
	ssize_t				temp;

	temp = 0;
	if (nbr >= 16)
	{
		temp += ft_putnbr_hex_pointer(nbr / 16, base);
		temp += ft_putnbr_hex_pointer(nbr % 16, base);
	}
	else
		temp += write(1, &base[nbr], 1);
	return (temp);
}

/**
 * @brief Print pointer adress
 *
 * @param nbr Number to be printed
 * @return ssize_t number of char printed
 */
ssize_t	ft_putpointer_fd(unsigned long nbr)
{
	if (!nbr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) != -1)
		return (ft_putnbr_hex_pointer(nbr, "0123456789abcdef\0") + 2);
	return (-1);
}

/**
 * @brief Write the int 'n' on the given file descriptor
 *	Works with recursion
 * @param n number to print
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
static ssize_t	ft_putnbr_recursive_fd(long long n, int fd)
{
	ssize_t	count_printed;
	char	temp;

	count_printed = 0;
	if (n >= 10)
		count_printed += ft_putnbr_fd(n / 10, fd);
	temp = n % 10 + '0';
	count_printed += write(fd, &temp, 1);
	return (count_printed);
}

/**
 * @brief Write the int 'n' on the given file descriptor
 *
 * @param n number to print
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putnbr_fd(long long n, int fd)
{
	ssize_t	count_printed;

	count_printed = 0;
	if (n < 0)
	{
		n = -n;
		count_printed += write(fd, "-", 1);
	}
	return (count_printed + ft_putnbr_recursive_fd(n, fd));
}

ssize_t ft_print_position(int x, int y)
{
	ssize_t count_printed;

	count_printed = 0;
	count_printed += write(1, "Pos: x,y(", 9);
	count_printed += ft_putnbr_fd(x, 1);
	count_printed += write(1, ", ", 2);
	count_printed += ft_putnbr_fd(y, 1);
	count_printed += write(1, ")\n", 2);
	return (count_printed);
}