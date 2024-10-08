#ifndef vector_h
#define vector_h

#include <vector>
#include <ostream>

class Vector {
    std::vector<int> items;

    public:
    Vector(): items() {}
    Vector(const Vector& v) : items(v.items) {}
    Vector(size_t length): items(length, 0){}
    
    ~Vector(){}

    // Operateur d'affectation (copie)
    Vector& operator=(const Vector& other);

    // Operateur accès (lecture et écriture)
    int& operator[](size_t index);

    // Operateur accès (lecture seule)
    const int& operator[](size_t index) const;

    // Opérateur de concaténation (+)
    Vector operator+(const Vector& other) const;

    // Opérateur du produit scalaire (*)
    int operator*(const Vector& other) const;

    // Opérateur flux de sotie
    friend std::ostream& operator<<(const std::ostream& os, const Vector& v);

    void push_back(int data){
        items.push_back(data);  
    }

    void pop_back(){
        if (!items.empty()){
            items.pop_back();
        }
    }

    size_t size() const {
        return items.size();
    }
};
#endif