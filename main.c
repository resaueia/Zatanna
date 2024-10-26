#include <stdio.h>
#include <unistd.h>

int		len(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	reverse(char *cmd)
{
	int		i = len(cmd);
	int		j = 0;
	char	temp;

	while (i >= j)
	{
		temp = cmd[j];
		cmd[j] = cmd[i];
		cmd[i] = temp;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i = 0;
	char	*cmd;
	int		count = argc;

	if (argc < 1)
		return (0);
	else
	{
		cmd = argv[1];
		while (cmd[i])
		{
			if (cmd[i] == ' ' || cmd[i] >= 7 && cmd[i] <= 13)
			{
				i++;
				continue;
			}
			else if ((cmd[i] >= 'a' && cmd[i] <= 'z') && (cmd[i - 1] == ' ' || cmd[i - 1] == '\t'))
			{
				cmd[i] = cmd[i] - 32;
			}
			write(1, &cmd[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
