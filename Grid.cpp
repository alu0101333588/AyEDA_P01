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
            rejilla_[i][j].setposicion(i, j);
        }
    }
}

bool Grid::celulaViva(int i, int j) {
    if (i+1 >= n_-1 || j+1 >= m_-1 || i < 0 || j < 0) {
        return true; // Manifestamos un error
    }
    State estado1;
    estado1.setViva();
    rejilla_[i+1][j+1].setState(estado1);
    return false;
}

void Grid::nextGeneration(Grid& rejilla1){

    std::cout << "TURNO 0: " << std::endl << "  ";
    for (int i = 0; i < m_-2; i++){ // Leyenda números parte superior
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
        std::cout << i-1 << " ";
        for (int j = 1; j < m_-1; j++) {
            std::cout << rejilla_[i][j] << " ";
        } 
        std::cout << std::endl;
    }

    for (int i = 0; i < m_-2; i++){
        std::cout << "__";
    }
    std::cout << std::endl;

    int turn = 0;
    while (turn != nTurnos_) {
        turn++;
        for (int i = 1; i < n_-1; i++) { // Se aplican las condiciones
            for (int j = 1; j < m_-1; j++) {
                State estado3 = rejilla_[i][j].getState();
                if (estado3.getState1() == 0) {
                    if (rejilla_[i][j].neighbors(rejilla1) == 3) {
                        State estado4;
                        estado4.setViva();
                        rejilla_[i][j].setNextState(estado4);
                    } else {
                        State estado4;
                        estado4.setMuerta();
                        rejilla_[i][j].setNextState(estado4);
                    }
                }

                if (estado3.getState1() == 1) {
                    if (rejilla_[i][j].neighbors(rejilla1) == 2 || rejilla_[i][j].neighbors(rejilla1) == 3) {
                        State estado4;
                        estado4.setViva();
                        rejilla_[i][j].setNextState(estado4);
                    } else {
                        State estado4;
                        estado4.setMuerta();
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

        std::cout << "TURNO " << turn << ":" << std::endl << "  ";

        for (int i = 0; i < m_-2; i++){ // Leyenda números parte superior
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for (int i = 1; i < n_-1; i++) { // Se imprimen por pantalla las células
            std::cout << i-1 << " ";
            for (int j = 1; j < m_-1; j++) {
                std::cout << rejilla_[i][j] << " ";
            } 
            std::cout << std::endl;
        }
        for (int i = 0; i < m_-2; i++){
            std::cout << "__";
        }
        std::cout << std::endl;
    }
}

void Grid::visualizacion() {

    // n_ Filas
    // m_ Columnas

    std::cout << "INFORME: n" << n_ << ". m" << m_ << " :: " << n_-2 << " : " << m_-2 << std::endl; 
    for (int i = 0; i < m_-2; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m_-2; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < n_-2; j++) {
        std::cout << j << std::endl;
    }
    for (int i = 0; i < m_-2; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
        
}


const Cell& Grid::getCell(int i, int j) const {
    return rejilla_[i][j];
}