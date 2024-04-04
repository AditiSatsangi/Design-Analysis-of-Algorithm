
#include <iostream>
#include <vector>
#include <fstream>
#include <random>

std::vector<int> generateRandomArray(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    std::vector<int> randomArray(size);

    for (int i = 0; i < size; ++i) {
        randomArray[i] = distribution(gen);
    }

    return randomArray;
}

void writeArrayToFile(const std::vector<int>& array, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& value : array) {
            outputFile << value << " ";
        }

        outputFile.close();
        std::cout << "Random values written to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the output file." << std::endl;
    }
}

int main() {
    int arraySize = 500000;
    int minValue = 1;
    int maxValue = 100000000;

    std::vector<int> randomArray = generateRandomArray(arraySize, minValue, maxValue);

    // Display a few elements as an example
    std::cout << "Random array between " << minValue << " and " << maxValue << ": ";
    for (int i = 0; i < 10; ++i) {
        std::cout << randomArray[i] << " ";
    }
    std::cout << "..." << std::endl;

    // Write the random values to a file
    writeArrayToFile(randomArray, "f6.txt");

    return 0;
}