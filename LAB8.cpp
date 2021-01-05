#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
char** input(int);
void output(int, char**);
void find(char**, int);
int main()
{
	char** str, let;
	int n, i, j;
	setlocale(LC_ALL, "russian");
	do {
		fflush(stdin);
		printf("Введите количество строк текста\n");
		scanf_s("%d", &n);
	} while (!n || n <= 0);
	n++;
	fflush(stdin);
	printf("Введите текст\n");
	str = input(n);
	printf("\nпредложения с четным количеством слов:\n");
	for (j = 0; j < n; j++)
	{
		find(str, j); //  передаем в функцию строку
	}
	free(str);
	return 0;
}
char** input(int n)
{
	char** str;
	if (!(str = (char**)calloc(n, sizeof(char*))))
	{
		printf("\nНедостаточно свободной памяти \n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (*(str + i) = (char*)calloc(255, sizeof(char)))
		{
			fgets(*(str + i), 255, stdin);
		}
	}
	return str;
}
void output(int n, char** str)
{
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (*(*(str + i) + j) != '\0')
		{
			printf("%c", *(*(str + i) + j));
			j++;
		}
	}
}
void find(char** str, int j)
{
	int k, i, i1, i2, l;
	i = k = i2 = 0;
	while (*(*(str + j) + i) != '\n') 
	{
		k = 0;
		i1 = i;
		while (*(*(str + j) + i) != '.')
		{
			while (*(*(str + j) + i) == ' ' || *(*(str + j) + i) == '.')i++;
			k++;
			while (*(*(str + j) + i) != ' '&& *(*(str + j) + i) != '.')i++;
			i2 = i;
		}
		if (k % 2 == 0)
		{
			for (l = i1; l<=i2; l++)
				printf("%c", *(*(str + j) + l));
		}
		i++;
	}
}