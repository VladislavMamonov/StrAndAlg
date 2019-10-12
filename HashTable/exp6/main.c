#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    collision hash_;
    srand(time(NULL));
    listnode* hashtab[HASHTAB_SIZE];
    // printf("%ld\n", sizeof(listnode) * N);
    hashtab_init(hashtab);
    memset(&hash_, 0, sizeof(collision));
    FILE* word;
    //FILE* HashtabLookup_X;
    FILE* HashtabLookup_Y;
    //HashtabLookup_X = fopen("HashtabLookup_X.dat", "wb");
    HashtabLookup_Y = fopen("HashtabLookup_Y.dat", "wb");
    word = fopen("words.txt", "r");
    if (word == NULL) {
        printf("Unknown file\n");
        return 1;
    }

    char key[100];
    int k = 0;

    char buf[256];
    int j = rand() % HASHTAB_SIZE;

    for (int i = 1; i <= HASHTAB_SIZE; i++) {
        if (i % 10000 == 0) {
        while (k < i) {
            fscanf(word, "%s", key);
            if (k == j)
                strcpy(buf, key);
            hashtab_add(hashtab, key, k++, &hash_);
            }    
            work(&hash_);
            double time;
            time = wtime();
            hashtab_lookup(hashtab, buf);
            time = wtime() - time;
            printf("elements: %d\twork time: %f\tcollision: %d\n", i, time, hash_.collisi);
            //fprintf(HashtabLookup_X, "%d\t%f\t%d\n", i, time, hash_.collisi);                
            fprintf(HashtabLookup_Y, "%d\t%f\t%d\n", i, time, hash_.collisi);                  
        }
    }
    fclose(word);
    //fclose(HashtabLookup_X);
    fclose(HashtabLookup_Y);
    return 0;
}