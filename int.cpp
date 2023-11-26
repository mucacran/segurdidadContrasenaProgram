#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;


// Función para calcular el número de combinaciones
long long calcularCombinaciones(int longitud, const string& str) {
    int nCombinaciones = 0;

    bool vNumero = true;
    bool vSimbolo = true;
    bool vLetraMayuscula = true;
    bool vLetraMinuscula = true;


    for (char caracter : str) {
        if (isdigit(caracter)) {
            if(vNumero == true){
                nCombinaciones += 10;
                vNumero = false;
            }
        } else if (isupper(caracter)) {
            if(vLetraMayuscula == true){
                nCombinaciones += 26;
                vLetraMayuscula = false;
            }
        } else if(islower(caracter)){
            if(vLetraMinuscula == true){
                nCombinaciones += 26;
                vLetraMinuscula = false;
            }
        }else {
            if(vSimbolo == true){
                nCombinaciones += 33;
                vSimbolo = false;
            }
        }
    }

    //return nCombinaciones;
    return pow(nCombinaciones, longitud);
}

// Función para calcular la intensidad en bits
int calcularBits(long long combinaciones) {
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
    long long numCombinaciones = calcularCombinaciones(longitud,contraseña);

    // Calcular la intensidad en bits
    int intensidadBits = calcularBits(numCombinaciones);

    // Mostrar resultados al usuario
    cout << "There are " << numCombinaciones << " combinations" << endl;
    cout << " That is equivalent to a key of " << intensidadBits << " bits." << endl;

    return 0;
}
