#include "NumClass.h"
#include <math.h>

/**
 * @brief returns the number of digits of given number
 * 
 * @param num the number to check his length
 * @return len of digits
 */
int lenOfNum(int num)
{
    int len = 0;
    
    while (num > 0)
    {
        len += 1;
        num /= 10;
    }
    return (len);
}

int isArmstrong(int num)
{
    int len = lenOfNum(num);
    int left = num;

    while (num > 0 && left > 0)
    {
        left -= pow(num%10, len);
        num /= 10;
    }

    if (num == 0)
    {
        return ((left == 0) ? TRUE : FALSE);
    }
    
    return FALSE;
}


int isPalindrome(int num)
{
    int temp = num;
    int check = 0;
    
    while (temp > 0)
    {
        check = check * 10 + temp % 10;
        temp /= 10;
    }

    return ((num == check) ? TRUE : FALSE);
}