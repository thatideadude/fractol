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
