#include <fstream>
#include <iostream>
#include <string>
#include "Cell.h"

void Cell::updateState(){
    estado_ = estadoFuturo_;
}

int Cell::neighbors(const Grid& rejilla1) { // Indica el número de células vecinas vivas
    int contador = 0;
    for (int i = i_-1; i < i_+2; i++){
        for (int j = j_-1; j_ < j_+2; j_++){
            State estado2 = rejilla1.rejilla_[i][j].getState();
            if (estado2.getState1() == 1) {
                contador++;
            }
            
        }
    }
    
}

ostream& operator<<(ostream& os, const Cell &celula1) {
    if (estado_.getState1() == 1) {
        os << "X";
    } else {
        os << " ";
    }
}

Cell::Cell (){
    estado_.setMuerta(); // Se marca como muerta inicialmente
    estadoFuturo_.setMuerta(); // Se marca como muerta inicialmente
}
