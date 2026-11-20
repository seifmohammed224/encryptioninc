#include<stdio.h>
#include<stdlib.h>
int encrypt(FILE *secretFile,FILE *encFile, FILE *keyFile ){

    int c;
    int key = rand();
    fputc(key, keyFile);
    while ((c = fgetc(secretFile)) != EOF) {
        c = c ^ key;
        fputc(c, encFile);
    }
    
    return 0;
}
int main(int argc, char* argv[]){
    FILE *secretFile = fopen(argv[1], "r");
    FILE *encFile = fopen(argv[2], "w");
    FILE *keyFile = fopen(argv[3], "w");
    if (!secretFile || !encFile || !keyFile) {
        printf("enter valid argument");
        exit(-1);
    }
    encrypt(secretFile, encFile, keyFile);
    
    fclose(secretFile);
    fclose(encFile);
    fclose(keyFile);
    return 0;
}
