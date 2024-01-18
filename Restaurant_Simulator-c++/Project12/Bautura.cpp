#include "Bautura.h"


Bautura::Bautura()
{
    // cout << "\nCONSTRUCTOR DEFAULT- CLASA BAUTURA";
}
Bautura::Bautura(const char* denumireBautura, float pretBautura, float areAlcool, Retetar retetaBautura)
{
    //cout << "\nCONSTRUCTOR CU TOTI PARAM- CLASA BAUTURA";
    this->retetaBautura = retetaBautura;
    if (denumireBautura != nullptr && strlen(denumireBautura) >= 3)
    {
        this->denumireBautura = new char[strlen(denumireBautura) + 1];
        strcpy(this->denumireBautura, denumireBautura);
    }
    else { cerr << "\nDenumire necorespunzatoare.";  this->denumireBautura = nullptr; }
    if (pretBautura > 5)
        this->pretBautura = pretBautura;
    else this->pretBautura = 0;
    this->areAlcool = areAlcool;
}
Bautura::Bautura(const char* denumireBautura, float pretBautura, Retetar retetaBautura)
{
    //constructor daca stim ca este o bautura simpla, fara alcool
   // cout << "\nCONSTRUCTOR CU 3 PARAM= CLASA BAUTURA";
    this->retetaBautura = retetaBautura;
    if (denumireBautura != nullptr && strlen(denumireBautura) >= 3)
    {
        this->denumireBautura = new char[strlen(denumireBautura) + 1];
        strcpy(this->denumireBautura, denumireBautura);
    }
    else { cerr << "\nDenumire necorespunzatoare.";  this->denumireBautura = nullptr; }
    if (pretBautura > 5)
        this->pretBautura = pretBautura;
    else this->pretBautura = 0;
}
Bautura::Bautura(const Bautura& b)
{
    // cout << "\nCONSTRUCTOR DE COPIERE- CLASA BAUTURA";
    this->retetaBautura = b.retetaBautura;
    if (b.denumireBautura != nullptr)
    {
        this->denumireBautura = new char[strlen(b.denumireBautura) + 1];
        strcpy(this->denumireBautura, b.denumireBautura);
    }
    else
        this->denumireBautura = nullptr;
    if (b.pretBautura > 5)
        this->pretBautura = b.pretBautura;
    else this->pretBautura = 0;
    this->areAlcool = b.areAlcool;
}
Bautura::~Bautura()
{
    // cout << "\nDESTRUCTOR- CLASA BAUTURA";
    delete[] this->denumireBautura;
    this->denumireBautura = nullptr;
}
Bautura& Bautura::operator=(const Bautura& b)
{
    // cout << "\nOP =";
    if (this != &b)
    {
        this->retetaBautura = b.retetaBautura;
        if (b.denumireBautura != nullptr) {
            delete[] this->denumireBautura;
            this->denumireBautura = nullptr;
            this->denumireBautura = new char[strlen(b.denumireBautura) + 1];
            strcpy(this->denumireBautura, b.denumireBautura);
        }
        else
            this->denumireBautura = nullptr;
        if (b.pretBautura > 5)
            this->pretBautura = b.pretBautura;
        else this->pretBautura = 0;
        this->areAlcool = b.areAlcool;
    }
    else
    {
        exception* pEx = new exception("Eroare autoasignare");
        cerr << "\n" << pEx->what();
        throw* pEx;
    }
    return *this;
}
void Bautura::afisareBautura()
{
    cout << "\n-------------METODA-AFISARE-------------";
    cout << "\nDenumire bautura: " << this->denumireBautura;
    cout << "\nPret bautura: " << this->pretBautura;
    cout << "\nAre alcool: ";
    if (this->areAlcool == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\nReteta preparat: "; this->retetaBautura.afisareRetetar();
    cout << "\n-------------------------------------";
}
const char* Bautura::getDenumireBautura()
{
    return this->denumireBautura;
}
void Bautura::setDenumireBautura(const char* denumireBautura)
{
    if (denumireBautura == nullptr || strlen(denumireBautura) < 3)
        return;

    if (this->denumireBautura != nullptr)
        delete[] this->denumireBautura;

    this->denumireBautura = new char[strlen(denumireBautura) + 1];
    strcpy(this->denumireBautura, denumireBautura);
}
float Bautura::getPretBautura()
{
    return this->pretBautura;
}
void Bautura::setPretBautura(float pretBautura)
{
    if (pretBautura >= 3)
        this->pretBautura = pretBautura;
}
bool Bautura::getAreAlcool()
{
    return this->areAlcool;
}
void Bautura::setAreAlcool(bool bauturaAlcool)
{
    if (bauturaAlcool != false)
        this->areAlcool = bauturaAlcool;
}
ostream& operator <<(ostream& out, const Bautura& b)
{
    out << "\n----------OSTREAM-----------------";
    out << "\nDenumire bautura: " << b.denumireBautura;
    out << "\nPret bautura: " << b.pretBautura;
    out << "\nAre alcool: ";
    if (b.areAlcool == true)
        out << "Da";
    else
        out << "Nu";
    out << "\nReteta preparat: " << b.retetaBautura << endl;
    out << "\n-------------------------------------";
    return out;
}
const Retetar& Bautura::getRetetaBautura()
{
    return this->retetaBautura;
}
void Bautura::setRetetaBautura(const Retetar& retetaBautura)
{
    this->retetaBautura = retetaBautura;
}
istream& operator>>(istream& in, Bautura& b)
{
    delete[] b.denumireBautura;
    b.denumireBautura = nullptr;

    bool exit = false;
    char buffer[50];
    do
    {
        cout << "\nIntroduceti denumirea bauturii: ";
        in.getline(buffer, sizeof(buffer));
        if (strlen(buffer) >= 3)
        {
            b.denumireBautura = new char[strlen(buffer) + 1];
            strcpy(b.denumireBautura, buffer);
            exit = true;

        }
        else
        {
            cerr << "\nDenumirea este mai mica decat 3. Reintroduceti." << endl;
        }

    } while (exit == false);

    exit = false;
    do {
        cout << "\nIntroduceti pret bautura: ";
        if (in >> b.pretBautura && b.pretBautura >= 5) {
            exit = true;
        }
        else {
            cerr << "\nPretul este prea mic sau introducerea nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    char citire;
    do {
        cout << "\nAre alcool (0-NU, 1-DA): ";
        in >> citire;
        if (isdigit(citire))
            b.areAlcool = citire - '0';
        else
            cerr << "\nValoarea introdusa nu este o corespunzatoare. Reintroduceti." << endl;
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    in >> b.retetaBautura;

    return in;
}
void Bautura::durataPregatireBautura()
{
    cout << "\nBautura " << this->denumireBautura << " se poate gati in " << this->retetaBautura.getDurataPreparare() << " minute.";
}
ofstream& operator<<(ofstream& out, const Bautura& b) {
    if (b.denumireBautura != nullptr)
        out << b.denumireBautura;
    out << ",";
    out << b.pretBautura;
    out << ",";
    out << b.areAlcool;
    out << "\n";
    return out;
}
void  Bautura::descriereBautura()
{
    retetaBautura.descriereReteta();
}
bool  Bautura::valabilitateBautura()
{
    return retetaBautura.valabilitateRetetar();
}
bool  Bautura::disponibilitateBautura() {
    return retetaBautura.disponibilitateRetetar();
}
void Bautura::scadeStocBautura()
{
    retetaBautura.scadeStocReteta();
}
