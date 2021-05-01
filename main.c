/* 
* to do:
* grootte uitlezen 
* 
* 
* 
* 
* 
* 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printbinchar(char);

int main()
{
    printbinchar(' ');
    return 0;
}
void printbinchar(char character)
{
    char test[9] = "";
    char output[9];
    _itoa(character, output, 2);
    printf("%s\n", output);

    int i = 0;
    while (output[i] != '\0') i++;
    printf("%d\n", i);


    if(i < 8) {
        for (int j = 0; j < (8 - i); j++)
        {
            test[j] = '0';
        }
    }
    strcat(test, output);
    printf("%s\n", test);
}

