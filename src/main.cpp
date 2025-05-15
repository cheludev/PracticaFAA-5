#include <algorithm>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

#include "RUTATAPAS.h";

int main() {
        vector<Bar> bares = {
                {"El Rincon del Choco", 9, 30, 10},
                {"Bar La Esquina", 6, 15, 5},
                {"Tapas & Canyas", 4, 15, 5},
                {"Casa Manolo", 8, 25, 5},
                {"La Bodeguita", 7, 20, 7},
                {"El Mirador", 10, 30, 12},
                {"Meson del Puerto", 5, 15, 5},
                {"La Taberna Asturiana", 8, 20, 10},
                {"El Rincon del Abuelo", 3, 25, 12},
                {"Taperia Central", 6, 20, 7}
        };

        int tiempoT = 180;

        if (bares.empty()) {
                cout << "No hay bares para ordenar ";
        } else {
                vector<Bar> estrategia1 = RUTATAPAS(bares, tiempoT, 'v');
                imprimirVectorOrdenado(estrategia1, 'v', tiempoT);

                vector<Bar> estrategia2 = RUTATAPAS(bares, tiempoT, 't');
                imprimirVectorOrdenado(estrategia2,'t', tiempoT);

                vector<Bar> estrategia3 = RUTATAPAS(bares, tiempoT, 'r');
                imprimirVectorOrdenado(estrategia3, 'r', tiempoT);
        }



}
