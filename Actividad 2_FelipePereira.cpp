#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctype.h>

using namespace std;

class Lista{
  public:
    struct Nodo{
      string Nombre;
      string Direccion;
      char Telefono[50];
      char RUT[50];
      int Edad;
      struct Nodo *Siguiente;
    };
    Lista(){};
    ~Lista(){};
    int InsertarElemento(Nodo **);
    void ListarElementos(Nodo *);
    int BorrarElementoListaFinal(Nodo **);
    int BorrarElementoListaPrincipio(Nodo **);
    int BorrarElementoIntermedio(Nodo **);
};

int soloesLetra(string cadena);

int main(int argc, char *argv[])
{
  Lista::Nodo *Inicio = NULL;
  Lista Persona_1;
  int opcion = 0;
  int opcion2 = 0;
  do {
      cout << "\n1.- Insertar elemento en la lista.";
      cout << "\n2.- Listar elementos de la lista.";
      cout << "\n3.- Borrar elemento de la lista.";
      cout << "\n0.- Salir del programa.";
      cout << "\n=====================================";
      cout << "\nOpcion ...: ";
      cin >> opcion;
  
      switch(opcion) {
        case 1:
          Persona_1.InsertarElemento(&Inicio);
          break;
        case 2:
          Persona_1.ListarElementos(Inicio);
          break;
        case 3:
          cout << "\n(0) Volver Menu Anterior.";
          cout << "\n(1) Borrar al final.";
          cout << "\n(2) Borrar al principio.";
          cout << "\n(3) Borrar Intermedio.";
          cout << "\n.... ";
          cin >> opcion2;
          switch(opcion2){
            case 1:
              Persona_1.BorrarElementoListaFinal(&Inicio);
              break;
            case 2:
              Persona_1.BorrarElementoListaPrincipio(&Inicio);
              break;
            case 3:
              Persona_1.BorrarElementoIntermedio(&Inicio);
              break;
          }
               break;
      }
  } while(opcion != 0);
system("PAUSE");
return 0;
}

int Lista::InsertarElemento(Nodo **Inicio) 
{
  Nodo *Elemento = NULL;
  Nodo *Recorrer = NULL;
  Nodo *Ultimo = NULL;

  Recorrer = *Inicio;
    while(Recorrer != NULL){
      Ultimo = Recorrer;
      Recorrer = Recorrer -> Siguiente;
    }
  
    Elemento = new Nodo[sizeof(Nodo*)];
    if(Elemento == NULL)
      return -1;

    cin.ignore();
    do { // validación de datos de entrada. (solo acepta letras)
      cout << "\nTeclear Nombre : ";
        getline(cin, Elemento->Nombre);  
    } while (!soloesLetra(Elemento->Nombre));
  
    cout << "Teclear RUT : ";
      cin >> Elemento -> RUT;
    cout << "Teclear Edad : ";
      cin >> Elemento -> Edad;
    cin.ignore();
    cout << "Teclear Direccion : ";
      getline(cin, Elemento->Direccion);
    cout << "Teclear Telefono : ";
      cin >> Elemento -> Telefono;
  
    Elemento -> Siguiente = NULL;
  
    if (Ultimo == NULL) {
        *Inicio = Elemento;
    } 
    else {
      Ultimo -> Siguiente = Elemento;
    }
  return 0;
}

void Lista::ListarElementos(Nodo *Inicio) 
{
    Nodo *Recorrer = Inicio;
    cout << "\nListado de elementos de la lista";
    cout << "\n===================================";
    while(Recorrer != NULL){
          cout << endl
          << Recorrer -> Nombre << " | "
          << Recorrer -> RUT << " | "
          << Recorrer -> Edad << " | "
          << Recorrer -> Direccion << " | "
          << Recorrer -> Telefono << " | ";
        Recorrer = Recorrer -> Siguiente;
     }
     cout << "\n===================================\n";
}

int Lista::BorrarElementoListaPrincipio(Nodo **Inicio)
{
    Nodo *Borrar = NULL;
    if (*Inicio == NULL){
       cout << "\nNo hay elementos que borrar\n";
       return -1;
    } 
    else {
      Borrar = *Inicio;
      *Inicio = (*Inicio) -> Siguiente;
      delete [] Borrar;
    }
    return 0;
}

int Lista::BorrarElementoListaFinal(Nodo **Inicio)
{
    Nodo *Borrar = NULL;;
    Nodo *Recorrer = NULL;
    Recorrer = *Inicio;
    if(Recorrer == NULL) {
     cout << "\nNo existen elementos que borrar\n";
     return -1;
    }
    while(Recorrer->Siguiente != NULL) {
      Borrar = Recorrer;
      Recorrer = Recorrer->Siguiente;
    }
    if(Borrar == NULL) {
      Borrar = *Inicio;
      *Inicio = NULL;
      delete [] Borrar;
   }
   else {
     delete [] Borrar->Siguiente;
     Borrar -> Siguiente = NULL;
   }
    return 0;
}

int Lista::BorrarElementoIntermedio(Nodo **Inicio) {
  
    Nodo *Recorrer = NULL;
    Nodo *Borrar = NULL;
    Nodo *Anterior = NULL;

    char RUTaBuscar[30];
    int encontrado = 0;

    cout << "\nRUT a eliminar: ";
    cin >> RUTaBuscar;
    if (*Inicio == NULL) {
       cout << "\nNo hay elementos que borrar\n";
       return -1;
    } else {
        cout << "\nBuscando: " << RUTaBuscar;
        Recorrer = *Inicio;
        Anterior = *Inicio;
        while(Recorrer != NULL && encontrado == 0)
        {
            cout << ".";
            if(strcmp(Recorrer->RUT, RUTaBuscar) == 0) {
                cout << " (Encontrado Ok)\n";
                encontrado = 1;
                Borrar = Recorrer;
                if(Recorrer == *Inicio) {
                    *Inicio = Recorrer->Siguiente;
                } else {
                    Anterior->Siguiente = Borrar->Siguiente;
                }
                free(Borrar);
            } else {
                Anterior = Recorrer;
                Recorrer = Recorrer -> Siguiente;
            }
        }
    }
    return 0;
}

int soloesLetra(string cadena)
{
  int i = 0;
  while (cadena[i]) {
    if (!isalpha(cadena[i]) && cadena[i] != ' ')
      return 0;
  i++;
  }
return 1;
}
