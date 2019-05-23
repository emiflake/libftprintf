/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:33:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/23 17:01:03 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include "writer.h"
# include "token.h"

typedef ssize_t(*t_formatter)(t_writer *writer, t_token *token, va_list vlist);


ssize_t			fmt_putstr(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putstrlit(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putpercent(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putnbr(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putptr(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_puthex(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putoct(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putchr(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_putflt(t_writer *writer, t_token *token, va_list vlist);
ssize_t			fmt_printmemory(t_writer *writer, t_token *token, va_list vlist);

ssize_t			intern_fmt_puthex(t_writer *writer, unsigned long long value, int caps);
ssize_t			intern_fmt_pad(t_writer *writer, char c, size_t amt);
char			intern_to_hex(char num, int caps);

#endif
