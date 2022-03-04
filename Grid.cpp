#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"
#include "State.h"


Grid::Grid(int n, int m, int turnos) {
    nTurnos_ = turnos;
    rejilla_ = new Cell* [n+2];
    n_ = n+2;
    m_ = m+2;
    for (int i = 0; i < n+2; i++) {
        rejilla_[i] = new Cell*[m+2];
    }

    for (int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            rejilla_[i][j].Cell(); // marcar inicialmente todas las células como muertas
            rejilla_[i][j].setposicion(i, j);
        }
    }
}

bool Grid::celulaViva(int i, int j) {
    std::cout << "PRUEBA. Célula viva" << std::endl;
    if (i+2 >= n | j+2 >= m | i < 0 | j < 0) {
        return true; // Manifestamos un error
    }
    State estado1;
    estado1.setViva();
    rejilla_[i+2][j+2].setState(estado1);
    return false;
}

const Cell& Grid::getCell(int, int) const;
void Grid::nextGeneration(){
    State estado1;
    estado1.setMuerta();
    estado1.setViva();
    rejilla_[i][j].setNextState(estado1);
    int turn = nTurnos_;
    while (turn != 0) {

        for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
            for (int j = 1; j < m_-1; j++) {
                State estado2 = rejilla_[i][j].getState();
                std::cout << estado2.getState1() << " ";
            } 
            std::cout << std::endl;
        }

        for (int i = 1; i < n_-1; i++) { // Se actualiza el estado de las células
            for (int j = 1; j < m_-1; j++) {
                rejilla_[i][j].updateState(); 
            } 
        }

        for (int i = 0; i < n_-2; i++){ // Leyenda números parte superior
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
            for (int j = 1; j < m_-1; j++) {
                State estado2 = rejilla_[i][j].getState();
                std::cout << estado2.getState1() << " ";
            } 
            std::cout << std::endl;
        }
    }

   

    
}

void visualizacion() {
    for (int i = 0; i < n_-2; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < m_-2; j++) {
        std::cout << j << std::endl;
    }
        
}