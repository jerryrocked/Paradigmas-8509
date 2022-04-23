#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;


/* Joaquín Mujica Villalobos
   20.678.382-6
*/



/* 
  ----------------------------------
          * Clase Persona *
  ----------------------------------
*/
class Persona
{
	public:	
  struct {
		string nombre,rut,dir,telf;
		char sex;
		int edad;
	}reg;	
	Persona(){ };
	~Persona(){ };
	void datos_persona();
	void mostrar_persona();
};
// se ingresan datos persona
void Persona::datos_persona(){
    cout << "\n----------------------------------";
    cout << "\n        Ingresar Datos" << endl;
    cout << "----------------------------------";
		cout << "\nIngrese Nombre: "; getline(cin, reg.nombre);
    cout << "Ingrese Rut: "; getline(cin, reg.rut);
    cout << "Direccion: " ; getline(cin, reg.dir);
    cout << "Telefono: " ; getline(cin, reg.telf);
    cout << "Sex: "; cin >> reg.sex;
    cout << "Edad: "; cin >> reg.edad;
	};
// se muestran datos persona
void Persona::mostrar_persona(){
    cout << "\n\n---------------------------------" << endl;
    cout << "              Datos" << endl;
    cout << "---------------------------------" << endl;
		cout << "Nombre: "<< reg.nombre << endl;
    cout << "Rut: " << reg.rut << endl;
    cout << "Direccion: " << reg.dir << endl;
    cout << "Telefono: " << reg.telf << endl;
    cout << "Sex: " << reg.sex << endl;
    cout << "Edad: " << reg.edad << endl;
    cout << "---------------------------------" << endl;
	};
/* 
  ----------------------------------
          * Clase Profesor *
  ----------------------------------
*/

class Profesor: public virtual Persona
{
	public:
	string cat;
	int cant;
	Profesor(){	};
	~Profesor(){ };
	void datos_profesor();
	void mostrar_profesor();
	void entregar_notas();
};
// se ingresa categoria profesor
void Profesor::datos_profesor() {
		int i;
		datos_persona();
		cin.ignore();
		cout << "Escriba la Categoria: ";getline(cin, cat);	
	};
// se muestra categoria profesor
void Profesor::mostrar_profesor(){
		int i;
		mostrar_persona();
		cout << "Categoria : " << cat << endl;
	};
/* 
  ----------------------------------
        * Clase Estudiante *
  ----------------------------------
*/

class Estudiante: public virtual Persona
{
	public:
	string carrera;
	int can;
	Estudiante(){ };
	~Estudiante(){ };
	void datos_estudiante();
	void mostrar_estudiante();
};
// se ingresa carrera estudiante
void Estudiante::datos_estudiante() {
		int i;
		datos_persona();
		cout << "Ingresar Carrera que Estudia";
		cin >> carrera;
	};
// se muestra carrera estudiante
void Estudiante::mostrar_estudiante(){
		mostrar_persona();
		cout << "\n Carrera: " << carrera;
	};

/* 
  ----------------------------------
        * Clase Asignatura *
  ----------------------------------
*/

class Asignatura: public Profesor, public Estudiante {
  public:
  string seccion[10];
  string asign[10], codigo[10];
  char nom[40] = "Estudiante.txt";
  int cantidad;
  string materia[5] = {"Programación", "Base de Datos", "Algoritmos &   Estructura de Datos", "Desarrollo Web & Mobil", "Paradigmas de la Programación"};
  string cod[5] = {"PR001", "BD002", "AE003", "DM004", "PP005"};
  Asignatura(){ };
  ~Asignatura(){ };
  void AsignDatosEst();
  void AsignMostrarEst();
  void AsignDatosProf();
  void AsignMostrarProf();
};

// Mostrar Datos de profesor en asignatura
void Asignatura::AsignMostrarProf(){
  string archivo("Datos Carrera");
  ofstream Prof_out;
  mostrar_profesor();
  cout << "Cantidad Asignaturas: "<< cantidad << endl;
  cout << "Asignaturas: \n";
  for (int i = 0; cantidad; i++){
    cout << asign[i] << endl;
    cout << codigo[i] << endl;
    cout << seccion[i] << endl;
  }
  Prof_out.open(archivo, std::ios_base::app);
  for (int i = 0; cantidad; i++){
    Prof_out << asign[i] << endl;
    Prof_out << codigo[i] << endl;
    Prof_out << seccion[i] << endl;
  }
  Prof_out.close();
};

// Ingreso de datos de asignatura para profesor
void Asignatura::AsignDatosProf(){
  int opcion, opc;
  datos_profesor();
  cout << "\n----------------------------------" << endl;
  cout << "Escriba la cantidad de Asignaturas" << "\n: ";
  cin >> cantidad;
  // Menu de ingreso de Asignaturas
  for (int i = 0; i < cantidad; i++){
    cout << "\nSeleccione las Asignaturas:" << endl;
    cout << "\n 1. " << materia[0];
    cout << "\n 2. " << materia[1];
    cout << "\n 3. " << materia[2];
    cout << "\n 4. " << materia[3];
    cout << "\n 5. " << materia[4] << endl;
    cout << "\nSeleccione una opción" << "\n: ";
    cin >> opcion;
    switch (opcion){
      case 1: {
        asign[i] = materia[0];
        codigo[i] = cod[0];
        break;
      }
      case 2: {
        asign[i] = materia[1];
        codigo[i] = cod[1];
        break;
      }
      case 3: {
        asign[i] = materia[2];
        codigo[i] = cod[2];
        break;
      }
      case 4: {
        asign[i] = materia[3];
        codigo[i] = cod[3];
        break;
      }
      case 5: {
        asign[i] = materia[4];
        codigo[i] = cod[4];
        break;
      }
    }
    // Ingreso datos de seccion
    cout << "\n----------------------------------";
    cout << "\n 1. Sección 1";
    cout << "\n 2. Sección 2" << endl;
    cout << "\nSeleccione una Sección" << "\n: ";
    cin >> opc;
    switch (opc){
      case 1: {
        seccion[i] = "1";
        break;
      }
      case 2: {
        seccion[i] = "2";
        break;
      }
    } 
  }
};

// se muestran datos de estudiante por asignatura
void Asignatura::AsignMostrarEst(){
  string archivo("Info Ramo Estudiante");
  ofstream Est_out;
  mostrar_estudiante();
  cout << "Asignaturas: " << endl;
  for (int i = 0; i < cantidad; i++){
    cout << asign[i] << endl;
    cout << codigo[i] << endl;
    cout << seccion[i] << endl;
  }
  Est_out.open(archivo, std::ios_base::app);
  for (int i = 0; i < cantidad; i++){
    Est_out << asign[i] << endl;
    Est_out << codigo[i] << endl;
    Est_out << seccion[i] << endl;
  }
  Est_out.close();
}

// Ingreso de datos de asignatura para estudiante
void Asignatura::AsignDatosEst(){
  int opcion, opc;
  datos_estudiante();
  cout << "Escriba la cantidad de Asignaturas: ";
  cin >> cantidad;
  // Menu de ingreso de Asignaturas
  for (int i = 0; i < cantidad; i++){
    cout << "\nSeleccione las Asignaturas:" << endl;
    cout << "\n 1. " << materia[0];
    cout << "\n 2. " << materia[1];
    cout << "\n 3. " << materia[2];
    cout << "\n 4. " << materia[3];
    cout << "\n 5. " << materia[4] << endl;
    cout << "\n Seleccione una opción" << "\n: ";
    cin >> opcion;
    switch (opcion){
      case 1: {
        asign[i] = materia[0];
        codigo[i] = cod[0];
        break;
      }
      case 2: {
        asign[i] = materia[1];
        codigo[i] = cod[1];
        break;
      }
      case 3: {
        asign[i] = materia[2];
        codigo[i] = cod[2];
        break;
      }
      case 4: {
        asign[i] = materia[3];
        codigo[i] = cod[3];
        break;
      }
      case 5: {
        asign[i] = materia[4];
        codigo[i] = cod[4];
        break;
      }
    }
    // Ingreso datos de seccion
    cout << "\n 1. Sección 1";
    cout << "\n 2. Sección 2";
    cout << "\n Seleccione una Sección" << "\n: ";
    cin >> opc;
    switch (opc){
      case 1: {
        seccion[i] = "1";
        break;
      }
      case 2: {
        seccion[i] = "2";
        break;
      }
    } 
  }
};



void FuncionArchivo(){
  string n_Archivo;
  cout << "Ingrese el nombre de su archivo" << "\n: ";
  cin >> n_Archivo;
  string nombreArchivo = n_Archivo;
  ifstream archivo(nombreArchivo.c_str());
  string linea, nombre, nota1, nota2, nota3, nota4;
  int res, j, i=0, lon;
  string arreglo[100];
  char b, l;
  while (getline(archivo, linea)){
    lon = linea.length();
    for (j=0 ;j<lon ;j++){
      l = linea[j];
      b = ' ';
      if (l!=b){
        if(i==0)
          nombre = nombre + linea[j];
        if (i == 1)
          nota1 = nota1 + linea[j];
        if (i == 2)
          nota2 = nota2 + linea[j];
        if (i == 3)
          nota3 = nota3 + linea[j];
        if (i==4)
          nota4 = nota4 + linea[j];
      }
      else{
        i++;
      }
  }
    string nombre_estudiante[40] = {nombre};
    float num1 = stof(nota1);
    float num2 = stof(nota2);
    float num3 = stof(nota3);
    float num4 = stof(nota4);
    float notas[4] = {num1, num2, num3, num4};
    float promedio = ((num1 + num2 + num3 + num4)/4);
    cout << "\n----------------------------\n";
    cout << "Nombre estudiante: "<< nombre << endl;
    cout << "Nota 1: " << num1 << endl;
    cout << "Nota 2: " << num2 << endl;
    cout << "Nota 3: " << num3 << endl;
    cout << "Nota 4: " << num4 << endl;
    cout << "Promedio: " << promedio;
    i = 0;
    nombre = " ";
    nota1 = " ";
    nota2 = " ";
    nota3 = " ";
    nota4 = " ";
  }
}


// --------------- Funcion Main ---------------
int main(){
  Asignatura as;
  string n_Archivo;
  int respuesta;
  cout << "\n"; 
  cout << "Sistema de Notas\n\n";
  cout << " -- Manual --\n";
	cout << " 1. Profesor\n";
	cout << " 2. Estudiante\n" << endl;
	cout << " 3. Salir del sistema\n";
	cout << "\nSeleccione una opción\n" << ": ";
  cin >> respuesta;
  cin.ignore();

  switch (respuesta){
    // caso para ingreso datos Profesor
		case 1:
			cout << "\n----------------------------------" << endl;
      cout << "\nDatos Profesor: " << endl;
      as.AsignDatosProf();
      as.AsignMostrarProf();
			break;
    // caso para ingreso datos Estudiante
		case 2:
      cout << "\n----------------------------------" << endl;
      cout << "\nDatos estudiante: " << endl;
      as.AsignDatosEst();
      as.AsignMostrarEst();
			break;
    // caso para salir del programa
		case 3:
			cout << "\nSaliendo del sistema...";
	}
	return 0;  
}
