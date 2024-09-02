#include <stdio.h>
#include <math.h>

void *funcaoErroQuadratico(double a, double b, double *y, double *x, int qntPontos, double taxaDeAprendizado)
{
    double erro = 1e5;
    double erroa = 0;
    double dA, dB;
    double r;
    int count = 0;
    while ((fabs(erro - erroa) / erro) > 0.01)
    {
        erroa = erro;
        erro = 0;
        for (int i = 0; i < qntPontos; i++)
        {
            double previsao = a * x[i] + b;
            erro += pow(y[i] - previsao, 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {
            double previsao = a * x[i] + b;
            dA += (taxaDeAprendizado * ((y[i] - previsao) * (-x[i]))) / (1e-8 + r);
            dB += (taxaDeAprendizado * ((y[i] - previsao) * (-1))) / (1e-8 + r);
        }
        a -= dA;
        b -= dB;
        count++;
        printf("\na = %.3f, b = %.3f, erro = %.3f\n", a, b, erro);
    }

    printf("\n%i", count);
}