#include <cmath>
#include <iostream>
#include <typeinfo>

#include "polaire.hpp"
#include "cartesien.hpp"

Polaire::Polaire(const Cartesien& c){
    c.convertir(*this);
}

double Polaire::getAngle() const
{
    return theta;
}

double Polaire::getDistance() const
{
    return dist;
}

void Polaire::setAngle(double a){
    theta = a;
}

void Polaire::setDistance(double d)
{
    dist = d;
}

void Polaire::afficher() const
{
    afficher(std::cout);
}

void Polaire::afficher(std::ostream& stream) const
{
    stream << "(a=" <<  theta << ";d=" << dist << ")";
}

void Polaire::convertir(Cartesien& c) const
{
    c.setX(dist * std::cos(theta * M_PI / 180));
    c.setY(dist * std::sin(theta * M_PI / 180));
}

void Polaire::convertir(Polaire& p) const 
{
    p.setAngle(theta);
    p.setDistance(dist);
}