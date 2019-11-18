/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 13:30:34 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 13:12:50 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*init_gnl(t_gnl *nl)
{
	int		i;

	i = 0;
	if (!(nl = malloc(sizeof(t_gnl))))
		return (NULL);
	nl->oct = 1;
	nl->total_oct = 0;
	nl->index = 0;
	if (!(nl->c_line = malloc(sizeof(char))))
		return (NULL);
	nl->c_line[i] = '\0';
	nl->exit = 1;
	return (nl);
}

int		transfert(t_gnl *nl)
{
	char		tmp[nl->total_oct + 1];
	int			i;

	i = 0;
	while (i != nl->total_oct - nl->oct)
	{
		tmp[i] = nl->c_line[i];
		i++;
	}
	tmp[i] = '\0';
	free(nl->c_line);
	if (!(nl->c_line = (char *)malloc(sizeof(char) * (nl->total_oct + 1))))
		return (0);
	i = -1;
	while (tmp[++i])
		nl->c_line[i] = tmp[i];
	return (1);
}

int		ft_realoc(t_gnl *nl, char *buff)
{
	int			i;

	i = -1;
	transfert(nl);
	while (buff[nl->index])
	{
		++i;
		if (buff[nl->index] == '\n')
		{
			nl->c_line[nl->total_oct - nl->oct + i] = '\0';
			return (0);
		}
		nl->c_line[nl->total_oct - nl->oct + i] = buff[nl->index];
		nl->index++;
	}
	if (nl->oct != BUFFER_SIZE && buff[BUFFER_SIZE - 1] == '\n')
		return (1);
	return (nl->oct);
}

void	analized(t_gnl *nl, char *buff, int fd)
{
	if (!buff[nl->index])
	{
		nl->oct = read(fd, buff, BUFFER_SIZE);
		buff[nl->oct] = '\0';
		nl->index = 0;
	}
	else
	{
		nl->oct = ft_strlen(buff, ++nl->index);
	}
	nl->total_oct += nl->oct;
}

int		get_next_line(int fd, char **line)
{
	t_gnl		*nl;
	static char	buff[BUFFER_SIZE + 1];
	static int	save_index = 0;

	nl = NULL;
	if ((!(nl = init_gnl(nl)) || fd == -1
	|| BUFFER_SIZE < 1) || read(fd, buff, 0) < 0)
		return (-1);
	nl->index = save_index;
	while (nl->exit)
	{
		analized(nl, buff, fd);
		nl->exit = ft_realoc(nl, buff);
	}
	nl->c_line[nl->total_oct] = '\0';
	save_index = nl->index;
	*line = nl->c_line;
	if (!nl->total_oct)
	{
		*line = calloc(1, 1); // attention calloc non ft_
		return (free_all(nl, 0, buff));
	}
	return (free_all(nl, 1, buff));
}
