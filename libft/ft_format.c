/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:45:50 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/25 13:45:51 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char		*ft_background(const char *str)
{
	char		*color;

	color = NULL;
	if (ft_strncmp(str, "eoc}", 4) == 0)
		CHECK(color = ft_strdup(EOC));
	else if (ft_strncmp(str, "black}", 6) == 0)
		CHECK(color = ft_strdup(BBLACK));
	else if (ft_strncmp(str, "red}", 4) == 0)
		CHECK(color = ft_strdup(BRED));
	else if (ft_strncmp(str, "green}", 6) == 0)
		CHECK(color = ft_strdup(BGREEN));
	else if (ft_strncmp(str, "yellow}", 7) == 0)
		CHECK(color = ft_strdup(BYELLOW));
	else if (ft_strncmp(str, "blue}", 5) == 0)
		CHECK(color = ft_strdup(BBLUE));
	else if (ft_strncmp(str, "magenta}", 8) == 0)
		CHECK(color = ft_strdup(BMAGENTA));
	else if (ft_strncmp(str, "cyan}", 5) == 0)
		CHECK(color = ft_strdup(BCYAN));
	else if (ft_strncmp(str, "white}", 5) == 0)
		CHECK(color = ft_strdup(BWHITE));
	return (color);
}

static char		*ft_text(const char *str)
{
	char		*color;

	color = NULL;
	if (ft_strncmp(str, "black}", 6) == 0)
		CHECK(color = ft_strdup(BLACK));
	else if (ft_strncmp(str, "red}", 4) == 0)
		CHECK(color = ft_strdup(RED));
	else if (ft_strncmp(str, "green}", 6) == 0)
		CHECK(color = ft_strdup(GREEN));
	else if (ft_strncmp(str, "yellow}", 7) == 0)
		CHECK(color = ft_strdup(YELLOW));
	else if (ft_strncmp(str, "blue}", 5) == 0)
		CHECK(color = ft_strdup(BLUE));
	else if (ft_strncmp(str, "magenta}", 8) == 0)
		CHECK(color = ft_strdup(MAGENTA));
	else if (ft_strncmp(str, "cyan}", 5) == 0)
		CHECK(color = ft_strdup(CYAN));
	else if (ft_strncmp(str, "white}", 5) == 0)
		CHECK(color = ft_strdup(WHITE));
	return (color);
}

char			*ft_format(const char *str)
{
	char		*color;

	color = NULL;
	if (ft_strncmp(str, "eoc}", 4) == 0)
		CHECK(color = ft_strdup(EOC));
	else if (ft_strncmp(str, "bold}", 4) == 0)
		CHECK(color = ft_strdup(BOLD));
	else if (ft_strncmp(str, "ital}", 4) == 0)
		CHECK(color = ft_strdup(ITAL));
	else if (ft_strncmp(str, "under}", 4) == 0)
		CHECK(color = ft_strdup(UNDER));
	else if ((color = ft_text(str)) != NULL)
		;
	else if (str[0] == 'b')
		CHECK(color = ft_background(&str[1]));
	return (color);
}
