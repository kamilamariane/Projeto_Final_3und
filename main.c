#include <stdio.h>
#include <time.h> 
#include<stdlib.h>

//chamando as funcoes abaixo:
#include "Headers/menu.h"
#include "Headers/escolha.h"

int main(){
    
  srand(time(NULL));
  int operacao;
  FILE*file;
  FILE *fileout;

  do{
    menu();
    printf("Digite sua operação: ");
    scanf("%d", &operacao);
    escolha(operacao);
  }while(operacao != 16);
  
  return 0;
}
