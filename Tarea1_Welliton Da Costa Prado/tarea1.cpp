#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

// Clase Persona
class Persona
{
public:
    struct
    {
        string nom, rut, dir, telf;
        char sex;
        int edad;
    } reg;
    Persona(){};
    ~Persona(){};
    void datosper();
    void mostrarper();
};
void Persona::datosper()
{
    cout << "Nombre : ";
    getline(cin, reg.nom);
    cout << "Rut : ";
    getline(cin, reg.rut);
};
void Persona::mostrarper()
{
    cout << "======================" << endl;
    cout << "Nombre : " << reg.nom << endl;
    cout << "Rut : " << reg.rut << endl;
};

// Clase Profesor
class Profesor : public virtual Persona
{
public:
    string cat;
    int cant;
    Profesor(){};
    ~Profesor(){};
    void datosprof();
    void mostrarprof();
    void ingresarNotas();
};

void Profesor::datosprof()
{
    int i;
    datosper();
    cout << "Escriba la Categoria: ";
    getline(cin, cat);
};
void Profesor::mostrarprof()
{
    int i;
    mostrarper();
    cout << "Categoria : " << cat << endl;
};

void Profesor::ingresarNotas()
{

    int ingreso;
    int contador;
    string verificador;
    string nomb, notas[4], datos[80];
    ofstream MyFile("Estudiante.txt");

    string myText;

    ofstream MyFile2("Estudiante.txt");

    // Pregunta si quiere ingresar las notas manualmente o por archivo
    cout << "Ingreso de notas: ";
    cout << "\n 1. Manual";
    cout << "\n 2. Archivo";
    cout << "\n Seleccione una Opcion: ";
    cin >> ingreso;
    switch (ingreso)
    {
    case 1:
        verificador = "s";
        contador = 0;

        while (verificador != "n")
        {
            // Manual
            cout << "Ingrese su nombre: ";
            cin >> nomb;

            cout << "Ingrese su primera nota: ";
            cin >> notas[0];

            cout << "Ingrese su segunda nota: ";
            cin >> notas[1];

            cout << "Ingrese su tercera nota: ";
            cin >> notas[2];

            cout << "Ingrese su cuarta nota: ";
            cin >> notas[3];

            datos[contador] = nomb + " " + notas[0] + " " + notas[1] + " " + notas[2] + " " + notas[3];

            contador++;

            cout << "Desea agregar otro estudiante? (s/n): ";
            cin >> verificador;
        }

        // Guarda datos en archivo "Estudiante.txt"
        for (int i = 0; i < contador; i++)
        {
            MyFile << datos[i] << endl;
        }

        MyFile.close();

        break;

    case 2:

        string archivo1;
        cout << "Nombre archivo: ";
        cin >> archivo1;
        ifstream MyReadFile(archivo1);

        // Lee archivo con los nombres y notas
        while (getline(MyReadFile, myText))
        {
            cout << myText << endl;
            MyFile2 << myText << endl;
        }

        MyReadFile.close();
        MyFile2.close();
        break;
    }
}

// Clase Estudiante
class Estudiante : public virtual Persona
{
public:
    string carr;
    int can;
    Estudiante(){};
    ~Estudiante(){};
    void datosest();
    void entregarNotas();
    void mostrarest();
};

void Estudiante::datosest()
{
    int i;
    datosper();
    cout << "Ingresar Carrera que Estudia: ";
    cin >> carr;
};

void Estudiante::entregarNotas()
{
    string resultado;
    ifstream Estudiante("Estudiante.txt", ios::out | ios::app);
    if (!Estudiante.is_open())
    {
        Estudiante.open("Estudiante.txt", ios::in);
    }
    // Aquí trato de comprobar si está vacio o no
    if (sizeof(Estudiante) == 0)
    {
        cout << "El profesor no ha entregado los resultados";
    }

    // Muestra resultados si el archivo no esta vacio
    cout << "Resultados: " << endl
         << endl;
    while (!Estudiante.eof())
    {
        getline(Estudiante, resultado);
        cout << resultado << endl;
    }
    Estudiante.close();
};

void Estudiante::mostrarest()
{
    mostrarper();

    cout << "\nCarrera: " << carr << endl;
};

// asignatura
class Asignatura : public Profesor, public Estudiante
{
public:
    string s[10], a[10], c[10];
    char nom[40] = "Estudiante.txt";
    int cant;
    string mat[5] = {"PROGRAMACION", "BASE DE DATOS", "ALGORITMO Y ESTRUCTURA DE DATOS", "DESARROLLO WEB Y MOBIL", "PARADIGMAS DE PROGRAMACION"};
    string cod[5] = {"PR001", "BD002", "AE003", "DM004", "PP005"};
    Asignatura(){};
    ~Asignatura(){};
    void ingresardatosp();
    void ingresardatose();
    void notasDefinitivasP();
    void notasDefinitivasE();
    void mostrare();
    void mostrarp();
};

void Asignatura::ingresardatosp()
{
    int opcion, opc;
    datosprof();
    cout << "Escriba la Cantidad de Asignaturas: ";
    cin >> cant;
    for (int i = 0; i < cant; i++)
    {
        cout << "Seleccione las Asignaturas: ";
        cout << "\n 1. " << mat[0];
        cout << "\n 2. " << mat[1];
        cout << "\n 3. " << mat[2];
        cout << "\n 4. " << mat[3];
        cout << "\n 5. " << mat[4];
        cout << "\n Seleccione una Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            a[i] = mat[0];
            c[i] = cod[0];
            break;
        }
        case 2:
        {
            a[i] = mat[1];
            c[i] = cod[1];
            break;
        }
        case 3:
        {
            a[i] = mat[2];
            c[i] = cod[2];
            break;
        }
        case 4:
        {
            a[i] = mat[3];
            c[i] = cod[3];
            break;
        }
        case 5:
        {
            a[i] = mat[4];
            c[i] = cod[4];
            break;
        }
        }

        cout << "\n 1. Seccion 1";
        cout << "\n 2. Seccion 2";
        cout << "\n Seleccione la Seccion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            s[i] = "1";
            break;
        }
        case 2:
        {
            s[i] = "2";
            break;
        }
        }
    }
};

void Asignatura::ingresardatose()
{
    int opcion, opc;
    datosest();
    cout << "Escriba la Cantidad de Asignaturas: ";
    cin >> cant;
    for (int i = 0; i < cant; i++)
    {
        cout << "Seleccione las Asignaturas: ";
        cout << "\n 1. " << mat[0];
        cout << "\n 2. " << mat[1];
        cout << "\n 3. " << mat[2];
        cout << "\n 4. " << mat[3];
        cout << "\n 5. " << mat[4];
        cout << "\n Seleccione una Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            a[i] = mat[0];
            c[i] = cod[0];
            break;
        }
        case 2:
        {
            a[i] = mat[1];
            c[i] = cod[1];
            break;
        }
        case 3:
        {
            a[i] = mat[2];
            c[i] = cod[2];
            break;
        }
        case 4:
        {
            a[i] = mat[3];
            c[i] = cod[3];
            break;
        }
        case 5:
        {
            a[i] = mat[4];
            c[i] = cod[4];
            break;
        }
        }
        cout << "\n 1. Seccion 1";
        cout << "\n 2. Seccion 2";
        cout << "\n Seleccione la Seccion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            s[i] = "1";
            break;
        }
        case 2:
        {
            s[i] = "2";
            break;
        }
        }
    }
};

void Asignatura::notasDefinitivasP()
{

    string archivo1 = "Estudiante.txt";
    ifstream archivo(archivo1.c_str());
    string linea, nomb, n1, n2, n3, n4;
    int res, lon, i, j = 0, c = 0;
    string nombres[100], apruebo[100];
    float notas1[100], notas2[100], notas3[100], notas4[100], promFinal[100];
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

    // Sacar promedios y guardarlos en archivo
    for (int i = 0; i < c; i++)
    {
        promFinal[i] = (notas1[i] + notas2[i] + notas3[i] + notas4[i]) / 4;

        MyFile << nombres[i] << " " << promFinal[i] << endl;
    }

    MyFile.close();
}

void Asignatura::notasDefinitivasE()
{

    string archivo1 = "Estudiante.txt";
    ifstream archivo(archivo1.c_str());
    string linea, nomb, prom;
    int res, lon, i, j = 0, c = 0;
    string nombres[100], apruebo[100];
    float notas1[100], promFinal[100];
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
            apruebo[c] = "Reprobado";
        }
        if (promFinal[c] >= 4)
        {
            apruebo[c] = "Aprobado";
        }

        c++;

        j = 0;
        nomb = "";
        prom = " ";
    }
    archivo.close();

    int opc;

    // Pregunta el ramo al cual se asignan las notas
    cout << "Para cual ramo van las notas?: " << endl;
    for (int i = 0; i < cant; i++)
    {
        cout << i + 1 << "." << a[i] << ":" << endl;
    }
    cout << "Escoja una opcion: ";
    cin >> opc;

    ofstream MyFile("Estudiante.txt");
    for (int k = 0; k < c; k++)
    {

        // Muestra resultados y los guarda en archivo
        cout << a[opc - 1] << " ";
        cout << promFinal[k] << " ";
        cout << apruebo[k] << endl;

        MyFile << a[opc - 1] << " " << promFinal[k] << " " << apruebo[k] << " " << endl;
    }
    MyFile.close();
}

void Asignatura::mostrare()
{

    mostrarest();

    cout << "\nAsignaturas: \n";
    for (int i = 0; i < cant; i++)
    {
        cout << a[i] << endl;
        cout << c[i] << endl;
        cout << s[i] << endl;
        cout << endl;
    }
};

void Asignatura::mostrarp()
{
    mostrarprof();
    cout << "Cantidad Asignatura : " << cant << endl;
    cout << "Asignaturas: \n";
    for (int i = 0; i < cant; i++)
    {
        cout << a[i] << endl;
    }
};

int main()
{
    Asignatura as;
    Profesor P;
    Estudiante E;
    int opc;
    cout << "Sistema de Notas \n";
    cout << "1. Profesor: \n";
    cout << "2. Estudiante: \n";
    cout << "3. Salir \n";
    cout << "Seleccionar Opcion: ";
    cin >> opc;
    cin.ignore();

    switch (opc)
    {
    case 1:
        as.ingresardatosp();

        // ingreso de notas
        P.ingresarNotas();
        // Calculo de notas
        as.notasDefinitivasP();
        // Genera archivo de entrega de notas
        as.notasDefinitivasE();
        // as.mostrarp();
        break;
    case 2:
        as.ingresardatose();
        // Entrga de notas
        E.entregarNotas();

        // as.mostrare();
        break;
    case 3:
        cout << "Saliendo del sistema";
    }

    return 0;
}