#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void plotGraphGNU(double *temposMedios, double *tamanhos, int testes, double a, double b, double c, int j);
void temposMediosGet(double *, int);
void geradorRandom(int *, int, int);
char *porcentagemBarra(int, int, int);
void escreverEmArquivo(double *, int, int, int);
char loading(int i);
void imprimirMat(double **matriz, int lin, int col, int qntDigitos);
