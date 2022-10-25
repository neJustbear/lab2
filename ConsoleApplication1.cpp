#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <ctime>
#include <functional>
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

void clockFunc(std::function<void()> func) {
    auto begin = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "Время выполнения: " << duration.count() << " мкрсек\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector <int> vec1;
    double size, count, key;
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
    auto begin = std::chrono::steady_clock::now();
    BubbleSort(vec1);
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


    std::cout << "\n";
    std::cout << "Введите ключ:\n";
    std::cin >> key;
    while (key != static_cast<int>(key) || std::cin.fail()) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        std::cout << "Ошибка! Введите правильное число:\n";
        std::cin >> key;
    }
    
    auto lambda = [vec1, key]() {bool flag = false;
    int left = 0;
    int right = vec1.size();
    int mid;
    while ((left <= right) && (flag != true)) {
        mid = (left + right) / 2;

        if (vec1[mid] == key) flag = true;
        if (vec1[mid] > key) right = mid - 1;
        else left = mid + 1;
    }
    if (flag) std::cout << "Индекс элемента " << key << " в массиве равен: " << mid << "\n";
    else std::cout << "Извините, но такого элемента в массиве нет\n"; };
    
    clockFunc(lambda);
    return 0;
}