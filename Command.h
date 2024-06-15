#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define BUFF_SIZE 100

typedef struct Chess_Piece {
	char name[10];
	//각 체스말의 대문자, NULL(공백)은 "-"
	char type[2];
	//'0' means black team, '1' means white team, '2' means NONE
	int team;
	//index 1: RANK, index 2: FILE
	int position[2];
	//1 = 'moving two RANK' is able, 0 is not
	int token;
} Chess_Piece;

void Print_ChessBoard(Chess_Piece* Chess_Board_PTR);

char* Get_buffer(void);

int Distinguish_Command(char* Command_BUFF_PTR, Chess_Piece* Chess_Board_PTR);

int Put_ChessPiece(char* storage[], Chess_Piece* Chess_Board_PTR); 

void exclude(char* storage[], Chess_Piece* Chess_Board_PTR);

void C(void);

void E(void);


void Print_ChessBoard(Chess_Piece* Chess_Board_PTR) {

	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("%s ", (*(Chess_Board_PTR + i * 8 + j)).type);
		}
	}
};

char* Get_buffer(void) {
	char* temp;
	char* Command_BUFF_PTR;
	Command_BUFF_PTR = (char*)malloc(BUFF_SIZE);
	int i;
	int size = 100;
	for (i = 0; (Command_BUFF_PTR[i] = getchar()) != 10; i++) {
		if (i % 99 == 0) {
			size += 99;
			temp = realloc(Command_BUFF_PTR, sizeof(char) * size);
			if (temp != NULL) {
				Command_BUFF_PTR = temp;
			}
		}
	}//for문
	Command_BUFF_PTR[(i + 1)] = 0;
	return Command_BUFF_PTR;
};

int Distinguish_Command(char* Command_BUFF_PTR, Chess_Piece* Chess_Board_PTR) {

	int i, j, k = 0, last_space = 0;

	char* storage[BUFF_SIZE] = { 0 };
	storage[0] = (char*)malloc(sizeof(char) * BUFF_SIZE);


	if (Command_BUFF_PTR[0] == 33) {
		for (i = 0; Command_BUFF_PTR[i] != 0; i++) {
			if (Command_BUFF_PTR[i] == 32 && Command_BUFF_PTR[i - 1] != 32) {
				for (j = last_space; j < i; j++) {
					storage[k][(j - last_space)] = Command_BUFF_PTR[j + 1];
				}
				storage[k][i - (1 + last_space)] = 0;
				//printf("%s\n", storage[k]);
				k++;
				storage[k] = (char*)malloc(sizeof(char) * BUFF_SIZE);
				last_space = i;
				storage;
			}
		}
		for (j = last_space; j < i; j++) {
			storage[k][(j - last_space)] = Command_BUFF_PTR[j + 1];
		}
		storage[k][i - (2 + last_space)] = 0;
		//printf("%s\n", storage[k]);
	}
	else {
		printf("<< 명령어 채팅을 쓰실땐 느낌표를 문장 맨 앞에 꼭 붙이세요!");
		return 0;
	}
	//help
	if (!strcmp(storage[0], "help"))
	{
		printf("<< 도움말 준비 중...");
	}
	//put Chess_Piece
	else if (!strcmp(storage[0], "put"))
	{
		Put_ChessPiece(storage, Chess_Board_PTR);
	}
	//map
	else if (!strcmp(storage[0], "map"))
	{
		Print_ChessBoard(Chess_Board_PTR);
	}
	//clear
	else if (!strcmp(storage[0], "clear"))
	{
		system("cls");
	}
	//kill
	else if (!strcmp(storage[0], "kill"))
	{
		printf("preparing");
	}
	//kill
	else if (!strcmp(storage[0], "kill"))
	{
		printf("preparing");
	}
	//exclude
	else if (!strcmp(storage[0], "exclude"))
	{
		exclude(storage, Chess_Board_PTR);
	}
	//default
	else
	{
		printf("<< 존재하지 않는 명령어입니다.");
	}

	free(Command_BUFF_PTR);

	return 0;
};

void exclude(char* storage[], Chess_Piece* Chess_Board_PTR)
{
	char type = *(storage[1]);
	int i, j;

	switch (type)
	{
	case 'R':
		for (i = 0; i < 8; i++) {
			printf("\n");
			for (j = 0; j < 8; j++) {
				if (!strcmp((Chess_Board_PTR + i * 8 + j)->type, "R")) {
					(Chess_Board_PTR + i * 8 + j)->token = 0;
					(Chess_Board_PTR + i * 8 + j)->team = 2;
					(Chess_Board_PTR + i * 8 + j)->position[0] = i + 1;
					(Chess_Board_PTR + i * 8 + j)->position[1] = j + 1;
					strcpy_s((Chess_Board_PTR + i * 8 + j)->name, 10, "None");
					strcpy_s((Chess_Board_PTR + i * 8 + j)->type, 2, "-");
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
				else {
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
			}
		}
		break;

	case 'P':
		for (i = 0; i < 8; i++) {
			printf("\n");
			for (j = 0; j < 8; j++) {
				if (!strcmp((Chess_Board_PTR + i * 8 + j)->type, "P")) {
					(Chess_Board_PTR + i * 8 + j)->token = 0;
					(Chess_Board_PTR + i * 8 + j)->team = 2;
					(Chess_Board_PTR + i * 8 + j)->position[0] = i + 1;
					(Chess_Board_PTR + i * 8 + j)->position[1] = j + 1;
					strcpy_s((Chess_Board_PTR + i * 8 + j)->name, 10, "None");
					strcpy_s((Chess_Board_PTR + i * 8 + j)->type, 2, "-");
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
				else {
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
			}
		}
		break;
	case 'B':
		for (i = 0; i < 8; i++) {
			printf("\n");
			for (j = 0; j < 8; j++) {
				if (!strcmp((Chess_Board_PTR + i * 8 + j)->type, "B")) {
					(Chess_Board_PTR + i * 8 + j)->token = 0;
					(Chess_Board_PTR + i * 8 + j)->team = 2;
					(Chess_Board_PTR + i * 8 + j)->position[0] = i + 1;
					(Chess_Board_PTR + i * 8 + j)->position[1] = j + 1;
					strcpy_s((Chess_Board_PTR + i * 8 + j)->name, 10, "None");
					strcpy_s((Chess_Board_PTR + i * 8 + j)->type, 2, "-");
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
				else {
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
			}
		}
		break;

	case 'N':
		for (i = 0; i < 8; i++) {
			printf("\n");
			for (j = 0; j < 8; j++) {
				if (!strcmp((Chess_Board_PTR + i * 8 + j)->type, "N")) {
					(Chess_Board_PTR + i * 8 + j)->token = 0;
					(Chess_Board_PTR + i * 8 + j)->team = 2;
					(Chess_Board_PTR + i * 8 + j)->position[0] = i + 1;
					(Chess_Board_PTR + i * 8 + j)->position[1] = j + 1;
					strcpy_s((Chess_Board_PTR + i * 8 + j)->name, 10, "None");
					strcpy_s((Chess_Board_PTR + i * 8 + j)->type, 2, "-");
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
				else {
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
			}
		}
		break;

	case 'Q':
		for (i = 0; i < 8; i++) {
			printf("\n");
			for (j = 0; j < 8; j++) {
				if (!strcmp((Chess_Board_PTR + i * 8 + j)->type, "Q")) {
					(Chess_Board_PTR + i * 8 + j)->token = 0;
					(Chess_Board_PTR + i * 8 + j)->team = 2;
					(Chess_Board_PTR + i * 8 + j)->position[0] = i + 1;
					(Chess_Board_PTR + i * 8 + j)->position[1] = j + 1;
					strcpy_s((Chess_Board_PTR + i * 8 + j)->name, 10, "None");
					strcpy_s((Chess_Board_PTR + i * 8 + j)->type, 2, "-");
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
				else {
					printf("%s ", (Chess_Board_PTR + i * 8 + j)->type);
				}
			}
		}
		break;
	default:
		printf("NON_TYPE?");
		break;
	}
};



void C(void) {
	printf("Debug Clear!");
}

void E(void) {
	printf("Something error!");
}