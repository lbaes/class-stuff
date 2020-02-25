#include  <stdio.h>
#include  <stdlib.h>
#include  <wait.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <unistd.h>

void  ClientProcess(int []);

int main(void)
{

    int ShmID;
    int *ShmPTR;
    pid_t pid;
    int status;
    int dado = 1;

    ShmID = shmget(IPC_PRIVATE, 1 * sizeof(int), IPC_CREAT | 0666);
    if (ShmID < 0)
    {
        printf("*** shmget error (server) ***\n");
        exit(1);
    }

    ShmPTR = (int *)shmat(ShmID, NULL, 0);
    if ((int)ShmPTR == -1)
    {
        printf("*** shmat error (server) ***\n");
        exit(1);
    }

    ShmPTR[0] = dado;
    printf("Varialvel %d criada pelo pai na memoria compartilhada\n", ShmPTR[0]);
    printf("Forkando...\n");
    pid = fork();

    if (pid < 0)
    {
        printf("*** fork error (server) ***\n");
        exit(1);
    }
    else if (pid == 0)
    {
        ClientProcess(ShmPTR);
        exit(0);
    }

    wait(&status);
    printf("Processo filho terminou a execucao...\n");
    printf("Multiplicando %d por 4...\n", ShmPTR[0]);
    ShmPTR[0] *= 4;
    printf("Novo valor = %d...\n", ShmPTR[0]);
    shmdt((void *)ShmPTR);
    printf("Server has detached its shared memory...\n");
    shmctl(ShmID, IPC_RMID, NULL);
    printf("Server has removed its shared memory...\n");
    printf("Server exits...\n");
    exit(0);
}

void  ClientProcess(int  SharedMem[])
{
     printf("   Client process started\n");
     printf("   Client found %d in shared memory\n", SharedMem[0]);
     printf("Somando 2 ao valor inicial...\n");
     SharedMem[0] += 2;
     printf("   Client is about to exit\n");
}