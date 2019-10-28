#include <unistd.h>

void	decrementation(char *fuck, char octet[2048], int *index, int pointer);
void	incrementation(char *fuck, char octet[2048], int *index, int pointer);

void	incrementation(char *fuck, char octet[2048], int *index, int pointer)
{
	while (fuck[*index] != ']' && fuck[*index] != '\0')
		*index += 1;
	if (fuck[*index] == ']' && octet[pointer] == 0)
		decrementation(fuck, octet, index, pointer);
	return ;
}

void	decrementation(char *fuck, char octet[2048], int *index, int pointer)
{
	while (fuck[*index] != '[' && *index > 0)
		*index -= 1;
	if (fuck[*index] == '[' && octet[pointer] == 0)
		incrementation(fuck, octet, index, pointer);
	return ;
}

void	brainfuck(char *fuck)
{
	char	octet[2048];
	int		index;
	int		pointer;

	index = 0;
	pointer = 0;
	while (fuck[index])
	{
		if (fuck[index] == '.')
			write(1, &octet[pointer], 1);
		if (fuck[index] == '>')
			pointer++;
		if (fuck[index] == '<')
			pointer--;
		if (fuck[index] == '+')
			octet[pointer] += 1;
		if (fuck[index] == '-')
			octet[pointer] -= 1;
		if (fuck[index] == '[' && octet[pointer] == 0)
			incrementation(fuck, octet, &index, pointer);
		if (fuck[index] == ']' && octet[pointer] != 0)
			decrementation(fuck, octet, &index, pointer);				
		index++;
	}
}

int		main(int argc, char **argv)
{
	brainfuck(argv[1]);
	return (0);
}
