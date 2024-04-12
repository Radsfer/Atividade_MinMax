#ifndef _RANDOMVECTOR_H_
#define _RANDOMVECTOR_H_

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>
#include <sys/stat.h>


class RandomVector
{
private:
    int size;
    float mean;
    std::vector<float>allDurations;
    std::vector<float>DurationsForOrdered;
    std::vector<float>DurationsForDisordered;
    std::vector<std::vector<float>> MatrixResult;

public:
    RandomVector(int s);
    std::vector<int> GenerateDisorderedVector();
    std::vector<int> GenerateOrderedVector();
    void clearTest();
    void clearMatrixTest();
    void FindMinMax1(std::vector<int>A);
    void FindMinMax2(std::vector<int>A);
    void FindMinMax3(std::vector<int>A);
    void saveInMatrix();
    std::vector<float> getDurations();
    void setOrderedDurantions(std::vector<float>Durations);
    void setDisorderedDurantions(std::vector<float>Durations);
    void calculateMeanDurantions();
    void saveDurantions(std::string filepath,int algNumber);
    void saveDurantionsMatrix(std::string filepath,int algNumber);
    ~RandomVector();
};


#endif
