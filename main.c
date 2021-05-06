/* 
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
* +++cmd argumenten kunnen uitlezen
* +++txt bestand uitlezen
* ---tekst omvormen naar binair
* ---grootte van bmp bestand uitlezen
* ---tekst in bmp bestand verwerken
* ---bmp bestand uitlezen
* ---binair omzetten naar tekst
* 
* ---fout geven bij te weinig of foutive cmd argumenten
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BESTAND "./test.txt"

void printbinchar(char);

int main(int argc, char* argv[]) {
	if(argc == 2 && strcmp(argv[1], "--help")==0)
    {
		printf("-c --> compress\n");
		printf("-s --> de input text file containing the secret message\n");
		printf("-i --> de input bmp file\n");
		printf("-o --> output image name\n");
		printf("EINDE HELP\n");
	}

	if(argc == 8)
    {
		//-c -s inputfile.txt -i meme.bmp -o memeOut.bmp
		printf("test\n");
		printf("%s\n", argv[3]);
		printf("%s\n", argv[5]);
		printf("%s\n", argv[7]);
	}



    FILE * fp = NULL; 

    fp = fopen(BESTAND, "r");
    if (fp == NULL)
    {
        printf("Can't open file\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int c;
        while ((c = getc(fp)) != '#' && c != EOF)putchar(c);
        printf("The contents of desname string  : %s", c);
    }
    

    fclose(fp);
    return 0;







    /*
    if (argc == 2) {
        printf("The argument supplied is %s\n", argv[1]);
    }
    else if (argc > 2) {
        printf("Too many arguments supplied.\n");
    }
    else {
        printf("One argument expected.\n");
    }
    */

    printbinchar('t');
    return 0;
}

void printbinchar(char character)
{
    char binLetter_8[9] = "";
    char binLetter[9];
    _itoa(character, binLetter, 2); //character omzetten naar 2(binair) in binLetter
    printf("Binaire waarde van letter: %s\n", binLetter); //printen binaire waarde van letter meegegeven aan printbinchar();

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

tutorialspoint.com / cprogramming / c_bit_fields.html

*/