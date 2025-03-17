#include "../includes/push_swap.h"

int	checker_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result 0;
	result = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-' )
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0')
		i++;
	}
	return (result * sign);

}

void	single_arg_checker(char *numbers)
{

}

void	multiple_arg_checker(char **str)
{

}

int	arg_checker(char **argv, int argc)
{
	if(argc == 2)
		single_arg_checker(argv[1]);
	else if (argc > 2)
		multiple_arg_checker(argv);
	return (0);
}