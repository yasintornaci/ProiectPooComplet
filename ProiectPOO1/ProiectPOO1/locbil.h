#pragma once
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class locbil
{
private:

	string zona;
	int nrRand;
	int nrCol;
	int* randScaun;
	int* colScaun;
	static int nrMaxLocuri;


public:
	locbil();
	locbil(string zona, int nrRand, int nrCol, int* randScaun, int* colScaun);
	locbil(const locbil& l);
	~locbil();
	locbil& operator=(const locbil& l);
	int getNrRand();
	int* getRandScaun();
	int getRandScaun(int index);
	int getNrCol();
	int* getColScaun();
	int getColScaun(int index);
	void setRandScaun(int* randScaun, int nrRand);
	void setColScaun(int* colScaun, int nrCol);
	static void setNrMaxLocuri(int nrMaxLocuri);
	static int getNrMaxLocuri();
	void serialize();
	void deserialize();
	friend ostream& operator<<(ostream& out, locbil l);
	friend istream& operator>>(istream& in, locbil& l);

};


