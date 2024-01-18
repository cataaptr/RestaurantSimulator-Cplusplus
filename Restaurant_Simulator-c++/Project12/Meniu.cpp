#include "Meniu.h"

Meniu::Meniu()
{
    // cout << "\nCONSTRUCTOR DEFAULT- CLASA MENIU";
}
Meniu::Meniu(int nrPreparate, Preparat* listaPreparate, int nrBauturi, Bautura* listaBauturi)
{
    //cout << "\nCONSTRCUTOR CU TOTI PARAM- CLASA MENIU";
    if (nrPreparate != 0 && listaPreparate != nullptr)
    {
        this->nrPreparate = nrPreparate;
        this->listaPreparate = new Preparat[this->nrPreparate];
        for (int i = 0; i < this->nrPreparate; i++) {
            this->listaPreparate[i] = listaPreparate[i];
        }
    }
    else
    {
        this->nrPreparate = 0;
        this->listaPreparate = nullptr;
    }
    if (nrBauturi != 0 && listaBauturi != nullptr)
    {
        this->nrBauturi = nrBauturi;
        this->listaBauturi = new Bautura[this->nrBauturi];
        for (int i = 0; i < this->nrBauturi; i++) {
            this->listaBauturi[i] = listaBauturi[i];
        }
    }
    else
    {
        this->nrBauturi = 0;
        this->listaBauturi = nullptr;
    }
}
Meniu::Meniu(int nrPreparate, Preparat* listaPreparate)
{
    //cout << "\nCONSTRCUTOR CU DOi PARAM- CLASA MENIU";
    if (nrPreparate != 0 && listaPreparate != nullptr)
    {
        this->nrPreparate = nrPreparate;
        this->listaPreparate = new Preparat[this->nrPreparate];
        for (int i = 0; i < this->nrPreparate; i++) {
            this->listaPreparate[i] = listaPreparate[i];
        }
    }
    else
    {
        this->nrPreparate = 0;
        this->listaPreparate = nullptr;
    }
}
Meniu::~Meniu()
{
    // cout << "\nDESTRUCTOR- CLASA MENIU";
    delete[] this->listaPreparate;
    this->listaPreparate = nullptr;
    delete[] this->listaBauturi;
    this->listaBauturi = nullptr;

}
Meniu::Meniu(const Meniu& m)
{
    // cout << "\nCONSTRUCTOR DE COPIERE- CLASA MENIU";
    if (m.nrPreparate != 0 && m.listaPreparate != nullptr)
    {
        this->nrPreparate = m.nrPreparate;
        this->listaPreparate = new Preparat[this->nrPreparate];
        for (int i = 0; i < this->nrPreparate; i++) {
            this->listaPreparate[i] = m.listaPreparate[i];
        }
    }
    else
    {
        this->nrPreparate = 0;    this->listaPreparate = nullptr;
    }
    if (m.nrBauturi != 0 && m.listaBauturi != nullptr)
    {
        this->nrBauturi = m.nrBauturi;
        this->listaBauturi = new Bautura[this->nrBauturi];
        for (int i = 0; i < this->nrBauturi; i++) {
            this->listaBauturi[i] = m.listaBauturi[i];
        }
    }
    else
    {
        this->nrBauturi = 0;
        this->listaBauturi = nullptr;
    }


}
Meniu& Meniu::operator=(const Meniu& m)
{
    if (this != &m)
    {
        if (m.nrPreparate != 0 && m.listaPreparate != nullptr)
        {
            delete[] this->listaPreparate;
            this->nrPreparate = m.nrPreparate;
            this->listaPreparate = new Preparat[this->nrPreparate];
            for (int i = 0; i < this->nrPreparate; i++) {
                this->listaPreparate[i] = m.listaPreparate[i];
            }
        }
        else
        {
            this->nrPreparate = 0;    this->listaPreparate = nullptr;
        }
        if (m.nrBauturi != 0 && m.listaBauturi != nullptr)
        {
            delete[] this->listaBauturi;
            this->nrBauturi = m.nrBauturi;
            this->listaBauturi = new Bautura[this->nrBauturi];
            for (int i = 0; i < this->nrBauturi; i++) {
                this->listaBauturi[i] = m.listaBauturi[i];
            }
        }
        else
        {
            this->nrBauturi = 0;
            this->listaBauturi = nullptr;
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
int Meniu::getNrPreparate()
{
    return this->nrPreparate;
}
const Preparat* Meniu::getListaPreparate()
{
    return this->listaPreparate;
}
int Meniu::getNrBauturi()
{
    return this->nrBauturi;
}
const Bautura* Meniu::getListaBauturi()
{
    return this->listaBauturi;
}
void Meniu::setListaPreparate(const Preparat* listaPreparat, int nrPreparate)
{
    for (int i = 0; i < this->nrPreparate; i++)
    {
        this->listaPreparate[i].~Preparat();
    }
    delete[] this->listaPreparate;
    this->listaPreparate = nullptr;
    if (nrPreparate > 0 && listaPreparat != nullptr)
    {
        this->nrPreparate = nrPreparate;
        this->listaPreparate = new Preparat[this->nrPreparate];
        for (int i = 0; i < this->nrPreparate; i++)
            this->listaPreparate[i] = listaPreparate[i];
    }
    else
    {
        this->nrPreparate = 0;
        this->listaPreparate = nullptr;
    }
}
void Meniu::setListaBauturi(const Bautura* listaBauturi, int nrBauturi)
{
    for (int i = 0; i < this->nrBauturi; i++)
    {
        this->listaBauturi[i].~Bautura();
    }
    delete[] this->listaBauturi;
    this->listaBauturi = nullptr;
    if (nrBauturi > 0 && listaBauturi != nullptr)
    {
        this->nrBauturi = nrBauturi;
        this->listaBauturi = new Bautura[this->nrBauturi];
        for (int i = 0; i < this->nrBauturi; i++)
            this->listaBauturi[i] = listaBauturi[i];
    }
    else
    {
        this->nrBauturi = 0;
        this->listaBauturi = nullptr;
    }
}
ostream& operator <<(ostream& out, const Meniu& m)
{
    out << "\n----------------OUT-MENIU---------------";
    out << "\nLista preparate: ";
    if (m.nrPreparate > 0)
    {
        for (int i = 0; i < m.nrPreparate; i++) {
            out << endl << m.listaPreparate[i] << endl;
        }
    }
    else
        out << "-";
    out << "\n-----------------------------------";
    out << "\nLista Bauturi: ";
    if (m.nrBauturi > 0)
    {
        for (int i = 0; i < m.nrBauturi; i++) {
            out << endl << m.listaBauturi[i] << endl;
        }
    }
    else
        out << "-";
    out << "\n-----------------------------------";

    return out;
}
istream& operator>>(istream& in, Meniu& m)
{
    if (m.listaPreparate != nullptr)
    {
        delete[] m.listaPreparate;
        m.listaPreparate = nullptr;
    }

    if (m.listaBauturi != nullptr)
    {
        delete[] m.listaBauturi;
        m.listaBauturi = nullptr;
    }

    bool exit = false;
    do {
        cout << "\nIntroduceti nr preparate: ";
        if (in >> m.nrPreparate && m.nrPreparate > 0) {
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
        if (m.nrPreparate > 0) {

            m.listaPreparate = new Preparat[m.nrPreparate];

            for (int i = 0; i < m.nrPreparate; ++i) {
                cout << "\nIntroduceti detalii pentru preparatul " << i + 1 << ":" << endl;
                in >> m.listaPreparate[i];
            }
            exit = true;
        }
        else {
            cerr << "\nNu se poate face lista de ingrediente, pentru ca numarul de preparate este zero. " << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    } while (exit == false);

    exit = false;
    do {
        cout << "\nIntroduceti nr bauturi: ";
        if (in >> m.nrBauturi && m.nrBauturi > 0) {
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
        if (m.nrBauturi > 0) {

            m.listaBauturi = new Bautura[m.nrBauturi];

            for (int i = 0; i < m.nrBauturi; ++i) {
                cout << "\nIntroduceti detalii pentru preparatul " << i + 1 << ":" << endl;
                in >> m.listaBauturi[i];
            }
            exit = true;
        }
        else {
            cerr << "\nNu se poate face lista de ingrediente, pentru ca numarul de preparate este zero. " << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    } while (exit == false);

    return in;
}
void Meniu::afisareMesajMeniu()
{
    cout << "\n****************************MENIU*****************************";
    cout << "\n*                                                            *";
    cout << "\n*                    1. Meniu Preparate                      *";
    cout << "\n*                    2. Meniu Starters                       *";
    cout << "\n*                    3. Meniu Main Course                    *";
    cout << "\n*                    4. Meniu Paste & Risotto                *";
    cout << "\n*                    5. Meniu Pizza                          *";
    cout << "\n*                    6. Meniu Bauturi                        *";
    cout << "\n*                                                            *";
    cout << "\n**************************************************************";
    cout << "\n*                    7. Stergere element                     *";
    cout << "\n**************************************************************";
    cout << "\n*                    8. Intrebari frecvente                  *";
    cout << "\n**************************************************************";
    cout << "\n*                    9. SUMAR COMANDA                        *";
    cout << "\n**************************************************************";
}
void Meniu::afisareMeniuPreparate()
{
    cout << "\n**********************MENIU***PREPARATE***********************";
    cout << "\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    for (int i = 0; i < this->nrPreparate; i++)
    {
        cout << "\n               " << i + 1 << ". " << this->listaPreparate[i].getDenumirePreparat();
        cout << "\n        ( ";
        this->listaPreparate[i].descrierePreparat();
        cout << " ) ";
        cout << "\n        Gramaj:";
        this->listaPreparate[i].gramajPreparat();
        cout << "\n        Pret: " << this->listaPreparate[i].getPretPreparat() << endl;
    }
    cout << "\n";
    cout << "\n**************************************************************";
}
void Meniu::afisareMeniuBauturi()
{
    cout << "\n**********************MENIU***BAUTURI*************************";
    cout << "\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    for (int i = 0; i < this->nrBauturi; i++)
    {
        cout << "\n               " << i + 1 << ". " << this->listaBauturi[i].getDenumireBautura();
        cout << "\n        ( ";
        this->listaBauturi[i].descriereBautura();
        cout << " ) ";
        cout << "\n        Pret: " << this->listaBauturi[i].getPretBautura() << endl;
    }
    cout << "\n";
    cout << "\n**************************************************************";
}
void Meniu::afisareMeniuStarters()
{
    cout << "\n**********************MENIU***STARTERS************************";
    cout << "\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    int k = 0;
    for (int i = 0; i < this->nrPreparate; i++)
    {
        if (this->listaPreparate[i].getEsteStarter() == true)
        {
            cout << "\n               " << k + 1 << ". " << this->listaPreparate[i].getDenumirePreparat();
            cout << "\n        ( ";
            this->listaPreparate[i].descrierePreparat();
            cout << " ) ";
            cout << "\n        Gramaj:";
            this->listaPreparate[i].gramajPreparat();
            cout << "\n        Pret: " << this->listaPreparate[i].getPretPreparat() << endl;
            k++;
        }
    }
    cout << "\n";
    cout << "\n**************************************************************";
}
void Meniu::afisareMeniuMainCourse()
{
    cout << "\n**********************MENIU***MAIN*COURSE*********************";
    cout << "\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    int k = 0;
    for (int i = 0; i < this->nrPreparate; i++)
    {
        if (this->listaPreparate[i].getEsteMainCourse() == true)
        {
            cout << "\n                " << k + 1 << ". " << this->listaPreparate[i].getDenumirePreparat();
            cout << "\n        ( ";
            this->listaPreparate[i].descrierePreparat();
            cout << " ) ";
            cout << "\n        Gramaj:";
            this->listaPreparate[i].gramajPreparat();
            cout << "\n        Pret: " << this->listaPreparate[i].getPretPreparat() << endl;
            k++;
        }
    }
    cout << "\n";
    cout << "\n**************************************************************";
}
void Meniu::afisareMeniuPaste_Risotto()
{
    cout << "\n**********************MENIU***PASTE*&*RISOTTO*****************";
    cout << "\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    int k = 0;
    for (int i = 0; i < this->nrPreparate; i++)
    {
        if (this->listaPreparate[i].getEstePasta_risotto() == true)
        {
            cout << "\n                 " << k + 1 << ". " << this->listaPreparate[i].getDenumirePreparat();
            cout << "\n        ( ";
            this->listaPreparate[i].descrierePreparat();
            cout << " ) ";
            cout << "\n        Gramaj:";
            this->listaPreparate[i].gramajPreparat();
            cout << "\n        Pret: " << this->listaPreparate[i].getPretPreparat();
            k++;
        }
    }
    cout << "\n";
    cout << "\n**************************************************************";
}
void Meniu::afisareMeniuPizza()
{
    cout << "\n**********************MENIU***PIZZA***************************";
    cout << "\n";
    cout << "\n<-INAPOI MENIU PRINCIPAL (TASTA 0)\n";
    int k = 0;
    for (int i = 0; i < this->nrPreparate; i++)
    {
        if (this->listaPreparate[i].getEstePizza() == true)
        {
            cout << "\n             " << k + 1 << ". " << this->listaPreparate[i].getDenumirePreparat() << " (10-MICA, 20-MEDIE, 3-MARE)";
            cout << "\n        ( ";
            this->listaPreparate[i].descrierePreparat();
            cout << " ) ";
            cout << "\n        Gramaj:";
            this->listaPreparate[i].gramajPreparat();
            cout << "\n        Pret: " << this->listaPreparate[i].getPretPreparat() << endl;
            k++;
        }
    }
    cout << "\n";
    cout << "\n**************************************************************";
}
void Meniu::adaugaPreparat(Preparat p)
{
    for (int i = 0; i < this->nrPreparate; i++) {
        if (strcmp(this->listaPreparate[i].getDenumirePreparat(), p.getDenumirePreparat()) == 0) {
            cout << "Preparatul " << p.getDenumirePreparat() << " exista deja in meniu." << endl;
            return;
        }
    }

    if (!this->listaPreparate) {
        this->listaPreparate = new Preparat[1];
        this->nrPreparate = 0;
    }
    this->nrPreparate++;

    Preparat* nou = new Preparat[this->nrPreparate];

    for (int i = 0; i < this->nrPreparate - 1; i++) {
        nou[i] = this->listaPreparate[i];
    }

    nou[this->nrPreparate - 1] = p;
    delete[] this->listaPreparate;
    this->listaPreparate = nou;
}
void Meniu::stergePreparat(int pozitie)
{
    if (pozitie < 0 || pozitie >= this->nrPreparate) {
        cerr << "Pozitie invalida." << endl;
        return;
    }

    if (this->nrPreparate == 1) {
        delete[] this->listaPreparate;
        this->listaPreparate = nullptr;
        this->nrPreparate = 0;
        return;
    }

    Preparat* listaNoua = new Preparat[(this->nrPreparate - 1) * sizeof(Preparat)];
    int indexNouLista = 0;

    for (int i = 0; i < this->nrPreparate; i++) {
        if (i != pozitie - 1) {
            listaNoua[indexNouLista] = this->listaPreparate[i];
            indexNouLista++;
        }
    }

    delete[] this->listaPreparate;
    this->listaPreparate = listaNoua;
    this->nrPreparate--;
}
void Meniu::adaugaBautura(Bautura b)
{
    for (int i = 0; i < this->nrBauturi; i++) {
        if (strcmp(this->listaBauturi[i].getDenumireBautura(), b.getDenumireBautura()) == 0) {
            cout << "Bautura " << b.getDenumireBautura() << " exista deja in meniu." << endl;
            return;
        }
    }

    if (!this->listaBauturi) {
        this->listaBauturi = new Bautura[1];
        this->nrBauturi = 0;
    }
    this->nrBauturi++;

    Bautura* nou = new Bautura[this->nrBauturi];

    for (int i = 0; i < this->nrBauturi - 1; i++) {
        nou[i] = this->listaBauturi[i];
    }

    nou[this->nrBauturi - 1] = b;
    delete[] this->listaBauturi;
    this->listaBauturi = nou;
}
void Meniu::stergeBautura(int pozitie)
{
    if (pozitie < 0 || pozitie >= this->nrBauturi) {
        cerr << "Pozitie invalida." << endl;
        return;
    }

    if (this->nrBauturi == 1) {
        delete[] this->listaBauturi;
        this->listaBauturi = nullptr;
        this->nrBauturi = 0;
        return;
    }

    Bautura* listaNoua = new Bautura[(this->nrBauturi - 1) * sizeof(Bautura)];
    int indexNouLista = 0;

    for (int i = 0; i < this->nrBauturi; i++) {
        if (i != pozitie - 1) {
            listaNoua[indexNouLista] = this->listaBauturi[i];
            indexNouLista++;
        }
    }

    delete[] this->listaBauturi;
    this->listaBauturi = listaNoua;
    this->nrBauturi--;
}
void Meniu::creareMeniuPreparat(fstream& file, Retetar reteteP[])
{
    if (file) {
        delete[] this->listaPreparate;
        int nrLinieP = 0;
        string line;

        while (getline(file, line)) {
            nrLinieP++;
        }

        file.clear();
        file.seekg(0, ios::beg);

        if (nrLinieP > 0) {
            this->nrPreparate = nrLinieP;
            this->listaPreparate = new Preparat[nrLinieP];

            int i = 0;
            while (getline(file, line) && i < nrLinieP) {
                stringstream ss(line);
                string numePreparat;
                float pret;
                int picant;
                int pizzaInt;
                int tipPizza;
                int starterInt;
                int pastaRisottoInt;
                int mainCourseInt;

                if (getline(ss, numePreparat, ',')) {
                    string pretStr, picantStr, pizzaIntStr, tipPizzaStr, starterIntStr, pastaRisottoIntStr, mainCourseIntStr;

                    if (getline(ss, pretStr, ',') && getline(ss, picantStr, ',') && getline(ss, pizzaIntStr, ',') && getline(ss, tipPizzaStr, ',') && getline(ss, starterIntStr, ',') &&
                        getline(ss, pastaRisottoIntStr, ',') && getline(ss, mainCourseIntStr, ',')) {

                        try {
                            pret = stof(pretStr);
                            picant = stoi(picantStr);
                            pizzaInt = stoi(pizzaIntStr);
                            tipPizza = stoi(tipPizzaStr);
                            starterInt = stoi(starterIntStr);
                            pastaRisottoInt = stoi(pastaRisottoIntStr);
                            mainCourseInt = stoi(mainCourseIntStr);
                        }
                        catch (const invalid_argument& e) {
                            cerr << "Eroare la conversia valorilor: " << e.what() << "\n";
                            break;
                        }
                        bool pizza = (pizzaInt == 1);
                        bool starter = (starterInt == 1);
                        bool pastaRisotto = (pastaRisottoInt == 1);
                        bool mainCourse = (mainCourseInt == 1);

                        string restulLiniei;
                        getline(ss, restulLiniei);

                        Retetar reteta = reteteP[i];
                        this->listaPreparate[i].setRetetaPreparat(reteta);
                        this->listaPreparate[i].setDenumirePreparat(numePreparat.c_str());
                        this->listaPreparate[i].setPretPreparat(pret);
                        this->listaPreparate[i].setGradPicant(picant);
                        this->listaPreparate[i].setEstePizza(pizza);
                        this->listaPreparate[i].setTipPizza(static_cast<TipPizza>(tipPizza));
                        this->listaPreparate[i].setEsteStarter(starter);
                        this->listaPreparate[i].setEstePasta_risotto(pastaRisotto);
                        this->listaPreparate[i].setEsteMainCourse(mainCourse);

                        i++;
                    }
                    else {
                        cerr << "Eroare la citirea valorilor\n";
                        break;
                    }
                }
            }
        }
    }
    else {
        cout << "\nEroare la deschiderea fisierului de preparate";
    }

}
void Meniu::creareMeniuBauturi(fstream& file, Retetar reteteB[]) {
    if (file) {
        delete[] this->listaBauturi;
        int nrLinieB = 0;
        string line;

        while (getline(file, line)) {
            nrLinieB++;
        }

        file.clear();
        file.seekg(0, ios::beg);

        if (nrLinieB > 0) {
            this->nrBauturi = nrLinieB;
            this->listaBauturi = new Bautura[nrLinieB];

            int i = 0;
            while (getline(file, line) && i < nrLinieB) {
                stringstream ss(line);
                string numeBautura;
                float pret;
                int areAlcoolInt;
                getline(ss, numeBautura, ',');

                if (!ss) {
                    cerr << "Eroare citire nume bautura";
                    break;
                }

                ss >> pret >> areAlcoolInt;
                bool areAlcool = (areAlcoolInt == 1);

                Retetar reteta = reteteB[i];
                this->listaBauturi[i].setRetetaBautura(reteta);

                this->listaBauturi[i].setDenumireBautura(numeBautura.c_str());
                this->listaBauturi[i].setPretBautura(pret);
                this->listaBauturi[i].setAreAlcool(areAlcool);

                i++;
            }
        }
    }
    else {
        cout << "\nEroare la deschiderea fisierului de bauturi";
    }
}
void Meniu::rulareMeniu(int* optiune)
{
    int cont = 1;
    //int optiune;
    int num;
    char c;

    afisareMesajMeniu();
    do {
        cout << "\nAlegeti afisarea meniului dorit: ";
        c = getch();

        num = c - '0';
        cout << c;

    } while (num < 0 || num>9);

    system("cls");
    switch (num)
    {
    case 0: {afisareMesajMeniu(); }break;
    case 1: {afisareMeniuPreparate(); }break;
    case 2: {afisareMeniuStarters();  }break;
    case 3: {afisareMeniuMainCourse();  }break;
    case 4: {afisareMeniuPaste_Risotto();  }break;
    case 5: {afisareMeniuPizza();  }break;
    case 6: {afisareMeniuBauturi();  }break;
    }
    *optiune = num;

}
void Meniu::continuare(int* cont)
{
    char c;
    int num;
    do {
        cout << "\n Mai doriti ceva din acest meniu?\n" << endl;
        cout << "1- DA" << endl;
        cout << "0- MENIU PRINCIPAL" << endl;

        c = getch();
        num = c - '0';
        cout << c;
        if (c < '0' || c > '9') {
            num = -1;
        }

    } while (num != 0 && num != 1);
    *cont = num;

}


