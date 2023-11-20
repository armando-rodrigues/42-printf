/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidro2 <davidro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:01:24 by david             #+#    #+#             */
/*   Updated: 2023/11/20 13:45:00 by davidro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_lowhex(unsigned long long n, char *base, int counter)
{
    if(n >= 16)
    {
        counter += ft_lowhex(n / 16, base, counter);
    }
    write(1, &base[n % 16], 1);
    counter++;
    return (counter);
}

static int  ft_uphex(unsigned long long n, char *base, int counter)
{
    if(n >= 16)
    {
        counter += ft_uphex(n / 16, base, counter);
    }
    write(1, &base[n % 16], 1);
    counter++;
    return (counter);
}

int	ft_puthex_pf(unsigned long long n, char c)
{
    char    *base;
    int     counter;

    counter = 0;
    if (c == 'x')
    {
        base = "0123456789abcdef";
        counter = ft_lowhex(n, base, counter);
    }
    else if (c == 'X')
    {
        base = "0123456789ABCDEF";
        counter = ft_uphex(n, base, counter);
    }
    return (counter);
}

// int main()
// {
//     ft_puthex_pf(159, 'x');
//     write(1, "\n", 1);
//     printf("%x", 159);
// }