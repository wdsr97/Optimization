#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data() {}
    Data(std::vector <std::vector <int> > adjacencyMatrix);
    // friend void Chromossome::updateFitness();
    void displayInfo();
private:
    std::vector <std::vector <int> > adjacencyMatrix;
};

#endif
