#include <iostream>

using namespace std;

int main()
{
    cout << "Press Ctrl-C to stop..." << endl;
    cout << "TAXI FARES" << endl;

    while (true)
    {
        // Define constants of service in Tokyo
        const int firstTwoKms = 710;
        const int farePer275Meters = 90;

        // Ask user for details about trip
        char time;
        cout << "Are you hiring our service between 6 AM and 11 PM ([Y]es/[N]o)? ";
        cin >> time;

        int distance;
        cout << "How many meters are you planning to use our service? ";
        cin >> distance;

        // Exclude impossible situations
        if ((distance < 0) || ((time != 'Y') && (time != 'y') && (time != 'N') && (time != 'n')))
        {
            cout << "You've entered an invalid value to one of the parameters to specify your trip's price. Please try again..." << endl;
            continue;
        }

        // Calculate and display total price
        int totalFare = firstTwoKms;
        distance -= 2000;
        if (distance > 0) for (int i = distance; i > 0; i -= 275) totalFare += farePer275Meters;
        if ((time == 'N') || (time == 'n')) totalFare *= 1.3;
        cout << "Your described trip costs CNY " << totalFare << endl;
    }

    return 0;
}
