#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct coordinates{
    double x;
    double y;
};

void output(vector<coordinates> &rS);
void koch_curve(int i, int n, vector<coordinates> &rS, coordinates instance1, coordinates instance2);
coordinates rotate(coordinates instance3, coordinates instance5);

int main(void){
    int n, i;
    vector<coordinates> S;
    vector<coordinates> &rS = S;
    cin >> n;
    i = 0;
    coordinates instance1, instance2;
    instance1.x = 0;
    instance1.y = 0;
    instance2.x = 100;
    instance2.y = 0;
    rS.push_back(instance1);
    koch_curve(i, n, rS, instance1, instance2);
    rS.push_back(instance2);

    output(rS);

    return 0;
}

void output(vector<coordinates> &rS){
    int size = rS.size();
    for (int i = 0; i < size; i++){
        cout << rS[i].x << " " << rS[i].y << endl;
    }
}

void koch_curve(int i, int n, vector<coordinates> &rS, coordinates instance1, coordinates instance2){
    if (i == n){
        if (instance2.x != 100){
            rS.push_back(instance2);
        }
    }
    else{
        i++;
        coordinates instance3, instance4, instance5;
        instance3.x = (2 * instance1.x + instance2.x) / 3;
        instance3.y = (2 * instance1.y + instance2.y) / 3;
        koch_curve(i, n, rS, instance1, instance3);
        instance5.x = (instance1.x + 2 * instance2.x)/ 3;
        instance5.y = (instance1.y + 2 * instance2.y)/ 3;
        instance4  = rotate(instance3, instance5);
        koch_curve(i, n, rS, instance3, instance4);
        koch_curve(i, n, rS, instance4, instance5);
        koch_curve(i, n, rS, instance5, instance2);
    }
}

coordinates rotate(coordinates instance3, coordinates instance5){
    coordinates instance4, dir_vector;
    dir_vector.x = instance5.x - instance3.x;
    dir_vector.y = instance5.y - instance3.y;
    instance4.x = instance3.x + (1/2 * dir_vector.x - sqrt(3)/2 * dir_vector.y);
    instance4.y = instance3.y + (sqrt(3)/2 * dir_vector.x + 1/2 * dir_vector.y);
    return instance4;
}