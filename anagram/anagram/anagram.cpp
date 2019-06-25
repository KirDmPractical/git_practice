#include "pch.h"
#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void do_anagramm(char *p, char *a, int lenth)
{
	int cycle = 0, position;
	srand(time(NULL));
	char text[1000];
	strcpy(text, p);
	
	while (cycle < lenth)
	{
		int loop = 0;
		position = rand() % lenth + 0;
	tryagain:
		//пропуск знаков, не предусмотренных задачей
		if (text[position] == '\n' || text[position] == '\0' || text[position] == '.' || text[position] == ' ' || text[position] == '\t' || text[position] == ';' || text[position] == ',' || text[position] == '!' || text[position] == '?')
		{
			if (loop == lenth)
				goto end;
			if (position == lenth)
			{
				position = 0;
				loop += 1;
				goto tryagain;
			}
			else
			{
				position += 1;
				loop += 1;
				goto tryagain;
			}
		}
		*(a + cycle) = text[position];
		text[position] = '.';
		cycle++;
	}
end:
	*(a + cycle) = '\0';
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char text[1001];
	int lenth = 0;
	printf("Программа превращает полученный текст в анаграмму, игнорируя пробелы и знаки препинания.");
	printf("\nМаксимальная длинна текста: 1000 знаков\n");
	printf("Введите ваш текст:\n");
	//Ввод пользовательского текста посимвольно
	while (lenth < 1000 && text[lenth - 1] != '\n')
	{
		text[lenth] = getchar();
		lenth += 1;
	}
	text[lenth] = '\0';
	lenth -= 1;
	char * anagramm = (char*)malloc(lenth + 1);
	do_anagramm(&text[0], &anagramm[0], lenth);
	printf("Полученная анаграмма: ");
	puts(anagramm);
	return 0;
}