#pragma once
#include "Preparat.h"
#include "Bautura.h"
#include <conio.h>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <list>


class Comanda {
    int nrPreparateComanda = 0;
    int* nrBucatiPreparat = nullptr;
    Preparat* listaPreparateComanda = nullptr;
    int nrBauturiComanda = 0;
    int* nrBucatiBautura = nullptr;
    Bautura* listaBauturiComanda = nullptr;
public:
    Comanda();
    Comanda(int nrPreparateComanda, int* nrBucatiPreparat, Preparat* listaPreparateComanda, int nrBauturiComanda, int* nrBucatiBautura, Bautura* listaBauturiComanda);
    Comanda(const Comanda& c);
    Comanda& operator=(const Comanda& c);
    ~Comanda();
    const Preparat* getListaPreparateComanda();
    const Bautura* getListaBauturiComanda();
    void setListaPreparateComanda(const Preparat* listaPreparateComanda, const int* nrBucatiPreparat, int nrPreparateComanda);
    void setListaBauturiComanda(const Bautura* listaBauturiComanda, const int* nrBucatiBautura, int nrBauturiComanda);
    const int* getNrBucatiPreparat();
    const int* getNrBucatiBautura();
    friend ostream& operator <<(ostream& out, const Comanda& c);
    friend istream& operator>>(istream& in, Comanda& c);
    int nrTotalProduseComanda();
    float pretTotalComanda();
    void adaugaPreparatComanda(Preparat p);
    void stergePreparatComanda(int pozitie);
    void adaugaBauturaComanda(Bautura b);
    void stergeBauturaComanda(int pozitie);
    void afisareComanda();
    bool valabilitateComandaPreparat();
    bool disponibilitateComandaPreparat();
    bool valabilitateComandaBautura();
    bool disponibilitateComandaBautura();
    void ruleazaComandaPreparat(vector<Preparat>& v, int* optiune2);
    void ruleazaComandaStarters(vector<Preparat>& v, int* optiune2);
    void ruleazaComandaMainCourse(vector<Preparat>& v, int* optiune2);
    void ruleazaComandaPaste_Risotto(vector<Preparat>& v, int* optiune2);
    void ruleazaComandaPizza(vector<Preparat>& v, int* optiune2);
    void ruleazaComandaBautura(vector<Bautura>& v, int* optiune2);
    void afisareIntrebari(map<string, string>& intrebRasp);
    void creareIntrebariMain(map<string, string>& intrebRasp, map<string, int>& frecventaIntrebari);
    void ruleazaIntrebari(map<string, string>& intrebRasp, map<string, int>& frecventaIntrebari);
    void creareIntrebariFisier(map<string,string>& intrebRasp, map<string, int>& frecventaIntrebari);
    void salveazaIntrebariFisier(map<string, string>& intrebRasp, map<std::string, int>& frecventaIntrebari);
    void raportFrecventaIntrebari(map<string, string>& intrebRasp, map<std::string, int>& frecventaIntrebari);
    void adaugaComandaFisier(const string& fileName,float pretTotatal);
    void raportCifraDeAfaceri();
    void conversieBinar(const string& fileName1, const string& fileName2);
};