#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/// ARQUIVO ///

void arquivogen(float labastecido, float lbombaresto, float gasprice,
               int carrosatendidos, int capacidade, float lbomba,
               int carrosnabastecer, struct Tcarro filam[], struct Tcarro filaf[], int fila) {

  FILE *fp;

  fp = fopen("relatorio.txt", "w");

  fprintf(fp, "\n\t ///Arquivo geral de relatórios///\n\n Valor do combustível: %f \n "
      "Tamanho de fila suportada: %d \n Quantidade de litros inicial na bomba: "
      "%f \n\n \t ///Subrelatórios/// \n\n Quantidade de litros vendida: "
      "%.2f\n "
      "Valor total arrecadado de vendas: %.2f\n Quantidade de carros "
      "atendidos: "
      "%d\n Carros atendidos sem abastecer (falta combustível na bomba): %d \n "
      "Quantidade de combustível restante no tanque: %.2f",
      gasprice, capacidade, lbomba, labastecido, labastecido * gasprice,
      carrosatendidos, carrosnabastecer, lbombaresto);

  fprintf(fp, "\n\n==============================================\n");

  fprintf(fp, "\n\t /// Carros na fila /// \n");
  for (int cont = 0; cont < fila; cont ++){
    fprintf(fp, "\n\tCarro número %d\n", cont + 1);
    fprintf(fp, "\n\t Ano do veículo: %d \n\t Porte do veículo: %d\n\t Cor do veículo: %s\n\n",
                 filam[cont].ano, filam[cont].porte, filam[cont].cor);
  }

  fprintf(fp, "\n\t /// Carros atendidos /// \n");
  for (int cont = 0; cont < carrosatendidos; cont ++){
    fprintf(fp, "\n\tCarro número %d\n", cont + 1);
    fprintf(fp, "\n\t Ano do veículo: %d \n\t Porte do veículo: %d\n\t Cor do veículo: %s\n\n",
                 filaf[cont].ano, filaf[cont].porte, filaf[cont].cor);
  }
  
  fclose(fp);

}

/// MENSAGEM DE VALOR INVALIDO ///

void mensagem1() {
  printf(RED "\nValor inválido \n" WHT);
  printf("Tente novamente\n\n");
}

struct Tcarro criaCarro() {

  struct Tcarro aux;

  printf("\nAno do veículo:\n");
  scanf("%d", &aux.ano);

  printf("\nSelecione o porte do veículo:\n\n 1 - Pequeno (motos)\n 2 - Médio "
         "(carros)\n 3 - Grande (caminhão)\n");
  scanf("%d", &aux.porte);
  getchar();

  printf("\nCor do veículo:\n");
  fgets(aux.cor, 20, stdin);
  aux.cor[strcspn(aux.cor, "\n")] = 0;

  return aux;
}