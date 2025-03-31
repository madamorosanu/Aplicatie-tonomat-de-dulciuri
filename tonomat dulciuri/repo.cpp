#include "repo.h"
#include "entitate.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;


//constructor
RepoTonomat::RepoTonomat() {
    nrdulciuri=0;
}

RepoTonomat::~RepoTonomat(){}

void RepoTonomat::adaugaDulciuri(const Tonomat& produs, int cantitate){
    for (auto& dulceInfo : dulciuri) {
        if (dulceInfo.produs.getCod() == produs.getCod()) {
            dulceInfo.quantity+= cantitate;
            return;
        }
    }
    DulceInfo newDulceInfo = { produs, cantitate };
    dulciuri.push_back(newDulceInfo);
    nrdulciuri++;
}
Tonomat* RepoTonomat::toateDulciurile(){
    Tonomat* dulciuriArray = new Tonomat[dulciuri.size()];
    for (size_t i = 0; i < dulciuri.size(); ++i) {
        dulciuriArray[i] = dulciuri[i].produs;
    }
    return dulciuriArray;
}

const map<int, int>* RepoTonomat::toateMonedele() const {
    return &monezi;
}
//afiseaza cheltuieli
void RepoTonomat::afiseazaDulciuri() const{
    for (const auto& d : dulciuri) {
        cout << "Dulcele cu codul " << d.produs.getCod() << " si numele: " << d.produs.getNume()
             << " are pretul de " << d.produs.getPret() << " RON si cantitatea de " << d.quantity << ".\n";
    }
}
//adaugamonezi
void RepoTonomat::adaugaMoneda(int valoare, int numar) {
    monezi[valoare] += numar;
}

void RepoTonomat::cumparaDulce(int cod, int sumaIntrodusa){
    DulceInfo* dulceCumparat = nullptr;
    for ( auto& dulce : dulciuri) {
        if (dulce.produs.getCod() == cod) {
            dulceCumparat = &dulce;
            break;
        }
    }

    // Verifică dacă produsul există
    if (dulceCumparat == nullptr) {
        cout << "Produsul nu exista.\n";
        return;
    }

    // Verifică suma introdusă
    if (sumaIntrodusa < dulceCumparat->produs.getPret()) {
        cout << "Suma introdusa este insuficienta.\n";
        return;
    }

    // Calculează restul
    int rest = sumaIntrodusa - dulceCumparat->produs.getPret();

    // Verifică dacă tonomatul poate oferi restul
    for (const auto& moneda : monezi) {
        int cantitateUtilizata = min(rest / moneda.first, moneda.second);
        rest -= cantitateUtilizata * moneda.first;
    }

    // Dacă restul este diferit de zero, tonomatul nu poate oferi rest
    if (rest > 0) {
        cout << "Tonomatul nu poate da rest.\n";
        return;
    }

    // Scade monezile necesare pentru rest
    for (auto& moneda : monezi) {
        int cantitateUtilizata = min((sumaIntrodusa - dulceCumparat->produs.getPret()) / moneda.first, moneda.second);
        monezi[moneda.first] -= cantitateUtilizata;
        rest -= cantitateUtilizata * moneda.first;
    }

    dulceCumparat->quantity--;
    dulceCumparat->purchaseCount++;

    if (dulceCumparat->quantity == 0) {
        auto it = remove_if(dulciuri.begin(), dulciuri.end(), [cod](const DulceInfo& di) {
            return di.produs.getCod() == cod;
        });
        dulciuri.erase(it, dulciuri.end());
        nrdulciuri--;
    }

    // Afisează mesajul de achiziționare și restul
    cout << "Ai cumparat " << dulceCumparat->produs.getNume() << ". Restul tau: " << sumaIntrodusa - dulceCumparat->produs.getPret() << " RON.\n";
}


void RepoTonomat::modificaDulce(int cod, int pret, char* nume) {
    bool modificat=false;
    for (auto&dulce:dulciuri) {
        if (dulce.produs.getCod() == cod) {
            dulce.produs.setPret(pret);
            dulce.produs.setNume(nume);
            modificat = true;
        }
    }

    if(!modificat){
        cout << "Nu s-a gasit dulce cu codul " <<cod << endl;}
}

void RepoTonomat::stergeProdus(int codProdus) {
    auto it = find_if(dulciuri.begin(), dulciuri.end(), [codProdus](const DulceInfo& di) {
        return di.produs.getCod() == codProdus;
    });

    if (it != dulciuri.end()) {
        if (distance(it, dulciuri.end()) == 1) {
            dulciuri.pop_back();
        } else {
            *it = dulciuri.back();
            dulciuri.pop_back();
        }
        nrdulciuri--;
        cout << "Produs sters cu succes.\n";
    } else {
        cout << "Produsul nu exista.\n";
    }
}

// Generarea unui raport privind stocul de produse
void RepoTonomat::genereazaRaportStoc() {
    cout << "Stocul curent de produse:\n";
    for (const auto& dulce : dulciuri) {
        cout << "Cod: " << dulce.produs.getCod() << ", Nume: " << dulce.produs.getNume() << ", Pret: " << dulce.produs.getPret() << " RON\n";
    }
}

// Generarea unui raport privind stocul de monezi
void RepoTonomat::genereazaRaportMonezi() {
    cout << "Stocul curent de monezi:\n";
    for (const auto& moneda : monezi) {
        cout << "Valoare: " << moneda.first << " RON, Numar: " << moneda.second << "\n";
    }
}
void RepoTonomat::celeMaiCumparateProduse() const {
    if (dulciuri.empty()) {
        cout << "Nu exista produse in tonomat.\n";
        return;
    }

    auto max_purchase_count = max_element(dulciuri.begin(), dulciuri.end(), [](const DulceInfo& a, const DulceInfo& b) {
        return a.purchaseCount < b.purchaseCount;
    })->purchaseCount;

    cout << "Cele mai cumparate produse:\n";
    for (const auto& dulce : dulciuri) {
        if (dulce.purchaseCount == max_purchase_count) {
            cout << "Cod: " << dulce.produs.getCod() << ", Nume: " << dulce.produs.getNume() << ", Cumparat de " << dulce.purchaseCount << " ori\n";
        }
    }
}
void RepoTonomat::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nu am putut deschide fișierul " << filename << " pentru citire.\n";
        return;
    }

    int cod;
    int pret;
    std::string nume;
    int cantitate;

    while (file >> cod >> nume >> pret >> cantitate) {
        Tonomat produs(cod, pret, nume.c_str());
        adaugaDulciuri(produs, cantitate);
    }

    file.close();
}
void RepoTonomat::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nu am putut deschide fișierul " << filename << " pentru scriere.\n";
        return;
    }

    for (const auto& dulce : dulciuri) {
        file << dulce.produs.getCod() << " " << dulce.produs.getNume() << " " << dulce.produs.getPret() << " " << dulce.quantity << "\n";
    }

    file.close();
}








