/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <ede-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:18:45 by ede-lang          #+#    #+#             */
/*   Updated: 2024/03/12 11:50:50 by ede-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*joinandfree(char *buff, char *str)
{
	char	*tmp;

	tmp = ft_strjoin((char const *)str, (char const *)buff);
	free(str);
	return (tmp);
}

char	*setbuff(char *buff)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	rest = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i] && rest)
	{
		rest[j] = buff[i];
		i++;
		j++;
	}
	free(buff);
	return (rest);
}

char	*nline(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*readfile(int fd, char *result)
{
	char	*buff;
	int		len;

	if (!result)
		result = ft_calloc(1, sizeof(char));
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	len = 1;
	while (len > 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
		{
			free(result);
			free(buff);
			return (NULL);
		}
		buff[len] = 0;
		result = joinandfree(buff, result);
		if (ft_strchr(buff, '\n') || !result)
			break ;
	}
	free(buff);
	return (result);
}

/**
 * @brief Get the next line object
 *
 * @param fd
 * @return char*
 */
char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = nline(buffer[fd]);
	buffer[fd] = setbuff(buffer[fd]);
	return (line);
}
