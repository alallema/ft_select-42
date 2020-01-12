#include "select.h"

static void		bold_color(void)
{
    t_data  *data;
	char	color[COLOR_NB][10];

	ft_strcpy(color[RED], "\033[1;31m");
	ft_strcpy(color[PIN], "\033[1;35m");
	ft_strcpy(color[BLU], "\033[1;34m");
	ft_strcpy(color[PUR], "\033[1;94m");
	ft_strcpy(color[PRR], "\033[1;36m");
	ft_strcpy(color[GRE], "\033[1;32m");
	ft_strcpy(color[YEL], "\033[1;33m");
	ft_strcpy(color[STD], "\033[1;39m");
    data = get_data(NULL);
	free(data->color);
	data->color = ft_strdup(color[data->color_nb - 10]);
	brain_print();
}

static void	    normal_color(void)
{
    t_data  *data;
	char	color[COLOR_NB][10];

	ft_strcpy(color[RED], "\033[31m");
	ft_strcpy(color[PIN], "\033[35m");
	ft_strcpy(color[BLU], "\033[34m");
	ft_strcpy(color[PUR], "\033[94m");
	ft_strcpy(color[PRR], "\033[36m");
	ft_strcpy(color[GRE], "\033[32m");
	ft_strcpy(color[YEL], "\033[33m");
	ft_strcpy(color[STD], "\033[39m");
    data = get_data(NULL);
	free(data->color);
	data->color = ft_strdup(color[data->color_nb]);
	brain_print();
}

void	        change_color(int action)
{
    t_data  *data;

    data = get_data(NULL);
	if (action == TAB)
	{
		if (data->color_nb == COLOR_NB - 1)
			data->color_nb = 0;
		else if (data->color_nb == COLOR_NB + 9)
			data->color_nb = 10;
		else
			data->color_nb = data->color_nb + 1;
	}
	if (action == ALT_C)
	{
		if (data->color_nb < 10)
			data->color_nb = data->color_nb + 10;
		else
			data->color_nb = data->color_nb - 10;
	}
	if (data->color_nb < 10)
		normal_color();
	else
		bold_color();
}