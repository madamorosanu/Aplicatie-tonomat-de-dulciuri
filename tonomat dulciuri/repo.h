#ifndef UNTITLED_REPO_H
#define UNTITLED_REPO_H
#include "entitate.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class RepoTonomat{
private:
    struct DulceInfo {
        Tonomat produs;
        int quantity;
        int purchaseCount;
    };

    static const int max_dulciuri=100;
    static const int max_monezi=1000;
    int nrdulciuri;
    vector<DulceInfo> dulciuri;
    map<int,int>monezi;

public:
    RepoTonomat();
    ~RepoTonomat();
    void adaugaDulciuri(const Tonomat& dulce, int cantitate);
    void afiseazaDulciuri() const;
    Tonomat* toateDulciurile();
    const map<int, int>* toateMonedele() const;
    void stergeProdus(int codProdus);
    void adaugaMoneda(int valoare, int numar);
    void cumparaDulce(int cod, int sumaIntrodusa);
    void genereazaRaportStoc();
    void genereazaRaportMonezi();
    void modificaDulce(int cod,int pret, char* nume);
    void celeMaiCumparateProduse() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;



};
#endif //UNTITLED_REPO_H
