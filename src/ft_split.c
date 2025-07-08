/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:42:38 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/02 19:56:30 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *input, char separator)
{
	bool	flag;
	int		ret;

	ret = 0;
	while (*input)
	{
		flag = false;
		while (*input == separator)
			input++;
		while (*input != separator && *input)
		{
			if (flag == false)
			{
				flag = true;
				ret++;
			}
			input++;
		}
	}
	return (ret);
}

/**
 * tester count words
int main(){
    ft_printf("%d\n", count_words("1212 1212 SAAS", ' '));
    ft_printf("%d\n", count_words("asdfas   as asdf      asdfa", ' '));
    ft_printf("%d\n",
	count_words("-------------------asdfasdfasasdfas---------00000---", '-'));
}*/

static char	*word_extract(char *input, char separator)
{
	char			*ret;
	int				size;
	int				j;
	static int		i = 0;

	while (input[i] && input[i] == separator)
		i++;
	size = 0;
	while (input[i + size] && input[i + size] != separator)
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	j = 0;
	while (j < size)
		ret[j++] = input[i++];
	ret[size] = '\0';
	return (ret);
}
/**
 * tester count words

int	main(void)
{
	char	*str = "hola que                          tal";
	char	*word1 = word_extract(str, ' ');
	char	*word2 = word_extract(str, ' ');
	char	*word3 = word_extract(str, ' ');

	ft_printf("%s\n", word1);
	ft_printf("%s\n", word2);
	ft_printf("%s\n", word3);
	free(word1);
	free(word2);
	free(word3);
}
*/

/**
 * Separa las palabras en un array de strings
*/
char	**ft_split2(char *input, char separator)
{
	int		words_number;
	char	**ret;
	int		i;

	i = 0;
	words_number = count_words(input, separator);
	ret = malloc(sizeof(char *) * (words_number + 2));
	if (ret == NULL)
		return (NULL);
	ret[i] = ft_strdup("42");
	i++;
	while (words_number-- > 0)
	{
		ret[i] = word_extract(input, separator);
		if (!ret[i])
		{
			while (i > 0)
				free(ret[--i]);
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	i = 0;
	return (ret);
}

/**
 * tester ft_split

int	main(void)
{
	char *a = "hola   qu4 ee tt tal";
	char **ret = ft_split2(a, ' ');

	for (int i = 0; ret[i] != NULL; i++)
	{
		ft_printf("%s\n", ret[i]);
		free(ret[i]);
	}
	free(ret);
}
*/
