#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matriz(int n){
  //creo un vector de n filas donde cada fila es un vector de tamano n.
  //inicio con un valor_posicion_matriz para que la posicion (0,0) se inicializa bien.
  vector<vector<int>> matriz(n, vector<int>(n));
  int valor_posicion_matriz = 1;
  for(int p = 0; p < n*n; p++){
    int i = p/n; //con la division nos va a ir dando la fila.
    int j = p%n; //con el resto nos va a ir dando la columna.
    matriz[i][j] = valor_posicion_matriz++; //pongo el ++ a la derecha para que haga lo que tenga que hacer y despues sume.
  }
  return matriz;
}

void imprimir_matriz(const vector<vector<int>>& matriz){
  //paso la matriz por referencia para no tener problema si llega a ser muy grande.
  int n = matriz.size();
  for(int p = (n*n)-1; p >= 0; p--){
    int i = p/n;
    int j = p%n;
    cout << "Valor en (" << i << ", " << j << "): " << matriz[i][j] << endl;
  }
}

int main(){
  int n;
  cout << "Ingrese el n para el tamano de su matriz: ";
  cin>>n;
  vector<vector<int>> mi_matriz = matriz(n);
  imprimir_matriz(mi_matriz);
}