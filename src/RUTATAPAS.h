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


vector<Bar> RUTATAPAS(vector<Bar> bares, int tiempoDisponible, char estrategia) {
        // Ordenar bares según valoracion
        sortBarVector(bares, estrategia);

        int tiempoRestante = tiempoDisponible;
        vector<Bar> baresSeleccionados;

        for (const Bar& bar : bares) {
                // Tiempo total = ida + vuelta + consumicion
                int tiempoNecesario = (2*bar.tiempoDesplazamiento) + bar.tiempoConsumicion;

                if (tiempoRestante >= tiempoNecesario) {
                        baresSeleccionados.push_back(bar);
                        tiempoRestante -= tiempoNecesario;
                }
        }

        return baresSeleccionados;
}

void imprimirVectorOrdenado(vector<Bar> baresOrdenados, char estr, int tiempoT) {

        int tiempoEmpleado = 0;
        int tiempoIndividual = 0;
        double rating = 0.0;

        switch (estr) {
                case 'v': cout << "\nEstrategia 1\n*******************************************\n";
                        break;

                case 't': cout << "\nEstrategia 2\n*******************************************\n";
                        break;

                case 'r': cout << "\nEstrategia 3\n*******************************************\n";
                        break;

                default: cout << "Como has llegado aquí soldado?";
                        break;
        }


        cout<< "BARES {";
        for (Bar b : baresOrdenados) {
                tiempoIndividual = (2*b.tiempoDesplazamiento) + b.tiempoConsumicion;
                tiempoEmpleado += tiempoIndividual;
                rating += b.valoracion;

                cout << "\n\tNombre: " << b.nombre
                     << "\n\t\tValoracion individual: " << b.valoracion
                     << "\n\t\tTiempo individual: " << tiempoIndividual ;

        }

        cout << "\n\n\tValoracion total conseguida: " << rating/baresOrdenados.size();
        cout << "\n\tTiempo restante: " << tiempoT-tiempoEmpleado;
        cout<< "\n}\n\n";
}


#endif //RUTATAPAS_H
