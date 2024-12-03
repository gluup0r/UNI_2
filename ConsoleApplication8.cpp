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
    cout << "����� ������: " << a.number << endl;
    cout << "������� �����������: " << a.station << endl;
    cout << "��� �����������: " << a.time << endl;
    cout << "ֳ�� �����: " << a.ticket_price << " ���" << endl;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ticket trains[5] = {
        {101, "���", "08:00", 150.50},
        {102, "����", "12:30", 200.00},
        {103, "�����", "15:45", 180.75},
        {104, "�������", "18:20", 170.25},
        {105, "�����", "20:00", 220.40}
    };

    char target_city[40];
    cout << "������ ����� ����: ";
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
        cout << "���� � ��������� ������� ������ �� ���� " << target_city << ":\n";
        cout << "����� ������: " << min_price_train << ", ������� ������: " << min_price << " ���.\n";
    }
    else {
        cout << "���� ����� �� ���� " << target_city << ".\n";
    }

    system("pause");
    return 0;
}
