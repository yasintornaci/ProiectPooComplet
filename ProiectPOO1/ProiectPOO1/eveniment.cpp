#include "eveniment.h";
#include <string>
#include <iostream>
#include<fstream>
using namespace std;

eveniment::eveniment() : idEv(0) {  //constructor implicit//
	tipEv = nullptr;
	dataEv = "";
	oraEv = "";
	locatieEv = "";
}

eveniment::eveniment(const char* tipEv, string dataEv, string oraEv, string locatieEv) : idEv(idEv)  //constructor cu parametrii//
{
	if (tipEv != nullptr)
	{
		this->tipEv = new char[strlen(tipEv) + 1];
		strcpy_s(this->tipEv, strlen(tipEv) + 1, tipEv);
	}
	else
	{
		this->tipEv = nullptr;
	}
	this->dataEv = dataEv;
	this->oraEv = oraEv;
	this->locatieEv = locatieEv;

}
eveniment::eveniment(const eveniment& e) : idEv(e.idEv)   //constructor de copiere//
{
	if (e.tipEv != nullptr)
	{
		this->tipEv = new char[strlen(e.tipEv) + 1];
		strcpy_s(this->tipEv, strlen(e.tipEv) + 1, e.tipEv);
	}
	else
	{
		this->tipEv = nullptr;
	}
	this->dataEv = e.dataEv;
	this->oraEv = e.oraEv;
	this->locatieEv = e.locatieEv;

}
eveniment::~eveniment()    //destructor//
{
	if (this->tipEv != nullptr)
	{
		delete[] this->tipEv;
	}
}

eveniment& eveniment::operator=(const eveniment& e)
{
	if (this != &e)
	{
		if (e.tipEv != nullptr)
		{
			if (tipEv != nullptr)
			{
				delete[] tipEv;
			}

			this->tipEv = new char[strlen(e.tipEv) + 1];
			strcpy_s(this->tipEv, strlen(e.tipEv) + 1, e.tipEv);
		}
		this->dataEv = e.dataEv;
		this->oraEv = e.oraEv;
		this->locatieEv = e.locatieEv;
	}
	return *this;
}

string eveniment::getOraEv()
{
	return this->oraEv;
}

string eveniment::getDataEv()
{
	return this->dataEv;
}

string eveniment::getLocatieEv()
{
	return this->locatieEv;
}

//metoda virtuala

int eveniment::ora_Maxima_Final_Eveniment()
{
	return stoi(getOraEv()) + 2;
}

void eveniment::setTipEv(const char* tipEv)
{
	if (tipEv != nullptr)
	{
		if (this->tipEv != nullptr)
		{
			delete[] this->tipEv;
		}
		this->tipEv = new char[strlen(tipEv) + 1];
		strcpy_s(this->tipEv, strlen(tipEv) + 1, tipEv);
	}
}

char* eveniment::getTipEv() {
	if (tipEv != nullptr)
	{
		char* copy = new char[strlen(tipEv) + 1];
		strcpy_s(copy, strlen(tipEv) + 1, tipEv);
		return copy;
	}
	return nullptr;
}

string eveniment::getTipEvAsString()
{
	string copie = tipEv;
	return copie;
}

char& eveniment::operator[](int index)
{
	if (tipEv != nullptr && index >= 0 && index < strlen(tipEv))
	{
		return tipEv[index];
	}
	else
		return charInvalid;
}


istream& operator>>(istream& in, eveniment& e)
{
	cout << "Evenimentul la care doriti sa participati:"<<endl<<"Daca numele evenimentului are mai multe cuvinte,"<<endl<<"va rugam sa legati cuvintele cu ajutorul simbolului '_'   :";
	string buffer;
	in >> buffer;
	e.setTipEv(buffer.c_str());
	cout << endl;
	cout << "Data la care doriti sa participati la eveniment: \n(introduceti data pe modelul urmator : '12.09.2023') :";
	in >> ws;
	getline(in, e.dataEv);
	cout << endl;
	cout << "Ora la care doriti sa participati la eveniment"<<endl<<"(ora se considera fixa, ex. 18) : " ;
	in >> e.oraEv;
	cout << endl;
	cout << "Locatia unde doriti sa participati la eveniment: ";
	in >> ws;
	getline(in, e.locatieEv);
	cout << endl;

	return in;
}

ostream& operator<<(ostream& out, eveniment e)
{
	out << "Evenimentul la care doriti sa participati:       ";
	if (e.tipEv != nullptr)
	{
		out << e.tipEv;
	}
	out << endl;
	out << "Data la care doriti sa participati la eveniment: " << e.dataEv << endl;
	out << "Ora la care doriti sa participati la eveniment : " << e.oraEv << endl;
	out << "Locatia unde doriti sa participati la eveniment: " << e.locatieEv << endl;
	return out;
}

ofstream& operator<<(ofstream& f, eveniment e)
{
	if (e.tipEv != nullptr)
	{
		f << e.tipEv << endl;
	}
	f << e.dataEv << endl;
	f << e.oraEv << endl;
	f << e.locatieEv << endl;
	return f;
}

/*ifstream& operator>>(ifstream& f, eveniment e)
{
	if (e.tipEv != nullptr)
	{
		f >> e.tipEv;
	}
	getline(f, e.dataEv);
	getline(f,e.oraEv);
	getline(f,e.locatieEv);
	return f;
}*/

string eveniment::taraEv = "Romania";
char eveniment::charInvalid = -1;





