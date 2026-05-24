// ventas.cpp - versión C++98 compatible
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

const long long PRECIO_A = 5000LL;
const long long PRECIO_B = 12000LL;

struct Vendedor {
    string nombre;
    int productosA;
    int productosB;

    Vendedor() {
        productosA = 0;
        productosB = 0;
    }

    long long totalVenta() const {
        return 1LL * productosA * PRECIO_A + 1LL * productosB * PRECIO_B;
    }
};

struct Sucursal {
    string nombre;
    vector<Vendedor> vendedores;
    long long totalA;
    long long totalB;
    long long totalSucursal;

    Sucursal() {
        totalA = 0;
        totalB = 0;
        totalSucursal = 0;
    }
};

struct Ciudad {
    string nombre;
    vector<Sucursal> sucursales;
    long long totalA;
    long long totalB;
    long long totalCiudad;

    Ciudad() {
        totalA = 0;
        totalB = 0;
        totalCiudad = 0;
    }
};

// -------- Helpers de entrada --------
int leerEnteroNoNegativo(const string &prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x && x >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cout << "Entrada invalida. Ingrese un entero >= 0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string leerLineaNoVacia(const string &prompt) {
    string s;
    while (true) {
        cout << prompt;
        getline(cin, s);
        if (!s.empty()) return s;
        cout << "La cadena no puede estar vacia.\n";
    }
}

// -------- 1) Registrar datos --------
void registrarDatos(vector<Ciudad> &ciudades) {
    ciudades.clear();
    int nCiudades = leerEnteroNoNegativo("Ingrese cantidad de ciudades: ");
    for (int i = 0; i < nCiudades; i++) {
        Ciudad ci;
        ci.nombre = leerLineaNoVacia("\nNombre de la ciudad: ");

        int nSuc = leerEnteroNoNegativo("Cantidad de sucursales en " + ci.nombre + ": ");
        for (int j = 0; j < nSuc; j++) {
            Sucursal s;
            s.nombre = leerLineaNoVacia("\n  Nombre de la sucursal: ");

            int nVend = leerEnteroNoNegativo("  Cantidad de vendedores en " + s.nombre + ": ");
            for (int k = 0; k < nVend; k++) {
                Vendedor v;
                v.nombre = leerLineaNoVacia("    Nombre del vendedor: ");
                v.productosA = leerEnteroNoNegativo("    Productos categoria A vendidos: ");
                v.productosB = leerEnteroNoNegativo("    Productos categoria B vendidos: ");

                s.totalA += v.productosA * PRECIO_A;
                s.totalB += v.productosB * PRECIO_B;
                s.totalSucursal += v.totalVenta();

                s.vendedores.push_back(v);
            }

            ci.sucursales.push_back(s);
            ci.totalA += s.totalA;
            ci.totalB += s.totalB;
            ci.totalCiudad += s.totalSucursal;
        }
        ciudades.push_back(ci);
    }
    cout << "\nRegistro completado.\n";
}

// -------- 2) Mostrar totales --------
void mostrarTotales(const vector<Ciudad> &ciudades) {
    if (ciudades.empty()) {
        cout << "No hay datos. Use la opcion 1 para registrar.\n";
        return;
    }
    long long totalCadena = 0;
    cout << "\n=== VENTAS TOTALES ===\n";
    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        cout << "Ciudad: " << ci.nombre << "  -> Total ciudad: $" << ci.totalCiudad << "\n";
        for (size_t j = 0; j < ci.sucursales.size(); j++) {
            const Sucursal &s = ci.sucursales[j];
            cout << "   Sucursal: " << s.nombre << "  -> Total sucursal: $" << s.totalSucursal << "\n";
        }
        totalCadena += ci.totalCiudad;
    }
    cout << "TOTAL CADENA: $" << totalCadena << "\n";
}

// -------- 3) Mostrar porcentajes --------
void mostrarPorcentajes(const vector<Ciudad> &ciudades) {
    if (ciudades.empty()) {
        cout << "No hay datos. Use la opcion 1 para registrar.\n";
        return;
    }

    long long totalCadenaA = 0, totalCadenaB = 0;
    for (size_t i = 0; i < ciudades.size(); i++) {
        totalCadenaA += ciudades[i].totalA;
        totalCadenaB += ciudades[i].totalB;
    }
    long long totalCadena = totalCadenaA + totalCadenaB;

    cout << fixed << setprecision(2);
    cout << "\n=== PORCENTAJES POR CATEGORIA ===\n";

    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        cout << "\nCiudad: " << ci.nombre << "\n";
        for (size_t j = 0; j < ci.sucursales.size(); j++) {
            const Sucursal &s = ci.sucursales[j];
            long long sTotal = s.totalA + s.totalB;
            double pctA = (sTotal == 0) ? 0.0 : 100.0 * (double)s.totalA / (double)sTotal;
            double pctB = (sTotal == 0) ? 0.0 : 100.0 * (double)s.totalB / (double)sTotal;
            cout << "  Sucursal: " << s.nombre << " -> A: " << pctA << "% , B: " << pctB
                 << "% (Total $" << sTotal << ")\n";
        }
    }

    cout << "\n-- Por ciudad --\n";
    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        long long cTotal = ci.totalA + ci.totalB;
        double pctA = (cTotal == 0) ? 0.0 : 100.0 * (double)ci.totalA / (double)cTotal;
        double pctB = (cTotal == 0) ? 0.0 : 100.0 * (double)ci.totalB / (double)cTotal;
        cout << "Ciudad: " << ci.nombre << " -> A: " << pctA << "% , B: " << pctB
             << "% (Total $" << cTotal << ")\n";
    }

    cout << "\n-- Total cadena --\n";
    double pctCadA = (totalCadena == 0) ? 0.0 : 100.0 * (double)totalCadenaA / (double)totalCadena;
    double pctCadB = (totalCadena == 0) ? 0.0 : 100.0 * (double)totalCadenaB / (double)totalCadena;
    cout << "Cadena -> A: " << pctCadA << "% , B: " << pctCadB << "% (Total $" << totalCadena << ")\n";
}

// -------- 4) Mostrar mayores --------
void mostrarMayores(const vector<Ciudad> &ciudades) {
    if (ciudades.empty()) {
        cout << "No hay datos. Use la opcion 1 para registrar.\n";
        return;
    }

    cout << "\n=== MAYORES VENTAS ===\n";
    // Por sucursal
    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        cout << "\nCiudad: " << ci.nombre << "\n";
        for (size_t j = 0; j < ci.sucursales.size(); j++) {
            const Sucursal &s = ci.sucursales[j];
            if (s.vendedores.empty()) {
                cout << "  Sucursal: " << s.nombre << " -> sin vendedores.\n";
                continue;
            }
            long long bestVal = -1;
            string bestName;
            for (size_t k = 0; k < s.vendedores.size(); k++) {
                const Vendedor &v = s.vendedores[k];
                if (v.totalVenta() > bestVal) {
                    bestVal = v.totalVenta();
                    bestName = v.nombre;
                }
            }
            cout << "  Sucursal: " << s.nombre << " -> Mayor vendedor: " << bestName
                 << " con $" << bestVal << "\n";
        }
    }
    // Por ciudad
    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        long long bestVal = -1;
        string bestName, bestSucursal;
        for (size_t j = 0; j < ci.sucursales.size(); j++) {
            const Sucursal &s = ci.sucursales[j];
            for (size_t k = 0; k < s.vendedores.size(); k++) {
                const Vendedor &v = s.vendedores[k];
                if (v.totalVenta() > bestVal) {
                    bestVal = v.totalVenta();
                    bestName = v.nombre;
                    bestSucursal = s.nombre;
                }
            }
        }
        if (bestVal >= 0)
            cout << "Ciudad: " << ci.nombre << " -> Mayor vendedor: " << bestName
                 << " (Sucursal: " << bestSucursal << ") con $" << bestVal << "\n";
        else
            cout << "Ciudad: " << ci.nombre << " -> no hay vendedores.\n";
    }
    // Por cadena
    long long bestValChain = -1;
    string bestName, bestCity, bestSuc;
    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        for (size_t j = 0; j < ci.sucursales.size(); j++) {
            const Sucursal &s = ci.sucursales[j];
            for (size_t k = 0; k < s.vendedores.size(); k++) {
                const Vendedor &v = s.vendedores[k];
                if (v.totalVenta() > bestValChain) {
                    bestValChain = v.totalVenta();
                    bestName = v.nombre;
                    bestCity = ci.nombre;
                    bestSuc = s.nombre;
                }
            }
        }
    }
    if (bestValChain >= 0)
        cout << "\nCadena -> Mayor vendedor: " << bestName << " (Ciudad: " << bestCity
             << ", Sucursal: " << bestSuc << ") con $" << bestValChain << "\n";
}

// -------- 5) Mostrar promedios --------
void mostrarPromedios(const vector<Ciudad> &ciudades) {
    if (ciudades.empty()) {
        cout << "No hay datos. Use la opcion 1 para registrar.\n";
        return;
    }
    cout << "\n=== PROMEDIOS ===\n";
    long long totalCadena = 0;
    long long countCadena = 0;
    for (size_t i = 0; i < ciudades.size(); i++) {
        const Ciudad &ci = ciudades[i];
        cout << "\nCiudad: " << ci.nombre << "\n";
        long long cityTotal = 0;
        long long cityCount = 0;
        for (size_t j = 0; j < ci.sucursales.size(); j++) {
            const Sucursal &s = ci.sucursales[j];
            long long sTotal = s.totalSucursal;
            long long sCount = (long long) s.vendedores.size();
            double avgS = (sCount == 0) ? 0.0 : (double) sTotal / (double) sCount;
            cout << "  Sucursal: " << s.nombre << " -> Promedio por vendedor: $" << avgS << "\n";
            cityTotal += sTotal;
            cityCount += sCount;
        }
        double avgC = (cityCount == 0) ? 0.0 : (double) cityTotal / (double) cityCount;
        cout << "  Promedio ciudad " << ci.nombre << " -> $" << avgC << "\n";
        totalCadena += cityTotal;
        countCadena += cityCount;
    }
    double avgChain = (countCadena == 0) ? 0.0 : (double) totalCadena / (double) countCadena;
    cout << "\nPromedio cadena por vendedor -> $" << avgChain
         << " (sobre " << countCadena << " vendedores)\n";
}

// -------- main --------
int main() {
    vector<Ciudad> ciudades;
    int opcion = 0;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar datos\n";
        cout << "2. Mostrar totales\n";
        cout << "3. Mostrar porcentajes\n";
        cout << "4. Mostrar mayores ventas\n";
        cout << "5. Mostrar promedios\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcion) {
            case 1: registrarDatos(ciudades); break;
            case 2: mostrarTotales(ciudades); break;
            case 3: mostrarPorcentajes(ciudades); break;
            case 4: mostrarMayores(ciudades); break;
            case 5: mostrarPromedios(ciudades); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);
    return 0;
}


