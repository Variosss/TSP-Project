/** @file */
//
// Created by Jakub Grąbka on 10/12/2022.
//

#ifndef KURIER_FUNKCJE_H
#define KURIER_FUNKCJE_H
#include <vector>
#include <algorithm>
#include <string>
enum params_result
{
    PARAMS_OK,     ///< poprawne wywołanie programu
    PARAMS_ERROR   ///< niepoprawne parametry wywołania programu
};
params_result odczytaj_argumenty(int ile, const char ** argumenty, std::string & szInput, std::string & szOutput);
/** Funkcja która inicjalizuje vectora
 * @param in_file argument funkcji, plik wejściowy
 * @return maksymalna numer miasta.
 */

int inicjalizacja_vectora(std::string in_file);
/** Funkcja która pobiera z pliku wejściowego danę o odległości pomiędzy drogami następnie wrzuca te dane do vektora
 * @param in_file plik wejściowy
 * @param graf vector do którego chcemy wrzucić danę.
 */
void inicjalizacja_danych(std::string in_file,std::vector<std::vector<float>> &graf);

/** Funkcja itteruje po każdym sąsiedzie i jeżeli jest on poprawny tzn. nie został odwiedzony oraz jest sąsiadem aktualnego miasta idzie do niego i wywołuje rekurencje, jeżeli funkcja odwiedzi wszystkie miasta sprawdza czy może wrócić do miasta startowego jeśli tak, to dodaje koszt do miasta 0 i sprawdza czy koszt jest najmniejszy.
 * @param miasto aktualne miasto
 * @param licznik ile miast odwiedzliśmy
 * @param graf vector z odległościami
 */
void tsp(int miasto,int licznik, std::vector<std::vector<float>> &graf);

extern int row;
extern float koszt, min_koszt;
extern std::vector<int>ostateczna_droga;


#endif //KURIER_FUNKCJE_H