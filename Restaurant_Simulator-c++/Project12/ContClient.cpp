#include "ContClient.h"

	ContClient::ContClient(string parola, string dataCreareCont, string nume, string prenume, string nrTelefon, string adresa, string email)
	{
		//cout<<\nCONSTRUCTOR FARA PARAM- CLASA CONT CLIENT";
		regex formatData3("(0[1-9]|[12][0-9]|3[01]).(0[1-9]|1[0-2]).(\\d{4})");
		if (regex_match(dataCreareCont, formatData3))
			this->dataCreareCont = dataCreareCont;
		else
		{
			cerr << "\nData necorespunzatoare."; this->dataCreareCont = "ZZ-LL-AAAA";
		}
		regex formatData2("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%%*?&#]{8,15}$");
		if (regex_match(parola, formatData2))
			this->parola = parola;
		else
			this->parola = "Parola#";
		if (nume.length() >= 3)
			this->nume = nume;
		else
			this->nume = "Anonim";
		if (prenume.length() >= 3)
			this->prenume = prenume;
		else
			this->prenume = "Anonim";

		regex formatData1("[[:digit:]]{4}-[[:digit:]]{3}-[[:digit:]]{3}");
		if (regex_match(nrTelefon, formatData1))
			this->nrTelefon = nrTelefon;
		else
			this->nrTelefon = "0000-000-000";

		if (adresa.length() >= 5)
			this->adresa = adresa;
		else
			this->adresa = "fara_adresa";

		regex formatData("[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-9]+)*(.\[a-z]{2,4})");
		if (regex_match(email, formatData))
			this->email = email;
		else
			this->email = "email@yahoo.com";

	}
	ContClient::ContClient()
	{
		//cout<<"\nCONSTRUCTOR CU TOTI PARAM- CLASA CONT CLIENT";

	}
	ContClient::~ContClient()
	{
		//cout<<"\nDESTRUCTOR- CLASA CONT CLIENT";
	}
	ContClient::ContClient(const ContClient& c) {
		regex formatData3("(0[1-9]|[12][0-9]|3[01]).(0[1-9]|1[0-2]).(\\d{4})");
		if (regex_match(c.dataCreareCont, formatData3))
			this->dataCreareCont = c.dataCreareCont;
		else
		{
			cerr << "\nData necorespunzatoare."; this->dataCreareCont = "ZZ-LL-AAAA";
		}
		regex formatData2("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%%*?&#]{8,15}$");
		if (regex_match(c.parola, formatData2))
			this->parola = c.parola;
		else
			this->parola = "Parola#";
		if (c.nume.length() >= 3)
			this->nume = c.nume;
		else
			this->nume = "Anonim";

		if (c.prenume.length() >= 3)
			this->prenume = c.prenume;
		else
			this->prenume = "Anonim";

		regex formatData1("[[:digit:]]{4}-[[:digit:]]{3}-[[:digit:]]{3}");
		if (regex_match(c.nrTelefon, formatData1))
			this->nrTelefon = c.nrTelefon;
		else
			this->nrTelefon = "0000-000-000";

		if (c.adresa.length() >= 5)
			this->adresa = c.adresa;
		else
			this->adresa = "fara_adresa";

		regex formatData("[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-9]+)*(.\[a-z]{2,4})");
		if (regex_match(c.email, formatData))
			this->email = c.email;
		else
			email = "email@yahoo.com";
	}
	ContClient& ContClient::operator=(const ContClient& c)
	{
		if (this != &c) {
			regex formatData3("(0[1-9]|[12][0-9]|3[01]).(0[1-9]|1[0-2]).(\\d{4})");
			if (regex_match(c.dataCreareCont, formatData3))
				this->dataCreareCont = c.dataCreareCont;
			else
			{
				cerr << "\nData necorespunzatoare."; this->dataCreareCont = "ZZ-LL-AAAA";
			}
			regex formatData2("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%%*?&#]{8,15}$");
			if (regex_match(c.parola, formatData2))
				this->parola = c.parola;
			else
				this->parola = "Parola#";
			if (c.nume.length() >= 3)
				this->nume = c.nume;
			else
				this->nume = "Anonim";

			if (c.prenume.length() >= 3)
				this->prenume = c.prenume;
			else
				this->prenume = "Anonim";

			regex formatData1("[[:digit:]]{4}-[[:digit:]]{3}-[[:digit:]]{3}");
			if (regex_match(c.nrTelefon, formatData1))
				this->nrTelefon = c.nrTelefon;
			else
				this->nrTelefon = "0000-000-000";

			if (c.adresa.length() >= 5)
				this->adresa = c.adresa;
			else
				this->adresa = "fara_adresa";

			regex formatData("[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-9]+)*(.\[a-z]{2,4})");
			if (regex_match(c.email, formatData))
				this->email = c.email;
			else
				email = "email@yahoo.com";
		}
		return *this;
	}
	void ContClient::afisareContClient()
	{
		cout << "\n************AFISARE*CONT*CLIENT************";
		cout << "\nNume: " << this->nume;
		cout << "\nPrenume: " << this->prenume;
		cout << "\nParola: " << this->parola;
		cout << "\nNr telefon: " << this->nrTelefon;
		cout << "\nAdresa livrare: " << this->adresa;
		cout << "\nEmail: " << this->email;
		cout << "\nDate creare cont: " << this->dataCreareCont;
		cout << "\n*******************************************";

	}
	string ContClient::getDataCreareCont()
	{
		return this->dataCreareCont;
	}
	void ContClient::setDataCreareCOnt(string dataCreareCont)
	{
		regex formatData3("(0[1-9]|[12][0-9]|3[01]).(0[1-9]|1[0-2]).(\\d{4})");
		if (regex_match(dataCreareCont, formatData3))
			this->dataCreareCont = dataCreareCont;
	}
	void ContClient::setParola(string parola)
	{
		regex formatData2("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%%*?&#]{8,15}$");
		if (regex_match(parola, formatData2))
			this->parola = parola;
	}
	const string ContClient::getParola()
	{
		return this->parola;
	}
	void ContClient::setNume(string nume)
	{
		if (nume.length() >= 3)
			this->nume = nume;
	}
	const string ContClient::getNume()
	{
		return this->nume;
	}
	void ContClient::setPrenume(string prenume)
	{
		if (prenume.length() >= 3)
			this->prenume = prenume;
	}
	const string ContClient::getPrenume()
	{
		return this->prenume;
	}
	const string ContClient::getNrTelefon()
	{
		return this->nrTelefon;
	}
	void ContClient::setNrTelefon(string nrTelefon)
	{
		regex formatData1("[[:digit:]]{4}-[[:digit:]]{3}-[[:digit:]]{3}");
		if (regex_match(nrTelefon, formatData1))
			this->nrTelefon = nrTelefon;
	}
	const string ContClient::getEmail()
	{
		return this->email;
	}
	void ContClient::setEmail(string email)
	{
		regex formatData("[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-9]+)*(.\[a-z]{2,4})");
		if (regex_match(email, formatData))
			this->email = email;
	}
	const string ContClient::getAdresa()
	{
		return this->adresa;
	}
	void ContClient::setAdresa(string adresa)
	{
		if (adresa.length() >= 5)
			this->adresa = adresa;
	}
	 ostream& operator<<(ostream& out, const ContClient& c) {
		out << "\n---------OSTREAM-----------";
		out << "\nNume: " << c.nume;
		out << "\nPrenume: " << c.prenume;
		out << "\nParola: " << c.parola;
		out << "\nNr telefon: " << c.nrTelefon;
		out << "\nAdresa livrare: " << c.adresa;
		out << "\nEmail: " << c.email;
		out << "\nData creare cont: " << c.dataCreareCont;
		out << "\n--------------------";
		return out;
	}
	 ifstream& operator>>(ifstream& in, ContClient& c) {

		string line;

		getline(in, line);

		istringstream iss(line);
		string token;

		getline(iss, token, ';');
		c.nume = token;

		getline(iss, token, ';');
		c.prenume = token;

		getline(iss, token, ';');
		c.nrTelefon = token;

		getline(iss, token, ';');
		c.adresa = token;

		getline(iss, token, ';');
		c.email = token;

		getline(iss, token, ';');
		c.dataCreareCont = token;

		return in;
	}
	int ContClient::cautaClientDupaEmail(vector<ContClient>& vectorClienti, const string& emailCautat) {
		int pozitie = 0;
		for (auto x : vectorClienti) {
			if (x.getEmail() == emailCautat) {
				return pozitie;
			}
			++pozitie;
		}
		return -1;
	}
	string extrageLinieDinFisier(const string& filename, int* pozitie) {
		ifstream inFile(filename);
		if (!inFile.is_open()) {
			cerr << "Nu s-a putut deschide fisierul " << filename << " pentru citire.\n";
			return "";
		}

		string line;
		int currentPos = 0;
		while (getline(inFile, line)) {
			if (currentPos == *pozitie) {
				inFile.close();
				return line;
			}
			++currentPos;
		}

		if (!inFile.eof()) {
			cerr << "Eroare la citirea din fisierul " << filename << ".\n";
		}

		inFile.close();
		return "";
	}
	string extrageParolaDinFisier(const string& filename, int indexParola)
	{
		ifstream inFile(filename);
		if (!inFile.is_open())
		{
			cerr << "Nu s-a putut deschide fisierul " << filename << " pentru citire.\n";
			return "";
		}

		string line;
		int currentPos = 0;

		while (currentPos < indexParola && getline(inFile, line))
		{
			++currentPos;
		}

		if (currentPos != indexParola)
		{

			inFile.close();
			cerr << "Indexul parola nu a fost gasit in fisier.\n";
			return "";
		}

		for (char& caracter : line)
		{
			caracter = caracter-3;

			inFile.close();
			return line;
		}
	}
	
	void ContClient::saveFile(const vector<string>& p_text, const string& fileName) {
		ofstream file(fileName);
		if (!file.is_open()) {
			cerr << "Nu s-a putut deschide fisierul " << fileName << " pentru scriere.\n";
			return;
		}

		for (const string& parola : p_text) {
			for (char caracter : parola) {
				file << caracter+3;
				file << "\n";
			}
			file << "0\n";
		}

		file.close();
	}
	vector<string> ContClient::citesteLiniiFisier(const string& fileName) {
		vector<string> linii;
		ifstream file(fileName);

		if (!file.is_open()) {
			cerr << "Nu s-a putut deschide fisierul " << fileName << " pentru citire.\n";
			return linii;
		}

		string line;
		while (getline(file, line)) {
			linii.push_back(line);
		}

		file.close();
		return linii;
	}
	string ContClient::getFile(const string& fileName, int* pozitie) {
		string line;
		ifstream file(fileName);

		if (!file.is_open()) {
			cerr << "Nu s-a putut deschide fisierul " << fileName << " pentru citire.\n";
			return "";
		}

		int eChar;
		int contor = 0;
		string st;
		while (file >> eChar) {
			line += (char)(eChar-3);
			//cout <<endl<<line;
			if (eChar == 0) {

				if (contor == *pozitie) {
					st = line.substr(0, line.size() - 1);
					//cout << endl << st;
					break;
				}
				else
				{
					contor++; line.clear();
				}
			}
		}

		file.close();
		return st;
	}
	/*void ContClient::actualizareCSV(vector<ContClient>Clienti, const string& fileName)
	{

		ofstream fisier(fileName, ios::app);

		string nume;
		do
		{
			cout << "\nNume: ";
			cin >> nume;
		} while (nume.length() <= 3);

		string prenume;
		do
		{
			cout << "\nPrenume: ";
			cin >> prenume;
		} while (prenume.length() <= 3);

		regex formatData1("[[:digit:]]{4}-[[:digit:]]{3}-[[:digit:]]{3}");
		string nrTelefon;
		do
		{
			cout << "\nNr telefon:";
			cin >> nrTelefon;

		} while (regex_match(nrTelefon, formatData1) == false);

		string adresa;
		do
		{
			cout << "\nAdresa: ";
			cin >> adresa;
		} while (adresa.length() <= 3);

		string email;
		regex formatData("[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-9]+)*(.\[a-z]{2,4})");
		do
		{
			cout << "\nE-mail:";
			cin >> email;

		} while (regex_match(email, formatData) == false);

		regex formatData3("(0[1-9]|[12][0-9]|3[01]).(0[1-9]|1[0-2]).(\\d{4})");
		do
		{
			cout << "\nDate creare cont:";
			cin >> dataCreareCont;

		} while (regex_match(dataCreareCont, formatData3) == false);

		string parola;
		regex formatData2("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&#])[A-Za-z\\d@$!%%*?&#]{8,15}$");
		do
		{
			cout << "\nParola:";
			cin >> parola;

		} while (regex_match(parola, formatData2) == false);

		if (fisier.is_open()) {
			fisier << nume << ";" << prenume << ";" << nrTelefon << ";" << adresa << ";" << email << ";" << dataCreareCont << endl;
			fisier.close();
			cout << "Randul a fost adaugat cu succes.\n";
		}
		else {
			cerr << "Nu se poate deschide fisierului.\n";
		}

	}
	*/
	void ContClient::raportClienti(vector<ContClient>vectorClienti)
	{

		ofstream file("RaportClienti.txt");

		cout << "\n\n------------------------------------------RAPORT-CLIENTI------------------------------------------\n";
		cout << "\n\t*Numar conturi clienti: " << vectorClienti.size();

		multiset<string> dateAni;
		multiset<string>dateLuna;
		for (ContClient x : vectorClienti)
		{
			dateAni.insert(x.getDataCreareCont().substr(6, 4));
			if (x.getDataCreareCont().substr(6, 4) == "2024")
				dateLuna.insert(x.getDataCreareCont().substr(3, 7));
		}
		int nrAn2024 = 0, nrAn2023 = 0;
		for (auto x : dateAni)
		{
			if (x == "2024")
				nrAn2024++;

			if (x == "2023")
				nrAn2023++;
		}
		cout << "\n\t*Numar conturi create anul trecut: " << nrAn2023;
		cout << "\n\t*Numar conturi create in acest an: " << nrAn2024;
		cout << "\n\t*Numar conturi create in aceasta luna: " << dateLuna.size();

		cout << "\n\nComparatie conturi create conturi anul cu anul curent: ";
		cout << "\n\n2023: ";
		for (int i = 0; i < nrAn2023; i++)
			cout << " * ";
		cout << "\n\n2024: ";
		for (int i = 0; i < nrAn2024; i++)
			cout << " * ";
		if (nrAn2023 > nrAn2024)
			cout << "\n\tSe poate observa ca in anul precedent au fost create mai multe conturi.";
		else
			cout << "\n\tSe poate observa ca in anul curent au fost create mai multe conturi.";

		cout << "\n\nLista clienti: \n";
		for (int i = 0; i < vectorClienti.size(); i++)
		{
			cout << "\n\t" << i + 1 << ". " << vectorClienti[i].getNume() << " " << vectorClienti[i].getPrenume();
			cout << " \nDate contact: " << vectorClienti[i].getEmail() << "," << vectorClienti[i].getNrTelefon() << "," << vectorClienti[i].getAdresa();
		}

		cout << "\n\n\n------------------------------------------------------------------------------------------------";

		file << "\n\n------------------------------------------RAPORT-CLIENTI------------------------------------------\n";
		file << "\n\t*Numar conturi clienti: " << vectorClienti.size();
		file << "\n\t*Numar conturi create anul trecut: " << nrAn2023;
		file << "\n\t*Numar conturi create in acest an: " << nrAn2024;
		file << "\n\t*Numar conturi create in aceasta luna: " << dateLuna.size();
		file << "\n\nComparatie conturi create conturi anul cu anul curent: ";
		file << "\n\n2023: ";
		for (int i = 0; i < nrAn2023; i++)
			file << " * ";
		file << "\n\n2024: ";
		for (int i = 0; i < nrAn2024; i++)
			file << " * ";
		if (nrAn2023 > nrAn2024)
			file << "\n\tSe poate observa ca in anul precedent au fost create mai multe conturi.";
		else
			file << "\n\tSe poate observa ca in anul curent au fost create mai multe conturi.";
		file << "\n\nLista clienti: \n";
		for (int i = 0; i < vectorClienti.size(); i++)
		{
			file << "\n\t" << i + 1 << ". " << vectorClienti[i].getNume() << " " << vectorClienti[i].getPrenume();
			file << " \nDate contact: " << vectorClienti[i].getEmail() << "," << vectorClienti[i].getNrTelefon() << "," << vectorClienti[i].getAdresa();
		}

		file << "\n\n\n------------------------------------------------------------------------------------------------";

		file.close();
	}
	void ContClient::raportFeedback()
	{
		string linie;
		ofstream file("RaportFeedback.txt");
		ifstream file1("Feedback.txt");
		map<string, int> feedback;

		if (file1.is_open())
		{
			while (getline(file1, linie))
			{
				//cout << linie << '\n';

				istringstream ss(linie);
				string cheieUnica;
				int nota;
				getline(ss, cheieUnica, '-');
				ss >> nota;

				feedback[cheieUnica] = nota;
			}

			file1.close();

		}
		else cout << "\nNu se poate deschide fiserul Feedback.txt";

		int suma = 0;
		for (auto x : feedback)
		{
			if (x.second > 0 && x.second < 11)
				suma += x.second;
		}


		float medie = (float)suma / feedback.size();

		cout << "\n\n------------------------------------------RAPORT-FEEDBACK------------------------------------------\n";
		cout << "\n\t*Numar feedback oferit de clienti: " << feedback.size();
		cout << "\n\t*Medie feedback: " << fixed << setprecision(2) << medie;
		if (medie > 5)
			cout << "\nRestaurantul primeste in general o nota buna.";
		else
			cout << "\nRestaurantul primeste in general o nota nu chiar atat de buna.";

		int nota1 = 0, nota2 = 0, nota3 = 0, nota4 = 0, nota5 = 0, nota6 = 0, nota7 = 0, nota8 = 0, nota9 = 0, nota10 = 0;

		cout << "\n\nLista feedback: ";
		for (auto x : feedback)
		{

			cout << "\n\t" << x.first << " " << x.second;
			switch (x.second)
			{
			case 1: nota1++; break;
			case 2: nota2++; break;
			case 3: nota3++; break;
			case 4: nota4++; break;
			case 5: nota5++; break;
			case 6: nota6++; break;
			case 7: nota7++; break;
			case 8: nota8++; break;
			case 9: nota9++; break;
			case 10: nota10++; break;
			}

		}
		cout << "\n\n\t\tMetoda reprezentare a datelor: ";
		cout << "\n\n\t 1  | ";
		for (int i = 0; i < nota1; i++)
			cout << " * ";
		cout << "\n\t 2  | ";
		for (int i = 0; i < nota2; i++)
			cout << " * ";
		cout << "\n\t 3  | ";
		for (int i = 0; i < nota3; i++)
			cout << " * ";
		cout << "\n\t 4  | ";
		for (int i = 0; i < nota4; i++)
			cout << " * ";
		cout << "\n\t 5  | ";
		for (int i = 0; i < nota5; i++)
			cout << " * ";
		cout << "\n\t 6  | ";
		for (int i = 0; i < nota6; i++)
			cout << " * ";
		cout << "\n\t 7  | ";
		for (int i = 0; i < nota7; i++)
			cout << " * ";
		cout << "\n\t 8  | ";
		for (int i = 0; i < nota8; i++)
			cout << " * ";
		cout << "\n\t 9  | ";
		for (int i = 0; i < nota9; i++)
			cout << " * ";
		cout << "\n\t 10 | ";
		for (int i = 0; i < nota10; i++)
			cout << " * ";

		cout << "\n\n---------------------------------------------------------------------------------------------------\n";

		file << "\n\n------------------------------------------RAPORT-FEEDBACK------------------------------------------\n";
		file << "\n\t*Numar feedback oferit de clienti: " << feedback.size();
		file << "\n\t*Medie feedback: " << fixed << setprecision(2) << medie;
		if (medie > 5)
			file << "\nRestaurantul primeste in general o nota buna.";
		else
			file << "\nRestaurantul primeste in general o nota nu chiar atat de buna.";
		file << "\n\nLista feedback: ";
		for (auto x : feedback)
			file << "\n\t" << x.first << " " << x.second;
		file << "\n\n\t\tMetoda reprezentare a datelor: ";
		file << "\n\n\t 1  | ";
		for (int i = 0; i < nota1; i++)
			file << " * ";
		file << "\n\t 2  | ";
		for (int i = 0; i < nota2; i++)
			file << " * ";
		file << "\n\t 3  | ";
		for (int i = 0; i < nota3; i++)
			file << " * ";
		file << "\n\t 4  | ";
		for (int i = 0; i < nota4; i++)
			file << " * ";
		file << "\n\t 5  | ";
		for (int i = 0; i < nota5; i++)
			file << " * ";
		file << "\n\t 6  | ";
		for (int i = 0; i < nota6; i++)
			file << " * ";
		file << "\n\t 7  | ";
		for (int i = 0; i < nota7; i++)
			file << " * ";
		file << "\n\t 8  | ";
		for (int i = 0; i < nota8; i++)
			file << " * ";
		file << "\n\t 9  | ";
		for (int i = 0; i < nota9; i++)
			file << " * ";
		file << "\n\t 10 | ";
		for (int i = 0; i < nota10; i++)
			file << " * ";

		file << "\n\n---------------------------------------------------------------------------------------------------\n";

		file.close();
	}
	void ContClient::adaugaFeedback(const string& fileName)
	{
		ofstream fisier(fileName, ios::app);
		string descriere;
		int nota;
		do
		{
			cout << "\nIntroduceti descrierea: ";
			cin >> descriere;
		} while (descriere.length() <= 3);

		do {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nIntroduceti nota (1-10): ";
			cin >> nota;

			if (cin.fail() || nota < 1 || nota > 10) {
				cin.clear();
				cout << "Nota introdusa nu este valida. Va rugam reintroduceti.\n";
			}

		} while (nota < 1 || nota > 10);

		cout << "\nFeedback adaugat cu succes. Va multumim pentru timpul acordat.";

		fisier  << descriere << "-" << nota << "\n";
		fisier.close();
	}
	void ContClient::actualizareConectare(const string& fileName, int* mailGresit, int* mailCorect, int* parolaGresita, int* parolaCorecta)
	{
		int mailGresitF, mailCorectF, parolaGresitaF, parolaCorectaF;

		fstream file(fileName, ios::in);
		if (!file.is_open()) {
			cerr << "Eroare la deschiderea fisierului." << endl;
			return;
		}
		else
		{
			//cout << endl << mailGresit << " " << mailCorect << " " << parolaGresita << " " << parolaCorecta << endl;
			file >> mailGresitF >> mailCorectF >> parolaGresitaF >> parolaCorectaF;
			//cout << endl << mailGresitF << " " << mailCorectF << " " << parolaGresitaF << " " << parolaCorectaF << endl;
			*mailGresit += mailGresitF;
			*mailCorect += mailCorectF;
			*parolaCorecta += parolaCorectaF;
			*parolaGresita += parolaGresitaF;

			//cout << endl << mailGresitF << " " << mailCorectF << " " << parolaGresitaF << " " << parolaCorectaF << endl;

			//file << mailCorectF << "\n" << mailCorectF << "\n" << parolaGresitaF << "\n" << parolaCorectaF << "\n";
			file.close();
		}

	}
	void ContClient::actualizareF(const string& fileName, int* mailGresit, int* mailCorect, int* parolaGresita, int* parolaCorecta)
	{
		ofstream file(fileName);
		if (!file.is_open()) {
			cerr << "Eroare la deschiderea fisierului." << endl;
			return;
		}
		else
		{
			file << *mailGresit << "\n" << *mailCorect << "\n" << *parolaGresita << "\n" << *parolaCorecta << endl;
			file.close();
		}
	}
	void ContClient::raportSecuritate(const string& fileName)
	{
		fstream file(fileName, ios::in);
		ofstream file1("RaportSecuritate.txt");
		int mailGresitF, mailCorectF, parolaGresitaF, parolaCorectaF;

		if (!file.is_open()) {
			cerr << "Eroare la deschiderea fisierului." << endl;
			return;
		}
		else
		{
			file >> mailGresitF >> mailCorectF >> parolaGresitaF >> parolaCorectaF;
			file.close();
		}

		cout << "\n\n------------------------------------------RAPORT-SECURITATE------------------------------------------\n";
		cout << "\n\n\t*Numar introduceri gresite e-mail: " << mailGresitF;
		cout << "\n\t*Numar introduceri corecte e-mail: " << mailCorectF;
		cout << "\n\t*Numar introduceri gresite parola: " << parolaGresitaF;
		cout << "\n\t*Numar introduceri corecte parola: " << parolaCorectaF;
		float raport = (float)(mailCorectF + parolaCorectaF) / (mailGresitF + parolaGresitaF);
		cout << "\n\t*Raport logari reusite/nereusite: " << fixed << setprecision(2) << raport;
		if (raport >= 5)
			cout << "\n\nNumarul logarilor corecte este mai mare decat cel al logarilor incorecte. Sistemul de logare curent este sigur.";
		else
			cout << "\n\nNumarul logarilor corecte este mai mic decat cel al logarilor incorecte. Sistemul de logare curent este nesigur, recomandam imbunatatirea acestuia.";
		cout << "\n\n-----------------------------------------------------------------------------------------------------\n";

		file1 << "\n\n------------------------------------------RAPORT-SECURITATE------------------------------------------\n";
		file1 << "\n\n\t*Numar introduceri gresite e-mail: " << mailGresitF;
		file1 << "\n\t*Numar introduceri corecte e-mail: " << mailCorectF;
		file1 << "\n\t*Numar introduceri gresite parola: " << parolaGresitaF;
		file1 << "\n\t*Numar introduceri corecte parola: " << parolaCorectaF;
		file1 << "\n\t*Raport logari reusite/nereusite: " << fixed << setprecision(2) << raport;
		if (raport >= 5)
			file1 << "\n\nNumarul logarilor corecte este mai mare decat cel al logarilor incorecte. Sistemul de logare curent este sigur.";
		else
			file1 << "\n\nNumarul logarilor corecte este mai mic decat cel al logarilor incorecte. Sistemul de logare curent este nesigur, recomandam imbunatatirea acestuia.";
		file1 << "\n\n-----------------------------------------------------------------------------------------------------\n";
		file1.close();
	}

