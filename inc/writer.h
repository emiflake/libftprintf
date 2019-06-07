/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:59:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/07 12:52:53 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_H
# define WRITER_H
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct	s_writer
{
	ssize_t	(*write)(struct s_writer *self, char *str, size_t length);
	void	*state;
	size_t	written;
	int		failed;
}				t_writer;

void			writer_write(t_writer *writer, char *str, size_t length);

/*
** Write to an fd
*/
typedef int		t_writer_fd_state;
ssize_t			writer_fd_write(t_writer *self, char *str, size_t length);

/*
** Write to a FILE
*/
typedef FILE	t_writer_file_state;
ssize_t			writer_file_write(t_writer *self, char *str, size_t length);

/*
** Write to auto-allocated string
** TODO: implement Vector
*/
typedef struct	s_writer_alloc_state
{
	char	**str_ptr;
	size_t	len;
}				t_writer_alloc_state;
ssize_t			writer_alloc_write(t_writer *self, char *str, size_t length);

typedef struct	s_writer_string_state
{
	char	*str_ptr;
	ssize_t	maximum;
}				t_writer_string_state;
ssize_t			writer_string_write(t_writer *self, char *str, size_t length);

#endif
