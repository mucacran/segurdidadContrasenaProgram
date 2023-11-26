#include <iostream>
#include <cmath>

using namespace std;

// Función para calcular el número de combinaciones
long long calcularCombinaciones(int longitud, int opciones) {
    long long nCombinaciones = 1;

    for (int i = 0; i < longitud; ++i) {
        nCombinaciones *= opciones;
    }

    return nCombinaciones;
}

// Función para calcular la intensidad en bits
int calcularBits(long long combinaciones) {
    return log2(combinaciones);
}

int main() {
    // Solicitar al usuario la contraseña
    cout << "Por favor ingrese la contraseña: ";
    string contraseña;
    getline(cin, contraseña);

    // Calcular el número total de combinaciones
    int opciones = 0;
    for (char caracter : contraseña) {
        if (isalpha(caracter)) {
            opciones += 26; // Letras
        } else if (isdigit(caracter)) {
            opciones += 10; // Números
        } else {
            opciones += 32; // Otros caracteres (símbolos)
        }
    }

    int longitud = contraseña.length();
    long long numCombinaciones = calcularCombinaciones(longitud, opciones);
    int bits = calcularBits(numCombinaciones);

    // Mostrar resultados al usuario
    cout << "Para la contraseña '" << contraseña << "':" << endl;
    cout << "Hay " << numCombinaciones << " combinaciones" << endl;
    cout << "Eso equivale a una clave de " << bits << " bits." << endl;

    return 0;
}
