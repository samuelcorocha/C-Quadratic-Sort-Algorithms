#include "bolha.h"
#include "insercao.h"
#include "selecao.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


#include <windows.h>
#include <winbase.h>
#include <psapi.h>


double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}

int main()
{
    clock_t start_time, end_time;
    double cpu_time_used, memory_used;

    for(int alg = 0; alg < 3; alg++)
    {
        switch(alg)
        {
        case 0:
            for(int ord = 0; ord < 3; ord++)
            {
                for(int n=2000; n<=2048000; n *= 2)
                {
                    int *vet = malloc(n * sizeof(int));

                    switch(ord)
                    {
                    case 0:
                        crescente(vet, n);
                        FILE* bolha_cresc = fopen("bolha_cresc.csv", "a");

                        start_time = clock();
                        bolha(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(bolha_cresc, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(bolha_cresc);
                        free(vet);
                        break;
                    case 1:
                        decrescente(vet, n);
                        FILE* bolha_decresc = fopen("bolha_decresc.csv", "a");

                        start_time = clock();
                        bolha(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(bolha_decresc, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(bolha_decresc);
                        free(vet);
                        break;
                    case 2:
                        aleatorio(vet, n);
                        FILE* bolha_aleat = fopen("bolha_aleat.csv", "a");

                        start_time = clock();
                        bolha(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(bolha_aleat,"%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(bolha_aleat);
                        free(vet);
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 1:
            for(int ord = 0; ord < 3; ord++)
            {
                for(int n=2000; n<=2048000; n *= 2)
                {
                    int *vet = malloc(n * sizeof(int));

                    switch(ord)
                    {
                    case 0:
                        crescente(vet, n);
                        FILE* insercao_cresc = fopen("insercao_cresc.csv", "a");

                        start_time = clock();
                        insercao(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(insercao_cresc, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(insercao_cresc);
                        free(vet);
                        break;
                    case 1:
                        decrescente(vet, n);
                        FILE* insercao_decresc = fopen("insercao_decresc.csv", "a");

                        start_time = clock();
                        insercao(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(insercao_decresc, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(insercao_decresc);
                        free(vet);
                        break;
                    case 2:
                        aleatorio(vet, n);
                        FILE* insercao_aleat = fopen("insercao_aleat.csv", "a");

                        start_time = clock();
                        insercao(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(insercao_aleat, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(insercao_aleat);
                        free(vet);
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 2:
            for(int ord = 0; ord < 3; ord++)
            {
                for(int n=2000; n<=2048000; n *= 2)
                {
                    int *vet = malloc(n * sizeof(int));

                    switch(ord)
                    {
                    case 0:
                        crescente(vet, n);
                        FILE* selecao_cresc = fopen("selecao_cresc.csv", "a");

                        start_time = clock();
                        selecao(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(selecao_cresc, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(selecao_cresc);
                        free(vet);
                        break;
                    case 1:
                        decrescente(vet, n);
                        FILE* selecao_decresc = fopen("selecao_decresc.csv", "a");

                        start_time = clock();
                        selecao(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(selecao_decresc, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(selecao_decresc);
                        free(vet);
                        break;
                    case 2:
                        aleatorio(vet, n);
                        FILE* selecao_aleat = fopen("selecao_aleat.csv", "a");

                        start_time = clock();
                        selecao(vet, n);
                        end_time = clock();

                        cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                        memory_used = get_memory_used_MB();

                        printf("%d\t%0.2f\t%0.2f\n", n, cpu_time_used, memory_used);
                        fprintf(selecao_aleat, "%d;%0.2f;%0.2f\n", n, cpu_time_used, memory_used);

                        fclose(selecao_aleat);
                        free(vet);
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
