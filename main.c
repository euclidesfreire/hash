#include "hash.c"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int lerArquivo(Hash *h){
	FILE *f = fopen("dicionario.txt", "r");
		
	char *palavra = (char*)malloc(100*sizeof(char));
	int cont = 0;
		
	while(fscanf(f, "%s", palavra) != EOF){
			insertNode(h, palavra, palavra);
			cont++;			
	}	
	
	return cont;
}

int quantasVezes(Hash *h, char *key){
	int i, cont=0;
	Node *p;
     
	for(i = 0; i<MAX; i++){
		if(h->table[i] != NULL){
			p = h->table[i];		
			while(p->next != NULL){
				if(strcmp(p->value, key) == 0){
					cont++;
				}
		    	p = p->next;
		    }
		}
	}
	
	return cont;	
}

void escreverCopia(Hash *h){
	int i, j;
	Node *p;
	FILE *c = fopen("copia.txt", "wt");
     
	for(i = 0; i<MAX; i++){
		if(h->table[i] != NULL){
			p = h->table[i];		
			while(p->next != NULL){
				fprintf(c, "%s", p->value);
		    	p = p->next;
		    }
		}
	}
	
}

void listarHash(Hash *h){
	int i, j;
	Node *p;
     
    printf("\n------ TABELA HASH ------\n");
	for(i = 0; i<MAX; i++){
		if(h->table[i] != NULL){
			p = h->table[i];
			printf("\n\nTABELA[ %d ]\n\n", i);			
			while(p->next != NULL){
				printf("Key[ %s ] => %s\n", p->key, p->value);
		    	p = p->next;
		    }
		}
	}
	printf("-------------------\n");
}

void menu() {
  printf ("######### TABELA HASH #########\n\n");
  printf ("========== MENU ==========\n");
  printf ("1 - Informar quantas vezes uma palavra aparece no arquivo\n");
  printf ("2 - Quantas palavras diferentes foram encontradas no arquivo\n");
  printf ("3 - O total de palavras do arquivo\n");
  printf ("4 - Buscar por uma palavra no arquivo\n");
  printf ("5 - Inserir uma palavra nova\n");
  printf ("6 - Excluir uma palavra\n");
  printf ("7 - Imprimir a estruturação da tabela hash\n");
  printf ("\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

int main(int argc, char const *argv[]){
	char *palavra, *key;
	int cont;
	FILE *file;
	Hash *h = create(MAX);
		
	cont = lerArquivo(h);
	escreverCopia(h);
	
	int op = -1;

  do {
	system("cls || clear");
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
      	palavra = (char*)malloc(100*sizeof(char));
        printf("Digite a Chave: ");
        scanf("%s", palavra);
        printf("\n%s", palavra); 
      	cont = quantasVezes(h, palavra);
		printf("\n%s Aparece %d no Arquivo\n", palavra, cont);     
        break;
      case 2:
        
        break;
      case 3:
      	
		  printf("\n#Tolal de Palavras: %d\n", cont);
		          
        break;
      case 4:
      	    	
		key = (char*)malloc(100*sizeof(char));
        printf("Digite a Chave: ");
        scanf("%s", key);
        
        Node *n = searchNode(h, key);
        
        if(n != NULL)
        	printf("Key[ %s ] => %s", n->key, n->value);
        
        break;
      case 5:
      	
      	palavra = (char*)malloc(100*sizeof(char));
        printf("Digite a palavra: ");
        scanf("%s", palavra);
        
        insertNode(h, palavra, palavra);
                
        break;
      case 6:
      
        break;
      case 7:
      	listarHash(h);        
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
	
	return 0;
}
