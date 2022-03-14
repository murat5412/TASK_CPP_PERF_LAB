#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    float centr_circle_X, centr_circle_Y, radius_circle,
        coordinates_point_X, coordinates_point_Y;

    //Считывание данных окружности в переменные
    ifstream fin;
    fin.open("circle", ios_base::in);
    if (fin.is_open()) {
        fin >> centr_circle_X;
        fin >> centr_circle_Y;
        fin >> radius_circle;
    }
    else {
        cout << "Error with the file.";
    }
    fin.close();

    ofstream fout;
    fout.open("answers");

    fin.open("points");
    if (fin.is_open()) {
        while (!fin.eof()) {
            fin >> coordinates_point_X >> coordinates_point_Y;
            if (pow(coordinates_point_X - centr_circle_X, 2) + 
                pow(coordinates_point_Y - centr_circle_Y, 2) == pow(radius_circle,2)) {
                fout << 0 <<endl;
            }
            else if (pow(coordinates_point_X - centr_circle_X, 2) +
                pow(coordinates_point_Y - centr_circle_Y, 2) < pow(radius_circle, 2)) {
                fout << 1 << endl;
            }
            else {
                fout << 2 << endl;
            }
        }
    }
    else {
        cout << "Error with the file.";
    }

    fout.close();

    return 0;
}