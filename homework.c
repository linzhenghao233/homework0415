#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTU 10

int inputscore();
void displayscore(int, int);
void sumavgscore(int, int);
void maxminscore(int, int);
void gradescore();
void password();
void mainmenu();

int main(void) {
	int stu_score[MAXSTU], stu_count, choose, i;
	stu_count = 0;

	password();		//输入密码才能进入系统

	while (getchar() != EOF) {
		mainmenu();
		printf("\t\t请选择主菜单序号（0~5）：");
		scanf_s("%d", &choose);

		switch (choose) {
		case 1:stu_score[stu_count] = inputscore(), stu_count++; break;
		case 2:displayscore(stu_count - 1, stu_score); break;
		case 3:sumavgscore(stu_count - 1, stu_score); break;
		case 4:maxminscore(stu_count - 1, stu_score); break;
		case 5:gradescore(stu_count - 1, stu_score); break;
		case 0:return 0;
		default:printf("\n\t\t输入无效，请重新选择\n");
		}

		while (getchar() != '\n');

		printf("\n\n\t\t按回车返回主菜单");
	}
}

void password() {
	char pwd[] = {'l', 'z', 'h', '2', '3', '3', '\0'}, ch;
	int i;
	i = 0;

	printf("请输入密码：");
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			break;

		if (ch != pwd[i])
			break;
		i++;
	}
	if (i == strlen(pwd))
		printf("密码正确！回车进入菜单。");
	else {
		printf("密码错误！");
		while (getchar() != '\n');
		password();
	}
}

void mainmenu() {
	system("cls");
	printf("\n\n");
	printf("\t\t|----------------------------------------|\n");
	printf("\t\t|		学生成绩统计系统	 |\n");
	printf("\t\t|----------------------------------------|\n");
	printf("\t\t|		1--录入学生成绩		 |\n");
	printf("\t\t|		2--显示学生成绩		 |\n");
	printf("\t\t|		3--统计总分和平均分	 |\n");
	printf("\t\t|		4--统计最高分和最低分 	 |\n");
	printf("\t\t|		5--统计各分数段人数	 |\n");
	printf("\t\t|		0--退出			 |\n");
	printf("\t\t|----------------------------------------|\n");
}

int inputscore() {
	int score;

	printf("输入一个成绩：");
	scanf_s("%d", &score);

	return score;
}

void displayscore(int stu_count,int* stu_score) {
	int i;

	for (i = 0; i <= stu_count; i++)
		printf("%d\n", stu_score[i]);
}

void sumavgscore(int stu_count, int* stu_score) {
	int sum, i;
	sum = 0;

	for (i = 0; i <= stu_count; i++)
		sum += stu_score[i];

	printf("总分为：%d\n平均分为：%g", sum, sum / ((double)stu_count + 1));
}

void maxminscore(int stu_count, int* stu_score) {
	int max, min, i;
	max = 0, min = 100;

	for (i = 0; i <= stu_count; i++) {
		if (stu_score[i] > max)
			max = stu_score[i];
		if (stu_score[i] < min)
			min = stu_score[i];
	}

	printf("最大值：%d\n最小值：%d", max, min);
}

void gradescore(int stu_count, int* stu_score) {
	int fail, pass, excellence, i;
	fail = pass = excellence = 0;

	for (i = 0; i <= stu_count; i++) {
		if (stu_score[i] < 60)
			fail++;
		else if (stu_score[i] >= 60 && stu_score[i] < 90)
			pass++;
		else if (stu_score[i] >= 90)
			excellence++;
	}
	printf("小于60的人数：%d\n60-90的人数：%d\n大于等于90的人数：%d",
		fail, pass, excellence);
}