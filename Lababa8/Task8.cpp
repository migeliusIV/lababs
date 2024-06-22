#include <iostream>
#include <map>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    std::map<std::string, int> Inventory;

    // filling
    Inventory["Отвертка"] = 0;
    Inventory["Молоток"] = 10;
    Inventory["Гайки"] = 100;
    Inventory["Профиль"] = 0;
    Inventory["Уголок"] = 9;
    Inventory["Доска"] = 17;

    // output
    std::cout << "Товары на складе:" << std::endl;
    for (const auto& item : Inventory) {
        if (item.second != 0) {
            std::cout << item.first << " - " << item.second << std::endl;
        }
    }

    return 0;
}