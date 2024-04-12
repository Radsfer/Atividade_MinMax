#include <iostream>
#include <vector>
#include"RandomVector.hpp"

int main ()
{
    
    srand(time(nullptr));
    std::vector<int> tamanhos = {1000,10000,100000,500000};
   
    for(int n=0;n<tamanhos.size();n++)
    {
    RandomVector test1 =RandomVector(tamanhos[n]);
    RandomVector test2 =RandomVector(tamanhos[n]);
    std::vector <int> vec1Ordered= test1.GenerateOrderedVector();
    std::vector<int> vec2Desordered = test2.GenerateDisorderedVector();

    for(int i=0;i<10;i++)
    {
        test1.FindMinMax1(vec1Ordered);
        test1.setOrderedDurantions(test1.getDurations());
    }
    test1.calculateMeanDurantions();
    test1.saveDurantions("datasets/algOrdenado/tempoAlg1_Ordenado.txt", 1);
    test1.saveInMatrix();
    test1.clearTest();

    for(int i=0;i<10;i++)
    {
    test2.FindMinMax1(vec2Desordered);
    test2.setDisorderedDurantions(test2.getDurations());
    }
    test2.calculateMeanDurantions();
    test2.saveDurantions("datasets/algDesordenado/tempoAlg1_Desordenado.txt", 1);
    test2.saveInMatrix();
    test2.clearTest(); 

    for(int i=0;i<10;i++)
    {
    test1.FindMinMax2(vec1Ordered);
    test1.setOrderedDurantions(test1.getDurations());
    }
    test1.calculateMeanDurantions();
    test1.saveDurantions("datasets/algOrdenado/tempoAlg2_Ordenado.txt", 2);
    test1.saveInMatrix();
    test1.clearTest();

    for(int i=0;i<10;i++)
    {
    test2.FindMinMax2(vec2Desordered);
    test2.setDisorderedDurantions(test2.getDurations());
    }
    test2.calculateMeanDurantions();
    test2.saveDurantions("datasets/algDesordenado/tempoAlg2_Desordenado.txt", 2);
    test2.saveInMatrix();
    test2.clearTest();


    for(int i=0;i<10;i++)
    {
    test1.FindMinMax3(vec1Ordered);
    test1.setOrderedDurantions(test1.getDurations());
    }
    test1.calculateMeanDurantions();
    test1.saveDurantions("datasets/algOrdenado/tempoAlg3_Ordenado.txt", 3);
    test1.saveInMatrix();
    test1.clearTest();

    for(int i=0;i<10;i++)
    {
    test2.FindMinMax3(vec2Desordered);
    test2.setDisorderedDurantions(test2.getDurations());
    }
    test2.calculateMeanDurantions();
    test2.saveDurantions("datasets/algDesordenado/tempoAlg3_Desordenado.txt", 3);
    test2.saveInMatrix();
    test2.clearTest();
    
    test1.saveDurantionsMatrix("datasets/Matrix_Dados/Ordenado_", tamanhos[n]);
    test2.saveDurantionsMatrix("datasets/Matrix_Dados/Desordenado_", tamanhos[n]);
    test1.clearMatrixTest();
    test2.clearMatrixTest();
    }
    return 0;
}
