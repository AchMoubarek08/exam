/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:50:37 by amoubare          #+#    #+#             */
/*   Updated: 2022/11/01 23:51:16 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conditions(char c, void *args, int *count)
{
	if (c == 'd')
		ft_putnbr((int)args, count);
	else if (c == 's')
		ft_putstr((char *)args, count);
	else if (c == 'x')
		ft_putnbr_hexa((unsigned int)args, 'x', count);
}

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	args;

	va_start(args, s);
	c = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'd' || *s == 'x' || *s == 's')
			{
				ft_conditions(*s, va_arg(args, void *), &c);
			}
			else
				ft_putchar(*s, &c);
		}
		else
			ft_putchar(*s, &c);
		s++;
	}
	va_end(args);
	return (c);
}
int main()
{
	char *str = malloc(sizeof(char ) * 20);
	str = "fjield"; 
	int i = 51;
	printf("%d", ft_printf("%%%%%d%d%d%x%s", i, i, i, i, str));
	printf("\n");
	printf("%d",   printf("%%%%%d%d%d%x%s", i, i, i, i, str));
	printf("\n");
	return 0;
}
