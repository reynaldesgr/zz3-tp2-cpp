#ifndef nuage_h
#define nuage_h

#include <vector>
#include <cstddef>
#include <iostream>

#include <cartesien.hpp>
#include <polaire.hpp>

class Cartesien;
class Polaire;

template <typename T>
class Nuage {
    std::vector<T> points;

    public:
        void ajouter(const T& point);

        typedef typename std::vector<T>::iterator iterator;
        typedef typename std::vector<T>::const_iterator const_iterator;

        typename std::vector<T>::iterator begin();
        typename std::vector<T>::iterator end();

        typename std::vector<T>::const_iterator begin() const;
        typename std::vector<T>::const_iterator end() const;

        // void afficher() const;

        std::size_t size() const;
};


template <typename T>
void Nuage<T>::ajouter(const T& point)
{
    points.push_back(point);
}

template <typename T>
typename std::vector<T>::iterator Nuage<T>::begin()
{
    return points.begin();
}

template <typename T>
typename std::vector<T>::iterator Nuage<T>::end()
{
    return points.end();
}

template <typename T>
typename std::vector<T>::const_iterator Nuage<T>::begin() const
{
    return points.begin();
}

template <typename T>
typename std::vector<T>::const_iterator Nuage<T>::end() const
{
    return points.end();
}

template <typename T>
std::size_t Nuage<T>::size() const {
    return points.size();
}

template <typename T>
T barycentre_v1(Nuage<T> nuage) {
    Cartesien sum(0,0); 
    double nb_points = nuage.size();

    for (const T& point : nuage) {
        Cartesien temp(point); 
        point.convertir(temp);  

        sum.setX(sum.getX() + temp.getX());
        sum.setY(sum.getY() + temp.getY());
    }

    if (nuage.size() > 0)
    {
        sum.setX(sum.getX() / nb_points);
        sum.setY(sum.getY() / nb_points); 
    }

    if constexpr (std::is_same<T, Cartesien>::value) {
        return sum;
    } 
    // constexpr : mot-clé (C++11 : indique que certaines valeurs/fonctions peuvent être évaluées lors de la compilation)
    else if constexpr (std::is_same<T, Polaire>::value) {
        Polaire barycentre_polaire;
        sum.convertir(barycentre_polaire);  

        std::cout << barycentre_polaire << std::endl;
        return barycentre_polaire;
    }

}

// Specialized Function Implementation 
template <>
Polaire barycentre_v1<Polaire>(Nuage<Polaire> nuage) {
    double sum_distance = 0.0;
    double sum_angle = 0.0;

    if (nuage.size() == 0) {
        return Polaire(sum_distance, sum_angle); 
        // Aucun point, retourner l'origine
    }

    size_t nb_points = nuage.size();

    for (const Polaire& point : nuage) {
        sum_distance += point.getDistance();
        sum_angle += point.getAngle();
    }

    // Créer le barycentre en polaire
    Polaire barycentre;
    barycentre.setDistance(sum_distance / nb_points);
    barycentre.setAngle(sum_angle / nb_points);

    return barycentre;
}

template <typename C>
auto barycentre_v2(const C& nuage) {
    using T = typename C::value_type;

    if (nuage.empty()) {
        if constexpr (std::is_same<T, Cartesien>::value) {
            return Cartesien(0, 0); // Renvoie (0, 0) pour les coordonnées cartésiennes
        } else if constexpr (std::is_same<T, Polaire>::value) {
            return Polaire(0, 0); // Renvoie (0, 0) pour les coordonnées polaires
        }
    }

    Cartesien sum(0, 0); 
    double nb_points = 0;

    // Itération sur les points dans le conteneur
    for (const T& point : nuage) {
        Cartesien temp; 
        point.convertir(temp);  // Convertir directement le point en Cartesien

        sum.setX(sum.getX() + temp.getX());
        sum.setY(sum.getY() + temp.getY());
        nb_points++;
    }

    // Calcul de la moyenne
    if (nb_points > 0) {
        sum.setX(sum.getX() / nb_points);
        sum.setY(sum.getY() / nb_points); 
    }

    // Retourner le barycentre selon le type
    if constexpr (std::is_same<T, Cartesien>::value) {
        return sum; // Retourne le barycentre en coordonnées cartésiennes
    } 
    else if constexpr (std::is_same<T, Polaire>::value) {
        Polaire barycentre_polaire;
        sum.convertir(barycentre_polaire);  // Convertir le barycentre cartésien en polaire

        return barycentre_polaire; // Retourne le barycentre en coordonnées polaires
    }
}
#endif