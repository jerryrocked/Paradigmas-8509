#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string doc="archivo1.txt";
    ifstream txt(doc.c_str());
    
    string linea, nom, n1, n2, n3, n4;
	vector<string> nombres;
	vector<float> nt1, nt2, nt3, nt4;
	
    int cont_lineas, largo, i, j=0;
    char sp=' ';
      
    while (getline(txt, linea)) {
        for (i = 0; i < linea.length(); i++){
            if (linea[i] != sp){
                if (j == 0){
                nom = nom + linea[i];
	                if (linea[i+1] == sp)
	                	nombres.push_back(nom);
           		}
                if (j == 1){
                	n1 = n1 + linea[i];
	                if (linea[i+1] == sp)
	                	nt1.push_back(stof(n1));					
				}               
                if (j == 2){
                	n2 = n2 + linea[i];
	                if (linea[i+1] == sp)
	                	nt2.push_back(stof(n2));
				}                  
                if (j == 3){
                	n3 = n3 + linea[i];
	                if (linea[i+1] == sp)
	                	nt3.push_back(stof(n3));					
				}                  
                if (j == 4){
                	n4 = n4 + linea[i];
	                if (linea[i-1] == sp)
	                	nt4.push_back(stof(n4));					
				}	                      
            }
            else
            	j++; 
        }
		cont_lineas = cont_lineas + 1;          
        j = 0;
        nom = " ";
        n1 = " ";
        n2 = " ";
        n3 = " ";
        n4 = " ";   
    }
 
 	for(int i = 0; i < cont_lineas; i++){
 		cout<<nombres[i]<<nt1[i]<<nt2[i]<<nt3[i]<<nt4[i]<< endl;
	}
	txt.close();
}

