/*
Se adjunta:
  - Estudiantes.txt (Aca estan registrados algunos Estudiantes con Nombre, Rut, etc..)
  - Profesores.txt (Aca estan registrados algunos Profesores con Nombre, Rut, etc..)
  (No son necesarios, para la ejecucion del programa, puesto que si no existen los crea. Pero estan
  para facilitar la ejecucion y pruebas).

  El programa permite leer el .txt con Profesores y el .txt Alumnos, tambien permite agregar manualmente mas profesores y estudiantes, 
  desde el menu Profesor(Administrador).

  El Estudiante solo podra ver sus notas si el Profesor previamente le inscribio sus notas en una Asignatura,
  de no estar aun en el sistema, al estudiante se le indicará.

  El programa permite mostrarle al estudiante si Aprobo o Reprobo y su nota Definitiva por Asignatura.

  Mas detalles comentados.

*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Prototipo funcion extra.
int compararString(string rut, string rutBuscar);

// Definiciones de clases y metodos.
class Persona
{
	public:
  	struct{
  		string nom, rut, dir, telf;
  		int edad;
  	}registro;	
  	Persona(){ };
  	~Persona(){ };
};

class Profesor: public virtual Persona
{
	public:
  	string cat;
  	int cant ;
  	Profesor(){	};
  	~Profesor(){ };
		void ingresar_Profesor();
    void ingresarNotas();
};

class Estudiante: public virtual Persona
{
	public:
  	string carr;
  	int can;
  	Estudiante(){	};
  	~Estudiante(){ };
		void ingresar_Estudiante();
    void solicitar_Notas();
};

class Asignatura: public Profesor, public Estudiante
{
	public:
  	string materia[5] = {"PROGRAMACION",
                          "BASE DE DATOS",
                          "ALGORITMO Y ESTRUCTURA DE DATOS",
                          "DESARROLLO WEB Y MOBIL",
                          "PARADIGMAS DE PROGRAMACION"};
  	string codigo[5] = {"PR001","BD002","AE003","DM004","PP005"};
  	Asignatura(){};
  	~Asignatura(){};
    void mostrar_Asignaturas();
    void ingresar_Notas();
    void guardar_Calificaciones(string n, string r);
};

// Funcion para comparar si 2 datos tipo string son iguales.
int compararString(string rut, string rutBuscar){
  int i=0;
  while(i < rutBuscar.length()){
    if (rut[i] != rutBuscar[i]){
      return -1;
    }
    i = i + 1;
  }
  if(rut.length() == rutBuscar.length()){
    return 0;
  }
return -1;
}

// Funcion para registrar un Profesor en el sistema.
void Profesor::ingresar_Profesor(){
  string nombre_arch = "Profesores.txt";
	fstream archivo(nombre_arch, ios::app);
	int op, op2;
	do
	{
    cout << "\n======================================";
		cout << "\n1.- Nuevo registro\n2.- Salir\n";
    cout << "======================================\n";
    cout << "Opcion: ";
		cin >> op;
    
		cin.ignore();
		if (op == 1) {

			if(!archivo.is_open()){ 
				archivo.open(nombre_arch, ios::app);
			}
      
			cout << "Nombre: ";
				getline(cin, registro.nom);
			cout << "Rut: ";
				getline(cin, registro.rut);
			cout << "Direccion: ";
				getline(cin, registro.dir);
			cout << "Telefono: ";
				getline(cin, registro.telf);
			cout << "Edad: ";
				cin >> registro.edad;
      
      cin.ignore();
  		cout << "Escriba la Categoria: "; 
        getline(cin, cat);
      cout << "Escriba la Cantidad de Asignaturas: ";
        cin >> cant;
      
			cout << "1.- Guardar registro\n2.- Regresar\nOpcion: ";
			cin >> op2;
			if(op2 == 1){
				archivo << registro.nom << " ";
				archivo << registro.rut << " ";
				archivo << registro.dir << " ";
				archivo << registro.telf << " ";
				archivo << registro.edad << endl;
				cout << "Registro guardado con exito...\n";
        archivo.close();
			}
		}
	}	while(op != 2);
  archivo.close();
  cout << "Saliste con exito.\n";
};

// Funcion para registrar un Estudiante en el sistema.
void Estudiante::ingresar_Estudiante(){
  string nombre_arch = "Estudiantes.txt";
	fstream archivo(nombre_arch, ios::app);
	int op, op2;
	do
	{
    cout << "\n======================================";
		cout << "\n1.- Nuevo registro\n2.- Salir\n";
    cout << "======================================\n";
    cout << "Opcion: ";
		cin >> op;
    
		cin.ignore();
		if (op == 1) {

			if(!archivo.is_open()){ 
				archivo.open(nombre_arch, ios::app);
			}
      
			cout << "Nombre: ";
				getline(cin, registro.nom);
			cout << "Rut: ";
				getline(cin, registro.rut);
			cout << "Direccion: ";
				getline(cin, registro.dir);
			cout << "Telefono: ";
				getline(cin, registro.telf);
			cout << "Edad: ";
				cin >> registro.edad;
			cout << "1.- Guardar registro\n2.- Regresar\nOpcion: ";
			cin >> op2;
			
			if(op2 == 1){
				archivo << registro.nom << " ";
				archivo << registro.rut << " ";
				archivo << registro.dir << " ";
				archivo << registro.telf << " ";
				archivo << registro.edad << endl;
				cout << "Registro guardado con exito...\n";
        archivo.close();
			}
		}
	}	while(op != 2);
  archivo.close();
  cout << "Saliste con exito.\n";
};

// Funcion para ingresar notas de Estudiantes por asignatura.
// Verifica que el Estudiante se encuentre en el sistema y luego se gestionan las notas
void Asignatura::ingresar_Notas(){
  
  string nombre, rut, rutBuscar;

  cin.ignore();
  cout << "\nEscriba RUT del estudiante: ";
    getline(cin, rutBuscar);
  
  string arch="Estudiantes.txt";
  ifstream archivo(arch.c_str());
  string linea;
  int largo, i, j=0;

  while (getline(archivo, linea)) {
    largo = linea.length();
    for (i = 0; i < largo; i++){
      if (linea[i] != ' '){
        if (j == 0){
          nombre = nombre + linea[i];
        }
        if (j == 1){  
          rut = rut + linea[i];
				}
      }
      else
        j++;
    }
    
    if (compararString(rut, rutBuscar) == 0){
      cout << "======= Estudiante Encontrado =======" << endl;
      archivo.close();
      break;
    }
    
    j = 0;
    nombre = "";
    rut = "";
  }
  archivo.close();
  guardar_Calificaciones(nombre, rut); // Aca se gestionan las notas luego de verificar.
}

// Funcion para ingresar y guardar las notas del Estudiante.
void Asignatura::guardar_Calificaciones(string nombre, string rut){

  int numAsignatura, cantAsig;
  /* Cantidad de .txt, ejemplo: Calificacion Matematica.txt*/
  cout << "\nIngrese la cantidad de asignaturas a ingresarles nota: ";
    cin >> cantAsig;

  int i = 0;
  while (i < cantAsig ){
    cout << "\n\tSeleccione la asignatura para guardar notas. " << endl;
    mostrar_Asignaturas();
    cout << "\nOpcion: ";
      cin >> numAsignatura;
    
    float n1, n2, n3, n4;
    cout << "\nIngresar notas de "<< nombre << " para -> " << materia[numAsignatura-1] << endl;
    cout << "\nIngrese la nota 1: ";
      cin >> n1;
    cout << "Ingrese la nota 2: ";
      cin >> n2;
    cout << "Ingrese la nota 3: ";
      cin >> n3;
    cout << "Ingrese la nota 4: ";
      cin >> n4;

    string nombre_arch = "Calificaciones " + materia[numAsignatura-1] + ".txt";
    cout << "\n" << nombre_arch << endl;
	  fstream archivo(nombre_arch, ios::app);

		if(!archivo.is_open()){ 
			archivo.open(nombre_arch, ios::app);
		}
    archivo << nombre << " ";
    archivo << rut << " ";
		archivo << n1 << " ";
    archivo << n2 << " ";
		archivo << n3 << " ";
    archivo << n4 << endl;
		cout << "Registro guardado con exito...\n";
    archivo.close();

    i = i + 1;
  }
}

// Funcion para que el estudiante pueda recibir un RUT.txt con su nota y se Aprobo o no
void Estudiante::solicitar_Notas(){
  Asignatura a;
  int i = 0;
  cout << "\n==================================================";
  while (i < sizeof a.materia/sizeof a.materia[0]){
   
    string nombre_arch = "Calificaciones " + a.materia[i] + ".txt";
    ifstream archivo(nombre_arch.c_str());
    
    if(archivo.fail()){
      cout << "\nAun no hay notas en " << a.materia[i];
    }
      
    else{
      /* recorrer el archivo a archivo para ver si hay notas en el por el RUT */
      cout << "\n\nHay notas en " << a.materia[i] << "." << endl;
      string nombre, rut, rutBuscar;
      cin.ignore();
      cout << "Ingrese Su RUT para ver si tiene notas: ";
        getline(cin, rutBuscar);

      string linea, n1, n2, n3, n4;
      vector <float> Notas1, Notas2, Notas3, Notas4;
      float nt1, nt2, nt3, nt4;
      int largo, j=0;

      while (getline(archivo, linea)) {
        largo = linea.length();
        for (int k = 0; k < largo; k++){
          char espacio = ' ';
          if (linea[k] != espacio){
            if (j == 0){
              nombre = nombre + linea[k];
            }
            if (j == 1){  
              rut = rut + linea[k];
    				}
            if (j == 2){
              n1 = n1 + linea[k];
              nt1 = stof(n1); 
    				}
            if (j == 3){
              n2 = n2 + linea[k];
              nt2 = stof(n2);  
    				}
            if (j == 4){
              n3 = n3 + linea[k];
              nt3 = stof(n3);
    				}
            if (j == 5){
              n4 = n4 + linea[k];
              nt4 = stof(n4); 
    				}
          }
          else
            j++;          
        }
          if (compararString(rut, rutBuscar) == 0){
            /* Aca mostrar las notas al cohincidir el RUT */
            cout << "======= Notas Encontradas =======\n" << endl;
            /* Ahora que tengo las notas agregarlas por Asignatura a un .txt */
            string nom_arch = rut + ".txt";
            string Aprobado_Reprobado;
            fstream archivo(nom_arch, ios::app);
            float nDef = (nt1+nt2+nt3+nt4)/4;
            
            if (nDef > 3.95)
              Aprobado_Reprobado = "Aprobado";
            else
              Aprobado_Reprobado = "Reprobado";
            
            archivo << a.materia[i] << " " << nDef << " " << Aprobado_Reprobado << endl;
            
            cout << nombre << " Tu Nota Definitiva es: " << nDef << endl;
            break;
          }
        j = 0;
        nombre = "";
        rut = "";
        n1 = "";
        n2 = "";
        n3 = "";
        n4 = "";
      }   
    }
  i = i + 1;
  }
}

// Declaraciones de funciones para ver opciones de menu, categorizadas.
void verMenu(){
  cout << "\n========== Sistema opciones ==========\n";
  cout << "1. Acceso Profesor.\n2. Acceso Alumno.\n3. Salir.\n";
  cout << "======================================" << endl;
}

void verMenuProfe(){
  cout << endl << "\n======== Opciones del profesor ========" << endl;
  cout << "1. Ingresar nuevo profesor/alumno." << endl;
  cout << "2. Gestionar notas Alumnos." << endl;
  cout << "3. Regresar." << endl;
  cout << "=======================================" << endl;
}

void verMenuEst(){
  cout << endl << "\n======= Opciones del estudiante =======" << endl;
  cout << "1. Ver si las notas estan disponibles." << endl;
  cout << "2. Salir" << endl;
  cout << "=======================================" << endl;
}

void Asignatura::mostrar_Asignaturas(){
  cout << "=====================================================";
  for (int i=0; i < (sizeof materia/sizeof materia[0]); i++){
  	cout << "\n" << i+1 << ". " << materia[i] << " - " << codigo[i];
  }
  cout << "\n=====================================================";
}

void verMenuProfe_Registrar(){
  cout << "\n=============== Opciones ===============" << endl;
  cout << "1. Registrar a un Profesor." << endl;
  cout << "2. Registrar a un Estudiante." << endl;
  cout << "3. Regresar." << endl;
  cout << "========================================" << endl;  
}

void verMenuProfe_GestionarNotas(){
  cout << "\n========== Opciones ==========";
  cout << "\n1. Entregar notas estudiante.";
  cout << "\n2. Regresar."; 
  cout << "\n==============================";
}

// Funcion principal encargada de manipular los Menu y sus operaciones.
int main(){
  int op;
  
  do{
    verMenu();
    cout << "Opcion: ";
    cin >> op;
    if (op==1){                             // Si es Profesor
      int op2;
      do{
        verMenuProfe();
        cout << "Opcion: ";
        cin >> op2;   
        if(op2==1){                         // Si quiere registrar Profesor/Alumno
          int op3;
          verMenuProfe_Registrar();
          cout << "Opcion: ";
          cin >> op3;
          switch(op3){
            case 1:{                        // Registrar Profesor
              Profesor p;
              p.ingresar_Profesor();
              break;
            }
            case 2:{                        // Registrar Estudiante
              Estudiante e;
              e.ingresar_Estudiante();
              break;
            }
            case 3:{                        // Regresar
              break;
            }
          }
        }
        if(op2==2){                        // Gestionar notas.
          int op4;
          verMenuProfe_GestionarNotas();
          cout << "\nOpcion: ";
            cin >> op4;
          switch(op4){
            case 1:{                       // Ingresar notas estudiantes.
              int op5;
              Asignatura a;
              a.ingresar_Notas();  
              break;
            }
          }
        }
        if(op2==3){}                       // Regresar.
      } while (op2 != 3);
    }
    if (op==2){                            // Si es Estudiante
      int op4;
      verMenuEst();
      cout << "Opcion: ";
      cin >> op4;
      switch(op4){                        // Ver notas Disponibles
        case 1:{
          Estudiante e;
          e.solicitar_Notas();
          break;
        }
      }
    }
  } while (op != 3);
  cout << "\nSaliendo del programa...\n";
}