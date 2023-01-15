#include "bilete.h"
#include <string>
#include<iostream>
#include<cstdlib>
using namespace std;


bilete::bilete() : idbilet(0)
{
	pret = 0;
	numeclient = "";
	emailclient = "";
	zonabilet = "";
	categorieclient = "";
}



bilete::bilete(float pret, string numeclient,string emailclient, string zonabilet,string categorieclient) : idbilet(idbilet)
{
	this->pret = pret;
	this->numeclient = numeclient;
	this->emailclient = emailclient;
	this->zonabilet = zonabilet;
	this->categorieclient = categorieclient;
}



bilete::bilete(const bilete& b) : idbilet(b.idbilet)
{
	this->pret = b.pret;
	this->numeclient = b.numeclient;
	this->emailclient = emailclient;
	this->zonabilet = b.zonabilet;
	this->categorieclient = b.categorieclient;
}


bilete& bilete::operator=(const bilete& b)
{
	if (this != &b)
	{
		this->pret = b.pret;
		this->numeclient = b.numeclient;
		this->emailclient = emailclient;
		this->zonabilet = b.zonabilet;
		this->categorieclient = b.categorieclient;
	}
	return *this;
}

bilete& bilete::operator++()
{
	this->pret = this->pret + 1;
	return *this;
}

int bilete::getPret()
{
	return this->pret;
}


string bilete::getNumeclient()
{
	return this->numeclient;
}

string bilete::getEmailclient()
{
	return this->emailclient;
}

string bilete::getZonabilet()
{
	return this->zonabilet;
}

string bilete::getCategorieclient()
{
	return this->categorieclient;
}

int bilete::getIdbilet()
{
	return idbilet;
}


void bilete::setNumeclient(string numeclient)
{
	this->numeclient = numeclient;

}

void bilete::setEmailclient(string emailclient)
{
	this->emailclient = emailclient;
}

void bilete::setZonabilet(string zonabilet)
{
	this->zonabilet = zonabilet;

}

void bilete::setCategorieclient(string zonabilet)
{
	this->zonabilet = zonabilet;
}


istream& operator>>(istream& in, bilete& b)
{
	cout << "Nume client : ";
	in >> ws;
	getline(in, b.numeclient);
	cout << endl;
	cout << "Email-ul dvs. : ";
	in >> b.emailclient;
	int ok = 0;
	for (int i = 0; i < b.emailclient.length(); i++)
	{
		if (b.emailclient[i] == '@')
			ok = 1;
	}
	if (ok == 0)
	{
		throw invalid_argument("email");
	}
	cout << endl;
	cout << "Categorie client ( introduceti doar una dintre urmatoarele :copil/student/adult/pensionar): ";
	//in >> b.categorieclient;
	getline(in, b.categorieclient);
	getline(in, b.categorieclient);
	if (strcmp(b.categorieclient.c_str(), "copil") != 0 && strcmp(b.categorieclient.c_str(), "student") != 0 && strcmp(b.categorieclient.c_str(), "adult") != 0 && strcmp(b.categorieclient.c_str(), "pensionar") != 0)
	//if(b.categorieclient!="copil" && b.categorieclient != "student" && b.categorieclient != "adult" && b.categorieclient != "pensionar")
		throw invalid_argument("categorie");
	cout << endl;
	cout << "Zona unde doriti bilet ( introduceti doar una dintre urmatoarele :peluza/tribuna/loja/VIP): ";
	getline(in, b.zonabilet);
	if (strcmp(b.zonabilet.c_str(), "peluza") != 0 && strcmp(b.zonabilet.c_str(), "tribuna") != 0 && strcmp(b.zonabilet.c_str(), "loja") != 0 && strcmp(b.zonabilet.c_str(), "VIP") != 0)
		throw invalid_argument("zona");
	cout << endl;
	cout << "Pretul biletului pe care-l doriti: ";
	string pret2;
	getline(in, pret2);
	b.pret = stof(pret2);
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, bilete b)
{
	out << "Numele clientului: " << b.numeclient << endl;
	//out << "Email-ul clientului: " << b.emailclient << endl;
	out << "Categoria clientului: " << b.categorieclient << endl;
	out << "Pretul unui singur bilet: " << b.pret << endl;
	out << "Zona unde va veti aseza: " << b.zonabilet << endl;
	//out << "ID bilet: " << 10000000*b.pret+10000* << endl;


	out << endl;
	return out;
};






