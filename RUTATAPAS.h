#ifndef RUTATAPAS_H
#define RUTATAPAS_H

#include <algorithm>
#include <locale>
#include <vector>
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

struct Bar {
    char nombre[50];
    int valoracion;
    int tiempoConsumicion;
    int tiempoDesplazamiento;
};

vector<Bar> RUTATAPAS(vector<Bar> bares, int tiempoDisponible);

vector<Bar> sortBarVector(vector<Bar>& bares, char criterio_c) {
    criterio_c = tolower(criterio_c);

    switch (criterio_c) {
        case 'v':  // Ordenar por valoración descendente
            //Lambdas en C++ -> [](){}
            sort(bares.begin(), bares.end(),
                [](const Bar& a, const Bar& b) {return a.valoracion > b.valoracion;}
                );
            break;

        case 't':  // Ordenar por tiempo de visita
            sort(bares.begin(), bares.end(), [](const Bar& a, const Bar& b) {
                return (a.tiempoDesplazamiento*2 + a.tiempoConsumicion) <
                    (b.tiempoDesplazamiento*2 + b.tiempoConsumicion);
            });
            break;

        case 'r':  // Ordenar por ratio valoración/tiempoTotal
            sort(bares.begin(), bares.end(), [](const Bar& a, const Bar& b) {
                return (a.valoracion/(a.tiempoDesplazamiento*2 + a.tiempoConsumicion)) >
                    (b.valoracion/(b.tiempoDesplazamiento*2 + b.tiempoConsumicion));
            });
            break;

        default: cout << "Como has llegado aquí soldado?";

            break;
    }

    return bares;
}

#endif //RUTATAPAS_H
