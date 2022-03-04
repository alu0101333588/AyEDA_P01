#ifndef GRID_H
#define GRID_H
#include <fstream>
#include <iostream>
#include "Cell.h"

class Cell;
class Grid {
    public:
        Grid(int n, int m, int turnos); // Constructor 
        const Cell& getCell(int i, int j) const;
        void nextGeneration(Grid& rejilla1);
        bool celulaViva(int i, int j); // Marcar como viva la célula ubicada en la posición (i, j)
                                        // Si sale true entonces ha tenido lugar un error
        void visualizacion();


    private:
        Cell** rejilla_;
        int nTurnos_;
        int n_; // Dimensiones NxM de la rejilla
        int m_;

};

#endif