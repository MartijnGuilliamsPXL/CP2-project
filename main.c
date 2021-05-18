// Jackers Gijs & Guilliams Martijn
// CP2: Semester opdracht
// Studenten PXL-Digital 
// Elektronica-ICT 
// PBEAI-B

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Functies
void compressDecompress(char);
int char_binair(char, int);
char binair_char();

//Char arrays
char binChar[8];
char InputTXT[20];
char BMPINPUTFILE[20];
char BMPOUTPUTFILE[20];
char OutputTXT[20];

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
			//InputTXT geen vaste grootte geven //werkt niet
			//InputTXT = (char*)malloc(strlen(argv[3]));
			//memcpy(InputTXT, argv[3], strlen(argv[3]));

			memcpy(InputTXT, argv[3], 20);
		}
		if (argc == 8 && strcmp(argv[4], "-i") == 0)
		{
			memcpy(BMPINPUTFILE, argv[5], 20);
		}
		if (argc == 8 && strcmp(argv[6], "-o") == 0)
		{
			memcpy(BMPOUTPUTFILE, argv[7], 20);
		}
		compressDecompress('c');
	}
	else if (argc == 6 && strcmp(argv[1], "-d") == 0)
	{
		//(naam bestand) -d -i memeOut.bmp -o bericht.txt

		if (argc == 6 && strcmp(argv[2], "-i") == 0)
		{
			memcpy(BMPINPUTFILE, argv[3], 20);
		}
		if (argc == 6 && strcmp(argv[4], "-o") == 0)
		{
			memcpy(OutputTXT, argv[5], 20);
		}
		compressDecompress('d');
	}
	else
	{
		printf("Fout!!! \nNiet de juiste argumenten \nKijk in --help voor de uitleg \n");
		exit(EXIT_FAILURE);
	}
	return 0;
}


/*
* compressDecompress schrijft de secret message in een BMP bestand of haalt de secret message uit het BMP bestand.
*@param: char codeDecode keuze voor compress(c) of decompress(d).
*@return: void (geen)
*/
void compressDecompress(char codeDecode)
{ 
	FILE* inputFilePointer = fopen(BMPINPUTFILE, "rb"); //Maak een file pointer naar de afbeelding
	if (inputFilePointer == NULL) //Test of het open van de file gelukt is!
	{
		printf("BMP file kan niet worden geopend %s\n", BMPINPUTFILE);
		exit(EXIT_FAILURE);
	}

	unsigned char bmpHeader[54]; // voorzie een array van 54-bytes voor de BMP Header
	fread(bmpHeader, sizeof(unsigned char), 54, inputFilePointer); // lees de 54-byte header

	//Breedte en hoogte uit de header halen
	int width = *(int*)&bmpHeader[18];
	int height = *(int*)&bmpHeader[22];

	//lezen van de pixels
	int imageSize = 3 * width * height; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
	unsigned char* inputPixels = (unsigned char*)calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels

	fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file)

	fseek(inputFilePointer, 54, SEEK_SET);

	if (compressDecompress == 'c') //coderen
	{
		FILE* inputTextPointer = NULL;
		inputTextPointer = fopen(InputTXT, "rb");

		FILE* outputFilePointer = NULL;
		outputFilePointer = fopen(BMPOUTPUTFILE, "wb"); //nieuwe bmp aanmaken voor secret message in te schrijven

		fwrite(bmpHeader, sizeof(char), sizeof(bmpHeader), outputFilePointer); //header toevoegen aan output bestand

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

		fclose(outputFilePointer);
		fclose(inputTextPointer);
	}

	else if (c == 'd') //decoderen
	{
		FILE* outputTextPointer = NULL;
		outputTextPointer = fopen(OutputTXT, "wb");

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

		fclose(outputTextPointer);
	}
	fclose(inputFilePointer);
}


/*
* char_binair: één bit uit een letter nemen op plaats i.
*@param: char character: letter om bit uit te halen.
*	     int i: aantal plaatsen dat opgeschoven moeten worden.
*@return: bit die in het BMP bestand wordt geplaatst.
*/
int char_binair(char character, int i)
{
	return((character >> (i)) & 1);
}


/*
* binair_char: binair omzetten naar een character.
*@param: geen parameter.
*@return: geeft letter terug.
*/
char binair_char()
{
	return strtol(binChar, 0, 2);
}