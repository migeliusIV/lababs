#include <iostream>
#include <map>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    std::map<std::string, int> Inventory;

    // filling
    Inventory["��������"] = 0;
    Inventory["�������"] = 10;
    Inventory["�����"] = 100;
    Inventory["�������"] = 0;
    Inventory["������"] = 9;
    Inventory["�����"] = 17;

    // output
    std::cout << "������ �� ������:" << std::endl;
    for (const auto& item : Inventory) {
        if (item.second != 0) {
            std::cout << item.first << " - " << item.second << std::endl;
        }
    }

    return 0;
}