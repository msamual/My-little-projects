#include <stdio.h>

#define MEMORY 100

void	instruction(void)
{
	printf("*** Симплетрон приветствует вас! ***\n\
*** Пожалуйста, введите вашу программу, по одной комманде ***\n\
*** (или слову данных) за раз. Я буду выводить в качестве ***\n\
*** подсказки текущий адрес и знак вопроса (?). Введенное ***\n\
*** вами слово будет размещено по указанному адресу. Для  ***\n\
*** прекращения ввода программы введите число -99999.     ***\n");
}

void	scaner(int memory[])
{
	int tmp  = 0;

	for (int i = 0; i < MEMORY; i++) {
		if (i < 10)
			printf("0");
		printf("%d? ", i);
		scanf("%d", &tmp);
		if (tmp == -99999)
			break ;
		memory[i] = tmp;
	}
	printf("*** Загрузка программы завершена ***\n\
*** Начинаю выполнение программы ***\n");
}

void	dump(int memory[])
{
	printf("ПАМЯТЬ:\n\
	0	1	2	3	4	5	6	7	8	9");
	for (int i = 0; i < MEMORY; i++) {
		if (i % 10 == 0)
			printf("\n%2d  ", i);
		printf("+");
		if (memory[i] / 1000 == 0)
			printf("0");
		if (memory[i] / 100 == 0)
			printf("0");
		if (memory[i] / 10 == 0)
			printf("0");
		printf("%d   ", memory[i]);
	}
	printf("\n");
}

int		main(void)
{
	int memory[100] = {0};

	instruction();
	scaner(memory);
	dump(memory);
	return (0);
}
