#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <sstream>

using namespace std;

class Persona
{
	public:
	struct {
		string nom,rut;
		
	}reg;	
	Persona(){ };
	~Persona(){ };
	void datosper();
	void mostrarper();
};
void Persona::datosper(){
		cout << "Nombre : "; getline(cin, reg.nom);
    	cout << "Rut : "; getline(cin, reg.rut);
        while(atoi(reg.rut.c_str())<99999999 || atoi(reg.rut.c_str())>999999999){
            cout << "ERROR: Rut invalido, vuelva a ingresarlo: ";getline(cin, reg.rut);
        }

	};
void Persona::mostrarper(){
		cout << "Nombre : "<<reg.nom<<endl;
    	cout << "Rut : "<<reg.rut<<endl;

	};

class Profesor: public virtual Persona
{
	public:
	string cat;
	int cant;
	Profesor(){	};
	~Profesor(){ };
	void datosprof();
	void mostrarprof();
};

void Profesor::datosprof() {
		int i;
		datosper();
	};
void Profesor::mostrarprof(){
		int i;
		mostrarper();
	};



class Estudiante: public virtual Persona
{
	public:
	string carr;
    float notas[4];
	int can;
	Estudiante(){ };
	~Estudiante(){ };
	void datosest();
	void mostrarest();
};
void Estudiante::datosest() {
		int i;
		datosper();
	};
void Estudiante::mostrarest(){
		mostrarper();
	};



class Asignatura: public Profesor, public Estudiante
{
	public:
	string s[10];
	string a[10],c[10];
    Estudiante estudiantes[5];
	char nom[40]= "Estudiante.txt";
	int cant;
	string mat[5]={"PROGRAMACION","BASE DE DATOS","ALGORITMO Y ESTRUCTURA DE DATOS","DESARROLLO WEB Y MOBIL","PARADIGMAS DE PROGRAMACION"};
	string cod[5]={"PR001","BD002","AE003","DM004","PP005"};
	Asignatura(){ };
	~Asignatura(){ };
	void ingresardatose();
	void mostrare();
    void ingresarNotas();
    void pedirPromedios(string a[10],string c[10],string s[10],string nombre,int cant);
	void ingresardatosp();
    void confirmarNotas();
	void mostrarp();
};
void Asignatura::mostrarp(){
		mostrarprof();
		cout << "Cantidad Asignatura : "<<cant<<endl;
		cout<<"Asignaturas: \n";	
		for(int i=0;i<cant;i++){
			cout<<a[i]<<endl;
		}
        cout << "\n";
};
void Asignatura::ingresarNotas(){
    float notas[4];
    string texto,archivo,nombre,lista_alumnos[50],lista_ruts[50];
    string rut_estudiante,nombre_completo,T,linea,asignaturas[10];
    int cant_estudiantes,aux,contador=0,cont=0,n=0,ctd=0,p;
    for(int i=0;i<cant;i++){
        asignaturas[i] = a[i]+ " " +c[i] + " " + s[i]+".txt";
        
    }
    
      
    for (int j = 0;j<cant;j++){
        //se definen la cantidad de estudiantes
        cout << "ASIGNATURA: " << a[j] << " " << c[j] << " " << s[j] << endl;
        cout << "Ingrese la cantidad de estudiantes en esta asignatura: ";
        cin >> cant_estudiantes;   
        while(cant_estudiantes>50 || cant_estudiantes<1){
            cout << "ERROR: Cantidad invaldia de estudiantes, vuelva a ingresar el valor: ";cin >> cant_estudiantes;
        }
        for(int a=0;a<50;a++){
            lista_alumnos[a]="";
            lista_ruts[a]="";
        }
        for(int k=0;k<cant_estudiantes;k++){
        cin.ignore();
        //Se ingresan los datos de los estudiantes
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombre);
            p = 0;
            while(p<cant_estudiantes){
                if(lista_alumnos[p+1]==nombre){
                    cout << "-----------------------------------------" << endl;
                    cout << "ERROR: Ya ingreso ese nombre. Vuelva a ingresar el nombre del estudiante: ";
                    getline(cin, nombre);
                    p=0;
                }
                else{
                    p++;
                }
            }

            lista_alumnos[k+1] = nombre;
            
            cout << "Ingrese el rut: ";getline(cin, rut_estudiante);
            //Se confirma que el rut sea valido
            while(atoi(rut_estudiante.c_str())<99999999 || atoi(rut_estudiante.c_str())>999999999){
                cout << "ERROR: Rut invalido, vuelva a ingresarlo: ";getline(cin, reg.rut);
        }
            p = 0;
            while(p<cant_estudiantes){
                if(lista_alumnos[p+1]==rut_estudiante){
                    cout << "-----------------------------------------" << endl;
                    cout << "ERROR: Ya ingreso ese nombre. Vuelva a ingresar el nombre del estudiante: ";
                    getline(cin, rut_estudiante);
                    p=0;
                }
                else{
                    p++;
                }
            }

        lista_ruts[k+1]=rut_estudiante;
            //string con los datos de los estudiantes
            texto = nombre + " " + rut_estudiante;

            //se agregan las notas al string que contiene los datos de los estudiantes
            for (int i = 0;i<4;i++){
                cout << "Ingrese las notas del estudiante n°: "<< i+1 <<endl;
                cin >> notas[i];
                while(notas[i]>7 || notas[i]<1)
                {
                    cout << "ERROR: Nota no valida vuelva a ingresar la nota: " <<endl;
                    cin >> notas[i];
                }
                texto = texto + " " + to_string(notas[i]).substr(0,4);
            }
                texto = texto+"\n";

                //se le asigna los datos de la asignatura a un string para crear el archivo
                archivo = a[j] +" "+ c[j] + " "+ s[j] + ".txt";

                FILE *x = fopen(archivo.c_str(),"a");
                
                //se añaden los datos del estudiante al txt de la respectiva asignatura
                fputs (texto.c_str(),x);

                fclose (x);
        }
    }
    

};

void Asignatura::pedirPromedios(string a[10],string c[10],string s[10],string nombre,int cant){
    string nombre_completo;
    string T,linea;
    float promedio;
    int cont=0,contador=0,posicion,ctd=0;
    bool verificador=false;
    float lista_promedios[40];
    string lista_alumnos[40];
    string asignaturas[cant];
    int ver[cant];
    FILE *file; //archivo

    //concatena los datos de la asignatura para tener el nombre del .txt de dicha asignatura
    //ademas de verificar que los archivos existan
    for(int i=0;i<cant;i++){
        asignaturas[i] = a[i]+ " " +c[i] + " " + s[i]+" PROMEDIOS FINALES.txt";
        if (file = fopen(asignaturas[i].c_str(), "r")){
            ctd+=1;
            fclose(file);

        }
    }
    for(int i = 0;i<cant;i++){
        
        contador = 0;
        
        cont=0;
        //revisa si el archivo existe
    if (ctd==cant) {
        
            // se abre el archivo con el nombre de la asignatura
            ifstream archivo(asignaturas[i].c_str());
            verificador = 0;
            //se leen las lineas del .txt
            while(getline(archivo,linea)){
            contador = 0;
            
            stringstream X(linea); 
                //se separa la linea del txt por cada espacio que tenga, para poder obtener el nombre,rut y las notas
                while (getline(X, T, ' ')) {  
                    contador+=1;
                    if(contador==1){
                        nombre_completo=T;
                    }
                    
                    if(contador==2){
                        nombre_completo=nombre_completo + " " + T;

                    }
                    if(contador==3){
                        // float f = std::stof(T);                    
                        // suma = suma + f;
                        promedio = atoi(T.c_str());
                    }
                } 
            // promedio = suma/4;
            //se comprueba que el nombre ingresado este dentro del txt
            if (nombre == nombre_completo){
                verificador = 1;
                posicion = cont;

            }
            //se le asigna los nombres y los promedios calculados a 2 variables para guardarlos
            lista_alumnos[cont] = nombre_completo;
            lista_promedios[cont] = promedio;

            //contador para asignar los nombre y promedios a la posicion de sus respectivos arreglos
            cont+=1;


        }
        archivo.close();
        // si se encontro el nombre dentro del archivo se genera el archivo notas y añade el nombre de la asignatura
        // , el promedio y si esta aprobada o reprobada
        if(verificador == true){
            FILE *file = fopen((nombre+".txt").c_str(), "a+");
            if(lista_promedios[posicion]>=4){
            linea = a[i] + " " + to_string(lista_promedios[posicion]).substr(0,4)+" " + "APROBADA\n";
            cout << a[i] << " PROMEDIO: " << to_string(lista_promedios[posicion]).substr(0,4) << endl;
        }
        else{
            linea = a[i]+ " " + to_string(lista_promedios[posicion]).substr(0,4)+" " + "REPROBADA\n";
            cout << a[i] << " PROMEDIO: " << to_string(lista_promedios[posicion]).substr(0,4) << endl;

        }
        fputs (linea.c_str(),file);
        fclose(file);
        }
        //en caso de que el nombre no este en el archivo
        if (verificador == false){
            cout << "EL ALUMNO NO ESTA EN LA ASIGNATURA" << endl;
        }
    }
        
        else {
        cout <<"TODAVIA NO ESTAN LAS NOTAS DE ESTE RAMO"<< endl;
    }
    }
}


void Asignatura::ingresardatosp(){
	int opcion,opc,cont=0,n=0,k=0,h=1;
    string verifier[5][3];
	datosprof();
	cout<<"Escriba la Cantidad de Asignaturas: ";cin>> cant;
	for (int i=0;i<cant;i++){
		cout<<"Seleccione las Asignaturas: ";
		cout<<"\n 1. "<<mat[0];
		cout<<"\n 2. "<<mat[1];
		cout<<"\n 3. "<<mat[2];
		cout<<"\n 4. "<<mat[3];
		cout<<"\n 5. "<<mat[4];
		cout<<"\n Seleccione una Opcion: ";
		cin>>opcion;
        
        while(k<5){
                verifier[k][0] = mat[k] + " " + cod[k];
                    for(int y=1;y<3;y++){
                        verifier[k][y]="";
                    }
                    k++;
            }
        

        for (int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            cout << verifier[i][j] <<" ";
        }
        cout << "\n";
    }

    //    while(h<5){
    //             verifier[k][0] = mat[k] + " " + cod[k];
    //                 for(int y=1;y<3;y++){
    //                     if(verifier[k][y]!=""){

    //                     }
    //                 }
    //                 h++;
    //         }


     


        while(verifier[opcion-1][1]!="" && verifier[opcion-1][2]!=""){
            cout << "ERROR: Ambas secciones ya estan tomadas, vuelva a ingresar una opcion: " << endl;
            cout<<"Seleccione las Asignaturas: ";
            cout<<"\n 1. "<<mat[0];
            cout<<"\n 2. "<<mat[1];
            cout<<"\n 3. "<<mat[2];
            cout<<"\n 4. "<<mat[3];
            cout<<"\n 5. "<<mat[4];
            cout<<"\n Seleccione una Opcion: ";
            cin>>opcion;
        }


        while(opcion>5 || opcion<1){
            cout << "\nERROR: no existe esa opcion vuelva a ingresar"<< endl;
            cout<<"Seleccione las Asignaturas: ";
            cout<<"\n 1. "<<mat[0];
            cout<<"\n 2. "<<mat[1];
            cout<<"\n 3. "<<mat[2];
            cout<<"\n 4. "<<mat[3];
            cout<<"\n 5. "<<mat[4];
            cout<<"\n Seleccione una Opcion: ";
            cin>>opcion;
           
        }


		switch (opcion){
			case 1: {
			a[i]=mat[0];
			c[i]=cod[0];
			break;
			}
			case 2: {
			a[i]=mat[1];
			c[i]=cod[1];
			break;
			}
			case 3: {
			a[i]=mat[2];
			c[i]=cod[2];
			break;
			}
			case 4: {
			a[i]=mat[3];
			c[i]=cod[3];
			break;
			}
			case 5: {
			a[i]=mat[4];
			c[i]=cod[4];
			break;
			}
			}
		
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\n Seleccione la seccion: ";			
		cin>>opc;
        for (int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            cout << verifier[i][j] <<" ";
        }
        cout << "\n";
    }

        while(verifier[opcion-1][2]!="" && verifier[opcion-1][1]==""){
            

            cout << "ERROR:La seccion 2 esta tomada: " << endl;
            cout<<"\n 1. Seccion 1";
            cout<<"\n 2. Seccion 2";
            cout<<"\n Seleccione la seccion: ";			
            cin>>opc;
            if(opc==1){
                break;
            }
        }
        while(verifier[opcion-1][2]=="" && verifier[opcion-1][1]!="" ){
            

            cout << "ERROR:La seccion 1 esta tomada: " << endl;
            cout<<"\n 1. Seccion 1";
            cout<<"\n 2. Seccion 2";
            cout<<"\n Seleccione la seccion: ";			
            cin>>opc;
            if(opc==2){
                break;
            }
        }
        
        verifier[opcion-1][opc] = reg.nom; 

		switch (opc){
			case 1: {
				s[i]="1";
				break;
			}
			case 2: {
				s[i]="2";
				break;
			}
		}
 	}
        
};


void Asignatura::ingresardatose(){
	int opcion,opc,n=0,cont=0;
    string cursos[5];
    int verifier[5] = {0,0,0,0,0};
	datosest();
	cout<<"Escriba la Cantidad de Asignaturas: ";cin>> cant;
	for (int i=0;i<cant;i++){
		cout<<"Seleccione las Asignaturas: ";
		cout<<"\n 1. "<<mat[0];
		cout<<"\n 2. "<<mat[1];
		cout<<"\n 3. "<<mat[2];
		cout<<"\n 4. "<<mat[3];
		cout<<"\n 5. "<<mat[4];
		cout<<"\n Seleccione una Opcion: ";
		cin>>opcion;
        //verifica que la asignatura ingreasa no este repetida
            while(verifier[opcion-1]==1){
           
                cout << "\nERROR: Ya coloco esa asignatura. Vuelva a ingresarla: "; 
                cout<<"Seleccione las Asignaturas: ";
                cout<<"\n 1. "<<mat[0];
                cout<<"\n 2. "<<mat[1];
                cout<<"\n 3. "<<mat[2];
                cout<<"\n 4. "<<mat[3];
                cout<<"\n 5. "<<mat[4];
                cout<<"\n Seleccione una Opcion: ";               
                cin >> opcion;
                if (verifier[opcion-1]==0){
                    break;
                }

            }

        while(opcion>5 || opcion<1){
            cout << "\nERROR: no existe esa opcion vuelva a ingresar"<< endl;
            cout<<"Seleccione las Asignaturas: ";
            cout<<"\n 1. "<<mat[0];
            cout<<"\n 2. "<<mat[1];
            cout<<"\n 3. "<<mat[2];
            cout<<"\n 4. "<<mat[3];
            cout<<"\n 5. "<<mat[4];
            cout<<"\n Seleccione una Opcion: ";
            cin>>opcion;
           
        }
        
        

        cont+=1;
		switch (opcion){
		case 1: {
			a[i]=mat[0];
			c[i]=cod[0];
            verifier[0] = 1;
			break;
		}
		case 2: {
			a[i]=mat[1];
			c[i]=cod[1];
            verifier[1] = 1;
            
			break;
		} 
		case 3: {
			a[i]=mat[2];
			c[i]=cod[2];
            verifier[2] = 1;
			break;
		} 
		case 4: {
			a[i]=mat[3];
			c[i]=cod[3];
            verifier[3] = 1;
			break;
		} 
		case 5: {
			a[i]=mat[4];
			c[i]=cod[4];
            verifier[4] = 1;
			break;
		} 
		}
		cout<<"\n Seleccione la seccion: ";			
		cout<<"\n 1. Seccion 1";
		cout<<"\n 2. Seccion 2";
		cout<<"\n Seleccione una opcion: ";			
		cin>>opc;
        //revisa que la opcion sea 1 o 2
        while(opc>2 || opc<1){
            cout << "ERROR: opcion no valida, vuelva a ingresarla..." << endl;
            cout<<"1. Seccion 1";
            cout<<"\n 2. Seccion 2";
            cout<<"\n Seleccione la seccion: ";			
		    cin>>opc;
        }
		switch (opc){
			case 1: {
				s[i]="1";
				break;
			}
			case 2: {
				s[i]="2";
				break;
			}
		}
	}


}; 
void Asignatura::confirmarNotas(){
   
    string lista_alumnos[40],nombre2,apellido2,nombre_completo;
    float lista_promedios[40],promedio,suma=0;
    int contador=0,cont=0,aux2;
    string auxiliar_nombre,texto,T,linea,nombre_archivo1,nombre_archivo2;
    for(int j = 0;j<cant;j++){
    nombre_archivo1= a[j] + " " + c[j] + " " + s[j] + ".txt";

    ifstream archivo(nombre_archivo1.c_str());

            //Obtiene los datos del txt como el nombre, rut y notas
            while(getline(archivo,linea)){
            contador = 0;
            suma = 0;
                
            stringstream X(linea); 
            
            while (getline(X, T, ' ')) {  
                contador+=1;

                if(contador==1){
                   nombre_completo=T;
                }
                if(contador==2){
                    nombre_completo= nombre_completo + " " +T;
                }
                if(contador>3){
                    float f = std::stof(T);                    
                    suma = suma + f;
                }

            }  
            promedio = suma/4;
            lista_alumnos[cont] = nombre_completo;
            lista_promedios[cont] = promedio;

            cont+=1;


        }
        archivo.close();
            //Metodo de la burbuja, para ordenar los promedios de mayor a menor
            for(int i=0; i<cont; i++){
                    // Comparaciones
                    for(int j=0; j<cont-i; j++){
                    // Intercambiar los elementos
                    if(lista_promedios[j] < lista_promedios[j+1]){
                        aux2=lista_promedios[j];
                        auxiliar_nombre=lista_alumnos[j];
                        lista_promedios[j]=lista_promedios[j+1];
                        lista_alumnos[j]=lista_alumnos[j+1];
                        lista_alumnos[j+1]=auxiliar_nombre;
                        lista_promedios[j+1]=aux2;
                        }
                    }
                }
                cout << "\n------------------------APROBADOS------------------------" << endl;
                contador=0;
            nombre_archivo2 = a[j] + " " + c[j] + " " + s[j] + " PROMEDIOS FINALES.txt";
            
            for (int i=0;i<cont;i++){
                texto = lista_alumnos[i] + " " + to_string(lista_promedios[i]).substr(0,4) + "\n";
                FILE *x = fopen(nombre_archivo2.c_str(),"a");
                fputs (texto.c_str(),x);
                fclose (x);
                if(lista_promedios[i]>=4){
                    cout << lista_alumnos[i] <<  " promedio: " << to_string(lista_promedios[i]).substr(0,4) << endl;
                    contador+=1;
                }

                }
                cout << "---------------------------------------------------------" << endl;
                cout << "CANTIDAD DE APROBADOS: " << contador << endl;
                cout << "CANTIDAD DE REPROBADOS: " << cont-contador <<  "\n---------------------------------------------------------" << endl;
        
    }
    
}
void Asignatura::mostrare(){
	mostrarest();

};

int main(int argc, char** argv) {
	Asignatura as;
	int opc,opc2;
    while(opc!=3){

	cout<<"Sistema de Notas \n";
	cout<<"1. Profesor: \n";
	cout<<"2. Estudiante: \n";
	cout<<"3. Salir \n";
	cout<<"Seleccionar Opcion: ";
	cin>>opc;
	cin.ignore();
    while(opc>3 || opc<1){
        	cout<<"Opcion no valida, vuelva a ingresar \n";
        	cout<<"Sistema de Notas \n";
            cout<<"1. Profesor: \n";
            cout<<"2. Estudiante: \n";
            cout<<"3. Salir \n";
            cout<<"Seleccionar Opcion: ";
	        cin>>opc;
    }
    cin.ignore();
	switch (opc){
		case 1:
			as.ingresardatosp();
			as.mostrarp();
            cout << "Seleccione una de las siguientes opciones:" << endl;
            cout << "1.- Ingresar notas" << endl;
            cout << "2.- Calcular promedios" << endl;
            cin >> opc2;
            switch(opc2){
                case 1:
                    cout << "----------------------------------------------------------------------"<<endl;
                    as.ingresarNotas();
                    break;

                case 2:
                    as.confirmarNotas();
                    break;
            }
			break;
		case 2:
			as.ingresardatose();
            cout << "----------------------------------------------------------------------"<<endl;
			as.mostrare();
            as.pedirPromedios(as.a,as.c,as.s,as.reg.nom,as.cant);
            cout << "----------------------------------------------------------------------"<<endl;
			break;
		case 3:
			cout<<"Saliendo del sistema";
	}
    }
	
	return 0;
}