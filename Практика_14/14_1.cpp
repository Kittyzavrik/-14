#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // читаем всю строку, включая пробелы

    string st;  // используем строку как стек — так проще
    bool ok = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);  // открывающая — кидаем в стек
        }
        else if (c == ')' || c == ']' || c == '}') {
            // закрывающая, а закрывать нечего
            if (st.empty()) {
                ok = false;
                break;
            }
            char last = st.back(); // скопировали последний символ в переменную last
            st.pop_back(); // убрали последний символ

            // проверяем, что пары совпадают
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                ok = false;
                break;
            }
        }
        // остальные символы (буквы, пробелы, знаки) просто игнорим
    }

    // если после всего стек не пуст — значит, что-то не закрыли
    if (!st.empty()) ok = false;

    cout << (ok ? "yes" : "no");
    return 0;
}