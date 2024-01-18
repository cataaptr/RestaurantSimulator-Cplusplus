#pragma once
#include <regex>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <iostream>
#include "IFile.h"

#pragma warning(disable : 4996)
using namespace std;
const int lungimeMax = 20;

class MateriePrima :IFile {
    static int contor_ID_materiePrima;
    const int ID_materiePrima;
    char* denumireMateriePrima = nullptr;
    float stoc = 0; //considerat pe buc/kg/litru 
    string dataExpirare = "ZZ-LL-AAAA";
    bool necesitateRefrigerare = false;
    bool bautura = false;

public:
    MateriePrima();
    MateriePrima(const char* denumireMateriePrima, float stoc, string dataExpirare, bool necisitateRefrigerare, bool bautura);
    MateriePrima(const char* denumireMateriePrima, float stoc, string dataExpirare);
    MateriePrima(const MateriePrima& m);
    ~MateriePrima();
    const char* getDenumireMateriePrima();
    void setDenumire(const char* denumireMateriePrima);
    bool getRefrigerare();
    void setRefrigerare(bool necesitateRefrigerare);
    bool getBautura();
    void setBautura(bool bautura);
    float getStoc();
    void setStoc(float stoc);
    string getDataExpirare();
    void setDataExpirare(string dataExpirare);
    const int getIdMateriePrima();
    void afisareMateriePrima();
    MateriePrima& operator=(const MateriePrima& m);
    friend ostream& operator<<(ostream& out, const MateriePrima& m);
    friend istream& operator>>(istream& in, MateriePrima& m);
    static int generare_ID_materiePrima();
    bool disponibilitateStoc();
    bool valabiliateMateriePrima();
    MateriePrima& operator++();
    MateriePrima operator++(int);
    MateriePrima operator+(int stocSuplimentar);
    MateriePrima& operator+=(int stocSuplimentar);
    bool operator!();
    friend ofstream& operator<<(ofstream& out, const MateriePrima& m);
    friend ifstream& operator>>(ifstream& in, MateriePrima& m);
    void stergereMateriePrimaVector(const string& denumireStergere, vector<MateriePrima>& v);
    void adaugaMateriePrimaVector(vector<MateriePrima>& v);
    void scadeStoc(float gramaj);
    void saveToFile(fstream& file);
    void restoreFromFile(fstream& file);
};
