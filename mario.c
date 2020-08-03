// Mario (Less Comfortable)

#include <cs50.h>
#include <stdio.h>

int main(void) {
    int input = get_int("Height: ");

    while (input < 1 || input > 8) {
        input = get_int("Height: ");
    }

    if ((input > 0 || input < 9)) {
        for (int i = 1; i < input+1; ++i) {
             int val1 = input - i;
             int val2 = input - val1;

             for (int j = 0; j < val1; ++j) {
                 printf(" ");
             }
             for (int j = 0; j < val2; ++j) {
                 printf("#");
             }
             printf("\n");
        }
    }
}
