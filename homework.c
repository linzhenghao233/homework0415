#include <stdio.h>
#include <string.h>
#define MAXSTU 10

int inputscore();
void displayscore();
void sumavgscore();
void maxminscore();
void gradescore();
void password();
void mainmenu();

int main(void) {
	int stu_score[MAXSTU], stu_count, choose;
	stu_count = 0;

	password();

	return 0;
}

void password() {
	char pwd[] = {'l', 'z', 'h', '2', '3', '3', '\0'}, ch;
	int i;
	i = 0;

	printf("ÇëÊäÈëÃÜÂë£º");
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			break;

		if (ch != pwd[i])
			break;
		i++;
	}
	if (i == strlen(pwd))
		printf("ÃÜÂëÕıÈ·£¡");
	else {
		printf("ÃÜÂë´íÎó£¡ÇëÔÙ´ÎÊäÈëÃÜÂë£º");
		password();
	}
}