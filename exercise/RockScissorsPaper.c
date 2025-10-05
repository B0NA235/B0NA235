//RockScissorsPaper.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void line();

int main() {
	char user;
	char computer_c;
	int computer;

	srand(time(NULL));
	while (1) {
		printf("가위(s), 바위(r), 보(p) 중 하나를 입력하세요 (다른 입력은 종료): ");
		scanf(" %c", &user);
		int computer = rand() % 3;//0: 묵, 1: 찌, 2: 빠
		switch (computer)
		{
			case 0:
				computer_c = 'r';
				break;
			case 1:
				computer_c = 's';
				break;
			case 2:
				computer_c = 'p';
				break;
		}
		if (computer_c == user)
		{
			printf("user: %c\ncomputer: %c\n", user, computer_c);
			printf("draw\n");
		}
		else if ((computer_c == 'r' && user == 's') || (computer_c == 's' && user == 'p') || (computer_c == 'p' && user == 'r'))
		{
			printf("user: %c\ncomputer: %c\n", user, computer_c);
			printf("You lose..\n");
		}
		else if ((user == 'r' && computer_c == 's') || (user == 's' && computer_c == 'p') || (user == 'p' && computer_c == 'r'))
		{
			printf("user: %c\ncomputer: %c\n", user, computer_c);
			printf("You win!\n");
		}
		else
		{
			printf("프로그램을 종료합니다\n");
			break;
		}
		line();
	}
	return 0;
}

void line()
{
	printf("---------------------------------------------------------\n");
}
