#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    
    int cent;
    
    do
    {
        float owed_cash = get_float("Enter: ");
        cent = round(owed_cash * 100);
    }
    while(cent <= 0);
    
    int quarters = cent / 25;
    int dimes = (cent % 25) / 10;
    int nickels = ((cent % 25) % 10) / 5;
    int pennies = ((cent % 25) % 10) % 5;

    
    printf("%d\n", quarters + dimes + nickels + pennies);
}


