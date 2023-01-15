#pragma once
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class bilete
{
private:
	float pret;
	const int idbilet;
	string numeclient;
	string emailclient;
	string zonabilet;
	string categorieclient;
public:
	bilete();
	bilete(float pret, string numeclient,string emailclient, string zonabilet, string categorieclient);
	bilete(const bilete& b);
	bilete& operator=(const bilete& b);
	bilete& operator++();
	int getPret();
	string getNumeclient();
	string getEmailclient();
	string getZonabilet();
	string getCategorieclient();
	int getIdbilet();
	void setNumeclient(string numeclient);
	void setEmailclient(string emailclient);
	void setZonabilet(string zonabilet);
	void setCategorieclient(string zonabilet);
	friend istream& operator>>(istream& in, bilete& b);
	friend ostream& operator<<(ostream& out, bilete b);


};

