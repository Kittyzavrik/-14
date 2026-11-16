#include <iostream>
#include <stack> // готов стек
#include <algorithm>

class MinStack {
public:
    void push(int x) { // х на вершину
        elements.push(x); // кладем в основ стек
        // Минимум на этом уровне: либо x, либо предыдущий минимум
        mins.push(mins.empty() ? x : std::min(x, mins.top()));
    }

    void pop() { //уб верх элем
        elements.pop(); // уб верх из основ стека
        mins.pop(); 
    }

    int top() const { //возвращ верх элем не убирая его
        return elements.top(); //отдаем вершину основ стека
    }

    bool empty() const { // да если пуст
        return elements.empty(); // пуст когда пуст минс
    }

    int getMin() const { // текущий мин стека
        return mins.top(); // минимум всех элем
    }

private:
    std::stack<int> elements; // сами элементы
    std::stack<int> mins;     // минимум на каждом уровне
};

int main() { //
    MinStack s; //пустой объект

    // Кладём: 5, 3, 7, 1, 4
    for (int x : {5, 3, 7, 1, 4}) {
        s.push(x); // кладем очередное число
    }

    std::cout << "min: " << s.getMin() << "\n"; // 1 мин
    std::cout << "top: " << s.top()    << "\n"; // 4 вершина

    s.pop();                                     // убрали 4
    std::cout << "min: " << s.getMin() << "\n"; // 1

    s.pop();                                     // убрали 1
    std::cout << "min: " << s.getMin() << "\n"; // 3

    // Опустошаем до конца
    while (!s.empty()) {
        std::cout << "pop " << s.top(); //тек вершина
        s.pop(); // удаляем вершину
        if (!s.empty()) { //если не пуст
            std::cout << " -> min: " << s.getMin(); //печатаем минимум
        }
        std::cout << "\n";
    }

    return 0;
}