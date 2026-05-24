#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Estudiante {
    char cedula[20];
    char nombre[50];
    char grado[10];
    double saldo;
};

struct Producto {
    char codigo[20];
    char nombre[50];
    double precio;
    int stock;
};

struct Compra {
    char fecha[12];
    char prodNombre[50];
    double valor;
    char estCedula[20];
};

// --- UTILIDADES ---
void limpiarPantalla() {
    system("cls"); 
}

void limpiarBuffer() {
    // Limpia el flujo de entrada en caso de errores o saltos de línea pendientes
    cin.ignore(10000, '\n'); 
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    limpiarBuffer();
    cin.get();
}

void leerCadena(char* buffer, int tam) {
    limpiarBuffer();
    cin.getline(buffer, tam);
}

void leerPalabra(char* buffer, int tam) {
    cin >> setw(tam) >> buffer;
    limpiarBuffer();
}

bool esFechaValida(const char* fecha) {
    int dia,mes,anio;
    // sscanf ayuda a separar la cadena "DD/MM/AAAA" en 3 variables enteras
    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio) != 3) return false;
    if (anio<2000 || anio > 2100) return false;
    if (dia<1) return false;
    if (mes<1 || mes > 12) return false;
    
    // usamos el Truco del índice 0. Ponemos un 0 al inicio para que
    // Enero sea el índice 1, Febrero el 2, etc. Facilita la lógica.
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Ajuste para años bisiestos (Febrero tiene 29 días)
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasPorMes[2] = 29;
    }
    
    // Validamos si el día ingresado es mayor al permitido para ese mes
    if (dia > diasPorMes[mes]) return false;
    
    return true;
}

// --- BÚSQUEDAS ---
long buscarEstudiante(const char* cedula) {
    ifstream f("estudiantes.dat", ios::binary);
    if (!f) return -1;
    Estudiante e;
    while (f.read((char*)&e, sizeof(Estudiante))) {
        if (strcmp(e.cedula, cedula) == 0) {
            
            // tellg() nos dice dónde está el puntero AHORA (al final del registro leído).
            // Restamos sizeof(Estudiante) para devolver la posición DE INICIO de este registro.
            // Esto servirá para sobrescribirlo después.
            return (long)f.tellg() - sizeof(Estudiante);
        }
    }
    return -1; // -1 significa que no se encontró
}

long buscarProducto(const char* codigo) {
    ifstream f("productos.dat", ios::binary);
    if (!f) return -1;
    Producto p;
    while (f.read((char*)&p, sizeof(Producto))) {
        if (strcmp(p.codigo, codigo) == 0) return (long)f.tellg() - sizeof(Producto);
    }
    return -1;
}

bool tieneComprasRegistradas(const char* cedula) {
    ifstream f("compras.dat", ios::binary);
    if (!f) return false;
    Compra c;
    while (f.read((char*)&c, sizeof(Compra))) {
        if (strcmp(c.estCedula, cedula) == 0) {
            return true;
        }
    }
    return false;
}

//FUNCIONES PRINCIPALES 

void registrarEstudiante() {
    Estudiante e;
    limpiarPantalla();
    cout << "=== REGISTRO DE ESTUDIANTE ===\n";

    cout << "Cedula: ";
    leerPalabra(e.cedula, 20);

    // Verificamos duplicados antes de pedir más datos
    if (buscarEstudiante(e.cedula) != -1) {
        cout << ">> Error: La cedula ya se encuentra registrada.\n"; return;
    }

    cout << "Nombre: ";
    cin.getline(e.nombre, 50);

    cout << "Grado: ";
    cin >> setw(10) >> e.grado;

    do {
        cout << "Saldo Inicial (Min $5000): ";
        cin >> e.saldo;
        
        // Validación : Si el usuario escribe letras en vez de números
        if(cin.fail()) {
            cin.clear(); // Limpia el estado de error
            limpiarBuffer(); // Descarta la entrada incorrecta
            e.saldo = 0;
            cout << ">> Error: Valor numerico invalido.\n";
            continue; 
        }
        
        if (e.saldo < 5000) {
            cout << ">> Saldo insuficiente. Debe ser minimo $5000.\n";
        }
    } while (e.saldo < 5000);

    // ios::app permite añadir al final sin borrar lo anterior
    ofstream f("estudiantes.dat", ios::binary | ios::app);
    if (!f) { cout << ">> Error critico: No se puede acceder al archivo.\n"; return; }
    
    f.write((char*)&e, sizeof(Estudiante));

    // Verificación de escritura: Asegura que el disco no esté lleno
    if (!f) {
        cout << ">> ERROR GRAVE: Fallo de escritura (Disco lleno o error I/O).\n";
        f.close();
        return;
    }
    f.close();
    cout<<">> Estudiante registrado exitosamente.\n";
}

void agregarProducto() {
    Producto p;
    limpiarPantalla();
    cout<<"=== NUEVO PRODUCTO ===\n";

    cout<<"Codigo: ";
    leerPalabra(p.codigo, 20);

    if (buscarProducto(p.codigo) != -1) {
        cout<<">> Error: Codigo duplicado.\n"; return;
    }

    cout << "Nombre Producto: ";
    cin.getline(p.nombre, 50);

    do {
        cout << "Precio: "; cin >> p.precio;
        if (cin.fail() || p.precio <= 0) {
            cin.clear(); limpiarBuffer(); p.precio = 0;
            cout<<">> Precio invalido.\n";
        }
    } while (p.precio <= 0);

    do {
        cout<< "Stock: "; cin >> p.stock;
        if (cin.fail() || p.stock < 0) {
            cin.clear(); limpiarBuffer(); p.stock = -1;
            cout << ">> Stock invalido.\n";
        }
    } while (p.stock < 0);

    ofstream f("productos.dat", ios::binary | ios::app);
    if (!f) { cout << ">> Error al abrir archivo de productos.\n"; return; }

    f.write((char*)&p, sizeof(Producto));
    
    if(!f) {
        cout<<">> ERROR GRAVE: No se pudo guardar el producto.\n";
    } else {
        cout<<">> Producto agregado al inventario.\n";
    }
    f.close();
}

void realizarCompra() {
    char cedula[20], codigo[20];
    limpiarPantalla();
    cout << "=== CAJA / VENTA ===\n";

    cout << "Cedula Estudiante: ";
    leerPalabra(cedula, 20);

    long posEst = buscarEstudiante(cedula);
    if (posEst == -1) { cout << ">> Error: Estudiante no encontrado.\n"; return; }

    cout << "Codigo Producto: ";
    leerPalabra(codigo, 20);

    long posProd = buscarProducto(codigo);
    if (posProd == -1) { cout << ">> Error: Producto no encontrado.\n"; return; }

    // EXPLICACIÓN: Abrimos con 'in | out' para leer Y escribir en el mismo archivo.
    fstream fEst("estudiantes.dat", ios::binary | ios::in | ios::out);
    fstream fProd("productos.dat", ios::binary | ios::in | ios::out);

    if (!fEst || !fProd) { 
        cout << ">> Error: No se pueden abrir los archivos de datos.\n"; 
        return; 
    }

    Estudiante e; 
    Producto p;

    // 1. LEEMOS LOS DATOS ACTUALES
    // seekg (Seek Get) mueve el puntero de LECTURA a la posición encontrada
    fEst.seekg(posEst);
    if (fEst.fail() || !fEst.read((char*)&e, sizeof(Estudiante))) {
        cout << ">> Error Fatal: No se pudo leer el registro del estudiante.\n";
        return;
    }

    fProd.seekg(posProd);
    if (fProd.fail() || !fProd.read((char*)&p, sizeof(Producto))) {
        cout << ">> Error Fatal: No se pudo leer el registro del producto.\n";
        return;
    }

    // Validaciones de negocio
    if (p.stock <= 0) {
        cout << ">> Error: Producto AGOTADO.\n"; return;
    }
    if (e.saldo < p.precio) {
        cout << ">> Error: Saldo insuficiente.\n"; return;
    }

    // Modificamos en memoria RAM
    e.saldo -= p.precio;
    p.stock--;

    // 2. ESCRIBIMOS LOS DATOS ACTUALIZADOS (Sobrescribimos)
    // seekp (Seek Put) mueve el puntero de ESCRITURA a la misma posición
    fEst.seekp(posEst); 
    fEst.write((char*)&e, sizeof(Estudiante));
    if (!fEst) { 
        cout << ">> ERROR CRITICO: Fallo al actualizar saldo.\n"; 
        return; 
    }

    fProd.seekp(posProd); 
    fProd.write((char*)&p, sizeof(Producto));
    if (!fProd) {
        cout << ">> ERROR CRITICO: Fallo al actualizar stock.\n";
        return;
    }

    fEst.close();
    fProd.close();

    // 3. REGISTRAR EN EL HISTORIAL
    Compra c;
    do {
        cout<< "Fecha (DD/MM/AAAA): ";
        leerPalabra(c.fecha, 12);
        if (!esFechaValida(c.fecha)) cout << ">> Error: Fecha invalida.\n";
    } while(!esFechaValida(c.fecha));

    strncpy(c.prodNombre, p.nombre, 49); 
    c.valor = p.precio;
    strncpy(c.estCedula, e.cedula, 19);

    ofstream fComp("compras.dat", ios::binary | ios::app);
    if (fComp) {
        fComp.write((char*)&c, sizeof(Compra));
        if(!fComp) cout << ">> Advertencia: Venta hecha, pero falló registro historico.\n";
    } else {
        cout << ">> Advertencia: No se pudo acceder al historial de compras.\n";
    }
    
    cout << ">> Venta exitosa. Nuevo saldo: $" << e.saldo << "\n";
}

void recargarSaldo() {
    char cedula[20];
    double monto;
    limpiarPantalla();
    cout << "=== RECARGAR SALDO ===\n";

    cout << "Cedula: ";
    leerPalabra(cedula, 20);

    long pos = buscarEstudiante(cedula);
    if (pos == -1) {cout << ">> Error: Estudiante no encontrado.\n"; return; }

    // Abrimos en modo lectura/escritura para modificar solo el saldo
    fstream f("estudiantes.dat", ios::binary | ios::in | ios::out);
    if (!f) { cout << ">> Error de acceso a archivo.\n"; return; }

    Estudiante e;

    f.seekg(pos);
    if (!f.read((char*)&e, sizeof(Estudiante))) {
        cout << ">> Error: No se pudo leer el registro.\n";
        return;
    }

    cout<< "Estudiante: " << e.nombre << " | Saldo Actual: $" << fixed << setprecision(2) << e.saldo << "\n";
    cout<< "Monto a recargar (Max $500,000): ";
    cin>>monto;

    if (cin.fail() || monto <= 0 || monto > 500000) {
        cin.clear(); limpiarBuffer();
        cout << ">> Error: Monto invalido.\n";
    } else {
        e.saldo += monto;
        
        // Regresamos a la posición original y guardamos
        f.seekp(pos);
        f.write((char*)&e, sizeof(Estudiante));
        
        if(!f) {
            cout << ">> ERROR: Fallo al guardar el nuevo saldo.\n";
        } else {
            cout << ">> Recarga exitosa. Nuevo saldo: $" << e.saldo << "\n";
        }
    }
    f.close();
}

void eliminarEstudiante() {
    char cedula[20];
    limpiarPantalla();
    cout << "=== ELIMINAR ESTUDIANTE ===\n";
    cout << "Cedula: ";
    leerPalabra(cedula, 20);

    if (buscarEstudiante(cedula) == -1) {
        cout << ">> Error: El estudiante no existe.\n"; return;
    }

    // Regla de integridad: No borrar si tiene historial
    if (tieneComprasRegistradas(cedula)) {
        cout<< ">> BLOQUEADO: Estudiante con historial de compras activo.\n";
        return;
    }

    ifstream in("estudiantes.dat", ios::binary);
    if (!in) { cout << ">> Error al leer base de datos.\n"; return; }

    //  Como no podemos borrar un "pedazo" de un archivo secuencial fácilmente,
    // creamos un archivo temporal nuevo.
    ofstream out("temp.dat", ios::binary);
    if (!out) { cout << ">> Error: No se puede crear archivo temporal.\n"; in.close(); return; }
    
    // Archivo de texto para auditoría
    ofstream ret("retiros.txt", ios::app);

    Estudiante e;
    bool eliminado = false;
    bool errorIO = false;

    // Copiamos TODOS los estudiantes al temporal, MENOS el que queremos borrar
    while (in.read((char*)&e, sizeof(Estudiante))) {
        if (strcmp(e.cedula, cedula) == 0) {
            eliminado = true;
            if(ret) {
                ret << "Eliminado: " << e.nombre << " (CC: " << e.cedula << ")\n";
            }
        } else {
            out.write((char*)&e, sizeof(Estudiante));
            if(!out) { errorIO = true; break; } 
        }
    }
    
    in.close(); 
    out.close(); 
    ret.close();

    // Gestión final de archivos: Borrar original -> Renombrar temporal
    if (errorIO) {
        cout << ">> ERROR: Fallo de disco. Restaurando backup...\n";
        remove("temp.dat"); 
    } else if (eliminado) {
        if (remove("estudiantes.dat") != 0) {
            cout << ">> Error: No se pudo borrar el archivo original.\n";
        } else if (rename("temp.dat", "estudiantes.dat") != 0) {
            cout << ">> Error Critico: Fallo al renombrar archivo temporal.\n";
        } else {
            cout << ">> Estudiante eliminado correctamente.\n";
        }
    } else {
        remove("temp.dat");
        cout << ">> Operacion cancelada.\n";
    }
}

void mostrarConsultas() {
    char op;
    do {
        limpiarPantalla();
        cout<< "=== CONSULTAS ===\n"
             <<"a. Consultar Estudiante\n"
             <<"b. Listar Inventario\n"
             <<"c. Saldos Bajos (<$5000)\n"
             <<"d. Volver\n"
             <<"Opcion: ";
        cin>>op;
        limpiarBuffer();

        if (op == 'a') {
            char cedula[20];
            cout<<"Cedula: "; leerPalabra(cedula, 20);

            long pos = buscarEstudiante(cedula);
            if (pos != -1) {
                ifstream f("estudiantes.dat", ios::binary);
                if(f) {
                    Estudiante e;
                    f.seekg(pos); 
                    
                    if(f.read((char*)&e, sizeof(Estudiante))) {
                         cout<< "\n--- DATOS ---\n"
                             << "Nombre: " << e.nombre << "\n"
                             << "Grado:  " << e.grado << "\n"
                             << "Saldo:  $" << fixed << setprecision(2) << e.saldo << "\n";
                             
                        cout<< "\n--- HISTORIAL DE COMPRAS ---\n";
                        ifstream fc("compras.dat", ios::binary);
                        if(fc) {
                            Compra c;
                            bool hay = false;
                            cout << left << setw(12) << "FECHA" << setw(25) << "PRODUCTO" << "VALOR" << endl;
                            cout << string(45, '-') << endl;
                            while (fc.read((char*)&c, sizeof(Compra))) {
                                if (strcmp(c.estCedula, cedula) == 0) {
                                    cout << left << setw(12) << c.fecha
                                         << setw(25) << c.prodNombre
                                         << "$" << c.valor << endl;
                                    hay = true;
                                }
                            }
                            if(!hay) cout << "(Este estudiante no ha realizado compras)\n";
                            fc.close();
                        }
                    } else {
                        cout << ">> Error al leer datos del estudiante.\n";
                    }
                    f.close();
                }
            } else cout<< ">> No existe el estudiante.\n";
            pausar();
        }
        else if (op == 'b') {
            ifstream f("productos.dat", ios::binary);
            if(!f) { cout << "Inventario vacio.\n"; pausar(); continue; }
            Producto p;
            cout << "\n" << left << setw(10) << "CODIGO" << setw(25) << "NOMBRE" << setw(10) << "PRECIO" << "STOCK" << endl;
            cout << string(55, '-') << endl;
            while (f.read((char*)&p, sizeof(Producto)))
                cout << left << setw(10) << p.codigo << setw(25) << p.nombre
                     << "$" << setw(9) << fixed << setprecision(2) << p.precio << p.stock << endl;
            f.close();
            pausar();
        }
        else if (op == 'c') {
            ifstream f("estudiantes.dat", ios::binary);
            if(!f) { cout << "Sin datos.\n"; pausar(); continue; }
            Estudiante e;
            cout << "\n--- ESTUDIANTES CON SALDO BAJO (< $5000) ---\n";
            while (f.read((char*)&e, sizeof(Estudiante)))
                if (e.saldo < 5000) cout << "- " << e.nombre << " (Saldo: $" << e.saldo << ")\n";
            f.close();
            pausar();
        }
    } while (op != 'd');
}

int main() {
    int op;
    do {
        limpiarPantalla();
        cout<<"================================\n";
        cout<<"  TIENDA ESCOLAR 'EstuMercado'  \n";
        cout<<"================================\n";
        cout<<"1. Registrar Estudiante\n";
        cout<<"2. Agregar Producto\n";
        cout<<"3. Realizar Compra\n";
        cout<<"4. Recargar Saldo\n";
        cout<<"5. Eliminar Estudiante\n";
        cout<<"6. Consultas\n";
        cout<<"7. Salir\n";
        cout<<"Seleccione: ";

        cin>>op;

        if (cin.fail()) {
            cin.clear();
            limpiarBuffer();
            op = 0;
        } else {
            limpiarBuffer();
        }

        switch (op) {
            case 1:registrarEstudiante(); pausar(); break;
            case 2:agregarProducto(); pausar(); break;
            case 3:realizarCompra(); pausar(); break;
            case 4:recargarSaldo(); pausar(); break;
            case 5:eliminarEstudiante(); pausar(); break;
            case 6:mostrarConsultas(); break;
            case 7:cout << "Saliendo del sistema...\n"; break;
            default:cout << "Opcion invalida. Intente de nuevo.\n"; pausar();
        }
    } while (op!=7);
    return 0;
}
