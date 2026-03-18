#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    system("chcp 1251 > null");

    string filename;
    cout << "Введіть ім'я файлу: "; // text.txt
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Помилка: Файл не знайдено!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;
    string content = "";

    while (getline(file, line)) {
        lineCount++;
        content += line + "\n";

        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) {
                inWord = false;
            }
            else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }
    }

    file.close();

    cout << "\n========== Вміст файлу ==========" << endl;
    cout << content;
    cout << "===================================" << endl;

    cout << "\n========== Звіт ==========" << endl;
    cout << "Рядків: " << lineCount << endl;
    cout << "Слів:   " << wordCount << endl;

    return 0;
}
