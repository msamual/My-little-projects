#include <stdio.h>
#include <stdlib.h>
/*** размер памяти ***/
#define MEMORY 100
/*** коды операций ***/
#define READ	10
#define WRITE	11
#define LOAD	20
#define STORE	21
#define ADD		30
#define SUB		31
#define DIV		32
#define MUL		33
#define BRANCH	40
#define BRANCHNEG	41
#define BRANCHZERO	42
#define HALT		43

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
		while ((tmp > 9999 || tmp < -9999) && tmp != -99999) {
			printf("Введите число в диапазоне от -9999 до 9999: ");
			scanf("%d", &tmp);
		}
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
void error(int accumulator, int memory[], int operation_code, int operand)
{
	if (memory[operand] == 0 && operation_code == DIV) {
		printf("*** Попытка деления на ноль ***\n");
		printf("*** Симплетрон аварийно завершил выполнение программы***\n");
		dump(memory);
		exit(1);
	}
	if (accumulator < -9999 || accumulator > 9999) {
		printf("*** Переполнение аккумулятора! ***\n");
		printf("*** Симплетрон аварийно завершил выполнение программы***\n");
		dump(memory);
		exit(1);
	}
}

void	interpretator(int memory[])
{
	int accumulator = 0;
	int inst_counter = 0;
	int inst_register = 0;
	int operation_code = 0;
	int operand = 0;

	while (inst_counter < MEMORY) {
		inst_register = memory[inst_counter];
		operation_code = inst_register / 100;
		operand = inst_register % 100;
		if (operation_code == READ) {
			printf("Введите число: ");
			scanf("%d", &memory[operand]);
		}
		if (operation_code == WRITE)
			printf("%d\n", memory[operand]);
		if (operation_code == LOAD)
			accumulator = memory[operand];
		if (operation_code == STORE)
			memory[operand] = accumulator;
		if (operation_code == ADD)
			accumulator = accumulator + memory[operand];
		if (operation_code == SUB)
			accumulator = accumulator - memory[operand];
		if (operation_code == DIV) {
			error(accumulator, memory, operation_code, operand);
			accumulator = accumulator / memory[operand];
		}
		if (operation_code == MUL)
			accumulator = accumulator * memory[operand];
		inst_counter++;
		if (operation_code == BRANCH)
			inst_counter = operand;
		if (operation_code == BRANCHNEG && accumulator < 0)
			inst_counter = operand;
		if (operation_code == BRANCHZERO && accumulator == 0)
			inst_counter = operand;
		if (operation_code == HALT) {
			printf("*** Симплетрон закончил свои вычисления ***\n");
			break ;
		}
		error(accumulator, memory, operation_code, operand);
	}
}

int		main(void)
{
	int memory[100] = {0};

	instruction();
	scaner(memory);
	interpretator(memory);
	return (0);
}
