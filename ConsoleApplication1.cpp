#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <ctime>
#include <functional>
#include <string>
//using namespace std;

void BubbleSort(std::vector<int> vec)//size, 
{
    int temp;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

// *time* clockFunc(std::function)
//[](){}

long long clockFunc(const std::function<void()>& func) {
    auto begin = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    return duration.count();
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector <int> vec1;
    double size, count;
    srand(time(0));
    std::cout << "Введите размер вектора:\n";
    std::cin >> size;
    while (size != static_cast<int>(size) || std::cin.fail()) {//c style cast, or-
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
        vec1.push_back(count);
    }
    const auto BubleSortTime = clockFunc([&vec1]() {
        BubbleSort(vec1);
        });
    std::cout << "Сортировка пузырьком\nВремя выполнения: " << BubleSortTime << " мкрсек\n";
    const auto sortTime = clockFunc([&vec1]() {
        sort(vec1.begin(), vec1.end());
        });
    std::cout << "Сортировка sort\nВремя выполнения: " << sortTime << " мкрсек\n";
    for (const auto& i : vec1) {
        std::cout << i << " ";
    }


    std::cout << "\n";
    std::cout << "Введите ключ:\n";
    std::string input;
    int key;
    std::cin >> input;
    try {
        key = std::stoi(input);
    }
    catch (const std::invalid_argument& ex) {
        std::cout << ex.what() << "\n";
        return 0;
    }
    
    auto lambda = [vec1, key]() {
    bool flag = false;
    int left = 0;
    int right = vec1.size() - 1;
    int mid;
    while ((left <= right) && (flag != true)) {
        mid = (left + right) / 2;

        if (vec1[mid] == key) flag = true;
        if (vec1[mid] > key) right = mid - 1;
        else left = mid + 1;
    }
    if (flag) std::cout << "Индекс элемента " << key << " в массиве равен: " << mid << "\n";
    else std::cout << "Извините, но такого элемента в массиве нет\n"; 
    };

    const auto searhTime = clockFunc(lambda);
    std::cout << "Время поиска: " << searhTime;
    return 0;
}
