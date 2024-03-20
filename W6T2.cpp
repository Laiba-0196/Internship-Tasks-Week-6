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

struct Booking {
    int bookingNumber;
    Ticket* tickets;
    double totalCost;
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

void processBooking(const Ticket* tickets, int numTickets, int bookingNumber, BookingDay* days, int numDays) {
    double totalCost = 0.0;
    Ticket* bookedTickets = new Ticket[numTickets];

    // Select tickets
    for (int i = 0; i < numTickets; ++i) {
        int quantity;
        cout << "Enter the number of " << tickets[i].type << " tickets: ";
        cin >> quantity;
        totalCost += tickets[i].price * quantity;
        bookedTickets[i] = { tickets[i].type, tickets[i].price };
    }

    // Book the day
    string selectedDay;
    cout << "Enter the date for booking (YYYY-MM-DD): ";
    cin >> selectedDay;
    for (int i = 0; i < numDays; ++i) {
        if (days[i].date == selectedDay && days[i].available) {
            days[i].available = false;
            break;
        }
    }

    cout << "\nBooking Details:\n";
    cout << "Booking Number: " << bookingNumber << endl;
    cout << "Total Cost: $" << totalCost << endl;
    cout << "Booked Tickets:\n";
    for (int i = 0; i < numTickets; ++i) {
        cout << bookedTickets[i].type << " ($" << bookedTickets[i].price << ")\n";
    }

    delete[] bookedTickets;
}

int main() {
    Ticket oneDayTickets[] = { {"Adult", 25.0}, {"Child", 15.0} };
    BookingDay availableDays[] = { {"2024-03-21", true}, {"2024-03-22", true}, {"2024-03-23", true} };
    const int numOneDayTickets = sizeof(oneDayTickets) / sizeof(oneDayTickets[0]);
    const int numAvailableDays = sizeof(availableDays) / sizeof(availableDays[0]);
    int bookingNumber = 1;

    displayTicketOptions(oneDayTickets, numOneDayTickets);
    displayAvailableDays(availableDays, numAvailableDays);

    processBooking(oneDayTickets, numOneDayTickets, bookingNumber++, availableDays, numAvailableDays);

    return 0;
}
