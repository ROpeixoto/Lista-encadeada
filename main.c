#include <stdio.h>
#include "lista.h"

int main(){
tp_listase *lista, *list;
lista = inicializa_listase();
list = inicializa_listase();

insere_listase_fim(&lista, 10);
insere_listase_fim(&lista, 20);
insere_listase_fim(&lista, 30);
insere_listase_fim(&lista, 40);
insere_listase_fim(&lista, 50);
insere_listase_fim(&lista, 60);
insere_listase_no_inicio(&lista,20);
  


  imprime_listase(lista);
}