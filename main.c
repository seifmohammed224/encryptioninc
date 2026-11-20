#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(FILE *secretFile, FILE *encFile, FILE *keyFile) {
    int c;
    int key = rand() % 256;

    fputc(key, keyFile);

    while ((c = fgetc(secretFile)) != EOF) {
        c = c ^ key;
        fputc(c, encFile);
    }

    return 0;
}

int decrypt(FILE *decFile, FILE *encFile, FILE *keyFile) {
    int c;
    int key;

    key = fgetc(keyFile);

    while ((c = fgetc(encFile)) != EOF) {
        c = c ^ key;
        fputc(c, decFile);
    }

    return 0;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("missing mode argument\n");
        return 1;
    }

    if (strcmp(argv[1], "-e") == 0) {

        if (argc < 3) {
            printf("missing input file\n");
            return 1;
        }

        FILE *secretFile = fopen(argv[2], "rb");

        FILE *encFile;
        FILE *keyFile;

        if (argc >= 4)
            encFile = fopen(argv[3], "wb");
        else
            encFile = fopen("enc.out", "wb");

        if (argc >= 5)
            keyFile = fopen(argv[4], "wb");
        else
            keyFile = fopen("key.out", "wb");

        if (!secretFile || !encFile || !keyFile) {
            printf("error opening files\n");
            if (secretFile != NULL){
                fclose(secretFile);
            }
            if (encFile != NULL){
                fclose(encFile);
            }
            if (keyFile != NULL){
                fclose(keyFile);
            }
            return 1;
        }

        encrypt(secretFile, encFile, keyFile);

        fclose(secretFile);
        fclose(encFile);
        fclose(keyFile);
    }

    else if (strcmp(argv[1], "-d") == 0) {


        if (argc < 4) {
            printf("missing encrypted file or key file\n");
            return 1;
        }

        FILE *encFile = fopen(argv[2], "rb");
        FILE *keyFile = fopen(argv[3], "rb");

        FILE *decFile;

        if (argc >= 5)
            decFile = fopen(argv[4], "wb");
        else
            decFile = fopen("dec.out", "wb");

        if (!encFile || !keyFile || !decFile) {
            printf("error opening files\n");
            if (decFile != NULL){
                fclose(decFile);
            }
            if (encFile != NULL){
                fclose(encFile);
            }
            if (keyFile != NULL){
                fclose(keyFile);
            }
            return 1;
        }

        decrypt(decFile, encFile, keyFile);

        fclose(encFile);
        fclose(keyFile);
        fclose(decFile);
    }

    else {
        printf("invalid mode use -e for encryption or -d for decryption\n");
        return 1;
    }

    return 0;
}
