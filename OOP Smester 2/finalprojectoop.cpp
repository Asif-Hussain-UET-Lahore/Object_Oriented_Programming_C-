#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Flight
{
protected:
    string flightNumber;
    string departureCity;
    string arrivalCity;
    string departureTime;
    string arrivalTime;
    string departureDate;
    int totalSeats;
    int availableSeats;
public:
    Flight() {}
    virtual void displayFlightDetails()
    {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Departure Date: " << departureDate << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    virtual void input()
    {
        cout << endl
             << "Enter the Flight Number : ";
        cin >> flightNumber;
        cout << endl
             << "Enter the Departure City :";
        cin >> departureCity;
        cout << endl
             << "Enter the Arrival City :";
        cin >> arrivalCity;
        cout << endl
             << "Enter the Departure Time : ";
        cin >> departureTime;
        cout << endl
             << "Enter the Arrival Time : ";
        cin >> arrivalTime;
        cout << endl
             << "Enter the Departure Date : ";
        cin >> departureDate;
        cout << endl
             << "Enter the Available Seats : ";
        cin >> availableSeats;
    }
};

class InternationalFlight : public Flight
{
private:
    string visaRequirements;
    string immigrationInfo;

public:
    InternationalFlight() {}

    void displayFlightDetails() override
    {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Departure Date: " << departureDate << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    void input() override
    {
        Flight::input();
        cout << endl
             << "Enter the visa requirement :";
        cin >> visaRequirements;
        cout << endl
             << "Enter the Immigration Information :";
        cin >> immigrationInfo;

        ofstream fout("InternationalFlight.txt", ios::app);
        if (fout.is_open())
        {
            fout << flightNumber << endl;
            fout << "Departure City :" << departureCity << endl;
            fout << "Arrival City :" << arrivalCity << endl;
            fout << "Departure Time :" << departureTime << endl;
            fout << "Arrival Time :" << arrivalTime << endl;
            fout << "Departure Date :" << departureDate << endl;
            fout << "Available seats :" << availableSeats << endl;
            fout << "visa Requirement :" << visaRequirements << endl;
            fout << "Immigration Information :" << immigrationInfo << endl;
            fout.close();
        }
    }

    void removeFromFile(const string &flightNumber)
    {
        ifstream fin("InternationalFlight.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                found = true;
                for (int i = 0; i < 8; ++i)
                    getline(fin, line); // Skipping 8 lines for the flight details
            }
            else
            {
                temp << line << endl;
            }
        }
        fin.close();
        temp.close();
        if (found)
        {
            remove("InternationalFlight.txt");
            rename("temp.txt", "InternationalFlight.txt");
            cout << "Flight with number " << flightNumber << " has been removed from InternationalFlight.txt" << endl;
        }
        else
        {
            cout << "Flight with number " << flightNumber << " not found in InternationalFlight.txt" << endl;
        }
    }

    void searchFlight(const string &flightNumber)
    {
        ifstream fin("InternationalFlight.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                found = true;
                cout << "Flight with number " << flightNumber << " found in InternationalFlight.txt" << endl;
                for (int i = 0; i < 8; ++i)
                {
                    getline(fin, line);
                    cout << line << endl;
                }
                break;
            }
        }
        fin.close();
        if (!found)
        {
            cout << "Flight with number " << flightNumber << " not found in InternationalFlight.txt" << endl;
        }
    }

    void updateFlight(const string &flightNumber)
    {
        ifstream fin("InternationalFlight.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                found = true;
                Flight::input(); // Update flight details
                cout << endl
                     << "Enter the visa requirement :";
                cin >> visaRequirements;
                cout << endl
                     << "Enter the Immigration Information :";
                cin >> immigrationInfo;
                temp << flightNumber << endl;
                temp << departureCity << endl;
                temp << arrivalCity << endl;
                temp << departureTime << endl;
                temp << arrivalTime << endl;
                temp << departureDate << endl;
                temp << availableSeats << endl;
                temp << visaRequirements << endl;
                temp << immigrationInfo << endl;
            }
            else
            {
                temp << line << endl;
            }
        }
        fin.close();
        temp.close();
        if (found)
        {
            remove("InternationalFlight.txt");
            rename("temp.txt", "InternationalFlight.txt");
            cout << "Flight with number " << flightNumber << " has been updated in InternationalFlight.txt" << endl;
        }
        else
        {
            cout << "Flight with number " << flightNumber << " not found in InternationalFlight.txt" << endl;
        }
    }

    bool flightExist(const string &flightNumber)
    {
        ifstream fin("InternationalFlight.txt");
        string line;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }
    bool domesticflightExist(const string &flightNumber)
    {
        ifstream fin("domesticticket.txt", ios::app);
        string line;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }
};
class DomesticFlight : public Flight
{
private:
    string domesticRegulations;

public:
    DomesticFlight() {}

    void displayFlightDetails() override
    {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure City: " << departureCity << endl;
        cout << "Arrival City: " << arrivalCity << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Departure Date: " << departureDate << endl;
        cout << "Available Seats: " << availableSeats << endl;
        cout << endl
             << "Domestic Regulation : " << domesticRegulations;
    }

    void input() override
    {
        Flight::input();
        cout << endl
             << "Enter the Domestic Regulation :";
        cin >> domesticRegulations;

        ofstream fout("DomesticFlight.txt", ios::app);
        if (fout.is_open())
        {
            fout << flightNumber << endl;
            fout << "Departure City :" << departureCity << endl;
            fout << "Arrival City :" << arrivalCity << endl;
            fout << "Departure Time :" << departureTime << endl;
            fout << "Arrival Time :" << arrivalTime << endl;
            fout << "Departure Date :" << departureDate << endl;
            fout << "Available seats :" << availableSeats << endl;
            fout << "domestic Regulation :" << domesticRegulations << endl;
            fout.close();
        }
    }

    void removeFromFile(const string &flightNumber)
    {
        ifstream fin("DomesticFlight.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                found = true;
                for (int i = 0; i < 7; ++i)
                    getline(fin, line); // Skipping 7 lines for the flight details
            }
            else
            {
                temp << line << endl;
            }
        }
        fin.close();
        temp.close();
        if (found)
        {
            remove("DomesticFlight.txt");
            rename("temp.txt", "DomesticFlight.txt");
            cout << "Flight with number " << flightNumber << " has been removed from DomesticFlight.txt" << endl;
        }
        else
        {
            cout << "Flight with number " << flightNumber << " not found in DomesticFlight.txt" << endl;
        }
    }

    void searchFlight(const string &flightNumber)
    {
        ifstream fin("DomesticFlight.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                found = true;
                cout << "Flight with number " << flightNumber << " found in DomesticFlight.txt" << endl;
                for (int i = 0; i < 7; ++i)
                {
                    getline(fin, line);
                    cout << line << endl;
                }
                break;
            }
        }
        fin.close();
        if (!found)
        {
            cout << "Flight with number " << flightNumber << " not found in DomesticFlight.txt" << endl;
        }
    }

    void updateFlight(const string &flightNumber)
    {
        ifstream fin("DomesticFlight.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == flightNumber)
            {
                found = true;
                Flight::input(); // Update flight details
                cout << endl
                     << "Enter the Domestic Regulation :";
                cin >> domesticRegulations;
                temp << flightNumber << endl;
                temp << departureCity << endl;
                temp << arrivalCity << endl;
                temp << departureTime << endl;
                temp << arrivalTime << endl;
                temp << departureDate << endl;
                temp << availableSeats << endl;
                temp << domesticRegulations << endl;
            }
            else
            {
                temp << line << endl;
            }
        }
        fin.close();
        temp.close();
        if (found)
        {
            remove("DomesticFlight.txt");
            rename("temp.txt", "DomesticFlight.txt");
            cout << "Flight with number " << flightNumber << " has been updated in DomesticFlight.txt" << endl;
        }
        else
        {
            cout << "Flight with number " << flightNumber << " not found in DomesticFlight.txt" << endl;
        }
    }
};
class FlightManager
{
private:
    static const int MAX_FLIGHTS = 100;
    Flight flights[MAX_FLIGHTS];
    int numFlights;
    Flight *ptr1;
    Flight *ptr2;
    InternationalFlight d1;
    DomesticFlight s1;

public:
    FlightManager() {}

    void addInterFlight()
    {
        ptr1 = &d1;
        ptr1->input();
        ptr2->input();
    }

    void adddomflight()
    {
        ptr2 = &s1;
        ptr2->input();
    }

    void removeinterflight(const string &flightNumber)
    {
        d1.removeFromFile(flightNumber);
    }

    void removedomflight(const string &flightNumber)
    {
        s1.removeFromFile(flightNumber);
    }

    void searchInternationalFlight(const string &flightNumber)
    {
        d1.searchFlight(flightNumber);
    }

    void searchDomesticFlight(const string &flightNumber)
    {
        s1.searchFlight(flightNumber);
    }

    void updateInternationalFlight(const string &flightNumber)
    {
        d1.updateFlight(flightNumber);
    }

    void updateDomesticFlight(const string &flightNumber)
    {
        s1.updateFlight(flightNumber);
    }

    void viewAllInternationalFlights()
    {
        cout << endl
             << "----------[International Flights]----------" << endl;
        ifstream fin("InternationalFlight.txt");
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        fin.close();
    }

    void viewAllDomesticFlights()
    {
        cout << endl
             << "----------[Domestic Flights]----------" << endl;
        ifstream fin("DomesticFlight.txt");
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        fin.close();
    }

    bool checkFlightExist(const string &flightNumber)
    {
        return d1.flightExist(flightNumber);
    }
    bool domesticflightExist(const string &flightNumber)
    {
        return d1.domesticflightExist(flightNumber);
    }
};

class Passenger
{
public:
    string name;
    int age;
    string cnic;
    string bookingdate;
    string bookingtime;

public:
    Passenger() {}

    Passenger(string pname, int page, string pcnic) : name(pname), age(page), cnic(pcnic) {}

    void input()
    {
        cout << endl
             << "Please Enter Your name : ";
        cin >> name;
        cout << endl
             << "Please Enter your Age in year: ";
        cin >> age;
        cout << endl
             << "Please Enter Your CNIC ";
        cin >> cnic;
        cout << endl
             << "Please Enter your Booking Date : ";
        cin >> bookingdate;
        cout << endl
             << "Please Enter the Booking Time :";
        cin >> bookingtime;
    }
    void display()
    {
        cout << endl
             << "name :" << name;
        cout << endl
             << "Age :" << age;
        cout << endl
             << "CNIC :" << cnic;
        cout << endl
             << "Booking Date :" << bookingdate;
        cout << endl
             << "Booking Time :" << bookingtime;
    }
};

class FlightTicket
{
private:
    string ticketID;
    Passenger passenger;
    Flight flight;
    string flightNo;
    string seatNumber;

public:
    FlightTicket() {}

    void applyticket(FlightManager &flightManager)
    {
        int a = 2;
        passenger.input();
        cout << endl
             << "Enter the Ticket ID: ";
        cin >> ticketID;
        cout << endl
             << "Enter the Flight Number: ";
        cin >> flightNo;
        if (flightManager.checkFlightExist(flightNo))
        {
            cout << "Flight number " << flightNo << " exists." << endl;
            cout << "Enter the seat Number: ";
            cin >> seatNumber;
            string s1, s2, s3, s4, s5, s6, s7, s8, s9;
            ifstream fin("applyticket.txt");
            string line;
            if (fin.is_open())
            {
                while (getline(fin, s1))
                {
                    getline(fin, s2);
                    getline(fin, s3);
                    getline(fin, s4);
                    getline(fin, s5);
                    getline(fin, s6);
                    getline(fin, s7);
                    getline(fin, s8);
                    getline(fin, s9);
                    if (s9 == string(seatNumber) && s2 == flightNo)
                    {
                        a = 3;
                        cout << endl
                             << "This seat is not available in this flight. Please select another seat." << endl;
                        break;
                    }
                }
                fin.close();
            }

            if (a == 2)
            {
                ofstream fout("applyticket.txt", ios::app);
                if (fout.is_open())
                {
                    fout << ticketID << endl;
                    fout << flightNo << endl;
                    fout << "Passenger Details:" << endl;
                    fout << "Name: " << passenger.name << endl;
                    fout << "Age: " << passenger.age << endl;
                    fout << "CNIC: " << passenger.cnic << endl;
                    fout << "Booking Date: " << passenger.bookingdate << endl;
                    fout << "Booking Time: " << passenger.bookingtime << endl;
                    fout << seatNumber << endl;
                    fout.close();
                    cout << "Ticket has been successfully applied and saved to applyticket.txt" << endl;
                }
            }
        }
        else
        {
            cout << "Flight number " << flightNo << " does not exist." << endl;
        }
    }
    void domesticapplyticket(FlightManager &flightManager)
    {
        int a = 2;
        passenger.input();
        cout << endl
             << "Enter the Ticket ID: ";
        cin >> ticketID;
        cout << endl
             << "Enter the Flight Number: ";
        cin >> flightNo;
        if (flightManager.checkFlightExist(flightNo))
        {
            cout << "Flight number " << flightNo << " exists." << endl;
            cout << "Enter the seat Number: ";
            cin >> seatNumber;
            string s1, s2, s3, s4, s5, s6, s7, s8, s9;
            ifstream fin("domesticticket.txt");
            string line;
            if (fin.is_open())
            {
                while (getline(fin, s1))
                {
                    getline(fin, s2);
                    getline(fin, s3);
                    getline(fin, s4);
                    getline(fin, s5);
                    getline(fin, s6);
                    getline(fin, s7);
                    getline(fin, s8);
                    getline(fin, s9);
                    if (s9 == string(seatNumber) && s2 == flightNo)
                    {
                        a = 3;
                        cout << endl
                             << "This seat is not available in this flight. Please select another seat." << endl;
                        break;
                    }
                }
                fin.close();
            }

            if (a == 2)
            {
                ofstream fout("domesticticket.txt", ios::app);
                if (fout.is_open())
                {
                    fout << ticketID << endl;
                    fout << flightNo << endl;
                    fout << "Passenger Details:" << endl;
                    fout << "Name: " << passenger.name << endl;
                    fout << "Age: " << passenger.age << endl;
                    fout << "CNIC: " << passenger.cnic << endl;
                    fout << "Booking Date: " << passenger.bookingdate << endl;
                    fout << "Booking Time: " << passenger.bookingtime << endl;
                    fout << seatNumber << endl;
                    fout.close();
                    cout << "Ticket has been successfully applied and saved to domesticapplyticket.txt" << endl;
                }
            }
        }
        else
        {
            cout << "Flight number " << flightNo << " does not exist." << endl;
        }
    }
    void display()
    {
        cout << endl
             << "Ticket ID :" << ticketID;
        cout << endl
             << "Flight No :" << flightNo;
        cout << endl
             << "Seat Number :" << seatNumber;
    }
};
class Reservation
{
private:
    Flight *flight;
    Passenger passenger;
    FlightTicket f1;
    InternationalFlight inter1;
    FlightManager m1;
    string status;

public:
    Reservation() {}
    void viewallflight()
    {
        flight = &inter1;
        m1.viewAllInternationalFlights();
    }
    void viewalldomesticflight()
    {
        flight = &inter1;
        m1.viewAllDomesticFlights();
    }
    void applyTicket()
    {
        f1.applyticket(m1);
    }
    void domesticapplyTicket()
    {
        f1.domesticapplyticket(m1);
    }
    void viewAllInternationalReservations()
    {
        ifstream fin("applyticket.txt");
        string line;
        cout << endl
             << "----------[International Reservations]----------" << endl;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        fin.close();
    }
    void viewAllDomesticReservations()
    {
        ifstream fin("domesticticket.txt");
        string line;
        cout << endl
             << "----------[Domestic Reservations]----------" << endl;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        fin.close();
    }
    void searchInternationalReservation(const string &ticketID)
    {
        ifstream fin("applyticket.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == ticketID)
            {
                found = true;
                cout << "Reservation with Ticket ID " << ticketID << " found in applyticket.txt" << endl;
                for (int i = 0; i < 8; ++i)
                {
                    getline(fin, line);
                    cout << line << endl;
                }
                break;
            }
        }
        fin.close();
        if (!found)
        {
            cout << "Reservation with Ticket ID " << ticketID << " not found in applyticket.txt" << endl;
        }
    }
    void searchDomesticReservation(const string &ticketID)
    {
        ifstream fin("domesticticket.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == ticketID)
            {
                found = true;
                cout << "Reservation with Ticket ID " << ticketID << " found in domesticticket.txt" << endl;
                for (int i = 0; i < 8; ++i)
                {
                    getline(fin, line);
                    cout << line << endl;
                }
                break;
            }
        }
        fin.close();
        if (!found)
        {
            cout << "Reservation with Ticket ID " << ticketID << " not found in domesticticket.txt" << endl;
        }
    }
};
class ReservationManager
{
private:
    Reservation r1;

public:
    ReservationManager() {}
    void applyTicket()
    {
        r1.applyTicket();
    }
    void domesticapplyTicket()
    {
        r1.domesticapplyTicket();
    }
    void removeInternationalReservation()
    {
        string ticketID;
        cout << endl
             << "Enter the Ticket ID to remove: ";
        cin >> ticketID;
        ifstream fin("applyticket.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == ticketID)
            {
                found = true;
                for (int i = 0; i < 8; ++i)
                    getline(fin, line); // Skipping 8 lines for the ticket details
            }
            else
            {
                temp << line << endl;
            }
        }
        fin.close();
        temp.close();
        if (found)
        {
            remove("applyticket.txt");
            rename("temp.txt", "applyticket.txt");
            cout << "Ticket with ID " << ticketID << " has been removed from applyticket.txt" << endl;
        }
        else
        {
            cout << "Ticket with ID " << ticketID << " not found in applyticket.txt" << endl;
        }
    }
    void removeDomesticReservation()
    {
        string ticketID;
        cout << endl
             << "Enter the Ticket ID to remove: ";
        cin >> ticketID;
        ifstream fin("domesticticket.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        while (getline(fin, line))
        {
            if (line == ticketID)
            {
                found = true;
                for (int i = 0; i < 8; ++i)
                    getline(fin, line); // Skipping 8 lines for the ticket details
            }
            else
            {
                temp << line << endl;
            }
        }
        fin.close();
        temp.close();
        if (found)
        {
            remove("domesticticket.txt");
            rename("temp.txt", "domesticticket.txt");
            cout << "Ticket with ID " << ticketID << " has been removed from domesticticket.txt" << endl;
        }
        else
        {
            cout << "Ticket with ID " << ticketID << " not found in applyticket.txt" << endl;
        }
    }
};
int main()
{
    cout << endl
         << "                         ----------------------------[Flight Reservation System]--------------------            QATAR AIRWAYS & PIA";
    int a;
    for (; true;)
    {
        for (; true;)
        {
            system("cls");
            cout << endl
                 << "                           ----------------------------[Flight Reservation System]--------------------        ";
            cout << endl
                 << "Press 1 for FlightMananger Interface :";
            cout << endl
                 << "Press 2 for ReservationManager interface : ";
            cout << endl
                 << "Press 3 for Passenger Interface : ";
            cin >> a;
            int g;
            cout << endl
                 << "Press 1 for continue...";
            cout << endl
                 << "Press 0 for back ....  :";
            cin >> g;
            if (g == 1)
            {
                break;
            }
        }
        switch (a)
        {
        case 1:
        {
            string Password;
            int id;
            cout << endl
                 << "Welcome to Flight Mananger : ";
            cout << endl
                 << "Enter the Password to Login  :";
            cin >> Password;
            cout << endl
                 << "Enter the ID for Login  :";
            cin >> id;

            if (Password == "ali" && id == 123)
            {
                for (; true;)
                {
                    int i;
                    cout << endl
                         << "You are Successfully Login as Flight Mananger :";
                    cout << endl
                         << "Press 1 for Add International Flight:";
                    cout << endl
                         << "Press 2 for Add Domestic Flight :";
                    cout << endl
                         << "Press 3 for Remove International Flight : ";
                    cout << endl
                         << "Press 4 for Remove Domestic Flight :";
                    cout << endl
                         << "Press 5 for Update International Flight :";
                    cout << endl
                         << "Press 6 for Update Domestic Information  Flight :";
                    cout << endl
                         << "Press 7 for View All International Flight :";
                    cout << endl
                         << "Press 8 for View All Domestic Flight :";
                    cout << endl
                         << "Press 9 for Searching Domestic flight :";
                    cout << endl
                         << "Press 10 for Searching International Flight :";
                    cin >> i;

                    FlightManager t1;

                    switch (i)
                    {
                    case 1:
                    {
                        t1.addInterFlight();
                        break;
                    }
                    case 2:
                    {
                        t1.adddomflight();
                        break;
                    }
                    case 3:
                    {
                        string flightNumber;
                        cout << endl
                             << "Enter the Flight Number to remove: ";
                        cin >> flightNumber;
                        t1.removeinterflight(flightNumber);
                        break;
                    }
                    case 4:
                    {
                        string flightNumber;
                        cout << endl
                             << "Enter the Flight Number to remove: ";
                        cin >> flightNumber;
                        t1.removedomflight(flightNumber);
                        break;
                    }
                    case 5:
                    {
                        string flightNumber;
                        cout << endl
                             << "Enter the Flight Number to update: ";
                        cin >> flightNumber;
                        t1.updateInternationalFlight(flightNumber);
                        break;
                    }
                    case 6:
                    {
                        string flightNumber;
                        cout << endl
                             << "Enter the Flight Number to update: ";
                        cin >> flightNumber;
                        t1.updateDomesticFlight(flightNumber);
                        break;
                    }
                    case 7:
                    {
                        t1.viewAllInternationalFlights();
                        break;
                    }
                    case 8:
                    {
                        t1.viewAllDomesticFlights();
                        break;
                    }
                    case 9:
                    {
                        string flightNumber;
                        cout << endl
                             << "Enter the Domestic Flight Number to search: ";
                        cin >> flightNumber;
                        t1.searchDomesticFlight(flightNumber);
                        break;
                    }
                    case 10:
                    {
                        string flightNumber;
                        cout << endl
                             << "Enter the International Flight Number to search: ";
                        cin >> flightNumber;
                        t1.searchInternationalFlight(flightNumber);
                        break;
                    }
                    default:
                    {
                        cout << endl
                             << "Your Input is incorrect Please Enter the Correct input :";
                    }
                    }
                    int t;
                    cout << endl
                         << "Press 1 for Continue.....";
                    cout << endl
                         << "Press 0 for Exit......";
                    cin >> t;
                    if (t == 0)
                    {
                        exit(0);
                    }
                    system("cls");
                }
            }
            break;
        }

        case 2:
        {
            int i;
            string password;
            int id;
            cout << endl
                 << "wellcome to Reservation Mananger portal ";
            cout << endl
                 << "Please Enter the Password to login :";
            cin >> password;
            cout << endl
                 << "Please Enter the ID to Login this Portal :";
            cin >> id;
            if (password == "ali" && id == 123)
            {
                for (; true;)
                {
                    int a;
                    int i;
                    cout << endl
                         << "Your are Successfully Login as ReservationMananger :";
                    cout << endl
                         << "Press 1 for international Reservation Interface :";
                    cout << endl
                         << "Press 2 for Domestic Reservation Interface :";
                    cin >> i;
                    if (i == 1)
                    {
                        cout << endl
                             << "Press 1 for Make international Reservation :";
                        cout << endl
                             << "Press 2 for Remove International Reservation :";
                        cout << endl
                             << "Press 3 for View all international flights : ";
                        cout << endl
                             << "press 4 for view all internationalal reservation :";
                        cout << endl
                             << "Press 5 for searching International Reservation :";
                        cin >> a;
                        switch (a)
                        {
                        case 1:
                        {
                            ReservationManager f1;
                            f1.applyTicket();
                            break;
                        }
                        case 2:
                        {
                            ReservationManager f1;
                            f1.removeInternationalReservation();
                            break;
                        }
                        case 3:
                        {
                            Reservation f1;
                            f1.viewallflight();
                            break;
                        }
                        case 4:
                        {
                            Reservation f1;
                            f1.viewAllInternationalReservations();
                            break;
                        }
                        case 5:
                        {
                            string ticketname;
                            cout << endl
                                 << "Enter the Ticket ID for Searching International Reservation :";
                            cin >> ticketname;
                            Reservation f1;
                            f1.searchInternationalReservation(ticketname);
                            break;
                        }
                        default:
                        {
                            cout << endl
                                 << "Your Input is incorrect Please Enter the Correct input :";
                        }
                        }
                    }

                    if (i == 2)
                    {
                        int i;
                        cout << endl
                             << "Press 1 for Make Domestic Reservation :";
                        cout << endl
                             << "Press 2 for Remove Domestic Reservation :";
                        cout << endl
                             << "Press 3 for view all domestic flights :";
                        cout << endl
                             << "Press 4 for view all domestic reservation :";
                        cout << endl
                             << "Press 5 for searching a Domestic Reservation :";
                        cin >> i;
                        switch (i)
                        {
                        case 1:
                        {
                            ReservationManager m1;
                            m1.domesticapplyTicket();
                            break;
                        }
                        case 2:
                        {
                            ReservationManager f1;
                            f1.removeDomesticReservation();
                            break;
                            break;
                        }
                        case 3:
                        {
                            Reservation f1;
                            f1.viewalldomesticflight();
                            break;
                        }
                        case 4:
                        {
                            Reservation f1;
                            f1.viewAllDomesticReservations();
                            break;
                        }
                        case 5:
                        {
                            string ticketname;
                            cout << endl
                                 << "Enter the Ticket ID for Searching Domestic Reservation :";
                            cin >> ticketname;
                            Reservation f1;
                            f1.searchDomesticReservation(ticketname);
                            break;
                        }
                        default:
                        {
                            cout << endl
                                 << "Your Input is incorrect Please Enter the Correct input :";
                        }
                        }
                    }
                    int t;
                    cout << endl
                         << "Press 1 for Continue.....";
                    cout << endl
                         << "Press 0 for Exit......";
                    cin >> t;
                    if (t == 0)
                    {
                        exit(0);
                    }
                    system("cls");
                }
            }
            break;
        }
        case 3:
        {
            int a;
            cout << endl
                 << "Wellcome to passenger portal :";
            cout << endl
                 << "Press 1 for International Ticket Booking :";
            cout << endl
                 << "Press 2 for Domestic Ticket Booking :";
            cout << endl
                 << "Press 3 for view your International Ticket :";
            cout << endl
                 << "Press 4 for view your Domestic Ticket :";
            cout << endl
                 << "Press 5 for View all International Flight :";
            cout << endl
                 << "Press 6 for View all Domestic Flight :";
            cin >> a;
            switch (a)
            {
            case 1:
            {
                ReservationManager f1;
                f1.applyTicket();
                break;
            }
            case 2:
            {
                ReservationManager m1;
                m1.domesticapplyTicket();
                break;
            }
            case 3:
            {
                string ticketname;
                cout << endl
                     << "Enter the Ticket ID for Searching International Reservation :";
                cin >> ticketname;
                Reservation f1;
                f1.searchInternationalReservation(ticketname);
                break;
            }
            case 4:
            {
                string ticketname;
                cout << endl
                     << "Enter the Ticket ID for Searching Domestic Reservation :";
                cin >> ticketname;
                Reservation f1;
                f1.searchDomesticReservation(ticketname);
                break;
            }
            case 5:
            {
                Reservation f1;
                f1.viewallflight();
                break;
            }
            case 6:
            {
                Reservation f1;
                f1.viewAllDomesticReservations();
                break;
            }
            default:
            {
                cout << endl
                     << "Your Input is incorrect Please Enter the Correct input :";
            }
            }
        }
            int t;
            cout << endl
                 << "Press 1 for Continue.....";
            cout << endl
                 << "Press 0 for Exit......";
            cin >> t;
            if (t == 0)
            {
                exit(0);
            }
        }
    }
    return 0;
}