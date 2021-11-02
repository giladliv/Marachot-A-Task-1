#include <stdio.h>
#include "NumClass.h"

int main()
{
    int num1=0, num2=0, temp=0;
    printf("Please Enter here your first number: ");
    scanf("%d", &num1);
    printf("Please Enter here your second number: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("The Armstrong numbers are:");
    for (int curr = num1; curr <= num2; curr++)
    {
        if (isArmstrong(curr) == TRUE)
        {
            printf(" %d", curr);
        }
    }

    printf("\nThe Palindromes are:");
    for (int curr = num1; curr <= num2; curr++)
    {
        if (isPalindrome(curr) == TRUE)
        {
            printf(" %d", curr);
        }
    }

    printf("\nThe Prime numbers are:");
    for (int curr = num1; curr <= num2; curr++)
    {
        if (isPrime(curr) == TRUE)
        {
            printf(" %d", curr);
        }
    }

    printf("\nThe Strong numbers are:");
    for (int curr = num1; curr <= num2; curr++)
    {
        if (isStrong(curr) == TRUE)
        {
            printf(" %d", curr);
        }
    }

    

    return (0);
}