# Paradigmas-8509
8509
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
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
        float n_float = stof(n1);
        float n2_float = stof(n2);
        float n3_float = stof(n3);
        float n4_float = stof(n4);
        float totaln[4] = {n_float, n2_float, n3_float, n4_float};
        string nombre_a[] = {nomb};

        cout<<n_float<<endl;
        cout<<n2_float<<endl;
        cout<<n3_float<<endl;
        cout<<n4_float<<endl;
        j=0;
        nomb=" ";
        n1=" ";
        n2=" ";
        n3=" ";
        n4=" ";
        }
  }
