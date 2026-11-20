# c file encryptor

a small file encryption/decryption program i made using c.

## features
- encrypt files using xor
- decrypt files using a saved key
- supports binary files
- custom output filenames
- default output filenames

## compile

```bash
gcc main.c -o crypt
```

## usage

### encrypt

```bash
./crypt -e input.txt encrypted.bin key.bin
```

you can also just use:

```bash
./crypt -e input.txt
```

default files will be `enc.out` and `key.out`.

### decrypt

```bash
./crypt -d encrypted.bin key.bin output.txt
```

or:

```bash
./crypt -d encrypted.bin key.bin
```

the default output file is `dec.out`.

