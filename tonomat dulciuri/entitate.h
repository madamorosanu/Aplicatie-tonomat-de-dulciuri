#ifndef UNTITLED_ENTITATE_H
#define UNTITLED_ENTITATE_H
class Tonomat{
private:
    int Cod;
    int Pret;
    char* Nume;
public:
    Tonomat();
    Tonomat(int cod, int pret, const char* nume);
    Tonomat(const Tonomat& s);
    ~Tonomat();
    int getCod() const;
    void setCod(int cod);
    int getPret() const;
    void setPret(int pret);
    char *getNume() const;
    void setNume(const char *nume);
    bool operator==(const Tonomat &s) const;
    bool operator!=(const Tonomat &s) const;
    Tonomat& operator=(const Tonomat &s);
};
#endif //UNTITLED_ENTITATE_H
