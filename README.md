# encryption in c
this is my encryption/decryption program in c

to use , make a text file , lets say you name it secretfile.txt

you clone the repo , put the file next to the source code, then the name of the output encrypted file , then the name of the key for it and compile , after compiling you run

```./enc secretfile.txt secretfileenc secretfilekey```
this will make 2 new files , an encrypted file and a key file
now if you want to decrypt it , u compile dec.c

then run it , put the encryptied file , the key file and the output you want to name for example
```
./dec secretfileenc secretfilekey secretfiledecrypted.txt
```
and boom it works for some reason
-- note: it is completely optional to provide output names , like you dont need to provide a key file name or encrypted file name when encrypting something and you dont need to provide outputted decrypted file name
