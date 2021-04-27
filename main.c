#include <stdio.h>
#include <stdlib.h>

#define __DEBUG

#define BMPINPUTFILE "test.bmp"

int main()
{
    #ifdef __DEBUG
        printf("DEBUG info: BMP transformer\n");
    #endif

    FILE* inputFilePointer = fopen(BMPINPUTFILE, "rb"); //maak een file pointer naar de afbeelding
    if(inputFilePointer == NULL) //Test of het open van de file gelukt is!
    {
        printf("Something went wrong while trying to open %s\n", BMPINPUTFILE);
        exit(EXIT_FAILURE);
    }

    #ifdef __DEBUG
        printf("DEBUG info: Opening File OK: %s\n", BMPINPUTFILE);
    #endif

    unsigned char bmpHeader[54]; // voorzie een array van 54-bytes voor de BMP Header
    fread(bmpHeader, sizeof(unsigned char), 54, inputFilePointer); // lees de 54-byte header

    //Informatie uit de header (wikipedia)
    // haal de hoogte en breedte uit de header
    int breedte = *(int*)&bmpHeader[18];
    int hoogte = *(int*)&bmpHeader[22];

    #ifdef __DEBUG
        printf("DEBUG info: breedte = %d\n", breedte);
        printf("DEBUG info: hoogte = %d\n", hoogte);
    #endif

    int imageSize = 3 * breedte * hoogte; //ieder pixel heeft 3 byte data: rood, groen en blauw (RGB)
    unsigned char* inputPixels = (unsigned char *) calloc(imageSize, sizeof(unsigned char)); // allocate een array voor alle pixels
	

	
    fread(inputPixels, sizeof(unsigned char), imageSize, inputFilePointer); // Lees alle pixels (de rest van de file
    fclose(inputFilePointer);
	for(int i =0; i < imageSize-2; i+=3)
	{
		printf("pixel %d: B= %d, G=%d, R=%d\n", i, inputPixels[i], inputPixels[i+1], inputPixels[i+2]);
	}
   
    fclose(inputFilePointer);
    free(inputPixels);
    
    return 0;
}
