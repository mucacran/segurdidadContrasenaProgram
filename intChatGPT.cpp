#include <iostream>
#include <cmath>
using namespace std;

//
//identificar si es simbolos numero o letras
void analizarCaracteres(const string& str) {
    for (char caracter : str) {
        if (isdigit(caracter)) {
            cout << "El carácter '" << caracter << "' es un número." << endl;
        } else if (isalpha(caracter)) {
            cout << "El carácter '" << caracter << "' es una letra." << endl;
        } else {
            cout << "El carácter '" << caracter << "' es un símbolo." << endl;
        }
    }
}

// Función para calcular el número de combinaciones
int calcularCombinaciones(int longitud, int tamanoAlfabeto) {
    return pow(tamanoAlfabeto, longitud);
}

// Función para calcular la intensidad en bits
int calcularBits(int combinaciones) {
    return log2(combinaciones);
}

int main() {
    // Solicitar al usuario la contraseña
    cout << "Por favor ingrese la contraseña: ";
    string contraseña;
    cin >> contraseña;

    // Obtener la longitud de la contraseña y el tamaño del alfabeto (supongamos 33 símbolos)
    int longitud = contraseña.length();
    int tamanoAlfabeto = 33;

    // Calcular el número de combinaciones
    int numCombinaciones = calcularCombinaciones(longitud, tamanoAlfabeto);

    // Calcular la intensidad en bits
    int intensidadBits = calcularBits(numCombinaciones);

    // Mostrar resultados al usuario
    cout << "Hay " << numCombinaciones << " combinaciones" << endl;
    cout << "Eso equivale a una clave de " << intensidadBits << " bits." << endl;

    return 0;
}
