#include "Comanda.h"

Comanda::Comanda()
{
    //cout << "\nCONSTRUCTOR FARA PARAM- CLASA COMANDA";
}
Comanda::Comanda(int nrPreparateComanda, int* nrBucatiPreparat, Preparat* listaPreparateComanda, int nrBauturiComanda, int* nrBucatiBautura, Bautura* listaBauturiComanda)
{
    // cout << "\nCONSTRUCTOR CU TOTI PARAM- CLASA COMANDA";
    if (nrPreparateComanda != 0 && listaPreparateComanda != nullptr && nrBucatiPreparat != nullptr)
    {
        this->nrPreparateComanda = nrPreparateComanda;
        this->listaPreparateComanda = new Preparat[this->nrPreparateComanda];
        this->nrBucatiPreparat = new int[this->nrPreparateComanda];
        for (int i = 0; i < this->nrPreparateComanda; i++) {
            this->listaPreparateComanda[i] = listaPreparateComanda[i];
            if (nrBucatiPreparat[i] > 0)
                this->nrBucatiPreparat[i] = nrBucatiPreparat[i];
        }
    }
    else { this->nrPreparateComanda = 0; this->listaPreparateComanda = nullptr; this->nrBucatiPreparat = nullptr; }

    if (nrBauturiComanda != 0 && listaBauturiComanda != nullptr && nrBucatiBautura != nullptr)
    {
        this->nrBauturiComanda = nrBauturiComanda;
        this->listaBauturiComanda = new Bautura[this->nrBauturiComanda];
        this->nrBucatiBautura = new int[this->nrBauturiComanda];
        for (int i = 0; i < this->nrBauturiComanda; i++) {
            this->listaBauturiComanda[i] = listaBauturiComanda[i];
            if (nrBucatiBautura[i] > 0)
                this->nrBucatiBautura[i] = nrBucatiBautura[i];
        }
    }
    else { this->nrBauturiComanda = 0; this->listaBauturiComanda = nullptr; this->nrBucatiBautura = nullptr; }
}
Comanda::Comanda(const Comanda& c)
{
    // cout << "\nCONSTRUCTOR DE COPIERE- CLASA COMANDA";
    if (c.nrPreparateComanda != 0 && c.listaPreparateComanda != nullptr && c.nrBucatiPreparat != nullptr)
    {
        this->nrPreparateComanda = c.nrPreparateComanda;
        this->listaPreparateComanda = new Preparat[this->nrPreparateComanda];
        this->nrBucatiPreparat = new int[this->nrPreparateComanda];
        for (int i = 0; i < this->nrPreparateComanda; i++) {
            this->listaPreparateComanda[i] = c.listaPreparateComanda[i];
            if (c.nrBucatiPreparat[i] > 0)
                this->nrBucatiPreparat[i] = c.nrBucatiPreparat[i];
        }
    }
    else
    {
        this->listaPreparateComanda = nullptr;
        this->nrBucatiPreparat = nullptr;
        this->nrPreparateComanda = 0;
    }
    if (c.nrBauturiComanda != 0 && c.listaBauturiComanda != nullptr && c.nrBucatiBautura != nullptr)
    {
        this->nrBauturiComanda = c.nrBauturiComanda;
        this->listaBauturiComanda = new Bautura[this->nrBauturiComanda];
        this->nrBucatiBautura = new int[this->nrBauturiComanda];
        for (int i = 0; i < this->nrBauturiComanda; i++) {
            this->listaBauturiComanda[i] = c.listaBauturiComanda[i];
            if (c.nrBucatiBautura[i] > 0)
                this->nrBucatiBautura[i] = c.nrBucatiBautura[i];
        }
    }
    else {
        this->nrBauturiComanda = 0; this->listaBauturiComanda = nullptr; this->nrBucatiBautura = nullptr;
    }

}
Comanda& Comanda::operator=(const Comanda& c)
{
    if (this != &c)
    {
        delete[] this->listaPreparateComanda;
        delete[] this->nrBucatiPreparat;

        this->listaPreparateComanda = nullptr;
        this->nrBucatiPreparat = nullptr;

        delete[] this->listaBauturiComanda;
        delete[] this->nrBucatiBautura;

        this->listaBauturiComanda = nullptr;
        this->nrBucatiBautura = nullptr;

        if (c.nrPreparateComanda > 0 && c.listaPreparateComanda != nullptr && c.nrBucatiPreparat != nullptr)
        {
            this->nrPreparateComanda = c.nrPreparateComanda;
            this->listaPreparateComanda = new Preparat[this->nrPreparateComanda];
            this->nrBucatiPreparat = new int[this->nrPreparateComanda];
            for (int i = 0; i < this->nrPreparateComanda; i++)
            {
                this->listaPreparateComanda[i] = c.listaPreparateComanda[i];
                if (c.nrBucatiPreparat[i] > 0)
                    this->nrBucatiPreparat[i] = c.nrBucatiPreparat[i];
            }
        }
        else

        {
            this->listaPreparateComanda = nullptr;
            this->nrBucatiPreparat = nullptr;
            this->nrPreparateComanda = 0;
        }
        if (c.nrBauturiComanda != 0 && c.listaBauturiComanda != nullptr && c.nrBucatiBautura != nullptr)
        {
            this->nrBauturiComanda = c.nrBauturiComanda;
            this->listaBauturiComanda = new Bautura[this->nrBauturiComanda];
            this->nrBucatiBautura = new int[this->nrBauturiComanda];
            for (int i = 0; i < this->nrBauturiComanda; i++) {
                this->listaBauturiComanda[i] = c.listaBauturiComanda[i];
                if (c.nrBucatiBautura[i] > 0)
                    this->nrBucatiBautura[i] = c.nrBucatiBautura[i];
            }
        }
        else {
            this->nrBauturiComanda = 0; this->listaBauturiComanda = nullptr; this->nrBucatiBautura = nullptr;
        }

    }
    else
    {
        exception* pEx = new exception("Eroare autoasignare");
        cerr << "\n" << pEx->what();
        throw* pEx;
    }
    return *this;
}
Comanda::~Comanda() {
    // cout << "\nDESTRCUTOR- CLASA COMANDA";
    delete[] this->listaPreparateComanda;
    this->listaPreparateComanda = nullptr;
    delete[] this->nrBucatiPreparat;
    this->nrBucatiPreparat = nullptr;

    delete[] this->listaBauturiComanda;
    this->listaBauturiComanda = nullptr;
    delete[] this->nrBucatiBautura;
    this->nrBucatiBautura = nullptr;

}
const Preparat* Comanda::getListaPreparateComanda()
{
    return this->listaPreparateComanda;
}
const Bautura* Comanda::getListaBauturiComanda()
{
    return this->listaBauturiComanda;
}
void Comanda::setListaPreparateComanda(const Preparat* listaPreparateComanda, const int* nrBucatiPreparat, int nrPreparateComanda)
{
    for (int i = 0; i < this->nrPreparateComanda; i++)
    {
        this->listaPreparateComanda[i].~Preparat();
    }
    delete[] this->listaPreparateComanda;
    delete[] this->nrBucatiPreparat;
    this->listaPreparateComanda = nullptr;
    this->nrBucatiPreparat = nullptr;

    if (nrPreparateComanda > 0 && listaPreparateComanda != nullptr && nrBucatiPreparat != nullptr)
    {
        this->nrPreparateComanda = nrPreparateComanda;


        this->listaPreparateComanda = new Preparat[this->nrPreparateComanda];
        this->nrBucatiPreparat = new int[this->nrPreparateComanda];

        for (int i = 0; i < this->nrPreparateComanda; i++)
        {
            this->listaPreparateComanda[i] = listaPreparateComanda[i];
            this->nrBucatiPreparat[i] = nrBucatiPreparat[i];
        }
    }
    else
    {
        this->nrPreparateComanda = 0;
        this->listaPreparateComanda = nullptr;
        this->nrBucatiPreparat = nullptr;
    }
}
void Comanda::setListaBauturiComanda(const Bautura* listaBauturiComanda, const int* nrBucatiBautura, int nrBauturiComanda)
{
    for (int i = 0; i < this->nrBauturiComanda; i++)
    {
        this->listaBauturiComanda[i].~Bautura();
    }
    delete[] this->listaBauturiComanda;
    delete[] this->nrBucatiBautura;
    this->listaBauturiComanda = nullptr;
    this->nrBucatiBautura = nullptr;

    if (nrBauturiComanda > 0 && listaBauturiComanda != nullptr && nrBucatiBautura != nullptr)
    {
        this->nrBauturiComanda = nrBauturiComanda;


        this->listaBauturiComanda = new Bautura[this->nrBauturiComanda];
        this->nrBucatiBautura = new int[this->nrBauturiComanda];

        for (int i = 0; i < this->nrBauturiComanda; i++)
        {
            this->listaBauturiComanda[i] = listaBauturiComanda[i];
            this->nrBucatiBautura[i] = nrBucatiBautura[i];
        }
    }
    else
    {
        this->nrBauturiComanda = 0;
        this->listaBauturiComanda = nullptr;
        this->nrBucatiBautura = nullptr;
    }
}
const int* Comanda::getNrBucatiPreparat() {
    return this->nrBucatiPreparat;
}
const int* Comanda::getNrBucatiBautura() {
    return this->nrBucatiBautura;
}
ostream& operator <<(ostream& out, const Comanda& c)
{
    out << "\n----------------OUT-COMANDA---------------";
    out << "\nLista preparate: ";
    if (c.nrPreparateComanda > 0)
    {
        for (int i = 0; i < c.nrPreparateComanda; i++) {
            out << endl << c.listaPreparateComanda[i] << " - Bucati: " << c.nrBucatiPreparat[i];
        }
    }
    else
        out << "-";
    out << "\nLista bauturi: ";
    if (c.nrBauturiComanda > 0)
    {
        for (int i = 0; i < c.nrBauturiComanda; i++) {
            out << endl << c.listaBauturiComanda[i] << " - Bucati: " << c.nrBucatiBautura[i];
        }
    }
    else
        out << "-";
    out << "\n-----------------------------------";

    return out;
}
istream& operator>>(istream& in, Comanda& c)
{
    if (c.listaPreparateComanda != nullptr)
    {
        delete[] c.listaPreparateComanda;
        c.listaPreparateComanda = nullptr;
    }

    if (c.nrBucatiPreparat != nullptr)
    {
        delete[] c.nrBucatiPreparat;
        c.nrBucatiPreparat = nullptr;
    }

    if (c.listaBauturiComanda != nullptr)
    {
        delete[] c.listaBauturiComanda;
        c.listaBauturiComanda = nullptr;
    }

    if (c.nrBucatiBautura != nullptr)
    {
        delete[] c.nrBucatiBautura;
        c.nrBucatiBautura = nullptr;
    }

    bool exit = false;
    do {
        cout << "\nIntroduceti nr preparate: ";
        if (in >> c.nrPreparateComanda && c.nrPreparateComanda > 0) {
            exit = true;
        }
        else {
            cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!exit);

    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    exit = false;
    do {
        if (c.nrPreparateComanda > 0) {

            c.listaPreparateComanda = new Preparat[c.nrPreparateComanda];
            c.nrBucatiPreparat = new int[c.nrPreparateComanda];

            for (int i = 0; i < c.nrPreparateComanda; ++i) {
                cout << "\nIntroduceti detalii pentru preparatul " << i + 1 << ":" << endl;
                in >> c.listaPreparateComanda[i];
                bool bucValid = false;
                do {
                    cout << "\nIntroduceti numarul de bucati pentru preparatul " << i + 1 << ": ";
                    if (in >> c.nrBucatiPreparat[i] && c.nrBucatiPreparat[i] > 0) {
                        bucValid = true;
                    }
                    else {
                        cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
                        in.clear();
                        in.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!bucValid);
            }
            exit = true;
        }
        else {
            cerr << "\nNu se poate face comanda preparatului, pentru ca numarul de preparate este zero. " << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!exit);

    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    exit = false;
    do {
        cout << "\nIntroduceti nr bauturi: ";
        if (in >> c.nrBauturiComanda && c.nrBauturiComanda > 0) {
            exit = true;
        }
        else {
            cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!exit);

    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    exit = false;
    do {
        if (c.nrBauturiComanda > 0) {

            c.listaBauturiComanda = new Bautura[c.nrBauturiComanda];
            c.nrBucatiBautura = new int[c.nrBauturiComanda];

            for (int i = 0; i < c.nrBauturiComanda; ++i) {
                cout << "\nIntroduceti detalii pentru bautura " << i + 1 << ":" << endl;
                in >> c.listaPreparateComanda[i];
                bool bucValid = false;
                do {
                    cout << "\nIntroduceti numarul de bucati pentru bautura " << i + 1 << ": ";
                    if (in >> c.nrBucatiBautura[i] && c.nrBucatiBautura[i] > 0) {
                        bucValid = true;
                    }
                    else {
                        cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
                        in.clear();
                        in.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!bucValid);
            }
            exit = true;
        }
        else {
            cerr << "\nNu se poate face comanda bauturii, pentru ca numarul de bauturi este zero. " << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!exit);

    return in;
}
int Comanda::nrTotalProduseComanda() {
    int totalProduse = 0;
    if (this->nrBucatiPreparat != nullptr) {
        for (int i = 0; i < this->nrPreparateComanda; i++) {
            totalProduse += this->nrBucatiPreparat[i];
        }
    }
    if (this->nrBucatiBautura != nullptr) {
        for (int i = 0; i < this->nrBauturiComanda; i++) {
            totalProduse += this->nrBucatiBautura[i];
        }
    }

    return totalProduse;
}
float Comanda::pretTotalComanda()
{
    float pretTotal = 0;

    if (this->listaPreparateComanda != nullptr && this->nrPreparateComanda > 0 && this->nrBucatiPreparat != nullptr)
    {
        for (int i = 0; i < this->nrPreparateComanda; i++)
        {
            if (this->listaPreparateComanda != nullptr)
                pretTotal = pretTotal + this->listaPreparateComanda[i].getPretPreparat() * this->nrBucatiPreparat[i];
        }
    }
    if (this->listaBauturiComanda != nullptr && this->nrBauturiComanda > 0 && this->nrBucatiBautura != nullptr)
    {
        for (int i = 0; i < this->nrBauturiComanda; i++)
        {
            if (this->listaBauturiComanda != nullptr)
                pretTotal = pretTotal + this->listaBauturiComanda[i].getPretBautura() * this->nrBucatiBautura[i];
        }
    }

    return pretTotal;
}
void Comanda::adaugaPreparatComanda(Preparat p)
{
    for (int i = 0; i < this->nrPreparateComanda; i++) {
        if (strcmp(p.getDenumirePreparat(), this->listaPreparateComanda[i].getDenumirePreparat()) == 0) {
            this->nrBucatiPreparat[i]++;
            // cout << "Preparatul " << p.getDenumirePreparat() << " exista deja in comanda. Numarul de bucati a fost incrementat." << endl;
            return;
        }
    }

    if (!this->listaPreparateComanda) {
        this->listaPreparateComanda = new Preparat[1];
        this->nrBucatiPreparat = new int[1];
        this->nrPreparateComanda = 0;
    }
    this->nrPreparateComanda++;

    Preparat* nou = new Preparat[this->nrPreparateComanda];
    int* noiBucati = new int[this->nrPreparateComanda];

    for (int i = 0; i < this->nrPreparateComanda - 1; i++) {
        nou[i] = this->listaPreparateComanda[i];
        noiBucati[i] = this->nrBucatiPreparat[i];
    }

    nou[this->nrPreparateComanda - 1] = p;
    noiBucati[this->nrPreparateComanda - 1] = 1;

    delete[] this->listaPreparateComanda;
    delete[] this->nrBucatiPreparat;

    this->listaPreparateComanda = nou;
    this->nrBucatiPreparat = noiBucati;
    cout << "\nPRODUS ADAUGAT CU SUCCES";
}
void Comanda::stergePreparatComanda(int pozitie)
{
    if (pozitie < 0 || pozitie >= this->nrPreparateComanda)
    {
        cerr << "Pozitie invalida." << endl;
        return;
    }

    for (int i = pozitie; i < this->nrPreparateComanda - 1; i++)
    {
        this->listaPreparateComanda[i] = this->listaPreparateComanda[i + 1];
        this->nrBucatiPreparat[i] = this->nrBucatiPreparat[i + 1];
    }

    this->nrPreparateComanda--;
}
void Comanda::adaugaBauturaComanda(Bautura b)
{
    for (int i = 0; i < this->nrBauturiComanda; i++) {
        if (strcmp(b.getDenumireBautura(), this->listaBauturiComanda[i].getDenumireBautura()) == 0) {
            this->nrBucatiBautura[i]++;
            //cout << "Bautura " << b.getDenumireBautura() << " exista deja in comanda. Numarul de bucati a fost incrementat." << endl;
            return;
        }
    }

    if (!this->listaBauturiComanda) {
        this->listaBauturiComanda = new Bautura[1];
        this->nrBucatiBautura = new int[1];
        this->nrBauturiComanda = 0;
    }
    this->nrBauturiComanda++;

    Bautura* nou = new Bautura[this->nrBauturiComanda];
    int* noiBucati = new int[this->nrBauturiComanda];

    for (int i = 0; i < this->nrBauturiComanda - 1; i++) {
        nou[i] = this->listaBauturiComanda[i];
        noiBucati[i] = this->nrBucatiBautura[i];
    }

    nou[this->nrBauturiComanda - 1] = b;
    noiBucati[this->nrBauturiComanda - 1] = 1;

    delete[] this->listaBauturiComanda;
    delete[] this->nrBucatiBautura;

    this->listaBauturiComanda = nou;
    this->nrBucatiBautura = noiBucati;
}
void Comanda::stergeBauturaComanda(int pozitie)
{
    if (pozitie < 0 || pozitie >= this->nrBauturiComanda)
    {
        cerr << "Pozitie invalida." << endl;
        return;
    }

    for (int i = pozitie; i < this->nrBauturiComanda - 1; i++)
    {
        this->listaBauturiComanda[i] = this->listaBauturiComanda[i + 1];
        this->nrBucatiBautura[i] = this->nrBucatiBautura[i + 1];
    }

    this->nrBauturiComanda--;
}
void Comanda::afisareComanda()
{
    cout << "\n------------------------------------COMANDA--------------------------------------------";
    cout << "\n";
    cout << "\nComanda dumneavoastra contine: " << nrTotalProduseComanda() << " produse";

    int k = 0;
    for (int i = 0; i < this->nrPreparateComanda; i++)
    {
        cout << "\n               " << k + 1 << ". " << this->listaPreparateComanda[i].getDenumirePreparat();
        cout << "\n        Bucati: " << this->nrBucatiPreparat[i];
        cout << "\n        Pret (bucata) : " << this->listaPreparateComanda[i].getPretPreparat();
        cout << "\n        Pret TOTAL bucati : " << this->listaPreparateComanda[i].getPretPreparat() * this->nrBucatiPreparat[i] << endl;
        k++;
    }
    for (int i = 0; i < this->nrBauturiComanda; i++)
    {
        cout << "\n               " << k + 1 << ". " << this->listaBauturiComanda[i].getDenumireBautura();
        cout << "\n        Bucati: " << this->nrBucatiBautura[i];
        cout << "\n        Pret (bucata) : " << this->listaBauturiComanda[i].getPretBautura();
        cout << "\n        Pret TOTAL bucati : " << this->listaBauturiComanda[i].getPretBautura() * this->nrBucatiBautura[i] << endl;
        k++;
    }

    cout << "\n";
    cout << "\nPRET TOTAL COMANDA: " << pretTotalComanda() << " lei" << endl;
    cout << "\n----------------------------------------------------------------------------------------";
}
bool Comanda::valabilitateComandaPreparat()
{
    for (int i = 0; i < this->nrPreparateComanda; i++)
    {
        if (!this->listaPreparateComanda[i].valabilitatePreparat())
        {
            return false;
        }
    }


    return true;
}
bool Comanda::disponibilitateComandaPreparat()
{
    for (int i = 0; i < this->nrPreparateComanda; i++)
    {
        if (!this->listaPreparateComanda[i].disponibilitatePreparat())
        {
            return false;
        }
    }


    return true;
}
bool Comanda::valabilitateComandaBautura()
{
    for (int i = 0; i < this->nrBauturiComanda; i++)
    {
        if (!this->listaBauturiComanda[i].valabilitateBautura())
        {
            return false;
        }
    }


    return true;
}
bool Comanda::disponibilitateComandaBautura()
{
    for (int i = 0; i < this->nrBauturiComanda; i++)
    {
        if (!this->listaBauturiComanda[i].disponibilitateBautura())
        {
            return false;
        }
    }


    return true;
}
void Comanda::ruleazaComandaPreparat(vector<Preparat>& v, int* optiune2)
{
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout << c;
    } while (num < 0 || num > v.size());
    *optiune2 = num;
    if (*optiune2 != 0) {
        if (v[*optiune2 - 1].valabilitatePreparat() == false || v[*optiune2 - 1].disponibilitatePreparat() == false)
        {
            cout << "\nNu se poate adauga acest produs in comanda. Va sugeram sa incercati alt produs din selectia noastra. ";
        }
        else
        {
            adaugaPreparatComanda(v[*optiune2 - 1]);

            v[*optiune2 - 1].scadeStocPreparat();

        }
    }
}
void Comanda::ruleazaComandaBautura(vector<Bautura>& v, int* optiune2)
{
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout << c;
    } while (num < 0 || num > v.size());
    *optiune2 = num;
    if (*optiune2 != 0) {
        if (v[*optiune2 - 1].valabilitateBautura() == false || v[*optiune2 - 1].disponibilitateBautura() == false)
        {
            cout << "\nNu se poate adauga acest produs in comanda. Va sugeram sa incercati alt produs din selectia noastra. ";
        }
        else
        {
            adaugaBauturaComanda(v[*optiune2 - 1]);
            v[*optiune2 - 1].scadeStocBautura();

        }
    }
}
void Comanda::ruleazaComandaStarters(vector<Preparat>& v, int* optiune2)
{
    vector<Preparat> str;
    for (Preparat x : v)
    {
        if (x.getEsteStarter() == true)
        {
            str.push_back(x);
        }
    }
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout << c;
    } while (num < 0 || num > str.size());
    *optiune2 = num;
    if (*optiune2 != 0)
    {
        int i = 0;
        int pozitie = 0;
        string denumire = str[*optiune2 - 1].getDenumirePreparat();
        bool gasit = false;
        while (i < v.size() && gasit == false)
        {
            if (v[i].getDenumirePreparat() == denumire)
            {

                pozitie = i;
                gasit = true;
            }
            else
                i++;
        }

        if (v[pozitie].valabilitatePreparat() == false || v[pozitie].disponibilitatePreparat() == false)
        {
            cout << "\nNu se poate adauga acest produs in comanda. Va sugeram sa incercati alt produs din selectia noastra. ";
        }
        else
        {
            adaugaPreparatComanda(v[pozitie]);
            v[pozitie].scadeStocPreparat();

        }
    }
}


void Comanda::ruleazaComandaMainCourse(vector<Preparat>& v, int* optiune2)
{
    vector<Preparat> mainC;
    for (Preparat x : v)
    {
        if (x.getEsteMainCourse() == true)
        {
            mainC.push_back(x);
        }
    }
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout << c ;
    } while (num < 0 || num > mainC.size());
    *optiune2 = num;
    if (*optiune2 != 0)
    {
        int i = 0;
        int pozitie = 0;
        string denumire = mainC[*optiune2 - 1].getDenumirePreparat();
        bool gasit = false;
        while (i < v.size() && gasit == false)
        {
            if (v[i].getDenumirePreparat() == denumire)
            {

                pozitie = i;
                gasit = true;
            }
            else
                i++;
        }

        if (v[pozitie].valabilitatePreparat() == false || v[pozitie].disponibilitatePreparat() == false)
        {
            cout << "\nNu se poate adauga acest produs in comanda. Va sugeram sa incercati alt produs din selectia noastra. ";
        }
        else
        {
            adaugaPreparatComanda(v[pozitie]);
            v[pozitie].scadeStocPreparat();

        }
    }
}
void Comanda::ruleazaComandaPaste_Risotto(vector<Preparat>& v, int* optiune2)
{
    vector<Preparat> paste;
    for (Preparat x : v)
    {
        if (x.getEstePasta_risotto() == true)
        {
            paste.push_back(x);
        }
    }
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout <<  c ;
    } while (num < 0 || num > paste.size());
    *optiune2 = num;
    if (*optiune2 != 0)
    {
        int i = 0;
        int pozitie = 0;
        string denumire = paste[*optiune2 - 1].getDenumirePreparat();
        bool gasit = false;
        while (i < v.size() && gasit == false)
        {
            if (v[i].getDenumirePreparat() == denumire)
            {

                pozitie = i;
                gasit = true;
            }
            else
                i++;
        }

        if (v[pozitie].valabilitatePreparat() == false || v[pozitie].disponibilitatePreparat() == false)
        {
            cout << "\nNu se poate adauga acest produs in comanda. Va sugeram sa incercati alt produs din selectia noastra. ";
        }
        else
        {
            adaugaPreparatComanda(v[pozitie]);
            v[pozitie].scadeStocPreparat();

        }
    }
}
void Comanda::ruleazaComandaPizza(vector<Preparat>& v, int* optiune2)
{
    vector<Preparat> pizza;
    for (Preparat x : v)
    {
        if (x.getEstePizza() == true)
        {
            pizza.push_back(x);
        }
    }
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout << c ;
    } while (num < 0 || num > pizza.size());
    *optiune2 = num;
    if (*optiune2 != 0)
    {
        int i = 0;
        int pozitie = 0;
        string denumire = pizza[*optiune2 - 1].getDenumirePreparat();
        bool gasit = false;
        while (i < v.size() && gasit == false)
        {
            if (v[i].getDenumirePreparat() == denumire)
            {

                pozitie = i;
                gasit = true;
            }
            else
                i++;
        }

        if (v[pozitie].valabilitatePreparat() == false || v[pozitie].disponibilitatePreparat() == false)
        {
            cout << "\nNu se poate adauga acest produs in comanda. Va sugeram sa incercati alt produs din selectia noastra. ";
        }
        else
        {
            adaugaPreparatComanda(v[pozitie]);
            v[pozitie].scadeStocPreparat();

        }
    }
}
void Comanda::afisareIntrebari(map<string,string>& intrebRasp)
{
    int i = 1;
    cout << "\n------------------------------------INTREBARI--------------------------------------------\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    for (auto I : intrebRasp)
    {
        cout << "\n\t\t" << i << ". ";
        cout << I.first;
        i++;
    }
    cout << "\n-----------------------------------------------------------------------------------------\n";
}
/* void Comanda::creareIntrebariMain(map<string, string>& intrebRasp, map<string, int>& frecventaIntrebari)
{

    frecventaIntrebari["Care sunt orele de functionare ale restaurantului?"] = 0;
    frecventaIntrebari["Este necesara o rezervare prealabila? "] = 0;
    frecventaIntrebari["Cum pot face o rezervare?"] = 0;
    frecventaIntrebari["Ce metode de plata sunt acceptate?"] = 0;
    frecventaIntrebari["Cat dureaza livrarea?"] = 0;
    frecventaIntrebari["Detalii contact"] = 0;

    intrebRasp["Care sunt orele de functionare ale restaurantului?"] = "\n\tPROGRAM:\n\t\tLUNI-VINERI: 10:00-22:00\n\t\tSAMBATA-DUMINICA: 10:00-01:00";
    intrebRasp["Este necesara o rezervare prealabila ? "] = "\n\tRecomandam realizarea unei rezervari pentru a evita situatiile neplacute.";
    intrebRasp["Cum pot face o rezervare? "] = "\n\tRezervarile se realizeaza exclusiv telefon la numarul: (+40)-000-000-000";
    intrebRasp["Ce metode de plata sunt acceptate?"] = "\n\tMetodele de plata acceptate sunt: plata la livrare, plata cu cardul.";
    intrebRasp["Cat dureaza livrarea?"] = "\n\tLivrarea poate sa difere in functie locatia clientului, dar in medie: 40 min-o ora";
    intrebRasp["Detalii contact"] = "\n\tNumar telefon: (+40)-000-000-000\n\tLocatie: Strada Florilor, Numarul 9";

} */
void Comanda::ruleazaIntrebari(map<string, string>& intrebRasp, map<string, int>& frecventaIntrebari)
{
    char c; int num;
    do {
        cout << "\nIntroduceti numarul dorit: ";
        c = getch();
        num = c - '0';
        cout << c;
    } while (num < 0 || num > intrebRasp.size());
    if (num != 0)
    {
        auto it = intrebRasp.begin();
        advance(it, num - 1);

        string intrebare = it->first;
        string raspuns = it->second;

        cout << frecventaIntrebari[intrebare] << endl;
        frecventaIntrebari[intrebare]++;
        cout << frecventaIntrebari[intrebare] << endl;

        cout << "\nIntrebare: " << intrebare << "\nRaspuns: " << raspuns << endl;
    }

}

void Comanda::creareIntrebariFisier(map<string,string>& intrebRasp, map<string, int>& frecventaIntrebari) {
    ifstream file("Frecvente.txt");

    if (file.is_open()) {
        string linie;

        while (getline(file, linie)) {
            istringstream linieStream(linie);
            string intrebare, raspuns, frecventaStr;

            getline(linieStream, intrebare, ',');
            getline(linieStream, frecventaStr, ',');
            getline(linieStream, raspuns);

            if (!frecventaStr.empty()) {
                int frecventa = stoi(frecventaStr);
                frecventaIntrebari[intrebare] = frecventa;
                intrebRasp[intrebare] = raspuns;
            }
            else {
                cerr << "\nFrecventa nu poate fi convertita deoarece sirul este gol.";
            }
        }

        file.close();
    }
    else {
        cerr << "\nEroare la deschiderea fisierului Frecvente.txt";
    }
}
void Comanda::salveazaIntrebariFisier( map<string, string>& intrebRasp, map<string, int>& frecventaIntrebari)
{
    ofstream file("Frecvente.txt");

    if (file.is_open()) {
        for (const auto& pair : intrebRasp) {
            const string& intrebare = pair.first;
            const string& raspuns = pair.second;
            int frecventa = frecventaIntrebari.at(intrebare);

            file << intrebare << "," << frecventa << "," << raspuns << "\n";
        }

        file.close();
       // cout << "Intrebari si raspunsuri salvate cu succes in fisierul Frecvente.txt\n";
    }
    else {
        cerr << "\nEroare la deschiderea fisierului Frecvente.txt";
    }
}
void Comanda::raportFrecventaIntrebari(map<string, string>& intrebRasp, map<string, int>& frecventaIntrebari)
{
    ofstream file("RaportFrecvente.txt");

    int nrTotalAccesari = 0;
    float produs = 1;

    for (auto x : frecventaIntrebari)
    {
        nrTotalAccesari += x.second;
        produs *= x.second;
    }


    multimap<int, string> copie;

    for (auto it : frecventaIntrebari) {
        copie.insert({ it.second, it.first });
    }

    cout << "\n\n------------------------------------RAPORT-INTREBARI-FRECVENTE------------------------------------\n";
    cout << "\n\t*Numar intrebari: " << intrebRasp.size();
    cout << "\n\t*Numar accesari intrebari: " << nrTotalAccesari;
    float medieA = float(nrTotalAccesari) / intrebRasp.size();
    cout << "\n\t*Media aritmetica: " << medieA;
    int locMediana = (intrebRasp.size() + 1) / 2;
    float medieG = sqrt(produs);
    cout << "\n\t*Media geometrica: " << medieG;
    cout << "\n\t*Mediana ( cuantila de ordin 2) : ";
    int contor = 1;
    int mediana = 0;
    for (auto x : copie) {
        if (contor == locMediana)
        {
            cout << "Intrebarea: " << x.second << " ( " << x.first << " accesari ) ";
            mediana = x.first;
        }
        contor++;
    }
    cout << "\n\nTop trei intrebari cele mai accesate: ";
    contor = 0;
    for (auto x = copie.rbegin(); x != copie.rend(); x++)
    {

        if (contor < 3)
        {
            cout << "\n\t" << contor + 1 << ". ";
            cout << x->second << " ( ";
            if (x->first == 1)
                cout << x->first << " accesare ) ";
            else
                cout << x->first << " accesari ) ";
            contor++;
        }
    }
    cout << "\n\nTop trei intrebari cele mai putin accesate: ";
    contor = 0;
    for (auto x : copie) {
        if (contor < 3)
        {
            cout << "\n\t" << contor + 1 << ". ";
            cout << x.second << " ( ";
            if (x.first == 1)
                cout << x.first << " accesare ) ";
            else
                cout << x.first << " accesari ) ";
            contor++;
        }
    }
    cout << "\n\n\n\tMetoda de reprezentare a datelor utilizand tehnica STEAM AND LEAF ( usor modificata ):\n ";
    contor = 0;
    for (auto x : copie)
    {
        cout << "\n" << contor << " | ";

        for (int i = 0; i < x.first; i++)
        {
            cout << "*" << " ";
        }
        cout << "\t\t ( " << x.second << " )\n";
        contor++;
    }

    cout << "\n\n\n------------------------------------------------------------------------------------------------";

    if (file.is_open())
    {
        file << "\n\n------------------------------------RAPORT-INTREBARI-FRECVENTE------------------------------------\n";
        file << "\n\t*Numar intrebari: " << intrebRasp.size();
        file << "\n\t*Numar accesari intrebari: " << nrTotalAccesari;
        file << "\n\t*Media aritmetica: " << medieA;
        file << "\n\t*Media geometrica: " << medieG;
        file << "\n\t*Mediana (cuantila de ordin 2) : ";
        contor = 1;
        for (auto x : copie) {
            if (contor == locMediana)
            {
                file << "Intrebarea: " << x.second << " ( " << x.first << " accesari ) ";
            }
            contor++;
        }
        file << "\n\nTop trei intrebari cele mai accesate: ";
        int contor = 0;
        for (auto x = copie.rbegin(); x != copie.rend(); x++)
        {
            if (contor < 3)
            {
                file << "\n\t" << contor + 1 << ". ";
                file << x->second << " ( ";
                if (x->first == 1)
                    file << x->first << " accesare ) ";
                else
                    file << x->first << " accesari ) ";
                contor++;
            }
        }
        file << "\n\nTop trei intrebari cele mai putin accesate: ";
        contor = 0;
        for (auto x : copie) {
            if (contor < 3)
            {
                file << "\n\t" << contor + 1 << ". ";
                file << x.second << " ( ";
                if (x.first == 1)
                    file << x.first << " accesare ) ";
                else
                    file << x.first << " accesari ) ";
                contor++;
            }
        }
        file << "\n\n\n\tMetoda de reprezentare a datelor utilizand tehnica STEAM AND LEAF ( usor modificata ):\n ";
        contor = 0;
        for (auto x : copie)
        {
            file << "\n" << contor << " | ";

            for (int i = 0; i < x.first; i++)
            {
                file << "*" << " ";
            }
            file << "\t\t ( " << x.second << " )\n";
            contor++;
        }
        file << "\n\n------------------------------------------------------------------------------------------------";
    }
    else {
        cerr << "\nEroare la deschiderea fisierului RaportFrecvente.txt";

    }
}
    void Comanda::adaugaComandaFisier(const string& fileName,float pretTotal)
    {
        ofstream fisier(fileName, ios::app);
        if(pretTotal!=0)
            fisier << pretTotal << "\n";
        fisier.close();
    }
    void Comanda::raportCifraDeAfaceri()
    {
        float linie;
        list <float> listaComenzi;
        int cheltuieliExploatare, cheltuieliAmortizare, cheltuieliDobanzi;
        ofstream file("RaportCifraDeAfaceri.txt");
        ifstream file1("Cheltuieli.txt");
        ifstream file2("Comenzi.txt");
        if (!file1.is_open()) {
            cerr << "Eroare la deschiderea fisierului." <<endl;
            return;
        }
        else
        {
            file1 >> cheltuieliExploatare >> cheltuieliAmortizare >> cheltuieliDobanzi;
            file1.close();
        }
        if (!file2.is_open()) {
            cerr << "Eroare la deschiderea fisierului." << endl;
            return;
        }
        else
        {
            list<float>::iterator it = listaComenzi.begin();
            while (file2 >> linie)
            {
                listaComenzi.push_back(linie);
                
            }
            file2.close();
        }
        float suma = 0;
        for (list<float>::iterator i = listaComenzi.begin(); i != listaComenzi.end();  i++)
            suma += *i;
        cout << "\n------------------------------------RAPORT-CIFRA-DE-AFACERI-----------------------------------\n";
        cout << "\n\t*Nr comenzi plasate: " << listaComenzi.size();
        cout << "\n\t*Prima comanda plasata: " << listaComenzi.front();
        cout << "\n\t*Ultima comanda plasata: " << listaComenzi.back();
        listaComenzi.sort();
        cout << "\n\t*Cea mai mica comanda: " << listaComenzi.front();
        cout << "\n\t*Cea mai mare comanda: " << listaComenzi.back();
        cout << "\n\n\t*Cifra de afaceri: " << suma;
        float exB = suma - cheltuieliExploatare - cheltuieliAmortizare;
        cout << "\n\t*Excedentul brut (CA-Ch exploatare-Ch cu amortizarea): " << exB;
        float rezultatCurent = exB - cheltuieliDobanzi;
        cout << "\n\t*Rezultatul curent (ExB-Ch dobanzi): " << rezultatCurent;
        float impozit2 = rezultatCurent * 0.16;
        cout << "\n\t*Profit: " << rezultatCurent - impozit2;
        cout << "\n\n----------------------------------------------------------------------------------------------\n";

        file << "\n------------------------------------RAPORT-CIFRA-DE-AFACERI-----------------------------------\n";
        file << "\n\t*Nr comenzi plasate: " << listaComenzi.size();
        file << "\n\t*Prima comanda plasata: " << listaComenzi.front();
        file << "\n\t*Ultima comanda plasata: " << listaComenzi.back();
        file << "\n\t*Cea mai mica comanda: " << listaComenzi.front();
        file << "\n\t*Cea mai mare comanda: " << listaComenzi.back();
        file << "\n\n\t*Cifra de afaceri: " << suma;
        file << "\n\t*Excedentul brut (CA-Ch exploatare-Ch cu amortizarea): " << exB;
        file << "\n\t*Rezultatul curent (ExB-Ch dobanzi): " << rezultatCurent;
        file << "\n\t*Profit: " << rezultatCurent - impozit2;
        file << "\n\n----------------------------------------------------------------------------------------------\n";

        file.close();
    }
    void Comanda::conversieBinar(const string& fileName1, const string& fileName2)
    {
        string line;
        ifstream file1(fileName1);
        fstream file2(fileName2, ios::out | ios::binary);
        if (!file1.is_open() || !file2.is_open()) {
            cout << "\nEroare la deschiderea fisierelor." << endl;
            return;
        }
        
        while (file1>>line) {
            
            int lg = line.length() + 1;
            file2.write((char*)&lg, sizeof(int));
 
        }

        file1.close();
        file2.close();
    }
    
   
    