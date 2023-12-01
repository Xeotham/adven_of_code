/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:54:59 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/01 22:02:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

int	spell_check_front(char *str, int *k)
{
	char	*number[10];
	int		i;

	i = 1;
	number[1] = "one";
	number[2] = "two";
	number[3] = "three";
	number[4] = "four";
	number[5] = "five";
	number[6] = "six";
	number[7] = "seven";
	number[8] = "eight";
	number[9] = "nine";
	while (i < 10)
	{
		if (ft_strnstr(str, number[i], ft_strlen(number[i])) != 0)
		{
			*k = ft_strlen(number[i]);
			return (i);
		}
		i++;
	}
	return (-1);
}

int	spell_check_back(char *str, int *ind)
{
	char	*number[10];
	int		i;

	i = 1;
	number[1] = "one";
	number[2] = "two";
	number[3] = "three";
	number[4] = "four";
	number[5] = "five";
	number[6] = "six";
	number[7] = "seven";
	number[8] = "eight";
	number[9] = "nine";
	while (i < 10)
	{
		if (ft_strnstr(str, number[i], ft_strlen(number[i])) != 0)
		{
			(*ind) += ft_strlen(number[i]) - 1;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	find_first_number(char *str, int *d)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			*d = i;
			return (str[i] - '0');
		}
		else if ((j = spell_check_front(str + i, &k)) != -1)
		{
			*d = i + k;
			return (j);
		}
		i++;
	}
	return (-1);
}

int	find_last_number(char *str)
{
	int	k;
	int	ret;
	int	tmp_spell;

	k = 0;
	while (str[k])
	{
		if (ft_isdigit(str[k]) == 1)
		{
			ret = str[k] - '0';
			k++;
		}
		else if ((tmp_spell = spell_check_back(str + k, &k)) != -1)
			ret = tmp_spell;
		else
			k++;
	}
	return (ret);
}

int	find_number(char *str)
{
	int		number;
	int		f_num;
	int		l_num;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strtrim(str, "\n");
	if (!tmp)
		return (0);
	f_num = find_first_number(tmp, &i);
	l_num = find_last_number(tmp + i);
	if (f_num == -1)
		return (0);
	number = (f_num * 10) + l_num;
	return (number);
}

int	main(void)
{
	char *buffer;
	int fd;
	int number;
	int sum;

	fd = open("input", O_RDONLY);
	buffer = ft_calloc(1, 1);
	sum = 0;
	while (buffer)
	{
		buffer = get_next_line(fd);
		number = find_number(buffer);
		ft_printf("%d\n", number);
		sum += number;
        ft_printf("sum : %d\n", sum);
		free(buffer);
	}
	ft_printf("resultat : %d", sum);
	return (0);
}