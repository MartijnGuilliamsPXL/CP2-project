/*
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
* +++cmd argumenten kunnen uitlezen
* +++txt bestand uitlezen
* +++array grootte bepalen door bestand
* +++tekst omvormen naar binair
* +++grootte van bmp bestand uitlezen
* +++fout geven bij te weinig of foutive cmd argumenten
* +++bmp bestand uitlezen
* +++binair omzetten naar letter
* +++binair omzetten naar tekst
* ---nuttige commentaar
* +++benamingen verbeteren
* +++letter in bmp bestand verwerken
* +++tekst in bmp bestand verwerken
* ---2 verschillende bestanden maken
* ---schrijvenBMP stoppen bij *
* --- * toevegen aan bestand zonder *
* ---Readme
*
* Eventuele uitbreidingen:
*
*/


//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bestanden toekennen
char InputTXT[20];
char BMPINPUTFILE[20];
char BMPOUTPUTFILE[20];
char OutputTXT[20];

//alle functies
void schrijvenBMP();
void inlezenBMP();
int char_binair(char, int);
char binair_char();

//char arrays
char binChar[8];

int main(int argc, char* argv[]) {
	if (argc == 2 && strcmp(argv[1], "--help") == 0) //--help
	{
		printf("--help -c -->  help voor compress\n");
		printf("--help -d --> help voor decompress\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 3 && strcmp(argv[1], "--help") == 0)
	{
		if (argc == 3 && strcmp(argv[2], "-c") == 0) //--help -c
		{
			printf("-c --> compress\n");
			printf("-s --> het input tekstbestand met de secret message\n");
			printf("-i --> de input bmp file\n");
			printf("-o --> output image name\n");
			printf("EINDE HELP\n\n\n");
		}
		else if (argc == 3 && strcmp(argv[2], "-d") == 0) //--help -d
		{
			printf("-d --> decompress\n");
			printf("-i --> input bmp die de secret message bevat\n");
			printf("-o --> output text file waar het gedecodeerde bericht in komt\n");
			printf("EINDE HELP\n\n\n");
		}
		else
		{
			printf("Fout!!! \nNiet de juiste argumenten \nKijk in --help voor de uitleg \n");
		}
		exit(EXIT_FAILURE);
	}
	else if (argc == 8 && strcmp(argv[1], "-c") == 0) 
	{
		//(naam bestand) -c -s inputfile.txt -i meme.bmp -o memeOut.bmp
		if (argc == 8 && strcmp(argv[2], "-s") == 0) 
		{
			memcpy(InputTXT, argv[2], 20);
			InputTXT = "./inputfile.txt";
			printf("%s\n", argv[3]); //inputfile.txt
		}
		if (argc == 8 && strcmp(argv[4], "-i") == 0) 
		{
			BMPINPUTFILE = "./meme.bmp";
			printf("%s\n", argv[5]); //meme.bmp
		}
		if (argc == 8 && strcmp(argv[6], "-o") == 0) 
		{
			BMPOUTPUTFILE = "./memeOut.bmp";
			printf("%s\n", argv[7]); //memeOut.bmp
		}
		schrijvenBMP();
			
	} 
	else if (argc == 6 && strcmp(argv[1], "-d") == 0)
	{
		//(naam bestand) -d -i meme.bmp -o bericht.txt

		if (argc == 6 && strcmp(argv[2], "-i") == 0)
		{
			printf("%s\n", argv[3]); //meme.bmp
			//functie aanroepen
		}
		if (argc == 6 && strcmp(argv[4], "-o") == 0)
		{
			printf("%s\n", argv[5]); //bericht.txt
			//functie aanroepen
		}
		
	}
	else
	{
		printf("Fout!!! \nNiet de juiste argumenten \nKijk in --help voor de uitleg \n");
		exit(EXIT_FAILURE);
	}

	inlezenBMP();
	return 0;
}

void schrijvenBMP()
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
	int width = *(int*)& bmpHeader[18];
	int height = *(int*)& bmpHeader[22];

	//lezen van de pixels
	int imageSize = 3 * width * height; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
	unsigned char* inputPixels = (unsigned char*)calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels

	fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file)


	fseek(inputFilePointer, 54, SEEK_SET); //54 byte overslaan (Header)
	FILE* inputTextPointer = NULL;
	inputTextPointer = fopen(InputTXT, "rb");

	FILE* outputFilePointer = NULL;
	outputFilePointer = fopen(BMPOUTPUTFILE, "wb"); //nieuwe bmp aanmaken voor secret message in te schrijven

	fwrite(bmpHeader,sizeof(char),sizeof(bmpHeader), outputFilePointer); //header toevoegen aan output bestand

	while (!feof(inputFilePointer))
	{
		char currentCharacter = fgetc(inputTextPointer);
		for (int i = 7; i >= 0; i--)
		{
			int valueByte = fgetc(inputFilePointer);

			int bitChar = char_binair(currentCharacter, i);

			int singleBitPixel = valueByte & 1; //gaat een 0 of 1 teruggeven 
			
			if (singleBitPixel < bitChar)
			{
				valueByte++;
				fputc(valueByte, outputFilePointer);
			}
			else if (singleBitPixel > bitChar)
			{
				valueByte--;
				fputc(valueByte, outputFilePointer);
			}
			else
			{
				fputc(valueByte, outputFilePointer);
			}
		}
	}

	fclose(inputFilePointer);
	fclose(outputFilePointer);
	fclose(inputTextPointer);
}


void inlezenBMP()
{
	//teste of bmp file opent 
	FILE* inputFilePointer = fopen("memeOut.bmp", "rb"); //maak een file pointer naar de afbeelding
	if (inputFilePointer == NULL) //Test of het open van de file gelukt is!
	{
		printf("BMP file kan niet worden geopend %s\n", "memeOut.bmp");
		exit(EXIT_FAILURE);
	}

	unsigned char bmpHeader[54]; // voorzie een array van 54-bytes voor de BMP Header
	fread(bmpHeader, sizeof(unsigned char), 54, inputFilePointer); // lees de 54-byte header

	//Haal de hoogte en breedte uit de header
	int width = *(int*)& bmpHeader[18];
	int height = *(int*)& bmpHeader[22];

	//lezen van de pixels
	int imageSize = 3 * width * height; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
	unsigned char* inputPixels = (unsigned char*)calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels

	fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file)

	fseek(inputFilePointer, 54, SEEK_SET);

	FILE* outputTextPointer = NULL;
	outputTextPointer = fopen("output.txt", "wb");

	char lastChar = ' ';
	
	while ((!feof(inputFilePointer)) && lastChar != '*')
	{
		for (int i = 0; i < 8; i++)
		{
			int valueByte = fgetc(inputFilePointer);
			int singleBitPixel = valueByte & 1;
			binChar[i] = singleBitPixel + '0';
		}
		lastChar = binair_char();
		fputc(lastChar, outputTextPointer);
	}
	fclose(inputFilePointer);
	fclose(outputTextPointer);
}

int char_binair(char character, int i) 
{
	//nuttige commentaar
	return((character >> (i)) & 1);
}

char binair_char()
{
	//nuttige commentaar
	return strtol(binChar, 0, 2);
}
