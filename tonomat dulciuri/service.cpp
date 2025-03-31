#include "service.h"
#include "entitate.h"
#include "repo.h"

// Constructor
ServiceTonomat::ServiceTonomat() {}

// Destructor
ServiceTonomat::~ServiceTonomat() {}

// Metoda pentru adaugarea unui produs nou
void ServiceTonomat::adaugaProdus(const Tonomat& produs, int cantitate) {
    repo.adaugaDulciuri(produs, cantitate);
}

// Metoda pentru stergerea unui produs existent
void ServiceTonomat::stergeProdus(int codProdus) {
    repo.stergeProdus(codProdus);
}

// Metoda pentru achizitionarea unui produs
void ServiceTonomat::cumparaDulce(int codProdus, int sumaIntrodusa) {
    repo.cumparaDulce(codProdus, sumaIntrodusa);
}


// Metoda pentru adaugarea de monede in tonomat
void ServiceTonomat::adaugaMoneda(int valoare, int numar) {
    repo.adaugaMoneda(valoare, numar);
}

// Metoda pentru generarea unui raport privind stocul de produse
void ServiceTonomat::genereazaRaportStoc() {
    repo.genereazaRaportStoc();
}

// Metoda pentru generarea unui raport privind stocul de monezi
void ServiceTonomat::genereazaRaportMonezi() {
    repo.genereazaRaportMonezi();
}
void ServiceTonomat:: celemaiCumparateProduse(){
    repo.celeMaiCumparateProduse();
}
void ServiceTonomat:: afiseazaDulciuri(){
    repo.afiseazaDulciuri();
}
void ServiceTonomat:: modificaDulciuri(int cod, int pret, char* nume){
    repo.modificaDulce( cod, pret ,  nume);
}
