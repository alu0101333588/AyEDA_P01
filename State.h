#ifndef STATE_H
#define STATE_H
#include <fstream>
#include <iostream>
#include <string>

class State {
    public:
        int getState1(){ return estado_; }
        void setState(int estado){estado_ = estado;} 
        void setMuerta() {estado_ = 0;}
        void setViva() {estado_ = 1;}

    private:
        int estado_; // 0 si está muerta, 1 si está viva

};

#endif