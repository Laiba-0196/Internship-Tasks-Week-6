#include <iostream>
#include <iomanip>

using namespace std;

struct Ticket {
    string type;
    double price;
};

struct BookingDay {
    string date;
    bool available;
};

void displayTicketOptions(const Ticket* tickets, int numTickets) {
    cout << "Ticket Options:\n";
    cout << setw(10) << left << "Type" << "Price ($)\n";
    for (int i = 0; i < numTickets; ++i) {
        cout << setw(10) << left << tickets[i].type << tickets[i].price << endl;
    }
}

void displayAvailableDays(const BookingDay* days, int numDays) {
    cout << "\nAvailable Booking Days:\n";
    cout << "Date       Available\n";
    for (int i = 0; i < numDays; ++i) {
        cout << setw(10) << left << days[i].date << (days[i].available ? "Yes" : "No") << endl;
    }
}

int main() {
    Ticket oneDayTickets[] = { {"Adult", 25.0}, {"Child", 15.0} };
    Ticket twoDayTickets[] = { {"Adult", 40.0}, {"Child", 25.0} };
    BookingDay availableDays[] = { {"2024-03-21", true}, {"2024-03-22", true}, {"2024-03-23", true} };
    const int numOneDayTickets = sizeof(oneDayTickets) / sizeof(oneDayTickets[0]);
    const int numTwoDayTickets = sizeof(twoDayTickets) / sizeof(twoDayTickets[0]);
    const int numAvailableDays = sizeof(availableDays) / sizeof(availableDays[0]);

    displayTicketOptions(oneDayTickets, numOneDayTickets);
    displayTicketOptions(twoDayTickets, numTwoDayTickets);
    displayAvailableDays(availableDays, numAvailableDays);

    return 0;
}
