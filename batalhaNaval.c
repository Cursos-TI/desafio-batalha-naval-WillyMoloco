#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas do navio horizontal
    int linhaH = 2;  // linha inicial
    int colunaH = 4; // coluna inicial

    // Coordenadas do navio vertical
    int linhaV = 5;  // linha inicial
    int colunaV = 7; // coluna inicial

    // Validação para garantir que os navios estão dentro dos limites
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO || linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Coordenadas inválidas para posicionamento dos navios.\n");
        return 1;
    }

    // Verificação de sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA || tabuleiro[linhaV + i][colunaV] != AGUA) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Posiciona o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
