#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <regex>
#include <set>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;



class ContClient
{
	string nume = "Anonim";
	string prenume = "Anonim";
	string nrTelefon = "0000-000-000";
	string adresa = "fara_adresa";
	string email = "email@yahoo.com";
	string dataCreareCont = "ZZ.LL.AAAA";

	string parola = "Parola#";

public:
	ContClient(string parola, string dataCreareCont, string nume, string prenume, string nrTelefon, string adresa, string email);
	ContClient();
	~ContClient();
	ContClient(const ContClient& c);
	ContClient& operator=(const ContClient& c);
	void afisareContClient();
	string getDataCreareCont();
	void setDataCreareCOnt(string dataCreareCont);
	void setParola(string parola);
	const string getParola();
	void setNume(string nume);
	const string getNume();
	void setPrenume(string prenume);
	const string getPrenume();
	const string getNrTelefon();
	void setNrTelefon(string nrTelefon);
	const string getEmail();
	void setEmail(string email);
	const string getAdresa();
	void setAdresa(string adresa);
	friend ostream& operator<<(ostream& out, const ContClient& c);
	friend ifstream& operator>>(ifstream& in, ContClient& c);
	int cautaClientDupaEmail(vector<ContClient>& vectorClienti, const std::string& emailCautat);
	//static int encrypt(int p_letter);
	//static int decypt(int p_letter);
	void saveFile(const vector<string>& p_text, const string& fileName);
	vector<string> citesteLiniiFisier(const string& fileName);
	string getFile(const string& fileName, int* pozitie);
	void actualizareCSV(vector<ContClient>Clienti, const string& fileName);
	void raportClienti(vector<ContClient>vectorClienti);
	void raportFeedback();
	void adaugaFeedback(const string& fileName);
	void actualizareConectare(const std::string& fileName, int* mailGresit, int* mailCorect, int* parolaGresita, int* parolaCorecta);
	void actualizareF(const std::string& fileName, int* mailGresit, int* mailCorect, int* parolaGresita, int* parolaCorecta);
	void raportSecuritate(const string& fileName);
};