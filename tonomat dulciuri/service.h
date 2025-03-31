#ifndef UNTITLED_SERVICE_H
#define UNTITLED_SERVICE_H
#include "repo.h"
#include "entitate.h"
#include<iostream>
#include <cstring>
#include<vector>
#include <stack>
using namespace std;

class ServiceTonomat {
private:
    RepoTonomat repo;
public:
    ServiceTonomat();
    ~ServiceTonomat();
    void adaugaProdus(const Tonomat& produs, int cantitate);
    void stergeProdus(int codProdus);
    void cumparaDulce(int codProdus, int sumaIntrodusa);
    void adaugaMoneda(int valoare, int numar);
    void genereazaRaportStoc();
    void genereazaRaportMonezi();
    void celemaiCumparateProduse();
    void  afiseazaDulciuri();
    void  modificaDulciuri(int cod, int pret, char* nume);

};
#endif //UNTITLED_SERVICE_H
