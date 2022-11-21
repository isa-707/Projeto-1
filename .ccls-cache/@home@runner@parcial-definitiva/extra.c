#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 10

#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define CYN "\e[0;36m"
#define BRED "\e[1;31m"

int arquivogen(float labastecido, float lbombaresto, float gasprice, int carrosatendidos, int capacidade, float lbomba, int carrosnabastecer);

void mensagem1();

struct Tcarro{
  int ano;
  int porte;
  char cor[20];
};

struct Tcarro criaCarro(){

  struct Tcarro aux;
  printf("\nAno do veiculo:\n");
  scanf("%d", &aux.ano);
  printf("\nSelecione o porte do veiculo:\n\n 1 - Pequeno (motos)\n 2 - Medio (carros)\n 3 - Grande (caminhao)\n");
  scanf("%d", &aux.porte);
  getchar();
  printf("\nCor do veiculo:\n");
  fgets(aux.cor, 20, stdin);
  aux.cor[strcspn(aux.cor, "\n")] = 0;
  
  return aux;
}

int main() {

  int fila, escolha, subescolha, carrosatendidos = 0, capacidade = 0, carrosnabastecer = 0;
  float gasprice = 0, lbomba = 0, labastecer = 0, labastecido = 0, lbombaresto = 0;
  int cont;
  struct Tcarro filam[n], filaf[n];
  char clscr;
  
  printf("Autora do programa: Isabela Yasmim Osowski \n\n  Um posto de combustíveis necessita melhorar o processo de gerenciamento de suas informações e para isso conta com seu auxílio no desenvolvimento de um sistema de informação que informatize algumas atividades. \n\n");

  //SETAR PARAMETROS

  //PRECO GASOLINA
  while (gasprice <= 0){
  printf("Valor da gasolina \n");
  scanf("%f", &gasprice);

  if (gasprice <= 0){
    mensagem1();
    }
  }

  //MAX FILA DE CARROS
  while (capacidade <= 0){
  printf("Numero maximos de carros que podem ficar na fila\n");
  scanf("%d", &capacidade);

  if (capacidade <= 0){
    mensagem1();
  }
  fila = 0;
  }

  //LITROS DE GASOLINA
  while (lbomba <= 0){
  printf("Litros de gasolina na bomba\n");
  scanf("%f", &lbomba);
  lbombaresto = lbomba;

  if (lbomba <= 0){
    mensagem1();
  }
  }

  //////////////////////////////MENU//////////////////////////////
  
  while (escolha != 5){

  subescolha += 1;

  clscr = getchar();
  printf("\e[1;1H\e[2J"); //CLEAR SCREEN
    
  //MENU 
  printf("\n\n \t ---- MENU PRINCIPAL ---\n\n \t 1 - Adicionar um carro na fila \n\n \t 2 - Abastecimento \n\n \t 3 - Exibir carros na fila de espera \n\n \t 4 - Relatórios \n\n \t 5 - Encerrar  \n\n");

  scanf("%d", &escolha);

  clscr = getchar();

  printf("\e[1;1H\e[2J"); //CLEAR SCREEN
    
  switch(escolha){
      
    case (1):

      if (fila < capacidade){

      filam[fila] = criaCarro();

      fila ++;
        
      printf(CYN"\n\t Carro adicionado na fila | Numero de carros restantes %d"WHT, fila);
      }
      else{
        printf(RED"\n\tA fila esta cheia"WHT);
      }

    break;

    case (2):
      
      if (fila > 0){

        if (lbombaresto == 0){
          printf(RED"\n\t Sem combustivel restante na bomba\n"WHT);
          printf("\n\t O restante dos carros serao liberados\n");

          for(cont = 0; cont < fila; cont ++){
            filaf[carrosatendidos] = filam[cont];

            carrosatendidos++;
            fila = 0;
            carrosnabastecer++;
          }
        }

        else{
      printf("\n\t O carro recebera quantos litros de combustivel?\n");
      scanf("%f", &labastecer);

      getchar(); // Funcao adicionada para nao entrar em conflito com o clscr no comeco do while
        
        if (labastecer > lbombaresto){
          printf(RED"\n\tNao ha combustivel suficiente na bomba, combustivel restante %.1f \n"WHT, lbombaresto);
        }
      
        if (labastecer > 0 && labastecer <= lbombaresto){

        filaf[carrosatendidos] = filam[0];

        for(cont = 0 ; cont < fila; cont ++){
          filam[cont] = filam[cont + 1];
        }
          
        fila --;
        carrosatendidos ++;
            
        labastecido += labastecer;
        lbombaresto -= labastecer;
        printf(CYN"\n\t Carro atendido | Carros restantes na fila %d\n"WHT, fila);
        }
        
          
            else{
              mensagem1();
            }
        }
        
      }
        
      else{
        printf(CYN"Nenhum carro na fila"WHT);
      }

    break;

    case (3):
      
      printf("\n\t Carros na fila de espera %d\n", fila);

      if (fila > 0){
        
        for(cont = 0; cont < fila; cont ++){
        
        printf(CYN"\n\tCarro numero %d\n\n", cont + 1);
        printf("\n\t Ano do veiculo: %d \n\t Porte do veiculo: %d\n\t Cor do veiculo: %s\n\n"WHT, filam[cont].ano, filam[cont].porte, filam[cont].cor);
      
        }
        
      }

    break;
      
    case (4):

      while (subescolha != 6){

        clscr = getchar();
        printf("\e[1;1H\e[2J"); //CLEAR SCREEN

      ///////////////// SUBMENU /////////////////
        
      printf("\n \t ------------------------------------------------ \n \t 1 - Quantidade de litros vendida \n \t 2 - Valor totalarrecadado com as vendas \n \t 3 - Quantidade e lista de carros atendidos \n \t 4 - Quantidade de combustível restante na bomba \n \t 5 - Gerar arquivo para impressão \n \t 6 - voltar ao menu anterior \n");
      scanf("%d", &subescolha);

        clscr = getchar();
        printf("\e[1;1H\e[2J"); //CLEAR SCREEN
        
      switch (subescolha){
        
          case (1):
            printf("\n\t Litros de combustível vendidos: %.2lf", labastecido);
          break;

          case (2):
            printf("\n\t Valor arrecadado: %.2lf", labastecido * gasprice);
          break;

          case (3):
            printf("\n\t Quantidade de carros atendidos: %d", carrosatendidos);
            printf("\n\t Quantidades de carros atendidos sem abastecer %d\n", carrosnabastecer);

            if (carrosatendidos > 0){

              for(cont = 0; cont < carrosatendidos; cont ++){
        
                  printf(CYN"\n\tCarros numero %d\n", cont + 1);
                  printf("\n\t Ano do veiculo: %d \n\t Porte do veiculo: %d\n\t Cor do veiculo: %s\n\n"WHT, filaf[cont].ano, filaf[cont].porte, filaf[cont].cor);

              }
              
            }
            
          break;

          case (4):
            printf("\n\t Litros de combustível restantes na bomba: %.2lf", lbombaresto);
          break;

          case (5):
            printf("\n\t Arquivo geral dos relatorios:");
            arquivogen(labastecido, lbombaresto, gasprice, carrosatendidos, capacidade, lbomba, carrosnabastecer);
          break;
        
          case (6):
            printf(CYN"\n\t Retornando ao menu anterior..."WHT);
          break;

          default:
            printf(BRED"\n\t Escolha nao reconhecida."WHT);
          }
      }
    break;
    

    case (5):
    printf(BRED"\n\t O programa foi encerrado"WHT);
    break;

    default:
    printf(BRED"\n\t Escolha nao reconhecida."WHT);
    clscr = getchar();
  }
  }
  
  return 0;
}

/// ARQUIVO ///

int arquivogen(float labastecido, float lbombaresto, float gasprice, int carrosatendidos, int capacidade, float lbomba, int carrosnabastecer){

  FILE *fp;

  fp = fopen("relatorio.txt", "w");

  fprintf(fp, "\t ///Arquivo geral de relatorios///\n\n Valor do combustivel: %f \n Tamanho de fila suportada: %d \n Quantidade de litros inicial na bomba: %f \n\n \t ///Subrelatorios/// \n\n Quantidade de litros vendida: %f\n Valor total arrecadado de vendas: %f\n Quantidade de carros atendidos: %d\n Carros atendidos sem abastecer (falta combustivel na bomba): %d \n Quantidade de combustivel restante no tanque: %f", gasprice, capacidade, lbomba, labastecido, labastecido * gasprice, carrosatendidos, carrosnabastecer, lbombaresto);
  
  fclose(fp);

  return 0;
}

/// MENSAGEM DE VALOR INVALIDO ///

void mensagem1(){
    printf(RED"Valor invalido \n"WHT);
    printf("Tente novamente\n\n");
}


