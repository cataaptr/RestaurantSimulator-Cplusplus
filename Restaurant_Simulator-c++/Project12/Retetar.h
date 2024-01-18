#pragma once
#include <iostream>
#include<vector>
#include "MateriePrima.h"


class Retetar : IFile{ //se considera reteta pt o portie
    int nrIngrediente = 0;
    MateriePrima** listaIngrediente = nullptr;
    float* gramaje = nullptr;
    int durataPreparare = 0; //se considera pe minute
    float cantitateZahar = 0;
    int nrCalorii = 0;
public:
    Retetar();
    Retetar(int nrIngrediente, MateriePrima** listaIngrediente, float* gramaje, int durataPreparare, float cantitateZahar, int nrCalorii);
    Retetar(int nrIngrediente, MateriePrima** listaIngrediente, float* gramaje);
    Retetar(const Retetar& r);
    Retetar& operator=(const Retetar& r);
    ~Retetar();
    void afisareRetetar();
    friend ostream& operator <<(ostream& out, const Retetar& r);
    int getDurataPreparare();
    void setDurataPreparare(int durataPreparare);
    float getCantitateZahar();
    void setCantitateZahar(float cantitateZahar);
    int getNrCalorii();
    void setNrCalorii(int nrCalorii);
    int getNrIngrediente();
    MateriePrima** getListaIngrediente();
    void setListaIngrediente(const MateriePrima** listaIngrediente, int nrIngrediente);
    const float* getGramaje();
    void setGramaje(const float* gramaje);
    friend istream& operator>>(istream& in, Retetar& r);
    void gramajTotal();
    void adaugaIngredient(MateriePrima m, float gramaj);
    void stergeIngredient(int pozitie);
    void descriereReteta();
    float& operator[](int pozitie);
    bool valabilitateRetetar();
    bool disponibilitateRetetar();
    void scadeStocReteta();
    void saveToFile(fstream& file);
    void restoreFromFile(fstream& file);
};