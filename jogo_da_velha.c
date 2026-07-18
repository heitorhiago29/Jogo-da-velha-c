#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
===========================================
JOGO DA VELHA
Autor: Heitor Hiago
Linguagem: C

Projeto desenvolvido para praticar:

- Funções
- Ponteiros
- Estruturas de repetição
- Estruturas condicionais
- Modularização
- Geração de números pseudoaleatórios

===========================================
*/

int verificarvencedor(char tabuleiro[3][3]);

void menuinicial(int *opcao)
{
    printf("===================================\n");
    printf("JOGO DA VELHA\n");
    printf("===================================\n");

    printf("1 - Jogar\n");
    printf("2 - Estatísticas\n");
    printf("3 - Sair\n");

    printf("Escolha uma opção: ");
    scanf("%d", opcao);
    printf("o jogador é o 'X' e o computador é o 'O'\n");
    printf("\n");
    printf("Autor: Heitor Hiago\n");
    printf("Linguagem: C\n");
    printf("====================================\n");

}

void tabuleiroatualizado(char tabuleiro[3][3])
{
    int i, j;
    printf("\n--- TABULEIRO ---\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" | %c", tabuleiro[i][j]);
        }
        printf(" |\n");
    }
}
void iniciojogo(char tabuleiro[3][3])
{
    /*função para iniciar o jogo da velha*/
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }

    tabuleiroatualizado(tabuleiro);
}

void partida(char tabuleiro[3][3])
{
    int lcomputador, ccomputador, ljogador, cjogador;
    int jogadas_validas, espacos_vazios, i, j;
    jogadas_validas=0;
    espacos_vazios=0;

    do
    {
        printf("Digite a linha e a coluna da sua jogada (0-2): ");
        scanf("%d %d", &ljogador, &cjogador);

        if(ljogador >= 0 && ljogador < 3 && cjogador >= 0 && cjogador <3 && tabuleiro[ljogador][cjogador]== ' ')
        {
            tabuleiro[ljogador][cjogador] = 'X';
            jogadas_validas = 1;
        }
        else 
        {
            printf("Posição inválida ou já ocupada! Tente novamente.\n");
        }
    } while (!jogadas_validas);

    tabuleiroatualizado(tabuleiro);

    if (verificarvencedor(tabuleiro) == 0) 
    {
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(tabuleiro[i][j] == ' ')
                {
                    espacos_vazios = espacos_vazios + 1;
                }
            }
        }
        if(espacos_vazios > 0)
        {
            printf("É a vez do computador...\n");
            do
            {
                lcomputador = rand() % 3;
                ccomputador = rand() % 3;
            } while(tabuleiro[lcomputador][ccomputador] != ' ');

            tabuleiro[lcomputador][ccomputador] = 'O';
            tabuleiroatualizado(tabuleiro);
        }
    }
}

int verificarvencedor(char tabuleiro[3][3])
{
    /*função para verificar o resultado do jogo da velha*/
    int i;
    /*vertical e horizontal*/
    for (i=0;i<3;i++)
    {
        if(tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' && tabuleiro[i][2]== 'X')
        {
            return 1;
        }
        else
        {
            if(tabuleiro[i][0] == 'O' && tabuleiro[i][1] == 'O' && tabuleiro[i][2]== 'O')
            {
                return 2;
            }
            else
            {
                if(tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i]== 'X')
                {
                    return 1;
                }
                else
                {
                    if(tabuleiro[0][i] == 'O' && tabuleiro[1][i] == 'O' && tabuleiro[2][i]== 'O')
                    {
                        return 2;
                    }
                }
            }
        }
    }
    if(tabuleiro[0][0]=='X'&& tabuleiro[1][1]=='X' && tabuleiro[2][2] == 'X')
    {
        return 1;
    }
    else
    {
        if(tabuleiro[0][0]=='O'&& tabuleiro[1][1]=='O' && tabuleiro[2][2] == 'O')
        {
            return 2;
        }
        else
        {
            if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X')
            {
                return 1;
            }
            else
            {
                if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O')
                {
                    return 2;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}

void estatisticas(int vitoriasjogador, int vitoriascomputador, int total_jogos)
{
    /*função para mostrar as estatísticas do jogo da velha*/
    printf("==================================\n");
    printf("Estatísticas do jogo da velha:\n");
    printf("==================================\n");
    printf("Vitórias do jogador: %d\n", vitoriasjogador);
    printf("Vitórias do computador: %d\n", vitoriascomputador);
    printf("Total de jogos disputados: %d\n", total_jogos);
    if (total_jogos > 0) 
    {
        printf("Aproveitamento do Jogador: %.2f%%\n", ((float)vitoriasjogador / total_jogos) * 100);
    } 
    else 
    {
        printf("Aproveitamento: 0%%\n");
    }
    printf("====================================\n");
}

void fimdejogo(void)
{
    printf("===============================\n");
    printf("        FIM DE JOGO     \n");
    printf("    Obrigado por jogar !\n");
    printf("================================\n");
}
int main(void)
{
    int opcao, total_jogos, vitoriasjogador, vitoriascomputador;
    char tabuleiro[3][3];
    int rodadas, status;
    rodadas=0;
    status=0;
    opcao=0;
    total_jogos=0;
    vitoriascomputador=0;
    vitoriasjogador=0;

    srand(time(NULL));

    while (opcao != 3)
    {
        menuinicial(&opcao);
        if(opcao ==1)
        {
            iniciojogo(tabuleiro);
            rodadas=0;
            status=0;
            while(rodadas < 5 && status == 0)
            {
                partida(tabuleiro);
                status=verificarvencedor(tabuleiro);
                rodadas=rodadas+1;
            }
            switch (status)
            {
                case 1:
                    printf("Parabéns! O jogador venceu!\n");
                    vitoriasjogador=vitoriasjogador+1;
                    break;
                case 2:
                    printf("Que pena! O computador venceu!\n");
                    vitoriascomputador=vitoriascomputador+1;
                    break;
                default:
                    printf("Empate ! Deu velha !");
                    break;
            }
            total_jogos=total_jogos+1;
        }
        else
        {
            if(opcao==2)
            {
                estatisticas(vitoriasjogador, vitoriascomputador, total_jogos);
            }
        }
    }
    fimdejogo();

    return 0;
}