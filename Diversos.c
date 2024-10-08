#include "Diversos.h"
#include "VerificacaoDeAlocacao.h"

void temposMediosGet(double *temposMedios, int qntTamanhos)
{
    FILE *arch;
    char linha[100];
    FILE *temp;
    char tempo[20];

    arch = fopen("tempos.txt", "w");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo tempos.txt");
        return;
    }

    for (int j = 0; j < qntTamanhos; j++)
    {
        sprintf(tempo, "tempo%i.txt", j);
        temp = fopen(tempo, "r");
        if (temp == NULL)
        {
            printf("Erro ao abrir o arquivo %s\n", tempo);
            continue;
        }

        double somaTempos = 0.0;
        int contagemTempos = 0;

        while (fgets(linha, sizeof(linha), temp) != NULL)
        {
            int tamanhoProblema;
            double tempoExecucao;

            
            if (sscanf(linha, "%d %lf", &tamanhoProblema, &tempoExecucao) == 2)
            {
                somaTempos += tempoExecucao;  
                contagemTempos++;
            }
        }

        if (contagemTempos > 0)
        {
            double media = somaTempos / contagemTempos;
            temposMedios[j] = media;  
            fprintf(arch, "%lf\n", temposMedios[j]);  
        }
        else
        {
            printf("\nErro: arquivo %s não contém dados válidos.\n", tempo);
        }

        fclose(temp);
    }

    fclose(arch);
}

void temposMediosGetw(double *temposMedios, int qntTamanhos)
{
    FILE *arch;
    char linha[100];
    arch = fopen("tempos.txt", "w");

    if (arch == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < qntTamanhos; i++)
    {
        if (fgets(linha, sizeof(linha), arch) != NULL)
        {
            if (sscanf(linha, "%f", &temposMedios[i]) != 1)
            {
                // printf("Erro ao converter o valor na linha %d.\n", i + 1);
            }
            else
            {
                //  printf("Valor lido na linha %d: %lf\n", i + 1, temposMedios[i]);
            }
        }
        else
        {
            //  printf("Erro ao ler a linha %d.\n", i + 1);
            break;
        }
    }

    fclose(arch); // Fechar o arquivo após a leitura
}

void normalizarDados(double *vet, float escala, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vet[i] = (vet[i] * escala);
    }
}

void dadosOriginais(double *vet, float escala, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vet[i] = (vet[i] / escala);
    }
}

void geradorRandom(int *array, int seed, int qntd)
{
    int i = 0;
    srand(seed);

    verificarAlocacaoPonteiroint(array, "vetor no gerador random com numeros gerados aleatoriamente");

    for (i = 0; i < qntd; i++)
    {
        array[i] = rand() % qntd;
    }
}

char loading(int i)
{
    if (i == 0)
        return '-';
    else if (i == 1)
        return '\\';
    else if (i == 2)
        return '|';
    else if (i == 3)
        return '/';
    else
        return '-';
}

char *porcentagemBarra(int qntdTestes, int total, int tamanhoBarra)
{
    int porcentagem = (int)(((double)qntdTestes / total) * 100);

    int numPreenchidos = (porcentagem * tamanhoBarra) / 100;

    char *barraString = (char *)malloc((tamanhoBarra + 6) * sizeof(char));
    barraString[0] = '[';
    for (int i = 1; i <= tamanhoBarra; i++)
    {
        barraString[i] = (i <= numPreenchidos) ? '=' : ' ';
    }
    char aux[4];
    sprintf(aux, "%i", porcentagem);
    barraString[tamanhoBarra + 1] = ']';
    barraString[tamanhoBarra + 2] = ' ';
    barraString[tamanhoBarra + 3] = aux[0];
    barraString[tamanhoBarra + 4] = aux[1];
    barraString[tamanhoBarra + 5] = aux[2];
    barraString[tamanhoBarra + 6] = '\0';
    return barraString;
}
void escreverEmArquivo(double *tempo, int qntTempos, int n, int i)
{
    double tempoMedio = 0;
    char *nomeDoArquivo = (char *)malloc((20) * sizeof(char));
    char *nomeDoArquivo2 = (char *)malloc((20) * sizeof(char));
    sprintf(nomeDoArquivo, "Tempo%i.txt", i);
    sprintf(nomeDoArquivo2, "tempos.txt");
    nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0';
    nomeDoArquivo2[strcspn(nomeDoArquivo2, "\n")] = '\0';
    srand(time(NULL));
    FILE *arquivoDeTempo = fopen(nomeDoArquivo, "w");
    FILE *arquivoTemposMedios = fopen(nomeDoArquivo2, "a");
    if (arquivoDeTempo == NULL || arquivoTemposMedios == NULL)
    {
        printf("\nNão foi possivel abrir ou criar o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(arquivoDeTempo, "\nTamanho do problema \t Tempo\n");

    for (int i = 0; i < qntTempos; i++)
    {
        fprintf(arquivoDeTempo, "\n\t\t%i   \t\t   %f", n, tempo[i]);
        tempoMedio += tempo[i];
    }

    tempoMedio /= qntTempos;

    fprintf(arquivoTemposMedios, "%f\n", tempoMedio);
    fclose(arquivoDeTempo);
    fclose(arquivoTemposMedios);
    /* free(nomeDoArquivo);
    free(arquivoTemposMedios); */
}

void plotGraphGNU(double *temposMedios, double *tamanhos, int testes, double a, double b, double c, int j)
{
    // Abrir arquivo para escrita dos dados
    FILE *dados = fopen("dados.txt", "w");
    if (dados == NULL)
    {
        perror("Erro ao abrir o arquivo dados.txt");
        return;
    }

    // Escrever dados no arquivo
    for (int i = 0; i < testes; i++)
    {
        fprintf(dados, "%f %f %f\n", tamanhos[i], temposMedios[i], (a * (tamanhos[i]*0.001) + b)/100);
    }
    fclose(dados);

    // Abrir o pipe para o Gnuplot
    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe == NULL)
    {
        perror("Erro ao abrir o pipe para Gnuplot");
        return;
    }

    // Configurar o Gnuplot
    fprintf(gnuplotPipe, "set terminal pngcairo enhanced size 1280,1280\n");
    fprintf(gnuplotPipe, "set output 'grafico%i.png'\n", j);
    fprintf(gnuplotPipe, "set title 'Gráfico de Complexidade'\n");
    fprintf(gnuplotPipe, "set xlabel 'Tamanho do problema'\n");
    fprintf(gnuplotPipe, "set ylabel 'Tempo médio'\n");
    fprintf(gnuplotPipe, "set grid\n");

    fprintf(gnuplotPipe, "f(x) = %f*x + %f\n", a, b);
    // Plotar os dados e a função
    fprintf(gnuplotPipe, "plot 'dados.txt' using 1:2 title 'Dados' with points pointtype 7 pointsize 1 lc rgb 'blue', \
        'dados.txt' using 1:3 title 'Pontos identificados' with line lc rgb 'red', \n");

    // Fechar o pipe
    pclose(gnuplotPipe);
}

void imprimirMat(double **matriz, int lin, int col, int qntDigitos)
{
    if (matriz == NULL)
    {
        printf("Matriz não inicializada\n");
        return;
    }

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %f ", matriz[i][j]);
        }
        printf("\n");
    }
}
