#include<iostream>
#include<fstream>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class persona{
	public:
	
	string nombre,apellido,rut,telefono;
	int edad;
	persona(){};
	~persona(){};
	
	void datos_persona();
	void mostrar_persona();
};

void persona::datos_persona(){
	cout<<"Ingrese el nombre:";
  	cin>>nombre;
  	cout<<"Ingrese el apellido:";
  	cin>>apellido;
	cout<<"Ingrese el rut:";
	cin>>rut;
	cout<<"Ingrese el telefono:";
	cin>>telefono;
	cout<<"Ingrese la edad:";
	cin>>edad;
};

void persona::mostrar_persona(){
  cout<<"Nombre:"<<nombre<<endl;
  cout<<"Apellido:"<<apellido<<endl;
  cout<<"Rut:"<<rut<<endl;
  cout<<"Telefono:"<<telefono<<endl;
  cout<<"Edad:"<<edad<<endl;
};

class profesor: public virtual persona{
	public:

  string asignatura;
  int num_secciones;
  profesor(){};
  ~profesor(){};
  
  void datos_profesor();
  void mostrar_profesor();
  void entregar_notas();
};


void profesor::datos_profesor(){
	int i;
	datos_persona();
	cin.ignore();
	cout<<"Escriba la asignatura:";
	getline(cin,asignatura);
};

void profesor::mostrar_profesor(){
	int i;
  	datos_persona();
	mostrar_persona();
};

void profesor::entregar_notas(){
	
};


class estudiante: public virtual persona{
	public:
	string carrera;
	int num_asignaturas;
	estudiante(){};
	~estudiante(){};
	
	void datos_estudiante();
	void mostrar_estudiante();
};

void estudiante::datos_estudiante(){
	int i;
	datos_persona();
	cout<<"Escriba la carrera:";
	getline(cin,carrera);
};

void estudiante::mostrar_estudiante(){
    datos_persona();
	mostrar_persona();
};


class asignatura: public profesor, public estudiante{
	public:
	
	string sec[10],asigna[10],codigo[10];
  char nomb[40]="Estudiante.txt";
	string ramo[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMOS Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOVIL","PARADIGMAS DE PROGRAMACION"};
	string codigos[5]={"PR001","BD002","AE003","DM004","PP005"};
	asignatura(){};
	~asignatura(){};
	
	
	void ingresar_datos_estudiante();
	void mostrar_e();
	void ingresar_datos_profesor();
	void mostrar_p();
};

void asignatura::ingresar_datos_estudiante(){
	int opcion,opc;
	mostrar_estudiante();
	cout<<"\nIngrese el numero de asignaturas:";
	cin>>num_asignaturas;
	for (int i=0;i<num_asignaturas;i++){
		cout<<"\n1."<<ramo[0];
		cout<<"\n2."<<ramo[1];
		cout<<"\n3."<<ramo[2];
		cout<<"\n4."<<ramo[3];
		cout<<"\n5."<<ramo[4];
		cout<<"\nSeleccione un ramo:";
		cin>>opcion;
		
		switch(opcion){
			case 1:{
				asigna[i]=ramo[0];
				codigo[i]=codigos[0];
				break;
			}
			case 2:{
				asigna[i]=ramo[1];
				codigo[i]=codigos[1];
				break;
			}
			case 3:{
				asigna[i]=ramo[2];
				codigo[i]=codigos[2];
				break;
			}
			
			case 4:{
				asigna[i]=ramo[3];
				codigo[i]=codigos[3];
				break;
			}
			
			case 5:{
				asigna[i]=ramo[4];
				codigo[i]=codigos[4];
				break;
			}
		}
    cout<<"\nCual es la seccion?"<<endl;
		cout<<"\n1. Seccion 1";
		cout<<"\n2. Seccion 2";
		cout<<"\nSeleccione una opcion:";
		cin>>opc;
		switch(opc){
			case 1:{
				sec[i]="1";
				break;
			}
			case 2:{
				sec[i]="2";
				break;
			}
		}		
	}	
};

void asignatura::mostrar_e(){
	//File* archivo;
	mostrar_estudiante();
	cout<<"Asignaturas \n:";
	for (int i=0;i<num_asignaturas;i++){
		cout<<asigna[i]<<endl;
		cout<<codigo[i]<<endl;
		cout<<sec[i]<<endl;		
	}
};

void asignatura::mostrar_p(){
  mostrar_profesor();
  cout<<"Asignaturas \n:";
  for (int i=0;i<num_asignaturas;i++){
    cout<<asigna[i]<<endl;
    cout<<codigo[i]<<endl;
    cout<<sec[i]<<endl;
    
  }
};

void asignatura::ingresar_datos_profesor(){
	int opcion,opc;
	mostrar_profesor();
	cout<<"Ingrese el numero de asignaturas:";
	cin>>num_asignaturas;
	for (int i=0;i<num_asignaturas;i++){
		cout<<"Elija las asignaturas:";
		cout<<"\n1."<<ramo[0];
		cout<<"\n2."<<ramo[1];
		cout<<"\n3."<<ramo[2];
		cout<<"\n4."<<ramo[3];
		cout<<"\n5."<<ramo[4];
		
		cout<<"\nElija una opcion:";
		cin>>opcion;
		switch(opcion){
			case 1:{
				asigna[i]=ramo[0];
				codigo[i]=codigos[0];
				break;
			}
			case 2:{
				asigna[i]=ramo[1];
				codigo[i]=codigos[1];
				break;
			}
			case 3:{
				asigna[i]=ramo[2];
				codigo[i]=codigos[2];
				break;
			}
			case 4:{
				asigna[i]=ramo[3];
				codigo[i]=codigos[3];
				break;
			}
			case 5:{
				asigna[i]=ramo[4];
				codigo[i]=codigos[4];
				break;
			}
		}
    cout<<"\nCual es la seccion?"<<endl;
    cout<<"1. Seccion 1"<<endl;
    cout<<"2. Seccion 2"<<endl;
    cout<<"Elija una opcion:";
    cin>>opc;
    switch(opc){
      case 1:{
        sec[i]="1";
        break;
      }
      case 2:{
        sec[i]="2";
        break;
      }
    }
	}
};




int main (){
	asignatura asig;
	int opc;
  char comienzo='s';
  while (comienzo=='s'){
	cout<<"----------Sistema de Notas----------\n";
	cout<<"1. Profesor\n";
	cout<<"2. Estudiante\n";
	cout<<"3. Salir del sistema\n";
	cout<<"Seleccione una de las opciones:";
	cin>>opc;
	switch(opc){
		case 1:
			asig.ingresar_datos_profesor();
			asig.mostrar_p();
      break;
			

		case 2:
			asig.ingresar_datos_estudiante();
			asig.mostrar_e();
			break;
		
		case 3:
			cout<<"Saliendo del sistema";
      
	
    }
	return 0;
}
}


