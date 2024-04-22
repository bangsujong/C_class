#include <stdio.h>
#define MAX (a,b) ((a)>(b)?(a):(b))
#define MAX_DEGREE 101
struct student
{
    int age;
    char name[30];
}s1;

int main()
{
    struct student s1 = {21,"홍길동"};

    //s1.name = "학생이름";

    printf("나이는 %d이고 이름은 \"%s\"입니다.\n", s1.age, s1.name);


}


