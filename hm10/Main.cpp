#include <iostream>
#include <iomanip>
#include <limits>

void inputArray(int* array, int size) {
    std::cout << "Enter elements of the array (separated by space): ";
    for (int i = 0; i < size; ++i) {
        while (true) {
            std::cin >> array[i];
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter an integer: ";
            }
            else {
                break;
            }
        }
    }
}

double findMax(int* array, int size) {
    double max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

double findMin(int* array, int size) {
    double min = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < min) min = array[i];
    }
    return min;
}

double findAvg(int* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) sum += array[i];
    return sum / size;
}

double Action(int* array, int size, double (*func)(int*, int)) {
    return func(array, size);
}

void processArray(int* array, int size, char name) {
    int choice;
    std::cout << "Select action for array " << name << ": 1 for max, 2 for min, 3 for avg: ";
    std::cin >> choice;

    switch (choice) {
    case 1: std::cout << "Max value in array " << name << ": " << Action(array, size, findMax) << std::endl; break;
    case 2: std::cout << "Min value in array " << name << ": " << Action(array, size, findMin) << std::endl; break;
    case 3: std::cout << "Average value in array " << name << ": " << std::fixed << std::setprecision(2) << Action(array, size, findAvg) << std::endl; break;
    default: std::cout << "Invalid choice" << std::endl; break;
    }
}

int main() {
    int sizeA, sizeB;

    std::cout << "Enter the size of array A: ";
    std::cin >> sizeA;
    int* arrayA = new int[sizeA];
    inputArray(arrayA, sizeA);
    processArray(arrayA, sizeA, 'A');

    std::cout << "Enter the size of array B: ";
    std::cin >> sizeB;
    int* arrayB = new int[sizeB];
    inputArray(arrayB, sizeB);
    processArray(arrayB, sizeB, 'B');

    delete[] arrayA;
    delete[] arrayB;

    return 0;
}
