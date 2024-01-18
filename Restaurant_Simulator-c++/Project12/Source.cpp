#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "MateriePrima.h"
#include "Retetar.h"
#include "Preparat.h"
#include "Bautura.h"
#include "Meniu.h"
#include "Comanda.h"
#include "ContClient.h"
using namespace std;



int main()
{
    MateriePrima m1;
    //vector<MateriePrima>vectorMateriePrima;
    ifstream f("AprovizionareMateriePrima.txt");
    //while (f >> m1)
    //{
       // vectorMateriePrima.push_back(m1);
    //}
    // for (vector<MateriePrima>::iterator I = vectorMateriePrima.begin(); I < vectorMateriePrima.end(); I++)
        // cout << *I << endl;  

    vector<MateriePrima*> PvectorMateriePrima;
    //for (int i = 0; i < vectorMateriePrima.size(); ++i) {
      //  MateriePrima* newObj = new MateriePrima(vectorMateriePrima[i]);
       // PvectorMateriePrima.push_back(newObj);
   // }

    while (f >> m1)
    {
        MateriePrima* newObj = new MateriePrima(m1);
        PvectorMateriePrima.push_back(newObj);
    }
    f.close();

    // for (vector<MateriePrima*>::iterator I = PvectorMateriePrima.begin(); I < PvectorMateriePrima.end(); I++)
         //cout << **I << endl; 

    MateriePrima* ingrediente1[] = { PvectorMateriePrima[0],PvectorMateriePrima[1],PvectorMateriePrima[2],PvectorMateriePrima[3],PvectorMateriePrima[4] };
    float gramaje1[] = { 1,200,3,1,3 };
    Retetar reteta1(5, ingrediente1, gramaje1, 30, 0, 400);

    MateriePrima* ingrediente2[] = { PvectorMateriePrima[5],PvectorMateriePrima[7],PvectorMateriePrima[8],PvectorMateriePrima[9],PvectorMateriePrima[2] };
    float gramaje2[] = { 1,100,50,100,3 };
    Retetar reteta2(5, ingrediente2, gramaje2, 40, 0, 600);

    MateriePrima* ingrediente3[] = { PvectorMateriePrima[10],PvectorMateriePrima[2],PvectorMateriePrima[6],PvectorMateriePrima[4] };
    float gramaje3[] = { 1,3,200,1 };
    Retetar reteta3(4, ingrediente3, gramaje3, 32, 0, 278);

    MateriePrima* ingrediente4[] = { PvectorMateriePrima[11],PvectorMateriePrima[12],PvectorMateriePrima[13],PvectorMateriePrima[2] };
    float gramaje4[] = { 1,100,1,3 };
    Retetar reteta4(4, ingrediente4, gramaje4, 28, 0, 233);

    MateriePrima* ingrediente5[] = { PvectorMateriePrima[14],PvectorMateriePrima[15],PvectorMateriePrima[16],PvectorMateriePrima[2],PvectorMateriePrima[8] };
    float gramaje5[] = { 100,200,100,3,200 };
    Retetar reteta5(5, ingrediente5, gramaje5, 28, 0, 399);

    MateriePrima* ingrediente6[] = { PvectorMateriePrima[17],PvectorMateriePrima[18],PvectorMateriePrima[2],PvectorMateriePrima[8] };
    float gramaje6[] = { 100,100,100,100 };
    Retetar reteta6(4, ingrediente6, gramaje6, 30, 0, 200);

    MateriePrima* ingrediente7[] = { PvectorMateriePrima[1],PvectorMateriePrima[2],PvectorMateriePrima[19],PvectorMateriePrima[8] };
    float gramaje7[] = { 100,3,300,100 };
    Retetar reteta7(4, ingrediente7, gramaje7, 45, 0, 400);

    MateriePrima* ingrediente8[] = { PvectorMateriePrima[1],PvectorMateriePrima[2],PvectorMateriePrima[19],PvectorMateriePrima[8] };
    float gramaje8[] = { 150,5,350,150 };
    Retetar reteta8(4, ingrediente8, gramaje8, 45, 0, 400);

    MateriePrima* ingrediente9[] = { PvectorMateriePrima[1],PvectorMateriePrima[2],PvectorMateriePrima[19],PvectorMateriePrima[8] };
    float gramaje9[] = { 200,6,600,200 };
    Retetar reteta9(4, ingrediente9, gramaje9, 45, 0, 400);

    // Retetar reteteP[] = { reteta1,reteta2,reteta3, reteta4, reteta5, reteta6, reteta7, reteta8, reteta9 };
     //vector <Preparat> vectorPreparat;
     //Preparat p1;


    Preparat p1(reteta1, "Calamari cu mozarella", 64, 0, false, TipPizza::MICA, 1, false, false);
    Preparat p2(reteta2, "Crochete de cod negru", 64, 0, false, TipPizza::MICA, 1, false, false);
    Preparat p3(reteta3, "Biban de Mare", 109, 0, false, TipPizza::MICA, false, false, true);
    Preparat p4(reteta4, "Somon in crusta de fistic", 109, 0, false, TipPizza::MICA, false, false, true);
    Preparat p5(reteta5, "Paste Carbonara", 69, 0, 1);
    Preparat p6(reteta6, "Risotto cu trufe", 89, 0, 1);
    Preparat p7(reteta7, "Pizza Quattro Formaggi Mica", 70, 0, 1, TipPizza::MICA);
    Preparat p8(reteta8, "Pizza Quattro Formaggi Medie", 80, 0, 1, TipPizza::MEDIE);
    Preparat p9(reteta9, "Pizza Quattro Formaggi Mare", 90, 0, 1, TipPizza::MARE);

    vector <Preparat> vectorPreparat = { p1,p2,p3,p4,p5,p6,p7,p8,p9 };
    ofstream g("Preparate.txt");
    for (Preparat x : vectorPreparat)
        g << x;
    g.close();

    //for (Preparat x : vectorPreparat)
        //cout << x << endl;

    MateriePrima* ingrediente10[] = { PvectorMateriePrima[31],PvectorMateriePrima[24],PvectorMateriePrima[25],PvectorMateriePrima[23] ,PvectorMateriePrima[22] };
    float gramaje10[] = { 200,1,10, 100,10 };
    Retetar reteta10(5, ingrediente10, gramaje10, 7, 10, 400);
    Bautura b1("Pina Colada", 40, 1, reteta10);

    MateriePrima* ingrediente11[] = { PvectorMateriePrima[30] };
    float gramaje11[] = { 1 };
    Retetar reteta11(1, ingrediente11, gramaje11, 0, 0, 0);
    Bautura b2("Suc", 10, reteta11);

    MateriePrima* ingrediente12[] = { PvectorMateriePrima[29] };
    float gramaje12[] = { 1 };
    Retetar reteta12(1, ingrediente12, gramaje12, 0, 0, 0);
    Bautura b3("Apa", 8, reteta12);

    MateriePrima* ingrediente13[] = { PvectorMateriePrima[28] };
    float gramaje13[] = { 200 };
    Retetar reteta13(1, ingrediente13, gramaje13, 0, 0, 0);
    Bautura b4("Vin", 45, reteta13);

    MateriePrima* ingrediente14[] = { PvectorMateriePrima[31] };
    float gramaje14[] = { 30 };
    Retetar reteta14(1, ingrediente14, gramaje14, 0, 2, 0);
    Bautura b5("Shot rom", 27, reteta14);

    MateriePrima* ingrediente15[] = { PvectorMateriePrima[26] ,PvectorMateriePrima[29] };
    float gramaje15[] = { 25,0.5 };
    Retetar reteta15(2, ingrediente15, gramaje15, 0, 5, 0);
    Bautura b6("Expresso", 15, reteta15);

    MateriePrima* ingrediente16[] = { PvectorMateriePrima[26] ,PvectorMateriePrima[29],PvectorMateriePrima[27] };
    float gramaje16[] = { 25,0.5,50 };
    Retetar reteta16(3, ingrediente16, gramaje16, 0, 8, 0);
    Bautura b7("Capuccino", 20, reteta16);

    vector <Bautura> vectorBauturi = { b1,b2,b3,b4,b5,b6,b7 };
    ofstream h("Bauturi.txt");
    for (Bautura x : vectorBauturi)
        h << x;
    h.close();

    // for (Bautura x : vectorBauturi)
        // cout << x << endl;


    Meniu meniu1;
    Retetar reteteP[] = { reteta1,reteta2,reteta3, reteta4, reteta5, reteta6, reteta7, reteta8, reteta9 };
    fstream a("Preparate.txt");
    meniu1.creareMeniuPreparat(a, reteteP);
    a.close();

    Retetar reteteB[] = { reteta10,reteta11,reteta12,reteta13,reteta14,reteta15,reteta16 };
    fstream b("Bauturi.txt");
    meniu1.creareMeniuBauturi(b, reteteB);
    b.close();


    Comanda c1;
    int optiune, optiune2; int contt = 0;
    int numar = 10;


    //for (MateriePrima* x : PvectorMateriePrima)
       // cout << x->getStoc() << " ";
   // cout << endl;

    map < string, string> intrebRasp;
    map<string, int> frecvIntreb;
    //c1.creareIntrebariMain(intrebRasp, frecvIntreb);
    c1.creareIntrebariFisier(intrebRasp, frecvIntreb);

    //for (auto I : frecvIntreb)
        //cout << I.first << " " << I.second << endl;


    cout << "\n\t\t\tRestaurant Prime\n";
    cout << "\n\tRestaurantul Prime este unul ce abordeaza bucataria italieneasca, luand repere si arome din intreaga lume.\nNe place sa gatim, sa o facem bine si sa putem impartasi cu cei care vin sa ne viziteze.\n";

    do {
        meniu1.rulareMeniu(&optiune);

        if (optiune == 1)
        {
            c1.ruleazaComandaPreparat(vectorPreparat, &optiune2);
            if (optiune2 != 0)
            {
                meniu1.continuare(&contt);
                while (contt == 1)
                {
                    c1.ruleazaComandaPreparat(vectorPreparat, &optiune2);
                    if (optiune2 != 0)
                        meniu1.continuare(&contt);
                }
                system("cls");
            }
        }
        if (optiune == 2)
        {
            c1.ruleazaComandaStarters(vectorPreparat, &optiune2);
            if (optiune2 != 0)
            {
                meniu1.continuare(&contt);
                while (contt == 1)
                {
                    c1.ruleazaComandaStarters(vectorPreparat, &optiune2);
                    meniu1.continuare(&contt);
                }
                system("cls");
            }
        }
        if (optiune == 3)
        {
            c1.ruleazaComandaMainCourse(vectorPreparat, &optiune2);
            if (optiune2 != 0)
            {
                meniu1.continuare(&contt);
                while (contt == 1)
                {
                    c1.ruleazaComandaMainCourse(vectorPreparat, &optiune2);
                    if (optiune2 != 0)
                        meniu1.continuare(&contt);
                }
                system("cls");
            }
        }
        if (optiune == 4)
        {
            c1.ruleazaComandaPaste_Risotto(vectorPreparat, &optiune2);
            if (optiune2 != 0)
            {
                meniu1.continuare(&contt);
                while (contt == 1)
                {
                    c1.ruleazaComandaPaste_Risotto(vectorPreparat, &optiune2);
                    if (optiune2 != 0)
                        meniu1.continuare(&contt);
                }
                system("cls");
            }
        }
        if (optiune == 5)
        {
            c1.ruleazaComandaPizza(vectorPreparat, &optiune2);
            if (optiune2 != 0)
            {
                meniu1.continuare(&contt);
                while (contt == 1)
                {
                    c1.ruleazaComandaPizza(vectorPreparat, &optiune2);
                    if (optiune2 != 0)
                        meniu1.continuare(&contt);
                }
                system("cls");
            }
        }
        if (optiune == 6)
        {
            c1.ruleazaComandaBautura(vectorBauturi, &optiune2);
            if (optiune2 != 0)
            {
                meniu1.continuare(&contt);
                while (contt == 1)
                {
                    c1.ruleazaComandaBautura(vectorBauturi, &optiune2);
                    if (optiune2 != 0)
                        meniu1.continuare(&contt);
                }
                system("cls");
            }
        }
        if (optiune == 7)
        {
            c1.afisareComanda();
            int pozitie = 0;
            cout << "\nIntroduceti pozitia dorita: ";
            cin >> pozitie;
            char adev;
            cout << "\nAti introdus: " << pozitie;
            do
            {
                cout << "\nDoriti stergerea unui preparat sau a unei bauturi?";
                cout << "\n0- PREPARAT";
                cout << "\n1- BAUTURA ";
                cin >> adev;
                cout << "\nAti introdus: " << adev;
            } while (adev != '0' && adev != '1');

            if (adev == '0')
                c1.stergePreparatComanda(pozitie - 1);
            else
                c1.stergeBauturaComanda(pozitie - 1);
        }
        if (optiune == 8)
        {
            c1.afisareIntrebari(intrebRasp);
            c1.ruleazaIntrebari(intrebRasp, frecvIntreb);
        }

    } while (optiune >= 0 && optiune <= 8 && contt == 0);
    c1.afisareComanda();
    c1.adaugaComandaFisier("Comenzi.txt", c1.pretTotalComanda());

   // for (MateriePrima* x : PvectorMateriePrima)
      //  cout << x->getStoc() << " ";
    //cout << endl;

    vector <ContClient> vectorClienti;
    ifstream fisierr("Clienti1.csv", ios::in);
    ContClient cont;
    if (!fisierr.is_open()) {
        cerr << "Eroare la deschiderea fisierului.\n";
        return 1;
    }
    while (fisierr >> cont)
    {
        vectorClienti.push_back(cont);
    }
    //for (auto x : vectorClienti)
        //cout << x;

    fisierr.close();


    vector <string> paroleN;
    paroleN = cont.citesteLiniiFisier("Parole.txt");
    //cout << "\n";
    //for (string x : paroleN)
        //cout << x << " ";
    cont.saveFile(paroleN, "Parole2.txt");


    string citireEmail;
    int mailGresit = 0, mailCorect = 0, parolaGresita = 0, parolaCorecta = 0;
    char caracter; int num;
    int existaMail;
    int contor1 = 0;
    do
    {
        cout << "\nPentru finalizarea comenzii avem nevoie de datele contului.\nE-mail: ";
        cin >> citireEmail;
        existaMail = cont.cautaClientDupaEmail(vectorClienti, citireEmail);
        if (existaMail == -1)
        {
            cout << "\nE-mail inexistent.";
            mailGresit++;
        }
        else
            mailCorect++;
        contor1++;
        system("cls");
    } while (existaMail == -1 && contor1 < 3);
    contor1 = 0;
    if (existaMail != -1)
    {
        string parolaCitita;
        do {
            cout << "\nParola: ";
            cin >> parolaCitita;
            string parolaBuna;
            parolaBuna = cont.getFile("Parole2.txt", &existaMail);

            if (parolaBuna == parolaCitita)
            {
                parolaCorecta++;
                cout << "\nConectare reusita.";
                cout << "\nComanda dumneavoastra: ";
                c1.afisareComanda();
                cout << "\nDoriti plasarea acesteia:\n";
                cout << "\n0- NU";
                cout << "\n1- DA\n";
                do {
                    cin >> caracter;
                    cout << "Ati introdus: " << caracter;
                } while (caracter != '0' && caracter != '1');

                if (caracter == '1')
                {
                    cout << "\n\n\tVa multumim. Comanda dumneavoastra va ajunge in cel mai scurt timp ( estimare livrare: 40-120 minute).";
                    cout << "\n\t Pentru mai multe detalii puteti sa ne contactati la numarul de telefon : (+40)-000-000-000";
                    cout << "\n\n\tDoriti sa ne lasati un feedback? Ajuta foarte mult la imbunatatirea serviciilor.";
                    cout << "\n0- NU";
                    cout << "\n1- DA\n";
                    do
                    {
                        caracter = _getch();
                        num = caracter - '0';
                        cout << "\nAti introdus: " << caracter;
                        if (caracter < '0' || caracter > '9') {
                            num = -1;
                        }
                    } while (num != 0 && num != 1);
                    if (num == 1)
                        cont.adaugaFeedback("Feedback.txt");
                    else
                    {
                        system("cls"); cout << "\nVa multumim pentru timpul acordat.\n";
                    }
                }
                else
                {
                    system("cls"); cout << "\nVa multumim pentru timpul acordat.\n";
                }
                break;
            }
            else
            {
                cout << "\nParola incorecta.\n";
                parolaGresita++;
                contor1++;
            }
            system("cls");
        } while (contor1 < 3);
    }
    cont.actualizareConectare("Conectari.txt", &mailGresit, &mailCorect, &parolaGresita, &parolaCorecta);
    cont.actualizareF("Conectari.txt", &mailGresit, &mailCorect, &parolaGresita, &parolaCorecta);

    //c1.conversieBinar("AprovizionareMateriePrima.txt", "AprovizionareMateriePrima.bin");
    //c1.conversieBinar("Preparate.txt", "Preparate.bin");
    //c1.conversieBinar("Bauturi.txt", "Bauturi.bin");


    /* IFile* filePointer;
    fstream fileSaveMateriePrima("colectieMateriePrima.bin", ios::out | ios::binary);
    PvectorMateriePrima[0]->saveToFile(fileSaveMateriePrima);
    fileSaveMateriePrima.close(); */

    /* fstream fileRestoreMateriePrima("colectieMateriePrima.bin", ios::in | ios::binary);
    MateriePrima materieP;
    materieP.restoreFromFile(fileRestoreMateriePrima);
    cout << materieP;
   fileRestoreMateriePrima.close();  */

    /* IFile* filePointer;
    fstream fileSaveRetetar("colectieRetetar.bin", ios::out | ios::binary);
    reteta12.saveToFile(fileSaveRetetar);
    fileSaveRetetar.close(); */

    /* fstream fileRestoreRetetar("colectieRetetar.bin", ios::in | ios::binary);
    //Retetar retetaRR;
    //retetaRR.restoreFromFile(fileRestoreRetetar);
    //cout << retetaRR;
    //fileRestoreRetetar.close(); */


    //c1.raportFrecventaIntrebari(intrebRasp, frecvIntreb);
    //c1.raportCifraDeAfaceri();
   //cont.raportClienti(vectorClienti);
   //cont.raportFeedback();
   //cont.raportSecuritate("Conectari.txt");


    ofstream f1("AprovizionareMateriePrima.txt");
    for (MateriePrima* x : PvectorMateriePrima)
        f1 << *x;
    f1.close();



    return 0;

}