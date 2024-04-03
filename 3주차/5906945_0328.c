# include <stdio.h>
# define MAX_DEGREE 101
struct polynomial
{
    int degree;
    float coef[MAX_DEGREE];
};

void print_polynomial();

struct polynomial add_polynomial_poly(struct polynomial A, struct polynomial B)
{
    struct polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree, degree_b = B.degree;

    C.degree = (A.degree > B.degree) ? A.degree : B.degree;
    
    while (Apos <= A.degree && Bpos <= B.degree)
    {
        if (degree_a > degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++];
            // Cpos = Cpos +1;
            // Apos = Apos + 1;
            degree_a--;
        }
        else if (degree_a == degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else
        {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}



int main()
{
    struct polynomial a = {5, {3.0, 6.0, 0.0, 0.0, 0.0, 10.0}};
    struct polynomial b = {4, {7.0, 0.0, 5.0, 0.0, 1.0}};
    struct polynomial X;
    printf("A : ");
    print_polynomial(a);
    printf("B : " );
    print_polynomial(b);

    X = add_polynomial_poly(a,b);
    printf("-----------------------------------------------------------\n");
    printf("Add A and B : ");
    print_polynomial(X);



    return 0;
}

void print_polynomial(struct polynomial p)
{
    for(int i = p.degree; i >= 1; i--)
    {
        printf("%3.1fx^%d +", p.coef[p.degree-i],i);
    }
    printf("%3.1f\n\n", p.coef[p.degree]);
}

