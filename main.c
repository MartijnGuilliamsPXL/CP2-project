/* 
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
* +++cmd argumenten kunnen uitlezen
* +++txt bestand uitlezen +++array grootte bepalen door bestand
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

void inlezenTXT();
int grootteTXT();
void printbinchar(char);
void binair_char();


char binLetter_8[9] = "";


int main(int argc, char* argv[]) {
	if(argc == 2 && strcmp(argv[1], "--help")==0)
    {
		printf("-c --> compress\n");
		printf("-s --> het input tekstbestand met de secret message\n");
		printf("-i --> de input bmp file\n");
		printf("-o --> output image name\n");
		printf("\n");
		printf("-d --> decompress\n");
		printf("-i --> input bmp die de secret message bevat\n");
		printf("-o --> output text file waar het gedecodeerde bericht in komt\n");
		printf("\n");
		printf("EINDE HELP\n\n\n");
	}

	if(argc == 8)
    {
		//-c -s inputfile.txt -i meme.bmp -o memeOut.bmp
		printf("compress\n");
		printf("%s\n", argv[3]);
		printf("%s\n", argv[5]);
		printf("%s\n", argv[7]);
	}


	inlezenTXT();
    printbinchar('t');
	binair_char();
    return 0;
}


void inlezenTXT()
{
	char* inputtekst = (char*)malloc(grootteTXT());
	FILE* fp = NULL;
	fp = fopen(BESTAND, "r");
	if (fp == NULL)
	{
		printf("Can't open file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fgets(inputtekst, 20, fp) != NULL)
		printf("\n\n\n%s\n\n\n", inputtekst);
	}
	fclose(fp);
	free(inputtekst);
}

int grootteTXT()
{
	FILE* fp = NULL;
	fp = fopen(BESTAND, "r");
	if (fp == NULL)
	{
		printf("Can't open file\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0, SEEK_END);
	int grootte = ftell(fp);
	fclose(fp);
	printf("Size is: %d\n", grootte);
	return grootte;
}


void printbinchar(char character)
{
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

void binair_char()
{
    char c = strtol(binLetter_8, 0, 2);
    printf("Letter is: %c \n", c);
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