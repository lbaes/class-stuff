#include <stdlib.h>
#include <stdio.h>

#define TAM 1000

int main(void)
{
    //alocacao
    int **m1 = (int **)malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++)
        m1[i] = (int *)malloc(TAM * sizeof(int));

    int **m2 = (int **)malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++)
        m2[i] = (int *)malloc(TAM * sizeof(int));

    int **mr = (int **)malloc(TAM * sizeof(int *));
    for (int i = 0; i < TAM; i++)
        mr[i] = (int *)malloc(TAM * sizeof(int));

    //inicializacao;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            m1[i][j] = m2[i][j] = i * TAM + j + 1;
            mr[i][j] = 0;
        }
    }

    //Computacao
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            for (int k = 0; k < TAM; k++)
            {
                mr[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    //Print
    printf("[%d]\n", mr[0][0]);
}