#include <stdio.h>
#include "NumClass.h"

int main()
{
    int num1=0, num2=0, temp=0;
    int isGood = FALSE;
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

    for (int i = 0; i < 4; i++)
    {
        isGood = FALSE;
        for (int curr = num1; curr <= num2; curr++)
        {
            switch (i)
            {
                case 0:
                    isGood = isPrime(curr);
                    break;

                case 1:
                    isGood = isArmstrong(curr);
                    break;

                case 2:
                    isGood = isStrong(curr);
                    break;

                case 3:
                    isGood = isPalindrome(curr);
                    break;
                
                default:
                    isGood = FALSE;
                    break;
            }
            if (isGood == TRUE)
            {
                printf("%d ", curr);
            }
        }
        printf("\n");        
    }

    return (0);
}