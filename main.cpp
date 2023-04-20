#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define CELLSY_MATRIX 35
#define CELLSX_MATRIX 126
#define CELLS_ARRAY 7703
#define NUM_START 45
#define NUM1 22
#define NUM2 1150
#define NUM3 46
#define NUM4 64
#define NUM5 1082
#define NUM6 1100


int main() {
    setlocale(LC_ALL, "ru");
    // Начало, Инициализация Операндов, Открываем Исходный Файл
    string a, path;
    int count = 0;

    cout << "Введите ПОЛНЫЙ путь к файлу: ";
    getline(cin, path);
    cout << endl;

    ifstream file(path, ifstream::in);
    ofstream file2("C:\\Algebra\\AlgebraC.csv", ofstream::out);

    if (file.is_open()) cout << "Файл Один был успешно открыт\n\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n";

    if (file2.is_open()) cout << "Файл Два был успешно открыт\n\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n";
    //...............//


    // Перепись Исходного Файла в Массив
    string array[CELLS_ARRAY];
    for (int i = 0; !file.eof(); i++) {
        a = "";
        getline(file, a, ';');

        array[i] = a;
    }
    //...............//

    file.close();

    // Находим Количевство Искохдного ФИО
    for (int i = 0, n = 0; i < NUM2; i++) {
        a = "";
        a = array[i];

        if (i == (NUM_START + n) && a != "") {
            count++;
            n += NUM1;
        }
    }

    cout << endl;
    cout << count << endl << endl;
    //...............//


    // Создаём Динамический Массив, Вносим в Него ФИО
    string* array1 = new string[count]{};

    for (int i = 0, n = 0, f = 0; i < NUM2; i++) {
        a = "";
        a = array[i];

        if (i == (NUM_START + n) && a != "") {
            array1[f] = array[i];
            n += NUM1;
            f++;
        }
    }
    //...............//


    // Создание Матрицы для Оценок
    int Matrix[CELLSY_MATRIX][CELLSX_MATRIX];

    for (int j = 0, r = 0; j < CELLSY_MATRIX; j++, r += NUM1) {
        for (int i = (NUM3 + r), m = 0, f = 0; m < CELLSX_MATRIX; i++, m++) {
            if (i == (NUM4 + r) + f) {
                i += NUM5;
                f += NUM6;
            }

            if (array[i] == "5") {
                Matrix[j][m] = 5;
            }
            else if (array[i] == "4") {
                Matrix[j][m] = 4;
            }
            else if (array[i] == "3") {
                Matrix[j][m] = 3;
            }
            else if (array[i] == "2") {
                Matrix[j][m] = 2;
            }
            else if (array[i] == "") {
                Matrix[j][m] = 0;
            }
            else {
                Matrix[j][m] = -1;
            }
        }
    }
    //...............//


    // В Новый Файл Вписаваем ФИО, а Потом Соответствено Оценки
    for (int j = 0; j < CELLSY_MATRIX; j++) {
        file2 << array1[j] << ";";

        for (int i = 0; i < CELLSX_MATRIX; i++) {
            file2 << Matrix[j][i] << ";";
        }

        file2 << endl;
    }
    //...............//

    file2.close();
    delete [] array1;

    return 0;
}