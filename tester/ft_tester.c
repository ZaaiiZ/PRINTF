/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:47:26 by victor            #+#    #+#             */
/*   Updated: 2026/05/15 22:30:35 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

#define BUFF_SIZE 10000

static void	ft_close_pipe(int *fd_pipe_p, int *fd_pipe_f);
static void	ft_printlog(char type_test, const char *format, va_list *arg,
				char *buffer_p, char *buffer_f, int size_p, int size_f,
				int return_p, int return_f, char flag);
static void	ft_printarg(const char *format, va_list *arg, int fd);

int	ft_tester(char type_test, const char *format, ...)
{
	va_list	arg_p;
	va_list	arg_f;
	va_list	arg_log;
	int		fd_pipe_p[2];
	int		fd_pipe_f[2];
	int		saved_stdout;
	char	buffer_p[BUFF_SIZE];
	char	buffer_f[BUFF_SIZE];
	int		size_p;
	int		size_f;
	int		return_p;
	int		return_f;
	
	if (pipe(fd_pipe_p) == -1)
		return (-1);
	if (pipe(fd_pipe_f) == -1)
	{
		close(fd_pipe_p[0]);
		close(fd_pipe_p[1]);
		return (-1);
	}
	saved_stdout = dup(1);
	if (saved_stdout == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		return (-1);
	}
		
	va_start(arg_p, format);
	va_copy(arg_f, arg_p);
	va_copy(arg_log, arg_p);
		
	if (dup2(fd_pipe_p[1], 1) == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		close(saved_stdout);
		va_end(arg_p);
		va_end(arg_f);
		va_end(arg_log);
		return (-1);
	}
	return_p = vprintf(format, arg_p);
	fflush(stdout);
	if (dup2(saved_stdout, 1) == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		close(saved_stdout);
		va_end(arg_p);
		va_end(arg_f);
		va_end(arg_log);
		return (-1);
	}
	close(fd_pipe_p[1]);
	size_p = read(fd_pipe_p[0], buffer_p, BUFF_SIZE - 1);
	if (size_p == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		close(saved_stdout);
		va_end(arg_p);
		va_end(arg_f);
		va_end(arg_log);
		return (-1);
	}
	else
		buffer_p[size_p] = '\0';
	close(fd_pipe_p[0]);

	if (dup2(fd_pipe_f[1], 1) == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		close(saved_stdout);
		va_end(arg_p);
		va_end(arg_f);
		va_end(arg_log);
		return (-1);
	}
	return_f = ft_vprintf(format, &arg_f);
	if (dup2(saved_stdout, 1) == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		close(saved_stdout);
		va_end(arg_p);
		va_end(arg_f);
		va_end(arg_log);
		return (-1);
	}
	close(fd_pipe_f[1]);
	size_f = read(fd_pipe_f[0], buffer_f, BUFF_SIZE - 1);
	if (size_f == -1)
	{
		ft_close_pipe(fd_pipe_p, fd_pipe_f);
		close(saved_stdout);
		va_end(arg_p);
		va_end(arg_f);
		va_end(arg_log);
		return (-1);
	}
	else
		buffer_f[size_f] = '\0';
	close(fd_pipe_f[0]);

	close(saved_stdout);
	
	va_end(arg_p);
	va_end(arg_f);
		
	if (size_p == size_f
		&& ft_memcmp(buffer_p, buffer_f, size_p) == 0
		&& return_p == return_f)
	{
		ft_printlog(type_test, format, &arg_log, buffer_p, buffer_f,
					size_p, size_f, return_p, return_f, 'S');
		va_end(arg_log);
		return (1);
	}
	else
	{
		ft_printlog(type_test, format, &arg_log, buffer_p, buffer_f,
					size_p, size_f, return_p, return_f, 'F');
		va_end(arg_log);
		return (0);
	}
}

static void	ft_close_pipe(int *fd_pipe_p, int *fd_pipe_f)
{
	close(fd_pipe_p[0]);
	close(fd_pipe_p[1]);
	close(fd_pipe_f[0]);
	close(fd_pipe_f[1]);
	return ;
}

static void	ft_printlog(char type_test, const char *format, va_list *arg,
				char *buffer_p, char *buffer_f, int size_p, int size_f,
				int return_p, int return_f, char flag)
{
	int	fd;
	
	if (flag == 'S')
		fd = open("SUCCED_LOG.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (flag == 'F')
		fd = open("FAILED_LOG.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return ;
	if (fd == -1)
		return ;
	
	write(fd, "%", 1);
	write(fd, &type_test, 1);
	if (flag == 'S')
		ft_putendl_fd(" : TEST SUCCED", fd);
	else
		ft_putendl_fd(" : TEST FAILED", fd);

	write(fd, "FORMAT        : ", 16);
	write(fd, "|", 1);
	ft_putstr_fd((char *)format, fd);
	ft_putendl_fd("|", fd);

	write(fd, "ARGUMENT(S)   : ", 16);
	ft_printarg(format, arg, fd);
	write(fd, "\n", 1);
		
	write(fd, "PRINTF()      : ", 16);
	write(fd, "|", 1);
	ft_putbuffer_fd(buffer_p, size_p, fd);
	ft_putendl_fd("|", fd);
	write(fd, "RETURN VALUE  : ", 16);
	ft_putnbr_fd(return_p, fd);
	write(fd, "\n", 1);

	write(fd, "FT_PRINT()    : ", 16);
	write(fd, "|", 1);
	ft_putbuffer_fd(buffer_f, size_f, fd);
	ft_putendl_fd("|", fd);
	write(fd, "RETURN VALUE  : ", 16);
	ft_putnbr_fd(return_f, fd);
	write(fd, "\n\n", 2);
	
	close(fd);

	return ;
}

static void	ft_printarg(const char *format, va_list *arg, int fd)
{
	t_tester_format		frm;
	const char			*p;
	char				chr;
	char				*str;
	uintptr_t			ptr;
	int					nbr;
	unsigned int		unbr;
	
	while (*format)
	{
		if(*format == '%')
		{
			p = ft_parse_tester_format(format + 1, &frm, arg);
			if (p == NULL)
			{
				write(fd, "INVALID ARGUMENTS", 17);
				return ;
			}
			format = p;
			if (frm.width_is_star == 1)
			{
				write(fd, "|", 1);
				ft_putnbr_fd(frm.star_width, fd);
				write(fd, "|  ", 3);
			}
			if (frm.precision_is_star == 1)
			{
				write(fd, "|", 1);
				ft_putnbr_fd(frm.star_precision, fd);
				write(fd, "|  ", 3);
			}
			if (frm.specifier == 'c')
			{
				chr = (char)va_arg(*arg, int);
				write(fd, "|", 1);
				if (chr == '\0')
					write(fd, "\\0", 2);
				else
					write(fd, &chr, 1);
				write(fd, "|  ", 3);
			}
			else if (frm.specifier == 's')
			{
				str = va_arg(*arg, char *);
				write(fd, "|", 1);
				if (str == NULL)
					ft_putstr_fd("(null)", fd);
				else
					ft_putstr_fd(str, fd);
				write(fd, "|  ", 3);
			}
			else if (frm.specifier == 'p')
			{
				ptr = (uintptr_t)va_arg(*arg, void *);
				write(fd, "|", 1);
				if (ptr == 0)
					ft_putstr_fd("(nil)", fd);
				else
					ft_putptr_fd(ptr, fd);
				write(fd, "|  ", 3);
			}
			else if (frm.specifier == 'd' || frm.specifier == 'i')
			{
				nbr = va_arg(*arg, int);
				write(fd, "|", 1);
				ft_putnbr_fd(nbr, fd);
				write(fd, "|  ", 3);
			}
			else if (frm.specifier == 'u')
			{
				unbr = va_arg(*arg, unsigned int);
				write(fd, "|", 1);
				ft_putulnbr_fd((unsigned long)unbr, fd);
				write(fd, "|  ", 3);
			}
			else if (frm.specifier == 'x')
			{
				unbr = va_arg(*arg, unsigned int);
				write(fd, "|", 1);
				ft_putxnbr_fd(unbr, "0123456789abcdef", fd);
				write(fd, "|  ", 3);
			}
			else if (frm.specifier == 'X')
			{
				unbr = va_arg(*arg, unsigned int);
				write(fd, "|", 1);
				ft_putxnbr_fd(unbr, "0123456789ABCDEF", fd);
				write(fd, "|  ", 3);
			}
		}
		else
			format++;
	}
	return ;
}
