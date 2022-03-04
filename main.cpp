#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"
#include "State.h"

int main() {
    int n = 0; 
    int m = 0;
    int nTurnos = 0;
    std::cout << "Indica el tamaño de la rejilla (NxM): ";
    std::cin >> n >> m;
    std::cout << std:: endl << "Indica el número de turnos: ";
    std::cin >> nTurnos;
    Grid rejilla1(n, m, nTurnos);
    rejilla1.visualizacion();

    std::cout << std::endl << "A continuación indica las posiciones de las células vivas (i,j)" << std::endl;
    std::cout << "Cuando desees finalizar escribe -1" << std::endl;
    while (n != -1 || m != -1) {
        cin << n << m;
        if(celulaViva(n, m)) {
            std::cout << "Ha habido un error, introduce valores correctos"
        } else {
            std::cout << "Subida. Correcta: (" << n << ", " << m << ")" << std::endl;
        }
    }
    std::cout << "Has finalizado el proceso de subida de células vivas..." << std::endl;
    rejilla1.nextGeneration();

    return 0;
}