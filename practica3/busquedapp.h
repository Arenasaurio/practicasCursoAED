#ifndef BUSQUEDAPP_H_INCLUDED
#define BUSQUEDAPP_H_INCLUDED

struct resultados lSearch(int [],int,int); //lSearch(VectorD,tamaño,valor Buscado);
void burbujaS(int [],int); //algoritmo de ordenamiento
struct resultados binSearch(int [],int,int,int); //binSearch(vectorO,inicio,fin,vB)
struct resultados indSearch(int[],int,int); //indSearch(VectorO,tama�o,vB);
struct resultados intSearch(int [],int,int,int); //intSearch(vectorO,inicio,fin,vB);
int exponential_search(int arr[], int n, int x, int* comparisons);
#endif // BUSQUEDAPP_H_INCLUDED
