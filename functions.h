#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// ARQUIVO ///

int arquivogen(float labastecido, float lbombaresto, float gasprice,
               int carrosatendidos, int capacidade, float lbomba,
               int carrosnabastecer) {

  FILE *fp;

  fp = fopen("relatorio.txt", "w");

  fprintf(
      fp,
      "\t ///Arquivo geral de relatorios///\n\n Valor do combustivel: %f \n "
      "Tamanho de fila suportada: %d \n Quantidade de litros inicial na bomba: "
      "%f \n\n \t ///Subrelatorios/// \n\n Quantidade de litros vendida: "
      "%.2f\n "
      "Valor total arrecadado de vendas: %.2f\n Quantidade de carros "
      "atendidos: "
      "%d\n Carros atendidos sem abastecer (falta combustivel na bomba): %d \n "
      "Quantidade de combustivel restante no tanque: %.2f",
      gasprice, capacidade, lbomba, labastecido, labastecido * gasprice,
      carrosatendidos, carrosnabastecer, lbombaresto);

  fclose(fp);

  return 0;
}

/// MENSAGEM DE VALOR INVALIDO ///

void mensagem1() {
  printf(RED "Valor invalido \n" WHT);
  printf("Tente novamente\n\n");
}

struct Tcarro criaCarro() {

  struct Tcarro aux;

  printf("\nAno do veiculo:\n");
  scanf("%d", &aux.ano);

  printf("\nSelecione o porte do veiculo:\n\n 1 - Pequeno (motos)\n 2 - Medio "
         "(carros)\n 3 - Grande (caminhao)\n");
  scanf("%d", &aux.porte);
  getchar();

  printf("\nCor do veiculo:\n");
  fgets(aux.cor, 20, stdin);
  aux.cor[strcspn(aux.cor, "\n")] = 0;

  return aux;
}