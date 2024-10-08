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

void primeiroGrau(double *a_e_b, double *y, double *x, int qntPontos, double taxaDeAprendizado)
{
    double erro = 1e5;
    double erroa = 0;
    double dA, dB, r;
    int count = 0;
    double theta = 1e-8;
    while ((fabs(erro - erroa) / erro) > 0.001)
    {
        erroa = erro;
        erro = 0;
        for (int i = 0; i < qntPontos; i++)
        {
            erro += pow(y[i] - func(a_e_b[0], a_e_b[1], x[i]), 2);
        }
        erro = erro / qntPontos;
        r = sqrt(erro);
        dA = dB = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {
            dA +=  ((y[i] - func(a_e_b[0], a_e_b[1], x[i])) * DfuncA(a_e_b[0], a_e_b[1], x[i]))/ (theta + r);
            dB +=   ((y[i] - func(a_e_b[0], a_e_b[1], x[i])) * DfuncB(a_e_b[0], a_e_b[1], x[i])) / (theta + r);
        }
        dA *= taxaDeAprendizado;
        dB *= taxaDeAprendizado;
        a_e_b[0] -= dA;
        a_e_b[1] -= dB;
        count++;
        printf("\na = %.3f, b = %.3f, erro = %.3f\n", a_e_b[0], a_e_b[1], erro);
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

void segundoGrau(double *a_e_b_e_c, double *y, double *x, int qntPontos, double taxaDeAprendizado)
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
            erro += pow(y[i] - funcq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2]), 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = dC = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {

            dA += (taxaDeAprendizado * ((y[i] - funcq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2])) * DfuncAq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2]))) / (theta + r);
            dB += (taxaDeAprendizado * ((y[i] - funcq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2])) * DfuncBq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2]))) / (theta + r);
            dC += (taxaDeAprendizado * ((y[i] - funcq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2])) * DfuncCq(a_e_b_e_c[0], a_e_b_e_c[1], x[i], a_e_b_e_c[2]))) / (theta + r);
        }
        a_e_b_e_c[0] -= dA;
        a_e_b_e_c[1] -= dB;
        a_e_b_e_c[2] == dC;
        count++;
        printf("\na = %.3f, b = %.3f, c = %.3f , erro = %.3f\n", a_e_b_e_c[0], a_e_b_e_c[1], a_e_b_e_c[2], erro);
    }

    printf("\n%i", count);
}

double funclog(double a, double b, double x)
{
    return a * x + b * log(x);
}

double DfunclogA(double a, double b, double x)
{
    return -x;
}

double DfunclogB(double a, double b, double x)
{
    return -log(x);
}

void logn(double *a_e_b, double *y, double *x, int qntPontos, double taxaDeAprendizado)
{
    double erro = 1e5;
    double erroa = 0.0;
    double dA, dB, r;
    int count = 0;
    double theta = 1e-8;

    do
    {
        erroa = erro;
        erro = 0.0;
        for (int i = 0; i < qntPontos; i++)
        {
            erro += pow(y[i] - funclog(a_e_b[0], a_e_b[1], x[i]), 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {

            dA += (taxaDeAprendizado * ((y[i] - funclog(a_e_b[0], a_e_b[1], x[i])) * DfunclogA(a_e_b[0], a_e_b[1], x[i]))) / (theta + r);
            dB += (taxaDeAprendizado * ((y[i] - funclog(a_e_b[0], a_e_b[1], x[i])) * DfunclogB(a_e_b[0], a_e_b[1], x[i]))) / (theta + r);
        }
        a_e_b[0] -= dA;
        a_e_b[1] -= dB;

        count++;
        printf("\na = %.3f, b = %.3f , erro = %.3f\n", a_e_b[0], a_e_b[1], erro);
    } while ((fabs(erro - erroa) / erro) > 0.01);
    printf("\n%i", count);
}