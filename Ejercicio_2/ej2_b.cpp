#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void logMessage(string mensaje, string archivo, int linea) {
    //hago el mismo codigo de antes pero lo ajusto para que las alertas puedan ser mensajes personalizados.
    //para el manejo de errores hago un try-catch que devuelva error si el archivo no se pudo abrir.
    try {
        ofstream outFile("ArchivoMensajes.txt", ios::app);
        if (!outFile.is_open()) {
            throw runtime_error("Error al abrir el archivo");
        }
        outFile << mensaje << " EL ARCHIVO QUE TIENE UN ERROR ES: " << archivo << " EL ERROR ES EN LA LINEA: " << linea << endl;
        outFile.close();
    } catch (const runtime_error& error) {
        cerr << error.what() << endl;
        exit(1);
    }
    //en caso de que el archivo no se pueda abrir el codigo salta a la parte del catch donde se maneja este error, el .what agarra el error que se produjo y se le informa al usuario.
}

void logMessage(string mensajeAcceso, string usuario) {
    //hago la funcion con el mismo nombre ya que aca lo que importa es la declaracion completa y se distinguen por los parametros.
    try {
        ofstream outFile("ArchivoMensajes.txt", ios::app);
        if (!outFile.is_open()) {
            throw runtime_error("Error al abrir el archivo");
        }
        outFile << "[SECURITY] " << mensajeAcceso << " " << usuario << endl;
        outFile.close();
    } catch (const runtime_error& error) {
        cerr << error.what() << endl;
        exit(1);
    }
}

int main() {
    string mensaje;
    string archivo;
    int linea;
    string respuesta = "si";
    string usuarios;
    string mensaje_de_seguridad;

    cout << "Desea ingresar con su usuario? ";
    getline(cin, usuarios);

    if (usuarios == "si" || usuarios == "SI" || usuarios == "Si") {
        cout << "Por favor ingrese su usuario: ";
        getline(cin, usuarios);
        cout << "Por favor ingrese su mensaje de seguridad: ";
        getline(cin, mensaje_de_seguridad);

        logMessage(mensaje_de_seguridad, usuarios);
    }

    while (respuesta == "SI" || respuesta == "si" || respuesta == "Si") {
        cout << "Ingrese mensaje de error: ";
        getline(cin, mensaje);
        cout << "Ingrese nombre del archivo: ";
        getline(cin, archivo);
        cout << "Ingrese número de línea: ";
        cin >> linea;
        cin.ignore();//esto lo hago para que no haya problemas con el entero que ingreso y no uso getline porque es solo para strings.

        logMessage(mensaje, archivo, linea);
        cout << "Desea ingresar otro mensaje? (si/no): ";
        getline(cin, respuesta);
    }

    cout << "Programa terminado." << endl;
}