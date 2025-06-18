#include "fractol.h"

int	ft_ncmp(char *s1, char *s2, int n)
{
	if (!s1 || !s2 || !n)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	put_error(void)
{
	char	*str;

	str = ERROR_MSG;
	while (str && *str)
		write(STDERR_FILENO, str++, 1);
}

double	atodouble(char *str, int sign, double power)
{
	long	interger;
	double	decimal;

	interger = 0;
	decimal = 0.0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		interger = interger * 10 + *str++ - '0';
	if (*str == '.')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		power /= 10;
		decimal = decimal + (*str++ - '0') * power;
	}
	return (interger + decimal * sign);
}
