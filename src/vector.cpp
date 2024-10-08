#include "vector.hpp"

Vector Vector::operator+(const Vector& other) const {
    if (this->size() != other.size()){
        throw std::invalid_argument("Vectors does not have the same size. Cannot concatenate.");
    }
    Vector res(this->size());
    for(size_t i = 0; i < this->size(); ++i){
        res[i] = this->items[i] + other.items[i];
    }
    return res;
}

const int& Vector::operator[](size_t index) const{
    if (index >= items.size()){
        throw std::out_of_range("Index out of bounds : " + index);
    }
    return items[index];
}

int& Vector::operator[](size_t index){
    if (index >= items.size()){
        throw std::out_of_range("Index out of bounds : " + index);
    }
    return items[index];
}

Vector& Vector::operator=(const Vector& other){
    if (this != &other){
        items = other.items;
    }
    return *this;
}

int Vector::operator*(const Vector& other) const {
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

std::ostream& operator<<(std::ostream& os, const Vector& v)
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