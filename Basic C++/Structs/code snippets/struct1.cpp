
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Point
{
    int x, y, z;
};

Point point{1, 2, 3}; // simple assignment of a struct in one line

int main()
{
    vector<Point> points;
    ifstream pfile("data.txt");
    Point new_pt;
    while (pfile >> new_pt.x >> new_pt.y >> new_pt.z)
    {

        points.push_back(new_pt);
    }
    for (Point p : points)
    {
        cout << p.x << ' ' << p.y << ' ' << p.z << endl;
    }
}
