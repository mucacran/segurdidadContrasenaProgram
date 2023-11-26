#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;


// Función para calcular el número de combinaciones
int calcularCombinaciones(int longitud, const string& str) {

    int nCombinaciones = 1;

    for (char caracter : str) {
        if (isdigit(caracter)) {
            nCombinaciones += 10;            
        } else if (isalpha(caracter)) {
            nCombinaciones += 26;
        } else {
            cout << "El carácter '" << caracter << "' es un símbolo." << endl;
             nCombinaciones += 33;
        }
    }

    return nCombinaciones;
}

// Función para calcular la intensidad en bits
int calcularBits(int combinaciones) {
    return log2(combinaciones);
}

int main() {
    // Solicitar al usuario la contraseña
    cout << "Please enter the password: ";
    string contraseña;
    getline(cin, contraseña);

    // Obtener la longitud de la contraseña y el tamaño del alfabeto (supongamos 33 símbolos)
    int longitud = contraseña.length();


    // Calcular el número de combinaciones
    int numCombinaciones = calcularCombinaciones(longitud,contraseña);

    // Calcular la intensidad en bits
    int intensidadBits = calcularBits(numCombinaciones);

    // Mostrar resultados al usuario
    cout << "Hay " << numCombinaciones << " combinaciones" << endl;
    cout << "Eso equivale a una clave de " << intensidadBits << " bits." << endl;

    return 0;
}
