#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "head.h"
int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "za malo argumentow";
        return 1;
    }
    std::string input_file; std::string output_file; int k; int d; int pkt;

    for (int i = 0; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "-i") {
            input_file = argv[i + 1];
            i++;
        }
        else if (a == "-o") {
            output_file = argv[i + 1];
            i++;
        }
        else   if (a == "-k") {
            std::istringstream iss(argv[i + 1]);
            if ((iss >> k) && iss.eof()) {
                ///the number is right
            }
            else {
                std::cout << "blad w argumencie numer " << i / 2 << "-argument powinien byc liczba";
                return 1;
            }i++;
        }
        else if (a == "-d") {
            std::istringstream iss(argv[i + 1]);
            if ((iss >> d) && iss.eof()) {
                ///the number is right
            }
            else {
                std::cout << "blad w argumencie numer " << i / 2 << "-argument powinien byc liczba";
                return 1;
            }
            i++;
        }
        else   if (a == "-pkt") {
            std::istringstream iss(argv[i + 1]);
            if ((iss >> pkt) && iss.eof()) {
                ///the number is right
            }
            else {
                std::cout << "blad w argumencie numer "<<i/2<<"-argument powinien byc liczba";
                return 1;
            }
            i++;
        }
    }
    std::cout << input_file;
    std::cout << output_file;
    std::cout << k;
    std::cout << d;
    create_data(pkt, d, input_file);

    ///document entity
    /// i love doxygen
    std::vector<Point> Points;
    Points = create_vec(input_file);

    Point p0 = Point({ 1.0,2.0,3.0 });//rob
    Point p1 = Point({ 4.0,2.0,7.0 });//rob

    k_means(&Points, 100, k, pkt, d);
    wyjscie(&Points, k, d, output_file);


    return 0;
}
///.\x64\Debug\FInalny_Projekt.exe -i dataset.txt -o liczby.txt -k 3 -d 2 -pkt 30