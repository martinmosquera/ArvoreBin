#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;


Arvore*  cria_arv_vazia (Arvore* a);
Arvore*  arv_constroi (char c, Arvore* e, Arvore* d);
int      verifica_arv_vazia (Arvore* a);
Arvore*  arv_libera (Arvore* a);
int      arv_pertence (Arvore* a, char c);
void     arv_imprime (Arvore* a,int lv);

Arvore* cria_arv_vazia (Arvore* a) {
  a->dir == NULL;
  a->esq == NULL;
   return NULL;
}

Arvore* arv_constroi (char c, Arvore* e, Arvore* d) {
  Arvore* a = (Arvore*)malloc(sizeof(Arvore));
  a->info = c;
  a->esq = e;
  a->dir = d;
  return a;
}

int verifica_arv_vazia (Arvore* a) {
  return (a == NULL);
}

Arvore* arv_libera (Arvore* a) {
  if (!verifica_arv_vazia(a)) {
    arv_libera (a->esq);
    arv_libera (a->dir);
    free(a);
  }
  return NULL;
}

void arv_imprime (Arvore* a, int lv){
	if(!a) return;
  if(lv == 0)
  printf("< %c", a->info);
  lv++;
  if(a->esq != NULL) printf("< %c", a->esq->info);
  else printf(">");
  if(a->dir != NULL) printf("< %c", a->dir->info);
	else printf(">");
  arv_imprime(a->esq,lv);
  arv_imprime(a->dir,lv);
}


int main (int argc, char *argv[]) {
  Arvore *a, *a1, *a2, *a3, *a4, *a5;
  a1 = arv_constroi('d',cria_arv_vazia(a1),cria_arv_vazia(a1));
  a2 = arv_constroi('b',cria_arv_vazia(a2),a1);
  a3 = arv_constroi('e',cria_arv_vazia(a3),cria_arv_vazia(a3));
  a4 = arv_constroi('f',cria_arv_vazia(a4),cria_arv_vazia(a4));
  a5 = arv_constroi('c',a3,a4);
  a  = arv_constroi('a',a2,a5);
  arv_imprime(a,0);
  return 0;
}
