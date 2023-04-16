#include<bits/stdc++.h>
using namespace std;

const int N=0;

#define ll long long
#define ld long double

class Car {
private:
    string make;
    string model;
    int year;
    int speed_x;
    int speed_y;
    int speed_z;
    int x;
    int y;
    int z;

public:
    
    Car(string make, string model, int year, int speed_x, int speed_y, int speed_z, int x, int y, int z) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->speed_x = speed_x;
        this->speed_y = speed_y;
        this->speed_z = speed_z;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    //To increase speed_x according to the given increment.
    void accelerate_x(int speed_increment) {
        this->speed_x += speed_increment;
    }

    //To increase speed_y according to the given increment.
    void accelerate_y(int speed_increment) {
        this->speed_y += speed_increment;
    }
    
    //To increase speed_z according to the given increment.
    void accelerate_z(int fly_speed_increment) {
        this->speed_z += fly_speed_increment;
    }
    
    //To determine speed_x after brake is applied.
    void brake_x(int speed_decrement) {
        this->speed_x -= speed_decrement;
    }

    //To determine speed_y after brake is applied.
    void brake_y(int speed_decrement) {
        this->speed_y -= speed_decrement;
    }
    
    //To determine speed_z after brake is applied.
    void brake_z(int speed_decrement) {
        this->speed_z -= speed_decrement;
    }
    
    //Takes the time and updates the car's position after that time.
    void move(int time) {
        this->x += speed_x*time;
        this->y += speed_y*time;
        this->z += speed_z*time;
    }

    //Detects whether collision will occur.
    bool detect_collision(Car car2) {
        int dx = this->x - car2.x;
        int dy = this->y - car2.y;
        int dz = this->z - car2.z;
        if (dx == 0 && dy == 0 && dz == 0) { 
            return true;
        }
        else {
            return false;
        }
    }

    //Finds the time it will take for two cars to collide.
    double time_to_collision(Car car2) {
        double rel_speed_x = speed_x - car2.speed_x;
        double rel_speed_y = speed_y - car2.speed_y;
        double rel_speed_z = speed_z - car2.speed_z;
        double dist_x = car2.x - x;
        double dist_y = car2.y - y;
        double dist_z = car2.z - z;
        if ((dist_x/rel_speed_x)==(dist_y/rel_speed_y) && (dist_y/rel_speed_y)==(dist_z/rel_speed_z)){
            return (dist_y/rel_speed_y);
        }
        else return -1;
    }
};

int main() {
    Car car1("Rolls Royce", "Ghost", 2022, 0, 1, 2, 100, 100, 100);
    Car car2("Aston Martin", "Valkyrie", 2021, 3, 3, 3, 85, 90, 95);
    
    double ttc = car1.time_to_collision(car2);
    if (ttc >= 0) {
        cout << "Time to collision: " << ttc << " seconds" << endl;
    }
    else {
        cout << "Will not collide" << endl;
    }
    car1.move(5);
    car2.move(5);
    if(car1.detect_collision(car2)){
        cout<<"Colloided"<<endl;
    }
    return 0;
}