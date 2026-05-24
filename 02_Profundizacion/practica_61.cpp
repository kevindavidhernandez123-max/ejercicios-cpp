#include <iostream>
#include <fstream>   // para ifstream, ofstream
#include <cstring>   // para strcpy

using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    // 1. Creamos 3 alumnos
    Alumno a1, a2, a3;

    a1.nombre= "Juan Perez";
    a1.edad = 20;
    a1.promedio = 4.5f;

    a2.nombre= "Maria Gomez";
    a2.edad = 19;
    a2.promedio = 4.8f;

    a3.nombre= "Luis Rodriguez";
    a3.edad = 21;
    a3.promedio = 4.2f;

    // 2. Guardamos los 3 alumnos en el archivo binario
    ofstream archivoSalida("alumnos.bin", ios::binary);
    if (!archivoSalida) {
        cout << "Error al abrir el archivo para escritura." << endl;
        return 1;
    }

    archivoSalida.write(reinterpret_cast<char*>(&a1), sizeof(Alumno));
    archivoSalida.write(reinterpret_cast<char*>(&a2), sizeof(Alumno));
    archivoSalida.write(reinterpret_cast<char*>(&a3), sizeof(Alumno));

    archivoSalida.close();

    // 3. Leemos los alumnos desde el archivo y los mostramos
    ifstream archivoEntrada("alumnos.bin", ios::binary);
    if (!archivoEntrada) {
        cout << "Error al abrir el archivo para lectura." << endl;
        return 1;
    }

    Alumno aux;
    cout << "Datos de los alumnos leidos desde alumnos.bin:\n" << endl;

    // Mientras se pueda leer un registro completo de tipo Alumno
    while (archivoEntrada.read(reinterpret_cast<char*>(&aux), sizeof(Alumno))) {
        cout << "Nombre:   " << aux.nombre << endl;
        cout << "Edad:     " << aux.edad << endl;
        cout << "Promedio: " << aux.promedio << endl;
        cout << "-------------------------" << endl;
    }

    archivoEntrada.close();

    return 0;
}

