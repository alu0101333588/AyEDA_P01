#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"
#include "State.h"



Grid::Grid(int n, int m, int turnos) {
    nTurnos_ = turnos;
    rejilla_ = new Cell*[n+2];
    n_ = n+2;
    m_ = m+2;
    for (int i = 0; i < n+2; i++) {
        rejilla_[i] = new Cell[m+2];
    }

    for (int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            //rejilla_[i][j].Cell(); // marcar inicialmente todas las células como muertas
            //rejilla_[i][j].setposicion(i, j);
        }
    }
}

bool Grid::celulaViva(int i, int j) {
    std::cout << "PRUEBA. Célula viva" << std::endl;
    if (i+2 >= n_ || j+2 >= m_ || i < 0 || j < 0) {
        return true; // Manifestamos un error
    }
    State estado1;
    estado1.setViva();
    rejilla_[i+2][j+2].setState(estado1);
    return false;
}

void Grid::nextGeneration(Grid& rejilla1){
    //State estado1;
    //estado1.setMuerta();
    //estado1.setViva();
    //rejilla_[i][j].setNextState(estado1);
    std::cout << "TURNO 0: " << std::endl;
    for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
        for (int j = 1; j < m_-1; j++) {
            std::cout << rejilla_[i][j];
        } 
        std::cout << std::endl;
    }

    for (int i = 0; i < n_-2; i++){
        std::cout << "__";
    }

    int turn = 1;
    while (turn != nTurnos_) {

        for (int i = 1; i < n_-1; i++) { // Se aplican las condiciones
            for (int j = 1; j < m_-1; j++) {
               
                State estado3 = rejilla_[i][j].getState();
                //std::cout << estado2.getState1() << " "; 
                if (estado3.getState1() == 0) {
                    if (rejilla_[i][j].neighbors(rejilla1) == 3) {
                        State estado4;
                        estado4.setViva();
                        rejilla_[i][j].setNextState(estado4);
                    }
                }

                if (estado3.getState1() == 1) {
                    if (rejilla_[i][j].neighbors(rejilla1) != 2 || rejilla_[i][j].neighbors(rejilla1) != 3) {
                        State estado4;
                        estado4.setViva();
                        rejilla_[i][j].setNextState(estado4);
                    }
                }
            } 
        }

        for (int i = 1; i < n_-1; i++) { // Se actualiza el estado de las células
            for (int j = 1; j < m_-1; j++) {
                rejilla_[i][j].updateState(); 
            } 
        }

        std::cout << "TURNO " << turn << ":" << std::endl;

        for (int i = 0; i < n_-2; i++){ // Leyenda números parte superior
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
            for (int j = 1; j < m_-1; j++) {
                std::cout << rejilla_[i][j];
                //State estado2 = rejilla_[i][j].getState();
                //std::cout << estado2.getState1() << " ";
            } 
            std::cout << std::endl;
        }
        for (int i = 0; i < n_-2; i++){
            std::cout << "__";
        }
        turn++;
    }
}

void Grid::visualizacion() {
    for (int i = 0; i < n_-2; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n_-2; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < m_-2; j++) {
        std::cout << j << std::endl;
    }
    for (int i = 0; i < n_-2; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
        
}


const Cell& Grid::getCell(int i, int j) const {
    return rejilla_[i][j];
}