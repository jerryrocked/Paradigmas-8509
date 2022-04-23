#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Persona {
public:
  struct {
    string nom, rut, dir, telf;
    char sex;
    int edad;
  } reg;
  Persona(){};
  ~Persona(){};
  void datosper();
  void mostrarper();
};
void Persona::datosper() {
  cout << "Nombre : ";
  getline(cin, reg.nom);
  cout << "Rut : ";
  getline(cin, reg.rut);
  cout << "Direccion : ";
  getline(cin, reg.dir);
  cout << "Telefono : ";
  getline(cin, reg.telf);
  cout << "Sex : ";
  cin >> reg.sex;
  cout << "Edad : ";
  cin >> reg.edad;
};
void Persona::mostrarper() {
  cout << "Nombre : " << reg.nom << endl;
  cout << "Rut : " << reg.rut << endl;
  cout << "Direccion : " << reg.dir << endl;
  cout << "Telefono : " << reg.telf << endl;
  cout << "Sex : ";
  cout << reg.sex << endl;
  cout << "Edad : ";
  cout << reg.edad << endl;
};

class Profesor : public virtual Persona {
public:
  string cat;
  int cant;
  Profesor(){ };
  ~Profesor(){ };
  void datosprof();
  void mostrarprof();
  void entregarnotas();
  void ingresarNotas();
};
void Profesor::ingresarNotas() {

    int opcioness;
    int j;
    string verificador;
    string Notas[4], datos[80],nomb;
  
//CREANDO EL ARCHIVO
  
    ofstream MyFile_M("Estudiante.txt");

    string myText;

    ofstream MyFile_A("Estudiante.txt");
  
//OPCIONES AL PROFESOR
  
    cout << endl <<"INGRESAR NOTAS: ";
    cout << endl<<" 1. MANUEALMENTE";
    cout << endl<<" 2. CON ARCHIVO";  
    cout << endl<<" SELECCIONE SU OPCION: ";
    cin >> opcioness;
    switch (opcioness)
    {
    case 1:
        verificador = "si";
        j = 0;

        while (verificador != "no")
        {
            cout <<endl<< "Ingrese su nombre: ";
            cin >> nomb;

            cout << "Ingrese su primera nota: ";
            cin >> Notas[0];

            cout << "Ingrese su segunda nota: ";
            cin >> Notas[1];

            cout << "Ingrese su tercera nota: ";
            cin >> Notas[2];

            cout << "Ingrese su cuarta nota: ";
            cin >> Notas[3];

            datos[j] = nomb + " " + Notas[0] + " " + Notas[1] + " " + Notas[2] + " " + Notas[3];

            j++;

            cout << endl<<"Desea agregar otro estudiante? (si/no): ";
            cin >> verificador;
        }

        for (int i = 0; i < j; i++)
        {
            MyFile_M << datos[i] << endl;
        }

        MyFile_M.close();

        break;

    case 2:

        string archivoo;
        cout <<endl<< "Nombre archivo: ";
        cin >> archivoo;
        ifstream MyReadFile(archivoo);

        while (getline(MyReadFile, myText))
        {
            cout << myText << endl;
            MyFile_A << myText << endl;
        }

        MyReadFile.close();
        MyFile_A.close();
        break;
      
      }
  }

void Profesor::datosprof() {
  int i;
  datosper();
  cin.ignore();
  cout << "Escriba la Categoria: ";
  getline(cin, cat);
};
void Profesor::mostrarprof() {
  int i;
  mostrarper();
  cout << "Categoria : " << cat << endl;
};

class Estudiante : public virtual Persona {
public:
  string carr;
  int can;
  Estudiante(){};
  ~Estudiante(){};
  void datosest();
  void mostrarest();
  void EntregaDeNotas();
};
void Estudiante::EntregaDeNotas() {
    
  
  string NOTAS;
    ifstream ArchivoEst("Estudiante.txt", ios::out | ios::app);
    if (!ArchivoEst.is_open())
    {
        ArchivoEst.open("Estudiante.txt", ios::in);
    }
    if (sizeof("Estudiante.txt") == 0)
    {
        cout << "TUS RESULTADOS NO ESTAN PUBLICADOS";  

    cout << "RESULTADO: " << endl;
    while (!ArchivoEst.eof())
    {
        getline(ArchivoEst, NOTAS);
        cout << NOTAS << endl;
    }
    ArchivoEst.close();
    }
};


void Estudiante::datosest() {
  int i;
  datosper();
  cout << "Ingresar Carrera que Estudia: ";
  cin >> carr;
};

void Estudiante::mostrarest() {
  mostrarper();
  cout << "\n Carrera: " << carr;
};

class Asignatura : public Profesor, public Estudiante {
public:
  string s[10];
  string a[10], c[10];
  char nom[40] = "Estudiante.txt";
  int cant;
  string mat[5] = {"PROGRAMACION", "BASE DE DATOS",
                   "ALGORITMO Y ESTRUCTURA DE DATOS", "DESARROLLO WEB Y MOBIL",
                   "PARADIGMAS DE PROGRAMACION"};
  string cod[5] = {"PR001", "BD002", "AE003", "DM004", "PP005"};
  Asignatura(){};
  ~Asignatura(){};
  void ingresardatose();
  void mostrare();
  void ingresardatosp();
  void mostrarp();
  void notasDefinitivasP();
  void notasDefinitivasEST();
};
void Asignatura::notasDefinitivasEST()

{

    string archivo1 = "Estudiante.txt";
    ifstream archivo(archivo1.c_str());
    string linea, nomb, prom;
    int res, lon, i, j = 0, c = 0;
    string  resultados[50],nombres[50];
    float notas1[50], promFinal[50];
    char b, l;

    while (getline(archivo, linea))
    {

        lon = linea.length();
        for (i = 0; i < lon; i++)
        {
            l = linea[i];
            b = ' ';
            if (l != b)
            {
                if (j == 0)
                    nomb = nomb + linea[i];
                if (j == 1)
                    prom = prom + linea[i];
            }
            else
                j++;
        }

        // pasar numeros str a float
        float promFinal_float = stof(prom);

        // agregar datos los arreglos
        nombres[c] = nomb;
        promFinal[c] = promFinal_float;
        if (promFinal[c] < 4)
        {
            resultados[c] = "USTED A REPROBADO... ESTUDIE MAS";
        }
        if (promFinal[c] >= 4)
        {
            resultados[c] = "FELICITACIONES A APROBADO";
        }

        c++;

        j = 0;
        nomb = "";
        prom = " ";
    }
    archivo.close();

    int NOTASOP;

    cout << "¿Para cual ramo van las notas?: " << endl;
    for (int i = 0; i < cant; i++)
    {
        cout << i + 1 << "." << a[i] << ":" << endl;
    }
    cout << "Escoja alguna opcion: ";
    cin >> NOTASOP;

    ofstream MyFile("Estudiante.txt");
    for (int cont = 0; cont < c; cont++)
    {

        cout << a[NOTASOP - 1] << " ";
        cout << promFinal[cont] << " ";
        cout << resultados[cont] << endl;

        MyFile << a[NOTASOP - 1] << " " << promFinal[cont] << " " << resultados[cont] << " " << endl;
    }
    MyFile.close();
}


void Asignatura::notasDefinitivasP(){

string archivo1 = "Estudiante.txt";
    ifstream archivo(archivo1.c_str());
    string linea, nomb, n1, n2, n3, n4;
    int res, lon, i, j = 0, c = 0;
    string nombres[50];
    float notas1[50], notas2[50], notas3[50], notas4[50],promFinal[50];
    char b, l;

    while (getline(archivo, linea))
    {
        lon = linea.length();
        for (i = 0; i < lon; i++)
        {
            l = linea[i];
            b = ' ';
            if (l != b)
            {
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
            }
            else
                j++;
        }

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
    archivo.close();
    ofstream MyFile("Estudiante.txt");

    
    for (int i = 0; i < c; i++)
    {
//ACA SACAREMOS LOS PROMEDIOS DE LOS ESTUDIANTES
        promFinal[i] = (notas1[i] + notas2[i] + notas3[i] + notas4[i]) / 4;

        MyFile << nombres[i] << " " << promFinal[i] << endl;
    }

    MyFile.close();
}
  
  

  
void Asignatura::mostrarp() {
  mostrarprof();
  cout << "Cantidad Asignatura : " << cant << endl;
  cout << "Asignaturas: \n";
  for (int i = 0; i < cant; i++) {
    cout << a[i] << endl;
  }
};
void Asignatura::ingresardatosp() {
  int opcion, opc;
  datosprof();
  cout << "Escriba la Cantidad de Asignaturas: ";
  cin >> cant;
  for (int i = 0; i < cant; i++) {
    cout << "Seleccione las Asignaturas: ";
    cout << "\n 1. " << mat[0];
    cout << "\n 2. " << mat[1];
    cout << "\n 3. " << mat[2];
    cout << "\n 4. " << mat[3];
    cout << "\n 5. " << mat[4];
    cout << "\n Seleccione una Opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1: {
      a[i] = mat[0];
      c[i] = cod[0];
      break;
    }
    case 2: {
      a[i] = mat[1];
      c[i] = cod[1];
      break;
    }
    case 3: {
      a[i] = mat[2];
      c[i] = cod[2];
      break;
    }
    case 4: {
      a[i] = mat[3];
      c[i] = cod[3];
      break;
    }
    case 5: {
      a[i] = mat[4];
      c[i] = cod[4];
      break;
    }
    }

    cout << "\n 1. Seccion 1";
    cout << "\n 2. Seccion 2";
    cout << "\n Seleccione la seccion: ";
    cin >> opc;
    switch (opc) {
    case 1: {
      s[i] = "1";
      break;
    }
    case 2: {
      s[i] = "2";
      break;
    }
    }
  }
};

void Asignatura::ingresardatose() {
  int opcion, opc;
  datosest();
  cout << "Escriba la Cantidad de Asignaturas: ";
  cin >> cant;
  for (int i = 0; i < cant; i++) {
    cout << "Seleccione las Asignaturas: ";
    cout << "\n 1. " << mat[0];
    cout << "\n 2. " << mat[1];
    cout << "\n 3. " << mat[2];
    cout << "\n 4. " << mat[3];
    cout << "\n 5. " << mat[4];
    cout << "\n Seleccione una Opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1: {
      a[i] = mat[0];
      c[i] = cod[0];
      break;
    }
    case 2: {
      a[i] = mat[1];
      c[i] = cod[1];
      break;
    }
    case 3: {
      a[i] = mat[2];
      c[i] = cod[2];
      break;
    }
    case 4: {
      a[i] = mat[3];
      c[i] = cod[3];
      break;
    }
    case 5: {
      a[i] = mat[4];
      c[i] = cod[4];
      break;
    }
    }
    cout << "\n 1. Secciï¿½n 1";
    cout << "\n 2. Secciï¿½n 2";
    cout << "\n Seleccione la secciï¿½n: ";
    cin >> opc;
    switch (opc) {
    case 1: {
      s[i] = "1";
      break;
    }
    case 2: {
      s[i] = "2";
      break;
    }
    }
  }
};
void Asignatura::mostrare() {
  FILE *archivo; // FILE se escribe en mayuscula
  mostrarest();
  string cod[40], as[40], sec[40];
  cout << "Asignaturas: \n";
  for (int i = 0; i < cant; i++) {
    cout << a[i] << endl;
    cout << c[i] << endl;
    cout << s[i] << endl;
  }
  // En el segundo parametro se escribe la forma en que sera abierto "w"
  for (int i = 0; i < cant; i++) {
  }
};

int main(int argc, char **argv) {
  Asignatura as;
  Profesor prof;
  Estudiante est;
  int opc;
  cout << "Sistema de Notas \n";
  cout << "1. Profesor: \n";
  cout << "2. Estudiante: \n";
  cout << "3. Salir \n";
  cout << "Seleccionar Opciï¿½n: ";
  cin >> opc;
  cin.ignore();
  switch (opc) {
  case 1:
    as.ingresardatosp();
    prof.ingresarNotas();
    as.mostrarp();
    as.notasDefinitivasP();
    as.notasDefinitivasEST();
    break;
  case 2:
    as.ingresardatose();
    est.EntregaDeNotas();

    break;
  case 3:
    cout << "Saliendo del sistema.. ADIOSS";
  }

    
  return 0;
}


