#include <stdio.h>
#include <stdlib.h>
#define nome "Funcionarios.txt"

int qtyPessoas();//ok
void NomeVogeCons();//ok
int* Idades();//ok
void MaiorMenor();//ok
void PrintNome(int n);//ok
void MediaIdade();//ok
float *Salarios();//ok
int MaiorSalario();//ok
void PessoaMaiorSalario();//ok
void PrintSexo(int n);//ok
void SexoPessoaMaiorSalario();//ok
int MaiorSobrenome();//ok
void PrintIdadeMaiorSobrenome();//ok

int main(void) {
  int cont = qtyPessoas();
  printf("\nO total de pessoas no arquivo é: %d",cont);
  NomeVogeCons();
  Idades();
  MaiorMenor();
  MediaIdade();
  Salarios();
  PessoaMaiorSalario();
  SexoPessoaMaiorSalario();
  PrintIdadeMaiorSobrenome();
  return 0;
}
int qtyPessoas(){
  char buffer[4097];
  FILE *arq;
  arq = fopen(nome,"r");
  int cont = 0;
  for(; cont < 100;){
    if(feof(arq)){
      break;
    }else{
      fgets(buffer, 4096, arq);
      cont++;
    }
  }
  fclose(arq);
  return cont;
}
void NomeVogeCons(){
  char buffer[4097];
  FILE *arq;
  arq = fopen(nome,"r");
  char vogais[] = "aeiouAEIOU";
  int TotVogal = 0,cont = 0;
  for(; cont < 100;){
    if(feof(arq)){
      break;
    }else{
      fgets(buffer, 4096, arq);
      for(int x = 0; x < 10;x++){
        if(vogais[x] == buffer[0]){
          TotVogal++;
        }
      }
      cont++;
    }
  }
  fclose(arq);
  int TotCons = qtyPessoas() - TotVogal;
  printf("\nTotal de pessoas com vogal na inicial do nome: %d\nTotal de pessoas com consoante na inicial do nome: %d\n",TotVogal,TotCons);
}
int* Idades(){
  FILE *arq;
  arq = fopen(nome,"r");
  char buffer[4097];
  int qty = qtyPessoas();
  int *idade = malloc(qty*sizeof(int));
  int cont = 0,cont2 = 0,espaco = 0,cont3 = 0;
  char idad[5];
  for(; cont < 100;){
    if(feof(arq)){
      break;
    }else{
      fgets(buffer, 4096, arq);
      while(1){
        if(buffer[cont2] == ' '){
          espaco++;
        }if(espaco == 4){
          if(buffer[cont2] == '\0'){
            break;
          }else{
          idad[cont3] = buffer[cont2];
          cont2++;
          cont3++;
          }
        }else{
          cont2++;
        }
      }
      idade[cont] = atoi(idad);
      cont++;
      cont2 = 0;
      espaco = 0;
      cont3 = 0;
    }
  }
  fclose(arq);
  return idade;
}
void MaiorMenor(){
  int valor, index1 = 0,index2 = 0,*idades,qty = qtyPessoas();
  idades = Idades();
  valor = idades[0];
  for(int i = 1; i < qty; i++){
    if(idades[i] < valor){
        valor = idades[i];
        index1 = i;
    }
  }
  valor = idades[0];
  for(int i = 1; i < qty; i++){
    if(idades[i] > valor){
        valor = idades[i];
        index2 = i;
    }
  }
  printf("A pessoa mais jovem é: ");
  PrintNome(index1);
  printf("\nA pessoa mais velha é: ");
  PrintNome(index2);
}
void PrintNome(int n){
  char buffer[4097];
  FILE *arq;
  arq = fopen(nome,"r");
  int cont = 0,cont2 = 0;
  for(; cont < 100;){
    if(feof(arq)){
      break;
    }else{
      fgets(buffer, 4096, arq);
      if(cont == n){
        for(int i = 0; buffer[i] != ' ';i++){
          printf("%c",buffer[i]);
        }
        break;
      }
      cont++;
    }
  }
  fclose(arq);
}
void MediaIdade(){
  int media = 0;
  int qty = qtyPessoas();
  int *idades = Idades();
  for(int i = 0; i < qty;i++){
    media += idades[i];
  }
  media = media/qty;
  printf("\nA média das idades foi de: %d",media);
}
float *Salarios(){
  FILE *arq;
  arq = fopen(nome,"r");
  char buffer[4097];
  int qty = qtyPessoas();
  float *salarios = malloc(qty*sizeof(float));
  int cont = 0,cont2 = 0,espaco = 0,cont3 = 0;
  char sala[5];
  for(; cont < 100;){
    if(feof(arq)){
      break;
    }else{
      fgets(buffer, 4096, arq);
      for(;buffer[cont2] != '\0';){
        if(buffer[cont2] == ' '){
          espaco++;
        }if(espaco == 2){
          cont2++;
          if(buffer[cont2] == ' '){
            break;
          }else{
            sala[cont3] = buffer[cont2];
            cont3++;
          }
        }else{
          cont2++;
        }
      }
      salarios[cont] = atof(sala);
      cont++;
      cont2 = 0;
      espaco = 0;
      cont3 = 0;
    }
  }
  fclose(arq);
  return salarios;
}
int MaiorSalario(){
  float *salarios = Salarios();
  float maior;
  int index = 0,qty = qtyPessoas();
  maior = salarios[0];
  for(int i = 1; i < qty;i++){
    if(salarios[i] > maior){
        maior = salarios[i];
        index = i;
    }
  }
  return index;
}
void PessoaMaiorSalario(){
  int i = MaiorSalario();
  printf("\nO nome da pessoa com maior salário é: ");
  PrintNome(i);
}
void SexoPessoaMaiorSalario(){
  int i = MaiorSalario();
  printf("\nO sexo da pessoa com maior salário é: ");
  PrintSexo(i);
}
void PrintSexo(int n){
  FILE *arq;
  arq = fopen(nome,"r");
  char c;
  int cont = 0,espaco = 0;
  while((c = getc(arq)) != EOF){ 
    if(c == '\n'){
      cont++;
    }else if(cont == n){
      if(c == ' '){
        espaco++;
      }else if(espaco == 3){
        printf("%c",c);
      }
    }
  }
  printf("\n");
  fclose(arq);
}
int MaiorSobrenome(){
  FILE *arq;
  arq = fopen(nome,"r");
  int qty = qtyPessoas();
  int sobrenome[qty];
  char letra;
  int cont = 0, espaco = 0,cont2 = 0,i = 0;
  while((letra = getc(arq)) != EOF){
    if(letra == '\n'){
      sobrenome[cont] = i;
      cont++;
      espaco = 0;
      i = 0;
    }else if(letra == ' '){
      espaco++;
    }else if(espaco == 1){
      if(letra != ' '){
        i++;
      }
    }
  }
  sobrenome[cont] = i;
  fclose(arq);
  int maior = sobrenome[0];
  int index = 0;
  for(int x = 1; x < qty;x++){
    if(sobrenome[x] > maior){
      maior = sobrenome[x];
      index = x;
    }
  }
  return index;
}
void PrintIdadeMaiorSobrenome(){
  int i = MaiorSobrenome();
  int *idades = Idades();
  printf("A idade da pessoa com maior sobrenome é: %d",idades[i]);
}