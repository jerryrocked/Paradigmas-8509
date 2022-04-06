#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main() {
  string archivo1 = "archivo1.txt";
  ifstream archivo(archivo1.c_str());
  string linea, nomb, n1, n2, n3, n4;
  int res, lon, i, j = 0, k = 0;
  string NomA[50];
  float nota1[50], nota2[50], nota3[50], nota4[50];
  char b, l;

  while (getline(archivo, linea)) {  
    
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

    float nota1Real = stof(n1);
    float nota2Real = stof(n2);
    float nota3Real = stof(n3);
    float nota4Real = stof(n4);
    j = 0;

    
    NomA[k] = nomb;
    nota1[k] = nota1Real;
    nota2[k] = nota2Real;
    nota3[k] = nota3Real;
    nota4[k] = nota4Real;
    k++;

    j = 0;
    nomb = " ";
    n1 = " ";
    n2 = " ";
    n3 = " ";
    n4 = " ";
  }
  
  for (int h = 0; h < k; h++){
    cout << NomA[h]<<endl;
    
    cout<<"la nota 1 es: "<< nota1[h]<<endl;
    cout<<"la nota 2 es: "<< nota2[h]<<endl;
    cout<<"la nota 3 es: "<< nota3[h]<<endl;
    cout<<"la nota 4 es: "<< nota4[h]<<endl;
  }
}