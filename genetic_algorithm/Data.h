#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data(int** adjacencyMatrix);
    friend void Chromossome::updateFitness();
private:
    int** adjacencyMatrix;
};

#endif
