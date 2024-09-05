#include <stdio.h>
#include <math.h>

// Derivadas para O(n)

double func(double a, double b, double x)
{
    return a * x + b;
}

double DfuncA(double a, double b, double x)
{
    return -x;
}
double DfuncB(double a, double b, double x)
{
    return -1;
}

double funcq(double a, double b, double x, double c)
{
    return a * (pow(x, 2)) + b * x + c;
}

void primeiroGrau(double a, double b, double *y, double *x, int qntPontos, double taxaDeAprendizado)
{
    double erro = 1e5;
    double erroa = 0;
    double dA, dB, r;
    int count = 0;
    double theta = 1e-8;
    while ((fabs(erro - erroa) / erro) > 0.01)
    {
        erroa = erro;
        erro = 0;
        for (int i = 0; i < qntPontos; i++)
        {
            erro += pow(y[i] - func(a, b, x[i]), 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {

            dA += (taxaDeAprendizado * ((y[i] - func(a, b, x[i])) * DfuncA(a, b, x[i]))) / (theta + r);
            dB += (taxaDeAprendizado * ((y[i] - func(a, b, x[i])) * DfuncB(a, b, x[i]))) / (theta + r);
        }
        a -= dA;
        b -= dB;
        count++;
        printf("\na = %.3f, b = %.3f, erro = %.3f\n", a, b, erro);
    }

    printf("\n%i", count);
}

// Derivadas para O(n**2)

double DfuncAq(double a, double b, double x, double c)
{
    return -2 * a * x;
}

double DfuncBq(double a, double b, double x, double c)
{
    return -x;
}

double DfuncCq(double a, double b, double x, double c)
{
    return 0;
}

void segundoGrau(double a, double b, double c, double *y, double *x, int qntPontos, double taxaDeAprendizado)
{
    double erro = 1e5;
    double erroa = 0;
    double dA, dB, dC, r;
    int count = 0;
    double theta = 1e-8;
    while ((fabs(erro - erroa) / erro) > 0.01)
    {
        erroa = erro;
        erro = 0;
        for (int i = 0; i < qntPontos; i++)
        {
            erro += pow(y[i] - funcq(a, b, x[i], c), 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = dC = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {

            dA += (taxaDeAprendizado * ((y[i] - funcq(a, b, x[i], c)) * DfuncAq(a, b, x[i], c))) / (theta + r);
            dB += (taxaDeAprendizado * ((y[i] - funcq(a, b, x[i], c)) * DfuncBq(a, b, x[i], c))) / (theta + r);
            dC += (taxaDeAprendizado * ((y[i] - funcq(a, b, x[i], c)) * DfuncCq(a, b, x[i], c))) / (theta + r);
        }
        a -= dA;
        b -= dB;
        c == dC;
        count++;
        printf("\na = %.3f, b = %.3f, c = %.3f , erro = %.3f\n", a, b, c, erro);
    }

    printf("\n%i", count);
}

double funclog(double a, double b, double x){
    return a * x + b*log(x);
}

double DfunclogA(double a, double b, double x){
    return -x;
}

double DfunclogB(double a, double b, double x){
    return -log(x);
}

void logn(double a, double b, double *y, double *x, int qntPontos, double taxaDeAprendizado){
    double erro = 1e5;
    double erroa = 0;
    double dA, dB, r;
    int count = 0;
    double theta = 1e-8;

    while ((fabs(erro - erroa) / erro) > 0.01)
    {
        erroa = erro;
        erro = 0;
        for (int i = 0; i < qntPontos; i++)
        {
            erro += pow(y[i] - funclog(a, b, x[i]), 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {

            dA += (taxaDeAprendizado * ((y[i] - funclog(a, b, x[i])) * DfunclogA(a, b, x[i]))) / (theta + r);
            dB += (taxaDeAprendizado * ((y[i] - funclog(a, b, x[i])) * DfunclogB(a, b, x[i]))) / (theta + r);
        }
        a -= dA;
        b -= dB;

        count++;
        printf("\na = %.3f, b = %.3f , erro = %.3f\n", a, b, erro);
    }
    printf("\n%i", count);
}