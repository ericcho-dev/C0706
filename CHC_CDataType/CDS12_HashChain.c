// CDS12_HashChain.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define SIZE 10
// ===============================================================
// < 구 조 체 >
// ===============================================================
typedef struct Student{
    int id;
    char gender;
    int score;
    struct Student* next;
}Student;
// ===============================================================
// < 전 역 변 수 >
// ===============================================================
Student* hashTable[SIZE];
// ===============================================================
// < 전 역 함 수 >
// ===============================================================


// 💀 학생 정보 만들기💀
void InitStudent(Student* s){ 
    // 노드를 만드는 것이 아닌, 넘겨받은 곳에 데이터만 채워주는 함수
    static int id = 20260001;
    s-> id = id++;
    s->score = rand()%101;
    s->gender = rand()%2==0 ? 'F' : 'M';
    s->next = NULL;
}

// 🫒 학생 정보 출력🫒
void PrintStudent(Student* s){
    printf("--------------\n");
    printf(" > ID : %d\n",s->id);
    printf(" > GENDER : %c\n",s->gender);
    printf(" > SCORE : %d\n",s->score);
    printf("--------------\n");
}
// ⭐ 해시 함수 ⭐
int Hash(int id){
    return id % SIZE;
}
// 🍅 새로운 학생 노드 생성 🍅
Student* CreateStudent(){
    Student* temp = (Student*)malloc(sizeof(Student));
    InitStudent(temp);
    return temp;
}
// 🥝 해시테이블에 새로 추가 🥝
void InsertHashTable(){
    Student* temp = CreateStudent(); // 약식 진행이므로 입력 x
    int index = Hash(temp->id); // 특정 ID를 해시 인덱스로 변환
    temp->next - hashTable[index];
    hashTable[index] = temp;
}

// 🫐 모든 요소들을 출력하기 🫐
// 연결 리스트 형태이므로, *move의 데이터 공간에 NULL이면 끝나게 할 것
void PrintStudentHashTable(){
    printf("==================\n");
    for(int i=0;i<SIZE;i++){
        Student* move = hashTable[i];
        if(move==NULL) continue;
        // 안에 몇번 출력해야 하는지 모름. 무한반복으로 처리
        printf(" <<< [ Index : %d ] >>>\n",i);
        for(;1;){
            // move는 현재 비어있지 않으니까, 출력 먼저 하기
            printf("[ID]:%d, [GENDER]:%c, [SCORE:%d\n]",move->id,move->gender,move->score);
            // 끝나고, move를 옮긴 후, NULL이라면 break;
            move = move->next;
            if(move==NULL) break;
        }
    }
    printf("==================\n");
}
// 🍎 특정 학생 검색하기 ID필요🍎
Student* FindStudent(int targetID){
    int index = Hash(targetID);
    Student* move = hashTable[index]; // NULL일 수도 있고, 구조체 집주소일수도 있음
    // targetID와 일치하는 move->ID를 찾아야 함. move가 NULL이면 없음.
    for(;1;){
        if(move==NULL){
            printf("Target[%d] Not Found\n", targetID);
            return NULL;
        }

        if(move->id == targetID){
            // 찾았음!!
            printf("<<Target Information >>\n");
            PrintStudent(move);
            return move;
        }

        move = move->next;
    }
}

// 🥵 특정 targetID의 학생정보를 삭제하기🥵
void Delete(int targetID){
    int index = Hash(targetID);

    Student* cur = hashTable[index];
    Student* prev = NULL; // 처음에 왜 널? 첫 값을 표현하기 위함.
    // -------------------------------------------------
    for(;1;){
        if(cur==NULL){
            printf("Target[%d] Not Found\n", targetID);
            return;
        }
        // 비어있진 않으니까... 비교먼저 진행
        if(cur->id == targetID){
            if(prev == NULL){
                // 첫 구조체가 타겟인 경우
                hashTable[index] = cur->next; // NULL일 수도 있고 아닐 수도...
            }else{
                // 타켓이 첫번째가 아닌 경우
                prev->next = cur->next; // 다음 위치로 변경
            }
            printf("Target Found!! Delete..\n");
            free(cur);
            return;
        }
        // 비교했는데 안맞으면, 다음으로 이동
        prev = cur;
        cur = cur->next;
    }
}
// 🥭 수정하기 🥭
void UpdateStudent(int targetID){   
    int score = 999;
    char gender = 'K';
    // -----------------------------
    Student* temp = FindStudent(targetID);
    if(temp==NULL) return;

    temp->score=score;
    temp->gender = gender;

    printf(" << Update Complete >>\n");
    PrintStudent(temp);
}
// 😍 전체 메모리 해제 😍
// ===============================================================
int main(){
    for(int i=0;i<15;i++){
        InsertHashTable();
    }
    PrintStudentHashTable();
    FindStudent(20260086);
    FindStudent(20269999);
   
    for(int i=0;i<50;i++){
        Delete(i+20260001); // 1~50 학생 삭제
    }
    PrintStudentHashTable();
    Delete(99999999);
    PrintStudentHashTable();

    // 100번, 99번 적용
    UpdateStudent(20260100);
    UpdateStudent(20260099);
    PrintStudentHashTable();
   
    
} // ===============================================================

