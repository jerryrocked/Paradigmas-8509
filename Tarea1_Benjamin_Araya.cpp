/*
PARADIGMAS DE LA PROGRAMACION - TAREA 1
Nombre: Benjamin Araya
RUT: 19323060-1
NRC: 8509
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

class Persona
{
	public:
	string nombre,apellido,rut,dir,telf,sex,edad;
	Persona(){ };
	~Persona(){ };
	void DatosPer();
	void MostrarPer();
};
//Ingresa datos personales en variables de clase Persona
void Persona::DatosPer(){
    getchar();
		cout << "Nombre : "; getline(cin,nombre);
    cout << "Apellido : "; getline(cin,apellido);
    cout << "Rut : "; getline(cin,rut);
    cout << "Direccion : " ; getline(cin,dir);
    cout << "Telefono : " ; getline(cin,telf);
    cout << "Sexo : "; getline(cin,sex);
    cout << "Edad : "; getline(cin,edad);
	};
//Muestra en pantalla los datos de la clase Persona
void Persona::MostrarPer(){
		  cout << "\nNombre : "<<nombre<<endl;
      cout << "Apellido : "<<apellido<<endl;
    	cout << "Rut : "<<rut<<endl;
    	cout << "Direccion : "<<dir<<endl;
    	cout << "Telefono : " <<telf<<endl;
    	cout << "Sexo : "; cout<<sex<<endl;
    	cout << "Edad : "; cout<<edad<<endl;
	};

class Profesor: public virtual Persona{
  public:
  string cat;
  Profesor(){};
  ~Profesor(){};
  void DatosProf();
  void MostrarProf();
};
void Profesor::DatosProf(){
  DatosPer();
  cout << "Escriba la Categoria : " ; getline(cin,cat);
}
void Profesor::MostrarProf(){
  MostrarPer();
  cout << "Categoria : "<<cat<<endl;
};

class Estudiante: public virtual Persona{
  public:
  string carr;
  Estudiante(){};
  ~Estudiante(){};
  void DatosEst();
  void MostrarEst();//muestra datos de estudiante
};
void Estudiante::DatosEst(){
  DatosPer();
  cout<<"Escriba la carrera: ";getline(cin,carr);
};
void Estudiante::MostrarEst(){
  MostrarPer();
  cout<<"Carrera: "<<carr<<endl;
};

class Asignatura: public Profesor, public Estudiante{
  public:
  string secc[10];//arreglo string con numero de seccion
  string asgn[10], c[10];//nombres de asignatura y codigo
  int cant;//cantidad de asignaturas
  string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};//las asignaturas que se pueden asignar
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
  string nomAsig[5];//nombre de archivos con las asignaturas
  Asignatura();
	~Asignatura();
	void IngresarDatosE();//ingresa datos de estudiantes
	void IngresarDatosP();//ingresa datos de profesor
	void MostrarP();//muesta datos del profesor
  void IngresoNotas();//ingreso de notas por el profesor
  void MostrarNotasP();//muestra las notas que tiene el profesor
  void MostrarNotasE();//muestra las notas del estudiante
};
void Asignatura::IngresarDatosP(){
  int opcion, opc;
  DatosProf();
  cout<<"Escriba la Cantidad de Asignaturas: ";cin>>cant;
  /*El bucle es para asignar las materias que va a ver el profesor y estudiantes*/
  for(int i=0;i<cant;i++){
    cout<<"Seleccione las Asignaturas: ";
		cout<<"\n 1. "<<mat[0];
		cout<<"\n 2. "<<mat[1];
		cout<<"\n 3. "<<mat[2];
		cout<<"\n 4. "<<mat[3];
		cout<<"\n 5. "<<mat[4];
		cout<<"\n Seleccione una Opcion: ";cin>>opcion;
    switch (opcion){
			case 1: {
			asgn[i]=mat[0];
			c[i]=cod[0];
			break;
			}
			case 2: {
			asgn[i]=mat[1];
			c[i]=cod[1];
			break;
			}
			case 3: {
			asgn[i]=mat[2];
			c[i]=cod[2];
			break;
			}
			case 4: {
			asgn[i]=mat[3];
			c[i]=cod[3];
			break;
			}
			case 5: {
			asgn[i]=mat[4];
			c[i]=cod[4];
			break;
			}
		}
    cout<<" 1. Sección 1";
		cout<<"\n 2. Sección 2";
		cout<<"\n Seleccione la sección: ";cin>>opc;
		switch (opc){
			case 1: {
				secc[i]="1";
				break;
			}
			case 2: {
				secc[i]="2";
				break;
			}
		}
  }
  
};
void Asignatura::MostrarP(){
  MostrarProf();
  cout<<"Cantidad de Asignaturas: "<<cant<<endl;
  cout<<"Asignaturas\tCodigo\tSeccion"<<endl;
  for(int i=0;i<cant;i++){
    cout<<asgn[i]<<"\t";
    cout<<c[i]<<"\t";
    cout<<secc[i]<<endl;
    }
};
void Asignatura::IngresoNotas(){
  cout<<"¿Necesita ingresar notas manualmente?(s/n): ";
  string opc, nomE,apE, o;
  double nota;
  string n[4] = {"Primera","Segunda","Tercera","Cuarta"};

  cin>>opc;
  if(opc.compare("s") == 0){
    /*Este bucle es para asignar las notas a las asignaturas
      de forma manual.
      Crea archivos dependiendo de las
      asignaturas que el profesor escogio en sus datos
      personales.*/
    for(int i=0;i<cant;i++){
      cout<<"Ingrese notas para "<<asgn[i]
        <<" Seccion "<<secc[i]<<endl;
      nomAsig[i] = asgn[i]+secc[i];
      ofstream archivo(nomAsig[i]);
      while(true){
        cout << "Escriba nombre de estudiante: ";cin>>nomE;
        cout << "Escriba apellido de estudiante: ";cin>>apE;
        archivo<<nomE<<" "<<apE;
        for(int j=0;j<4;j++){
          cout<<n[j]<<" nota: ";
          cin>>nota;
          if((nota>=1) && (nota<=7))
            archivo<<" "<<nota;
          else{
            cout<<"La nota no es valida"<<endl;
            j--;
          }
        }
        archivo<<"\n";
        cout<<"¿Desea agregar más estudiantes? (s) (n)"<<endl;
        cin>>o;
        if(o.compare("n") == 0)
          break;
      }
      archivo.close();
    }
  }
  else{
    /*Esta opcion es por si el profesor no requiere ingresar
      las asignaturas de forma manual y ya tiene sus archivos
      listos. Necesita ingresar los nombres de cada asignatura
      que haya escogido.*/
    getchar();
    for(int i=0;i<cant;i++){
      cout<<"Ingrese el nombre del archivo para "<<asgn[i]
        <<" Seccion "<<secc[i]<<":"<<endl;
      getline(cin,nomAsig[i]);
      if(nomAsig[i].compare("datos")==0){
        cout<<"*** No puede escoger ese nombre. ***"<<endl;
        i--;
        }
      }
  }
  /*Guarda la cantidad y el nombre de asignaturas(archivos)
    para darselas a la variable de alumnos.*/
  ofstream archivo2("datos");
  archivo2<<cant;
  for(int i=0;i<cant;i++){
    archivo2<<"\n"<<asgn[i];
    archivo2<<"\n"<<secc[i];
    archivo2<<"\n"<<nomAsig[i];
    }
  archivo2.close();

}
void Asignatura::MostrarNotasP(){
  string nom;
  int opc;
  cout<<"Asignaturas que puede ver:\n";
  for(int i=0;i<cant;i++)
    cout<<(i+1)<<". "<<asgn[i]<<" SECCIÓN "<<secc[i]<<endl;
  cout<<"Escoga alguna opción: ";
  cin>>opc;
  nom = nomAsig[(opc-1)];
  
  int l = 0;
  string linea;
  ifstream archivo(nom);
  while (getline(archivo, linea))
    ++l;
  archivo.close();

  string nombr[l],apellid[l], status[20];
  double n1,n2,n3,n4,np[l];

  ifstream archivo2(nom);
  for(int i=0;i<l;i++){
    archivo2>>nombr[i]>>apellid[i]>>n1>>n2>>n3>>n4;
    np[i] = (n1+n2+n3+n4)/4;
    if(np[i]<4)
      status[i] = "Reprobado";
    else
      status[i] = "Aprobado";
  }
  archivo2.close();

  double aux;
  string auxN, auxA, auxS;

  /*Doble bucle que ordena la lista de alumnos y sus notas de
    de mayor a menor*/
  for(int i=0;i<l;i++){
    for(int j=0;j<l;j++){
      if(np[i]>np[j]){
        aux=np[i];
        auxN = nombr[i];
        auxA = apellid[i];
        auxS = status[i];

        np[i] = np[j];
        nombr[i] = nombr[j];
        apellid[i] = apellid[j];
        status[i] = status[j];

        np[j] = aux;
        nombr[j] = auxN;
        apellid[j] = auxA;
        status[j] = auxS;
      }
    }
  }

  cout<<"\n===Notas para "<<asgn[(opc-1)]<<"===\n";
  for(int i=0;i<l;i++)
  cout<<nombr[i]<<" "
    <<apellid[i]<<" "
    <<np[i]<<" "
    <<status[i]<<endl;
}
void Asignatura::MostrarNotasE(){
  string lin;
  /*Abre el archivo "datos" para sacar las asignatura
    y el nombre de archivos que se necesitan leer*/
  ifstream archivoD("datos");
  getline(archivoD,lin);
  cant=stoi(lin);
  int k = 0;
  while(getline(archivoD,lin)){
    asgn[k] = lin;
    getline(archivoD,lin);
    secc[k] = lin;
    getline(archivoD,lin);
    nomAsig[k] = lin;
    k++;
  }
  archivoD.close();
  cout<<"===Notas de "<<nombre<<" "<<apellido<<"===\n";
  /*El bucle lee todas las asignaturas que escogio el profesor
    y busca el nombre del alumno y sus notas*/
  for(int j=0;j<cant;j++){
    int l = 0;
    string linea;
    ifstream archivo(nomAsig[j]);
    while (getline(archivo, linea))
      ++l;
    archivo.close();

    string nombr[l],apellid[l], status[20];
    double n1,n2,n3,n4,np[l];

    ifstream archivo2(nomAsig[j]);
    for(int i=0;i<l;i++){
      archivo2>>nombr[i]>>apellid[i]>>n1>>n2>>n3>>n4;
      //Calcula la nota promedio del alumno
      np[i] = (n1+n2+n3+n4)/4;
      /*Revisa si el alumno reprobo el ramo segun su nota
        promedio*/
      if(np[i]<4)
        status[i] = "Reprobado";
      else
        status[i] = "Aprobado";
      /*revisa si el alumno del archivo leido es el alumno que
        se quiere mostrar*/
      if((nombre.compare(nombr[i]) == 0)&&(apellido.compare(apellid[i]) == 0))
        cout<<asgn[j]<<" "<<np[i]<<" "<<status[i]<<endl;

    }
    archivo2.close();
  }
}
Asignatura::Asignatura(){
};
Asignatura::~Asignatura(){
  cout<<"end"<<endl;
};

int main() {
  Asignatura prof,est;
  bool DP1=false,DP2=false,DE=false,menu=true;
  /*DP1 revisa si se ingreso los datos del profesor
    DP2 revisa si se ingresaron las notas
    DE revisa si se ingreso los datos del estudiante
    menu revisa si es que se quiere salir del menu*/
  int opcion;
  while(menu==true){
    cout<<"\n MENU";
		cout<<"\n 1. PROFESOR";
		cout<<"\n 2. ESTUDIANTE";
    cout<<"\n 3. SALIR";
		cout<<"\n Seleccione una Opcion: ";cin>>opcion;
    switch(opcion){
      case 1:{
        cout<<"\n\t MENU PROFESOR";
        cout<<"\n\t 1. Ingresar datos personales";
		    cout<<"\n\t 2. Mostrar datos personales";
		    cout<<"\n\t 3. Ingresar notas";
        cout<<"\n\t 4. Mostrar notas";
        cout<<"\n\t 5. Salir a menu principal";
        cout<<"\n Seleccione una Opcion: ";cin>>opcion;
        switch(opcion){
          case 1:{
            prof.IngresarDatosP();
            DP1 = true;
            break;
          }
          case 2:{
            if (DP1)
              prof.MostrarP();
            else
              cout<<"*** No ha ingresado datos personales del profesor. ***";
            break;
          }
          case 3:{
            if(DP1){
              prof.IngresoNotas();
              DP2 = true;
              }
            else
              cout<<"*** No ha ingresado datos personales del profesor. ***";
            break;
          }
          case 4:{
            if(DP1 && DP2)
              prof.MostrarNotasP();
            else
              cout<<"*** No ha ingresado notas. ***";
            break;
          }
          case 5:{
            break;
          }
        }
        break;
      }
      case 2:{
        cout<<"\n\t MENU ESTUDIANTE";
        cout<<"\n\t 1. Ingresar datos personales";
		    cout<<"\n\t 2. Mostrar datos personales";
        cout<<"\n\t 3. Mostrar notas";
        cout<<"\n\t 4. Salir a menu principal";
        cout<<"\n Seleccione una Opcion: ";cin>>opcion;
        switch(opcion){
          case 1:{
            est.DatosEst();
            DE = true;
            break;
          }
          case 2:{
            if (DE)
              est.MostrarEst();
            else
              cout<<"\n*** No ha ingresado datos personales del estudiante. ***";
            break;
          }
          case 3:{
            if(DP2 && DE)
              est.MostrarNotasE();
            else
              cout<<"\n*** Falta ingresar notas o los datos del estudiante. ***";
            break;
          }
          case 4:{
            break;
          }
        }
        break;
      }
      case 3:{
        menu=false;
      }
    }
  }
  return 0;
}
