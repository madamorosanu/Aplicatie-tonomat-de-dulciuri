#include "filerepo.h"
#include <stdexcept>

FileRepository::FileRepository(const std::string& filename) : filename(filename) {
    loadFromFile();
}

void FileRepository::addItem(const Tonomat& item) {
    this->addItem(item);
    saveToFile();
}

void FileRepository::loadFromFile() {
    std::ifstream file(filename);
    file.close();
}

void FileRepository::saveToFile() {
    std::ofstream file(filename);
    file.close();
}
