#ifndef UNTITLED_FILEREPO_H
#define UNTITLED_FILEREPO_H

#include "repo.h"
#include "entitate.h"
#include <fstream>
#include <string>

class FileRepository :
public RepoTonomat{
private:
    std::string filename; //  salvare/citire
    void loadFromFile(); //  încărcarea datelor din fișier
    void saveToFile() ;   //  salvarea datelor în fișier

public:
    FileRepository(const std::string& filename);
    void addItem(const Tonomat& item);
};



#endif //UNTITLED_FILEREPO_H
