#include <stdio.h>
#include <string.h>

/* tem alguma forma de fazer o programa parar estando dentro de uma outra função que não a main? posso fazer goto.  Tem alguma espécie de throw error*/

/*
Vou tentar colocar o tamanho pra ser um limitador e se chegarmos ao limite, o código terminou com êxito.
*/

int q0(char* str, int pos, int tam);

int q1(char* str, int pos, int tam);
  
int q2(char* str, int pos, int tam);

//Talvez seria melhor preencher com \000
void preencheComBarraN(char* str, int tam);

//depois verificar o que aconteceria se colocasse como void,
//e a relação com o if
int verificaSeChegouAoFinal(int tam, int pos);

int main() {
  
/*
É importante que não haja lixo de memória. Por isso, preencher com '\n'.
Por exemplo, se colocarmos "A78", mas nas posições 3 a 5 tiver esse lixo
de memória: "A&*", vai dizer que não pertence à linguagem. Porém, acho
que o limitador de tamanho já cuida desse trabalho.
*/
  char str[8] = {};
  
  preencheComBarraN(str, 8);
  
  printf("Digite a cadeia a ser testada pelo autômato: ");
  scanf("%s", &str);
int tam_str = strlen(str);
  
  if(0 <= tam_str && tam_str<=8){
    //nada vai recebrr o retorno dessa função? Como efetivar que o codigo funciona?
    q0(str, 0, tam_str);
        
  }
  else{
    //erro
    printf("Erro: cadeia de tamanho maior que 8");
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
    //Verificar se precisa colocar pos++ aqui
    printf("ERRO: Q0 <= str[%d] = %c. A primeira posicao deve ser uma letra maiuscula\n", pos, str[pos]);
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
    printf("ERRO: Q1 <= str[%d] = %c. A segunda posição deve ser um algarismo", pos, str[pos]);
  }
}

//Ver se posso chamar q2 dentro de 
//q2. se não, posso criar um q3
// igual a q2 e fazer com que um 
//chame o outro
/* O que vai dizer wue não tem mais
de 8 símbolos vai ser o strlen.
mas, posso transformar isso em um estado?*/

/*Penso que depois de q1, a verificação vai ser  mesma.*/ 

int q2(char* str, int pos, int tam){
  int eAlfabeticoMai = str[pos] >= 'A' && str[pos] <= 'Z';
  int eAlfabeticoMin = str[pos] >= 'a' && str[pos] <= 'z';
  int eNumerico = str[pos] >= '0' && str[pos] <= '9';
  int eEspecialPermit = ( str[pos] == '@' || str[pos] == '*' || str[pos] == '_' || str[pos] == '-' || str[pos] == '#');
/*Aqui havia um problema, pois
vai rodar o if ainda que
o verificaSeChegouAoFinal() for verdadeiro.
Posso colocar dentro de um if, ainda que seja estranho. 
mas, pelo menos vai resolver esse problema
e se for uma inconsistência, penso ser uma inconsistência menor
*/

  if(verificaSeChegouAoFinal(tam, pos));

  else if(eAlfabeticoMai || eAlfabeticoMin || eNumerico || eEspecialPermit){
    
    //Colocar a informação da posição e que é Alfanumérico ou pertencente aos simbolos especiais permitidos
    printf("Q2 <= str[%d] = %c\n", pos, str[pos]);
    pos++;
    q2(str, pos, tam);
  }
  else{
    printf("ERRO: Q2 <= str[%d] = %c. Da terceira posicao em diante deve ser uma letra do alfabeto, um algarismo ou um dos simbolos '@', '*', '_', '-', '#'\n", pos, str[pos]);
  }
}

int verificaSeChegouAoFinal(int pos, int tam){
  if(pos == tam){
    //lidar com o êxito
    
    /*esse return está sendo posto só por uma questão sintática, pois 
    mesmo que iremos aqui já direcionar para o acerto não chegando a processar
    o
    estou colocando esa função em um if*/
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

/*
Posso fazer certos numeros wue se referem a tipos de erros e tratá-los na saída do q0

o problema é que não é um tratamento imediato, e vejo isso como problemático.

de toda forma, teria um switch case para cada tipo de erro qie foi retornado ao final de q0
    
*/

/*
Estou achando problemática essa forma 
usando o tamanho para verificar se já chegou ao final
porque parece que esse tamanho está sendo passado para vários escopos.
pensei que talvez fosse um problema com relação à memória,
mas acho que seria um problema
mais com relação à inconsistência
nessas passagens entre escopos.
*/

/*
O que queria fazer era sair de todas essas funções
aninhadas assim que chegasse ao final, assim, isso não seria um problema. mas é uma inconsistência que pode gerar um problema.
*/