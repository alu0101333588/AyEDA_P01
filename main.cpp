#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"
#include "State.h"

int main() {
    unsigned int n = 0, m = 0;
    unsigned int nTurnos = 0;
    std::cout << "Indica el tamaño de la rejilla (FilasxColumnas)(NxM): ";
    std::cin >> n >> m; // Filas x Columnas (m filas. n columnas)
    std::cout << "Indica el número de turnos: ";
    std::cin >> nTurnos;
    Grid rejilla1(n, m, nTurnos);
    rejilla1.visualizacion();
    int i = 0, j = 0; // i Filas, j Columnas

    std::cout << "A continuación indica las posiciones de las células vivas (i,j)" << std::endl;
    std::cout << "****(Cuando desees finalizar escribe -1)****" << std::endl;
    while (i != -1) {
        std::cout << "Introduce (i,j): ";
        std::cin >> i;
        if (i != -1){
            std::cin >> j;
        }  
        if(i != -1 && rejilla1.celulaViva(i, j)) {
            std::cout << "Ha habido un error, introduce valores correctos. ";
        } else if (i != -1) {
            std::cout << "Subida. Correcta: (" << i << ", " << j << ")" << std::endl;
        }
    }
    std::cout << std::endl << "Has finalizado el proceso de subida de células vivas..." << std::endl << std::endl;
    rejilla1.nextGeneration(rejilla1);

    return 0;
}