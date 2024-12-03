#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
struct ticket {
    int number;
    char station[40];
    char time[10];
    float ticket_price;
};
void show_ticket(ticket a)
{
    cout << "Номер потягу: " << a.number << endl;
    cout << "Станція призначення: " << a.station << endl;
    cout << "Час призначення: " << a.time << endl;
    cout << "Ціна білету: " << a.ticket_price << " грн" << endl;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ticket trains[5] = {
        {101, "Київ", "08:00", 150.50},
        {102, "Львів", "12:30", 200.00},
        {103, "Одеса", "15:45", 180.75},
        {104, "Миколаїв", "18:20", 170.25},
        {105, "Харків", "20:00", 220.40}
    };

    char target_city[40];
    cout << "Введіть назву міста: ";
    cin.getline(target_city, 40);

    bool found = false;
    float min_price = 1e9;
    int min_price_train = -1;

    for (int i = 0; i < 5; i++) {
        bool search = true;
        for (int j = 0; target_city[j] != '\0' || trains[i].station[j] != '\0'; j++) {
            if (target_city[j] != trains[i].station[j]) {
                search = false;
                break;
            }
        }

        if (search) {
            show_ticket(trains[i]);
            cout << "--------------------------\n";
            found = true;

            if (trains[i].ticket_price < min_price) {
                min_price = trains[i].ticket_price;
                min_price_train = trains[i].number;
            }
        }
    }

    if (found) {
        cout << "Поїзд з найнижчою вартістю квитка до міста " << target_city << ":\n";
        cout << "Номер потягу: " << min_price_train << ", Вартість квитка: " << min_price << " грн.\n";
    }
    else {
        cout << "Немає поїздів до міста " << target_city << ".\n";
    }

    system("pause");
    return 0;
}
