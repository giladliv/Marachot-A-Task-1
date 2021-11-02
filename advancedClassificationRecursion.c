#include "NumClass.h"
#include <math.h>


int paliCheck(int numOr, int num, int rev)
{
    if (num == 0)
    {
        return ((numOr == rev) ? TRUE : FALSE);
    }

    return paliCheck(numOr, num / 10, (rev*10) + num%10);
}

int isPalindrome(int num)
{
    return paliCheck(num, num, 0);
}

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

int checkArm(int num, int len, int left)
{
    if (num == 0)
    {
        return ((left == 0) ? TRUE : FALSE);
    }
    else if (left == 0)
    {
        return (FALSE);
    }

    return checkArm(num / 10, len, (left - pow(num%10, len)));
}

int isArmstrong(int num)
{
    return checkArm(num, lenOfNum(num), num);
}