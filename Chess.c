#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "Command.h"


#pragma warning (disable:26451) 


/*
룩(Rook)
나이트(Knight)
퀸(Queen)
킹(King)
폰(Pawn)
비숍(Bishop)
*/

int main() {
	Chess_Piece Chess_Board[8][8] = {

	{{"Rook","R", 0, {1,1}, 1}, {"Knight","N", 0, {1,2}, 1}, {"Bishop", "B", 0, {1,3}, 1}, {"Queen", "Q", 0, {1,4}, 1},
	{"King", "K", 0, {1,5}, 1}, {"Bishop", "B", 0, {1,6}, 1}, {"Knight","N", 0, {1,7}, 1}, {"Rook","R", 0, {1,8}, 1}},
	//RANK_1 (ONE)

	{{"Pawn", "P", 0, {2,1}, 1}, {"Pawn", "P", 0, {2,2}, 1}, {"Pawn", "P", 0, {2,3}, 1}, {"Pawn", "P", 0, {2,4}, 1},
	{"Pawn", "P", 0, {2,5}, 1}, {"Pawn", "P", 0, {2,6}, 1}, {"Pawn", "P", 0, {2,7}, 1}, {"Pawn", "P", 0, {2,8}, 1}},
	//RANK_2 (TWO)

	{{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0},
	{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}},
	//RANKE_3

	{{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0},
	{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}},
	//RANK_4

	{{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0},
	{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}},
	//RANK_5

	{{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0},
	{"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}, {"None", "-", 2, { 0,0 }, 0}},
	//RANK_6

	{{"Pawn", "P", 1, {7,1}, 1}, {"Pawn", "P", 1, {7,2}, 1}, {"Pawn", "P", 1, {7,3}, 1}, {"Pawn", "P", 1, {7,4}, 1},
	{"Pawn", "P", 1, {7,5}, 1}, {"Pawn", "P", 1, {7,6}, 1}, {"Pawn", "P", 1, {7,7}, 1}, {"Pawn", "P", 1, {7,8}, 1}},
	//RANK_7 (SEVEN)

	{{"Rook","R",1, {8,1}, 1}, {"Knight","N", 1, {8,2}, 1}, {"Bishop", "B", 1, {8,3}, 1}, {"Queen", "Q", 1, {8,4}, 1},
	{"King", "K", 1, {8,5}, 1}, {"Bishop", "B", 1, {8,6}, 1}, {"Knight","N", 1, {8,7}, 1}, {"Rook","R",1, {8,8}, 1}},
	//RANK_8 (EIGHT)
	};


	Chess_Piece* Chess_Board_PTR = Chess_Board;
	Print_ChessBoard(Chess_Board_PTR);
	while (1)
	{
		printf("\n\n>> ");
		char* Command_BUFF_PTR = Get_buffer();
		printf("<< %s", Command_BUFF_PTR);
		Distinguish_Command(Command_BUFF_PTR, Chess_Board_PTR);
	}
};



int Put_ChessPiece(char* storage[], Chess_Piece* Chess_Board_PTR) {

	for (int i = 0; i < 7; i++)
	{
		if (storage[i] == 0) {
			printf("<< 체스말 명령어(이동)에 필요한 정보(인자)들이 부족합니다.");
			return -1;
		}
	}

	if (storage[7] != 0) {
		printf("<< 채팅에 쓰인 명령어 인자들이 너무 많습니다!");
		return -1;
	}

	//RANK 행 - 가로
	//FILE 열 - 세로

	int RANK;
	int FILE;

	int NEXT_RANK;
	int NEXT_FILE;


	if (!strcmp(storage[1], "p")) {

		if ((RANK = atoi(storage[2])) == 0 || (FILE = atoi(storage[3])) == 0) {
			printf("<< 체스말의 현재 위치(2인자, 3인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
		}
		else {
			if (!strcmp((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, "P") && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team == 0)
			{
				if (strcmp(storage[4], "on")) {
					printf("<< 잘못된 체스말 이동 양식!");
					return -1;
				}


				if ((NEXT_RANK = atoi(storage[5])) == 0 || (NEXT_FILE = atoi(storage[6])) == 0) {
					printf("<< 체스말이 이동할 위치(4인자, 5인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
				}

#pragma region 폰 움직일 곳 적합성 판단
#pragma region 폰 움직일 곳 적합성 판단
#pragma region 폰 움직일 곳 적합성 판단

				else {
					if (NEXT_RANK == (RANK + 1) && NEXT_FILE == FILE && !strcmp((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name, "None")) {
						//printf("all clear, %d\n", NEXT_RANK);
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->token = 0;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team = 2;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[0] = RANK;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[1] = FILE;
						strcpy_s((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->name, 10, "None");
						strcpy_s((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, 2, "-");
						/*
						printf("%s\n", (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->name);
						printf("%d, %d\n", (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[0], (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[1]);
						*/
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->token = 0;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->team = 0;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[0] = NEXT_RANK;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[1] = NEXT_FILE;
						strcpy_s((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name, 10, "Pawn");
						strcpy_s((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->type, 2, "P");
						/*
						printf("%s\n", (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name);
						printf("%d, %d\n", (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[0], (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[1]);
						*/
						Print_ChessBoard(Chess_Board_PTR);
					}
					else if (NEXT_RANK == (RANK + 1) && (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->team == 1 && NEXT_FILE == FILE + 1 || NEXT_FILE == FILE - 1) {
						//printf("all clear, %d\n", NEXT_RANK);
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->token = 0;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team = 2;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[0] = RANK;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[1] = FILE;
						strcpy_s((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->name, 10, "None");
						strcpy_s((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, 2, "-");
						/*
						printf("%s\n", (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->name);
						printf("%d, %d\n", (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[0], (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[1]);
						*/
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->token = 0;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->team = 0;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[0] = NEXT_RANK;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[1] = NEXT_FILE;
						strcpy_s((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name, 10, "Pawn");
						strcpy_s((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->type, 2, "P");
						/*
						printf("%s\n", (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name);
						printf("%d, %d\n", (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[0], (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[1]);
						*/
						Print_ChessBoard(Chess_Board_PTR);
					}
					else if (NEXT_RANK == (RANK + 2) && NEXT_FILE == FILE && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->token == 1 && !strcmp((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name, "None")) {
						//printf("all clear, %d\n", NEXT_RANK);
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->token = 0;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team = 2;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[0] = RANK;
						(Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[1] = FILE;
						strcpy_s((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->name, 10, "None");
						strcpy_s((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, 2, "-");
						/*
						printf("%s\n", (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->name);
						printf("%d, %d\n", (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[0], (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->position[1]);
						*/
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->token = 0;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->team = 0;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[0] = NEXT_RANK;
						(Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[1] = NEXT_FILE;
						strcpy_s((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name, 10, "Pawn");
						strcpy_s((Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->type, 2, "P");
						/*
						printf("%s\n", (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->name);
						printf("%d, %d\n", (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[0], (Chess_Board_PTR + (NEXT_RANK - 1) * 8 + NEXT_FILE - 1)->position[1]);
						*/
						Print_ChessBoard(Chess_Board_PTR);
					}
					else printf("해당 칸으로는 이동이 불가능합니다.");
				}


#pragma endregion 폰 움직일 곳 적합성 판단
#pragma endregion 폰 움직일 곳 적합성 판단
#pragma endregion 폰 움직일 곳 적합성 판단

			}
			else printf("<< 해당 위치에는 폰이 없거나 상대팀 폰입니다. 명령어를 다시 입력해 주세요.");
		}

	}
	else if (!strcmp(storage[1], "r")) {

		if ((RANK = atoi(storage[2])) == 0 || (FILE = atoi(storage[3])) == 0) {
			printf("<< 체스말의 현재 위치(2인자, 3인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
			return -1;
		}
		else {
			if (!strcmp((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, "R") && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team == 0)
			{
				if (strcmp(storage[4], "on")) {
					printf("<< 잘못된 체스말 이동 양식!");
					return -1;
				}


				if ((NEXT_RANK = atoi(storage[5])) == 0 || (NEXT_FILE = atoi(storage[6])) == 0) {
					printf("<< 체스말이 이동할 위치(4인자, 5인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
					return -1;
				}
				else {
#pragma region 룩룩룩 행마 적합성
#pragma region 룩룩룩 행마 적합성
#pragma region 룩룩룩 행마 적합성

#pragma region 1
					if (RANK != NEXT_RANK && FILE == NEXT_FILE) {
						if(RANK > NEXT_RANK)
						{//open
							for (int i = RANK-2; i > NEXT_RANK-2; i--) {
								if (!strcmp((Chess_Board_PTR + i * 8 + FILE - 1)->type, "-")) {
									C();
								}
								else {
									E();
									return -1;
								}
							}
						}//close
						else if(RANK < NEXT_RANK)
						{//open
							for (int i = RANK; i < NEXT_RANK; i++) {
								if (!strcmp((Chess_Board_PTR + i * 8 + FILE - 1)->type, "-")) {
									C();
								}
								else {
									E();
									return -1;
								}
							}//close
						}
					}
#pragma region 1

#pragma region 룩룩룩 행마 적합성
#pragma region 룩룩룩 행마 적합성
#pragma region 룩룩룩 행마 적합성

				}
			}
		}
	}
	else if (!strcmp(storage[1], "b")) {

		if ((RANK = atoi(storage[2])) == 0 || (FILE = atoi(storage[3])) == 0) {
			printf("<< 체스말의 현재 위치(2인자, 3인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
		}
		else {
			if (!strcmp((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, "B") && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team == 0)
			{
				if (strcmp(storage[4], "on")) {
					printf("<< 잘못된 체스말 이동 양식!");
					return -1;
				}


				if ((NEXT_RANK = atoi(storage[5])) == 0 || (NEXT_FILE = atoi(storage[6])) == 0) {
					printf("<< 체스말이 이동할 위치(4인자, 5인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
				}
				else {

				}
			}
		}

	}
	else if (!strcmp(storage[1], "k")) {

		if ((RANK = atoi(storage[2])) == 0 || (FILE = atoi(storage[3])) == 0) {
			printf("<< 체스말의 현재 위치(2인자, 3인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
		}
		else {
			if (!strcmp((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, "K") && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team == 0)
			{
				if (strcmp(storage[4], "on")) {
					printf("<< 잘못된 체스말 이동 양식!");
					return -1;
				}


				if ((NEXT_RANK = atoi(storage[5])) == 0 || (NEXT_FILE = atoi(storage[6])) == 0) {
					printf("<< 체스말이 이동할 위치(4인자, 5인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
				}
				else {

				}
			}
		}

	}
	else if (!strcmp(storage[1], "q")) {

		if ((RANK = atoi(storage[2])) == 0 || (FILE = atoi(storage[3])) == 0) {
			printf("<< 체스말의 현재 위치(2인자, 3인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 0, 공백)를 입력 했습니다.");
		}
		else {
			if (!strcmp((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, "Q") && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team == 0)
			{
				if (strcmp(storage[4], "on")) {
					printf("<< 잘못된 체스말 이동 양식!");
					return -1;
				}


				if ((NEXT_RANK = atoi(storage[5])) == 0 || (NEXT_FILE = atoi(storage[6])) == 0) {
					printf("<< 체스말이 이동할 위치(4인자, 5인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
				}
				else {
					printf("all fine");
				}
			}
		}

	}
	else if (!strcmp(storage[1], "n")) {

		if ((RANK = atoi(storage[2])) == 0 || (FILE = atoi(storage[3])) == 0) {
			printf("<< 체스말의 현재 위치(2인자, 3인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
		}
		else {
			if (!strcmp((Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->type, "N") && (Chess_Board_PTR + (RANK - 1) * 8 + FILE - 1)->team == 0)
			{
				if (strcmp(storage[4], "on")) {
					printf("<< 잘못된 체스말 이동 양식!");
					return -1;
				}


				if ((NEXT_RANK = atoi(storage[5])) == 0 || (NEXT_FILE = atoi(storage[6])) == 0) {
					printf("<< 체스말이 이동할 위치(4인자, 5인자)에 대해 숫자를 입력해야 하는데 숫자가 아닌 문자(혹은 공백)를 입력 했습니다.");
				}
				else {
					printf("all fine!");
				}
			}
		}

	}
	else {
		printf("<< 체스말 이동 명령어에서 체스말(1인자)이 양식 밖의 문자로 입력 됐습니다.");
		return -1;
	}

	return 0;

	free(storage);
}



/*

{ {"Rook", "R", "black", { 1,1 }, 1}, { "Knight","N", "black", {1,2}, 1 }, { "Bishop", "B", "black", {1,3}, 1 }, { "Queen", "Q", "black", {1,4}, 1 },
{ "King", "K", "black", {1,5}, 1 }, { "Bishop", "B", "black", {1,6}, 1 }, { "Knight","N", "black", {1,7}, 1 }, { "Rook","R","black", {1,8}, 1 }},
//RANK_1 (ONE)

{ {"Pawn", "P", "black", {2,1}, 1}, {"Pawn", "P", "black", {2,2}, 1}, {"Pawn", "P", "black", {2,3}, 1}, {"Pawn", "P", "black", {2,4}, 1},
{"Pawn", "P", "black", {2,5}, 1}, {"Pawn", "P", "black", {2,6}, 1}, {"Pawn", "P", "black", {2,7}, 1}, {"Pawn", "P", "black", {2,8}, 1} },

*/