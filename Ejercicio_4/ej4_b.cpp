#include <iostream>
#include <chrono>
using namespace std;

constexpr bool compareStringsCompileTime(const char* str1, const char* str2) {
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
    //uso la funcion de chrono.
    auto startTime = std::chrono::high_resolution_clock::now();
    
    constexpr bool result = compareStringsCompileTime("Esta es una cadena de ejemplo con exactamente sesenta y cinco caracteres", "Esta es una cadena de ejemplo con exactamente sesenta y cinco caracteres");
    if(result){
        cout << "Las cadenas son iguales" << endl;
    } else {
        cout << "Las cadenas son distintas" << endl;
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    cout << "La comparación tomó: " << elapsedTime.count() << " nanosegundos." << endl;
    return 0;
}