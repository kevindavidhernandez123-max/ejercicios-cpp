#include <iostream>
#include <fstream>   
#include <sstream>   
#include <string>
using namespace std;

int main() {
    ifstream archivo("documento.txt"); 

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo documento.txt" << endl;
        return 1;
    }

    string linea;
    int lineas = 0;
    int total = 0;
    string palabram="";

    
    while (getline(archivo, linea)) {
        lineas++;       
        stringstream ss(linea);
        string palabra;

        while (ss>>palabra) {
            total++;

       
            if (palabra.size()>palabram.size()) {
                palabram = palabra;
            }
        }
    }

    archivo.close();
	   
    cout<<"Numero total de lineas:"<<lineas<< endl;
    cout<<"Numero total de palabras:" << total<< endl;
    cout<<"Palabra mas larga encontrada:" <<palabram<<endl;

    return 0;
}


