#ifndef _RANDOMVECTOR_H_
#define _RANDOMVECTOR_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <ios>




class RandomVector
{
private:
    int size;
    std::vector<float>allDurations;
    std::vector<float>DurationsForOrdered;
    std::vector<float>DurationsForDisordered;

public:
    RandomVector(int s);
    std::vector<int> GenerateDisorderedVector();
    std::vector<int> GenerateOrderedVector();
    void clearTest();
    void FindMinMax1(std::vector<int>A);
    void FindMinMax2(std::vector<int>A);
    void FindMinMax3(std::vector<int>A);
    std::vector<float> getDurations();
    void setOrderedDurantions(std::vector<float>Durations);
    void setDisorderedDurantions(std::vector<float>Durations);
    void saveDurantions(std::string filepath,int algNumber);
    ~RandomVector();
};


#endif
