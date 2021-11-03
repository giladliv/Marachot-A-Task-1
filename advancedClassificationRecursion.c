#include "NumClass.h"
#include <math.h>


/**
 * @brief the function is a recursive function that check if the number can be read forward and backwards
 * and have the same value
 * 
 * @param numOr the original number (won't change)
 * @param num the number that allways will be 10 times smaller
 * @param rev the nuber reversed
 * @return boolean - true / false 
 */
int paliCheck(int numOr, int num, int rev)
{
    // if the number is zero, there is no more devision by 10, then check if the revesre num is the same as the original
    if (num == 0)
    {
        return ((numOr == rev) ? TRUE : FALSE);
    }

    // recursive call - the number will be cut by the last digit and the reversed will gain new digit
    return paliCheck(numOr, num / 10, (rev*10) + num%10);
}

int isPalindrome(int num)
{
    return paliCheck(num, num, 0);  // apply the recursive function
}

/**
 * @brief returns the number of digits of given number
 * 
 * @param num the number to check his length
 * @return len of digits
 */
int lenOfNum(int num)
{
    int len = 0;
    // run untill the number has no digits (0 has 0 digits for us)
    while (num > 0)
    {
        len += 1;
        num /= 10;
    }
    return (len);
}

/**
 * @brief the nuber checks if nuber is an armstrong number recursively
 * 
 * @param num the number we want to check if armstrong
 * @param len the length of the original num
 * @param left shows the current state of nuber after subing the powerd digit
 * @return int 
 */
int checkArm(int num, int len, int left)
{
    if (num == 0)
    {
        return ((left == 0) ? TRUE : FALSE);
    }
    else if (left == 0) // if the number is not 0 (the end) and the left is zero - no possible option
    {
        return (FALSE);
    }

    //recursive call - remove the last digit from num, and sub left from the power of the digit
    return checkArm(num / 10, len, (left - pow(num%10, len)));
}

int isArmstrong(int num)
{
    return checkArm(num, lenOfNum(num), num);   // apply the rec call
}