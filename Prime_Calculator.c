#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
//Note: This implementation uses Willans' formula to calculate the nth prime number but only upto n = 7 due to the factorial growth in the calculations, which is way to big for simple integer types.
double factorial(int n)
{
    double f = 1.0;
    for(int i = 2; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int prime_detector(int j)
{
    double val = cos(M_PI * (factorial(j-1) + 1) / j);
    val = val * val;      // cos^2
    return (int)floor(val);
}

int willans_prime(int n)
{
    int sum_outer = 0;
    int limit = pow(2, n);
    for(int k = 1; k <= limit; k++)
    {
        int prime_count = 0;
        for(int j = 1; j <= k; j++)
        {
            prime_count += prime_detector(j);
        }
        if(prime_count == 0)
            continue;
        double term = pow((double)n / prime_count, 1.0/n);
        sum_outer += (int)floor(term);
    }
    return 1 + sum_outer;
}

int main()
{
    int nth_prime_number;
    printf("Welcome to the Prime Number Calculator!\n");
    printf("Enter the desired value of n to find the nth prime number: ");
    scanf("%d", &nth_prime_number);
    int prime_number = willans_prime(nth_prime_number);
    printf("Prime Number at Position %d is: %d\n", nth_prime_number, prime_number);
    return 0;
}