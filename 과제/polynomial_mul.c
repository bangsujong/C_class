# include <stdio.h>
# define MAX_DEGREE 100

struct polynomial
{
    int degree;
    float coef[MAX_DEGREE];
};

// 다항식 곱셈 함수
struct polynomial mul_polynomial(struct polynomial a, struct polynomial b)
{
    struct polynomial result;
    int resultDegree = a.degree + b.degree;
    int i,j;

    result.degree = resultDegree;
    for (i = 0; i < resultDegree; i++)
    {
        result.coef[i] = 0.0;
    }
    
    for (i = 0; i <= a.degree; i++)
    {
        for(j = 0; j <= b.degree; j++)
        {
            result.coef[i+j] += a.coef[i] * b.coef[j];
        }
    }
    return result;
}

void print_poly(struct polynomial p)
{
    for (int i = p.degree; i>0; i--)
    {
        printf("%3.1fx^%d + ", p.coef[p.degree - i],i);
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

int main()
{
    struct polynomial a ={6, {7, 0, 0, 5, 9, 0, 1}};
    struct polynomial b ={3, {5, 2, 1, 10}};
    struct polynomial result = mul_polynomial(a, b);
    print_poly(a);
    print_poly(b);

    mul_polynomial(a,b);
    printf("-----------------------------------------------------------------\n");
    print_poly(result);


return 0;

}