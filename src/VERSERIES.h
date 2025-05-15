#ifndef VERSERIES_H
#define VERSERIES_H

#include <algorithm>
#include <locale>
#include <vector>
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

struct Serie {
    char nombre[50];
    int capitulos;
    int duracion;
    int valoracion;
    int genero;
};

struct Capitulo {
    char nombre_serie[50];
    int numero;
    int duracion;
    int valoracion;
    Serie serie;
};

vector<Capitulo> sort(vector<Capitulo> capitulos, char criterio) {
    criterio = tolower(criterio);
    switch (criterio) {
    case 'v':
        sort(capitulos.begin(), capitulos.end(), [](const Capitulo& a, const Capitulo& b) {
            return a.valoracion > b.valoracion;
        });
        break;
    case 'd':
        sort(capitulos.begin(), capitulos.end(), [](const Capitulo& a, const Capitulo& b) {
            return (a.duracion < b.duracion);
        });
        break;
    case 'r':
        sort(capitulos.begin(), capitulos.end(), [](const Capitulo& a, const Capitulo& b) {
            return (double)(a.valoracion / a.duracion) > (double)(b.valoracion / b.duracion);
        });
        break;
    default:
        break;
    }
    return capitulos;
}

vector<Serie> agruparPorSerie(const vector<Capitulo>& cap) {
    vector<Serie> seriesSeleccionadas;
    for (Capitulo c : cap) {
        bool encontrada = false;
        for (Serie& s : seriesSeleccionadas) {
            if (strcmp(c.nombre_serie, s.nombre) == 0) {
                s.capitulos += 1;
                s.valoracion += c.valoracion;
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            Serie nueva;
            snprintf(nueva.nombre, sizeof(nueva.nombre), "%s", c.nombre_serie);
            nueva.capitulos = 1;
            nueva.valoracion = c.valoracion;
            nueva.genero = c.serie.genero;
            nueva.duracion = c.duracion;
            seriesSeleccionadas.push_back(nueva);
        }
    }
    return seriesSeleccionadas;
}

vector<Serie> maratonseries_capitulos(vector<Serie> series, int tiempoDisponible, char estrategia) {
    vector<Capitulo> capitulos;
    Capitulo aux;

    for (Serie s : series) {
        for (int j = 0; j < s.capitulos; j++) {
            snprintf(aux.nombre_serie, sizeof(aux.nombre_serie), "%s", s.nombre);
            aux.numero = j;
            aux.duracion = s.duracion;
            aux.valoracion = s.valoracion;
            aux.serie = s;
            capitulos.push_back(aux);
        }
    }

    capitulos = sort(capitulos, estrategia);
    int tiempoRestante = tiempoDisponible;
    vector<Capitulo> capitulosSeleccionados;

    for (Capitulo c : capitulos) {
        if (tiempoRestante >= c.duracion) {
            capitulosSeleccionados.push_back(c);
            tiempoRestante -= c.duracion;
        }
    }
    vector<Serie> seriesSeleccionadas = agruparPorSerie(capitulosSeleccionados);
    return seriesSeleccionadas;
}

void imprimirResultado(const vector<Serie>& seleccionadas, int tiempoDisponible, char estr) {
    int tiempoEmpleado = 0;
    int totalCapitulos = 0;
    int valoracionTotal = 0;
    int tiempoT = tiempoDisponible;

    switch (estr) {
        case 'v': cout << "\nEstrategia 1\n*******************************************\n";
            break;

        case 'd': cout << "\nEstrategia 2\n*******************************************\n";
            break;

        case 'r': cout << "\nEstrategia 3\n*******************************************\n";
            break;

        default: cout << "Como has llegado aquí soldado?";
            break;
    }

    cout << "Series seleccionadas:\n";
    for (const Serie& s : seleccionadas) {
        cout << "- " << s.nombre << " | Capitulos vistos: " << s.capitulos << endl;
        tiempoEmpleado += s.capitulos * s.duracion;
        valoracionTotal += s.valoracion;
        totalCapitulos += s.capitulos;
    }

    cout << "\nValoracion total conseguida: " << valoracionTotal/totalCapitulos;
    cout << "\nTiempo total empleado: " << tiempoEmpleado << " minutos";
    cout << "\nTiempo  RESTANTE: " << tiempoT - tiempoEmpleado << " minutos";
    cout << "\nNumero total de capitulos vistos: " << totalCapitulos << endl;
    cout << "\n\n";
}

#endif // VERSERIES_H
