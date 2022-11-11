#include "../../header.h"

int	check_line_in_list(char *line, char **list)	// If the line doesn't exist, returns 0; Otherwise, returns the index in the list. 
{
	int	i;
	
	i = -1;
	while (list[++i])
	{
		if (!ft_strncmp(line, list[i], ft_strlen(line)))
			return (i);
	}
	return (0);
}

void parsing(char *line, char c) // Removes the character's first and next occurrences from the string and then returns the string. 
{
	char	*ptr1;

    while (1)
    {
        ptr1 = ft_strchr(line, c);
        if (ptr1 == NULL)
        	break;
        else if (ft_strchr(ptr1 + 1, c) == NULL)
        	break;
        else
        {
            printf("teste");
        	ft_memmove(&line[ptr1 - line], &line[ptr1 - line + 1], ft_strlen(line) - (ptr1 - line));
        	ptr1 = ft_strchr(ptr1, c);
        	ft_memmove(&line[ptr1 - line], &line[ptr1 - line + 1], ft_strlen(line) - (ptr1 - line));
        }
    }
    return ;
}

int	len_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_cpy(char *dest, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		dest[i] = str[i];
	return (dest);
}