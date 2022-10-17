#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <ctime>
//using namespace std;

void BubbleSort(std::vector<int> vec, int size)//size, 
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

//std::optional *time* clockFunc(std::function)
//[](){}

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector <int> vec1;//list
    std::vector <int> vec2;
    double size, count;
    srand(time(0));
    std::cout << "Введите размер вектора:\n";
    std::cin >> size;
    while (size != int(size) || std::cin.fail()) {//c style cast, or-
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        std::cout << "Ошибка! Введите правильное число:\n";
        std::cin >> size;
    }
    std::cout << "Введите значения\n";
    for (int i = 0; i < size; i++) {
        count = rand();
        /*while (cin.fail()) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
            }
            cout << "Ошибка! Введите правильное число:" << endl;
            cin >> count;
        }*/
        vec1.push_back(count);
        vec2.push_back(count);//-
    }
    auto begin = std::chrono::steady_clock::now();
    BubbleSort(vec1, size);
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);//binary search
    std::cout << "Сортировка пузырьком\nВремя выполнения: " << duration.count() << " мкрсек\n";
    begin = std::chrono::steady_clock::now();
    sort(vec1.begin(), vec1.end());
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "Сортировка sort\nВремя выполнения: " << duration.count() << " мкрсек\n";
    for (int i = 0; i < size; i++) {
        std::cout << vec1[i] << " ";
    }
    return 0;
}
