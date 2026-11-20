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
    FILE *encFile;
    FILE *keyFile;
    if (!argv[2]) {
        encFile = fopen("enc.out", "w");
    } else {
        encFile = fopen(argv[2], "w");
    }
    if (!argv[2]) {
        keyFile = fopen("key.out", "w");
    } else {
        keyFile = fopen(argv[3], "w");
    }
    FILE *secretFile = fopen(argv[1], "r");


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
