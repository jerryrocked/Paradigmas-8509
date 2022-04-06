# Paradigmas-8509
8509

#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
//#include <vector>
using namespace std;
/* 
   La idea del algoritmo es: 

*- Rescatar la informacion del archivo
*- Separar las notas del nombre del estudiante
*- Transformar las notas a valores reales
*- Guardar la info en su respectivo arreglo
- Juntar los arreglos en un vector/arreglo -> No pude terminar de investigar si es que es posible
*/

// El Archivo debe llamarse "archivo1.txt"
int main() {
  string nombreArchivo = "archivo1.txt";
  ifstream archivo(nombreArchivo.c_str());
  string linea, nomb, n1, n2, n3, n4;
  int res, j, i=0, lon;
  string arreglo[100];
  char b, l;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)){
    lon = linea.length();
    for (j=0 ;j<lon ;j++){
      l = linea[j];
      b = ' ';
      if (l!=b){
        if(i==0)
          nomb=nomb+linea[j];
        if (i==1)
          n1=n1+linea[j];
        if (i==2)
          n2=n2+linea[j];
        if (i==3)
          n3=n3+linea[j];
        if (i==4)
          n4=n4+linea[j];
      }
      else{
        i++;
      }
  }
    float num1 = stof(n1);
    float num2 = stof(n2);
    float num3 = stof(n3);
    float num4 = stof(n4);
    float notas[4] = {num1, num2, num3, num4};
    string nombre_estudiante[40] = {nomb};
    cout << "\n Nombre estudiante:"<< nomb << endl;
    cout << " Nota 1: " << num1 << endl;
    cout << " Nota 2: " << num2 << endl;
    cout << " Nota 3: " << num3 << endl;
    cout << " Nota 4: " << num4 << endl;
// Las notas ya estan en tipo float, por lo que son capaces de trabajarse como decimales
/* 
  Podria usarse un "for" para utilizar los arreglos de manera dinamica
  pero a efectos de practicidad en esta tarea se dejarán de forma manual

for (i = 0; i<){};  - Sin terminar

*/    
    
    i = 0;
    nomb = " ";
    n1 = " ";
    n2 = " ";
    n3 = " ";
    n4 = " ";
  }
}


