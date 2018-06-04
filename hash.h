#ifndef HASH_H
#define HASH_H
#define TRUE 1
#define FALSE 0
#define MAX 65536


typedef struct elem{
	char *key;
	char *value;
	struct elem *next;
}Node;

typedef struct HASH_{
	int size;
	Node **table;
}Hash;

Hash* create(int size);

int hash(int tablesize, char *key);

Node* newNode(char *value, char *key);

int insertNode(Hash *T, char *value, char *key);

Node* searchNode(Hash *T, char *key);

Node* deleteNode(Hash *T, char *key);

#endif
