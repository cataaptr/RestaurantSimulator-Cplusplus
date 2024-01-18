#include"Preparat.h"
#include <fstream>

Preparat::Preparat() :ID_preparat(Preparat::contor_ID_preparat++)
{
    //cout << "\nCONSTRUCTOR DEFAULT- CLASA PREPARAT";
}
Preparat::Preparat(Retetar retetaPreparat, const char* denumirePreparat, float pretPreparat, int gradPicant, bool estePizza, TipPizza tipPizza, bool esteStarter, bool estePasta_risotto, bool esteMainCourse) : ID_preparat(Preparat::contor_ID_preparat++)
{
    //cout << "\nCONSTRUCTOR CU TOTI PARAM- CLASA PREPARAT";
    this->retetaPreparat = retetaPreparat;
    if (denumirePreparat != nullptr)
    {
        this->denumirePreparat = new char[strlen(denumirePreparat) + 1];
        strcpy(this->denumirePreparat, denumirePreparat);
    }
    else { cerr << "\nDenumire necorespunzatoare."; denumirePreparat = nullptr; }
    if (pretPreparat >= 5)
        this->pretPreparat = pretPreparat;
    else { cerr << "\nPretul introdus este prea mic."; this->pretPreparat = 0; }
    if (gradPicant <= 5 && gradPicant >= 0)
        this->gradPicant = gradPicant;
    else { cerr << "\nValorea trebuie sa fie in intervalul 0-5."; this->gradPicant = 0; }
    this->estePizza = estePizza;
    this->tipPizza = tipPizza;
    this->esteStarter = esteStarter;
    this->estePasta_risotto = estePasta_risotto;
    this->esteMainCourse = esteMainCourse;

}
Preparat::Preparat(Retetar retetaPreparat, const char* denumirePreparat, float pretPreparat, int gradPicant, bool estePasta_risotto) :ID_preparat(Preparat::contor_ID_preparat++)
{
    //constrcutor daca vrem sa facem paste mai usor
    //cout << "\nCONSTRUCTOR CU TREI PARAM- CLASA PREPARAT";
    this->retetaPreparat = retetaPreparat;
    if (denumirePreparat != nullptr)
    {
        this->denumirePreparat = new char[strlen(denumirePreparat) + 1];
        strcpy(this->denumirePreparat, denumirePreparat);
    }
    else { cerr << "\nDenumire necorespunzatoare."; denumirePreparat = nullptr; }
    if (pretPreparat >= 5)
        this->pretPreparat = pretPreparat;
    else { cerr << "\nPretul introdus este prea mic."; this->pretPreparat = 0; }
    if (gradPicant <= 5 && gradPicant >= 0)
        this->gradPicant = gradPicant;
    else { cerr << "\nValorea trebuie sa fie in intervalul 0-5."; this->gradPicant = 0; }
    this->estePasta_risotto = estePasta_risotto;
}
Preparat::Preparat(Retetar retetaPreparat, const char* denumirePreparat, float pretPreparat, int gradPicant, bool estePizza, TipPizza tipPizza) :ID_preparat(Preparat::contor_ID_preparat++)
{
    //constrcutor daca vrem sa facem pizza mai usor
    //cout << "\nCONSTRUCTOR CU TREI PARAM- CLASA PREPARAT";
    this->retetaPreparat = retetaPreparat;
    if (denumirePreparat != nullptr)
    {
        this->denumirePreparat = new char[strlen(denumirePreparat) + 1];
        strcpy(this->denumirePreparat, denumirePreparat);
    }
    else { cerr << "\nDenumire necorespunzatoare."; denumirePreparat = nullptr; }
    if (pretPreparat >= 5)
        this->pretPreparat = pretPreparat;
    else { cerr << "\nPretul introdus este prea mic."; this->pretPreparat = 0; }
    if (gradPicant <= 5 && gradPicant >= 0)
        this->gradPicant = gradPicant;
    else { cerr << "\nValorea trebuie sa fie in intervalul 0-5."; this->gradPicant = 0; }
    this->estePizza = estePizza;
    this->tipPizza = tipPizza;
}
Preparat::Preparat(const Preparat& p) :ID_preparat(Preparat::contor_ID_preparat++)
{
    //cout << "\nCONSTRUCTOR DE COPIERE- CLASA PREPARAT";
    this->retetaPreparat = p.retetaPreparat;
    if (p.denumirePreparat != nullptr)
    {
        this->denumirePreparat = new char[strlen(p.denumirePreparat) + 1];
        strcpy(this->denumirePreparat, p.denumirePreparat);
    }
    else
        denumirePreparat = nullptr;
    if (p.pretPreparat >= 5)
        this->pretPreparat = p.pretPreparat;
    else
        this->pretPreparat = 0;
    if (p.gradPicant <= 5 && p.gradPicant >= 0)
        this->gradPicant = p.gradPicant;
    else
        this->gradPicant = 0;
    this->estePizza = p.estePizza;
    this->tipPizza = p.tipPizza;
    this->esteStarter = p.esteStarter;
    this->estePasta_risotto = p.estePasta_risotto;
    this->esteMainCourse = p.esteMainCourse;
}
Preparat::~Preparat()
{
    //cout << "\nDESTRUCTOR- CLASA PREPARAT";
    delete[] this->denumirePreparat;
    this->denumirePreparat = nullptr;

}
const char* Preparat::getDenumirePreparat()
{
    return this->denumirePreparat;
}
void  Preparat::setDenumirePreparat(const char* denumirePreparat)
{
    if (denumirePreparat == nullptr || strlen(denumirePreparat) < 5)
        return;

    if (this->denumirePreparat != nullptr)
        delete[] this->denumirePreparat;

    this->denumirePreparat = new char[strlen(denumirePreparat) + 1];
    strcpy(this->denumirePreparat, denumirePreparat);
}
float  Preparat::getPretPreparat()
{
    return this->pretPreparat;
}
void  Preparat::setPretPreparat(float pretPreparat)
{
    if (pretPreparat >= 5)
        this->pretPreparat = pretPreparat;
}
int  Preparat::getGradPicant()
{
    return this->gradPicant;
}
void  Preparat::setGradPicant(int gradPicant)
{
    if (gradPicant <= 5 && gradPicant >= 0)
        this->gradPicant = gradPicant;
}
bool  Preparat::getEsteStarter()
{
    return this->esteStarter;
}
void  Preparat::setEsteStarter(bool esteStarter)
{
    if (esteStarter == true)
        this->esteStarter = esteStarter;
}
bool  Preparat::getEstePasta_risotto()
{
    return this->estePasta_risotto;
}
void  Preparat::setEstePasta_risotto(bool estePasta_risotto)
{
    if (estePasta_risotto == true)
        this->estePasta_risotto = estePasta_risotto;
}
bool  Preparat::getEsteMainCourse()
{
    return this->esteMainCourse;
}
void  Preparat::setEsteMainCourse(bool esteMainCourse)
{
    if (esteMainCourse == true)
        this->esteMainCourse = esteMainCourse;
}
bool  Preparat::getEstePizza()
{
    return this->estePizza;
}
void  Preparat::setEstePizza(bool estePizza)
{
    if (estePizza == true)
        this->estePizza = estePizza;
}
TipPizza  Preparat::getTipPizza()
{
    return this->tipPizza;
}
void  Preparat::setTipPizza(TipPizza tipPizza)
{
    if (estePizza != false)
        this->tipPizza = tipPizza;
}
void  Preparat::afisarePreparat()
{
    cout << "\n-------------METODA-AFISARE-PREPARAT------------";
    if (this->denumirePreparat != nullptr)
        cout << "\nDenumire preparat: " << this->denumirePreparat;
    else
        cout << "\nDenumire preparat: -";
    cout << "\nID_preparat: " << this->ID_preparat;
    cout << "\nPret preparat: " << this->pretPreparat;
    cout << "\nGrad picant: " << this->gradPicant;
    cout << "\nEste starter: ";
    if (this->esteStarter == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\nEste pasta/risotto: ";
    if (this->estePasta_risotto == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\nEste Main Course: ";
    if (this->esteMainCourse == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\nEste pizza: ";
    if (this->estePizza == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\nTip pizza: ";
    if (this->estePizza != false)
    {
        switch (this->tipPizza)
        {
        case 10: cout << "Mica"; break;
        case 20:cout << "Medie"; break;
        case 30:cout << "Mare"; break;
        }
    }
    else
        cout << "-";
    cout << "\nReteta preparat: "; this->retetaPreparat.afisareRetetar();
    cout << "\n------------------------------------";
}
Preparat& Preparat::operator=(const Preparat& p)
{
    //cout << "\nOP =";
    if (this != &p)
    {
        this->retetaPreparat = p.retetaPreparat;
        if (p.denumirePreparat != nullptr) {
            delete[] this->denumirePreparat;
            this->denumirePreparat = nullptr;
            this->denumirePreparat = new char[strlen(p.denumirePreparat) + 1];
            strcpy(this->denumirePreparat, p.denumirePreparat);
        }
        else
            this->denumirePreparat = nullptr;
        if (p.pretPreparat >= 5)
            this->pretPreparat = p.pretPreparat;
        else this->pretPreparat = 0;
        if (p.gradPicant <= 5 && p.gradPicant >= 0)
            this->gradPicant = p.gradPicant;
        else this->gradPicant = 0;
        this->estePizza = p.estePizza;
        this->tipPizza = p.tipPizza;
        this->esteStarter = p.esteStarter;
        this->estePasta_risotto = p.estePasta_risotto;
        this->esteMainCourse = p.esteMainCourse;
    }
    else
    {
        exception* pEx = new exception("Eroare autoasignare");
        cerr << "\n" << pEx->what();
        throw* pEx;
    }
    return *this;
}
ostream& operator <<(ostream& out, const Preparat& p)
{
    out << "\n----------------OUT-PREPARAT---------------";
    if (p.denumirePreparat != nullptr)
        out << "\nDenumire preparat: " << p.denumirePreparat;
    else
        out << "\nDenumire preparat: -";
    out << "\nID_preparat: " << p.ID_preparat;
    out << "\nPret preparat: " << p.pretPreparat;
    out << "\nGrad picant: " << p.gradPicant;
    out << "\nEste starter: ";
    if (p.esteStarter == true)
        out << "Da";
    else
        out << "Nu";
    out << "\nEste pasta/risotto: ";
    if (p.estePasta_risotto == true)
        out << "Da";
    else
        out << "Nu";
    out << "\nEste Main Course: ";
    if (p.esteMainCourse == true)
        out << "Da";
    else
        out << "Nu";
    out << "\nEste pizza: ";
    if (p.estePizza == true)
        out << "Da";
    else
        out << "Nu";
    out << "\nTip pizza: ";
    if (p.estePizza != false)
    {
        switch (p.tipPizza)
        {
        case 10:out << "Mica"; break;
        case 20:out << "Medie"; break;
        case 30:out << "Mare"; break;
        }
    }
    else
        out << "-";
    out << "\nReteta preparat: " << p.retetaPreparat << endl;
    out << "\n-----------------------------------";
    return out;
}
istream& operator>>(istream& in, Preparat& p) {

    if (p.denumirePreparat != nullptr)
    {
        delete[] p.denumirePreparat;
        p.denumirePreparat = nullptr;
    }

    bool exit = false;
    char buffer[50];
    do
    {
        cout << "\nIntroduceti denumirea preparatului: ";
        in.getline(buffer, sizeof(buffer));
        if (strlen(buffer) >= 5)
        {
            p.denumirePreparat = new char[strlen(buffer) + 1];
            strcpy(p.denumirePreparat, buffer);
            exit = true;

        }
        else
        {
            cerr << "\nDenumirea este mai mica decat 5. Reintroduceti." << endl;
        }

    } while (exit == false);


    int idGenerat = Preparat::generare_ID_preparat();
    const_cast<int&>(p.ID_preparat) = idGenerat;

    exit = false;
    do {
        cout << "\nIntroduceti pret preparat: ";
        if (in >> p.pretPreparat && p.pretPreparat >= 5) {
            exit = true;
        }
        else {
            cerr << "\nPretul este prea mic sau introducerea nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    exit = false;
    do {
        cout << "\nIntroduceti gradul de picant pentru preparat (0-5): ";
        if (in >> p.gradPicant && p.gradPicant >= 0 && p.gradPicant <= 5) {
            exit = true;
        }
        else {
            cerr << "\nValorea introdusa nu corespunde intervalului. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    char citire;

    do {
        cout << "\nEste pizza (0-NU,1-DA): ";
        in >> citire;
        if (isdigit(citire))
            p.estePizza = citire - '0';
        else
            cerr << "\nValoarea introdusa nu este o corespunzatoare. Reintroduceti." << endl;
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    do {
        cout << "\nEste starter (0-NU,1-DA): ";
        in >> citire;
        if (isdigit(citire))
            p.esteStarter = citire - '0';
        else
            cerr << "\nValoarea introdusa nu este o corespunzatoare. Reintroduceti." << endl;
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    do {
        cout << "\nEste pasta/risotto (0-NU,1-DA): ";
        in >> citire;
        if (isdigit(citire))
            p.estePasta_risotto = citire - '0';
        else
            cerr << "\nValoarea introdusa nu este o corespunzatoare. Reintroduceti." << endl;
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    do {
        cout << "\nEste Main Course (0-NU,1-DA): ";
        in >> citire;
        if (isdigit(citire))
            p.esteMainCourse = citire - '0';
        else
            cerr << "\nValoarea introdusa nu este o corespunzatoare. Reintroduceti." << endl;
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    int citire1;
    if (p.estePizza == true)
    {
        do {
            cout << "\nTip pizza (10-MICA, 20-MEDiE, 30-MARE): ";
            in >> citire1;
            if (citire1 == 10 || citire1 == 20 || citire1 == 30)
            {
                switch (citire1)
                {
                case 10: p.tipPizza = TipPizza::MICA; break;
                case 20: p.tipPizza = TipPizza::MEDIE; break;
                case 30: p.tipPizza = TipPizza::MARE; break;
                };
            }
            else
            {
                cerr << "\nValoarea introdus nu este corecta. Reintroduceti.";
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');

            }
        } while (citire1 != 10 && citire1 != 20 && citire1 != 30);
    }

    in >> p.retetaPreparat;

    return in;
}
int  Preparat::generare_ID_preparat() {
    return Preparat::contor_ID_preparat++;
}
const Retetar  Preparat::getRetetaPreparat()
{
    return this->retetaPreparat;
}
void  Preparat::setRetetaPreparat(const Retetar& retetaPreparat)
{
    this->retetaPreparat = retetaPreparat;
}
void  Preparat::durataPregatirePreparat()
{
    cout << "\nPreparatul " << this->denumirePreparat << " se poate gati in " << this->retetaPreparat.getDurataPreparare() << " minute.";
}
void  Preparat::descrierePreparat()
{
    retetaPreparat.descriereReteta();
}
void  Preparat::gramajPreparat()
{
    retetaPreparat.gramajTotal();
}
bool  Preparat::operator>(const Preparat& p) {
    if (this->pretPreparat > 0 && p.pretPreparat > 0) {
        return this->pretPreparat > p.pretPreparat;
    }
    else {
        throw new exception("Unele obiecte nu au preturi valide pentru comparatie");
    }
}
Preparat::operator string() {
    return string(this->denumirePreparat);
}
bool  Preparat::operator==(const Preparat& p) const {

    return this->ID_preparat == p.ID_preparat;
}
bool  Preparat::valabilitatePreparat()
{
    return retetaPreparat.valabilitateRetetar();
}
bool  Preparat::disponibilitatePreparat() {
    return retetaPreparat.disponibilitateRetetar();
}
ofstream& operator<<(ofstream& out, const Preparat& p) {
    if (p.denumirePreparat != nullptr)
        out << p.denumirePreparat;
    out << ",";
    out << p.pretPreparat;
    out << ",";
    out << p.gradPicant;
    out << ",";
    out << p.estePizza;
    out << ",";
    out << p.tipPizza;
    out << ",";
    out << p.esteStarter;
    out << ",";
    out << p.estePasta_risotto;
    out << ",";
    out << p.esteMainCourse;
    out << "\n";
    return out;
}

void Preparat::scadeStocPreparat()
{
    retetaPreparat.scadeStocReteta();
}

int Preparat::contor_ID_preparat = 0;
