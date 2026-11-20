#include <stdio.h>
#include <stdlib.h>
int decrypt(FILE *decFile, FILE *encFile, FILE *keyFile){
    int c;
    int key;
    key = fgetc(keyFile);
    while ((c = fgetc(encFile)) != EOF) {
        c = c ^ key;
        fputc(c, decFile);
    }

    return 0;
}
int main(int argc, char* argv[]){
    FILE *encFile = fopen(argv[1], "r");
    FILE *keyFile = fopen(argv[2], "r");
    FILE *decFile = fopen(argv[3], "w");
    if (!encFile || !keyFile) {
        printf("enter valid arguments");
        exit(-1);
    }
    decrypt(decFile, encFile, keyFile);
    
    fclose(encFile);
    fclose(keyFile);
    fclose(decFile);
    return 0;
}
