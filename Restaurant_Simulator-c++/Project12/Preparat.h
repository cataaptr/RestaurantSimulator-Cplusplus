#pragma once
#include <iostream>
#include <sstream>
#include "Retetar.h"
#include "IFile.h"

enum TipPizza { MICA = 10, MEDIE = 20, MARE = 30 };


class Preparat { 
    char* denumirePreparat = nullptr;
    const int ID_preparat;
    static int contor_ID_preparat;
    float pretPreparat = 0;
    int gradPicant = 0;
    bool estePizza = false;
    TipPizza tipPizza = TipPizza::MICA;
    bool esteStarter = false;
    bool estePasta_risotto = false;
    bool esteMainCourse = false;
    Retetar retetaPreparat;

public:
    Preparat();
    Preparat(Retetar retetaPreparat, const char* denumirePreparat, float pretPreparat, int gradPicant, bool estePizza, TipPizza tipPizza, bool esteStarter, bool estePasta_risotto, bool esteMainCourse);
    Preparat(Retetar retetaPreparat, const char* denumirePreparat, float pretPreparat, int gradPicant, bool estePasta_risotto);
    Preparat(Retetar retetaPreparat, const char* denumirePreparat, float pretPreparat, int gradPicant, bool estePizza, TipPizza tipPizza);
    Preparat(const Preparat& p);
    ~Preparat();
    const char* getDenumirePreparat();
    void setDenumirePreparat(const char* denumirePreparat);
    float getPretPreparat();
    void setPretPreparat(float pretPreparat);
    int getGradPicant();
    void setGradPicant(int gradPicant);
    bool getEsteStarter();
    void setEsteStarter(bool esteStarter);
    bool getEstePasta_risotto();
    void setEstePasta_risotto(bool estePasta_risotto);
    bool getEsteMainCourse();
    void setEsteMainCourse(bool esteMainCourse);
    bool getEstePizza();
    void setEstePizza(bool estePizza);
    TipPizza getTipPizza();
    void setTipPizza(TipPizza tipPizza);
    void afisarePreparat();
    Preparat& operator=(const Preparat& p);
    friend ostream& operator <<(ostream& out, const Preparat& p);
    friend istream& operator>>(istream& in, Preparat& p);
    static int generare_ID_preparat();
    const Retetar getRetetaPreparat();
    void setRetetaPreparat(const Retetar& retetaPreparat);
    void durataPregatirePreparat();
    void descrierePreparat();
    void gramajPreparat();
    bool operator>(const Preparat& p);
    operator string();
    bool operator==(const Preparat& p) const;
    bool valabilitatePreparat();
    bool disponibilitatePreparat();
    friend ofstream& operator<<(ofstream& out, const Preparat& p);
    void scadeStocPreparat();
  
};
