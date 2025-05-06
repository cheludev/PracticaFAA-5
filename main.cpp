#include <algorithm>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

#include "RUTATAPAS.h";

int tiempoT = 180;

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

void imprimirVectorOrdenado(vector<Bar> baresOrdenados, char estr) {

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
                imprimirVectorOrdenado(estrategia1, 'v');

                vector<Bar> estrategia2 = RUTATAPAS(bares, tiempoT, 't');
                imprimirVectorOrdenado(estrategia2,'t');

                vector<Bar> estrategia3 = RUTATAPAS(bares, tiempoT, 'r');
                imprimirVectorOrdenado(estrategia3, 'r');
        }



}
