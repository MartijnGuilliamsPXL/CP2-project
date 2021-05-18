// Jackers Gijs & Guilliams Martijn
// CP2: Semester opdracht
// Studenten PXL-Digital 
// Elektronica-ICT 
// PBEAI-B

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

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
		//Project.exe -c -s inputfile.txt -i meme.bmp -o memeOut.bmp
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
		//Project.exe -d -i memeOut.bmp -o bericht.txt

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