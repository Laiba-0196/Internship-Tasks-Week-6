#include <iostream>
#include <iomanip>

using namespace std;

struct Ticket {
    string type;
    double price;
    int capacity; // For family/group tickets, capacity indicates the number of people it covers
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
    cout << setw(10) << left << "Type" << setw(10) << "Price ($)" << "Capacity\n";
    for (int i = 0; i < numTickets; ++i) {
        cout << setw(10) << left << tickets[i].type << setw(10) << tickets[i].price << tickets[i].capacity << endl;
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
    int totalCapacity = 0;

    // Select tickets
    for (int i = 0; i < numTickets; ++i) {
        int quantity;
        cout << "Enter the number of " << tickets[i].type << " tickets: ";
        cin >> quantity;
        totalCost += tickets[i].price * quantity;
        bookedTickets[i] = { tickets[i].type, tickets[i].price, quantity };
        totalCapacity += tickets[i].capacity * quantity;
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
        cout << bookedTickets[i].type << " x" << bookedTickets[i].capacity << " ($" << bookedTickets[i].price << ")\n";
    }

    // Check if there's a better value option
    if (totalCapacity == 10 && totalCost > 2 * tickets[0].price) { // Assuming family ticket is the first ticket type
        cout << "Consider purchasing two family tickets instead for better value.\n";
    }

    delete[] bookedTickets;
}

int main() {
    Ticket oneDayTickets[] = { {"Adult", 25.0, 1}, {"Child", 15.0, 1}, {"Family", 60.0, 4} }; // Family ticket covers 4 people
    BookingDay availableDays[] = { {"2024-03-21", true}, {"2024-03-22", true}, {"2024-03-23", true} };
    const int numOneDayTickets = sizeof(oneDayTickets) / sizeof(oneDayTickets[0]);
    const int numAvailableDays = sizeof(availableDays) / sizeof(availableDays[0]);
    int bookingNumber = 1;

    displayTicketOptions(oneDayTickets, numOneDayTickets);
    displayAvailableDays(availableDays, numAvailableDays);

    processBooking(oneDayTickets, numOneDayTickets, bookingNumber++, availableDays, numAvailableDays);

    return 0;
}
