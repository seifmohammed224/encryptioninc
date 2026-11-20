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
    FILE *encFile = fopen("enc.out", "w");
    FILE *keyFile = fopen("key.out", "w");
    if (!secretFile) {
        printf("enter valid argument");
        exit(-1);
    }
    encrypt(secretFile, encFile, keyFile);
    
    fclose(secretFile);
    fclose(encFile);
    fclose(keyFile);
    return 0;
}