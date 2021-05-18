# Authors
- **Gijs Jackers & Martijn Guilliams**
- *Studenten PXL-Digital*
- *Elektronica-ICT* 
- *PBEAI-B*

# CP2-project
&nbsp;&nbsp;C-program that encrypts a message in a BMP file and decrypts the BMP file to a secret massage.

# How to use

- General help function
```
--help
```
- Help function of compress
```
--help -c
```
- Help function of decompress
```
--help -d
```

# How to compile
```
gcc -Wall -pedantic -c lib.c -o lib.o
```
```
gcc -Wall -pedantic main.c lib.o -o Project
```

&nbsp;**Compress**
```
Project.exe -c -s inputfile.txt -i meme.bmp -o memeOut.bmp
```

&nbsp;**Decompress**
```
Project.exe -d -i memeOut.bmp -o bericht.txt
```

# Bibliography

&nbsp;Char to binary:  
- https://stackoverflow.com/questions/7863499/conversion-of-char-to-binary-in-c 

&nbsp;Convert binary to text:
- https://www.c-programming-simple-steps.com/binary-to-text.html 

&nbsp;Cmd argumenten:
- https://stackoverflow.com/questions/20076001/how-do-i-create-a-help-option-in-a-command-line-program-in-c-c 

&nbsp;Fputc explanation:
- https://www.geeksforgeeks.org/fgetc-fputc-c/ 
