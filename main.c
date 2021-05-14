/* 
* to do:
* +++grootte uitlezen en aanpssen naar 8bits binair
* +++cmd argumenten kunnen uitlezen
* +++txt bestand uitlezen 
* +++array grootte bepalen door bestand
* ---tekst omvormen naar binair
* +++grootte van bmp bestand uitlezen
* +++letter in bmp bestand verwerken (hard gecodeerd)
* ---tekst in bmp bestand verwerken
* ---bmp bestand uitlezen
* ---binair omzetten naar tekst
* 
* ---fout geven bij te weinig of foutive cmd argumenten
*/


//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bestanden toekennen
#define BESTAND "./test.txt"
#define BMPINPUTFILE "./CP2_Encoded.bmp"

//alle void
void schrijvenBMP();
void inlezenBMP();
void schrijvenTXT();
void inlezenTXT();
int grootteTXT();
void char_binair(char);
void binair_char();

//char arrays
char binLetter_8[8];
char tekst[200]; //grootte variabel maken



int main(int argc, char* argv[]) {
	if (argc == 2 && strcmp(argv[1], "--help") == 0) //--help
	{
		printf("--help -c -->  help voor compress\n");
		printf("--help -d --> help voor decompress\n");
	}
	
	if (argc == 3 && strcmp(argv[1], "--help") == 0)
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

	}

	if (argc == 8 && strcmp(argv[1], "-c") == 0) 
	{
		//(naam bestand) -c -s inputfile.txt -i meme.bmp -o memeOut.bmp
		if (argc == 8 && strcmp(argv[2], "-s") == 0) 
		{
			printf("%s\n", argv[3]); //inputfile.txt
			//functie aanroepen
		}
		if (argc == 8 && strcmp(argv[4], "-i") == 0) 
		{
			printf("%s\n", argv[5]); //meme.bmp
			//functie aanroepen
		}
		if (argc == 8 && strcmp(argv[6], "-o") == 0) 
		{
			printf("%s\n", argv[7]); //memeOut.bmp
			//functie aanroepen
		}
			
	}

	if (argc == 6 && strcmp(argv[1], "-d") == 0)
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



	
	inlezenTXT();
    
	char_binair('t');
	
	binair_char();
	
	inlezenBMP();

	schrijvenBMP();

    return 0;
}

void schrijvenBMP()
{
	
}


void inlezenBMP()
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
	int breedte = *(int*)& bmpHeader[18];
	int hoogte = *(int*)& bmpHeader[22];

	printf("DEBUG info: breedte = %d\n", breedte);
	printf("DEBUG info: hoogte = %d\n", hoogte);

	//lezen van de pixels
	int imageSize = 3 * breedte * hoogte; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
	unsigned char* inputPixels = (unsigned char*)calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels

	fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file)
	fclose(inputFilePointer);
	int plaatsBit = 0;
	imageSize = 200; //testen tot 200
	for (int i = 0; i < imageSize - 2; i += 3)
	{
		int k;
		int limiet = 0;
		if(imageSize == 6 || (imageSize-6) % 9 == 0) //ervoor zorgen dat de in de 3e bit blauw niet meer wordt aangepast
		{
			limiet = 1;
		}
		else
		{
			limiet = 0;
		}

		for (int j = 2; j >= limiet; j--)
		{
			k = inputPixels[i + j] >> 7; // 7 => 8ste bit
			printf("k= %d: \n", k);
			if (k & 1)
			{
				binLetter_8[plaatsBit] = '1';
			}
			else
			{
				binLetter_8[plaatsBit] = '0';
			}
			plaatsBit++;
			if(plaatsBit >= 8)
			{
				plaatsBit = 0;
				binair_char(); // na 8 pas printen
			}
			

		}
		
		printf("pixel %d: B= %d, G=%d, R=%d\n", i, inputPixels[i], inputPixels[i + 1], inputPixels[i + 2]);
	}
	*/

	//int imageSize = 200; //testen tot 200
	//tekst = (char*)malloc(imageSize);
	//free(tekst);


	printf("test\n");
	//Hard gecodeerde letter A
	binLetter_8[0] = '0';
	binLetter_8[1] = '1';
	binLetter_8[2] = '0';
	binLetter_8[3] = '0';
	binLetter_8[4] = '0';
	binLetter_8[5] = '0';
	binLetter_8[6] = '0';
	binLetter_8[7] = '1';
	binair_char();
	//Hard gecodeerde letter *
	binLetter_8[0] = '0';
	binLetter_8[1] = '0';
	binLetter_8[2] = '1';
	binLetter_8[3] = '0';
	binLetter_8[4] = '1';
	binLetter_8[5] = '0';
	binLetter_8[6] = '1';
	binLetter_8[7] = '0';
	binair_char();
}

void schrijvenTXT();
{

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


void char_binair(char character)
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
	printf("binair_char\n");
    char c = strtol(binLetter_8, 0, 2);
	if(c == '*')
	{
		printf("*\n");
	}
	else
	{
		printf("Letter is: %c \n\n", c);
		tekst[0] = c; // plaats opschuiven
	}
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