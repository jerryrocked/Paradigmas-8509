#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include<stdlib.h>

using namespace std;
int main() {
    string archivo1="archivo1.txt";
    ifstream archivo(archivo1.c_str());
    string linea,nomb,n1,n2,n3,n4;
    int res,lon,i,j=0;
    string arreglo[100];
    char b,l;
    while (getline(archivo,linea)) {
        cout<<linea<<endl;
        lon = linea.length();
        for (i=0;i<lon;i++){
            l=linea[i];
            b=' ';
            if (l!=b){
                if (j==0)
                    nomb=nomb+linea[i];
                if (j==1)
                    n1=n1+linea[i];
                if (j==2)
                    n2=n2+linea[i];
                if (j==3)
                    n3=n3+linea[i];
                if (j==4)
                    n4=n4+linea[i];    
            }
            else
                j++;
        }
        cout<<nomb<<endl;
        cout<<n1<<endl;
        cout<<n2<<endl;
        cout<<n3<<endl;
        cout<<n4<<endl;
        j=0;
        nomb=" ";
        n1=" ";
        n2=" ";
        n3=" ";
        n4=" ";
        int TAMANO=50;
        double LISTA[TAMANO];
        double NOTAS=0;
        int i=0;
        
        ifstream dato;
        
        dato.open(archivo1.c_str());
        
        if(dato.is_open()){
        	while(getline(dato,linea)){
        		NOTAS=atof(linea);
        		LISTA[i]=NOTAS;
        		i++;
        	}
        }
        dato.close();
        
        for(i=0;i<TAMANO;i++){
        	 cout<<"lista de notas:"<<LISTA[TAMANO];
        }
        
       
        
        //res=n1+n2+n3+n4;
        }
    }
