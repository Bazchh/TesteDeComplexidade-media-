#include <stdio.h>
#include <stdlib.h>
#include "MetodoGradienteAdaptativo.c"
void primeiroGrau(double *a, double *b, double *y, double *x, int qntPontos, double taxaDeAprendizado);
double func(double a, double b, double x);
double DfuncA(double a, double b, double x);
double DfuncB(double a, double b, double x);
void segundoGrau(double *a, double *b, double c, double *y, double *x, int qntPontos, double taxaDeAprendizado);
double funcq(double a, double b, double x, double c);
double DfuncAq(double a, double b, double x, double c);
double DfuncBq(double a, double b, double x, double c);
double DfuncCq(double a, double b, double x, double c);
void logn(double *a, double *b, double *y, double *x, int qntPontos, double taxaDeAprendizado);
double DfunclogB(double a, double b, double x);
double DfunclogA(double a, double b, double x);
double funclog(double a, double b, double x);