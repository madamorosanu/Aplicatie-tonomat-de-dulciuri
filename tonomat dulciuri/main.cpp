#include "Repo.h"
#include "ui.h"
#include "teste.h"


int main() {
    RepoTonomat Repo;
    ServiceTonomat service;
    TonomatUi ui(service);
    ui.meniu();

    testAdaugaDulciuri();
    testAfiseazaDulciuri();
    testModificaDulciuri();
    testStergeProdus();
    testCumparaDulce();
    testAdaugaMoneda();
    testRapoarte();
    testCeleMaiCumparateProduse();


    return 0;

}
