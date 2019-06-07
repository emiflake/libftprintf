/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:04:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/07 12:18:51 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <libft.h>
#include "writer.h"

void	writer_write(t_writer *writer, char *str, size_t length)
{
	writer->write(writer, str, length);
}

ssize_t	writer_fd_write(t_writer *self, char *str, size_t length)
{
	self->written += length;
	return (write(*(t_writer_fd_state *)self->state, str, length));
}

ssize_t	writer_file_write(t_writer *self, char *str, size_t length)
{
	self->written += length;
	return (fwrite(str, length, 1, (t_writer_file_state *)self->state));
}

ssize_t	writer_alloc_write(t_writer *self, char *str, size_t length)
{
	t_writer_alloc_state	*state;
	char					*new;

	state = (t_writer_alloc_state*)self->state;
	new = ft_realloc(*state->str_ptr, state->len, state->len + length + 1);
	if (new == NULL)
		return (-1);
	*state->str_ptr = new;
	if (ft_memcpy(*state->str_ptr + state->len, str, length) == NULL)
		return (-1);
	state->len += length;
	new[state->len] = '\0';
	self->written += length;
	return (length);
}

ssize_t	writer_string_write(t_writer *self, char *str, size_t length)
{
	t_writer_string_state	*state;
	size_t					to_write;

	state = (t_writer_string_state*)self->state;
	if (self->written + length > (size_t)state->maximum && state->maximum > 0)
	{
		to_write = state->maximum - self->written;
		ft_memcpy(state->str_ptr + self->written, str, to_write);
		self->written += to_write;
	}
	else
	{
		ft_memcpy(state->str_ptr + self->written, str, length);
		self->written += length;
	}
	return (length);
}
