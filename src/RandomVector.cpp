#include "RandomVector.hpp"

RandomVector::RandomVector(int s)
{
    this->size = s;
}
std::vector<int> RandomVector::GenerateOrderedVector()
{
    int aux=0;
    std::vector<int> numeros(size);
    for (int i = 0; i < size; i++)
    {
      
       if(aux<1000)
        {
        numeros[i] = aux + 1;
        }else
        {
            aux=0;
        }
        aux++;
    }

    return numeros;
}

std::vector<int> RandomVector::GenerateDisorderedVector()
{
    std::vector<int> numeros(size);
    for (int i = 0; i < size; ++i)
    {
        numeros[i] = rand() % 1001;
    }
    return numeros;
}
void RandomVector::FindMinMax1(std::vector<int> A)
{
    int Max, Min;
    auto start = std::chrono::steady_clock::now();
    Max = A[0];
    Min = A[0];

    for (int i = 1; i < size; i++)
    {
        if (Max < A[i])
        {
            Max = A[i];
        }

        if (Min > A[i])
        {
            Min = A[i];
        }
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Valor Máximo Encontrado: " << Max << std::endl;
    std::cout << "Valor Mínimo Encontrado: " << Min << std::endl;
    float nanoseconds = duration.count() * 1.0e-6f;
    std::cout << "Tempo do algoritmo: " << nanoseconds << "ns" << std::endl;
    this->allDurations.push_back(nanoseconds);
}

void RandomVector::FindMinMax2(std::vector<int> A)
{
    int Max, Min;
    auto start = std::chrono::steady_clock::now();
    Max = A[0];
    Min = A[0];

    for (int i = 1; i < size; i++)
    {
        if (A[i] > Max)
        {
            Max = A[i];
        }
        else if (A[i] < Min)
        {
            Min = A[i];
        }
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Valor Máximo Encontrado: " << Max << std::endl;
    std::cout << "Valor Mínimo Encontrado: " << Min << std::endl;

    float nanoseconds = duration.count() * 1.0e-6f;
    std::cout << "Tempo do algoritmo: " << nanoseconds << "ns" << std::endl;
    this->allDurations.push_back(nanoseconds);
}

void RandomVector::FindMinMax3(std::vector<int> A)
{
    int Max, Min, fimDoAnel, i;
    auto start = std::chrono::steady_clock::now();
     
    if (size % 2 > 0)
    {
        A[size + 1] = A[size];
        fimDoAnel = size;
    }
    else
    {
        fimDoAnel = size - 1;
    }
    if (A[0] > A[1])
    {
        Max = A[0];
        Min = A[1];
    }
    else
    {
        Max = A[1];
        Min = A[0];
    }
    i = 2;
    while (i <= fimDoAnel)
    {
        if (A[i] > A[i + 1])
        {
            if(A[i]>Max)
            {
                Max=A[i];
            }
            if(A[i+1]<Min)
            {
                Min=A[i+1];
            }
        }
        else
        {
            if(A[i+1]>Max)
            {
                Max=A[i+1];
            }
            if(A[i]<Min)
            {
                Min=A[i];
            }
        }
        i = i + 2;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Valor Máximo Encontrado: " << Max << std::endl;
    std::cout << "Valor Mínimo Encontrado: " << Min << std::endl;

    float nanoseconds = duration.count() * 1.0e-6f;
    std::cout << "Tempo do algoritmo: " << nanoseconds << "ns" << std::endl;
    this->allDurations.push_back(nanoseconds);
}

std::vector<float> RandomVector::getDurations()
{
    return allDurations;
}

void RandomVector::saveInMatrix()
{

    if(DurationsForDisordered.size()>0)
    {
      MatrixResult.push_back(DurationsForDisordered);
          
    }else if(DurationsForOrdered.size()>0)
    {
      MatrixResult.push_back(DurationsForOrdered);
   }else
    {
        return;
    }
}

void RandomVector::setOrderedDurantions(std::vector<float>durations)
{
    int size = durations.size();
    for (int i=0; i<size;i++)
    {
        this->DurationsForOrdered.push_back(durations[i]);
    }
    allDurations.clear();
}

void RandomVector::setDisorderedDurantions(std::vector<float>durations)
{
    int size = durations.size();
    for (int i=0; i<size;i++)
    {
        this->DurationsForDisordered.push_back(durations[i]);
    }
    allDurations.clear();
}
void RandomVector::calculateMeanDurantions()
{
     float sizeDisordered=DurationsForDisordered.size();
     float sizeOrdered=DurationsForOrdered.size();

     float aux=0.0;
 
     if(sizeDisordered>0)
    {

            for(int i=0;i<sizeDisordered;i++)
            {
                aux+=DurationsForDisordered[i];
            }
        this->mean=aux/sizeDisordered;
    }else if(sizeOrdered>0)
    {
            for(int i=0;i<sizeOrdered;i++)
            {
                aux+=DurationsForOrdered[i];
            }
        this->mean=aux/sizeOrdered;
    }else
    {
        this->mean=0.0;
        return;
    }

}
void RandomVector::saveDurantions(std::string filepath, int algNumber)
{
    std::ofstream file(filepath, std::ios::app);
    std::string nameCase;
    size_t position1= filepath.find("_");
    size_t position2= filepath.find(".",position1);
    if(position1 != std::string::npos && position2 != std::string::npos)
    {
        nameCase= filepath.substr(position1+1,(position2-position1-1));
    }else
    {
    std::cerr<<"Erro ao pegar o nome do caso"<< std::endl;
    return;
    }
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return;
    }
    file<< "----------------------------------------------\n";
    file<< "Para o caso: "<<nameCase<<"\n";
    file<< "Tamanho do vetor: "<< size<<"\n";
    file<< "Algoritmo: "<< algNumber<<"\n";
    file<< "Média: "<< mean <<"\n";
    file<< "Duração em nano segundos: \n";
    if(nameCase=="Ordenado")
    {
        int size= DurationsForOrdered.size();
        for (int i=0;i<size; i++)
        {
            file<<DurationsForOrdered[i]<<"\n";
        }
    }else
    {
        int size= DurationsForDisordered.size();
        for (int i=0;i<size; i++)
        {
            file<<DurationsForDisordered[i]<<"\n";
        }

    }
    file<< "----------------------------------------------\n";

    file.close();
    chmod(filepath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);

}

void RandomVector::saveDurantionsMatrix(std::string filepath, int algNumber)
{
    std::string name=filepath+std::to_string(algNumber)+".txt";
     std::ofstream file(name);

    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return;
    }
    
    for(int i=0;i<MatrixResult[0].size();i++)
    {
        for (int j=0;j<MatrixResult.size();j++)
        {
        file<<MatrixResult[j][i]<<" ";
        }
        file<<"\n";
    }
    file.close();
    chmod(filepath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);

    
}

void RandomVector::clearTest()
{
    allDurations.clear();
    DurationsForOrdered.clear();
    DurationsForDisordered.clear();
}
void RandomVector::clearMatrixTest()
{
    MatrixResult.clear();
}
RandomVector::~RandomVector()
{
    allDurations.clear();
    DurationsForOrdered.clear();
    DurationsForDisordered.clear();
    MatrixResult.clear();
};
