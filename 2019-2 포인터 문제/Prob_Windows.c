// Prob_Windows.c
/**
 * OS Windows10
 * Compile with Visual Studio
 * 
 * @title CodeCure_Problem_Pointer
 * @author Taejin
 * @club CodeCure
 * @dept Software Engineering
 * @univ. Sangmyung University
 * @date 9/16/2019
 * @week 2
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> /* strcmp() */
#include <Windows.h> /* system() */

/* =============== Define =============== */
#define TRUE 1
#define FALSE 0

typedef int bool;
/* ====================================== */

/* =============== ProtoType ===============*/
void Swap(); // 매개변수 직접 작성
int StrLen(); // 매개변수 직접 작성
bool Collision();
bool PointerArithmetic();
bool PAAP();
bool CE();
/* =========================================*/

// Start main
int main(void) {
	int a = 10, b = 20;
	char* str = "CodeCure";

	puts("===============Swap Problem===============");
	Swap(&a, &b);
	if (a != 20 || b != 10) {
		puts("Wrong Answer in Swap");
		return -1;
	} else puts("Good Answer in Swap");
	printf("enter to continue "); getchar();
	system("cls");

	puts("===============StrLen Problem===============");
	if (StrLen(str) != 8) {
		puts("Wrong Answer in StrLen");
		return -1;
	} else puts("Good Answer in StrLen");
	printf("enter to continue "); getchar();
	system("cls");

	puts("===============Collision Problem===============");
	if (! Collision()) {
		puts("Wrong Answer in Collision");
		return -1;
	} else puts("Good Answer in Collision");
	getchar();
	printf("enter to continue "); getchar();
	system("cls");

	puts("===============PointerArithmetic Problem===============");
	if (! PointerArithmetic()) {
		puts("Wrong Answer in PointerArithmetic");
		return -1;
	} else puts("Good Answer in PointerArithmetic");
	getchar();
	printf("enter to continue "); getchar();
	system("cls");

	puts("===============PAAP Problem===============");
	if (! PAAP()) {
		puts("Wrong Answer in PAAP");
		return -1;
	} else puts("Good Answer in PAAP");
	printf("enter to continue "); getchar();
	system("cls");

	puts("===============CE Problem===============");
	if (! CE()) {
		puts("Wrong Answer in CE");
		return -1;
	} else puts("Good Answer in CE");
	getchar();
	printf("enter to continue "); getchar();
	system("cls");

	printf("Good Job! You can go Home\n");
	return 0;
} // End main

// 코드, 매개변수까지 직접 작성 (프로토타입까지 변경)
void Swap() {

}

// 코드, 매개변수까지 직접 작성 (프로토타입까지 변경)
int StrLen() {

}

// 코드 수정 금지, 입력 값 조절하여 반환 값 TRUE로 만들기
bool Collision() {
	long long hash = 0x6f43656475436572;

	short* shortPtr = &hash;
	short temp[5];

	shortPtr += 3;
	for (int i = 0; i < 4; i ++)
		temp[i] = *shortPtr--;
	temp[4] = 0;

	char* str = temp;
	char input[10];
	printf("Input str: "); scanf("%s", input);

	if (strcmp(str, input)) {
		puts("Wrong Input");
		return FALSE;
	}
	else return TRUE;
}

// 코드 수정 금지, 입력 값 조절하여 반환 값 TRUE로 만들기
bool PointerArithmetic() {
	char* charPtr = 0x1000;
	short* shortPtr = 0x1000;
	int* intPtr = 0x1000;
	double* doublePtr = 0x1000;

	int answer;

	printf("Input (charPtr): "); scanf("%x", &answer);
	if ((charPtr + 2) != answer) {
		puts("Wrong Input (charPtr)");
		return FALSE;
	} else puts("Good Input (charPtr)");

	printf("Input (shortPtr): "); scanf("%x", &answer);
	if ((shortPtr + 5) != answer) {
		puts("Wrong Input (shortPtr)");
		return FALSE;
	} else puts("Good Input (shortPtr)"); 

	printf("Input (intPtr): "); scanf("%x", &answer);
	if ((intPtr + 3) != answer) {
		puts("Wrong Input (intPtr)");
		return FALSE;
	} else puts("Good Input (intPtr)");

	printf("Input (doublePtr): "); scanf("%x", &answer);
	if ((doublePtr + 4) != answer) {
		puts("Wrong Input (doublePtr)");
		return FALSE;
	} else puts("Good Input (doublePtr)");

	return TRUE;
}

// 기존의 코드 수정 금지, (1)~(4) 중 하나를 주석 처리하여 반환 값 TRUE로 만들기
bool PAAP() {
	int mat[3][4];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			mat[i][j] = i * 10 + j;

	int *(ptr[4]) = mat; // (1)
	int *ptr[4] = mat; // (2)
	int (*ptr)[4] = mat; // (3)
	int (*ptr[4]) = mat; // (4)

	printf("mat[2][3]: %d\n", ptr[2][3]); // 23이 출력되어야 함

	return TRUE;

}

// 코드 수정 금지, 입력 값 조절하여 반환 값 TRUE로 만들기
bool CE() {
	long long int num[2] = { 0x1234567890123456, 0x0987654321098765 };

	long long int* lliPtr;
	char* charPtr;
	short* shortPtr;
	int* intPtr;

	char charAnswer;
	short shortAnswer;
	int intAnswer;
	long long int lliAnswer;

	int temp;

	printf("Input (charAnswer): "); scanf("%x", &temp);
	charAnswer = (char)temp;
	charPtr = num;
	charPtr += 2;
	if ((*charPtr) != charAnswer) {
		puts("Wrong Answer (charAnswer)");
		return FALSE;
	} else puts("Good Input (charAnswer)");

	printf("Input (intAnswer): "); scanf("%x", &intAnswer);
	intPtr = charPtr;
	intPtr += 2;
	if ((*intPtr) != intAnswer) {
		puts("Wrong Answer (intAnswer)");
		return FALSE;
	} else puts("Good Input (intAnswer)");

	printf("Input (shortAnswer): "); scanf("%x", &temp);
	shortAnswer = (short)temp;
	shortPtr = intPtr;
	shortPtr += 2;
	if ((*shortPtr) != shortAnswer) {
		puts("Wrong Answer (shortAnswer)");
		return FALSE;
	} else puts("Good Input (shortAnswer)");

	printf("Input (long long int Answer): "); scanf("%llx", &lliAnswer);
	lliPtr = num + 1;
	if ((*lliPtr) != lliAnswer) {
		puts("Wrong Answer (long long int Answer)");
		return FALSE;
	} else puts("Good Input (long long int Answer)");

	return TRUE;
}