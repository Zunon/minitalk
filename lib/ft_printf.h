/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:24:32 by kalmheir          #+#    #+#             */
/*   Updated: 2022/05/30 18:47:35 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		count_valid_flags(const char *str);
char	*ft_strchr(const char *s, int c);
void	putstrip(const char *str, char ignore_percent, size_t *count);
void	put_charc(char c, size_t *count);
void	put_pointerc(void *pointer, size_t *count);
void	put_nbrc(int num, size_t *count);
void	put_unbrc(unsigned int num, size_t *count);
void	put_hex(unsigned int num, unsigned char isLower, size_t *count);
void	put_longhex(unsigned long num, size_t *count);
void	switcher(char c, va_list *list, size_t *chars);
void	iterator(const char *str, va_list *list, size_t *count);
#endif // FT_PRINTF_H
