#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {

  int fila, escolha, subescolha, carrosatendidos = 0, capacidade = 0, carrosnabastecer = 0, n = 1;
  float gasprice = 0, lbomba = 0, labastecer = 0, labastecido = 0, lbombaresto = 0;
  int cont;
  struct Tcarro *filam, *filaf;
  char clscr;

  printf("Autora do programa: Isabela Yasmim Osowski \n\n  Um posto de "
         "combustíveis necessita melhorar o processo de gerenciamento de suas "
         "informações e para isso conta com seu auxílio no desenvolvimento de "
         "um sistema de informação que informatize algumas atividades. \n\n");

  // SETAR PARAMETROS

  // PRECO GASOLINA
  while (gasprice <= 0) {
    printf("Valor da gasolina \n");
    scanf("%f", &gasprice);

    if (gasprice <= 0) {
      mensagem1();
    }
  }

  // MAX FILA DE CARROS
  while (capacidade <= 0) {
    printf("Número de carros que podem ficar na fila\n");
    scanf("%d", &capacidade);

    if (capacidade <= 0) {
      mensagem1();
    }
    fila = 0;
  }

  filam = (struct Tcarro *)malloc(capacidade * sizeof(struct Tcarro));
  filaf = (struct Tcarro *)malloc(n * sizeof(struct Tcarro));

  // LITROS DE GASOLINA
  while (lbomba <= 0) {
    printf("Litros de gasolina na bomba\n");
    scanf("%f", &lbomba);
    lbombaresto = lbomba;

    if (lbomba <= 0) {
      mensagem1();
    }
  }

  //////////////////////////////MENU//////////////////////////////

  while (escolha != 5) {
    subescolha += 1;
    clscr = getchar();
    printf("\e[1;1H\e[2J"); // CLEAR SCREEN

    // MENU
    printf("\n\n \t ---- MENU PRINCIPAL ---\n\n \t 1 - Adicionar um carro na "
           "fila \n\n \t 2 - Abastecimento \n\n \t 3 - Exibir carros na fila "
           "de espera \n\n \t 4 - Relatórios \n\n \t 5 - Encerrar  \n\n");

    scanf("%d", &escolha);

    clscr = getchar();

    printf("\e[1;1H\e[2J"); // CLEAR SCREEN

    switch (escolha) {

    case (1):

      if (lbombaresto == 0) {
        printf(RED "\nNão há combustível restante na bomba, não é possível admitir mais carros\n" WHT);
      } else {
        if (fila < capacidade) {

          filam[fila] = criaCarro();

          fila++;

          printf(CYN "\n\t Carro adicionado na fila | Número de carros em espera %d" WHT,
                 fila);
        } else {
          printf(RED "\n\tA fila está cheia" WHT);
        }
      }

      break;

    case (2):

    if (fila == 0) {

    printf(CYN "Nenhum carro na fila" WHT);
    
    }
    else{
      if (lbombaresto == 0) {
        
          printf(RED "\n\t Sem combustível restante na bomba\n" WHT);
          printf("\n\t O restante dos carros serão liberados\n");

          for (cont = 0; cont <= fila; cont++) {

            n++;
            filaf = (struct Tcarro *)realloc(filaf, n * sizeof(struct Tcarro));

            filaf[carrosatendidos] = filam[cont];

            carrosatendidos++;
            fila --;
            carrosnabastecer++;
          }
          fila = 0;
      }
      else{
          printf("\n\t O carro receberá quantos litros de combustível?\n");
          scanf("%f", &labastecer);

          getchar(); // Funcao adicionada para nao entrar em conflito com o clscr no comeco do while
        
        if (labastecer > lbombaresto) {
          
            printf(RED "\n\t Não há combustível suficiente na bomba, combustível restante %.1f \n" WHT, lbombaresto);
          
          }
          else{

            if (labastecer > 0 && labastecer <= lbombaresto) {

            filaf[carrosatendidos] = filam[0];

            n++;
            filaf = (struct Tcarro *)realloc(filaf, n * sizeof(struct Tcarro));

            for (cont = 0; cont < fila; cont++) {
              filam[cont] = filam[cont + 1];
            }

            fila--;
            carrosatendidos++;

            labastecido += labastecer;
            lbombaresto -= labastecer;
            printf(CYN "\n\t Carro atendido | Carros restantes na fila %d\n" WHT, fila);
              }
              else {
              mensagem1();
              }
          }
        }
            
        }

    break;
      
    case (3):

      printf("\n\t Carros na fila de espera %d\n", fila);

      if (fila > 0) {

        for (cont = 0; cont < fila; cont++) {

          printf(CYN "\n\tCarro número %d\n\n", cont + 1);
          printf("\n\t Ano do veículo: %d \n\t Porte do veículo: %d\n\t Cor do veículo: %s\n\n" WHT,
                 filam[cont].ano, filam[cont].porte, filam[cont].cor);
        }
      }

      break;

    case (4):

      while (subescolha != 6) {

        clscr = getchar();
        printf("\e[1;1H\e[2J"); // CLEAR SCREEN

        ///////////////// SUBMENU /////////////////

        printf(
            "\n \t ------------------------------------------------ \n \t 1 - "
            "Quantidade de litros vendida \n \t 2 - Valor totalarrecadado com "
            "as vendas \n \t 3 - Quantidade e lista de carros atendidos \n \t "
            "4 - Quantidade de combustível restante na bomba \n \t 5 - Gerar "
            "arquivo para impressão \n \t 6 - voltar ao menu anterior \n");
        scanf("%d", &subescolha);

        clscr = getchar();
        printf("\e[1;1H\e[2J"); // CLEAR SCREEN

        switch (subescolha) {

        case (1):
          printf("\n\t Litros de combustível vendidos: %.2lf", labastecido);
          break;

        case (2):
          printf("\n\t Valor arrecadado: %.2lf", labastecido * gasprice);
          break;

        case (3):
          printf("\n\t Quantidade de carros atendidos: %d", carrosatendidos);
          printf("\n\t Quantidades de carros atendidos sem abastecer %d\n",
                 carrosnabastecer);

          if (carrosatendidos > 0) {

            for (cont = 0; cont < carrosatendidos; cont++) {

              printf(CYN "\n\tCarros número %d\n", cont + 1);
              printf("\n\t Ano do veículo: %d \n\t Porte do veículo: %d\n\t "
                     "Cor do veículo: %s\n\n" WHT,
                     filaf[cont].ano, filaf[cont].porte, filaf[cont].cor);
            }
          }

          break;

        case (4):
          printf("\n\t Litros de combustível restantes na bomba: %.2lf",
                 lbombaresto);
          break;

        case (5):
          printf("\n\t Arquivo geral dos relatórios:");
          arquivogen(labastecido, lbombaresto, gasprice, carrosatendidos,
                     capacidade, lbomba, carrosnabastecer, filam, filaf, fila);
          break;

        case (6):
          printf(CYN "\n\t Retornando ao menu anterior..." WHT);
          break;

        default:
          printf(BRED "\n\t Escolha não reconhecida." WHT);
        }
      }
      break;

    case (5):
      printf(BRED "\n\t O programa foi encerrado" WHT);
      break;

    default:
      printf(BRED "\n\t Escolha não reconhecida." WHT);
      clscr = getchar();
    }
  }

  return 0;
}
