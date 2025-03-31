#ifndef UNTITLED_UI_H
#define UNTITLED_UI_H
#include "repo.h"
#include "service.h"
#include "validatori.h"
#include "exceptii.h"

class TonomatUi{
private:
    ServiceTonomat& service;
    int optiune;
public:
    TonomatUi(ServiceTonomat& service);
    void meniu();
    void AdaugaDulciuri();
    void AdaugaMoneda();
    void AfiseazaDulciuri();
    void CumparaDulce();
    void ModificaDulce();
    void StergereDulciuri();
    void RaportStoc();
    void RaportMonezi();
    void CeleMaiCumparateProduse();
};
#endif //UNTITLED_UI_H
