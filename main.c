/**
	OchoDamas

	Versión sencilla que localiza las 92 soluciones
	No detecta simetrías.

	manc
*/

#include <stdio.h>

#define SI 1
#define NO 0

int N = 8;
int Soluciones = 0;
char T[8][8];

int PonerDamas(int id);
int SePuede(int i, int j);
void MostrarT();

int main()
{
    puts("Problema de las 8 damas");
    puts("Iniciando la búsqueda de soluciones");

    for ( int i=0 ; i<N ; i++ )
        for ( int j=0 ; j<N ; j++ )
            T[i][j] = '-';

    PonerDamas(0);

    return 0;
}

int PonerDamas(int c)
{
    if ( c == N ) {
        Soluciones++;
        printf("\nSolución %d\n", Soluciones);
        MostrarTablero();
    }

    for ( int r=0 ; r<N ; r++ )
        if ( SePuede(r, c) ) {
            T[r][c] = 'D';
			if ( PonerDamas(c+1) )
				return 1;
			T[r][c] = '-';
		}

    return 0;
}

int SePuede(int r, int c)
{
    int i, j;

    for ( i=0; i<N ; i++ )
        if ( T[i][c] == 'D' )
            return NO;

    for ( i=0; i<N ; i++ )
        if ( T[r][i] == 'D' )
            return NO;

    int m = r<c ? r : c;
    for ( i=r-m, j=c-m ; i<N && j<N ; i++,j++ )
        if ( T[i][j] == 'D' )
            return NO;

    for ( i=r+1, j=c-1; i<N && j>=0 ; i++, j--)
        if ( T[i][j] == 'D' )
            return NO;
    for ( i=r-1, j=c+1; i>=0 && j<N ; i--, j++)
        if ( T[i][j] == 'D' )
            return NO;

    return SI;
}

void MostrarTablero()
{
    for (int i =0; i<N; i++) {
        for(int  j = 0; j<N; j++)
            printf("%c ", T[i][j]);
        printf("\n");
    }
    printf("\n");
}

/* Fin de archivo */
