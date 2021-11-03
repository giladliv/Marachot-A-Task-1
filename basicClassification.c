#include "NumClass.h"
#include <math.h>

int isPrime(int num)
{
    int max = 0;
    if (num < 1)  // if the num is 0 or less - not prime (1 is prime for our task)
    {
        return (FALSE);
    }
    
    max = sqrt(num);
    // if num is devided without mod by the numbers between [2,sqrt(num)] - the number is not prime  
    for (int i = 2; i <= max; i++)
    {
        if (num % i == 0)
        {
            return (FALSE);
        }
    }
    // the number has passed the test - he is prime
    return (TRUE);
}

int isStrong(int num)
{
    int temp = num;
    int sum = 0;
    int fact = 1;
    if (num == 0)   // 0 is not strong 0 not equals to 0! (=1)
    {
        return (FALSE);
    }

    // until there are no digits in number - continue to cut
    while (temp > 0)
    {
        fact = 1;
        for (int i = 1; i <= (temp % 10); i++)  // get factorial by mul all the numbers 1*2*...*n
        {
            fact *= i;
        }
        sum += fact;    // add the result of factorial to the sum and then remove digit
        temp /= 10;
    }
    
    return ((sum == num) ? TRUE : FALSE);   // if the sum equals to the num - by defenition is strong number
}