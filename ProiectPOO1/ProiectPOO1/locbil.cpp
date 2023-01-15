#include "locbil.h"
#include <string>
#include <iostream>
#include<fstream>
using namespace std;


locbil::locbil()
{
	zona = "";
	nrRand = 0;
	nrCol = 0;
	randScaun = nullptr;
	colScaun = nullptr;
}

locbil::locbil(string zona, int nrRand, int nrCol, int* randScaun, int* colScaun)
{
	this->zona = zona;
	if (randScaun != nullptr && nrRand > 0)
	{
		this->randScaun = new int[nrRand];
		for (int i = 0; i < nrRand; i++)
		{
			this->randScaun[i] = randScaun[i];
		}
		this->nrRand = nrRand;
	}
	else
	{
		this->randScaun = nullptr;
		this->nrRand = 0;
	}

	if (colScaun != nullptr && nrCol > 0)
	{
		this->colScaun = new int[nrCol];
		for (int i = 0; i < nrCol; i++)
		{
			this->colScaun[i] = colScaun[i];
		}
		this->nrCol = nrCol;
	}
	else
	{
		this->colScaun = nullptr;
		this->nrCol = 0;
	}

}

locbil::locbil(const locbil& l)
{
	this->zona = l.zona;
	if (l.randScaun != nullptr && l.nrRand > 0)
	{
		this->randScaun = new int[l.nrRand];
		for (int i = 0; i < l.nrRand; i++)
		{
			this->randScaun[i] = l.randScaun[i];
		}
		this->nrRand = l.nrRand;
	}
	else
	{
		this->randScaun = nullptr;
		this->nrRand = 0;
	}

	if (l.colScaun != nullptr && l.nrCol > 0)
	{
		this->colScaun = new int[l.nrCol];
		for (int i = 0; i < l.nrCol; i++)
		{
			this->colScaun[i] = l.colScaun[i];
		}
		this->nrCol = l.nrCol;
	}
	else
	{
		this->colScaun = nullptr;
		this->nrCol = 0;
	}
}

locbil::~locbil()
{
	if (this->randScaun != nullptr)
	{
		delete[] this->randScaun;
	}

	if (this->colScaun != nullptr)
	{
		delete[] this->colScaun;
	}
}

locbil& locbil::operator=(const locbil& l)
{
	if (this != &l)
	{
		if (this->randScaun != nullptr)
		{
			delete[] this->randScaun;

		}
		if (l.randScaun != nullptr && l.nrRand > 0)
		{
			this->randScaun = new int[l.nrRand];
			for (int i = 0; i < l.nrRand; i++)
			{
				this->randScaun[i] = l.randScaun[i];
			}
			this->nrRand = l.nrRand;
		}
		else
		{
			this->randScaun = nullptr;
			this->nrRand = 0;
		}

		if (this->colScaun != nullptr)
		{
			delete[] this->colScaun;

		}
		if (l.colScaun != nullptr && l.nrCol > 0)
		{
			this->colScaun = new int[l.nrCol];
			for (int i = 0; i < l.nrCol; i++)
			{
				this->colScaun[i] = l.colScaun[i];
			}
			this->nrCol = l.nrCol;
		}
		else
		{
			this->colScaun = nullptr;
			this->nrCol = 0;
		}

	}
	return *this;
}

int locbil::getNrRand() {
	return nrRand;
}

int* locbil::getRandScaun()
{
	if (randScaun != nullptr)
	{
		int* copy = new int[nrRand];
		for (int i = 0; i < nrRand; i++) {
			copy[i] = randScaun[i];
		}
		return copy;
	}
	else return nullptr;
}

int locbil::getRandScaun(int index) {
	if (index >= 0 && index < nrRand) {
		return randScaun[index];
	}
}
/////////////////////////

int locbil::getNrCol() {
	return nrCol;
}

int* locbil::getColScaun()
{
	if (colScaun != nullptr)
	{
		int* copy = new int[nrCol];
		for (int i = 0; i < nrCol; i++) {
			copy[i] = colScaun[i];
		}
		return copy;
	}
	else return nullptr;
}

int locbil::getColScaun(int index) {
	if (index >= 0 && index < nrCol) {
		return colScaun[index];
	}
}
////////////////////////

void locbil::setRandScaun(int* randScaun, int nrRand) {
	if (randScaun != nullptr && nrRand > 0) {
		delete[] this->randScaun;
		this->randScaun = new int[nrRand];
		for (int i = 0; i < nrRand; i++) {
			this->randScaun[i] = randScaun[i];
		}
		this->nrRand = nrRand;
	}
}

void locbil::setColScaun(int* colScaun, int nrCol) {
	if (colScaun != nullptr && nrCol > 0) {
		delete[] this->colScaun;
		this->colScaun = new int[nrCol];
		for (int i = 0; i < nrCol; i++) {
			this->colScaun[i] = colScaun[i];
		}
		this->nrCol = nrCol;
	}
}
void locbil::setNrMaxLocuri(int nrMaxLocuri)
{
	locbil::nrMaxLocuri = nrMaxLocuri;
}

int locbil::getNrMaxLocuri()
{
	return nrMaxLocuri;
}


void locbil::serialize()
{
	ofstream f("locbil.bin", ios::binary);
	short dim = this->zona.length();
	f.write((char*)&dim, sizeof(dim));
	f.write(zona.c_str(), dim + 1);
	f.write((char*)&nrRand, sizeof(nrRand));
	for (int i = 0; i < nrRand; i++)
	{
		f.write((char*)&randScaun[i], sizeof(randScaun[i]));
	}
	for (int i = 0; i < nrRand; i++)
	{
		f.write((char*)&colScaun[i], sizeof(colScaun[i]));
	}
	f.close();
}


void locbil::deserialize()
{
	ifstream f("locbil.bin", ios::binary);
	short dim = 0;
	f.read((char*)&dim, sizeof(dim));
	char* n = new char[dim + 1];
	f.read(n, dim + 1);
	zona = n;
	delete[] n;
	f.read((char*)&nrRand, sizeof(nrRand));
	delete[] randScaun;
	randScaun = new int[nrRand];
	delete[] colScaun;
	colScaun = new int[nrRand];
	for (int i = 0; i < nrRand; i++)
	{
		f.read((char*)&randScaun[i], sizeof(randScaun[i]));
	}
	for (int i = 0; i < nrRand; i++)
	{
		f.read((char*)&colScaun[i], sizeof(colScaun[i]));
	}
	f.close();
}


ostream& operator<<(ostream& out, locbil l)
{
	
	out << "Numarul de bilete comandate: " << l.nrRand << endl;
	out << "Locurile achizitionate de dvs. : "<<endl<<endl;
	for (int i = 0; i < l.nrRand; i++)
	{
		out << i+1 << ". " << "Randul " << l.randScaun[i] << ", coloana " << l.colScaun[i] << endl;
	}

	/*for (int i = 0; i < l.nrRand; i++)
	{
		out << l.randScaun[i] << " ";
	}
	out << endl;
	out << "Nr coloane: " << l.nrCol << endl;
	out << "Coloane: ";
	for (int i = 0; i < l.nrCol; i++)
	{
		out << l.colScaun[i] << " ";
	}
	out << endl;*/

	return out;
}

istream& operator>>(istream& in, locbil& l)
{

	cout << "Numarul de bilete pe care doriti sa le cumparati: ";
	string nrRand2;
	getline(in, nrRand2);
	l.nrRand = stoi(nrRand2);
	cout << endl;


	if (l.randScaun != nullptr)
	{
		delete[] l.randScaun;
		l.randScaun = nullptr;
	}
	l.nrCol = l.nrRand;
	if (l.colScaun != nullptr)
	{
		delete[] l.colScaun;
		l.colScaun = nullptr;
	}

	l.colScaun = new int[l.nrCol];
	l.randScaun = new int[l.nrRand];
	if (l.nrRand == 1)
	{
		cout << "Randul pe care doriti sa stati: ";
		for (int i = 0; i < l.nrRand; i++)
		{
			cout << i + 1 << ".";
			in >> l.randScaun[i];
			cout << endl;
		}
		cout << endl;
		cout << "Coloana pe care doriti sa stati: "<<endl;
		for (int i = 0; i < l.nrCol; i++)
		{
			cout << i+1 << ".";
			in >> l.colScaun[i];
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Randurile pe care doriti sa stati \n(primul rand introdus este randul primului bilet,al doilea rand introdus randul celui de-al doilea bilet)  :" << endl;
		for (int i = 0; i < l.nrRand; i++)
		{
			cout << i+1 << ".";
			in >> l.randScaun[i];
			cout << endl;
		}
		cout << endl;
		cout << "Coloanele pe care doriti sa stati: \n(prima coloana introdusa este coloana primului bilet,a doua coloana introdusa este coloana celui de-al doilea bilet)"<<endl;
		for (int i = 0; i < l.nrCol; i++)
		{
			cout << i+1 << ".";
			in >> l.colScaun[i];
			cout << endl;
		}
		cout << endl;
	}
	/*cout << "Nr coloane: ";
	in >> l.nrCol;

	if (l.colScaun != nullptr)
	{
		delete[] l.colScaun;
		l.colScaun = nullptr;
	}

	l.colScaun = new int[l.nrCol];
	cout << "Coloane: ";
	for (int i = 0; i < l.nrCol; i++)
	{
		in >> l.colScaun[i];
	}
	*/
	return in;
}
int locbil::nrMaxLocuri = 10000;


















