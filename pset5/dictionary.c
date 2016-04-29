/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "dictionary.h"

typedef struct sll{
    char word[LENGTH+1];
    struct sll* next;
}
sll;

int sizel = 0;
sll* arr[212] = {NULL};


int hashpjw(const char *s)
    {
    	const char *p;
    	unsigned int h, g;
    	h = 0;
    	for(p=s; *p!='\0'; p++){
    		h = (h<<4) + *p;
    		if ((g = h&0xF0000000)) {
    			h ^= g>>24;
    			h ^= g;
    		}
    	}
    	return h % 211;
    }
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char DuplicateArray[45];
    int sizevalue = strlen (word);

    strncpy(DuplicateArray, word, sizevalue);//word is the const char pointer.
    DuplicateArray[sizevalue] = '\0';
    int i = 0;
    while ( DuplicateArray[i] != '\0' )
    {
    DuplicateArray[i] = tolower(DuplicateArray[i]);    
    i++;
    }
    
    
    
    int id = hashpjw(DuplicateArray);
    //printf("%d\n", id);
    if (arr[id] == NULL) {
        return false;
    } else {
        sll* head = arr[id];
        while(head != NULL){
            //printf("### %s  %s  %s\n", arr[id]->word, head->word, word);
            int res = strcmp(head->word, DuplicateArray);
            //printf("res = %d\n", res);
            if (res == 0) {
                return true;
            } else {
                head = head->next;
            }
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE * fp;
    fp = fopen (dictionary, "r");
    
    if(fp == NULL){
        return false;
    }

    char input[LENGTH+1];
    fscanf(fp, "%s", input);
    //printf("size of input %u\n", (int)sizeof(input));
    while (!feof(fp)) {
        sll* new_node = malloc(sizeof(sll));
        strncpy(new_node->word, input, strlen(input));
        //printf("$$ %s\n",new_node->word);
        int result = hashpjw(new_node->word);
        //printf("### %d\n", result);
        // not working yet vvv
        if(arr[result] == NULL) {
            //printf("zzzzzz\n");
            arr[result] = new_node;
        } else {
            new_node->next = arr[result];
            arr[result] = new_node;
          //  printf("ZzZZzz");
        }
        // not working yet ^^^
        //printf("##### %s\n", arr[result]->word);
        fscanf(fp, "%s", input);
        sizel++;
    }
    fclose(fp);
    if (sizeof(arr) == 0) {
        return false;
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return sizel;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < 211; i++) {
        sll* head = arr[i];
        while(head != NULL) {
            sll* temp = head;
            head = head->next;
            free(temp);
            sizel--;
        }
    }
    if (sizel == 0) {
        return true;
    } else {
        return false;
    }
    
}
