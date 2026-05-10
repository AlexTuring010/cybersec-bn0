#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <openssl/evp.h>

void sha256(const char *str, unsigned char hash[EVP_MAX_MD_SIZE], unsigned int *hash_len) {
    EVP_MD_CTX *ctx;
    ctx = EVP_MD_CTX_new();
    if (!ctx) {
        fprintf(stderr, "EVP_MD_CTX_new failed\n");
        exit(1);
    }
    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1 ||
        EVP_DigestUpdate(ctx, str, strlen(str)) != 1 ||
        EVP_DigestFinal_ex(ctx, hash, hash_len) != 1) {
        fprintf(stderr, "SHA-256 computation failed\n");
        exit(1);
    }
    EVP_MD_CTX_free(ctx);
}

void the_kingdom_is_yours() {
    execl("/bin/sh", "sh", NULL);
}

void check(char * key) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    sha256(key, hash, &hash_len);
    // only let arthur through
    if (strncmp(hash, "\xe6\xee\xaf\xfd\x9c\x82\x7c\x4e\xc5\x2b\xeb\xd8\x22\xcd\x1c\xe2\xbe\x33\x8d\xb1\x87\xf0\xcf\xa8\x58\x5a\xa7\x3b\x76\xf1\x11\xe7", hash_len) == 0) {
        the_kingdom_is_yours();
    }
    else {
        char * message;
        asprintf(&message, "Wrong key: %s. No key, no entry!\n", key);
        printf(message);
        // free(message) // memleak - it's ok for now
    }
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: %s <magic_key>\n", argv[0]);
        return 1;
    }
    char key[strlen(argv[1]) + 1];
    strcpy(key, argv[1]);
    check(key);
    return 0;
}