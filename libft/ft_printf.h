/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:06:28 by lde-mais          #+#    #+#             */
/*   Updated: 2023/07/01 20:06:36 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

void	ft_putnbrunsigned(unsigned int nbr, int *len);
void	ft_putnbr_base(int nbr, char *base, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
int		ft_printf(const char *format, ...);
char	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *str, char *buf);
int		has_newline(char *str);
char	*get_line(char *str);
char	*get_new_line(int fd, char *str);
char	*left_line(char *str);
char	*get_next_line(int fd);
int		ft_check_newline(char *s);
char	*ft_strdup(const char *s);
size_t	ft_tablen(char **tab);
char	**ft_tabdup(char **tab);
void	free_tab(char **tab);
char	**ft_split(char const *s, char c);

#endif