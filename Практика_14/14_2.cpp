#include <iostream>
#include <string>
#include <vector> //списки
#include <unordered_set> // поиск уже есть
#include <cctype> // проверка буква ли и привод к ниж регистру

using namespace std;

// Проверяем, является ли символ частью слова:
// буква или дефис (чтобы "всё-таки" осталось одним словом)
bool isWordChar(char c) { // прим символ возв да или нет
    return isalpha(static_cast<unsigned char>(c)) || c == '-'; //привод к беззнак типу
}

int main() {
    vector<string> uniqueWords;          // слова в порядке появления
    unordered_set<string> seen;          // для быстрой проверки "уже было?"
    string word;  // текущее слово

    char c;
    while (cin.get(c)) {
        if (isWordChar(c)) { //Если текущий символ — буква или дефис, значит, мы внутри слова.
            // Копим слово, приводя буквы к нижнему регистру
            word += tolower(static_cast<unsigned char>(c));
        } else if (!word.empty()) {
            // Встретили разделитель — слово закончилось
            if (seen.insert(word).second) { //если слова не было
                uniqueWords.push_back(word); // доб в конец
            }
            word.clear(); // очищ, коп новое сл
        }
    }

    // Не забываем про слово, если текст закончился без разделителя
    if (!word.empty() && seen.insert(word).second) { // если слово есть и оно нов
        uniqueWords.push_back(word); //доб в конец
    }

    for (const string& w : uniqueWords) { // переб все слова кладем в w
        cout << w << '\n'; // вывод
    }

    return 0;
}