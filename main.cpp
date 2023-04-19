#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Начало, Инициализация Операндов, Открываем Исходный Файл
    string a, path = "D:\\Test\\Algebra.csv";
    int count = 0;
    /*
    cout << "Введите ПОЛНЫЙ путь к файлу";
    cin >> a;
    cout << endl;
    */

    ifstream file(path, ifstream::in);

    if (file.is_open()) cout << "Файл был успешно открыт\n";
    else cout << "Что-то пошло не так. Файл не был открыт\n";
    //...............//



    // Перепись Исходного Файла в Массив
    string array[7703];
    for (int i = 0; !file.eof(); i++) {
        a = "";
        getline(file, a, ';');

        array[i] = a;
    }
    //...............//

    file.close();

    // Находим Количевство Искохдного ФИО
    for (int i = 0, n = 0; i < 1150; i++) {
        a = "";
        a = array[i];

        if (i == (45 + n) && a != "") {
            count++;
            n += 22;
        }
    }

    cout << count << endl;
    //...............//



    // Создаём Динамический Массив, Вносим в Него ФИО
    string *array1 = new string[count] {};

    for (int i = 0, n = 0, f = 0; i < 1150; i++) {
        a = "";
        a = array[i];

        if (i == (45 + n) && a != "") {
            array1[f] = array[i];
            n += 22;
            f++;
        }
    }
    //...............//



    // Создание Матрицы для Оценок
    int Matrix[1][126];

    for (int i = 46, n = 0, m = 0, f = 0; i < 7704; i++, m++) {
        if (i == (65 + f)) {
            i += 1082;
            f += 1100;
        }

        if (array[i] == "5") {
            Matrix[n][m] = 5;
        }
        else if (array[i] == "4") {
            Matrix[n][m] = 4;
        }
        else if (array[i] == "3") {
            Matrix[n][m] = 3;
        }
        else if (array[i] == "2") {
            Matrix[n][m] = 2;
        }
        else if (array[i] == "") {
            Matrix[n][m] = 0;
        }
        else {
            Matrix[n][m] = -1;
        }
    }

    for (int j = 0; j < 126; j++) {
        cout << Matrix[0][j] << "\n";
    }
    //...............//

    return 0;
}