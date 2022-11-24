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
      "\t ///Arquivo geral de relatórios///\n\n Valor do combustível: %f \n "
      "Tamanho de fila suportada: %d \n Quantidade de litros inicial na bomba: "
      "%f \n\n \t ///Subrelatórios/// \n\n Quantidade de litros vendida: "
      "%.2f\n "
      "Valor total arrecadado de vendas: %.2f\n Quantidade de carros "
      "atendidos: "
      "%d\n Carros atendidos sem abastecer (falta combustível na bomba): %d \n "
      "Quantidade de combustível restante no tanque: %.2f",
      gasprice, capacidade, lbomba, labastecido, labastecido * gasprice,
      carrosatendidos, carrosnabastecer, lbombaresto);

  fclose(fp);

  return 0;
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