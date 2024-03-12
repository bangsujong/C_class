# include <stdio.h>

// 소수 판별 함수
int is_prime(int n) {
    if (n <= 1)
        return 0; // 소수 아님
    if (n == 2)
        return 1; // 소수
    if (n % 2 == 0)
        return 0; // 짝수는 소수 아님

    // 홀수인 경우 소수 여부 확인
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0; // 소수 아님
    }
    return 1; // 소수
}

int main() {
    int sum = 0;

    // 0부터 100까지의 소수를 찾아 더함
    for (int num = 0; num <= 100; num++) {
        if (is_prime(num))
            sum += num;
    }

    printf("0부터 100까지의 소수의 합은: %d\n", sum);

    return 0;
}
