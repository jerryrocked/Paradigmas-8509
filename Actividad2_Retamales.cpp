#include <iostream>
#include <vector> 
 
using namespace std;

 

class Lista
{

public:
    string nombre;

  void InsertarElemento ();
  string imprimir();
 private:

};

 

 
int
main ()
{
  std::vector<Lista> arreglo;
  int tam=0;
 

  
int opcion = 0, opcion2 = 0,contador = 0;
  
  
 
  do
    {
      
cout << ("\n1.- Insertar elemento en la lista.") << endl;
      
cout << ("\n2.- Listar elementos de la lista.") << endl;
      
cout << ("\n3.- Borrar elemento de la lista.") << endl;
      
cout << ("\n0.- Salir del programa.") << endl;
      
cout << ("\n=====================================") << endl;
      
cout << ("\nOpcion ...: ") << endl;
      
cin >> opcion;
      
switch (opcion)
	{
	
 
case 1:
	  tam+=1;
	  arreglo.resize(tam);
	  arreglo[tam-1].InsertarElemento();
    
	  
break;
	
 
case 2:
	  
  for (int s  = 0;s<tam;s++){
      cout <<"Nombre: "  << arreglo[s].imprimir() << endl;
      
  }
	  
break;
	
case 3:
	  
cout << ("\n(0) Volver Menu Anterior.") << endl;
	  
cout << ("\n(1) Borrar al final.") << endl;
	  
cout << ("\n(2) Borrar al principio.") << endl;
	  
cout << ("\n(3) Borrar Intermedio.") << endl;
	  
cout << ("\n.... ");
	  
cin >> opcion2;
	  
 
switch (opcion2)
	    {
	    
 
case 1:
	      
  arreglo.pop_back();
  tam=tam-1;
  arreglo.resize(tam);
	      
 
break;
	    
 
case 2:
	      
  arreglo.erase(arreglo.begin());
  tam-=1;
  arreglo.resize(tam);
	      
 
break;
	    
case 3:
	      
  arreglo.erase(arreglo.begin()+(tam/2));
  tam-=1;
  arreglo.resize(tam);
	      
break;
	    
}
	  
break;
	
}
    
}
  while (opcion != 0);
  
system ("PAUSE");
  
return 0;
 
}
 
void Lista::InsertarElemento ()
{

    cin >> nombre;

}

string Lista::imprimir(){

    return nombre;
}
