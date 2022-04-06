#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;
int main() {
  string archivo1 = "archivo1.txt";
  ifstream archivo(archivo1.c_str());
  string linea, nomb, n1, n2, n3, n4;
  int res, lon, i, j = 0, c = 0;
  string nombres[100];
  float notas1[100], notas2[100], notas3[100], notas4[100];
  char b, l;

  while (getline(archivo, linea)) {
    //cout<<linea<<endl;
    lon = linea.length();
    for (i = 0; i < lon; i++) {
      l = linea[i];
      b = ' ';
      if (l != b) {
        if (j == 0)
          nomb = nomb + linea[i];
        if (j == 1)
          n1 = n1 + linea[i];
        if (j == 2)
          n2 = n2 + linea[i];
        if (j == 3)
          n3 = n3 + linea[i];
        if (j == 4)
          n4 = n4 + linea[i];
      } else
        j++;
    }
    // cout<<nomb<<endl;
    // cout<<n1<<endl;
    // cout<<n2<<endl;
    // cout<<n3<<endl;
    // cout<<n4<<endl;

    // pasar numeros str a float
    float n1_float = stof(n1);
    float n2_float = stof(n2);
    float n3_float = stof(n3);
    float n4_float = stof(n4);

    // agregar datos los arreglos
    nombres[c] = nomb;
    notas1[c] = n1_float;
    notas2[c] = n2_float;
    notas3[c] = n3_float;
    notas4[c] = n4_float;
    c++;

    j = 0;
    nomb = "";
    n1 = " ";
    n2 = " ";
    n3 = " ";
    n4 = " ";
  }

  //mostrando los arreglos con los datos y notas convertidas
  cout<<"AQUI ESTAN LOS DATOS SEPARADOS POR NOMBRE Y"<<endl;
  cout<<"NOTAS CONVERTIDAS EN VALORES REALES (FLOAT)"<<endl<<endl;
  cout<<"     🢃"<<endl<<endl;
  for (int k = 0; k < c; k++){
    
    cout<<nombres[k]<<" ";
    cout<<notas1[k]<<" ";
    cout<<notas2[k]<<" ";
    cout<<notas3[k]<<" ";
    cout<<notas4[k]<<endl;
    
  }
}