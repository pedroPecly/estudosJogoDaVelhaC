#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 3

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
char player1, player2;
int linha, coluna, cont, vencedor = 0, opcaoMenu;

void numRaid(int *numero1, int *numero2) {
    srand(time(NULL));
    *numero1 = rand() % TAMANHO_TABULEIRO;
    *numero2 = rand() % TAMANHO_TABULEIRO;
}

void menuIniciar() {
    char op;
    printf("---MENU JOGO DA VEIA 3.0---\n");
    printf("1- Um jogador\n");
    printf("2- Dois jogadores\n");

    do {
        printf("Opção selecionada: ");
        scanf(" %c", &op);
        if (op == '1' || op == '2') {
            opcaoMenu = (op == '1') ? 1 : 2;
        } else {
            printf("---ERRO---\n");
        }
    } while (opcaoMenu == 0);

    printf("\n");
}

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrarTabuleiro() {
    printf("--------\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O') {
                printf("%c ", tabuleiro[i][j]);
            } else {
                printf("%d%d ", i, j);
            }
        }
        printf("\n");
    }
    printf("--------\n");
}

void escolherPlayer() {
    char resp;
    int verificacao = 0;

    printf("Escolha seu jogador:\n");
    printf("1- Jogar com X\n");
    printf("2- Jogar com O\n");

    do {
        printf("Opção selecionada: ");
        scanf(" %c", &resp);
        if (resp == '1' || resp == '2') {
            if (resp == '1') {
                cont = 1;
                player1 = 'X';
                player2 = 'O';
            } else {
                cont = 2;
                player1 = 'O';
                player2 = 'X';
            }
            verificacao = 1;
        } else {
            printf("---ERRO---\n");
        }
    } while (verificacao == 0);

    printf("\n");
}

void jogadaPlayer(char jogador) {
    int tentativa = 0, verificacaoLinha = 0, verificacaoColuna = 0;

    printf("\nVez do %c\n", jogador);

    do {
        do {
            printf("Linha: ");
            scanf("%d", &linha);
            if (linha >= TAMANHO_TABULEIRO) {
                printf("---Valor inválido---\n");
            } else {
                verificacaoLinha = 1;
            }
        } while (verificacaoLinha == 0);

        do {
            printf("Coluna: ");
            scanf("%d", &coluna);
            if (coluna >= TAMANHO_TABULEIRO) {
                printf("---Valor inválido---\n");
            } else {
                verificacaoColuna = 1;
            }
        } while (verificacaoColuna == 0);

        if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {
            printf("Campo já ocupado\n");
        } else {
            tabuleiro[linha][coluna] = jogador;
            tentativa = 1;
        }
    } while (tentativa == 0);

    cont++;
    mostrarTabuleiro();
}

void jogadaMaquina() {
    int tentativa = 0, numero1, numero2;

    printf("\nVez do: %c\n", player2);

    do {
        numRaid(&numero1, &numero2);
        linha = numero1;
        coluna = numero2;

        if (tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
            tabuleiro[linha][coluna] = player2;
            tentativa = 1;
            mostrarTabuleiro();
        }
    } while (tentativa == 0);

    cont++;
}

int verificarVencedor() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return (tabuleiro[i][0] == 'X') ? 1 : 2;
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return (tabuleiro[0][i] == 'X') ? 1 : 2;
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return (tabuleiro[0][0] == 'X') ? 1 : 2;
    }

    if (tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2] && tabuleiro[2][0] != ' ') {
        return (tabuleiro[2][0] == 'X') ? 1 : 2;
    }

    return 0;
}

void rodadaMulti() {
    escolherPlayer();
    inicializarTabuleiro();
    mostrarTabuleiro();

    do {
        jogadaPlayer(player1);
        vencedor = verificarVencedor();
        if (vencedor > 0) break;

        jogadaMaquina();
        vencedor = verificarVencedor();
    } while (vencedor == 0);
}

void rodadaSingle() {
    escolherPlayer();
    inicializarTabuleiro();
    mostrarTabuleiro();

    do {
        jogadaPlayer(player1);
        vencedor = verificarVencedor();
        if (vencedor > 0) break;

        jogadaPlayer(player2);
        vencedor = verificarVencedor();
    } while (vencedor == 0);
}

int main() {
    char fimGame;

    do {
        menuIniciar();

        if (opcaoMenu == 1) {
            rodadaMulti();
        } else if (opcaoMenu == 2) {
            rodadaSingle();
        }

        printf("\n");
        if (vencedor != 0) {
            printf("\nVencedor %c\n", (vencedor == 1) ? 'X' : 'O');
        }

        printf("\nDeseja jogar novamente:\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        printf("Opção selecionada: ");
        scanf(" %c", &fimGame);

        if (fimGame == '1') {
            printf("\n");
            vencedor = 0;
            opcaoMenu = 0;
        }
    } while (fimGame != '2');

    return 0;
}

