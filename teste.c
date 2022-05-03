#include <stdio.h>
#include <stdlib.h>

char matriz[8][8];

#define MACRO_TESTE             \
    if (matriz[x][y] == '-')    \
    {                           \
        continue;;                  \
    }                           \
    else if (matriz[x][y] == peca)      \
    {                           \
        continue;;                  \
    }                           \
    else                        \
        return 1;
    


int peao(char x_rei, char y_rei, char x_peao, char y_peao, char peca)
{
    if (x_peao + 1 == x_rei && y_peao + - 1 == y_rei || x_peao + 1 == x_rei && y_peao + 1 == y_rei)
    {
        return 1;
    } 
    return 0;
}

int cavalo(char x_rei, char y_rei, char x_cavalo, char y_cavalo, char peca)
{
    if (x_cavalo - 2 == x_rei && y_cavalo + 1 == y_rei || x_cavalo - 2 == x_rei && y_cavalo - 1 == y_rei)
    {
        return 1;
    }
    if (x_cavalo + 2 == x_rei && y_cavalo - 1 == y_rei || x_cavalo + 2 == x_rei && y_cavalo + 1 == y_rei)
    {
        return 1;
    }
    if (x_cavalo - 1 == x_rei && y_cavalo + 2 == y_rei || x_cavalo - 1 == x_rei && y_cavalo - 2 == y_rei)
    {
        return 1;
    }
    if (x_cavalo + 1 == x_rei && y_cavalo - 2 == y_rei || x_cavalo + 1 == x_rei && y_cavalo + 2 == y_rei)
    {
        return 1;
    }
    return 0;
}

int bispo(char matriz[8][8], char x_rei, char y_rei, char x_bispo, char y_bispo, char peca)
{
    int x;
    int y;
    if (x_bispo > 0)
    {
        // anda para diagonal superior esquerda
        if (y_bispo > 0)
        {
            x = x_bispo;
            y = y_bispo;
            do
            {
                x--;
                y--;
                MACRO_TESTE
            } while (x > 0 && y > 0);
        }
        // anda para a diagonal superior direita
        if (y_bispo < 7)
        {
            x = x_bispo;
            y = y_bispo;
            do
            {
                x--;
                y++;
                MACRO_TESTE
            } while (x > 0 && y < 7);
        }
    }
    if (y_bispo < 8)
    {
        // anda para a diagonal inferior esquerda
        if (x_bispo > 0)
        {
            x = x_bispo;
            y = y_bispo;
            do
            {
                x++;
                y--;
                MACRO_TESTE
            } while (x < 7 && y > 0);
        }
        // anda para a diagonal inferior direita
        if (x_bispo < 7)
        {
            x = x_bispo;
            y = y_bispo;
            do
            {
                x++;
                y++;
                MACRO_TESTE
            } while (x < 7 && y < 7);
        }
    }
    return 0; 
}

int torre(char matriz[8][8], char x_rei, char y_rei, char x_torre, char y_torre, char peca)
{
    int x;
    int y;
    x = x_torre;
    // anda para a esquerda se n�o estiver na borda
    if (y_torre > 0) {
        for (y = y_torre - 1; y >= 0; y--)
        {
            MACRO_TESTE
        }
    }
    // anda para a direita se n�o estiver na borda
    if (y_torre < 8)
    {
        for (y = y_torre + 1; y <= 7; y++)
        {
            MACRO_TESTE
        }
    }
    // anda para cima se n�o estiver na borda
    y = y_torre;
    if (x_torre > 0) {
        for (x = x_torre - 1; x >= 0; x--)
        {
            MACRO_TESTE
        }
    }
    // anda para baixo se n�o estiver na borda
    if (x_torre < 7)
    {
        for (x = x_torre + 1; x <= 7; x++)
        {
            MACRO_TESTE
        }
    }
    return 0;  
}

int rei(char x_rei, char y_rei, char x_m_rei, char y_m_rei, char peca)
{
    if (x_m_rei - 1 == x_rei && y_m_rei == y_rei || x_m_rei - 1 == x_rei && y_m_rei + 1 == y_rei || x_m_rei == x_rei && y_m_rei + 1 == y_rei)
    {
        return 1;
    }
    if (x_m_rei + 1 == x_rei && y_m_rei + 1 == y_rei || x_m_rei + 1 == x_rei && y_m_rei == y_rei)
    {
        return 1;
    }
    if (x_m_rei == x_rei && y_m_rei - 1 == y_rei || x_m_rei - 1 == x_rei && y_m_rei - 1 == y_rei || x_m_rei + 1 == x_rei && y_m_rei - 1 == y_rei)
    {
        return 1;
    }
    return 0;
}

void varrer_adversario(char matriz[8][8], int x_rei, int y_rei, char peca, int aliada, int adversario)
{
    int x;
    int y;
    int xeque = 0;
    for (x = 0; x < 8; x++)
    {
        for (y = 0; y < 8; y++)
        {
            switch (matriz[x][y])
            {
                case 'p':
                {
                    xeque = peao(x_rei, y_rei, x, y, peca);
                }
                break;
                case 't':
                {
                    xeque = torre(matriz, x_rei, y_rei, x, y, peca);
                }
                break;
                case 'b':
                {
                    xeque = bispo(matriz, x_rei, y_rei, x, y, peca);
                }
                break;
                case 'q':
                {
                    xeque = bispo(matriz, x_rei, y_rei, x, y, peca);
                    if (xeque == 0)
                    {
                        xeque = torre(matriz, x_rei, y_rei, x, y, peca);
                    }
                }
                break;
                case 'c':
                {
                    xeque = cavalo(x_rei, y_rei, x, y, peca);
                }
                break;
                case 'k':
                {
                    xeque = rei(x_rei, y_rei, x, y, peca);
                }
                break;
            }
            if (xeque != 0)
            {
                printf("A peca %d pode comer a peca %d\n", aliada, adversario);
                return;
            }
        }
    }
    printf("A peca %d nao come a peca %d\n", aliada, adversario);
}

int main(void)
{
    char tabuleiro[8][8];
    char peca1;
    char peca2;
    int x;
    int y;
    
    printf("p - peao\n");
    printf("t - torre\n");
    printf("b - bispo\n");
    printf("q - rainha\n");
    printf("c - cavalo\n");
    printf("k - rei\n\n");

    char peca1temp[5];
    printf("escolha a pedra 1 seguindo o exemplo acima: ");
    scanf("%s", &peca1temp);

    char peca2temp[5];
    printf("escolha a pedra 2 como adversaria: ");
    scanf("%s", &peca2temp);

    peca1 = peca1temp[0];
    peca2 = peca2temp[0];

    srand(time(0));

    int x_peca1 = rand() % 8;
    int y_peca1 = rand() % 8;

    int x_peca2 = rand() % 8;
    int y_peca2 = rand() % 8;

    for (x = 0; x < 8; x++)
    {
        for (y = 0; y < 8; y++)
        {
            if (x == x_peca1 && y == y_peca1)
            {
                tabuleiro[x][y] = peca1;
                continue;
            }
            else if (x == x_peca2 && y == y_peca2)
            {
                tabuleiro[x][y] = peca2;
                continue;
            }
            tabuleiro[x][y] = '-'; 
            
        }
    }

    for (x = 0; x < 8; x++)
    {
        for (y = 0; y < 8; y++)
        {
            printf("%c ", tabuleiro[x][y]);
        }
        printf("\n");
    }

    varrer_adversario(tabuleiro, x_peca1, y_peca1, peca1, 1, 2);
    varrer_adversario(tabuleiro, x_peca2, y_peca2, peca2, 2, 1);

    return 0;
}