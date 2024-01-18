/** @file */
#include "funkcje.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> odwiedzone;
std::vector<int> droga;
std::vector<int> ostateczna_droga;
float min_koszt= std::numeric_limits<float>::max();
int maks;
float koszt;
params_result odczytaj_argumenty(int ile, const char ** argumenty, std::string & szInput, std::string & szOutput)
{
    const std::string ETYKIETA_INPUT  ("-i");
    const std::string ETYKIETA_OUTPUT ("-o");
    const int    FLAGA_INPUT     = 1;
    const int    FLAGA_OUTPUT    = FLAGA_INPUT << 1;

    const int    POPRAWNY_WYNIK  = FLAGA_INPUT | FLAGA_OUTPUT;
    int wynik = 0;

    for (int i = 1; i < ile - 1; i++)
    {
        std::string arg (argumenty[i]);
        if (arg == ETYKIETA_INPUT)
        {
            szInput = argumenty[i + 1];
            wynik |= FLAGA_INPUT;
        }
        if (arg == ETYKIETA_OUTPUT)
        {
            szOutput = argumenty[i + 1];
            wynik |= FLAGA_OUTPUT;
        }
    }

    if (wynik == POPRAWNY_WYNIK)
        return params_result::PARAMS_OK  ;
    else
        return params_result::PARAMS_ERROR ;
}

int inicjalizacja_vectora(std::string in_file)
{
    std::string wiersz;
    std::fstream plik;
    plik.open(in_file);
    while(std::getline( plik, wiersz ) )
    {
        maks = std::max(maks,int(wiersz[1])-48);
    }
    for (int i = 0; i < maks; ++i) {
    }
    plik.close();

    return maks+1;
}
void inicjalizacja_danych(std::string in_file, std::vector<std::vector<float>> &graf)
{
    std::string wiersz;
    std::fstream plik;
    plik.open(in_file);
    std::string temp;
    std::vector< std::string > temp_vect;

    while (std::getline(plik,wiersz)) {
        std::istringstream iss(wiersz);
        while (getline(iss, temp, ' ')) {
            temp_vect.push_back(temp);
        }

        if(temp_vect[1].substr(1,1) == ">")graf[stoi(temp_vect[0].substr(1))][stoi(temp_vect[2])] = stof(temp_vect[4].substr(0, temp_vect[4].size()));
        else {
            graf[stoi(temp_vect[0].substr(1))][stoi(temp_vect[2])] = stof(temp_vect[4].substr(0, temp_vect[4].size()));
            graf[stoi(temp_vect[2])][stoi(temp_vect[0].substr(1))] = stof(temp_vect[4].substr(0, temp_vect[4].size()));
        }

        temp_vect.clear();
    }
    for (int i = 0; i < row; ++i)odwiedzone.push_back(0);
    odwiedzone[0] = 1;
    droga.push_back(0);
}

void tsp(int miasto,int licznik, std::vector<std::vector<float>> &graf)
{
    if(licznik == 6 && graf[miasto][0] != 0)
    {
        koszt += graf[miasto][0];
        droga.push_back(0);
        for (auto i: droga) std::cout << i << " ";
        std::cout << koszt;
        if(koszt < min_koszt) {ostateczna_droga = droga; min_koszt = koszt;}
        std::cout << std::endl;
        droga.pop_back();
        koszt -= graf[miasto][0];
        return;
    }

    for (int i = 0; i < row; ++i) {
        if (graf[miasto][i] != 0 && odwiedzone[i] != 1)
        {
            koszt += graf[miasto][i];
            odwiedzone[i] = 1;
            droga.push_back(i);
            tsp(i,licznik+1,graf);
            odwiedzone[i] = 0;
            droga.pop_back();
            koszt -= graf[miasto][i];
        }
    }
}