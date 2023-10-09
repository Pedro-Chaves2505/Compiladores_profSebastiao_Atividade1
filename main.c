#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int q0(char* str, int pos, int tam);

int q1(char* str, int pos, int tam);
  
int q2(char* str, int pos, int tam);

void preencheComBarraN(char* str, int tam);

void tratementoError(int error, char* str, int pos);

int verificaSeChegouAoFinal(int tam, int pos);

int main() {
  system("clear");
  system("CLS");
  
  char str[8] = {};
  
  preencheComBarraN(str, 8);
  
  printf("Digite a cadeia a ser testada pelo autômato: ");
  scanf("%s", &str);
int tam_str = strlen(str);
  
  if(0 <= tam_str && tam_str<=8){
    q0(str, 0, tam_str);
        
  }
  else{
    //erro
    tratementoError(3, str, 0);
    return 1;
  }

  return 0;
}

int q0(char* str, int pos, int tam)
{
  if(verificaSeChegouAoFinal(pos, tam)){
  }
  else if(str[pos] >= 'A' && str[pos] <= 'Z'){
   printf("Q0 <= str[%d] = %c\n", pos, str[pos]);
   pos++;
   q1(str, pos, tam);    
  }
  else{
    tratementoError(0, str, pos);
  }
}

int q1(char* str, int pos, int tam){
  if(verificaSeChegouAoFinal(pos, tam)){
  }

  else if(str[pos] >= '0' && str[pos] <= '9'){
    printf("Q1 <= str[%d] = %c\n", pos, str[pos]);
    pos++;
    q2(str, pos, tam);
  }

  else{
    tratementoError(1, str, pos);
  }
}


int q2(char* str, int pos, int tam){
  int eAlfabeticoMai = str[pos] >= 'A' && str[pos] <= 'Z';
  int eAlfabeticoMin = str[pos] >= 'a' && str[pos] <= 'z';
  int eNumerico = str[pos] >= '0' && str[pos] <= '9';
  int eEspecialPermit = ( str[pos] == '@' || str[pos] == '*' || str[pos] == '_' || str[pos] == '-' || str[pos] == '#');

  if(verificaSeChegouAoFinal(tam, pos));

  else if(eAlfabeticoMai || eAlfabeticoMin || eNumerico || eEspecialPermit){
    
    //Colocar a informação da posição e que é Alfanumérico ou pertencente aos simbolos especiais permitidos
    printf("Q2 <= str[%d] = %c\n", pos, str[pos]);
    pos++;
    q2(str, pos, tam);
  }
  else{
    tratementoError(2, str, pos);
  }
}

int verificaSeChegouAoFinal(int pos, int tam){
  if(pos == tam){
    //lidar com o êxito
    
    printf("Sucesso\n");
    return 1;
  }
  else{
    return 0;
  }
}

void preencheComBarraN(char* str, int tam){
  int i = 0;
  for(i=0; i<tam; i++){
    str[i] = '\n';
  }
}

void tratementoError(int error, char* str, int pos){
  switch (error)
  {
  case 0:
    printf("ERRO: Q0 <= str[%d] = %c. A primeira posicao deve ser uma letra maiuscula\n", pos, str[pos]);
    break;

  case 1:
    printf("ERRO: Q1 <= str[%d] = %c. A segunda posição deve ser um algarismo", pos, str[pos]);
    break;

  case 2:
    printf("ERRO: Q2 <= str[%d] = %c. Da terceira posicao em diante deve ser uma letra do alfabeto, um algarismo ou um dos simbolos '@', '*', '_', '-', '#'\n", pos, str[pos]);
    break;

  case 3:
    printf("Erro: cadeia de tamanho maior que 8");
    break;
  
  }
}

