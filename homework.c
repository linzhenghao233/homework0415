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

	password();		//����������ܽ���ϵͳ

	while (getchar() != EOF) {
		mainmenu();
		printf("\t\t��ѡ�����˵���ţ�0~5����");
		scanf_s("%d", &choose);

		switch (choose) {
		case 1:stu_score[stu_count] = inputscore(), stu_count++; break;
		case 2:displayscore(stu_count - 1, stu_score); break;
		case 3:sumavgscore(stu_count - 1, stu_score); break;
		case 4:maxminscore(stu_count - 1, stu_score); break;
		case 5:gradescore(stu_count - 1, stu_score); break;
		case 0:return 0;
		default:printf("\n\t\t������Ч��������ѡ��\n");
		}

		while (getchar() != '\n');

		printf("\n\n\t\t���س��������˵�");
	}
}

void password() {
	char pwd[] = {'l', 'z', 'h', '2', '3', '3', '\0'}, ch;
	int i;
	i = 0;

	printf("���������룺");
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			break;

		if (ch != pwd[i])
			break;
		i++;
	}
	if (i == strlen(pwd))
		printf("������ȷ���س�����˵���");
	else {
		printf("�������");
		while (getchar() != '\n');
		password();
	}
}

void mainmenu() {
	system("cls");
	printf("\n\n");
	printf("\t\t|----------------------------------------|\n");
	printf("\t\t|		ѧ���ɼ�ͳ��ϵͳ	 |\n");
	printf("\t\t|----------------------------------------|\n");
	printf("\t\t|		1--¼��ѧ���ɼ�		 |\n");
	printf("\t\t|		2--��ʾѧ���ɼ�		 |\n");
	printf("\t\t|		3--ͳ���ֺܷ�ƽ����	 |\n");
	printf("\t\t|		4--ͳ����߷ֺ���ͷ� 	 |\n");
	printf("\t\t|		5--ͳ�Ƹ�����������	 |\n");
	printf("\t\t|		0--�˳�			 |\n");
	printf("\t\t|----------------------------------------|\n");
}

int inputscore() {
	int score;

	printf("����һ���ɼ���");
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

	printf("�ܷ�Ϊ��%d\nƽ����Ϊ��%g", sum, sum / ((double)stu_count + 1));
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

	printf("���ֵ��%d\n��Сֵ��%d", max, min);
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
	printf("С��60��������%d\n60-90��������%d\n���ڵ���90��������%d",
		fail, pass, excellence);
}