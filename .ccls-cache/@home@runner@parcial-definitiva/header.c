#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define CYN "\e[0;36m"
#define BRED "\e[1;31m"

void mensagem1();
int arquivogen(float labastecido, float lbombaresto, float gasprice, int carrosatendidos, int capacidade, float lbomba, int carrosnabastecer);
struct Tcarro criaCarro();
void imprimirfilas (struct Tcarro filam, struct Tcarro filaf, int cont, int carrosatendidos, int fila);

struct Tcarro {
  int ano;
  int porte;
  char cor[20];
};

