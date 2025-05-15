//
// Created by chxlxs0 on 07/05/2025.
//

#include <iostream>
#include <vector>
#include "VERSERIES.h"

using namespace std;

int main() {
    vector<Serie> series = {
        {"Stranger Things", 3, 50, 8, 0},
        {"Breaking Bad", 2, 45, 9, 1},
        {"The Office", 5, 22, 7, 2},
        {"Game of Thrones", 2, 60, 9, 3},
        {"Brooklyn Nine-Nine", 4, 22, 6, 2},
        {"The Mandalorian", 2, 40, 8, 0},
        {"Peaky Blinders", 3, 55, 7, 1},
        {"The Witcher", 2, 60, 7, 3},
        {"Money Heist", 3, 45, 8, 4},
        {"The Boys", 2, 55, 8, 4}
    };

    int tiempoDisponible = 600;

    vector<Serie> seleccionadas = maratonseries_capitulos(series, tiempoDisponible, 'v');
    imprimirResultado(seleccionadas, tiempoDisponible, 'v');

    seleccionadas = maratonseries_capitulos(series, tiempoDisponible, 'd');
    imprimirResultado(seleccionadas, tiempoDisponible, 'd');

    seleccionadas = maratonseries_capitulos(series, tiempoDisponible, 'r');
    imprimirResultado(seleccionadas, tiempoDisponible, 'r');

    return 0;
}
