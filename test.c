/* 
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
* +++cmd argumenten kunnen uitlezen
* +++txt bestand uitlezen 
* +++array grootte bepalen door bestand
* ---tekst omvormen naar binair
* +++grootte van bmp bestand uitlezen
* ---letter in bmp bestand verwerken
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
#define BMPINPUTFILE "test 1.bmp"

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

	//werken wet de bmp file----------------------------------------------------------------------

	//teste of bmp file opent 
	FILE* inputFilePointer = fopen(BMPINPUTFILE, "rb"); //maak een file pointer naar de afbeelding
	if (inputFilePointer == NULL) //Test of het open van de file gelukt is!
	{
		printf("BMP file kan niet worden geopend %s\n", BMPINPUTFILE);
		exit(EXIT_FAILURE);
	}

	unsigned char bmpHeader[54]; // voorzie een array van 54-bytes voor de BMP Header
	fread(bmpHeader, sizeof(unsigned char), 54, inputFilePointer); // lees de 54-byte header

	//Informatie uit de header (wikipedia)
	//Haal de hoogte en breedte uit de header
	int breedte = *(int*)& bmpHeader[18];
	int hoogte = *(int*)& bmpHeader[22];

	printf("DEBUG info: breedte = %d\n", breedte);
	printf("DEBUG info: hoogte = %d\n", hoogte);



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
		printf("\n%s\n\n", inputtekst);
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
		printf("Kan bestand niet openen\n");
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
    printf("Letter is: %c \n\n", c);
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