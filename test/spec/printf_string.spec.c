#include <criterion/criterion.h>
#include "ft_printf.h"

Test(printf_string, null)
{
	char *dest;

	ft_aprintf(&dest, "%s", NULL);
	cr_expect_str_eq(dest, "(null)");
}

Test(printf_string, pad_null)
{
	char *dest;

	ft_aprintf(&dest, "%10s", NULL);
	cr_expect_str_eq(dest, "    (null)");
}

Test(printf_string, pad_null_wildcard)
{
	char *dest;

	ft_aprintf(&dest, "%*s", 10, NULL);
	cr_expect_str_eq(dest, "    (null)");
}

Test(printf_string, normal_string)
{
	char *dest;

	ft_aprintf(&dest, "%s", "normal");
	cr_expect_str_eq(dest, "normal");
}

Test(printf_string, pad_normal_string_wildcard)
{
	char *dest;

	ft_aprintf(&dest, "%*s", 10, "normal");
	cr_expect_str_eq(dest, "    normal");
}

Test(printf_string, normal_string_cutoff)
{
	char *dest;

	ft_aprintf(&dest, "%.5s", "hello world");
	cr_expect_str_eq(dest, "hello");
	ft_aprintf(&dest, "%.5s", "world");
	cr_expect_str_eq(dest, "world");
	ft_aprintf(&dest, "%.2s", "world");
	cr_expect_str_eq(dest, "wo");
	ft_aprintf(&dest, "%.10s", "world");
	cr_expect_str_eq(dest, "world");
}

Test(printf_string, normal_string_cutoff_wildcard)
{
	char *dest;

	ft_aprintf(&dest, "%.*s", 5, "HELLO FELLOW HUMAN");
	cr_expect_str_eq(dest, "HELLO");
	ft_aprintf(&dest, "%.*s", 5, "");
	cr_expect_str_empty(dest);
}

Test(printf_string, leftpad_normal_string)
{
	char *dest;
	char *dest2;

	ft_aprintf(&dest, "%-5s", "HI");
	cr_expect_str_eq(dest, "HI   ");
	ft_aprintf(&dest2, "%-1s", "HI");
	cr_expect_str_eq(dest2, "HI");
}

Test(printf_string, leftpad_normal_string_wildcard)
{
	char *dest;

	ft_aprintf(&dest, "%-*s", 5, "HI");
	cr_expect_str_eq(dest, "HI   ");
	cr_expect_eq(ft_aprintf(&dest, "%-*s", 1, "HI"), 2);
	cr_expect_str_eq(dest, "HI");
}

Test(printf_string, complicated_string)
{
	char *dest;

	ft_aprintf(&dest, "%-*.*s:%s", 10, 5, "fight me", "now");
	cr_expect_str_eq(dest, "fight     :now");
}