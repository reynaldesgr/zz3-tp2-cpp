#ifndef point_h
#define point_h

#include <sstream>

class Cartesien;
class Polaire;

class Point {
    public: 
        virtual ~Point() = default;
        virtual void afficher() const = 0;
        virtual void afficher(std::ostream& stream) const = 0;

        virtual void convertir(Cartesien& c) const = 0;
        virtual void convertir(Polaire& p) const = 0;
};

std::ostream& operator<<(std::ostream& stream, Point const & p);

#endif                                              