#include "MateriePrima.h"


MateriePrima::MateriePrima() :ID_materiePrima(MateriePrima::contor_ID_materiePrima++)
{
    //cout << "\nCONSTRUCTOR DEFAULT- CLASA MATERIE PRIMA";
}
MateriePrima::MateriePrima(const char* denumireMateriePrima, float stoc, string dataExpirare, bool necisitateRefrigerare, bool bautura) : ID_materiePrima(MateriePrima::contor_ID_materiePrima++)
{
    //cout << "\nCONSTRUCTOR CU TOTI PARAM- CLASA MATERIE PRIMA";
    if (denumireMateriePrima != nullptr && strlen(denumireMateriePrima) >= 3)
    {
        this->denumireMateriePrima = new char[strlen(denumireMateriePrima) + 1];
        strcpy(this->denumireMateriePrima, denumireMateriePrima);
    }
    else { cerr << "\nDenumire necorespunzatoare.";  this->denumireMateriePrima = nullptr; }
    if (stoc >= 0)
        this->stoc = stoc;
    else
        this->stoc = 0;
    regex formatData("(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\\d{4})");
    if (regex_match(dataExpirare, formatData))
        this->dataExpirare = dataExpirare;
    else
    {
        cerr << "\nData necorespunzatoare."; this->dataExpirare = "ZZ-LL-AAAA";
    }
    this->necesitateRefrigerare = necisitateRefrigerare;
    this->bautura = bautura;
}
MateriePrima::MateriePrima(const char* denumireMateriePrima, float stoc, string dataExpirare) :ID_materiePrima(MateriePrima::contor_ID_materiePrima++)
{
    //constructor pt a forma obiecte care nu e o bautura si nu necesita refrigerare
    //cout << "\nCONSTRUCTOR CU 3 PARAM- CLASA MATERIE PRIMA";
    if (denumireMateriePrima != nullptr && strlen(denumireMateriePrima) >= 3)
    {
        this->denumireMateriePrima = new char[strlen(denumireMateriePrima) + 1];
        strcpy(this->denumireMateriePrima, denumireMateriePrima);
    }
    else { cerr << "\nDenumire necorespunzatoare.";  this->denumireMateriePrima = nullptr; }
    if (stoc >= 0)
        this->stoc = stoc;
    else
        this->stoc = 0;
    regex formatData("(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\\d{4})");
    if (regex_match(dataExpirare, formatData))
        this->dataExpirare = dataExpirare;
    else
        this->dataExpirare = "ZZ-LL-AAAA";
}
MateriePrima::MateriePrima(const MateriePrima& m) :ID_materiePrima(MateriePrima::contor_ID_materiePrima++)
{
    //cout << "\nCONSTRUCTOR DE COPIERE- CLASA MATERIE PRIMA";
    if (m.denumireMateriePrima != nullptr && strlen(m.denumireMateriePrima) >= 3)
    {
        this->denumireMateriePrima = new char[strlen(m.denumireMateriePrima) + 1];
        strcpy(this->denumireMateriePrima, m.denumireMateriePrima);
    }
    else { cerr << "\nDenumire necorespunzatoare.";  this->denumireMateriePrima = nullptr; }
    if (m.stoc >= 0)
        this->stoc = m.stoc;
    else
        this->stoc = 0;
    regex formatData("(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\\d{4})");
    if (regex_match(m.dataExpirare, formatData))
        this->dataExpirare = m.dataExpirare;
    else
        this->dataExpirare = "ZZ-LL-AAAA";
    this->necesitateRefrigerare = m.necesitateRefrigerare;
    this->bautura = m.bautura;
}
MateriePrima::~MateriePrima()
{
    //cout << "\nDESTRUCTOR-CLASA MATERIE PRIMA";
    delete[] this->denumireMateriePrima;
    this->denumireMateriePrima = nullptr;
}
const char* MateriePrima::getDenumireMateriePrima()
{
    return this->denumireMateriePrima;
}
void MateriePrima::setDenumire(const char* denumireMateriePrima)
{
    if (denumireMateriePrima == nullptr || strlen(denumireMateriePrima) < 3)
        return;

    if (this->denumireMateriePrima != nullptr)
    {
        delete[] this->denumireMateriePrima;
        this->denumireMateriePrima = nullptr;
    }

    this->denumireMateriePrima = new char[strlen(denumireMateriePrima) + 1];
    strcpy(this->denumireMateriePrima, denumireMateriePrima);
}
bool MateriePrima::getRefrigerare()
{
    return this->necesitateRefrigerare;
}
void MateriePrima::setRefrigerare(bool necesitateRefrigerare)
{
    if (necesitateRefrigerare == true)
        this->necesitateRefrigerare = necesitateRefrigerare;
}
bool MateriePrima::getBautura()
{
    return this->bautura;
}
void MateriePrima::setBautura(bool bautura)
{
    if (bautura == true)
        this->bautura = bautura;
}
float MateriePrima::getStoc()
{
    return this->stoc;
}
void MateriePrima::setStoc(float stoc)
{
    if (stoc >= 0)
        this->stoc = stoc;
}
string MateriePrima::getDataExpirare()
{
    return this->dataExpirare;
}
void MateriePrima::setDataExpirare(string dataExpirare)
{
    regex formatData("(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\\d{4})");
    if (regex_match(dataExpirare, formatData))
        this->dataExpirare = dataExpirare;
}
const int MateriePrima::getIdMateriePrima()
{
    return this->ID_materiePrima;
}
void MateriePrima::afisareMateriePrima()
{
    cout << "\n-------------METODA-AFISARE-MATERIE-PRIMA-----------";
    if (this->denumireMateriePrima != nullptr)
        cout << "\nDenumire materie prima: " << this->denumireMateriePrima;
    else
        cout << "\nDenumire materie prima: -";
    cout << "\nID Materie Prima: " << this->ID_materiePrima;
    if (stoc >= 0)
        cout << "\nStoc (buc/g/litru): " << this->stoc;
    else
        cout << "\nStoc (buc/g/litru): -";
    cout << "\nData expirare: " << this->dataExpirare;
    cout << "\nNecesitate refrigerare: ";
    if (this->necesitateRefrigerare == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\nBautura: ";
    if (this->bautura == true)
        cout << "Da";
    else
        cout << "Nu";
    cout << "\n------------------------------------";
}
MateriePrima& MateriePrima::operator=(const MateriePrima& m)
{
    //cout << "\nOP =";
    if (this != &m)
    {
        if (m.denumireMateriePrima != nullptr) {
            delete[] this->denumireMateriePrima;
            this->denumireMateriePrima = nullptr;
            this->denumireMateriePrima = new char[strlen(m.denumireMateriePrima) + 1];
            strcpy(this->denumireMateriePrima, m.denumireMateriePrima);
        }
        else
            this->denumireMateriePrima = nullptr;
        if (m.stoc >= 0)
            this->stoc = m.stoc;
        else this->stoc = 0;
        regex formatData("(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\\d{4})");
        if (regex_match(m.dataExpirare, formatData))
            this->dataExpirare = m.dataExpirare;
        else
            this->dataExpirare = "ZZ-LL-AAAA";
        this->necesitateRefrigerare = m.necesitateRefrigerare;
        this->bautura = m.bautura;
    }
    else
    {
        exception* pEx = new exception("Eroare autoasignare");
        cerr << "\n" << pEx->what();
        throw* pEx;
    }

    return *this;
}
ostream& operator<<(ostream& out, const MateriePrima& m)
{
    out << "\n----------------OUT-MATERIE-PRIMA----------------";
    if (m.denumireMateriePrima != nullptr)
        out << "\nDenumire materie prima: " << m.denumireMateriePrima;
    else
        out << "\nDenumire materie prima: -";
    out << "\nID Materie Prima: " << m.ID_materiePrima;
    if (m.stoc >= 0)
        out << "\nStoc (buc/g/litru): " << m.stoc;
    else
        out << "\nStoc (buc/g/litru): -";
    out << "\nData expirare: " << m.dataExpirare;
    out << "\nNecesitate refrigerare: ";
    if (m.necesitateRefrigerare == true)
        out << "Da";
    else
        out << "Nu";
    out << "\nBautura: ";
    if (m.bautura == true)
        out << "Da";
    else
        out << "Nu";
    out << "\n---------------------------------------------";

    return out;
}
istream& operator>>(istream& in, MateriePrima& m)
{
    if (m.denumireMateriePrima != nullptr)
    {
        delete[] m.denumireMateriePrima;
        m.denumireMateriePrima = nullptr;
    }

    bool exit = false;
    char buffer[50];

    do
    {
        cout << "\nIntroduceti denumirea materiei prime: ";
        in.getline(buffer, sizeof(buffer));
        if (strlen(buffer) >= 3)
        {
            m.denumireMateriePrima = new char[strlen(buffer) + 1];
            strcpy(m.denumireMateriePrima, buffer);
            exit = true;
        }
        else { cerr << "\nDenumirea este mai mica decat 3." << endl; }

    } while (exit == false);

    int idGenerat = MateriePrima::generare_ID_materiePrima();
    const_cast<int&>(m.ID_materiePrima) = idGenerat;

    exit = false;
    do {
        cout << "\nIntroduceti stocul (buc/g/litru) : ";
        if (in >> m.stoc && m.stoc >= 0) {
            exit = true;
        }
        else {
            cerr << "\nValorea introdusa pentru stoc trebuie sa fie pozitiva." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (exit == false);

    in.ignore(numeric_limits<streamsize>::max(), '\n');

    regex formatData("(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\\d{4})");
    do {
        cout << "\nIntroduceti data la care expira (tip data:ZZ-LL-AAAA): ";
        getline(in, m.dataExpirare);
        if (regex_match(m.dataExpirare, formatData) != true)
            cerr << "\nData nu respceta formatul." << endl;
    } while (regex_match(m.dataExpirare, formatData) != true);

    char citire;
    do {
        cout << "\nNecesita refrigerare (0-NU, 1-DA): ";
        in >> citire;
        if (isdigit(citire) && citire >= '0' && citire <= '1')
            m.necesitateRefrigerare = citire - '0';
        else
        {
            cerr << "\nValoarea introdusa nu este o corespunzatoare intervalului. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    do {
        cout << "\nBautura(0-NU, 1-DA): ";
        in >> citire;
        if (isdigit(citire) && citire >= '0' && citire <= '1')
            m.bautura = citire - '0';
        else
        {
            cerr << "\nValoarea introdusa nu este o corespunzatoare intervalului. Reintroduceti." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!isdigit(citire) || (citire != '0' && citire != '1'));

    return in;
}
int MateriePrima::generare_ID_materiePrima() {
    return MateriePrima::contor_ID_materiePrima++;
}
bool MateriePrima::disponibilitateStoc()
{
    if (this->stoc > 0)
        return true;
    else
        return false;
}
bool MateriePrima::valabiliateMateriePrima()
{
    time_t now;
    time(&now);

    string dataExpirare = this->dataExpirare;
    int ziExpirare = stoi(dataExpirare.substr(0, 2));
    int lunaExpirare = stoi(dataExpirare.substr(3, 2));
    int anExpirare = stoi(dataExpirare.substr(6, 4));

    struct tm expirare_tm = { 0 };
    expirare_tm.tm_mday = ziExpirare;
    expirare_tm.tm_mon = lunaExpirare - 1;
    expirare_tm.tm_year = anExpirare - 1900;
    expirare_tm.tm_hour = 0;
    expirare_tm.tm_min = 0;
    expirare_tm.tm_sec = 0;

    struct tm now_tm;
    localtime_s(&now_tm, &now);

    if (difftime(mktime(&expirare_tm), mktime(&now_tm)) < 0)
        return false;
    else
        return true;
}
MateriePrima& MateriePrima::operator++() {
    this->stoc++;
    return *this;
}
MateriePrima MateriePrima::operator++(int) {
    MateriePrima copie = *this;
    this->stoc++;
    return copie;
}
MateriePrima MateriePrima::operator+(int stocSuplimentar) {
    if (stocSuplimentar > 0) {
        MateriePrima rez = *this;
        rez.stoc += stocSuplimentar;
        return rez;
    }

    return *this;
}
MateriePrima& MateriePrima::operator+=(int stocSuplimentar) {
    if (stocSuplimentar > 0) {
        this->stoc += stocSuplimentar;
    }
    return *this;
}
bool MateriePrima::operator!() {
    return !this->stoc;
}
ofstream& operator<<(ofstream& out, const MateriePrima& m) {
    if (m.denumireMateriePrima != nullptr)
        out << m.denumireMateriePrima;
    out << " ";
    out << m.stoc;
    out << " ";
    out << m.dataExpirare;
    out << " ";
    out << m.necesitateRefrigerare;
    out << " ";
    out << m.bautura;
    out << "\n";
    return out;
}
ifstream& operator>>(ifstream& in, MateriePrima& m) {

    if (m.denumireMateriePrima != nullptr)
    {
        delete[] m.denumireMateriePrima;
        m.denumireMateriePrima = nullptr;
    }
    m.denumireMateriePrima = new char[lungimeMax];
    in >> m.denumireMateriePrima;
    in >> m.stoc;
    in.ignore();
    in >> m.dataExpirare;
    in.ignore();
    in >> m.necesitateRefrigerare;
    in.ignore();
    in >> m.bautura;

    return in;
}
void MateriePrima::stergereMateriePrimaVector(const string& denumireStergere, vector<MateriePrima>& v) {
    for (auto it = v.begin(); it != v.end(); ) {
        if (denumireStergere == it->getDenumireMateriePrima()) {
            it = v.erase(it);
        }
        else {
            ++it;
        }
    }
}
void MateriePrima::adaugaMateriePrimaVector(vector<MateriePrima>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (this->denumireMateriePrima == it->getDenumireMateriePrima()) {
            return;
        }
    }

    v.push_back(*this);
}
void MateriePrima::scadeStoc(float gramaj)
{
    this->stoc = this->stoc - gramaj;
}

void MateriePrima::saveToFile(fstream& file) {
    
    int lg = strlen(this->denumireMateriePrima) + 1;
    file.write((char*)&lg, sizeof(int));
    file.write(this->denumireMateriePrima, lg);
    file.write((char*)&this->stoc, sizeof(float));
    int lgg = this->dataExpirare.length() + 1;
    file.write((char*)&lgg, sizeof(int));
    file.write(this->dataExpirare.data(), lgg);
    file.write((char*)&this->necesitateRefrigerare, sizeof(bool));
    file.write((char*)&this->bautura, sizeof(bool));

}

void MateriePrima::restoreFromFile(fstream& file) {
    int lg;
    file.read((char*)&lg, sizeof(int));
    char* buffer = new char[lg];
    file.read(buffer, lg);

    this->denumireMateriePrima = new char[lg];
    strcpy(this->denumireMateriePrima, buffer);

    delete[] buffer;

    file.read((char*)&this->stoc, sizeof(float));
    file.read((char*)&lg, sizeof(int));
    buffer = new char[lg];
    file.read(buffer, lg);

    this->dataExpirare = buffer;

    delete[] buffer;

    file.read((char*)&this->necesitateRefrigerare, sizeof(bool));
    file.read((char*)&this->bautura, sizeof(bool));
}


int MateriePrima::contor_ID_materiePrima = 0;