#ifndef CELL_H
#define CELL_H
#include <fstream>
#include <iostream>
#include "State.h"


class Cell {
    public:
        Cell(); // Constructor
        State getState() const {return estado_;} // Devuelve el estado actual
        State setState(State estado1) {estado_ = estado1;} // Reemplazar el estado actual
        State setNextState(State estado1) {estadoFuturo_ = estado1;}
        void updateState(); // Actualiza el estado
        int neighbors(const Grid& rejilla1); // Devuelve el número de células vecinas vivas
        void setposicion(int i, int j); {i_ = i; j_ = j;}

        ostream& operator<<(ostream& os, const Cell &celula1);

    private:
        State estado_; // Estado actual
        State estadoFuturo_; // Estado al que debe cambiar 
        int i_; // Posición i que ocupa la célula
        int j_; // Posición j que ocupa la célula

}