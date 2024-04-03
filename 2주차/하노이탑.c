#include <stdio.h>

// 원판 이동 함수
void moveDisk(char source, char target) {
    printf("Move disk from %c to %c\n", source, target);
}

// 하노이 탑 알고리즘 (반복적 방법)
void hanoiIterative(int numDisks, char source, char auxiliary, char target) {
    // 원판 이동 방향 결정
    char temp;
    if (numDisks % 2 == 0) {
        temp = auxiliary;
        auxiliary = target;
        target = temp;
    }

    // 총 이동 횟수 계산
    int totalMoves = (1 << numDisks) - 1; // 2^numDisks - 1

    // 각 이동을 반복적으로 수행
    for (int move = 1; move <= totalMoves; move++) {
        if (move % 3 == 1) {
            moveDisk(source, target);
        } else if (move % 3 == 2) {
            moveDisk(source, auxiliary);
        } else if (move % 3 == 0) {
            moveDisk(auxiliary, target);
        }
    }
}

int main() {
    int numDisks = 3;
    char source = 'A';
    char auxiliary = 'B';
    char target = 'C';

    // 하노이 탑 문제 해결
    hanoiIterative(numDisks, source, auxiliary, target);

    return 0;
}
