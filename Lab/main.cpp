#include <iostream>
#include "point.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Point pt1("city_1", 1.23, 2.34);
    pt1.allPrint();

    Point pt2("city_2", 3.45, 4.56);
    pt2.allPrint();

    // wylicza odleglosc pomiedzy dwoma punktami
    cout << "Odleglosc pomiedzy pt1 i pt2: " << pointDist(pt1, pt2) << "\n\n";

    // zmienia imie point'a
    pt1.changeName("city_3");
    pt1.allPrint();

    // przesuwa punkt o podane wartosci
    pt1.movePoint(-1.23, -2.34);
    pt1.allPrint();

    // zapisuje do pustego point'a wszpolrzedne
    // punktu pomiedzy pt1 i pt2 
    Point pt3;
    pt3.allPrint();
    pt3.inTheMiddle(pt1, pt2, "mid_city");
    pt3.allPrint();

    // szuka punkt o mniejszej odleglosci od pt3
    cout << "Blizej jest " << closestFrom(pt1, pt2, pt3);
    
    return 0;
}

/* OUTPUT

    Point city_1 ma wspolrzedne x: 1.23 oraz y: 2.34

    Point city_2 ma wspolrzedne x: 3.45 oraz y: 4.56

    Odleglosc pomiedzy pt1 i pt2: 3.13955

    Point city_3 ma wspolrzedne x: 1.23 oraz y: 2.34

    Point city_3 ma wspolrzedne x: 0 oraz y: 0

    Point unknown ma wspolrzedne x: 0 oraz y: 0

    Point mid_city ma wspolrzedne x: 1.725 oraz y: 2.28

    Blizej jest Pierwszy

*/