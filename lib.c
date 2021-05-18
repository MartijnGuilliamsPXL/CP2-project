// Jackers Gijs & Guilliams Martijn
// CP2: Semester opdracht
// Studenten PXL-Digital 
// Elektronica-ICT 
// PBEAI-B

#include "lib.h"

//Char arrays
char binChar[8];
char InputTXT[20];
char BMPINPUTFILE[20];
char BMPOUTPUTFILE[20];
char OutputTXT[20];


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

	if (codeDecode == 'c') //coderen
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

	else if (codeDecode == 'd') //decoderen
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


int char_binair(char character, int i)
{
	return((character >> (i)) & 1);
}


char binair_char()
{
	return strtol(binChar, 0, 2);
}