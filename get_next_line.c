// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/08 20:48:54 by csouita           #+#    #+#             */
// /*   Updated: 2024/07/09 23:20:58 by csouita          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap_bonus.h"

// char	*all_buffer(char *str, int fd)
// {
// 	char		*buffer;
// 	ssize_t		count;

// 	buffer = malloc((size_t)BUFFER_SIZE + 1);
// 	if (buffer == NULL)
// 		return (NULL);
// 	while (!ft_strchr(str, '\n'))
// 	{
// 		count = read(fd, buffer, BUFFER_SIZE);
// 		if (count == -1)
// 			return (free(str), free(buffer), NULL);
// 		if (count == 0)
// 			break ;
// 		buffer[count] = '\0';
// 		str = ft_strjoin(str, buffer);
// 	}
// 	return (free(buffer), str);
// }

// char	*get_line(char *saved_s)
// {
// 	char	*line;
// 	size_t	i;

// 	i = 0;
// 	if (!*saved_s)
// 	{
// 		free(saved_s);
// 		return (NULL);
// 	}
// 	while (saved_s[i] != '\n' && saved_s[i])
// 		i++;
// 	if (saved_s[i] == '\n')
// 		i++;
// 	line = malloc(i + 1);
// 	if (!line)
// 	{
// 		free(saved_s);
// 		return (NULL);
// 	}
// 	line[i] = '\0';
// 	ft_memcpy(line, saved_s, i);
// 	printf("{%s}", line);
// 	return (line);
// }

// char	*left_line(char *saved_s, char *line)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new_str;

// 	i = 0;
// 	j = 0;
// 	while (saved_s[i] == line[i] && saved_s[i] && line[i])
// 		i++;
// 	if (!saved_s[i])
// 	{
// 		free(saved_s);
// 		return (NULL);
// 	}
// 	new_str = malloc(ft_strlen(saved_s) - i + 1);
// 	if (!new_str)
// 	{
// 		free(saved_s);
// 		return (NULL);
// 	}
// 	while (saved_s[i])
// 		new_str[j++] = saved_s[i++];
// 	new_str[j] = '\0';
// 	free(saved_s);
// 	return (new_str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*saved_s;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line = NULL;
// 	saved_s = all_buffer(saved_s, fd);
// 	if (!saved_s)
// 		return (NULL);
// 	line = get_line(saved_s);
// 	if (!line)
// 		return (NULL);
// 	saved_s = left_line(saved_s, line);
// 	return (line);
// }



#include "push_swap_bonus.h"

char	*ft_strchr1(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == s[i])
		return ((char *)(&s[i]));
	return (NULL);
}

void	*ft_memcpy1(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *str)
{
	char	*ptr;

	ptr = malloc((sizeof(char) * ft_strlen(str)) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, ft_strlen(str));
	ptr[ft_strlen(str)] = '\0';
	return (ptr);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if (!s1)
		return (ft_strjoin1(s2));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ls1);
	ft_memcpy(ptr + ls1, s2, ls2);
	ptr[ls1 + ls2] = '\0';
	free(s1);
	return (ptr);
}


char	*get_read(char *save_str, int fd)
{
	char	*buffer;
	ssize_t	read_n;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
	{
		free(save_str);
		return (NULL);
	}
	read_n = 1;
	while (!ft_strchr1(save_str, '\n'))
	{
		read_n = read(fd, buffer, BUFFER_SIZE);
		if (read_n <= 0)
			break ;
		buffer[read_n] = '\0';
		save_str = ft_strjoin2(save_str, buffer);
	}
	free(buffer);
	if (read_n < 0)
	{
		free(save_str);
		return (NULL);
	}
	return (save_str);
}

char	*get_line(char *save_str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save_str[i])
	{
		free(save_str);
		return (NULL);
	}
	while (save_str[i] != '\n' && save_str[i])
		i++;
	if (save_str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(save_str);
		return (NULL);
	}
	ft_memcpy1(line, save_str, i);
	line[i] = '\0';
	return (line);
}

char	*left_lines(char *line, char *save_str)
{
	int		i;
	int		j;
	char	*new_save_str;

	i = 0;
	j = 0;
	while (save_str[i] == line[i] && save_str[i] && line[i])
		i++;
	if (!save_str[i])
	{
		free(save_str);
		return (NULL);
	}
	new_save_str = malloc(ft_strlen1(save_str) - i + 1);
	if (!new_save_str)
	{
		free(save_str);
		return (NULL);
	}
	while (save_str[i])
		new_save_str[j++] = save_str[i++];
	new_save_str[j] = '\0';
	free(save_str);
	return (new_save_str);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_str = get_read(save_str, fd);
	if (!save_str)
		return (NULL);
	line = get_line(save_str);
	if (!line)
		return (NULL);
	save_str = left_lines(line, save_str);
	return (line);
}