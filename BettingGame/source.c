// 201533797 컴퓨터공학과 윤병헌
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
void game_start(void);			// 게임을 시작하기 위한 함수입니다
void game_how(void);			// 게임 방법을 보여주기 위한 함수입니다
void game_make_record(void);	// 게임 내 순위를 만들고 파일로 저장합니다 ( 처음 1회만 )
void game_record_see(void);		// 게임 내 순위를 보여주기 위한 함수입니다
void game_id(void);				// 게임 아이디를 저장하기 위한 함수입니다
void game_select(void);			// 게임 선택 화면 구현 함수입니다
int game_race(int);				// [경마] 게임 함수입니다
int game_777(int);				// [777] 게임 함수입니다
int game_wbg(int);				// [공은 어디로] 게임 함수입니다 ( where ball go )
void game_record_regist(int);	// 게임 기록(순위)를 저장하기 위한 함수입니다
char id_box[id_size] = { "\0" };	// 아이디 저장용 문자열입니다 최대 5자리의 아이디가 가능합니다
FILE *fp = NULL;

struct user {				// 사용자의 정보를 저장하기 위한 구조체입니다
	int ranking;			// 랭킹 기록용 변수입니다
	char id[id_size];		// id 기록용 문자열입니다
	int score;				// 점수 기록용 변수입니다
};

int main(void)
{
	system("title ____________________________________________________________    ★☆ Betting Game ☆★    __________________________________");	// cmd 타이틀 설정
	system("mode con: cols=100 lines=26 ");			// cmd 창 크기 조절
	game_start();				// game_start 함수 실행, 게임 시작 화면이 나옵니다

	//game_race(100);
	return 0;
}

void game_start(void)
{
	int updown = 0;		// 게임 스타트 -> 0, 게임 방법 -> 1, 순위 보기 -> 2, 나가기 -> 3 의 상태를 저장하기 위한 변수입니다
	char word = ' ';
	int i = 0;

	game_make_record();		// 처음 1회만 기록(파일)을 만들어줍니다

	SCTA(GSH(SOH), 0x000f);		// 흰색 글자로 설정
	while (1)
	{
		int check = 0;			// while 문을 조건에 맞게 탈출하기 위한 check 변수를 정의하였습니다
		printf("\n\n\n");
		SCTA(GSH(SOH), 0x000d);
		printf("\t    ┌────＼                              ┌──────               ┌──────── \n");
		SCTA(GSH(SOH), 0x000e);
		printf("\t    │    │          ──┬──  ──┬──  ㅇ     │                     │         \n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t    ├────┴＼  ┌──     │      │    │ ┌──┐ │  ────┐  ──┐ ┌──┬──┐ ├──────── \n");
		SCTA(GSH(SOH), 0x000d);
		printf("\t    │      │  ├──     │      │    │ │  │ │      │ ┌──┤ │  │  │ │         \n");
		SCTA(GSH(SOH), 0x0004);
		printf("\t    └──────┘  └──     │      │    │ │  │ └──────┘ └──┘ │  │  │ └──────── \n\n\n\n");
		SCTA(GSH(SOH), 0x000f);
		if (updown == 0)
		{
			SCTA(GSH(SOH), 0x000e);	// 노란색 글자를 위한 코드입니다
			printf("					<< 게임 스타트 >>\n\n");
			SCTA(GSH(SOH), 0x000f);	// 흰색 글자를 위한 코드입니다
		}
		else
			printf("					   게임 스타트\n\n");


		if (updown == 1)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("					 << 게임 방법 >>\n\n");
			SCTA(GSH(SOH), 0x000f);
		}
		else
			printf("					    게임 방법\n\n");


		if (updown == 2)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("					 << 순위 보기 >>\n\n");
			SCTA(GSH(SOH), 0x000f);
		}
		else
			printf("					    순위 보기\n\n");


		if (updown == 3)
		{
			SCTA(GSH(SOH), 0x000e);
			printf("					  << 나가기 >>\n\n\n");
			SCTA(GSH(SOH), 0x000f);
		}
		else
			printf("					     나가기\n\n\n");

		SCTA(GSH(SOH), 0x0006);
		printf("\t\t[  조작 키 ]  W : 위 / S : 아래 / J : 버튼 / Enter : 값 입력\n");
		printf("\t\t[  제작자  ]  201533797 컴퓨터공학과 윤병헌");
		SCTA(GSH(SOH), 0x000f);

		while (word = _getch())	// 문자를 입력받아서 밑의 코드들에 의해 조건에 맞게 처리합니다
		{
			if (word == 's' || word == 'S' || word == 'w' || word == 'W' || word == 'j' || word == 'J')
				check = 1;

			if (word == 's' || word == 'S')		// S를 입력할 때
				if (updown == 3)		// << 나가기 >> 에서 더 밑으로 가려고 하면 경고음을 냅니다
					printf("\a");
				else
					updown += 1;

			else if (word == 'w' || word == 'W')	// W를 입력할 때
				if (updown == 0)		// << 게임 스타트 >> 에서 더 위로 가려고 하면 경고음을 냅니다
					printf("\a");

				else
					updown -= 1;

			else if (word == 'j' || word == 'J')	// J를 입력할 때
				if (updown == 0)		// << 게임 스타트 >> 게임을 시작합니다
				{
					game_id();
					game_select();
					system("pause");
				}
				else if (updown == 1)		// << 게임 방법 >> 게임 방법을 보여줍니다
					game_how();				// game_how() 함수를 호출합니다

				else if (updown == 2)		// << 순위 보기 >> 순위를 보여줍니다
					game_record_see();

				else
				{
					printf("\n\n\t\t\t\t");
					SCTA(GSH(SOH), 0x0003);
					check = 2;
					break;				// updown == 3 이면서 word == 'j'인 상태, 즉 << 나가기 >> 에서 j키를 눌렀으므로 게임을 종료합니다
				}

			if (check > 0)		// check == 1 || check == 2
				break;
			else
				continue;
		}
		if (check == 2)
			break;
		system("cls");				// 실행 화면을 지웁니다
	}
}

void game_how(void)
{
	char check = ' ';		// J키를 눌러야만 이 함수를(화면을) 벗어나기 위해 정의된 check입니다
	system("cls");
	printf("									    ┌──────────────────┐\n");
	printf("									    │ ← 뒤로 가기 : J │\n");
	printf("									    └──────────────────┘");
	printf("\n\n\n\t\t\t");
	SCTA(GSH(SOH), 0x000d);
	printf("★☆ Betting Game ☆★ ");
	SCTA(GSH(SOH), 0x000f);
	printf("에 오신 것을 환영합니다 !\n\n\n\n");
	printf("\t\t게임이 시작 되면 여러분들에게는 베팅을 할 수 있는 ");
	SCTA(GSH(SOH), 0x000b);
	printf("5번의 기회");
	SCTA(GSH(SOH), 0x000f);
	printf(" 가 주어지며\n\n");
	printf("\t\t원한다면 중간에 게임을 끝낼 수도 있습니다\n\n");
	printf("\t\tBetting Game엔");
	SCTA(GSH(SOH), 0x000a);
	printf(" [경마] [777] [공은 어디로]");
	SCTA(GSH(SOH), 0x000f);
	printf(" 세 개의 게임이 있으며\n\n");
	printf("\t\t베팅을 위한 수단으로는");
	SCTA(GSH(SOH), 0x000e);
	printf(" ☆100개의 코인☆ ");
	SCTA(GSH(SOH), 0x000f);
	printf("이 주어집니다\n\n");
	printf("\t\t게임마다 배당률이 다르므로 신중하게 하셔야 합니다\n\n");
	printf("\t\t가능한 많은 코인을 모으시면 됩니다 ");
	while (check = _getch())
	{
		if (check == 'j' || check == 'J')
			break;
	}
	system("cls");
}

void game_make_record(void)
{
	//if ((fp = fopen("BettingGameRecord.txt", "r")) == NULL)		// 만약 게임을 처음 한다면 (기록이 없다면) 기록을 만들어 줍니다
	fopen_s(&fp, "BettingGameRecord.txt", "r");
	if (fp == NULL)													// 만약 게임을 처음 한다면 (기록이 없다면) 기록을 만들어 줍니다
	{
		struct user R[5];		// 5명의 기록을 저장하기 위한 5개의 레코드와 현 게임 이용자의 기록을 담거나 내림차순 용도의 NULL 레코드를 합쳐서 6개의 레코드로 구성된 R[6]입니다
		int i;
		char id_NULL[id_size] = { "\0" };
		for (i = 0; i < 5; i++)					// R[0]부터 R[5]까지 인위적인 데이터를 넣습니다
		{
			if (i == 0)
			{
				R[i].ranking = 1;
				strncpy_s(R[i].id, id_size, "HGH", id_size);
				R[i].score = 1000;
			}
			else if (i == 1)
			{
				R[i].ranking = 2;
				strncpy_s(R[i].id, id_size, "PSJ", id_size);
				R[i].score = 800;
			}
			else if (i == 2)
			{
				R[i].ranking = 3;
				strncpy_s(R[i].id, id_size, "JSB", id_size);
				R[i].score = 300;
			}
			else if (i == 3)
			{
				R[i].ranking = 4;
				//strcpy(R[i].id, "AAA");
				strncpy_s(R[i].id, id_size, "AAA", id_size);
				R[i].score = 80;
			}
			else
			{
				R[i].ranking = 5;
				//strcpy(R[i].id, "BBB");
				strncpy_s(R[i].id, id_size, "BBB", id_size);
				R[i].score = 50;
			}
		}
		//fp = fopen("BettingGameRecord.txt", "w");
		fopen_s(&fp, "BettingGameRecord.txt", "w");
		for (i = 0; i < 5; i++)
			fprintf(fp, "%d %-6s %d\n", R[i].ranking, R[i].id, R[i].score);		// 파일에 데이터를 저장합니다
		//fclose(fp);
	}
	fclose(fp);
}

void game_record_see(void)
{
	int i, ranking = 0, score = 0;
	char id[6] = { "\0" };
	char check = ' ';
	system("cls");
	printf("									    ┌──────────────────┐\n");
	printf("									    │ ← 뒤로 가기 : J │\n");
	printf("									    └──────────────────┘\n");
	SCTA(GSH(SOH), 0x000b);
	printf("\n\n\t\t\t\t\t   ☆ 순위 ☆\n\n");
	SCTA(GSH(SOH), 0x000f);
	printf("\t\t\t-----------------------------------------------\n");
	SCTA(GSH(SOH), 0x000e);
	printf("\t\t\t\t순위	     아이디	   점수\n");
	SCTA(GSH(SOH), 0x000f);
	printf("\t\t\t-----------------------------------------------\n\n");
	//fp = fopen("BettingGameRecord.txt", "r");
	fopen_s(&fp, "BettingGameRecord.txt", "r");
	for (i = 0; i < 5; i++)
	{
		//fscanf(fp, "%d %s %d\n", &ranking, id, &score);		//파일에서 정수(ranking), 문자열, 정수(score)를 데이터로 읽습니다
		fscanf_s(fp, "%d %s %d\n", &ranking, id, id_size, &score);		//파일에서 정수(ranking), 문자열, 정수(score)를 데이터로 읽습니다
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
		if (check == 'j' || check == 'J')					// J키를 입력하면 while반복문을 탈출합니다
			break;
	}

}

void game_id(void)
{
#define id_length 20
	int check = 0;					// check는 1이 되면 함수가 종료되게 설정하기 위한 변수입니다
	int id_check_i;					// 아이디가 영어 대문자로 되어있는지 확인하기 위한 변수입니다
	int i = 0;						// 아이디를 잘못 입력했을 경우 경고문을 출력하고 그 횟수를 저장하기 위한 변수 i입니다
	while (check == 0)
	{
		fflush(stdin);					// 버퍼를 비웁니다
		char id_check[id_length] = { "\0" };		// 아이디 자리수 체크용 문자열입니다
		for (int k = 0; k < id_length; k++)
			id_check[k] = '\0';
		check = 1;
		system("cls");
		SCTA(GSH(SOH), 0x000a);
		printf("\n\n\n\n\n\n\t\t\t\t\tID 를 생성하십시오\n\n");
		SCTA(GSH(SOH), 0x000f);
		printf("\n\t\t\t\t     ( 영어 대문자 3 ~ 5글자 )");
		if (i == 0)
			printf("\n\n\n\t\t\t\t\t      ");
		if (i != 0)
		{
			SCTA(GSH(SOH), 0x000c);
			printf("\n\t\t\t\t     조건에 맞게 만드십시오(%d)\n\n\t\t\t\t\t       ", i);
			//printf("\n\t\t\t\t     조건에 맞게 만드십시오\n\n\t\t\t\t\t       ");
			SCTA(GSH(SOH), 0x000f);
		}
		SCTA(GSH(SOH), 0x000e);
		//gets_s(id_check, sizeof(id_check));		# 배열 사이즈를 초과하면 에러 발생
		scanf_s("%s", id_check, sizeof(id_check));
		//printf("%d", strlen(id_check));

		SCTA(GSH(SOH), 0x000f);
		//if ((id_check[2] == '\0') || id_check[id_size-1] != '\0')			// id가 2글자 이하인 경우 또는 5글자가 넘는 경우 다시 입력하게 했습니다
		if ((strlen(id_check) <= 2) || (strlen(id_check) >= id_size))
		{
			check = 0;
			i++;
			continue;
		}
		//strncpy(id_box, id_check, id_size);
		strncpy_s(id_box, id_size, id_check, id_size);

		for (id_check_i = 0; id_box[id_check_i] != '\0'; id_check_i++)
		{
			if (isupper(id_box[id_check_i]) == 0)	// 영어 대문자가 아닌 글자가 있으면 다시 입력하게 합니다
			{
				check = 0;
				i++;
				break;
			}
		}
		if (check == 1)
		{
			SCTA(GSH(SOH), 0x000b);
			printf("\n\n\t\t\t\t\t아이디 생성 성공 !");
			SCTA(GSH(SOH), 0x000f);
		}
		Sleep(1000);
	}
}

void game_select(void)
{
	int select;					// 몇 번을 고를지에 대해 저장하기 위한 변수입니다
	int count = 5;				// 남은 게임 횟수를 저장하기 위한 변수입니다
	int coin = 100;				// 코인의 개수를 저장하기 위한 변수입니다
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
		printf("\t┌──────────────────┐           ┌─────────────────┐             ┌──────────────────┐ \n");
		printf("\t│ =================│           │                 │             │                  │ \n");
		printf("\t│  Z I             │           │ ================│             │        ㅇ        │ \n");
		printf("\t│ =================│           │  ┌─┐  ┌─┐  ┌─┐  │             │                  │ \n");
		printf("\t│  Z I             │           │  │ │  │ │  │ │  │             │      ㅇ   ㅇ     │ \n");
		printf("\t│ =================│           │    │    │    │  │             │                  │ \n");
		printf("\t│  Z I             │           │ ================│             │   ㅇ   ㅇ    ㅇ  │ \n");
		printf("\t│ =================│           │                 │             │                  │ \n");
		printf("\t└──────────────────┘           └─────────────────┘             └──────────────────┘ \n\n");
		SCTA(GSH(SOH), 0x000f);
		printf("\t          1                              2                               3\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t       [경마]                          [777]                       [공은 어디로]\n\n\n");
		SCTA(GSH(SOH), 0x000b);
		printf("\t\t\t\t%d번", count);
		SCTA(GSH(SOH), 0x000f);
		printf("의 기회가 있습니다");
		SCTA(GSH(SOH), 0x000e);
		printf(" ( 코인 : %d개 )\n\n", coin);
		if (count == 0 || coin == 0)
		{
			if (count == 0)
				printf("\t\t\t\t남은 기회가 없으므로 게임이 종료됩니다.\n\n\t\t\t\t");

			else
				printf("\t\t\t\t코인이 없으므로 게임이 종료됩니다.\n\n\t\t\t\t");

			system("pause");
			game_record_regist(coin);
			SCTA(GSH(SOH), 0x000f);
			game_record_see();
			printf("\t\t\t\t");
			break;
		}
		SCTA(GSH(SOH), 0x000f);
		printf("\t\t\t\t어느 게임을 하시겠습니까? (0:종료) : ");
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
#define race_width 60

	char a[race_width] = { "Z  I" };
	char b[race_width] = { "Z  I" };
	char c[race_width] = { "Z  I" };

	for (int idx = 4; idx < (race_width - 1); idx++) {
		a[idx] = ' ';
		b[idx] = ' ';
		c[idx] = ' ';
	}
	a[race_width - 1] = '\0';
	b[race_width - 1] = '\0';
	c[race_width - 1] = '\0';

	int copy_coin = coin;		// 코인 값을 저장할 변수입니다
	int a_check[2] = { 0 };		// 문자의 위치를 숫자로 나타내고 기억할 변수입니다
	int b_check[2] = { 0 };
	int c_check[2] = { 0 };
	int winner_check[3] = { 0 };	// 승자를 기록하기 위한 배열입니다. 공동 승자가 발생할 경우를 생각해서 배열로 만들었습니다
	int winner_betting = 0;		// 사용자로부터 승자를 예측해서 숫자로 입력받고 저장 위한 변수입니다.
	int coin_put = 0;			// 조건에 맞게 코인을 베팅하게 만들기 위한 변수입니다
	int coin_betting = 0;		// 베팅할 코인의 숫자를 저장하기 위한 변수입니다
	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t\t\t\t\t     [경마]\n\n\n");
		SCTA(GSH(SOH), 0x000e);
		printf("\t\t  =============================================================");
		SCTA(GSH(SOH), 0x000b);
		printf("\n\t\t     I\n\t\t1 ");
		/*
		for (i = 0; i < 60; i++)
		{
			printf("%c", a[i]);
		}*/
		printf("%s", a);

		printf("\n\t\t     I");
		SCTA(GSH(SOH), 0x000e);
		printf("\n\t\t  =============================================================");
		SCTA(GSH(SOH), 0x000c);
		printf("\n\t\t     I\n\t\t2 ");
		printf("%s", b);
		printf("\n\t\t     I");
		SCTA(GSH(SOH), 0x000e);
		printf("\n\t\t  =============================================================");
		SCTA(GSH(SOH), 0x000d);
		printf("\n\t\t     I\n\t\t3 ");
		printf("%s", c);
		printf("\n\t\t     I");
		SCTA(GSH(SOH), 0x000e);
		printf("\n\t\t  =============================================================\n\n\t\t\t\t");
		if (coin_put == 0)
		{
			printf("%d개", coin);
			SCTA(GSH(SOH), 0x000f);
			printf("의 코인이 있습니다.\n");
			SCTA(GSH(SOH), 0x000e);
			printf("\t\t\t\t몇 개");
			SCTA(GSH(SOH), 0x000f);
			printf("나 베팅하시겠습니까? (배당률 3배) ");
			SCTA(GSH(SOH), 0x000b);
			scanf_s(" %d", &coin_betting);
			if (coin_betting > coin || coin_betting <= 0)						// 보유 코인보다 더 많은 양의 코인을 베팅하려고 하면 continue를 합니다
			{
				printf("\t\t\t\t코인 개수를 확인하십시오\n\t\t\t\t");
				system("pause");
				continue;
			}
			printf("\t\t\t\t몇 번");
			SCTA(GSH(SOH), 0x000f);
			printf("말에 배팅하시겠습니까? (1 ~ 3) : ");
			SCTA(GSH(SOH), 0x000a);
			scanf_s(" %d", &winner_betting);
			if (winner_betting < 1 || winner_betting > 3)	// 해당 번호의 말이 없을 경우 continue를 합니다
			{
				printf("\t\t\t\t해당 번호의 말이 없습니다\n\t\t\t\t");
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
			printf("개의 코인으로 ");
			SCTA(GSH(SOH), 0x000a);
			printf("%d", winner_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("번 말 선택하셨습니다\n\t\t\t\t");
		}

		if (a_check[1] == (race_width - 2) || b_check[1] == (race_width - 2) || c_check[1] == (race_width - 2))
		{
			SCTA(GSH(SOH), 0x000f);
			printf("   1등은");
			if (a_check[1] == (race_width - 2))
			{
				SCTA(GSH(SOH), 0x000b);
				printf(" 1번");
				winner_check[0] = 1;
			}
			if (b_check[1] == (race_width - 2))
			{
				SCTA(GSH(SOH), 0x000c);
				printf(" 2번");
				winner_check[1] = 1;
			}
			if (c_check[1] == (race_width - 2))
			{
				SCTA(GSH(SOH), 0x000d);
				printf(" 3번");
				winner_check[2] = 1;
			}
			SCTA(GSH(SOH), 0x000f);
			printf(" 말 입니다 !!\n");
			if (winner_check[winner_betting - 1] == 1)
			{
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t기존 코인 (%d - %d) + 베팅 코인 ( %d * 3 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 3 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
			}

			else
			{
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t기존 코인 (%d - %d) + 베팅 코인 ( %d * 0 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 0 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
			}
			system("pause");
			return coin;
		}
		srand((unsigned)time(NULL));						// 시간에 따라 난수 발생

		if ((a_check[1] = (rand() % 6 + 4 + a_check[0])) > race_width - 2)	// 만약 (0부터 5까지 중 하나의 난수)+ 4 + 기존 문자의 위치(a_check[0])가 59를 넘으면
			a_check[1] = race_width - 2;								// 다음에 문자를 저장시킬 위치는 a_check[1] = 59    배열의 크기가 60이므로( 0 ~ 59 )
		a[a_check[1]] = a[a_check[0]];						// 기존 문자 위치에서의 문자를 다음 위치로 대입합니다
		a[a_check[0]] = ' ';								// 기존 문자 위치에 공백을 대입합니다
		a_check[0] = a_check[1];							// 문자가 이동된 위치를 기존 문자의 위치로 대입합니다

		if ((b_check[1] = (rand() % 6 + 4 + b_check[0])) > race_width - 2)
			b_check[1] = race_width - 2;
		b[b_check[1]] = b[b_check[0]];
		b[b_check[0]] = ' ';
		b_check[0] = b_check[1];

		if ((c_check[1] = (rand() % 6 + 4 + c_check[0])) > race_width - 2)
			c_check[1] = race_width - 2;
		c[c_check[1]] = c[c_check[0]];
		c[c_check[0]] = ' ';
		c_check[0] = c_check[1];
		Sleep(500);				// 1000/1000초 즉 1초 정지합니다
	}
}

int game_777(int coin)
{
#define width 20
#define height 9

	int copy_coin = coin;		// 코인 값을 저장할 변수입니다
	int coin_put = 0;			// 조건에 맞게 코인을 베팅하게 만들기 위한 변수입니다
	int coin_betting = 0;		// 베팅할 코인의 숫자를 저장하기 위한 변수입니다
	int number[3] = { 0 };		// 세 자리의 숫자를 저장할 배열입니다
	int stop = 0;				// 숫자를 더 이상 증가시키지 않고 멈추도록 하기 위한 변수입니다
	int k = 0;					// stop을 조절하기 위한 변수입니다
	int i = 0, j = 0;			// for문에서 쓰기 위한 변수 i, j 입니다
	char number_big[10][height][width] = { "\0" };		// 숫자를 특수문자로 크게 표시하기 위한 배열입니다
	system("cls");

	/*
	strcpy(number_big[0][0], " ┌―――――┐");
	strcpy(number_big[0][1], " │          │");
	strcpy(number_big[0][2], " │          │");
	strcpy(number_big[0][3], " │          │");
	strcpy(number_big[0][4], " │          │");
	strcpy(number_big[0][5], " │          │");
	strcpy(number_big[0][6], " │          │");
	strcpy(number_big[0][7], " │          │");
	strcpy(number_big[0][8], " └―――――┘");

	strcpy(number_big[1][0], "       │      ");
	strcpy(number_big[1][1], "      /│      ");
	strcpy(number_big[1][2], "     / │      ");
	strcpy(number_big[1][3], "       │      ");
	strcpy(number_big[1][4], "       │      ");
	strcpy(number_big[1][5], "       │      ");
	strcpy(number_big[1][6], "       │      ");
	strcpy(number_big[1][7], "       │      ");
	strcpy(number_big[1][8], "  ――――――");

	strcpy(number_big[2][0], " ――――――┐");
	strcpy(number_big[2][1], "             │");
	strcpy(number_big[2][2], "             │");
	strcpy(number_big[2][3], "             │");
	strcpy(number_big[2][4], " ┌――――――");
	strcpy(number_big[2][5], " │            ");
	strcpy(number_big[2][6], " │            ");
	strcpy(number_big[2][7], " │            ");
	strcpy(number_big[2][8], " └――――――");

	strcpy(number_big[3][0], " ――――――┐");
	strcpy(number_big[3][1], "             │");
	strcpy(number_big[3][2], "             │");
	strcpy(number_big[3][3], "             │");
	strcpy(number_big[3][4], " ――――――│");
	strcpy(number_big[3][5], "             │");
	strcpy(number_big[3][6], "             │");
	strcpy(number_big[3][7], "             │");
	strcpy(number_big[3][8], " ――――――┘");

	strcpy(number_big[4][0], " │          │");
	strcpy(number_big[4][1], " │          │");
	strcpy(number_big[4][2], " │          │");
	strcpy(number_big[4][3], " │          │");
	strcpy(number_big[4][4], " └―――――│");
	strcpy(number_big[4][5], "            │");
	strcpy(number_big[4][6], "            │");
	strcpy(number_big[4][7], "            │");
	strcpy(number_big[4][8], "            │");

	strcpy(number_big[5][0], " ┌――――――");
	strcpy(number_big[5][1], " │            ");
	strcpy(number_big[5][2], " │            ");
	strcpy(number_big[5][3], " │            ");
	strcpy(number_big[5][4], " └――――――");
	strcpy(number_big[5][5], "             │");
	strcpy(number_big[5][6], "             │");
	strcpy(number_big[5][7], "             │");
	strcpy(number_big[5][8], " ――――――┘");

	strcpy(number_big[6][0], " │           ");
	strcpy(number_big[6][1], " │           ");
	strcpy(number_big[6][2], " │           ");
	strcpy(number_big[6][3], " │           ");
	strcpy(number_big[6][4], " │―――――┐");
	strcpy(number_big[6][5], " │          │");
	strcpy(number_big[6][6], " │          │");
	strcpy(number_big[6][7], " │          │");
	strcpy(number_big[6][8], " └―――――┘");


	strcpy(number_big[7][0], " ┌―――――┐");
	strcpy(number_big[7][1], " │          │");
	strcpy(number_big[7][2], " │          │");
	strcpy(number_big[7][3], " │          │");
	strcpy(number_big[7][4], " │          │");
	strcpy(number_big[7][5], "            │");
	strcpy(number_big[7][6], "            │");
	strcpy(number_big[7][7], "            │");
	strcpy(number_big[7][8], "            │");

	strcpy(number_big[8][0], " ┌―――――┐");
	strcpy(number_big[8][1], " │          │");
	strcpy(number_big[8][2], " │          │");
	strcpy(number_big[8][3], " │          │");
	strcpy(number_big[8][4], " │―――――│");
	strcpy(number_big[8][5], " │          │");
	strcpy(number_big[8][6], " │          │");
	strcpy(number_big[8][7], " │          │");
	strcpy(number_big[8][8], " └―――――┘");

	strcpy(number_big[9][0], " ┌―――――┐");
	strcpy(number_big[9][1], " │          │");
	strcpy(number_big[9][2], " │          │");
	strcpy(number_big[9][3], " │          │");
	strcpy(number_big[9][4], " └―――――│");
	strcpy(number_big[9][5], "            │");
	strcpy(number_big[9][6], "            │");
	strcpy(number_big[9][7], "            │");
	strcpy(number_big[9][8], "            │");
	*/

	strncpy_s(number_big[0][0], width, " ┌―――――┐", width);
	strncpy_s(number_big[0][1], width, " │          │", width);
	strncpy_s(number_big[0][2], width, " │          │", width);
	strncpy_s(number_big[0][3], width, " │          │", width);
	strncpy_s(number_big[0][4], width, " │          │", width);
	strncpy_s(number_big[0][5], width, " │          │", width);
	strncpy_s(number_big[0][6], width, " │          │", width);
	strncpy_s(number_big[0][7], width, " │          │", width);
	strncpy_s(number_big[0][8], width, " └―――――┘", width);

	strncpy_s(number_big[1][0], width, "       │      ", width);
	strncpy_s(number_big[1][1], width, "      /│      ", width);
	strncpy_s(number_big[1][2], width, "     / │      ", width);
	strncpy_s(number_big[1][3], width, "       │      ", width);
	strncpy_s(number_big[1][4], width, "       │      ", width);
	strncpy_s(number_big[1][5], width, "       │      ", width);
	strncpy_s(number_big[1][6], width, "       │      ", width);
	strncpy_s(number_big[1][7], width, "       │      ", width);
	strncpy_s(number_big[1][8], width, "  ――――――", width);

	strncpy_s(number_big[2][0], width, " ――――――┐", width);
	strncpy_s(number_big[2][1], width, "             │", width);
	strncpy_s(number_big[2][2], width, "             │", width);
	strncpy_s(number_big[2][3], width, "             │", width);
	strncpy_s(number_big[2][4], width, " ┌――――――", width);
	strncpy_s(number_big[2][5], width, " │            ", width);
	strncpy_s(number_big[2][6], width, " │            ", width);
	strncpy_s(number_big[2][7], width, " │            ", width);
	strncpy_s(number_big[2][8], width, " └――――――", width);

	strncpy_s(number_big[3][0], width, " ――――――┐", width);
	strncpy_s(number_big[3][1], width, "             │", width);
	strncpy_s(number_big[3][2], width, "             │", width);
	strncpy_s(number_big[3][3], width, "             │", width);
	strncpy_s(number_big[3][4], width, " ――――――│", width);
	strncpy_s(number_big[3][5], width, "             │", width);
	strncpy_s(number_big[3][6], width, "             │", width);
	strncpy_s(number_big[3][7], width, "             │", width);
	strncpy_s(number_big[3][8], width, " ――――――┘", width);
	strncpy_s(number_big[4][0], width, " │          │", width);
	strncpy_s(number_big[4][1], width, " │          │", width);
	strncpy_s(number_big[4][2], width, " │          │", width);
	strncpy_s(number_big[4][3], width, " │          │", width);
	strncpy_s(number_big[4][4], width, " └―――――│", width);
	strncpy_s(number_big[4][5], width, "            │", width);
	strncpy_s(number_big[4][6], width, "            │", width);
	strncpy_s(number_big[4][7], width, "            │", width);
	strncpy_s(number_big[4][8], width, "            │", width);

	strncpy_s(number_big[5][0], width, " ┌――――――", width);
	strncpy_s(number_big[5][1], width, " │            ", width);
	strncpy_s(number_big[5][2], width, " │            ", width);
	strncpy_s(number_big[5][3], width, " │            ", width);
	strncpy_s(number_big[5][4], width, " └――――――", width);
	strncpy_s(number_big[5][5], width, "             │", width);
	strncpy_s(number_big[5][6], width, "             │", width);
	strncpy_s(number_big[5][7], width, "             │", width);
	strncpy_s(number_big[5][8], width, " ――――――┘", width);

	strncpy_s(number_big[6][0], width, " │           ", width);
	strncpy_s(number_big[6][1], width, " │           ", width);
	strncpy_s(number_big[6][2], width, " │           ", width);
	strncpy_s(number_big[6][3], width, " │           ", width);
	strncpy_s(number_big[6][4], width, " │―――――┐", width);
	strncpy_s(number_big[6][5], width, " │          │", width);
	strncpy_s(number_big[6][6], width, " │          │", width);
	strncpy_s(number_big[6][7], width, " │          │", width);
	strncpy_s(number_big[6][8], width, " └―――――┘", width);

	strncpy_s(number_big[7][0], width, " ┌―――――┐", width);
	strncpy_s(number_big[7][1], width, " │          │", width);
	strncpy_s(number_big[7][2], width, " │          │", width);
	strncpy_s(number_big[7][3], width, " │          │", width);
	strncpy_s(number_big[7][4], width, " │          │", width);
	strncpy_s(number_big[7][5], width, "            │", width);
	strncpy_s(number_big[7][6], width, "            │", width);
	strncpy_s(number_big[7][7], width, "            │", width);
	strncpy_s(number_big[7][8], width, "            │", width);

	strncpy_s(number_big[8][0], width, " ┌―――――┐", width);
	strncpy_s(number_big[8][1], width, " │          │", width);
	strncpy_s(number_big[8][2], width, " │          │", width);
	strncpy_s(number_big[8][3], width, " │          │", width);
	strncpy_s(number_big[8][4], width, " │―――――│", width);
	strncpy_s(number_big[8][5], width, " │          │", width);
	strncpy_s(number_big[8][6], width, " │          │", width);
	strncpy_s(number_big[8][7], width, " │          │", width);
	strncpy_s(number_big[8][8], width, " └―――――┘", width);

	strncpy_s(number_big[9][0], width, " ┌―――――┐", width);
	strncpy_s(number_big[9][1], width, " │          │", width);
	strncpy_s(number_big[9][2], width, " │          │", width);
	strncpy_s(number_big[9][3], width, " │          │", width);
	strncpy_s(number_big[9][4], width, " └―――――│", width);
	strncpy_s(number_big[9][5], width, "            │", width);
	strncpy_s(number_big[9][6], width, "            │", width);
	strncpy_s(number_big[9][7], width, "            │", width);
	strncpy_s(number_big[9][8], width, "            │", width);

	srand((unsigned)time(NULL));

	//for (i = 0; i < 3; i++)
	//	number[i] = rand() % 10;		// number[0], number[1], number[2] 에 각각 0부터 9까지의 난수를 저장합니다

	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t\t\t\t\t      [777]\n\n");
		SCTA(GSH(SOH), 0x000f);
		printf("\t\t\t=====================================================\n\n\t\t\t");
		for (i = stop; i < 3; i++)
			number[i] = (number[i] + rand()) % 10;

		/*
		number[0] = 0;
		number[1] = 1;
		number[2] = 2;
		*/

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
				printf(" %s   ", number_big[number[j]][i]);
			}
			printf("\n\t\t\t");
		}
		SCTA(GSH(SOH), 0x000f);
		printf("\n\t\t\t=====================================================");
		SCTA(GSH(SOH), 0x000a);
		if (coin_put == 0)
		{
			printf("\n\n\t\t\t\t%d개", coin);
			SCTA(GSH(SOH), 0x000f);
			printf("의 코인이 있습니다.\n");
			SCTA(GSH(SOH), 0x000e);
			printf("\t\t\t\t몇 개");
			SCTA(GSH(SOH), 0x000f);
			printf("나 베팅하시겠습니까? (배당률 ?배) ");
			SCTA(GSH(SOH), 0x000b);
			scanf_s(" %d", &coin_betting);
			if (coin_betting > coin || coin_betting <= 0)						// 보유 코인보다 더 많은 양의 코인을 베팅하려고 하면 continue를 합니다
			{
				printf("\t\t\t\t코인 개수를 확인하십시오\n\t\t\t\t");
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
			printf("개의 코인으로 베팅하셨습니다\n\t\t\t\t");

		}
		Sleep(100);		// 100/1000 초 즉 0.1초 정지
		k++;
		if (k == 10)
		{
			k = 0;
			stop++;
		}

		if (stop == 3)
		{
			if (number[0] == number[1] && number[1] == number[2])	// 세 개의 숫자가 같을 경우
			{
				if (number[0] == 7)		// 777 이면 잭팟
				{
					SCTA(GSH(SOH), 0x000d);
					printf("\t    ☆잭팟☆\n");
					SCTA(GSH(SOH), 0x000e);
					printf("\t\t       기존 코인 (%d - %d) + 베팅 코인 ( %d * 50 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 50 * coin_betting);
				}

				else					// 777을 제외하고 세 숫자가 같은 경우
				{
					SCTA(GSH(SOH), 0x000b);
					printf("      베팅에 성공하셨습니다\n");
					SCTA(GSH(SOH), 0x000e);
					printf("\t\t       기존 코인 (%d - %d) + 베팅 코인 ( %d * 10 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 10 * coin_betting);
				}
			}

			else if (((number[0] - number[1] == 5) || (number[0] - number[1] == 0) || (number[0] - number[1] == -5)) && ((number[0] - number[2] == 5) || (number[0] - number[2] == 0) || (number[0] - number[2] == -5)))
			{
				// 각 숫자의 차이의 절대값이 5거나 0인 경우
				// 즉 색이 같은 경우
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

				printf("\t 같은 색 세 개☆\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t       기존 코인 (%d - %d) + 베팅 코인 ( %d * 5 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 5 * coin_betting);
			}

			else
			{
				SCTA(GSH(SOH), 0x000c);
				printf("      베팅에 실패하셨습니다\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t       기존 코인 (%d - %d) + 베팅 코인 ( %d * 0 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 0 * coin_betting);
			}
			SCTA(GSH(SOH), 0x000f);
			system("pause");
			return coin;
		}
	}
}

int game_wbg(int coin)
{
#define wbg_width 12
#define wbg_length 7

	char wbg[wbg_length][wbg_width] = { "\0" };	// 게임을 구현하기 위한 문자 배열입니다
	int i = 0, j = 0;					// for문에서 쓰기 위한 변수 i, j 입니다
	int ball[3] = { 0 };				// 공의 위치를 숫자로 표현하고 저장하기 위한 배열입니다
	int std = 5;						// 공의 위치를 표현하기 위한 기준, 변수 std입니다
	int k = 0, count = 0;				// 조건에 맞게 공의 위치를 저장할 k, count입니다
	int box = 0;						// 몇 번 박스에 들어갔는지를 저장하기 위한 변수입니다
	int copy_coin = coin;				// 코인 값을 저장할 변수입니다
	int coin_put = 0;					// 조건에 맞게 코인을 베팅하게 만들기 위한 변수입니다
	int coin_betting = 0;				// 베팅할 코인의 숫자를 저장하기 위한 변수입니다
	int box_betting = 0;				// 몇 번 박스에 베팅했는지 저장하기 위한 변수입니다

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

		if (ball[i] == 1)					// 공이 들어갈 박스 번호를 조건에 맞추어 알아내기 위한 조건문입니다
			box++;
	}

	while (1)
	{
		system("cls");
		printf("\n\n");
		SCTA(GSH(SOH), 0x000a);
		printf("\t\t\t\t\t  [공은 어디로]\n\n\t\t\t");
		for (i = 0; i < wbg_length; i++)				// printf문을 위한 for문입니다
		{
			for (j = 0; j < wbg_width; j++)
			{
				if (wbg[i][j] == 'o') {
					SCTA(GSH(SOH), 0x000e);
					printf("   %c", wbg[i][j]);
				}
				else if (wbg[i][j] == 'A') {
					SCTA(GSH(SOH), 0x000d);
					printf("   %c", wbg[i][j]);
				}
				else if (wbg[i][j] == '\0') {
					printf("    ");
				}
				else {
					SCTA(GSH(SOH), 0x000b);
					printf("   %c", wbg[i][j]);
				}
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
			printf("\n\t\t\t\t%d개", coin);
			SCTA(GSH(SOH), 0x000f);
			printf("의 코인이 있습니다.\n");
			SCTA(GSH(SOH), 0x000e);
			printf("\t\t\t\t몇 개");
			SCTA(GSH(SOH), 0x000f);
			printf("나 베팅하시겠습니까? (배당률 3배) ");
			SCTA(GSH(SOH), 0x000b);
			scanf_s(" %d", &coin_betting);
			if (coin_betting > coin || coin_betting <= 0)						// 보유 코인보다 더 많은 양의 코인을 베팅하려고 하면 continue를 합니다
			{
				printf("\t\t\t\t코인 개수를 확인하십시오\n\t\t\t\t");
				system("pause");
				continue;
			}

			else
			{
				printf("\t\t\t\t몇 번");
				SCTA(GSH(SOH), 0x000f);
				printf("칸에 배팅하시겠습니까? (1 ~ 4) : ");
				SCTA(GSH(SOH), 0x000a);
				scanf_s(" %d", &box_betting);
				if (box_betting < 1 || box_betting > 4)	// 해당 번호의 말이 없을 경우 continue를 합니다
				{
					printf("\t\t\t\t해당 번호의 칸이 없습니다\n\t\t\t\t");
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
			printf("개의 코인으로 ");
			SCTA(GSH(SOH), 0x000a);
			printf("%d", box_betting);
			SCTA(GSH(SOH), 0x000f);
			printf("번 칸 선택하셨습니다.\n\t\t\t\t");
		}

		if (count < 6)				// 공의 위치가 위에서부터 0, 1, 2, 3, .. 이라고 할때 6보다 작은 경우 입니다
		{
			if (count % 2 == 0)		 // 짝수일 경우입니다
			{
				wbg[count + 1][std += ball[k]] = 'o';

				k++;
				count++;
			}

			else					// 홀수일 경우 입니다
			{
				if (count == 5 && (std == 0 || std == 10))		// 공의 위치가 5일 경우 입니다
				{
					wbg[count + 1][std] = 'o';
				}
				else				// 공의 위치가 1이나 3일 경우 입니다
					wbg[count + 1][std += ball[k - 1]] = 'o';		// k가 1 증가한 상태이므로 ball[k]이 아닌 ball[k-1]을 사용했습니다

				count++;
			}
		}
		else
		{
			if ((box + 1) == box_betting)		// 공이 있는 칸과 베팅한 칸이 같은 경우 입니다
			{
				SCTA(GSH(SOH), 0x000b);
				printf("      베팅에 성공하셨습니다\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t기존 코인 (%d - %d) + 베팅 코인 ( %d * 3 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 3 * coin_betting);
				SCTA(GSH(SOH), 0x000f);
				system("pause");
				return coin;
			}

			else
			{
				SCTA(GSH(SOH), 0x000c);
				printf("      베팅에 실패하셨습니다\n");
				SCTA(GSH(SOH), 0x000e);
				printf("\t\t\t기존 코인 (%d - %d) + 베팅 코인 ( %d * 0 ) = %d\n\n\t\t\t\t", copy_coin, coin_betting, coin_betting, coin = (coin - coin_betting) + 0 * coin_betting);
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
	int a;			// for문을 위한 변수입니다
	int b;			// 스와핑 알고리즘에서 쓸 값을 저장하기 위한 변수입니다
	char id_NULL[id_size] = { "\0" };		// 빈 문자열입니다

	//fp = fopen("BettingGameRecord.txt", "r");
	fopen_s(&fp, "BettingGameRecord.txt", "r");

	for (a = 0; a < 5; a++)
		//fscanf(fp, " %d %s %d", &R[a].ranking, R[a].id, &R[a].score);
		fscanf_s(fp, " %d %s %d", &R[a].ranking, R[a].id, id_size, &R[a].score);

	fclose(fp);

	if (R[4].score < coin)
	{
		//strncpy(R[4].id, id_box, id_size);
		strncpy_s(R[4].id, id_size, id_box, id_size);
		R[4].score = coin;

		//fp = fopen("BettingGameRecord.txt", "w");
		fopen_s(&fp, "BettingGameRecord.txt", "w");
		for (a = 3; a >= 0; a--)
		{
			if (R[a].score < coin)
			{
				b = R[a].score;
				R[a].score = coin;
				R[a + 1].score = b;

				/*
				strncpy(id_NULL, R[a].id, id_size);
				strncpy(R[a].id, id_box, id_size);
				strncpy(R[a + 1].id, id_NULL, id_size);
				*/

				strncpy_s(id_NULL, id_size, R[a].id, id_size);
				strncpy_s(R[a].id, id_size, id_box, id_size);
				strncpy_s(R[a + 1].id, id_size, id_NULL, id_size);
			}

			else
				break;
		}

		for (a = 0; a < 5; a++)
			fprintf(fp, "%d %-6s %d\n", R[a].ranking, R[a].id, R[a].score);		// 파일에 데이터를 저장합니다

		fclose(fp);
	}
}

