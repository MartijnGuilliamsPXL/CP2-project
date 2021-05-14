/* 
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
* +++cmd argumenten kunnen uitlezen
* +++txt bestand uitlezen 
* +++array grootte bepalen door bestand
* +++tekst omvormen naar binair
* +++grootte van bmp bestand uitlezen
* ---letter in bmp bestand verwerken 
* ---tekst in bmp bestand verwerken 
* ---bmp bestand uitlezen (hard gecodeerd (letter))
* +++binair omzetten naar letter
* +++binair omzetten naar tekst
* 
* +++fout geven bij te weinig of foutive cmd argumenten
*/


//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bestanden toekennen
#define InputTXT "./test.txt"
#define BMPINPUTFILE "./CP2_Encoded.bmp"
#define OutputTXT "./schrijf.txt"

//alle functies
void schrijvenBMP();
void inlezenBMP();
void schrijvenTXT();
void inlezenTXT();
int grootteTXT();
int char_binair(char, int);
char binair_char();

//char arrays
char binChar[8];

int main(int argc, char* argv[]) {
	//if (argc == 2 && strcmp(argv[1], "--help") == 0) //--help
	//{
	//	printf("--help -c -->  help voor compress\n");
	//	printf("--help -d --> help voor decompress\n");
	//	exit(EXIT_FAILURE);
	//}
	//else if (argc == 3 && strcmp(argv[1], "--help") == 0)
	//{
	//	if (argc == 3 && strcmp(argv[2], "-c") == 0) //--help -c
	//	{
	//		printf("-c --> compress\n");
	//		printf("-s --> het input tekstbestand met de secret message\n");
	//		printf("-i --> de input bmp file\n");
	//		printf("-o --> output image name\n");
	//		printf("EINDE HELP\n\n\n");
	//	}
	//	else if (argc == 3 && strcmp(argv[2], "-d") == 0) //--help -d
	//	{
	//		printf("-d --> decompress\n");
	//		printf("-i --> input bmp die de secret message bevat\n");
	//		printf("-o --> output text file waar het gedecodeerde bericht in komt\n");
	//		printf("EINDE HELP\n\n\n");
	//	}
	//	else
	//	{
	//		printf("Fout!!! \nNiet de juiste argumenten \nKijk in --help voor de uitleg \n");
	//	}
	//	exit(EXIT_FAILURE);
	//}
	//else if (argc == 8 && strcmp(argv[1], "-c") == 0) 
	//{
	//	//(naam bestand) -c -s inputfile.txt -i meme.bmp -o memeOut.bmp
	//	if (argc == 8 && strcmp(argv[2], "-s") == 0) 
	//	{
	//		printf("%s\n", argv[3]); //inputfile.txt
	//		//functie aanroepen
	//	}
	//	if (argc == 8 && strcmp(argv[4], "-i") == 0) 
	//	{
	//		printf("%s\n", argv[5]); //meme.bmp
	//		//functie aanroepen
	//	}
	//	if (argc == 8 && strcmp(argv[6], "-o") == 0) 
	//	{
	//		printf("%s\n", argv[7]); //memeOut.bmp
	//		//functie aanroepen
	//	}
	//		
	//} 
	//else if (argc == 6 && strcmp(argv[1], "-d") == 0)
	//{
	//	//(naam bestand) -d -i meme.bmp -o bericht.txt

	//	if (argc == 6 && strcmp(argv[2], "-i") == 0)
	//	{
	//		printf("%s\n", argv[3]); //meme.bmp
	//		//functie aanroepen
	//	}
	//	if (argc == 6 && strcmp(argv[4], "-o") == 0)
	//	{
	//		printf("%s\n", argv[5]); //bericht.txt
	//		//functie aanroepen
	//	}
	//}
	//else
	//{
	//	printf("Fout!!! \nNiet de juiste argumenten \nKijk in --help voor de uitleg \n");
	//	exit(EXIT_FAILURE);
	//}



	
	inlezenTXT();
    
	//char_binair('t');
	
	binair_char();
	
	inlezenBMP();

	schrijvenBMP();

    return 0;
}

void schrijvenBMP()
{
	/*
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
	int breedte = *(int*)&bmpHeader[18];
	int hoogte = *(int*)&bmpHeader[22];

	printf("DEBUG info: breedte = %d\n", breedte);
	printf("DEBUG info: hoogte = %d\n", hoogte);

	//lezen van de pixels
	int imageSize = 3 * breedte * hoogte; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
	unsigned char* inputPixels = (unsigned char*)calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels

	fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file)


	fseek(inputFilePointer, 54, SEEK_SET);
	FILE* fp = NULL;
	fp = fopen("test.txt", "rb");
	while (!feof(inputFilePointer))
	{
		char c = fgetc(fp);
		for (int i = 0; i < 8; i++)
		{
			int bit = fgetc(inputFilePointer);
			//printf("bit= %d", bit);
			int lastBit = char_binair(c, i);
			//printf("%d", lastBit);
			int singleBitPixel = bit & 1;
			printf("  %d", bit);

			if (singleBitPixel != lastBit && singleBitPixel < lastBit)
			{
				fputc(bit++, fp);
			}
			else if (singleBitPixel != lastBit && singleBitPixel > lastBit)
			{
				fputc(bit--, fp);
			}
		}
	}
	//fputc



	fclose(inputFilePointer);
	*/
}


void inlezenBMP()
{
	
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

	//lezen van de pixels
	int imageSize = 3 * breedte * hoogte; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
	unsigned char* inputPixels = (unsigned char*)calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels

	fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file)
	
	
	fseek(inputFilePointer, 54, SEEK_SET);
	FILE* fp = NULL;
	fp = fopen(OutputTXT, "wb");
	char laatsteChar = ' ';
	while ((!feof(inputFilePointer)) && laatsteChar != '*')
	{
		char c = fgetc(fp);
		for (int i = 0; i < 8; i++)
		{
			int bit = fgetc(inputFilePointer);
			int singleBitPixel = bit & 1;
			binChar[i] = singleBitPixel + '0';
		}
		laatsteChar = binair_char();
		fputc(laatsteChar, fp);
	}
	fclose(inputFilePointer);
	fclose(fp);
}

void schrijvenTXT()
{
	//fputc
}

void inlezenTXT()
{
	char* inputtekst = (char*)malloc(grootteTXT());
	FILE* fp = NULL;
	fp = fopen(InputTXT, "r");
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
	fp = fopen(InputTXT, "r");
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


int char_binair(char character, int i)
{
	return((character >> (i)) & 1);
}


char binair_char()
{
	char c = strtol(binChar, 0, 2);
	return c;
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