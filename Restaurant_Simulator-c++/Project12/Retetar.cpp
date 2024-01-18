#include "Retetar.h"

using namespace std;

Retetar::Retetar()
{
    //cout << "\nCONSTRUCTOR DEFAULT- CLASA RETETAR";
}
Retetar::Retetar(int nrIngrediente, MateriePrima** listaIngrediente, float* gramaje, int durataPreparare, float cantitateZahar, int nrCalorii)
{
    //cout << "\nCONSTRUCTOR CU TOTI PARAM- CLASA RETETAR";
    if (nrIngrediente != 0 && listaIngrediente != nullptr)
    {
        this->nrIngrediente = nrIngrediente;
        this->listaIngrediente = new MateriePrima * [this->nrIngrediente];
        this->gramaje = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->listaIngrediente[i] = listaIngrediente[i];
            this->gramaje[i] = gramaje[i];
        }
    }
    else { this->nrIngrediente = 0;  this->listaIngrediente = nullptr;  this->gramaje = nullptr; }
    if (durataPreparare > 3)
        this->durataPreparare = durataPreparare;
    else
    {
        // cerr << "\nDurata de preparare necorespunzatoare."; 
        this->durataPreparare = 0;
    }
    if (cantitateZahar >= 0)
        this->cantitateZahar = cantitateZahar;
    else
    {
        cerr << "\nCantitate de zahar necorespunzatoare."; this->cantitateZahar = 0;
    }
    if (nrCalorii >= 0)
        this->nrCalorii = nrCalorii;
    else
    {
        cerr << "\nNr calorii necorespunzatoare."; this->nrCalorii = 0;
    }
}
Retetar::Retetar(int nrIngrediente, MateriePrima** listaIngrediente, float* gramaje)
{
    //cout << "\nCONSTRUCTOR CU TREI PARAM- CLASA RETETAR";
    if (nrIngrediente != 0 && listaIngrediente != nullptr)
    {
        this->nrIngrediente = nrIngrediente;
        this->listaIngrediente = new MateriePrima * [this->nrIngrediente];
        this->gramaje = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->listaIngrediente[i] = listaIngrediente[i];
            this->gramaje[i] = gramaje[i];
        }
    }
    else { this->nrIngrediente = 0;  this->listaIngrediente = nullptr;  this->gramaje = nullptr; }
}
Retetar::Retetar(const Retetar& r)
{
    //cout << "\nCONSTRUCTOR DE COPIERE- CLASA RETETAR";
    if (r.nrIngrediente != 0 && r.gramaje != nullptr && r.listaIngrediente != nullptr)
    {
        this->nrIngrediente = r.nrIngrediente;
        this->listaIngrediente = new MateriePrima * [this->nrIngrediente];
        this->gramaje = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->listaIngrediente[i] = r.listaIngrediente[i];
            this->gramaje[i] = r.gramaje[i];
        }
    }
    else { this->nrIngrediente = 0;  this->listaIngrediente = nullptr;  this->gramaje = nullptr; }
    if (r.durataPreparare > 3)
        this->durataPreparare = r.durataPreparare;
    else this->durataPreparare = 0;
    if (r.cantitateZahar >= 0)
        this->cantitateZahar = r.cantitateZahar;
    else
        this->cantitateZahar = 0;
    if (r.nrCalorii >= 0)
        this->nrCalorii = r.nrCalorii;
    else this->nrCalorii = 0;
}
Retetar& Retetar::operator=(const Retetar& r)
{
    if (this != &r)
    {

        if (r.nrIngrediente != 0 && r.listaIngrediente != nullptr)
        {
            delete[] this->listaIngrediente;
            delete[] this->gramaje;
            this->nrIngrediente = r.nrIngrediente;
            this->listaIngrediente = new MateriePrima * [r.nrIngrediente];
            this->gramaje = new float[r.nrIngrediente];
            for (int i = 0; i < r.nrIngrediente; i++) {
                this->listaIngrediente[i] = r.listaIngrediente[i];
                this->gramaje[i] = r.gramaje[i];
            }
        }
        else { this->nrIngrediente = 0;  this->listaIngrediente = nullptr;  this->gramaje = nullptr; }
        if (r.durataPreparare > 3)
            this->durataPreparare = r.durataPreparare;
        else this->durataPreparare = 0;
        if (r.cantitateZahar >= 0)
            this->cantitateZahar = r.cantitateZahar;
        else
            this->cantitateZahar = 0;
        if (r.nrCalorii >= 0)
            this->nrCalorii = r.nrCalorii;
        else this->nrCalorii = 0;
    }
    else
    {
        exception* pEx = new exception("Eroare autoasignare");
        cerr << "\n" << pEx->what();
        throw* pEx;
    }
    return *this;
}
Retetar::~Retetar() {
    //cout << "\nDESTRCUTOR- CLASA RETETAR";
    delete[] this->listaIngrediente;
    this->listaIngrediente = nullptr;
    delete[] this->gramaje;
    this->gramaje = nullptr;
}
void Retetar::afisareRetetar()
{
    cout << "\n-------------METODA-AFISARE-RETETAR------------";
    cout << "\nDurata preparare: " << this->durataPreparare;
    cout << "\nCantitate zahar: " << this->cantitateZahar;
    cout << "\nNumar calorii: " << this->nrCalorii;
    cout << "\nNumar ingrediente: " << this->nrIngrediente;
    cout << "\nLista ingrediente: ";
    if (this->nrIngrediente > 0)
    {
        for (int i = 0; i < this->nrIngrediente; i++) {
            this->listaIngrediente[i]->afisareMateriePrima();
            cout << "\nGramaj " << this->listaIngrediente[i]->getDenumireMateriePrima() << " : " << this->gramaje[i] << " buc/g/litru\n";
        }

    }
    else
        cout << "-";
    cout << "\n------------------------------------------";
}
ostream& operator <<(ostream& out, const Retetar& r)
{
    out << "\n----------------OUT-RETETAR---------------";
    out << "\nDurata preparare: " << r.durataPreparare;
    out << "\nCantitate zahar: " << r.cantitateZahar;
    out << "\nNumar calorii: " << r.nrCalorii;
    out << "\nNumar ingrediente: " << r.nrIngrediente;
    out << "\nLista ingrediente: ";
    if (r.nrIngrediente > 0)
    {
        for (int i = 0; i < r.nrIngrediente; i++) {
            out << endl << *(r.listaIngrediente[i]) << "\nGramaj " << r.listaIngrediente[i]->getDenumireMateriePrima() << " : " << r.gramaje[i] << " buc/g/litru\n";
        }
    }
    else
        out << "-";
    out << "\n-----------------------------------";

    return out;
}
int Retetar::getDurataPreparare()
{
    return this->durataPreparare;
}
void Retetar::setDurataPreparare(int durataPreparare)
{
    if (durataPreparare > 3)
        this->durataPreparare = durataPreparare;
}
float Retetar::getCantitateZahar()
{
    return this->cantitateZahar;
}
void Retetar::setCantitateZahar(float cantitateZahar)
{
    if (cantitateZahar >= 0)
        this->cantitateZahar = cantitateZahar;
}
int Retetar::getNrCalorii()
{
    return this->nrCalorii;
}
void Retetar::setNrCalorii(int nrCalorii)
{
    if (nrCalorii >= 0)
        this->nrCalorii = nrCalorii;
}
int Retetar::getNrIngrediente()
{
    return this->nrIngrediente;
}
MateriePrima** Retetar::getListaIngrediente()
{
    return this->listaIngrediente;
}
void Retetar::setListaIngrediente(const MateriePrima** listaIngrediente, int nrIngrediente)
{
    for (int i = 0; i < this->nrIngrediente; i++)
    {
        this->listaIngrediente[i]->~MateriePrima();
    }
    delete[] this->listaIngrediente;
    this->listaIngrediente = nullptr;
    if (nrIngrediente > 0 && *listaIngrediente != nullptr)
    {
        this->nrIngrediente = nrIngrediente;
        this->listaIngrediente = new MateriePrima * [this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++)
            this->listaIngrediente[i] = new MateriePrima(**(listaIngrediente + i));
    }
    else
    {
        this->nrIngrediente = 0;
        this->listaIngrediente = nullptr;
    }
}
const float* Retetar::getGramaje()
{
    return this->gramaje;
}
void Retetar::setGramaje(const float* gramaje)
{
    if (this->nrIngrediente != 0 && gramaje != nullptr)
    {
        delete[] this->gramaje;
        this->gramaje = nullptr;
        this->gramaje = new float[this->nrIngrediente];
        for (int i = 0; i < this->nrIngrediente; i++)
            this->gramaje[i] = gramaje[i];

    }
}
istream& operator>>(istream& in, Retetar& r)
{
    if (r.listaIngrediente != nullptr)
    {
        delete[] r.listaIngrediente;
        r.listaIngrediente = nullptr;
    }
    if (r.gramaje != nullptr)
    {
        delete[] r.gramaje;
        r.gramaje = nullptr;
    }

    bool exit = false;
    do {
        cout << "\nIntroduceti nr ingrediente: ";
        if (in >> r.nrIngrediente && r.nrIngrediente > 0) {
            exit = true;
        }
        else {
            cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    exit = false;
    do {
        if (r.nrIngrediente > 0) {

            r.listaIngrediente = new MateriePrima * [r.nrIngrediente];

            for (int i = 0; i < r.nrIngrediente; ++i) {
                cout << "\nIntroduceti detalii pentru ingredientul " << i + 1 << ":" << endl;
                in >> *(r.listaIngrediente[i]);
            }
            exit = true;
        }
        else {
            cerr << "\nNu se poate face lista de ingrediente, pentru ca numarul de ingrediente este zero. " << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    } while (exit == false);

    exit = false;
    do {
        if (r.nrIngrediente >= 0) {
            r.gramaje = new float[r.nrIngrediente];
            for (int i = 0; i < r.nrIngrediente; ++i) {
                cout << "\nIntroduceti gramajul pentru ingredientul " << i + 1 << ": ";
                if (in >> r.gramaje[i] && r.gramaje[i] >= 0) {}
                else {
                    cerr << "\nValoarea introdusa pentru gramaj nu este valida. Reintroduceti." << endl;
                    in.clear();
                    in.ignore(numeric_limits<streamsize>::max(), '\n');
                    --i;
                }
            }

            exit = true;
        }
        else {
            cerr << "\nNu se pot introduce gramajele, pentru ca numarul de ingrediente este zero. " << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    exit = false;
    do {
        cout << "\nIntroduceti durata de preparare: ";
        if (in >> r.durataPreparare && r.durataPreparare >= 0) {
            exit = true;
        }
        else {
            cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);


    exit = false;
    do {
        cout << "\nIntroduceti nr de calorii: ";
        if (in >> r.nrCalorii && r.nrCalorii >= 0) {
            exit = true;
        }
        else {
            cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    exit = false;
    do {
        cout << "\nIntroduceti cantitatea de zahar: ";
        if (in >> r.cantitateZahar && r.cantitateZahar >= 0) {
            exit = true;
        }
        else {
            cerr << "\nValoarea introdusa nu este valida. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    return in;
}
void Retetar::gramajTotal()
{
    if (this->nrIngrediente <= 0)
    {
        cout << "-";
    }
    else
    {
        float gramajTotal = 0;
        for (int i = 0; i < this->nrIngrediente; i++)
            gramajTotal = gramajTotal + this->gramaje[i];
        cout << gramajTotal << "\n";
    }
}
void Retetar::adaugaIngredient(MateriePrima m, float gramaj)
{
    for (int i = 0; i < this->nrIngrediente; i++) {
        if (strcmp(this->listaIngrediente[i]->getDenumireMateriePrima(), m.getDenumireMateriePrima()) == 0) {

            cout << "\nIngredientul " << m.getDenumireMateriePrima() << " exista deja in reteta." << endl;
            return;
        }
    }

    if (!this->listaIngrediente) {
        this->listaIngrediente = new MateriePrima * [1];
        this->gramaje = new float[1];
        this->nrIngrediente = 0;
    }
    this->nrIngrediente++;

    MateriePrima** nou = new MateriePrima * [this->nrIngrediente];
    float* gramajeNoi = new float[this->nrIngrediente];

    for (int i = 0; i < this->nrIngrediente - 1; i++) {
        nou[i] = this->listaIngrediente[i];
        gramajeNoi[i] = this->gramaje[i];
    }

    nou[this->nrIngrediente - 1] = &m;
    gramajeNoi[this->nrIngrediente - 1] = gramaj;

    delete[] this->listaIngrediente;
    delete[] this->gramaje;

    this->listaIngrediente = nou;
    this->gramaje = gramajeNoi;
}
void Retetar::stergeIngredient(int pozitie)
{
    if (pozitie < 0 || pozitie >= this->nrIngrediente) {
        cerr << "Pozitie invalida." << endl;
        return;
    }

    if (this->nrIngrediente == 1) {
        delete[] this->listaIngrediente;
        delete[] this->gramaje;
        this->listaIngrediente = nullptr;
        this->gramaje = nullptr;
        this->nrIngrediente = 0;
        return;
    }

    MateriePrima** listaNoua = new MateriePrima * [(nrIngrediente - 1) * sizeof(MateriePrima)];
    float* gramajeNoi = new float[(nrIngrediente - 1) * sizeof(float)];

    int indexNouLista = 0;

    for (int i = 0; i < this->nrIngrediente; i++) {
        if (i != pozitie - 1) {
            listaNoua[indexNouLista] = this->listaIngrediente[i];
            gramajeNoi[indexNouLista] = this->gramaje[i];
            indexNouLista++;
        }
    }

    delete[] this->listaIngrediente;
    delete[] this->gramaje;

    this->listaIngrediente = listaNoua;
    this->gramaje = gramajeNoi;
    this->nrIngrediente--;
}
void Retetar::descriereReteta()
{
    if (nrIngrediente > 0 && listaIngrediente != nullptr)
    {
        for (int i = 0; i < this->nrIngrediente; i++)
            cout << this->listaIngrediente[i]->getDenumireMateriePrima() << " ";
    }
    else cout << "-";
}
float& Retetar::operator[](int pozitie) {
    if (pozitie >= 0 && pozitie < this->nrIngrediente)
        return this->gramaje[pozitie];
    else {

        throw new exception("Pozitie invalida la op[]");
    }
}
bool Retetar::valabilitateRetetar() {
    for (int i = 0; i < this->nrIngrediente; i++) {
        if (this->listaIngrediente[i]->valabiliateMateriePrima() == false) {
            return false;
        }
    }
    return true;
}
bool Retetar::disponibilitateRetetar() {
    for (int i = 0; i < this->nrIngrediente; i++) {
        if (this->listaIngrediente[i]->disponibilitateStoc() == false) {
            return false;
        }
    }
    return true;
}
void Retetar::scadeStocReteta() {

    for (int i = 0; i < this->nrIngrediente; i++) {
        float cantitate = this->gramaje[i];
        if (this->listaIngrediente[i]->getStoc() >= cantitate) {
            this->listaIngrediente[i]->setStoc(this->listaIngrediente[i]->getStoc() - cantitate);
        }
        else {

            cout << "Stoc insuficient pentru ingredientul " << this->listaIngrediente[i]->getDenumireMateriePrima() << endl;
        }
    }
}
void Retetar::saveToFile(fstream& file) {

    file.write((char*)&this->nrIngrediente, sizeof(int));

    for (int i = 0; i < this->nrIngrediente; ++i) {
        this->listaIngrediente[i]->saveToFile(file);
        file.write((char*)&this->gramaje[i], sizeof(float));
    }

    file.write((char*)&this->durataPreparare, sizeof(int));
    file.write((char*)&this->cantitateZahar, sizeof(float));
    file.write((char*)&this->nrCalorii, sizeof(int));

}

void Retetar::restoreFromFile(fstream& file) {
    file.read((char*)&this->nrIngrediente, sizeof(int));

    this->listaIngrediente = new MateriePrima * [this->nrIngrediente];
    this->gramaje = new float[this->nrIngrediente];

    for (int i = 0; i < this->nrIngrediente; ++i) {
        
        this->listaIngrediente[i] = new MateriePrima();
        this->listaIngrediente[i]->restoreFromFile(file);
        file.read((char*)&this->gramaje[i], sizeof(float));
    }
    file.read((char*)&this->durataPreparare, sizeof(int));
    file.read((char*)&this->cantitateZahar, sizeof(float));
    file.read((char*)&this->nrCalorii, sizeof(int));
}


