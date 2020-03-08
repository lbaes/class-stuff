#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>
#define MAX_THREADS 1

//checa se um numero é primo
bool primo(unsigned long long n)
{
    if (n == 0 || n == 1)
        return false;
    for (unsigned long long i = 2; i <= floor(sqrt(n)); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

//procura numeros primos entre N e M
void *primoIntervalo(void *argsptr)
{
    unsigned long long *args = (unsigned long long *)argsptr;

    unsigned long long N = (unsigned long long)args[0];
    unsigned long long M = (unsigned long long)args[1];

    printf("Procurando entre: %llu e %llu :\n", N, M);

    for (unsigned long long int i = N; i <= M; i++)
    {
        if (primo(i))
            //printf("%llu\n", i);
            ;
    }
    printf("Pronto\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tids[MAX_THREADS];
    unsigned long long int N;
    unsigned long long args[MAX_THREADS][2];

    if (argc != 2)
    {
        printf("--Mostra os numeros primos ate N\nUso: %s <N>\n", argv[0]);
        return 1;
    }

    N = strtoull(argv[1], NULL, 10);

    //divide o intervalo de busca entre as threads
    unsigned long long int intervalo = N/MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++)
    {
        args[i][0] = i*intervalo + 1;
        args[i][1] = (i+1)*intervalo;

    }

    //inicia as threads
    for (int i = 0; i < MAX_THREADS; i++)
    {
        printf("Iniciando Thread %d de %d\n", i+1, MAX_THREADS);
        pthread_create(&tids[i], NULL, primoIntervalo, (void *)args[i]);
    }

    //espera pelo termino de todas as threads
    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(tids[i], NULL);
    }
    
    printf("Programa terminou\n");

    return 0;
}
