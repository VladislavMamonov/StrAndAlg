#include "bstree.h"
#include "hashtab.h"
#include "AdditionalFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define n 200000

int main()
{
 	struct bstree *tree;
    struct bstree *node;
    
    char words[n][25];
    char *w;
    
    struct listnode *hnode;
    struct listnode *hashtab[n];
    
    hashtab_init(&hnode);
    hashtab_init(hashtab);
    
    FILE *word = fopen("words.txt", "r");
    FILE *BstreeLookup = fopen("bstree_lookup.dat", "wb");
    FILE *HashtabLookup = fopen("hashtab_lookup.dat", "wb");
    
    if (word == NULL) {
        printf("No file\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		fscanf(word, "%s", words[i]);

	fclose(word);

	int select;
	printf("Input exp: ");
	scanf("%d", &select);

	tree = bstree_create(words[0], 0);

	if (select == 1) {
		for (int i = 1; i <= n; i++) {		//Эксперимент 1
			bstree_add(tree, words[i], i);
			if (i % 10000 == 0) {
				w = words[getrand(1, i)];
				double time = wtime();
				node = bstree_lookup(tree, w);
				time = wtime() - time;
				printf("words = %d; time = %.6lf\n", i, time);
				printf("founded element: %s\n", node->key);
				fprintf(BstreeLookup, "%d\t%.9lf\n", i, time);
			}
		}

		printf("\n");
		printf("__________________________\n");
		printf("HASHTAB LOOKUP\n");
		sleep(4);
		for (int i = 1; i <= n; i++) {
			hashtab_add(hashtab, words[i], i);
			if (i % 10000 == 0) {
				w = words[getrand(1, i)];
				double time = wtime();
				hnode = hashtab_lookup(hashtab, w);
				time = wtime() - time;
				printf("words = %d; time = %.6lf\n", i, time);
				printf("founded element: %s\n", hnode->key);
				fprintf(HashtabLookup, "%d\t%.9lf\n", i, time);
			}
		}
		fclose(BstreeLookup);
		fclose(HashtabLookup);
	}

	if (select == 4) {
	    FILE *word_descending = fopen("words_descending.txt", "r");
    	FILE *bstree_min_average = fopen("bstree_min_average.dat", "wb");
    	FILE *bstree_min_worst = fopen("bstree_min_worst.dat", "wb");

		for (int i = 1; i <= n; i++) {		//Эксперимент 4
			bstree_add(tree, words[i], i);
			if (i % 10000 == 0) {
				double time = wtime();
				node = bstree_min(tree);
				time = wtime() - time;
				printf("words = %d; time = %.6lf\n", i, time);
				printf("founded element: %s\n", node->key);
				fprintf(bstree_min_average, "%d\t%.9lf\n", i, time);
			}	
		}
		for (int i = 0; i < n; i++)
			fscanf(word_descending, "%s", words[i]);	//Запись убывающих слов в массив

		printf("\n");
		printf("__________________________\n");
		printf("WORST HAPPENING LOOKUP\n");
		sleep(4);

		for (int i = 1; i <= n; i++) {
			bstree_add(tree, words[i], i);
			if (i % 10000 == 0) {
				double time = wtime();
				node = bstree_min(tree);
				time = wtime() - time;
				printf("words = %d; time = %.6lf\n", i, time);
				printf("founded element: %s\n", node->key);
				fprintf(bstree_min_worst, "%d\t%.9lf\n", i, time);
			}
		}
		fclose(word_descending);
		fclose(bstree_min_average);
		fclose(bstree_min_worst);
	}
}


