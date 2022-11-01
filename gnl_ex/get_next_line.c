/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:20:46 by amoubare          #+#    #+#             */
/*   Updated: 2022/11/01 23:54:28 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	nadi(char **stock, char **ligne)
{
	char	*temp;
	int		x;

	x = ft_int_strchr(*stock, '\n') + 1;
	*ligne = ft_substr(*stock, 0, x);
	temp = *stock;
	*stock = ft_substr(*stock, x, ft_strlen(*stock));
	free(temp);
}

char	*ft_free(char **lost)
{
	if (*lost)
		free(*lost);
	*lost = NULL;
	return (NULL);
}

char	*end_or_nofile(char **stock, char **ligne, char **buff)
{
	if (*stock && *stock[0] == '\0')
		ft_free(stock);
	*ligne = *stock;
	*stock = NULL;
	free(*buff);
	return (*ligne);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buff;
	char		*ligne;
	static char	*stock;
	char		*temp;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (ft_int_strchr(stock, '\n') == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0 || i == -1)
			return (end_or_nofile(&stock, &ligne, &buff));
		buff[i] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_free(&temp);
	}
	nadi(&stock, &ligne);
	free(buff);
	return (ligne);
}
int main()
{
	int fd = open("get_next_line.h", O_RDONLY);
	char *str = ft_strdup("");
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	return(0);
}