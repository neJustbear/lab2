#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<int>& vec, int size)
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

int main()
{
    setlocale(LC_ALL, "rus");
    vector <int> vec1;
    vector <int> vec2;
    double size, count;
    cout << "Введите размер вектора:\n";
    cin >> size;
    while (size != int(size) or cin.fail()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        cout << "Ошибка! Введите правильное число:" << endl;
        cin >> size;
    }
    cout << "Введите значения\n";
    for (int i = 0; i < size; i++) {
        cin >> count;
        while (cin.fail()) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
            }
            cout << "Ошибка! Введите правильное число:" << endl;
            cin >> count;
        }
        vec1.push_back(count);
        vec2.push_back(count);
    }
    auto begin = chrono::steady_clock::now();
    BubbleSort(vec1, size);
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << "Сортировка пузырьком\nВремя выполнения: " << duration.count() << " мкрсек\n";
    auto begin1 = chrono::steady_clock::now();
    sort(vec2.begin(), vec2.end());
    auto end1 = chrono::steady_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - begin1);
    cout << "Сортировка sort\nВремя выполнения: " << duration1.count() << " мкрсек\n";
    for (int i = 0; i < size; i++) {
        cout << vec1[i] << " ";
    }
    return 0;
}