# CP2-project:

C-program that encrypts a message in a BMP file and decrypts the BMP file to a secret massage

# How to compile:

gcc -Wall -pedantic -c lib.c -o lib.o

gcc -Wall -pedantic main.c lib.o -o Project

Compress:
- Project.exe -c -s inputfile.txt -i meme.bmp -o memeOut.bmp

Decompress:
- Project.exe -d -i memeOut.bmp -o bericht.txt


# Bibliography: 

Char to binary:  
- https://stackoverflow.com/questions/7863499/conversion-of-char-to-binary-in-c 

Convert binary to text:
- https://www.c-programming-simple-steps.com/binary-to-text.html 

Cmd argumenten:
- https://stackoverflow.com/questions/20076001/how-do-i-create-a-help-option-in-a-command-line-program-in-c-c 

Fputc explanation:
- https://www.geeksforgeeks.org/fgetc-fputc-c/ 
