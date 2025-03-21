#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void logMessage(const string& mensaje, const string& nivelSeveridad) {
    //chequeo que el error este dentro de las posibilidades que teniamos.
    if (nivelSeveridad != "DEBUG" && nivelSeveridad != "INFO" && 
        nivelSeveridad != "WARNING" && nivelSeveridad != "ERROR" && 
        nivelSeveridad != "CRITICAL") {
        std::cout << "Nivel de severidad no válido: " << nivelSeveridad << std::endl;
        return;
    }

    std::ofstream outFile("ArchivoMensajes.txt", std::ios::app); //busque y esto es para abrir el archivo de modo que cuando agrego algo no cree un archivo nuevo sino que agregue abajo.
    if (outFile.is_open()) {
        outFile << "[" << nivelSeveridad << "] " << mensaje << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
}

int main() {
    string mensaje;
    string alerta;
    string respuesta = "si";

    //hago un bucle para que el usuario pueda ingresar todas las alertas que quiera.
    while (respuesta == "SI" || respuesta == "si" || respuesta == "Si") {
        cout << "Ingrese alerta: ";
        getline(cin, alerta);
        cout << "Ingrese nuevo mensaje: ";
        getline(cin, mensaje);
        logMessage(mensaje, alerta);

        cout << "¿Desea ingresar otra alerta?: ";
        getline(cin, respuesta);
    }

    cout << "Programa terminado." << endl;
}
