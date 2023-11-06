#include <stdio.h>
#define N 10
int main(){
    int tablero[N][N];

    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            tablero[i][j]=0;
        }
    }
return 0;}

void colocaP(int tablero[N][N]){
    int coloca1Col=0;
    while(coloca1Col==N+1){
       if(coloca1Col!=0){
            for(int i=0; i<N; i++){
                for(int j=1; j<N; j++){
                    if(aSalvo){
                        tablero[i][j]=1;
                    }
                }
            }
       }
    }

}
void aSalvo(int n){
    return 1;
}
