#ifndef vector_it_h 
#define vector_it_h

#include <vector>
#include <iostream>
#include <stdexcept>

class VectorIt {
    std::vector<int> items;
    public:
        VectorIt(): items() {}
        VectorIt(const VectorIt& v): items(v.items){}
        VectorIt(size_t length): items(length, 0){}
        
        ~VectorIt(){}

        void push_back(int data) { items.push_back(data); }
        void pop_back(){ if (!items.empty()) { items.pop_back(); }}

        size_t size() const { return items.size(); }

        // Iterateur class
        class Iterateur {
            // Déclaration amicale pour que VectorIt puisse accéder à l'itérateur
            friend class VectorIt;

            private:
                VectorIt& vector;
                size_t index;

                Iterateur(VectorIt& v, size_t idx): vector(v), index(idx){}
            
            public:

                Iterateur& operator++(){
                    ++index;
                    return *this;
                }

                Iterateur operator++(int){
                    Iterateur temp = *this;
                    ++index;
                    return temp;
                }

                int operator*() const {
                    return vector.items[index];
                }

                bool operator==(const Iterateur& other) const {
                    return index == other.index && &vector == &other.vector;
                }

                bool operator!=(const Iterateur& other) const {
                    return !(*this == other);
                }
        };

    
    Iterateur begin() {
        return Iterateur(*this, 0);
    }

    Iterateur end() {
        return Iterateur(*this, items.size());
    }

    // Const versions (for const objects)
    Iterateur begin() const {
        return Iterateur(const_cast<VectorIt&>(*this), 0);
    }

    Iterateur end() const {
        return Iterateur(const_cast<VectorIt&>(*this), items.size());
    }
    

    // Operateur d'affectation (copie)
    VectorIt& operator=(const VectorIt& other);

    // Operateur accès (lecture et écriture)
    int& operator[](size_t index);

    // Operateur accès (lecture seule)
    const int& operator[](size_t index) const;

    // Opérateur de concaténation (+)
    VectorIt operator+(const VectorIt& other) const;

    // Opérateur du produit scalaire (*)
    int operator*(const VectorIt& other) const;

    // Opérateur flux de sotie
    friend std::ostream& operator<<(const std::ostream& os, const VectorIt& v);
};

#endif