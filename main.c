#include <string.h>
#include "Diversos.c"
#include "VerificacaoDeAlocacao.c"
#include "AlgoritmosDeOrdenacao.c"
#include "MetodoGradienteAdaptativo.c"
#include "FuncoesMMQ.c"
int main()
{
    int qntdOrdenacoes = 100;
    int tamanho = 1000;
    int testes = 100;
    double *tempos;
    double *tamanhos = (double *)malloc(testes * sizeof(double));
    double *temposMediosVet = (double *)malloc(testes * sizeof(double));
    double *coeficientes_e = (double *)malloc(2 * sizeof(double));

    verificarAlocacaoPonteiroDouble(tamanhos, "ponteiro de tamanhos");
    verificarAlocacaoPonteiroDouble(temposMediosVet, "Ponteiro com tempos medios");
    for (int i = 0; i < testes; tamanho += 1000, i++)
    {
        tamanhos[i] = tamanho;
        /*   tempos = complexidadeMedia(merge_sort, qntdOrdenacoes, tamanho, time(NULL));
         escreverEmArquivo(tempos, qntdOrdenacoes, tamanho, i);  */
    }

    temposMediosGet(temposMediosVet, testes);
    coeficientes_e[0] = 1;
    coeficientes_e[1] = 1;
    normalizarDados(temposMediosVet, 100, testes);
    normalizarDados(tamanhos, 0.001, testes);
    coeficientes_e = funcaoErroQuadratico(coeficientes_e, temposMediosVet, tamanhos, testes, 0.00001);
    /* dadosOriginais(temposMediosVet, 100, testes);
    dadosOriginais(tamanhos, 0.001, testes); */
    plotGraphGNU(temposMediosVet, tamanhos, testes, coeficientes_e[0], coeficientes_e[1], 1);
    free(tempos);
}