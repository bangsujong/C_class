#include <stdio.h>
#include <stdlib.h>

// 다항식을 나타내는 구조체 정의
typedef struct {
    double coef; // 계수
    int exp;     // 지수
} Polynomial;

// 다항식을 곱하는 함수
Polynomial* multiplyPolynomials(Polynomial* poly1, int size1, Polynomial* poly2, int size2, int* resultSize) {
    // 곱한 다항식을 저장할 동적 할당 배열 생성
    *resultSize = size1 * size2;
    Polynomial* result = (Polynomial*)malloc(*resultSize * sizeof(Polynomial));

    int k = 0; // 결과 다항식의 인덱스
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            // 다항식 곱셈 수행
            result[k].coef = poly1[i].coef * poly2[j].coef;
            result[k].exp = poly1[i].exp + poly2[j].exp;
            k++;
        }
    }

    // 지수가 같은 항의 계수를 더함
    for (int i = 0; i < *resultSize - 1; i++) {
        for (int j = i + 1; j < *resultSize; j++) {
            if (result[i].exp == result[j].exp) {
                result[i].coef += result[j].coef;
                // 항을 합친 후, 뒤의 항을 삭제하고 배열을 압축
                for (int l = j; l < *resultSize - 1; l++) {
                    result[l] = result[l + 1];
                }
                (*resultSize)--;
                result = (Polynomial*)realloc(result, *resultSize * sizeof(Polynomial));
                j--; // 한 번 더 검사하기 위해 j를 하나 줄임
            }
        }
    }

    return result;
}

// 다항식 출력 함수
void printPolynomial(Polynomial* poly, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.1fx^%d ", poly[i].coef, poly[i].exp);
        if (i != size - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("다항식 1의 총 항의 수를 입력하시오: ");
    scanf("%d", &size1);

    Polynomial* poly1 = (Polynomial*)malloc(size1 * sizeof(Polynomial));

    printf("고차항부터 차례로 계수와 지수를 입력하시오:\n");
    for (int i = 0; i < size1; i++) {
        printf("[계수, 차수] ");
        scanf("%lf %d", &poly1[i].coef, &poly1[i].exp);
    }

    printf("다항식 2의 총 항의 수를 입력하시오: ");
    scanf("%d", &size2);

    Polynomial* poly2 = (Polynomial*)malloc(size2 * sizeof(Polynomial));

    printf("고차항부터 차례로 계수와 지수를 입력하시오:\n");
    for (int i = 0; i < size2; i++) {
        printf("[계수, 차수] ");
        scanf("%lf %d", &poly2[i].coef, &poly2[i].exp);
    }

    // 다항식 곱셈 수행
    int resultSize;
    Polynomial* result = multiplyPolynomials(poly1, size1, poly2, size2, &resultSize);

    printf("입력된 다항식 1은 다음과 같습니다: ");
    printPolynomial(poly1, size1);
    printf("입력된 다항식 2은 다음과 같습니다: ");
    printPolynomial(poly2, size2);
    printf("곱한 다항식은 다음과 같습니다: ");
    printPolynomial(result, resultSize);

    // 동적 할당 메모리 해제
    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
