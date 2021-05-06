/* 
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
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
    printbinchar('t');
    return 0;
}

void printbinchar(char character)
{
    char binLetter_8[9] = "";
    char binLetter[9];
    _itoa(character, binLetter, 2); //character omzetten naar 2(binair) in binLetter
    printf("%s\n", binLetter); //printen binaire waarde van letter meegegeven aan printbinchar();

    int aantalBits = 0;
    while (binLetter[aantalBits] != '\0') aantalBits++;
    printf("Aantal bits: %d\n", aantalBits);

    //omzetten naar 8 bits binair
    if(aantalBits < 8) {
        for (int j = 0; j < (8 - aantalBits); j++)
        {
            binLetter_8[j] = '0';
        }
    }
    strcat(binLetter_8, binLetter);
    printf("Omgezet in 8 bits binair: %s\n", binLetter_8);
}















/*
typedef struct _iobuf

{

    char* _ptr;

    int _cnt;

    char* _base;

    int _flag;

    int _file;

    int _charbuf;

    int _bufsiz;

    char* _tmpfname;

} FILE;

unix.com/programming/150687-file-structure-stdio-h.html

tutorialspoint.com / cprogramming / c_bit_fields.htm

*/