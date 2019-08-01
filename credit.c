// Credit card verification
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Gets the first two numbers of card number
    long int cardnumber = get_long("Number: ");
    
    // Counts the digits
    int count = 0;
    long int n = cardnumber;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    long int number[count];
    
    if ((count != 13) && (count != 15) && (count != 16))
    {
        printf("INVALID\n");
    }  
    
    for (int i = 0; i < count; i++)
    {
        number[i] = cardnumber % 10;
        cardnumber = cardnumber / 10;
    }
    
    int originalnumber[count];
    for (int i = 1; i < count; i++)
    {
        originalnumber[i] = number[i];
    }
    
    for (int i = 1; i < count; i += 2)
    {
        number[i] = number[i] * 2;
    }
    
    int v = 0;
    int temp;

    if (count == 13)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalnumber[12] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    if (count == 15)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalnumber[14] == 3 && v % 10 == 0 && (originalnumber[13] == 4 || originalnumber[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    // Check for invalid no. of digits
    if (count == 16)
    {
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (originalnumber[15] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else if (originalnumber[15] == 5 && v % 10 == 0 && (originalnumber[14] == 1 || originalnumber[14] == 2 || originalnumber[14] == 3 
                 || originalnumber[14] == 4 || originalnumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }    
}
