// Jackers Gijs & Guilliams Martijn
// CP2: Semester opdracht
// Studenten PXL-Digital 
// Elektronica-ICT 
// PBEAI-B

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	/*
	* compressDecompress schrijft de secret message in een BMP bestand of haalt de secret message uit het BMP bestand.
	*@param: char codeDecode keuze voor compress(c) of decompress(d).
	*@return: void (geen)
	*/
	void compressDecompress(char codeDecode);


	/*
	* char_binair: één bit uit een letter nemen op plaats i.
	*@param: char character: letter om bit uit te halen.
	*	     int i: aantal plaatsen dat opgeschoven moeten worden.
	*@return: bit die in het BMP bestand wordt geplaatst.
	*/
	int char_binair(char character, int i);


	/*
	* binair_char: binair omzetten naar een character.
	*@param: geen parameter.
	*@return: geeft letter terug.
	*/
	char binair_char();