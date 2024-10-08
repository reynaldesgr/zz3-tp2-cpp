#include <cmath>
#include <iostream>

#include "cartesien.hpp"
#include "polaire.hpp"

Cartesien::Cartesien(const Polaire& p) {
    p.convertir(*this);
}

void Cartesien::afficher() const {
    afficher(std::cout);
}

void Cartesien::afficher(std::ostream& stream) const
{
    stream << "(x=" << x << ";y=" << y << ")";
}

std::ostream& operator<<(std::ostream& stream, Point const & p){
    p.afficher(stream);
    return stream;
}


void Cartesien::convertir(Polaire& p) const
{
    p.setAngle(std::atan2(y, x) * 180 / M_PI);
    p.setDistance(std::hypot(x, y));
} 

void Cartesien::convertir(Cartesien& c) const {
    c.setX(x);
    c.setY(y);
}



