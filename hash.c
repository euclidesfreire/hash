#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

Hash* create(int size){
	
	int i;
	Hash *ha = (Hash*)malloc(sizeof(Hash));
		
	ha->size = size;
	
	ha->table = (Node**)malloc(size*sizeof(Node));
	
	if(!ha->table){
        return NULL;
	}else{	
        for(i = 0; i <ha->size; i++){
            ha->table[i] = NULL;
        }
        return ha;
	}
}

int hash(int tablesize, char *key){
	
	unsigned long int hashval;
	int i;
	
    for(i = 0; i<strlen(key); i++){
        hashval = hashval << 8;
		hashval += key[i];
    }
    
    return (hashval % tablesize);

}

Node* newNode(char *value, char *key){
	Node *n;

	n = (Node*)malloc(sizeof(Node));

	if(!n)
    	return NULL;
	
	n->key = (char*)malloc(100 * sizeof(char));
	strcpy(n->key, key);
	n->value = (char*)malloc(100 * sizeof(char));
	strcpy(n->value, value);
	n->next = NULL;

	return n;

}

int insertNode(Hash *T, char *value, char *key){

    int pos = hash(T->size, key);
	
    Node *novo = newNode(value, key);
   

    if(!novo)
        return 0;

    if(T->table[pos] == NULL){
	    T->table[pos] = novo;
    } else {

        Node *p = T->table[pos];

        while(p->next != NULL)
            p = p->next;

        p->next = novo;

    }

    return 1;

}

Node* searchNode(Hash *T, char *key){
	int pos = hash(T->size, key);
	
	if(T->table[pos] == NULL){
		printf("Palavra nao encontrada!");
		return NULL;
	} else {
		Node *p = T->table[pos];
        
		while(strcmp(p->value, key) != 0){
		    p = p->next;
		    printf("OK\n");
		}
		
        return p;
	}
}

Node* deleteNode(Hash *T, char *key){

	int pos = hash(T->size, key);
	
	if(!T->table[pos]){
		printf("\nHash vazia!");
		return;
	} else {
		 
		Node *p = T->table[pos];
		Node *q;
		
        while(strcmp(p->value, key) != 0){
           	q = p;
		    p = p->next;
		}
		
		
        q->next = p->next;
        
        return p;
	}
	
}
