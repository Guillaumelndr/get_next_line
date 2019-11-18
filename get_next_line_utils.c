/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 07:58:04 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 08:36:09 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_all(t_gnl *nl, int ret, char *buff)
{
	if (ret == 0)
	{
		free(nl->c_line);
		nl->c_line = NULL;
	}
	if (!nl->index && buff[0] != '\n' && nl->oct != BUFFER_SIZE)
	{
		free(nl);
		return (0);
	}
	free(nl);
	return (ret);
}

size_t	ft_strlen(const char *s1, int i)
{
	int		j;

	j = 0;
	if (i >= BUFFER_SIZE)
		return (0);
	while (s1[i])
	{
		i++;
		j++;
	}
	return (j);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (!(ptr = malloc(size * count)))
		return (0);
	if (size * count > 2147483648)
		return (ptr);
	ptr[0] = '\0';
	return (ptr);
}
