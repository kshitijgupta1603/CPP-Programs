#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to store movie details
struct Movie {
    string title;
    double price;
};

// Function to display available movies
void displayMovies(const vector<Movie>& movies) {
    cout << "Available Movies:\n";
    for (int i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title << " - $" << movies[i].price << endl;
    }
}

int main() {
    // Initialize movie list
    vector<Movie> movies = {
        {"Avengers: Endgame", 12.99},
        {"The Batman", 14.99},
        {"Spider-Man: No Way Home", 13.49},
        {"The Matrix Resurrections", 15.99},
        {"Dune", 16.49}
    };

    int movieChoice;
    int numberOfTickets;
    double totalCost;

    cout << "Welcome to the Movie Ticket Booking System!\n";
    displayMovies(movies); // Show list of available movies

    // Ask user to choose a movie
    cout << "\nEnter the number corresponding to the movie you'd like to watch: ";
    cin >> movieChoice;

    // Validate user input
    if (movieChoice < 1 || movieChoice > movies.size()) {
        cout << "Invalid choice. Exiting the system.\n";
        return 0;
    }

    // Ask user for the number of tickets
    cout << "Enter the number of tickets you want to purchase: ";
    cin >> numberOfTickets;

    // Validate ticket input
    if (numberOfTickets <= 0) {
        cout << "Invalid number of tickets. Exiting the system.\n";
        return 0;
    }

    // Calculate total cost
    totalCost = movies[movieChoice - 1].price * numberOfTickets;

    // Display booking Details
    cout << "\nBooking Details:\n";
    cout << "Movie: " << movies[movieChoice - 1].title << endl;
    cout << "Number of Tickets: " << numberOfTickets << endl;
    cout << "Total Cost: $" << totalCost << endl;

    cout << "\nThank you for booking with us! Enjoy the movie.\n";

    return 0;
}