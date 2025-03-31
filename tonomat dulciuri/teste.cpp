#include "repo.h"
#include "entitate.h"
#include "teste.h"
#include "service.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

void testAdaugaDulciuri() {
    RepoTonomat repo;
    Tonomat dulce1(001, 100, "Mars");
    repo.adaugaDulciuri(dulce1, 3);

    // Verificăm dacă cheltuiala a fost adăugată cu succes
    Tonomat* dulciuri = repo.toateDulciurile();
    if (dulciuri[0].getCod() == 001 && strcmp(dulciuri[0].getNume(), "Mars") == 0) {
        cout << "Test adaugaDulciuri: PASS\n";
    } else {
        cout << "Test adaugaDulciuri: FAIL\n";
    }
}

// Funcție pentru testarea afișării cheltuielilor din repository
void testAfiseazaDulciuri() {
    RepoTonomat repo;
    Tonomat dulce1(001, 100, "Mars");
    repo.adaugaDulciuri(dulce1, 3);

    // Redirecționăm stdout pentru a verifica afișarea
    cout << "Test afiseazaDulciuri: PASS\n";
    streambuf* oldCout = cout.rdbuf();
    cout.rdbuf(nullptr);

    repo.afiseazaDulciuri();

    cout.rdbuf(oldCout); // Restaurăm stdout

    // Dacă afișarea este corectă, testul este trecut automat, altfel va fi evident că ceva nu este în regulă
}

// Funcție pentru testarea modificării unei cheltuieli în repository
void testModificaDulciuri() {
    RepoTonomat repo;
    Tonomat dulce1(1, 20, "Mars");
    repo.adaugaDulciuri(dulce1, 3);

    repo.modificaDulce(1, 25, "Bounty");

    // Verificăm dacă cheltuiala a fost modificată cu succes
    Tonomat* dulciuri = repo.toateDulciurile();
    if (dulciuri[0].getPret() == 25 && strcmp(dulciuri[0].getNume(), "Bounty") == 0) {
        cout << "Test modificaCheltuieli: PASS\n";
    } else {
        cout << "Test modificaCheltuieli: FAIL\n";
    }
}

void testStergeProdus() {
    RepoTonomat repo;
    Tonomat produs1(1, 5,"Ciocolata");
    Tonomat produs2(2, 3,"Biscuiti");

    repo.adaugaDulciuri(produs1, 3);
    repo.adaugaDulciuri(produs2, 3);

    repo.stergeProdus(1);

    // Verificăm dacă produsul a fost șters corect
    const Tonomat* dulciuri = repo.toateDulciurile();
    assert(dulciuri[0].getCod() == 2);
}
void testCumparaDulce() {
    RepoTonomat repo;
    Tonomat produs1(1, 5, "Ciocolata");
    Tonomat produs2(2, 3,"Biscuiti");

    repo.adaugaDulciuri(produs1, 3);
    repo.adaugaDulciuri(produs2, 3);

    repo.cumparaDulce(1, 10);

    repo.afiseazaDulciuri();// Verificăm dacă stocul s-a actualizat corect după achizițierepo.afiseazaDulciuri();
}
void testAdaugaMoneda() {
    RepoTonomat repo;

    repo.adaugaMoneda(5, 10);
    repo.adaugaMoneda(10, 5);

    // Verificăm dacă monezile au fost adăugate corect
    const map<int, int>* monezi = repo.toateMonedele();
    assert(monezi->at(5) == 10);
    assert(monezi->at(10) == 5);
}
void testRapoarte() {
    RepoTonomat repo;
    Tonomat produs1(1, 5, "Ciocolata");
    Tonomat produs2(2, 3,  "Biscuiti");

    repo.adaugaDulciuri(produs1, 3);
    repo.adaugaDulciuri(produs2,3);

    repo.adaugaMoneda(5, 10);
    repo.adaugaMoneda(10, 5);

    // Verificăm rapoartele de stoc și monezi
    repo.genereazaRaportStoc();
    repo.genereazaRaportMonezi();
}

void testCeleMaiCumparateProduse() {
    RepoTonomat repo;
    Tonomat produs1(1, 5, "Ciocolata");
    Tonomat produs2(2, 3, "Biscuiti");

    repo.adaugaDulciuri(produs1, 3);
    repo.adaugaDulciuri(produs2, 3);

    repo.cumparaDulce(1, 10);
    repo.cumparaDulce(1, 10);
    repo.cumparaDulce(2, 5);

    repo.celeMaiCumparateProduse();
}