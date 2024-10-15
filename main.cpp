#include <iostream>
#include <vector>
#include <cmath>

void printN(std::vector<std::vector<int>> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << '[';
        for (int j = 0; j < v[i].size(); j++){
            std::cout << v[i][j];
            if (j != v[i].size()-1){
                std::cout << ", ";
            }
        }
        std::cout << ']';
        if (i != v.size()-1){
            std::cout << ", ";
        }
    }
}

bool getIndexes(std::vector<int> &indexes, const int &mod){
    for (int i = indexes.size()-1; i >= 0; i--){
        if (indexes[i] < i+mod-indexes.size()){
            indexes[i]+=1;
            for (i; i < indexes.size()-1; i++){
                indexes[i+1] = indexes[i]+1;
            }
            return 1;
        }
    }
    return 0;
}

std::vector<std::vector<int>> getCombinations(const int &size){
    int numberOfCombinations = 1;
    std::vector<std::vector<int>> combinations;
    if (size == 0) return combinations;
    combinations.push_back(std::vector<int>(1, 0));
    while (numberOfCombinations <= size){
        std::vector<int> indexes(numberOfCombinations, 0);
        while (getIndexes(indexes, size)){
            std::vector<int> combination;
            for (int i = 0; i < numberOfCombinations; i++){
                combination.push_back(indexes[i]);
            }
            combinations.push_back(combination);
        }
        numberOfCombinations++;
    }
    return combinations;
}

int main(){
    std::cout << "Enter the size: ";
    int size;
    std::cin >> size;
    printN(getCombinations(size));
}