# Jogo da Velha 3.0

## Descrição

Este é um simples jogo da velha (tic-tac-toe) implementado em C. O jogo permite dois modos de jogo: um jogador contra a máquina ou dois jogadores. O projeto foi criado como parte de um exercício de aprendizado para aplicar conceitos básicos de programação em C.

## Funcionalidades

- **Modo de um jogador**: Jogue contra a máquina.
- **Modo de dois jogadores**: Dois jogadores humanos podem se enfrentar.
- **Verificação de vencedor**: O jogo verifica automaticamente se há um vencedor após cada movimento.
- **Interface de texto simples**: Utiliza a linha de comando para a interação com o usuário.

## Requisitos

- Compilador C (GCC, Clang, etc.)
- Sistema operacional compatível com a linha de comando (Windows, macOS, Linux)

## Como Compilar

Para compilar o jogo, você pode usar o GCC. Abra o terminal ou prompt de comando e execute o seguinte comando:

```sh
gcc -o jogo_da_velha jogo_da_velha.c
```

## Como Executar

Depois de compilar o jogo, você pode executá-lo com o seguinte comando:

```sh
./jogo_da_velha
```

## Instruções de Jogo

1. Ao iniciar o jogo, será apresentado um menu com duas opções:
    - 1: Um jogador
    - 2: Dois jogadores

2. Escolha o modo de jogo desejado digitando o número correspondente.

3. Escolha seu jogador (X ou O).

4. Para fazer uma jogada, você será solicitado a fornecer a linha e a coluna onde deseja colocar seu símbolo. As posições são indicadas por pares de números (por exemplo, 00 para a primeira linha e primeira coluna).

5. O jogo alternará entre os jogadores ou entre o jogador e a máquina, dependendo do modo selecionado.

6. O jogo verifica automaticamente se há um vencedor após cada jogada. Se houver um vencedor, ele será anunciado. Se todas as posições do tabuleiro forem preenchidas sem um vencedor, o jogo terminará em empate.

7. Após o término do jogo, você terá a opção de jogar novamente ou sair.

## Estrutura do Código

- `main()`: Função principal que gerencia o fluxo do jogo.
- `menuIniciar()`: Exibe o menu inicial e permite a seleção do modo de jogo.
- `escolherPlayer()`: Permite que o jogador escolha entre X e O.
- `inicializarTabuleiro()`: Inicializa o tabuleiro com espaços vazios.
- `mostrarTabuleiro()`: Exibe o tabuleiro na linha de comando.
- `jogadaPlayer()`: Gerencia as jogadas dos jogadores.
- `jogadaMaquina()`: Gerencia as jogadas da máquina no modo de um jogador.
- `verificarVencedor()`: Verifica se há um vencedor após cada jogada.
- `rodadaSingle()`: Gerencia uma rodada no modo de dois jogadores.
- `rodadaMulti()`: Gerencia uma rodada no modo de um jogador contra a máquina.
- `numRaid()`: Gera coordenadas aleatórias para a jogada da máquina.