/** @file */
#include <iostream>
#include <vector>
#include "funkcje.h"
#include <fstream>

int row;

int main(int argc, const char ** argv) {
    std::string in_file, out_file;
    if(odczytaj_argumenty(argc, argv, in_file, out_file) != PARAMS_OK)
    {        std::cout << "Nieprawidlowe parametry wywolania programu. Prosze o okresleniu pliku z danymi za pomoca flagi -i oraz pliku wyjsciowego za pomoca flagi -o" << std::endl;
        return 0;
    }


    row = inicjalizacja_vectora(in_file);
    std::vector<std::vector<float>> graf(row,std::vector<float>(row));


    inicjalizacja_danych(in_file,graf);
//    for (int i = 0; i < graf.size(); ++i) {
//        for (int j = 0; j < graf.size(); ++j) {
//            std::cout << graf[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
    tsp(0,1,graf);


    std::ofstream output(out_file);
    for (auto i:ostateczna_droga) {
        output << i << " ";
    }
    output <<std::endl<<  min_koszt;
    //output << wynik << " " << koszt;
    output.close();



    return 0;
}


