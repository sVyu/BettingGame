// 201533797 ��ǻ�Ͱ��а� ������
// BettingGame.c

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define SCTA SetConsoleTextAttribute
#define GSH GetStdHandle
#define SOH STD_OUTPUT_HANDLE
#define id_size 6				// id_box[id_size]
void game_start(void);			// ������ �����ϱ� ���� �Լ��Դϴ�
void game_how(void);			// ���� ����� �����ֱ� ���� �Լ��Դϴ�
void game_make_record(void);	// ���� �� ������ ����� ���Ϸ� �����մϴ� ( ó�� 1ȸ�� )
void game_record_see(void);		// ���� �� ������ �����ֱ� ���� �Լ��Դϴ�
void game_id(void);				// ���� ���̵� �����ϱ� ���� �Լ��Դϴ�
void game_select(void);			// ���� ���� ȭ�� ���� �Լ��Դϴ�
int game_race(int);				// [�渶] ���� �Լ��Դϴ�
int game_777(int);				// [777] ���� �Լ��Դϴ�
int game_wbg(int);				// [���� ����] ���� �Լ��Դϴ� ( where ball go )
void game_record_regist(int);	// ���� ���(����)�� �����ϱ� ���� �Լ��Դϴ�
char id_box[id_size] = { "\0" };	// ���̵� ����� ���ڿ��Դϴ� �ִ� 5�ڸ��� ���̵� �����մϴ�
FILE *fp = NULL;

struct user {				// ������� ������ �����ϱ� ���� ����ü�Դϴ�
	int ranking;			// ��ŷ ��Ͽ� �����Դϴ�
	char id[id_size];		// id ��Ͽ� ���ڿ��Դϴ�
	int score;				// ���� ��Ͽ� �����Դϴ�
};

int main(void)
{
	system("title ______________________________________________________________________________________________    �ڡ� Betting Game �١�    _____________________________________________________________________________");	// cmd Ÿ��Ʋ ����
	system("mode con: cols=100 lines=25 ");			// cmd â ũ�� ����
	game_start();				// game_start �Լ� ����, ���� ���� ȭ���� ���ɴϴ�
	return 0;
}

void game_start(void)
{
	int updown = 0;		// ���� ��ŸƮ -> 0, ���� ��� -> 1, ���� ���� -> 2, ������ -> 3 �� ���¸� �����ϱ� ���� �����Դϴ�
	char word = ' ';
	int i = 0;

	game_make_record();		// ó�� 1ȸ�� ���(����)�� ������ݴϴ�

	SCTA(GSH(SOH), 0x000f);		// ��� ���ڷ� ����
	while (1)
	{
		int check = 0;			// while ���� ���ǿ� �°� Ż���ϱ� ���� check ������ �����Ͽ����ϴ�
		printf("\n\n\n");
		SCTA(GSH(SOH), 0x000d);
		printf("\t  ��������                                ��������                  ���������� \n");
		SCTA(GSH(SOH), 0x000e);
		printf("\t  ��    ��        ������ ������ ��        ��                        ��         \n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t  ��������������    ��     ��   �� ������ ��  ������  ������������������������ \n");
		SCTA(GSH(SOH), 0x000d);
		printf("\t  ��      ������    ��     ��   �� ��  �� ��      ����������  ��  ����         \n");
		SCTA(GSH(SOH), 0x0004);
		printf("\t  ��������������    ��     ��   �� ��  �� ������������������  ��  ������������ \n\n\n\n");
		SCTA(GSH(SOH), 0x000f);
		if (updown == 0)
		{
			SCTA(GSH(SOH), 0x000e);	// ����� ���ڸ� ���� �ڵ��Դϴ�
			printf("					<< ���� ��ŸƮ >>\n\n");
			SCTA(GSH(SOH), 0x000f);	// ��� ���ڸ� ���� �ڵ��Դϴ�
		}
		else
			printf("					   ���� ��ŸƮ\n\n");


		if (updown == 1)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("					 << ���� ��� >>\n\n");
			SCTA(GSH(SOH), 0x000f);
		}
		else
			printf("					    ���� ���\n\n");


		if (updown == 2)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("					 << ���� ���� >>\n\n");
			SCTA(GSH(SOH), 0x000f);
		}
		else
			printf("					    ���� ����\n\n");


		if (updown == 3)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("					  << ������ >>\n\n\n");
			SCTA(GSH(SOH), 0x000f);
		}
		else
			printf("					     ������\n\n\n");

		SCTA(GSH(SOH), 0x0006);
		printf("\t\t[  ���� Ű ]  W : �� / S : �Ʒ� / J : ��ư / Enter : �� �Է�\n");
		printf("\t\t[  ������  ]  201533797 ��ǻ�Ͱ��а� ������");
		SCTA(GSH(SOH), 0x000f);

		while (word = _getch())	// ���ڸ� �Է¹޾Ƽ� ���� �ڵ�鿡 ���� ���ǿ� �°� ó���մϴ�
		{
			if (word == 's' || word == 'S' || word == 'w' || word == 'W' || word == 'j' || word == 'J')
				check = 1;

			if (word == 's' || word == 'S')		// S�� �Է��� ��
				if (updown == 3)		// << ������ >> ���� �� ������ ������ �ϸ� ������� ���ϴ�
					printf("\a");
				else
					updown += 1;

			else if (word == 'w' || word == 'W')	// W�� �Է��� ��
				if (updown == 0)		// << ���� ��ŸƮ >> ���� �� ���� ������ �ϸ� ������� ���ϴ�
					printf("\a");

				else
					updown -= 1;

			else if (word == 'j' || word == 'J')	// J�� �Է��� ��
				if (updown == 0)		// << ���� ��ŸƮ >> ������ �����մϴ�
				{
					game_id();
					game_select();
					system("pause");
				}
				else if (updown == 1)		// << ���� ��� >> ���� ����� �����ݴϴ�
					game_how();				// game_how() �Լ��� ȣ���մϴ�

				else if (updown == 2)		// << ���� ���� >> ������ �����ݴϴ�
					game_record_see();

				else
				{
					printf("\n\n\t\t\t\t");
					SCTA(GSH(SOH), 0x0003);
					check = 2;
					break;				// updown == 3 �̸鼭 word == 'j'�� ����, �� << ������ >> ���� jŰ�� �������Ƿ� ������ �����մϴ�
				}

			if (check > 0)		// check == 1 || check == 2
				break;
			else
				continue;
		}
		if (check == 2)
			break;
		system("cls");				// ���� ȭ���� ����ϴ�
	}
}

void game_how(void)
{
	char check = ' ';		// JŰ�� �����߸� �� �Լ���(ȭ����) ����� ���� ���ǵ� check�Դϴ�
	system("cls");
	printf("									    ����������������������\n");
	printf("									    �� �� �ڷ� ���� : J ��\n");
	printf("									    ����������������������");
	printf("\n\n\n\t\t\t");
	SCTA(GSH(SOH), 0x000d);
	printf("�ڡ� Betting Game �١� ");
	SCTA(GSH(SOH), 0x000f);
	printf("�� ���� ���� ȯ���մϴ� !\n\n\n\n");
	printf("\t\t������ ���� �Ǹ� �����е鿡�Դ� ������ �� �� �ִ� ");
	SCTA(GSH(SOH), 0x000b);
	printf("5���� ��ȸ");
	SCTA(GSH(SOH), 0x000f);
	printf(" �� �־�����\n\n");
	printf("\t\t���Ѵٸ� �߰��� ������ ���� ���� �ֽ��ϴ�\n\n");
	printf("\t\tBetting Game��");
	SCTA(GSH(SOH), 0x000a);
	printf(" [�渶] [777] [���� ����]");
	SCTA(GSH(SOH), 0x000f);
	printf(" �� ���� ������ ������\n\n");
	printf("\t\t������ ���� �������δ�");
	SCTA(GSH(SOH), 0x000e);
	printf(" ��100���� ���Ρ� ");
	SCTA(GSH(SOH), 0x000f);
	printf("�� �־����ϴ�\n\n");
	printf("\t\t���Ӹ��� ������ �ٸ��Ƿ� �����ϰ� �ϼž� �մϴ�\n\n");
	printf("\t\t������ ���� ������ �����ø� �˴ϴ� ");
	while (check = _getch())
	{
		if (check == 'j' || check == 'J')
			break;
	}
	system("cls");
}

void game_make_record(void)
{
	if ((fp = fopen("BettingGameRecord.txt", "r")) == NULL)		// ���� ������ ó�� �Ѵٸ� (����� ���ٸ�) ����� ����� �ݴϴ�
	{
		struct user R[5];		// 5���� ����� �����ϱ� ���� 5���� ���ڵ�� �� ���� �̿����� ����� ��ų� �������� �뵵�� NULL ���ڵ带 ���ļ� 6���� ���ڵ�� ������ R[6]�Դϴ�
		int i;
		char id_NULL[id_size] = { "\0" };
		for (i = 0; i < 5; i++)					// R[0]���� R[5]���� �������� �����͸� �ֽ��ϴ�
		{
			if (i == 0)
			{
				R[i].ranking = 1;
				strcpy(R[i].id, "PSJ");
				R[i].score = 1000;
			}
			else if (i == 1)
			{
				R[i].ranking = 2;
				strcpy(R[i].id, "JSB");
				R[i].score = 500;
			}
			else if (i == 2)
			{
				R[i].ranking = 3;
				strcpy(R[i].id, "HGH");
				R[i].score = 300;
			}
			else if (i == 3)
			{
				R[i].ranking = 4;
				strcpy(R[i].id, "AAA");
				R[i].score = 200;
			}
			else
			{
				R[i].ranking = 5;
				strcpy(R[i].id, "BBB");
				R[i].score = 100;
			}
		}
		fp = fopen("BettingGameRecord.txt", "w");
		for (i = 0; i < 5; i++)
			fprintf(fp, "%d %-6s %d\n", R[i].ranking, R[i].id, R[i].score);		// ���Ͽ� �����͸� �����մϴ�

		fclose(fp);
	}
}

void game_record_see(void)
{
	int i, ranking = 0, score = 0;
	char id[6] = { "\0" };
	char check = ' ';
	system("cls");
	printf("									    ����������������������\n");
	printf("									    �� �� �ڷ� ���� : J ��\n");
	printf("									    ����������������������\n");
	SCTA(GSH(SOH), 0x000b);
	printf("\n\n\t\t\t\t\t   �� ���� ��\n\n");
	SCTA(GSH(SOH), 0x000f);
	printf("\t\t\t-----------------------------------------------\n");
	SCTA(GSH(SOH), 0x000e);
	printf("\t\t\t\t����	     ���̵�	   ����\n");
	SCTA(GSH(SOH), 0x000f);
	printf("\t\t\t-----------------------------------------------\n\n");
	fp = fopen("BettingGameRecord.txt", "r");
	for (i = 0; i < 5; i++)
	{
		fscanf(fp, "%d %s %d\n", &ranking, id, &score);		//���Ͽ��� ����(ranking), ���ڿ�, ����(score)�� �����ͷ� �н��ϴ�
		if (strcmp(id, id_box) == 0)
			SCTA(GSH(SOH), 0x000d);
		else
			SCTA(GSH(SOH), 0x000f);
		printf("\t\t\t\t %d\t      %-6s\t %6d\n\n", ranking, id, score);
	}
	SCTA(GSH(SOH), 0x000f);
	fclose(fp);
	printf("\t\t\t-----------------------------------------------\n\n");
	while (check = _getch())
	{
		if (check == 'j' || check == 'J')					// JŰ�� �Է��ϸ� while�ݺ����� Ż���մϴ�
			break;
	}

}

void game_id(void)
{
	int check = 0;					// check�� 1�� �Ǹ� �Լ��� ����ǰ� �����ϱ� ���� �����Դϴ�
	int id_check_i;					// ���̵� ���� �빮�ڷ� �Ǿ��ִ��� Ȯ���ϱ� ���� �����Դϴ�
	int k = 0;						// id_check[20]�� NULL �迭�� ����� ���� �����Դϴ�
	int i = 0;						// ���̵� �߸� �Է����� ��� ����� ����ϰ� �� Ƚ���� �����ϱ� ���� ���� i�Դϴ�
	char id_check[20] = { "\0" };		// ���̵� �ڸ��� üũ�� ���ڿ��Դϴ�
	while (check == 0)
	{
		fflush(stdin);					// ���۸� ���ϴ�
		for (k = 0; k < 20; k++)
			id_check[k] = '\0';
		check = 1;
		system("cls");
		SCTA(GSH(SOH), 0x000a);
		printf("\n\n\n\n\n\n\t\t\t\t\tID �� �����Ͻʽÿ�\n\n");
		SCTA(GSH(SOH), 0x000f);
		printf("\n\t\t\t\t     ( ���� �빮�� 3 ~ 5���� )");
		if (i == 0)
			printf("\n\n\n\t\t\t\t\t      ");
		if (i != 0)
		{
			SCTA(GSH(SOH), 0x000c);
			printf("\n\t\t\t\t     ���ǿ� �°� ����ʽÿ�(%d)\n\n\t\t\t\t\t       ", i);
			SCTA(GSH(SOH), 0x000f);
		}
		SCTA(GSH(SOH), 0x000e);
		gets(id_check);
		SCTA(GSH(SOH), 0x000f);
		if ((id_check[2] == NULL) || id_check[id_size - 1] != NULL)			// id�� 2���� ������ ��� �Ǵ� 5���ڰ� �Ѵ� ��� �ٽ� �Է��ϰ� �߽��ϴ�
		{
			check = 0;
			i++;
			continue;
		}
		strncpy(id_box, id_check, id_size);

		for (id_check_i = 0; id_box[id_check_i] != NULL; id_check_i++)
		{
			if (isupper(id_box[id_check_i]) == 0)	// ���� �빮�ڰ� �ƴ� ���ڰ� ������ �ٽ� �Է��ϰ� �մϴ�
			{
				check = 0;
				i++;
				break;
			}
		}
		if (check == 1)
		{
			SCTA(GSH(SOH), 0x000b);
			printf("\n\n\t\t\t\t\t���̵� ���� ���� !");
			SCTA(GSH(SOH), 0x000f);
		}
		Sleep(1000);
	}
}

void game_select(void)
{
	int select;					// �� ���� ������ ���� �����ϱ� ���� �����Դϴ�
	int count = 5;				// ���� ���� Ƚ���� �����ϱ� ���� �����Դϴ�
	int coin = 100;				// ������ ������ �����ϱ� ���� �����Դϴ�
	if (strcmp(id_box, "YBH") == 0)
		coin = 20000;
	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000d);
		printf("\t\t\t\t\t\t\t\t\t      [ ID : %s ]", id_box);

		printf("\n\n");
		SCTA(GSH(SOH), 0x0003);
		printf("\t����������������������         ����������������������         ����������������������\n");
		printf("\t��================= ��         ��                  ��         ��                  ��\n");
		printf("\t��  Z I             ��         ��================= ��         ��        ��        ��\n");
		printf("\t��================= ��         ��  ���� ���� ����  ��         ��                  ��\n");
		printf("\t��  Z I             ��         ��  ���� ���� ����  ��         ��      ��   ��     ��\n");
		printf("\t��================= ��         ��    ��   ��   ��  ��         ��                  ��\n");
		printf("\t��  Z I             ��         ��================= ��         ��   ��   ��    ��  ��\n");
		printf("\t��================= ��         ��                  ��         ��                  ��\n");
		printf("\t����������������������         ����������������������         ����������������������\n\n");
		SCTA(GSH(SOH), 0x000f);
		printf("\t          1                              2                               3\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t       [�渶]                          [777]                       [���� ����]\n\n\n");
		SCTA(GSH(SOH), 0x000b);
		printf("\t\t\t\t%d��", count);
		SCTA(GSH(SOH), 0x000f);
		printf("�� ��ȸ�� �ֽ��ϴ�");
		SCTA(GSH(SOH), 0x000e);
		printf(" ( ���� : %d�� )\n\n", coin);
		if (count == 0 || coin == 0)
		{
			if (count == 0)
				printf("\t\t\t\t���� ��ȸ�� �����Ƿ� ������ ����˴ϴ�.\n\n\t\t\t\t");

			else
				printf("\t\t\t\t������ �����Ƿ� ������ ����˴ϴ�.\n\n\t\t\t\t");

			system("pause");
			game_record_regist(coin);
			SCTA(GSH(SOH), 0x000f);
			game_record_see();
			printf("\t\t\t\t");
			break;
		}
		SCTA(GSH(SOH), 0x000f);
		printf("\t\t\t\t��� ������ �Ͻðڽ��ϱ�? (0:����) : ");
		SCTA(GSH(SOH), 0x000d);
		scanf_s(" %d", &select);
		if (select == 0)
		{
			game_record_regist(coin);
			SCTA(GSH(SOH), 0x000f);
			game_record_see();
			printf("\t\t\t\t");
			break;
		}

		else if (select == 1)
		{
			coin = game_race(coin);
			count--;
		}
		else if (select == 2)
		{
			coin = game_777(coin);
			count--;
		}
		else if (select == 3)
		{
			coin = game_wbg(coin);
			count--;
		}
		else
			continue;
	}


}

int game_race(int coin)
{
	char a[60] = { "Z  I" };
	char b[60] = { "Z  I" };
	char c[60] = { "Z  I" };
	int i;						// �迭 ��¿� �����Դϴ�
	int copy_coin = coin;		// ���� ���� ������ �����Դϴ�
	int a_check[2] = { 0 };		// ������ ��ġ�� ���ڷ� ��Ÿ���� ����� �����Դϴ�
	int b_check[2] = { 0 };
	int c_check[2] = { 0 };
	int winner_check[3] = { 0 };	// ���ڸ� ����ϱ� ���� �迭�Դϴ�. ���� ���ڰ� �߻��� ��츦 �����ؼ� �迭�� ��������ϴ�
	int winner_betting = 0;		// ����ڷκ��� ���ڸ� �����ؼ� ���ڷ� �Է¹ް� ���� ���� �����Դϴ�.
	int coin_put = 0;			// ���ǿ� �°� ������ �����ϰ� ����� ���� �����Դϴ�
	int coin_betting = 0;		// ������ ������ ���ڸ� �����ϱ� ���� �����Դϴ�
	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t\t\t\t\t     [�渶]\n\n\n");
		SCTA(GSH(SOH), 0x000e);
		printf("\t\t  =============================================================");
		SCTA(GSH(SOH), 0x000b);
		printf("\n\t\t     I\n\t\t1 ");
		for (i = 0; i < 60; i++)
		{
			printf("%c", a[i]);
		}
		printf("\n\t\t     I");
		SCTA(GSH(SOH), 0x000e);
		printf("\n\t\t  =============================================================");
		SCTA(GSH(SOH), 0x000c);
		printf("\n\t\t     I\n\t\t2 ");
		for (i = 0; i < 60; i++)
		{
			printf("%c", b[i]);
		}
		printf("\n\t\t     I");
		SCTA(GSH(SOH), 0x000e);
		printf("\n\t\t  =============================================================");
		SCTA(GSH(SOH), 0x000d);
		printf("\n\t\t     I\n\t\t3 ");
		for (i = 0; i < 60; i++)
		{
			printf("%c", c[i]);
		}
		printf("\n\t\t     I");
		SCTA(GSH(SOH), 0x000e);
		printf("\n\t\t  =============================================================\n\n\t\t\t\t");
		if (coin_put == 0)
		{
			printf("%d��", coin);
			SCTA(GSH(SOH), 0x000f);
			printf("�� ������ �ֽ��ϴ�.\n");
			SCTA(GSH(SOH), 0x000e);
			printf("\t\t\t\t�� ��");
			SCTA(GSH(SOH), 0x000f);
			printf("�� �����Ͻðڽ��ϱ�? (���� 3��) ");
			SCTA(GSH(SOH), 0x000b);
			scanf_s(" %d", &coin_betting);
			if (coin_betting > coin || coin_betting <= 0)						// ���� ���κ��� �� ���� ���� ������ �����Ϸ��� �ϸ� continue�� �մϴ�
			{
				printf("\t\t\t\t���� ������ Ȯ���Ͻʽÿ�\n\t\t\t\t");
				system("pause");
				continue;
			}
			printf("\t\t\t\t�� ��");
			SCTA(GSH(SOH), 0x000f);
			printf("���� �����Ͻðڽ��ϱ�? (1 ~ 3) : ");
			SCTA(GSH(SOH), 0x000a);
			scanf_s(" %d", &winner_betting);
			if (winner_betting < 1 || winner_betting > 3)	// �ش� ��ȣ�� ���� ���� ��� continue�� �մϴ�
			{
				printf("\t\t\t\t�ش� ��ȣ�� ���� �����ϴ�\n\t\t\t\t");
				system("pause");
				continue;
			}
			coin_put++;
		}

		else
		{
			SCTA(GSH(SOH), 0x000b);
			printf("%d", coin_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("���� �������� ");
			SCTA(GSH(SOH), 0x000a);
			printf("%d", winner_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("�� �� �����ϼ̽��ϴ�\n\t\t\t\t");
		}

		if (a_check[1] == 59 || b_check[1] == 59 || c_check[1] == 59)
		{
			SCTA(GSH(SOH), 0x000f);
			printf("   1����");
			if (a_check[1] == 59)
			{
				SCTA(GSH(SOH), 0x000b);
				printf(" 1��");
				winner_check[0] = 1;
			}
			if (b_check[1] == 59)
			{
				SCTA(GSH(SOH), 0x000c);
				printf(" 2��");
				winner_check[1] = 1;
			}
			if (c_check[1] == 59)
			{
				SCTA(GSH(SOH), 0x000d);
				printf(" 3��");
				winner_check[2] = 1;
			}
			SCTA(GSH(SOH), 0x000f);
			printf(" �� �Դϴ� !!\n");
			if (winner_check[winner_betting - 1] == 1)
			{
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t���� ���� (%d - %d) + ���� ���� ( %d * 3 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 3 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
			}

			else
			{
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t���� ���� (%d - %d) + ���� ���� ( %d * 0 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 0 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
			}
			system("pause");
			return coin;
		}
		srand((unsigned)time(NULL));						// �ð��� ���� ���� �߻�

		if ((a_check[1] = (rand() % 6 + 4 + a_check[0])) > 59)	// ���� (0���� 5���� �� �ϳ��� ����)+ 4 + ���� ������ ��ġ(a_check[0])�� 59�� ������
			a_check[1] = 59;								// ������ ���ڸ� �����ų ��ġ�� a_check[1] = 59    �迭�� ũ�Ⱑ 60�̹Ƿ�( 0 ~ 59 )
		a[a_check[1]] = a[a_check[0]];						// ���� ���� ��ġ������ ���ڸ� ���� ��ġ�� �����մϴ�
		a[a_check[0]] = '\0';								// ���� ���� ��ġ�� �� �� �����մϴ�
		a_check[0] = a_check[1];							// ���ڰ� �̵��� ��ġ�� ���� ������ ��ġ�� �����մϴ�

		if ((b_check[1] = (rand() % 6 + 4 + b_check[0])) > 59)
			b_check[1] = 59;
		b[b_check[1]] = b[b_check[0]];
		b[b_check[0]] = '\0';
		b_check[0] = b_check[1];

		if ((c_check[1] = (rand() % 6 + 4 + c_check[0])) > 59)
			c_check[1] = 59;
		c[c_check[1]] = c[c_check[0]];
		c[c_check[0]] = '\0';
		c_check[0] = c_check[1];
		Sleep(1000);				// 1000/1000�� �� 1�� �����մϴ�
	}
}

int game_777(int coin)
{
#define width 20
#define height 9

	int copy_coin = coin;		// ���� ���� ������ �����Դϴ�
	int coin_put = 0;			// ���ǿ� �°� ������ �����ϰ� ����� ���� �����Դϴ�
	int coin_betting = 0;		// ������ ������ ���ڸ� �����ϱ� ���� �����Դϴ�
	int number[3] = { 0 };		// �� �ڸ��� ���ڸ� ������ �迭�Դϴ�
	int stop = 0;				// ���ڸ� �� �̻� ������Ű�� �ʰ� ���ߵ��� �ϱ� ���� �����Դϴ�
	int k = 0;					// stop�� �����ϱ� ���� �����Դϴ�
	int i = 0, j = 0;			// for������ ���� ���� ���� i, j �Դϴ�
	char number_big[10][height][width] = { "\0" };		// ���ڸ� Ư�����ڷ� ũ�� ǥ���ϱ� ���� �迭�Դϴ�
	system("cls");

	strcpy(number_big[0][0], " ��������������");
	strcpy(number_big[0][1], " ��          ��");
	strcpy(number_big[0][2], " ��          ��");
	strcpy(number_big[0][3], " ��          ��");
	strcpy(number_big[0][4], " ��          ��");
	strcpy(number_big[0][5], " ��          ��");
	strcpy(number_big[0][6], " ��          ��");
	strcpy(number_big[0][7], " ��          ��");
	strcpy(number_big[0][8], " ��������������");

	strcpy(number_big[1][0], "             ��");
	strcpy(number_big[1][1], "             ��");
	strcpy(number_big[1][2], "             ��");
	strcpy(number_big[1][3], "             ��");
	strcpy(number_big[1][4], "             ��");
	strcpy(number_big[1][5], "             ��");
	strcpy(number_big[1][6], "             ��");
	strcpy(number_big[1][7], "             ��");
	strcpy(number_big[1][8], "             ��");

	strcpy(number_big[2][0], " ��������������");
	strcpy(number_big[2][1], "             ��");
	strcpy(number_big[2][2], "             ��");
	strcpy(number_big[2][3], "             ��");
	strcpy(number_big[2][4], " ��������������");
	strcpy(number_big[2][5], " ��            ");
	strcpy(number_big[2][6], " ��            ");
	strcpy(number_big[2][7], " ��            ");
	strcpy(number_big[2][8], " ��������������");

	strcpy(number_big[3][0], " ��������������");
	strcpy(number_big[3][1], "             ��");
	strcpy(number_big[3][2], "             ��");
	strcpy(number_big[3][3], "             ��");
	strcpy(number_big[3][4], " ��������������");
	strcpy(number_big[3][5], "             ��");
	strcpy(number_big[3][6], "             ��");
	strcpy(number_big[3][7], "             ��");
	strcpy(number_big[3][8], " ��������������");

	strcpy(number_big[4][0], " ��          ��");
	strcpy(number_big[4][1], " ��          ��");
	strcpy(number_big[4][2], " ��          ��");
	strcpy(number_big[4][3], " ��          ��");
	strcpy(number_big[4][4], " ��������������");
	strcpy(number_big[4][5], "             ��");
	strcpy(number_big[4][6], "             ��");
	strcpy(number_big[4][7], "             ��");
	strcpy(number_big[4][8], "             ��");

	strcpy(number_big[5][0], " ��������������");
	strcpy(number_big[5][1], " ��            ");
	strcpy(number_big[5][2], " ��            ");
	strcpy(number_big[5][3], " ��            ");
	strcpy(number_big[5][4], " ��������������");
	strcpy(number_big[5][5], "             ��");
	strcpy(number_big[5][6], "             ��");
	strcpy(number_big[5][7], "             ��");
	strcpy(number_big[5][8], " ��������������");

	strcpy(number_big[6][0], " ��            ");
	strcpy(number_big[6][1], " ��            ");
	strcpy(number_big[6][2], " ��            ");
	strcpy(number_big[6][3], " ��            ");
	strcpy(number_big[6][4], " ��������������");
	strcpy(number_big[6][5], " ��          ��");
	strcpy(number_big[6][6], " ��          ��");
	strcpy(number_big[6][7], " ��          ��");
	strcpy(number_big[6][8], " ��������������");


	strcpy(number_big[7][0], " ��������������");
	strcpy(number_big[7][1], " ��          ��");
	strcpy(number_big[7][2], " ��          ��");
	strcpy(number_big[7][3], " ��          ��");
	strcpy(number_big[7][4], " ��          ��");
	strcpy(number_big[7][5], "             ��");
	strcpy(number_big[7][6], "             ��");
	strcpy(number_big[7][7], "             ��");
	strcpy(number_big[7][8], "             ��");

	strcpy(number_big[8][0], " ��������������");
	strcpy(number_big[8][1], " ��          ��");
	strcpy(number_big[8][2], " ��          ��");
	strcpy(number_big[8][3], " ��          ��");
	strcpy(number_big[8][4], " ��������������");
	strcpy(number_big[8][5], " ��          ��");
	strcpy(number_big[8][6], " ��          ��");
	strcpy(number_big[8][7], " ��          ��");
	strcpy(number_big[8][8], " ��������������");

	strcpy(number_big[9][0], " ��������������");
	strcpy(number_big[9][1], " ��          ��");
	strcpy(number_big[9][2], " ��          ��");
	strcpy(number_big[9][3], " ��          ��");
	strcpy(number_big[9][4], " ��������������");
	strcpy(number_big[9][5], "             ��");
	strcpy(number_big[9][6], "             ��");
	strcpy(number_big[9][7], "             ��");
	strcpy(number_big[9][8], "             ��");

	srand((unsigned)time(NULL));

	for (i = 0; i < 3; i++)
		number[i] = rand() % 10;		// number[0], number[1], number[2] �� ���� 0���� 9������ ������ �����մϴ�

	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t\t\t\t\t      [777]\n\n");
		SCTA(GSH(SOH), 0x000f);
		printf("\t\t\t=====================================================\n\n\t\t\t");
		for (i = stop; i < 3; i++)
			number[i] = (number[i] + rand() % 10) % 10;

		for (i = 0; i < height; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (number[j] == 0 || number[j] == 5)
					SCTA(GSH(SOH), 0x000b);
				else if (number[j] == 1 || number[j] == 6)
					SCTA(GSH(SOH), 0x000d);
				else if (number[j] == 2 || number[j] == 7)
					SCTA(GSH(SOH), 0x000e);
				else if (number[j] == 3 || number[j] == 8)
					SCTA(GSH(SOH), 0x000f);
				else
					SCTA(GSH(SOH), 0x000a);
				printf("%s  ", number_big[number[j]][i]);
			}
			printf("\n\t\t\t");
		}
		SCTA(GSH(SOH), 0x000f);
		printf("\n\t\t\t=====================================================");
		SCTA(GSH(SOH), 0x000a);
		if (coin_put == 0)
		{
			printf("\n\n\t\t\t\t%d��", coin);
			SCTA(GSH(SOH), 0x000f);
			printf("�� ������ �ֽ��ϴ�.\n");
			SCTA(GSH(SOH), 0x000e);
			printf("\t\t\t\t�� ��");
			SCTA(GSH(SOH), 0x000f);
			printf("�� �����Ͻðڽ��ϱ�? (���� ?��) ");
			SCTA(GSH(SOH), 0x000b);
			scanf_s(" %d", &coin_betting);
			if (coin_betting > coin || coin_betting <= 0)						// ���� ���κ��� �� ���� ���� ������ �����Ϸ��� �ϸ� continue�� �մϴ�
			{
				printf("\t\t\t\t���� ������ Ȯ���Ͻʽÿ�\n\t\t\t\t");
				system("pause");
				continue;
			}
			coin_put++;
		}
		else
		{
			SCTA(GSH(SOH), 0x000b);
			printf("\n\n\t\t\t\t%d", coin_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("���� �������� �����ϼ̽��ϴ�\n\t\t\t\t");

		}
		Sleep(100);		// 100/1000 �� �� 0.1�� ����
		k++;
		if (k == 10)
		{
			k = 0;
			stop++;
		}

		if (stop == 3)
		{
			if (number[0] == number[1] && number[1] == number[2])	// �� ���� ���ڰ� ���� ���
			{
				if (number[0] == 7)		// 777 �̸� ����
				{
					SCTA(GSH(SOH), 0x000d);
					printf("\t    �����̡�\n");
					SCTA(GSH(SOH), 0x000e);
					printf("\t\t       ���� ���� (%d - %d) + ���� ���� ( %d * 50 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 50 * coin_betting);
				}

				else					// 777�� �����ϰ� �� ���ڰ� ���� ���
				{
					SCTA(GSH(SOH), 0x000b);
					printf("      ���ÿ� �����ϼ̽��ϴ�\n");
					SCTA(GSH(SOH), 0x000e);
					printf("\t\t       ���� ���� (%d - %d) + ���� ���� ( %d * 10 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 10 * coin_betting);
				}
			}

			else if (((number[0] - number[1] == 5) || (number[0] - number[1] == 0) || (number[0] - number[1] == -5)) && ((number[0] - number[2] == 5) || (number[0] - number[2] == 0) || (number[0] - number[2] == -5)))
			{
				// �� ������ ������ ���밪�� 5�ų� 0�� ���
				// �� ���� ���� ���
				if (number[0] == 0 || number[0] == 5)
					SCTA(GSH(SOH), 0x000b);
				else if (number[0] == 1 || number[0] == 6)
					SCTA(GSH(SOH), 0x000d);
				else if (number[0] == 2 || number[0] == 7)
					SCTA(GSH(SOH), 0x000e);
				else if (number[0] == 3 || number[0] == 8)
					SCTA(GSH(SOH), 0x000f);
				else
					SCTA(GSH(SOH), 0x000a);

				printf("\t ���� �� �� ����\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t       ���� ���� (%d - %d) + ���� ���� ( %d * 5 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 5 * coin_betting);
			}

			else
			{
				SCTA(GSH(SOH), 0x000c);
				printf("      ���ÿ� �����ϼ̽��ϴ�\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t       ���� ���� (%d - %d) + ���� ���� ( %d * 0 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 0 * coin_betting);
			}
			SCTA(GSH(SOH), 0x000f);
			system("pause");
			return coin;
		}
	}
}

int game_wbg(int coin)
{
#define width 12
#define length 7

	char wbg[length][width] = { "\0" };	// ������ �����ϱ� ���� ���� �迭�Դϴ�
	int i = 0, j = 0;					// for������ ���� ���� ���� i, j �Դϴ�
	int ball[3] = { 0 };					// ���� ��ġ�� ���ڷ� ǥ���ϰ� �����ϱ� ���� �迭�Դϴ�
	int std = 5;						// ���� ��ġ�� ǥ���ϱ� ���� ����, ���� std�Դϴ�
	int k = 0, count = 0;				// ���ǿ� �°� ���� ��ġ�� ������ k, count�Դϴ�
	int box = 0;						// �� �� �ڽ��� �������� �����ϱ� ���� �����Դϴ�
	int copy_coin = coin;				// ���� ���� ������ �����Դϴ�
	int coin_put = 0;					// ���ǿ� �°� ������ �����ϰ� ����� ���� �����Դϴ�
	int coin_betting = 0;				// ������ ������ ���ڸ� �����ϱ� ���� �����Դϴ�
	int box_betting = 0;				// �� �� �ڽ��� �����ߴ��� �����ϱ� ���� �����Դϴ�

	wbg[0][std] = 'o';
	wbg[1][5] = 'A';
	wbg[3][3] = 'A';
	wbg[3][7] = 'A';
	wbg[5][1] = 'A';
	wbg[5][5] = 'A';
	wbg[5][9] = 'A';
	wbg[6][0] = '_';
	wbg[6][1] = 'I';
	wbg[6][2] = '_';
	wbg[6][3] = '_';
	wbg[6][4] = '_';
	wbg[6][5] = 'I';
	wbg[6][6] = '_';
	wbg[6][7] = '_';
	wbg[6][8] = '_';
	wbg[6][9] = 'I';
	wbg[6][10] = '_';

	srand((unsigned)time(NULL));

	for (i = 0; i < 3; i++)
	{
		ball[i] = (2 * (rand() % 2)) - 1;	// ball[k] == -1 || ball[k] == 1;

		if (ball[i] == 1)					// ���� �� �ڽ� ��ȣ�� ���ǿ� ���߾� �˾Ƴ��� ���� ���ǹ��Դϴ�
			box++;
	}

	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t\t\t\t\t  [���� ����]\n\n\t\t\t");
		for (i = 0; i < length; i++)				// printf���� ���� for���Դϴ�
		{
			for (j = 0; j < width; j++)
			{
				if (wbg[i][j] == 'o')
					SCTA(GSH(SOH), 0x000e);
				else if (wbg[i][j] == 'A')
					SCTA(GSH(SOH), 0x000d);
				else
					SCTA(GSH(SOH), 0x000b);
				printf("   %c", wbg[i][j]);

				if (wbg[i][j] == 'o')
					wbg[i][j] = '\0';
			}

			printf("\n\n\t\t\t");
		}
		SCTA(GSH(SOH), 0x000a);
		printf("   1\t       2\t       3\t   4\n");


		if (coin_put == 0)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("\n\t\t\t\t%d��", coin);
			SCTA(GSH(SOH), 0x000f);
			printf("�� ������ �ֽ��ϴ�.\n");
			SCTA(GSH(SOH), 0x000e);
			printf("\t\t\t\t�� ��");
			SCTA(GSH(SOH), 0x000f);
			printf("�� �����Ͻðڽ��ϱ�? (���� 3��) ");
			SCTA(GSH(SOH), 0x000b);
			scanf_s(" %d", &coin_betting);
			if (coin_betting > coin || coin_betting <= 0)						// ���� ���κ��� �� ���� ���� ������ �����Ϸ��� �ϸ� continue�� �մϴ�
			{
				printf("\t\t\t\t���� ������ Ȯ���Ͻʽÿ�\n\t\t\t\t");
				system("pause");
				continue;
			}

			else
			{
				printf("\t\t\t\t�� ��");
				SCTA(GSH(SOH), 0x000f);
				printf("ĭ�� �����Ͻðڽ��ϱ�? (1 ~ 4) : ");
				SCTA(GSH(SOH), 0x000a);
				scanf_s(" %d", &box_betting);
				if (box_betting < 1 || box_betting > 4)	// �ش� ��ȣ�� ���� ���� ��� continue�� �մϴ�
				{
					printf("\t\t\t\t�ش� ��ȣ�� ĭ�� �����ϴ�\n\t\t\t\t");
					system("pause");
					continue;
				}
				coin_put++;
			}
		}
		else
		{
			SCTA(GSH(SOH), 0x000b);
			printf("\n\t\t\t\t%d", coin_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("���� �������� ");
			SCTA(GSH(SOH), 0x000a);
			printf("%d", box_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("�� ĭ �����ϼ̽��ϴ�.\n\t\t\t\t");
		}

		if (count < 6)				// ���� ��ġ�� ���������� 0, 1, 2, 3, .. �̶�� �Ҷ� 6���� ���� ��� �Դϴ�
		{
			if (count % 2 == 0)		 // ¦���� ����Դϴ�
			{
				wbg[count + 1][std += ball[k]] = 'o';

				k++;
				count++;
			}

			else					// Ȧ���� ��� �Դϴ�
			{
				if (count == 5 && (std == 0 || std == 10))		// ���� ��ġ�� 5�� ��� �Դϴ�
				{
					wbg[count + 1][std] = 'o';
				}
				else				// ���� ��ġ�� 1�̳� 3�� ��� �Դϴ�
					wbg[count + 1][std += ball[k - 1]] = 'o';		// k�� 1 ������ �����̹Ƿ� ball[k]�� �ƴ� ball[k-1]�� ����߽��ϴ�

				count++;
			}
		}
		else
		{
			if ((box + 1) == box_betting)		// ���� �ִ� ĭ�� ������ ĭ�� ���� ��� �Դϴ�
			{
				SCTA(GSH(SOH), 0x000b);
				printf("      ���ÿ� �����ϼ̽��ϴ�\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t���� ���� (%d - %d) + ���� ���� ( %d * 3 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 3 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
				system("pause");
				return coin;
			}

			else
			{
				SCTA(GSH(SOH), 0x000c);
				printf("      ���ÿ� �����ϼ̽��ϴ�\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t���� ���� (%d - %d) + ���� ���� ( %d * 0 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 0 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
				system("pause");
				return coin;
			}
		}

		Sleep(500);
	}
}

void game_record_regist(int coin)
{
	struct user R[5] = { 0 };
	int a;			// for���� ���� �����Դϴ�
	int b;			// ������ �˰��򿡼� �� ���� �����ϱ� ���� �����Դϴ�
	char id_NULL[id_size] = { "\0" };		// �� ���ڿ��Դϴ�

	fp = fopen("BettingGameRecord.txt", "r");

	for (a = 0; a < 5; a++)
		fscanf(fp, " %d %s %d", &R[a].ranking, R[a].id, &R[a].score);

	fclose(fp);

	if (R[4].score < coin)
	{
		strncpy(R[4].id, id_box, id_size);
		R[4].score = coin;

		fp = fopen("BettingGameRecord.txt", "w");
		for (a = 3; a >= 0; a--)
		{
			if (R[a].score < coin)
			{
				b = R[a].score;
				R[a].score = coin;
				R[a + 1].score = b;

				strncpy(id_NULL, R[a].id, id_size);
				strncpy(R[a].id, id_box, id_size);
				strncpy(R[a + 1].id, id_NULL, id_size);
			}

			else
				break;
		}

		for (a = 0; a < 5; a++)
			fprintf(fp, "%d %-6s %d\n", R[a].ranking, R[a].id, R[a].score);		// ���Ͽ� �����͸� �����մϴ�

		fclose(fp);
	}
}

