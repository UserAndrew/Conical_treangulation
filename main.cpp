/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

struct Coordinates
{
    double x;
    double y;
    double z;
}coordinates, coordinates_pi, coordinates_pi_plus_one, coordinates_a, coordinates_normal;

Coordinates getCoordinatesPi(double current, double radius, int amount) {
    coordinates.x = radius*cos((2*M_PI*current)/amount);
    coordinates.y = radius*sin((2*M_PI*current)/amount);
    coordinates.z = 0;

    return coordinates;
}

Coordinates getCoordinatesA(double height) {
    coordinates.x = 0;
    coordinates.y = 0;
    coordinates.z = height;
    
    return coordinates;
}

Coordinates getCoordinatesNormal(double ax, double ay, double az,\
                                 double px, double py, double pz,\
                                 double ppox, double ppoy, double ppoz) {
    Coordinates coordinates_vec_a;
    coordinates_vec_a.x = ax - px;
    coordinates_vec_a.y = ay - py;
    coordinates_vec_a.z = az - pz;
    
    Coordinates coordinates_vec_b;
    coordinates_vec_b.x = ppox - px;
    coordinates_vec_b.y = ppoy - py;
    coordinates_vec_b.z = ppoz - pz;  
    
    coordinates_normal.x = coordinates_vec_a.y*coordinates_vec_b.z - coordinates_vec_a.z*coordinates_vec_b.y;
    coordinates_normal.y = (-1)*(coordinates_vec_a.x*coordinates_vec_b.z - coordinates_vec_a.z*coordinates_vec_b.x);
    coordinates_normal.z = coordinates_vec_a.x*coordinates_vec_b.y - coordinates_vec_a.y*coordinates_vec_b.x;
    
    return coordinates_normal;
}

int main()
{
    double H;
    double R;
    int N;
    std::cout << "Введите высоту конуса:" << std::endl;
    std::cin >> H;
    std::cout << "Введите радиус основания конуса:" << std::endl;
    std::cin >> R;
    std::cout << "Введите количество сегментов:" << std::endl;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::cout << "Координаты " << i+1 << "-го треугольника:" << std::endl;
        coordinates_pi = getCoordinatesPi(i, R, N);
        std::cout << "Pi[" << i << "] (" << std::fixed << std::setprecision(2) << coordinates_pi.x << ", " \
        << coordinates_pi.y << ", " << coordinates_pi.z << "), ";
        
        coordinates_a = getCoordinatesA(H);
        std::cout << "A (" << coordinates_a.x << ", " << coordinates_a.y << ", " << coordinates_a.z << "), ";
        
        coordinates_pi_plus_one = getCoordinatesPi(i+1, R, N);
        std::cout << "Pi[" << i+1 << "] (" << coordinates_pi_plus_one.x << ", "\
        << coordinates_pi_plus_one.y << ", " << coordinates_pi_plus_one.z << ")" << std::endl;
        
        getCoordinatesNormal(coordinates_a.x, coordinates_a.y, coordinates_a.z, \
                             coordinates_pi.x, coordinates_pi.y, coordinates_pi.z, \
                             coordinates_pi_plus_one.x, coordinates_pi_plus_one.y, coordinates_pi_plus_one.z);
        
        std::cout << "Координаты нормали в точке P[" << i << "]:" << std::endl;
        std::cout << "N{" << coordinates_normal.x << ", " << coordinates_normal.y << ", " << coordinates_normal.z << "}" << std::endl;
        
    }
}
