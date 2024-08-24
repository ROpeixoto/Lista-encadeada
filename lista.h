#ifndef LISTASE_H
#define LISTASE_H
#include <stdio.h>
#include <stdlib.h>
//PEDALA CUIDADO COM O REPLIT 8===============D
typedef int tp_item;

typedef struct tp_no{
tp_item info;
struct tp_no *prox;

}tp_listase;

tp_listase * inicializa_listase(){
return NULL;
}

int listase_vazia(tp_listase *lista){
  if(lista==NULL) return 1;
  return 0;
}

tp_listase * aloca_listase(){
  tp_listase *novo_no;
  novo_no=(tp_listase*) malloc(sizeof(tp_listase));
  
  return novo_no;
}

int insere_listase_fim(tp_listase **l, tp_item e){
  tp_listase *novo_no, *atu;
  novo_no = aloca_listase();
  if(novo_no == NULL) return 0;
  novo_no->info= e;
  novo_no->prox=NULL;

  if(listase_vazia(*l)){
    *l=novo_no;
  }else{
      atu=*l;
    while(atu->prox!=NULL){
      atu=atu->prox;
    }
    atu->prox=novo_no;
  }
  return 1;
}
    
 void imprime_listase(tp_listase *lista){
   tp_listase *atu;
   atu=lista;
   while (atu!= NULL){
     printf("%d\n", atu->info);
     atu=atu->prox;
   }
 }
  
int remove_listase(tp_listase **lista, tp_item e){
  tp_listase *ant, *atu;
  atu = *lista;
  ant = NULL;
  while ((atu != NULL)&&(atu->info!=e)){
    ant=atu;
    atu=atu->prox;
}
if(atu==NULL) return 0;
if(ant==NULL){
  *lista = atu->prox;
}
else{
  ant->prox=atu->prox;
}
free(atu);
atu=NULL;
return 1;
}

tp_listase *busca_listase(tp_listase *lista, tp_item e){
  tp_listase *atu;
  atu=lista;
  while((atu!=NULL)&&(atu->info!=e)){
    atu=atu->prox;
  }
  if(atu==NULL) return NULL;
  return atu;
}

int tamanho_listase(tp_listase *lista){
  int cont=0;
  tp_listase *atu;
  atu=lista;
  while(atu!=NULL){
    cont++;
      atu=atu->prox;
  }
  return cont;
}

void destroi_listase(tp_listase **l){
  tp_listase *atu;
  atu= *l;
  while(atu!=NULL){
    *l=atu->prox;
    free(atu);
    atu=*l;
  }
  *l=NULL;
}

int maior_que_listase(tp_listase *lista, int e){
  int cont=0;
  tp_listase *atu;
  atu=lista;
 while(atu!=NULL){
   if(atu->info > e){
    cont++;
   }
      atu=atu->prox;
  }
  return cont;
}

int igual_listas(tp_listase *lista, tp_listase *list){
  int cont=0, cont2=0;
  tp_listase *atu, *atuu;
  atu=lista;
  atuu=list;
  while(atu!=NULL){
    cont++;
      atu=atu->prox;
  }
  while(atuu!=NULL){
    cont2++;
      atuu=atuu->prox;
  }
  if (cont != cont2){
    printf("as listas tem tamanhos diferentes");
    return 0;
  }
  
  atu=lista;
  atuu=list;
  
  while((atu!=NULL) && (atuu!=NULL)){
    if(atu -> info != atuu -> info){
      return 0;
    }
    atu=atu->prox;
    atuu=atuu->prox;
  }
  return 1;
}

void eliminacao(tp_listase *lista, int x){
  int cont=0;
  tp_listase *atu,*next;
  atu=lista;
  next=lista;
    
  while(tamanho_listase(lista)>1){
  while(next->prox !=NULL){
    next = next ->prox ;
    }
    next->prox = lista;
    cont++;
  if (cont==x){
    remove_listase(&lista, next->info);
  }
    cont=0;
    next=next->prox;
  }
}

int insere_listase_no_inicio(tp_listase **lista, tp_item e){
  tp_listase *novo_no;
  novo_no = aloca_listase();
  if(novo_no == NULL) return 0;
  novo_no->info = e;
  if(listase_vazia(*lista)){
    novo_no->prox = NULL;
  } else novo_no->prox = *lista;
  *lista = novo_no;
  
return 1;
}

#endif