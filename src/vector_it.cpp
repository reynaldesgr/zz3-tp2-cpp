#include "vector_it.hpp"

VectorIt VectorIt::operator+(const VectorIt& other) const {
    if (this->size() != other.size()) {
        throw std::invalid_argument("Vectors must have the same size to add them together.");
    }

    VectorIt res(this->size()); 
    
    Iterateur it1 = this->begin();
    Iterateur it2 = other.begin();

    for (size_t i = 0; it1 != this->end() && it2 != other.end(); ++it1, ++it2, ++i) {
        res[i] = *it1 + *it2;  
    }

    return res;
}

const int& VectorIt::operator[](size_t index) const{
    if (index >= items.size()){
        throw std::out_of_range("Index out of bounds : " + index);
    }
    return items[index];
}

int& VectorIt::operator[](size_t index){
    if (index >= items.size()){
        throw std::out_of_range("Index out of bounds : " + index);
    }
    return items[index];
}

VectorIt& VectorIt::operator=(const VectorIt& other){
    if (this != &other){
        items = other.items;
    }
    return *this;
}

int VectorIt::operator*(const VectorIt& other) const {
    if (this->size() != other.size()){
        throw std::invalid_argument("Vectors does not have the same size.");
    }
    int res = 0;
    for (size_t i = 0; i < other.size(); i++)
    {
        res += this->items[i] * other.items[i];
    }

    return res;
}

std::ostream& operator<<(std::ostream& os, const VectorIt& v)
{
    os << "[ ";
    for (size_t i = 0; i < v.size(); i++){
        os << v[i];
        if (i < v.size() - 1){
            os << ", ";
        }
    }
    os << " ]";
    return os;
}