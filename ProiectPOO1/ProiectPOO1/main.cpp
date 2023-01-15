#include<iostream>
#include<string>
#include<fstream>
#include "eveniment.h"
#include "locbil.h"
#include "bilete.h"
using namespace std;
void showInitialMessage() {
	cout << "============================================================================================" << '\n' << '\n';
	cout << "Alegeti evenimentul la care doriti sa cumparati bilet: " << '\n' << '\n';
	cout << "1. Meci de fotbal " << '\n';
	cout << "2. Film" << '\n';
	cout << "3. Piesa de teatru" << '\n';
	cout << "4. Vizualizare evenimente disponibile" << '\n' << '\n';
	cout << "5. Iesire" << '\n' << '\n';
	cout << "Pentru alegerea evenimentului introduceti cifra corespondenta evenimentului si apasati ENTER" << '\n' << '\n';
	cout << "============================================================================================" << '\n' << '\n';
}
void visualev() {
	cout << "============================================================================================" << '\n' << '\n';
	cout << "Vizualizati evenimentele disponibile din categoria: " << '\n' << '\n';
	cout << "1. Meci de fotbal " << '\n';
	cout << "2. Film" << '\n';
	cout << "3. Piesa de teatru" << '\n';
	cout << "4. Iesire" << '\n' << '\n';
	cout << "Pentru alegerea evenimentului introduceti cifra corespondenta evenimentului si apasati ENTER" << '\n' << '\n';
	cout << "============================================================================================" << '\n' << '\n';
}

class abonament :public bilete
{
private:
	int pretabo;
public:

	abonament()
	{
		pretabo = 0;
	}

	abonament(float pret, string numeclient, string emailclient, string zonabilet,
		string categorieclient, int pretabo) :bilete(pret, numeclient, emailclient, zonabilet, categorieclient)
	{
		this->pretabo = pretabo;
	}

	virtual int calcul_Pret_Abo_Pe_An()
	{
		pretabo = getPret();
		return pretabo * 32;
	}

	abonament(const abonament& ab) :bilete(ab)
	{
		this->pretabo = ab.pretabo;
	}
	
	abonament& operator=(const abonament& ab)
	{
		if (this != &ab)
		{
			bilete::operator=(ab);
			this->pretabo = ab.pretabo;
		}
		return *this;
	}

	friend ostream& operator<<(ostream&, abonament);
	friend istream& operator>>(istream&, abonament&);

};

ostream& operator<<(ostream& out, abonament ab)
{
	out << (bilete)ab << endl;
	out << "Pret abonament: " << ab.pretabo << endl;
	return out;
};

istream& operator>>(istream& in, abonament& ab) 
{
	in >> (bilete&)ab;
	cout << "Pret abonament: ";
	in >> ab.pretabo;
	return in;
};
int main()
{
	string optiune1;
	string optiune2;
	string optiune3;
	string optiune4;
	eveniment e1;
	eveniment e1a;
	eveniment e2a;
	eveniment e3a;
	eveniment e4a;
	bilete b1;
	locbil l1;
	eveniment e1c("_______________Steaua-Rapid", "_______________19.02.2023", "_______________18", "_______________National Arena");
	ofstream fe1c("e1.txt");
	fe1c << e1c;
	fe1c.close();
	eveniment e2c("_______________Dinamo-Steaua", "_______________07.10.2023", "_______________20", "_______________Stefan cel Mare");
	ofstream fe2c("e2.txt");
	fe2c << e2c;
	fe2c.close();
	eveniment e3c("_______________Avatar:Calea_Apei", "_______________20.01.2023", "_______________19", "_______________CinemaCity_AFI");
	ofstream fe3c("e3.txt");
	fe3c << e3c;
	fe3c.close();
	eveniment e4c("_______________Barbierul_din_Sevilla", "_______________23.01.2023", "_______________15", "_______________Teatrul_Tandarica");
	ofstream fe4c("e4.txt");
	fe4c << e4c;
	fe4c.close();

	while (1)
	{
		optiune1:
		showInitialMessage();
		{
			getline(cin,optiune1); //selectam optiunea 
			try
			{
				if (optiune1[0] < '1' || optiune1[0]>'5')
					throw invalid_argument("Optiune invalida ,incercati din nou");

				if (optiune1[0] == '1' || optiune1[0] == '2' || optiune1[0] == '3')
				{
					eveniment:
					cin >> e1;
					bilet:
					try
					{
						cin >> b1;
					}
					catch (invalid_argument& e)
					{
						if (strcmp(e.what(), "email") == 0)
							cout << "Greseala email!" << '\n' << endl;
						else if (strcmp(e.what(), "categorie") == 0)
							cout << "Greseala categorie client!" << endl << endl;
						else if (strcmp(e.what(), "zona") == 0)
							cout << "Greseala zona bilet!" << endl << endl;
						else
							cout << "Greseala pret!" << '\n' << endl;
						goto bilet;
					}
					loc:
					try 
					{
						cin >> l1;
					}
					catch (invalid_argument& a)
					{
						cout << endl;
						cout << "Greseala numar de bilete ! Incercati sa tastati un numar valid !" << endl << endl;
						goto loc;
					}
					
				}
				if (optiune1[0] == '4')
				{
				optiune4:
					visualev();
					getline(cin, optiune4);
					try
					{

						if (optiune4[0] < '1' || optiune4[0]>'4')
						{
							throw invalid_argument("Optiune invalida ,incercati din nou");
							goto optiune4;
						}
							
						cout << "========================================================================================" << endl;
						if (optiune4[0] == '1')
						{

							ifstream ge1a;
							cout << "________________________________________________________________EVENIMENTUL 1" << endl;
							ge1a.open("e1.txt", ios::in);
							for (int i = 0; i < 1; i++)
							{
								ge1a >> e1a;
								cout << e1a;
							}
							ge1a.close();
							cout << endl << endl << endl;

							ifstream ge2a;
							cout << "________________________________________________________________EVENIMENTUL 2" << endl;
							ge2a.open("e2.txt", ios::in);
							for (int i = 0; i < 1; i++)
							{
								ge2a >> e2a;
								cout << e2a;
							}
							ge2a.close();

							goto optiune1;


						}
						if (optiune4[0] == '2')
						{
							ifstream ge3a;
							cout << "________________________________________________________________EVENIMENTUL 1" << endl;
							ge3a.open("e3.txt", ios::in);
							for (int i = 0; i < 1; i++)
							{
								ge3a >> e3a;
								cout << e3a;
							}
							ge3a.close();
							goto optiune1;
						}
						if (optiune4[0] == '3')
						{
							ifstream ge4a;
							cout << "________________________________________________________________EVENIMENTUL 1" << endl;
							ge4a.open("e4.txt", ios::in);
							for (int i = 0; i < 1; i++)
							{
								ge4a >> e4a;
								cout << e4a;
							}
							ge4a.close();
							goto optiune1;
						}
						if (optiune4[0] == '4')
						{
							goto optiune1;
						}
					}
					catch (invalid_argument& e)
					{
						cout << e.what() << '\n';
					}

				}
				if (optiune1[0] == '5')
				{
					cout << "Multumim pentru ca ati folosit aplicatia ! O zi frumoasa !" << endl;
					break;
				}

				cout << endl << endl << endl;
				cout << "Datele comenzii dumneavoastra :    " << endl << endl;
				cout << e1;
				cout << b1;
				cout << l1 << endl;
				l1.serialize();
				cout << "Pretul total al comenzii: " << b1.getPret() * l1.getNrRand() << endl;
				int idbil = 10000000 * stoi(optiune1) + 1000000 * b1.getPret() + 10000 * l1.getRandScaun(0) + 1000 * l1.getNrRand() + 100 * stoi(e1.getOraEv()) + 1 * l1.getColScaun(0);
				cout << "Id-ul biletului:" <<idbil << endl << endl;
				optiune3:
				cout << "Va rugam frumos sa verificati datele tocmai introduse,daca sunt corecte tastati 'Y' , daca doriti modificarea lor tastati 'N' " << endl;
				cin >> optiune3;
				
				//try
				{
					while (optiune3 != "Y" && optiune3 != "y" && optiune3 != "N" && optiune3 != "n")
					{
						//throw invalid_argument("Optiune invalida ,incercati din nou");
						cout << endl <<"Optiune invalida , va rugam incercati din nou!"<<endl;
						cout << "Va rugam frumos sa verificati datele tocmai introduse,daca sunt corecte tastati 'Y' , daca doriti modificarea lor tastati 'N' " << endl;
						cin >> optiune3;
					}
					if (optiune3 == "Y" || optiune3 == "y")
					{
						cout << "Comanda Inregistrata! Veti primi confirmarea comenzii pe email-ul dvs. " << b1.getEmailclient() << " .O zi frumoasa in continuare!" << endl;
						break;
					}
						
					if (optiune3 == "N" || optiune3 == "n")
						goto eveniment;

				}
				/*catch (invalid_argument& a)
				{
					cout << a.what() << '\n';
				}*/
				getline(cin, optiune1);
			}
			catch (invalid_argument& e)
			{
				cout << e.what() << '\n';
			}


		}
	}
	

	//temporar loc de testare clase,retusarea finala pentru faza 2 :)
	//pe parcursul construirii meniului interactiv cu siguranta voi mai gasi atribute pe care le-as putea utiliza
	/*eveniment e1;
	eveniment e2("fotbal", " 19 decembrie", " 19", " BUCURESTI");
	eveniment e3 = e2;
	e1 = e3;
	cout << e1;

	locbil l1;
	int v[]{ 1,2 };
	int w[]{ 3,4 };
	locbil l2(" peluza", 2, 2, v, w);
	l1 = l2;
	cout << l1<<endl;
	cout << l1.getNrMaxLocuri;
	cout << endl;



	bilete b1;
	bilete b2(50 ,"Yasin", "VIP", "student");
	bilete b3(b2);
	cout << b3;
	bilete b4;
	cin >> b4;
	cout << endl;
	cout << "Afisarea biletului inregistrat cu datele anterioare:" << endl;
	cout << b4;
	bilete b5 = ++b2;//operatorul de pre incrementare creste pretul cu o unitate
	cout << endl;
	cout << b5;*/
	




	return 0;
}