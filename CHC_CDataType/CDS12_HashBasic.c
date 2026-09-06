// CDS12_HashBasic.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define SIZE 100
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct{
    int id;
    char name[100];
    int score;
    char gender;
}Student;
// ===============================================================
// < 전 역 변 수 >
// ===============================================================
Student* hashTable[SIZE]; // 포인터배열 100개
// ===============================================================
// < 전 역 함 수 >
// ===============================================================
void InitStudent(Student* s){
    static int studentNumber = 20260001;
    char nameList[10][100]={"KDS","NDS","JBY","KBM","KMJ","AEJ","KSL","AAA","BBB","CCC"};
    // 데이터 삽입
    s->gender = rand()%2==0 ? 'F' : 'M';
    s->id = studentNumber++;
    strcpy(s->name ,nameList[rand()%10]);
    s->score = rand()%101; // 0~100
}
void PrintStudent(Student* s){
    printf("--------------\n");
    printf(" > ID : %d\n",s->id);
    printf(" > NAME : %s\n",s->name);
    printf(" > GENDER : %c\n",s->gender);
    printf(" > SCORE : %d\n",s->score);
    printf("--------------\n");
}
void InitStudentArray(Student* sAry,int size){
    for(int i=0;i<size;i++){
        InitStudent(&sAry[i]);
    }
}
void PrintStudentArray(Student* sAry,int size){
    for(int i=0;i<size;i++){
        PrintStudent(&sAry[i]);
    }
}
// --------------------------------------------------------------
// 해시 함수 - 원본을 어떠한 형식으로 변환 시키는 공식함수
// --------------------------------------------------------------
int Hash(int id){
    return id%SIZE;
}
// 해시 추가함수
void InsertHashTable(Student* s){
    // 학생정보 중, ID를 해시로 변환해서 해시테이블 저장
    int index = Hash(s->id); // 0~99
    hashTable[index] = s;
    // 원본의 어떠한 1개 구조체의 "주소"를 해시테이블에
    // ID값을 해시 함수를 이용해서 저장시킴
}
void InsertHashTableArray(Student* sAry, int size){
    for(int i=0;i<size;i++){
        InsertHashTable(&sAry[i]);
    }
}

Student* FindStudent(int targetID){
    int index = Hash(targetID);
    PrintStudent(hashTable[index]);
    return hashTable[index];
}

void UpdateStudent(){
    printf("< UPDATE STUDENT >\n");
    int targetID;
    printf("Input TargetID : ");
    scanf("%d", &targetID);
    // ------------------------------------
    // 안전장치
    if( hashTable[Hash(targetID)] == NULL ){
        printf("Not Found Target\n");
        return;
    }
    // --------------------------------------
    Student* temp = FindStudent(targetID);
    strcpy(temp->name, "KKKKKKKKKKK");
    temp->score = -999;

    PrintStudent(temp);
}
// ===============================================================
int main(){
    srand(time(NULL));
    Student stu[100];
    InitStudentArray(stu,100);
    PrintStudentArray(stu,100);
    printf("=============================\n");
    // ---------------------------------------
    // 기본세팅 끝. 이제 해시 진행
    // ---------------------------------------
    // 해시테이블에 결과 저장하기
    InsertHashTableArray(stu,100);
    // // 특정 값 검색하기
    // int searchID = 0;
    // printf("Input Search ID : ");
    // scanf("%d", &searchID);

    // Student* temp = FindStudent(searchID);
    // temp->score+=20;
    UpdateStudent();
} // ===============================================================
/*
< 도서관 - 시스템 >
도서ID를 이용해서 해시 테이블에 책 이라는 구조체를 저장. 
0. 책 구조체 : bookID - 순서대로 저장, bookName(랜덤), bookPrice / Chain 사용시, next필요

1. 도서 검색 -> 도서ID
   1.1 있는 경우 
    1) 도서정보 출력
    2) 도서정보 수정
        - 도서 이름 변경
        - 도서 가격 변경
        - 변경 이후, 출력 한번 하면 될 듯.
    3) 도서정보 삭제 - Basic버전은 생각을 해봐야 함...    
   1.2 없는 경우
    1) 없다고 하면 끝. 다시 메인 화면으로 이동

당연히, 종료 있어야 하고, 너무 빨리 지나가지 않게
Sleep도 적당히 걸어주세요.    

*/

