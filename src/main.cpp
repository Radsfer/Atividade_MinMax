#include <iostream>
#include"RandomVector.hpp"

#define SIZE 1000

int main ()
{
    
    srand(time(nullptr));

    RandomVector test1 =RandomVector(SIZE);
    RandomVector test2 =RandomVector(SIZE);

    std::vector <int> vec1Ordered= test1.GenerateOrderedVector();
    std::vector<int> vec2Desordered = test2.GenerateDisorderedVector();
    test1.FindMinMax1(vec1Ordered);
    test1.setOrderedDurantions(test1.getDurations());
    test1.saveDurantions("tempo_Ordenado.txt", 0);
    test1.clearTest();

    test2.FindMinMax1(vec2Desordered);
    test2.setDisorderedDurantions(test2.getDurations());
    test2.saveDurantions("tempo_Desordenado.txt", 0);
    test2.clearTest(); 

    test1.FindMinMax2(vec1Ordered);
    test1.setOrderedDurantions(test1.getDurations());
    test1.saveDurantions("tempo_Ordenado.txt", 1);
    test1.clearTest();

    test2.FindMinMax2(vec2Desordered);
    test2.setDisorderedDurantions(test2.getDurations());
    test2.saveDurantions("tempo_Desordenado.txt", 1);
    test2.clearTest();


    test1.FindMinMax3(vec1Ordered);
    test1.setOrderedDurantions(test1.getDurations());
    test1.saveDurantions("tempo_Ordenado.txt", 2);
    test1.clearTest();

    test2.FindMinMax3(vec2Desordered);
    test2.setDisorderedDurantions(test2.getDurations());
    test2.saveDurantions("tempo_Desordenado.txt", 2);
    test2.clearTest();

    return 0;
}
