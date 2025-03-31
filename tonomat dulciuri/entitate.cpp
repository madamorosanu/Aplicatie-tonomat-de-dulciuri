#include "entitate.h"
#include<iostream>
#include<cstring>
using namespace std;
//constructor
Tonomat::Tonomat(){
    Cod=001;
    Pret=0;
    Nume = nullptr;
}
//constructor cu parametri
Tonomat::Tonomat(int cod, int pret, const char* nume){
    Cod = cod;
    Pret=pret;
    if (nume != nullptr) {
        Nume = new char[strlen(nume) + 1];
        strcpy(Nume, nume);
    } else {
        Nume = nullptr;
    }
}

//constructor copiere
Tonomat::Tonomat(const Tonomat& s){
    Nume=new char[strlen(s.Nume)+1];
    strcpy_s(Nume, sizeof(Nume), s.Nume);
    Cod=s.Cod;
    Pret=s.Pret;
}
//destructor

Tonomat::~Tonomat(){
    if(Nume){
        delete[] Nume;
        Nume= nullptr;
    }
}

int Tonomat::getCod() const {
    return Cod;
}

void Tonomat::setCod(int cod) {
    Cod = cod;
}

int Tonomat::getPret() const {
    return Pret;
}

void Tonomat::setPret(int pret) {
    Pret = pret;
}

char *Tonomat::getNume() const {
    return Nume;
}

void Tonomat::setNume(const char *nume) {
    if(Nume){
        delete[] Nume;
        Nume= nullptr;
    }
    Nume = new char[strlen(nume)+1];
    strcpy(Nume,nume);
}

bool Tonomat::operator==(const Tonomat &s) const {
    return Cod == s.Cod &&
           Pret == s.Pret &&
           strcmp(Nume, s.Nume) == 0;
}

bool Tonomat::operator!=(const Tonomat &s) const {
    return !(s == *this);
}

Tonomat& Tonomat::operator=(const Tonomat &s)  {
    if (this != &s) {
        this->setCod(s.Cod);
        this->setPret(s.Pret);
        this->setNume(s.Nume);
        return *this;
    }
}
