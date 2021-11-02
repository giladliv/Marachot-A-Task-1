#include "NumClass.h"
#include <math.h>

int isPrime(int num)
{
    int max = 0;
    if (num < 1)
    {
        return (FALSE);
    }
    
    max = sqrt(num);
    for (int i = 2; i <= max; i++)
    {
        if (num % i == 0)
        {
            return (FALSE);
        }
    }
    return (TRUE);
}

int isStrong(int num)
{
    int temp = num;
    int sum = 0;
    int fact = 1;
    if (num == 0)
    {
        return (FALSE);
    }

    while (temp > 0)
    {
        fact = 1;
        for (int i = 1; i <= (temp % 10); i++)
        {
            fact *= i;
        }
        sum += fact;
        temp /= 10;
    }
    
    return ((sum == num) ? TRUE : FALSE);
}