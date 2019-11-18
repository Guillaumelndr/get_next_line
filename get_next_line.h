/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 13:29:03 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 19:18:56 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_gnl
{
	char		*c_line;
	int			oct;
	int			total_oct;
	int			index;
	int			exit;
}				t_gnl;

int				get_next_line(int fd, char **line);
t_gnl			*init_gnl(t_gnl *nl);
size_t			ft_strlen(const char *s1, int i);
int				free_all(t_gnl *nl, int ret, char *buff);
void			*ft_calloc(size_t count, size_t size);

#endif
