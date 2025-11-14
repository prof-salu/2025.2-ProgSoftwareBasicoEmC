/*
 * TAREFA: O COFRE DO BANCO (COM BUG E VALORES VARIÁVEIS)
 * OBJETIVO: Este codigo tem um bug de condicao de corrida.
 * O saldo final impresso esta incorreto.
 * MISSAO: Corrigir o bug usando um Mutex (API do Windows).
 */

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define N_THREADS 5 // Número de threads (agências)

// --- Variáveis Globais ---
double g_saldoBancario = 1000.0; // O recurso compartilhado (vulnerável)

// --- Estrutura de Dados para Threads ---
typedef struct {
    const char* nome;
    int tipoOperacao; // 1 para Depósito, 2 para Saque
    double valor;     // O valor da transação
} ThreadArgs;


/*
 * Esta é a operação vulnerável de depósito.
 * O Sleep() simula o tempo de processamento.
 * NÃO MODIFIQUE ESTA FUNÇÃO.
 */
void operacaoDeposito(const char* nome, double valor) {
    printf("%s [Agencia] quer depositar %.2f...\n", nome, valor);
    fflush(stdout);
    
    double saldoLocal = g_saldoBancario; // 1. LÊ o saldo
    printf("%s [Agencia]... leu o saldo de %.2f\n", nome, saldoLocal);
    
    Sleep(2000); // 2. SIMULA processamento (AQUI O BUG ACONTECE)
    
    saldoLocal += valor; // 3. CALCULA o novo saldo
    
    g_saldoBancario = saldoLocal; // 4. ESCREVE o novo saldo
    
    printf("%s [Agencia]... DEPOSITOU %.2f. Novo saldo (na sua visao): %.2f\n", nome, valor, g_saldoBancario);
    fflush(stdout);
}

/*
 * Esta é a operação vulnerável de saque.
 * NÃO MODIFIQUE ESTA FUNÇÃO.
 */
void operacaoSaque(const char* nome, double valor) {
    printf("%s [Agencia] quer sacar %.2f...\n", nome, valor);
    fflush(stdout);

    double saldoLocal = g_saldoBancario; // 1. LÊ o saldo
    printf("%s [Agencia]... leu o saldo de %.2f\n", nome, saldoLocal);

    Sleep(1500); // 2. SIMULA processamento
    
    saldoLocal -= valor; // 3. CALCULA o novo saldo
    
    g_saldoBancario = saldoLocal; // 4. ESCREVE o novo saldo

    printf("%s [Agencia]... SACOU %.2f. Novo saldo (na sua visao): %.2f\n", nome, valor, g_saldoBancario);
    fflush(stdout);
}

/*
 * A rotina principal da thread.
 * Analise esta função para encontrar onde proteger.
 */
DWORD WINAPI threadRoutine(LPVOID lpParam) {
    ThreadArgs* args = (ThreadArgs*)lpParam;
    
    if (args->tipoOperacao == 1) {
        operacaoDeposito(args->nome, args->valor);
    } else if (args->tipoOperacao == 2) {
        operacaoSaque(args->nome, args->valor);
    }
    
    free(args); // Libera a memória dos argumentos
    return 0;
}

int main() {
    // --- DADOS DAS TRANSAÇÕES (Sinta-se livre para alterar para testar) ---
    const char* nomes[N_THREADS] = {"Agencia_A", "Agencia_B", "Caixa_C", "Agencia_D", "Caixa_E"};
    int operacoes[N_THREADS] = {1, 2, 1, 2, 1}; // 1=Dep, 2=Saque
    double valores[N_THREADS] = {500.0, 300.0, 200.0, 700.0, 100.0};
    // Saldo esperado: 1000 + 500 - 300 + 200 - 700 + 100 = 800.00
    // ---------------------------------------------------------------------

    HANDLE threads[N_THREADS];
    ThreadArgs* threadArgs[N_THREADS];

    printf("Simulacao iniciada. Saldo inicial: %.2f\n", g_saldoBancario);
    printf("-------------------------------------------\n");

    int i = 0;
    for (i; i < N_THREADS; ++i) {
        threadArgs[i] = (ThreadArgs*)malloc(sizeof(ThreadArgs));
        if (threadArgs[i] == NULL) {
            perror("Erro ao alocar memoria para args");
            return 1;
        }

        threadArgs[i]->nome = nomes[i];
        threadArgs[i]->tipoOperacao = operacoes[i];
        threadArgs[i]->valor = valores[i];

        threads[i] = CreateThread(
            NULL, 0, threadRoutine, threadArgs[i], 0, NULL
        );
        if (threads[i] == NULL) {
            perror("Erro ao criar thread");
            return 1;
        }
    }

    // Espera todas as threads terminarem
    WaitForMultipleObjects(N_THREADS, threads, TRUE, INFINITE);

    printf("-------------------------------------------\n");
    printf("Todas as agencias terminaram as operacoes.\n");
    printf("SALDO FINAL (COM BUG?): %.2f\n", g_saldoBancario);
    printf("Saldo esperado (correto): 800.00\n");

    // Limpa os handles das threads
    i = 0;
    for (i; i < N_THREADS; ++i) {
        CloseHandle(threads[i]);
    }

    return 0;
}
