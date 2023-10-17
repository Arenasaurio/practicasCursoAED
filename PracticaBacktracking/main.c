#include <stdio.h>
#include <stdbool.h>
#define N 8

bool btNQueens(int [N][N],int);
//btNQueens(tablero,columna);
bool isSafe(int [N][N],int,int);

int main() {
    int board[N][N];
    int elPapu=0, soluciones=0;//variable que determina las impresiones de las posibles soluciones siempre menores a N
    while(elPapu<N){
    int contadorMamus=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j]=0;

    if(btNQueens(board,elPapu)==false)
    {
        printf("No ha solucion");
        return false;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        if(board[i][j]==1){
            contadorMamus++;
        }
    }
    if(contadorMamus==N){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
        printf("\n\n");soluciones++;}
    elPapu++;}
    if(soluciones==1){
        printf("SOLUCION UNICA");
    }
    else if(soluciones==0){
        printf("SIN SOLUCION");
    }
    else{
        printf("SOLUCIONES ENCONTRADAS: %d", soluciones);
    }
    return 0;
}

bool btNQueens(int board[N][N],int col)
{
    if(col>=N) //verificar si las reinas han sido colocadas
        return true;
    for(int i=0;i<N;i++)
    {
       if(isSafe(board,i,col)) //pregunta si es seguro colocar R
       {
           board[i][col]=1; //se cloca la reina
           if(btNQueens(board,col+1)) //se recorre la col a la derecha
               return true;
           board[i][col]=0; //aqui se aplic el backtracking
       }
    }
    return false;
}


bool isSafe(int board[N][N],int r,int col)
{
    int i,j; //Renglone sy columnas de otras reinas
    //verificar si hay reinas en el renglon del lado izquierdo
    for(i=0;i<col;i++)
        if(board[r][i])
            return false;


    //verificar si hay reinas en la diagonal izquierda superior
    for(i=r-1,j=col-1;i>=0 && j>=0;i--,j--)
        if(board[i][j])
            return false;

    for(i=r+1,j=col-1;i<N && j>=0; i++, j--)
        if(board[i][j])
            return false;


    return true;

}

