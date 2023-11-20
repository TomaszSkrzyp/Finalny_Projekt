#include<vector>
#include <fstream>
#include<sstream>
#include<string>
#include"head.h"
//#include"create_vec.h"
std::vector<Point> create_vec(std::string input_file) {
    std::vector<Point> vv;
    std::string line;
    std::ifstream input(input_file);
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        double i;
        std::vector<double> v;
        while (ss >> i) {

            v.push_back(i);
        }
        vv.push_back(Point(v));
    }
    return vv;
}