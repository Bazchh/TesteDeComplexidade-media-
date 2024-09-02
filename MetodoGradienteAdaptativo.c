#include <stdio.h>
#include <math.h>

double *funcaoErroQuadratico(double *coeficientes, double *y, double *x, int qntPontos, double taxaDeAprendizado)
{
    double erro = pow(10, 5);
    double erroa = 0;
    double dA, dB;
    double r;
    int count = 0;
    int i;
    while (((erro - erroa) / erro) > 0.01)
    {
        erroa = erro;

        for (int i = 0; i < qntPontos; i++)
        {
            double previsao = coeficientes[0] * x[i] + coeficientes[1];
            erro += pow(y[i] - previsao, 2);
        }
        erro /= qntPontos;
        r = sqrt(erro);
        dA = dB = 0.0;

        for (int i = 0; i < qntPontos; i++)
        {
            double previsao = coeficientes[0] * x[i] + coeficientes[1];
            dA += taxaDeAprendizado * ((y[i] - previsao) * (-x[i])) / (pow(10, -8) + r);
            dB += taxaDeAprendizado * ((y[i] - previsao) * (- 1)) / (pow(10, -8) + r);
        }
        coeficientes[0] -= dA;
        coeficientes[1] -= dB;
        count ++;
        printf("\na = %f, b = %f, erro = %f\n", coeficientes[0], coeficientes[1], erro);
        
    }

    printf("\n%i", count);
    return coeficientes;
}