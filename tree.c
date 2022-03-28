#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;


Arvore*  cria_arv_vazia ();
Arvore*  arv_constroi (char c, Arvore* e, Arvore* d);
int      verifica_arv_vazia (Arvore* a);
Arvore*  arv_libera (Arvore* a);
int      arv_pertence (Arvore* a, char c);
void     arv_imprime (Arvore* a);
int conta_nos(Arvore *a);
char max_arvore(Arvore *a);
int altura_arvore(Arvore *a);
int nos_folha_arvore(Arvore *a);

Arvore* cria_arv_vazia () {
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

void arv_imprime (Arvore* a){
  if(a == NULL) {
    printf(" <> ");
    return;
  }
  printf(" < %c", a->info);
  arv_imprime(a->esq);
  arv_imprime(a->dir);
  printf(" > ");  
}

int arv_pertence(Arvore* a,char c){
  if(a == NULL) return 0;
  if(a->info == c) return 1;  
  if(arv_pertence(a->esq,c)) return 1;
  if(arv_pertence(a->dir,c)) return 1;
}

int conta_nos(Arvore *a){
  if(a == NULL) return 0;
  int dir, izq;
  dir = conta_nos(a->dir);
  izq = conta_nos(a->esq);
  return (dir+izq+1);
}

char max_arvore(Arvore *a){
  if(a == NULL) return 0;
  char ini = a->info;
  char esq,dir;
  esq = max_arvore(a->esq);
  dir = max_arvore(a->dir);

  if((ini > esq) && (ini > dir)) return ini;
  if((esq > ini) && (esq > dir)) return esq;
  if((dir > ini) && (dir > ini)) return dir;
}
int altura_arvore(Arvore *a){
  if(a == NULL) return 0;
  int esq = altura_arvore(a->esq);
  int dir = altura_arvore(a->dir);
  if(esq > dir) return (esq +1);
  else return (dir + 1);
}

int nos_folha_arvore(Arvore *a){
  if(a == NULL) return 0;
  if(a->dir == NULL && a->esq == NULL) return 1;
  int esq = nos_folha_arvore(a->esq);
  int dir = nos_folha_arvore(a->dir);  
  return (esq + dir);
}


int main (int argc, char *argv[]) {
  Arvore *a, *a1, *a2, *a3, *a4, *a5;
  char c;
  int p,f;
  a1 = arv_constroi('d',cria_arv_vazia(),cria_arv_vazia());
  a2 = arv_constroi('b',cria_arv_vazia(),a1);
  a3 = arv_constroi('e',cria_arv_vazia(),cria_arv_vazia());
  a4 = arv_constroi('f',cria_arv_vazia(),cria_arv_vazia());
  a5 = arv_constroi('c',a3,a4);
  a  = arv_constroi('a',a2,a5);
  // imprime o arvore
  arv_imprime(a);
  printf("\n Digita um caracter: ");
  scanf("%c",&c);
  printf("o valor de %c e %d\n",c,c);
  // retorna se um elemnto esta o no no arvore
  p = arv_pertence(a,c);
  if(p == 1) printf("|-> %c pertence ao arvore\n",c);
  else printf("|-> %c Nao pertence ao arvore\n",c);
  // conta os nos do arvore
  p = conta_nos(a);
  printf("|-> %d nos em total\n",p);
  // retorna o maximo valor do arvore
  c = max_arvore(a);
  printf("|-> O maximo valor no arvore e %c\n",c);
  // altura do arvore
  p = altura_arvore(a);
  printf("|-> A altura do arvore e : %d\n",p);
  // nos que sao folha
  f = nos_folha_arvore(a);
  printf("|-> A quantidade de nos folha no arvore e : %d\n",f);
  return 0;
}
