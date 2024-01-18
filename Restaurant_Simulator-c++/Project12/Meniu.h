#pragma once
#include "Preparat.h"
#include "Bautura.h"
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>

class Meniu {
    int nrPreparate = 0;
    Preparat* listaPreparate = nullptr;
    int nrBauturi = 0;
    Bautura* listaBauturi = nullptr;
public:
    Meniu();
    Meniu(int nrPreparate, Preparat* listaPreparate, int nrBauturi, Bautura* listaBauturi);
    Meniu(int nrPreparate, Preparat* listaPreparate);
    ~Meniu();
    Meniu(const Meniu& m);
    Meniu& operator=(const Meniu& m);
    int getNrPreparate();
    const Preparat* getListaPreparate();
    int getNrBauturi();
    const Bautura* getListaBauturi();
    void setListaPreparate(const Preparat* listaPreparat, int nrPreparate);
    void setListaBauturi(const Bautura* listaBauturi, int nrBauturi);
    friend istream& operator>>(istream& in, Meniu& m);
    friend ostream& operator <<(ostream& out, const Meniu& m);
    void afisareMesajMeniu();
    void afisareMeniuPreparate();
    void afisareMeniuStarters();
    void afisareMeniuMainCourse();
    void afisareMeniuPaste_Risotto();
    void afisareMeniuPizza();
    void adaugaPreparat(Preparat p);
    void stergePreparat(int pozitie);
    void adaugaBautura(Bautura b);
    void stergeBautura(int pozitie);
    void afisareMeniuBauturi();
    void creareMeniuPreparat(fstream& file, Retetar reteteP[]);
    void creareMeniuBauturi(fstream& file, Retetar reteteB[]);
    void rulareMeniu(int* optiune);
    void continuare(int* cont);
};