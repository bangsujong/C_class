#include <stdio.h>
#include <stdlib.h> // exit 함수 사용을 위해 추가
#define MAX_TERMS 100

struct term 
{
    float coef;
    int expon;
};

struct term terms[MAX_TERMS] = {{7.0, 6}, {5.0, 3}, {9.0, 2}, {1.0, 0}, {5.0, 3}, {2.0, 2}, {1.0, 1},{10.0,0}};
int avail = 8;

// 다항식을 출력하는 함수
void print_poly(int s, int e) 
{
    for (int i = s; i < e; i++) 
    {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

// 항을 terms 배열에 추가하는 함수
void attach(float coef, int expon) 
{
    if (avail >= MAX_TERMS) 
    {
        fprintf(stderr, "항의 수가 너무 많습니다.\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}


// 두 다항식을 곱하는 함수
void poly_multiply(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) 
{
    *Cs = avail; // 결과 다항식의 시작 인덱스 설정

    for (int i = As; i <= Ae; i++) 
    {
        for (int j = Bs; j <= Be; j++) 
        {
            float tempcoef = terms[i].coef * terms[j].coef;
            int tempexpon = terms[i].expon + terms[j].expon;
            
            // 결과 다항식에 추가하는 항이 이미 있는지 확인
            int found = 0;
            for (int k = *Cs; k < avail; k++) 
            {
                if (terms[k].expon == tempexpon)
                {
                    terms[k].coef += tempcoef;
                    found = 1;
                    break;
                }
            }

            // 결과 다항식에 추가하는 항이 없으면 새로 추가
            if (!found) {
                attach(tempcoef, tempexpon);
            }
        }
    }

    *Ce = avail - 1; // 결과 다항식의 끝 인덱스 설정
}



// 두 다항식을 더하는 함수
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) 
{
    float tempcoef;
    *Cs = avail; // 결과 다항식의 시작 인덱스 설정

    while (As <= Ae && Bs <= Be) 
    {
        if (terms[As].expon > terms[Bs].expon) 
        {
            attach(terms[As].coef, terms[As].expon);
            As++;
        } else if (terms[As].expon == terms[Bs].expon) 
        {
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef) // 계수의 합이 0이 아니면 결과에 추가
                attach(tempcoef, terms[As].expon);
            As++;
            Bs++;
        } else 
        {
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
        }
    }

    // 남은 항들을 결과에 추가
    for (; As <= Ae; As++) attach(terms[As].coef, terms[As].expon);
    for (; Bs <= Be; Bs++) attach(terms[Bs].coef, terms[Bs].expon);

    *Ce = avail - 1; // 결과 다항식의 끝 인덱스 설정
}

// int main() {
//     int Cs, Ce;
//     printf("A = ");
//     print_poly(0, 2);
//     printf("B = ");
//     print_poly(3, 5);

//     poly_add2(0, 2, 3, 5, &Cs, &Ce);
//     printf("—————————\n");
//     printf("Result = ");
//     print_poly(Cs, Ce);

//     return 0;
// }

int main() 
{
    int Cs, Ce;
    printf("A = ");
    print_poly(0, 3);
    printf("B = ");
    print_poly(4, 7);

    poly_multiply(0, 3, 4, 7, &Cs, &Ce);
    printf("—————————\n");
    printf("Result = ");
    print_poly(Cs, Ce);

    return 0;
}
