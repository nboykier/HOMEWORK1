#include <iostream>
using namespace std;

constexpr bool compareStringsCompileTime(const char* str1, const char* str2) {
    //como implemento de forma recursiva si ambos son vacio significara que llegamos al final y pasamos.
    //por los otros dos filtros que en caso de ser distintos ya hubieran descartado la hipotesis.
    //de que ambas cadenas son iguales.
    //uso char* porque segun entendi no podia usar funciones, y las funciones son las que me hubieran echo que sea mas
    //sencillo usando string, pero al no poder, el uso de char me parece mas facil entender
    //como es que voy recorriendo un array de caracteres entonces me imagino como voy comparando
    //un caracter a otro de una manera para mi mas entendible.
    if (*str1 == '\0' && *str2 == '\0') {
        return true;
    }
    if (*str1 == '\0' || *str2 == '\0') {
        return false;
    }
    if (*str1 != *str2) {
        return false;
    }
    return compareStringsCompileTime(str1 + 1, str2 + 1);
}
int main() {
    constexpr bool result = compareStringsCompileTime("Esta es una cadena de ejemplo con exactamente sesenta y cinco caracteres", "Esta es una cadena de ejemplo con exactamente sesenta y cinco caracteres");
    if(result){
        cout << "Las cadenas son iguales" << endl;
    } else {
        cout << "Las cadenas son distintas" << endl;
    }
    constexpr bool result_negativo = compareStringsCompileTime("Esta es una cadena de ejemplo con exactamente sesenta y cinco caracteres diferente", "Esta es una cadena de ejemplo con exactamente sesenta y cinco caracteres");
    if(result_negativo){
        cout << "Las cadenas son iguales" << endl;
    } else {
        cout << "Las cadenas son distintas" << endl;
    }
    return 0;
}
