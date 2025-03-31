#include "ui.h"
#include "entitate.h"
#include "repo.h"
#include "service.h"
#include "validatori.h"
#include "exceptii.h"
#include<iostream>
using namespace std;

TonomatUi::TonomatUi(ServiceTonomat& service):service(service), optiune(0) {}

void TonomatUi::meniu(){
    do{  cout<<"\n1. Adaugarea unui dulce in lista.\n";
        cout<<"2. Adauga moneda.\n";
        cout<<"3. Afisare lista dulciuri.\n";
        cout<<"4. Cumpara dulce.\n";
        cout<<"5. Modificare dulce.\n";
        cout<<"6. Stergere dulciuri.\n";
        cout<<"7. Generarea unui raport privind stocul de produse.\n";
        cout<<"8. Generarea unui raport privind stocul de monezi.\n";
        cout<<"9. Cele mai cumparate produse.\n";
        cout<<"10. Inchidere aplicatie.\n";
        cout<<"\nAlegeti optiunea:";
        cin>>optiune;

        switch(optiune){
            case 1:
                AdaugaDulciuri();
                break;
            case 2:
                AdaugaMoneda();
                break;
            case 3:
                AfiseazaDulciuri();
                break;
            case 4:
                CumparaDulce();
                break;
            case 5:
                ModificaDulce();
                break;
            case 6:
                StergereDulciuri();
                break;
            case 7:
                RaportStoc();
                break;
            case 8:
                RaportMonezi();
                break;
            case 9:
                CeleMaiCumparateProduse();
                break;
            case 10:
                cout<<"Aplicatia se inchide.\n";
                break;
            default:
                cout<<"Optiune invalida.Reincercati!\n";
        }
    }while(optiune!=10);
}

void TonomatUi::AdaugaDulciuri(){
    int cod, pret, cantitate;
    char* nume=new char[100];
    cout<<"Introduceti codul:";
    cin>>cod;
    cout<<"Introduceti pretul:";
    cin>>pret;
    cin.ignore();
    cout<<"Introduceti numele dulcelui:";
    cin.getline(nume,100);
    cout<<"Introduceti cantitatea de dulciuri:";
    cin>>cantitate;
    Tonomat dulce(cod, pret, nume);
    service.adaugaProdus(dulce, cantitate);
    cout<<"Dulce adaugat!\n";
    delete [] nume;
}
void TonomatUi::AdaugaMoneda(){
    int valoare,numar;
    cout<<"Introduceti valoarea monedei:";
    cin>>valoare;
    cout<<"Introduceti nr de monede:";
    cin>>numar;
    service.adaugaMoneda(valoare, numar);
}
void  TonomatUi::AfiseazaDulciuri(){
    service.afiseazaDulciuri();
}

void TonomatUi::CumparaDulce(){
    int cod,sumaintrodusa;
    cout<<"Introduceti cod pentru dulce:";
    cin>>cod;
    cout<<"Introduceti suma :";
    cin>>sumaintrodusa;
    service.cumparaDulce(cod, sumaintrodusa);
}
void TonomatUi::ModificaDulce(){
    int pret, cod;
    char*  nume=new char[100];
    cout<<"Introduceti codul dulcelui pe care doriti sa il modificati:";
    cin>>cod;
    cout<<"Introduceti noul nume al dulcelui:";
    cin.get();
    cin.getline(nume,100);
    cout<<"Introduceti noul pret al dulcelui:";
    cin>>pret;
    Tonomat tonomat(cod, pret, nume);
    service.modificaDulciuri(cod, pret, nume);
    cout<<"\nDulce modificat!";
    delete [] nume;
}
void TonomatUi::StergereDulciuri() {
    int codProdus;
    cout<<"Introduceti codul produsului de sters:";
    cin>>codProdus;
    service.stergeProdus(codProdus);
}

void TonomatUi::RaportStoc(){
    service.genereazaRaportStoc();
}

void TonomatUi::RaportMonezi(){
    service.genereazaRaportMonezi();
}

void TonomatUi::CeleMaiCumparateProduse(){
    service.celemaiCumparateProduse();
}

