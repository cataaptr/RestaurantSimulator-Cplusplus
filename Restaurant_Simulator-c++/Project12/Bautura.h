#pragma once
#include <iostream>
#include <fstream>
#include "Retetar.h"

class Bautura  {
    char* denumireBautura = nullptr;
    float pretBautura = 0;
    bool areAlcool = 0;
    Retetar retetaBautura;

public:
    Bautura();
    Bautura(const char* denumireBautura, float pretBautura, float areAlcool, Retetar retetaBautura);
    Bautura(const char* denumireBautura, float pretBautura, Retetar retetaBautura);
    Bautura(const Bautura& b);
    ~Bautura();
    Bautura& operator=(const Bautura& b);
    void afisareBautura();
    const char* getDenumireBautura();
    void setDenumireBautura(const char* denumireBautura);
    float getPretBautura();
    void setPretBautura(float pretBautura);
    bool getAreAlcool();
    void setAreAlcool(bool bauturaAlcool);
    friend ostream& operator <<(ostream& out, const Bautura& b);
    const Retetar& getRetetaBautura();
    void setRetetaBautura(const Retetar& retetaBautura);
    friend istream& operator>>(istream& in, Bautura& b);
    void durataPregatireBautura();
    friend ofstream& operator<<(ofstream& out, const Bautura& b);
    void descriereBautura();
    bool valabilitateBautura();
    bool  disponibilitateBautura();
    void scadeStocBautura();
   // void saveToFile(fstream& file);
   // void restoreFromFile(fstream& file);
};