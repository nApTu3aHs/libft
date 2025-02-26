#include <limits.h>
#include "libft.h"

static unsigned long long mod(long double a, int b)
{
	if (a > (long double)(ULONG_LONG_MAX))
		return (0);
	return (((unsigned long long)a) % b);
}

static long double round(long double x, int decimals, int base)
{
	long double pow;

	pow = (long double)ft_ullpow(base, decimals);
	if ((int)x != (((int)x) / 2) * 2)
		return (x + .5 / pow);
	if (.5 / pow + (long double)((unsigned long long)(x * pow)) / pow - x)
		return (x + .5 / pow);
	return (x);
}

char *ft_ftoa_buf(char *s, long double n, int decimals)
{
	char *ptr;
	int base;
	long double m;

	base = 10;
	ptr = s;
	if (n < 0)
	{
		*ptr++ = '-';
		n *= -1;
	}
	n = round(n, decimals, base);
	m = n;
	if (m < 1.)
		*ptr++ = '0';
	while (m >= 1.)
	{
		*ptr++ = '0' + (int)mod(m, base);
		m /= base;
	}
	*ptr = 0;
	ft_strrev(*s == '-' ? s + 1 : s);
	if (!decimals)
		return (s);
	*ptr++ = '.';
	while (decimals--)
	{
		n *= base;
		*ptr++ = '0' + (int)(mod(n, base));
	}
	*ptr = 0;
	return (s);
}

char *ft_ftoa(long double n, int decimals)
{
	size_t d;
	char *s;
	int base;

	base = 10;
	d = ft_count_int_digits((long int)n, base) + decimals + 1;
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	return (ft_ftoa_buf(s, n, decimals));
}
