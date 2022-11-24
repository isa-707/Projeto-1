#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define CYN "\e[0;36m"
#define BRED "\e[1;31m"
#define GRN "\e[0;32m"

struct Tcarro {
  int ano;
  int porte;
  char cor[20];
};

void mensagem1();
void arquivogen(float labastecido, float lbombaresto, float gasprice, int carrosatendidos, int capacidade, float lbomba, int carrosnabastecer, struct Tcarro filam[], struct Tcarro filaf[], int fila);
struct Tcarro criaCarro();


