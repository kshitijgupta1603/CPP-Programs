#include <iostream>
#include <cctype> // For tolower

using namespace std;

// Function to convert to Celsius
void convertToCelsius(double temp, char scale) {
    scale = tolower(scale);
    if (scale == 'f') {
        double celsius = (temp - 32) * 5.0 / 9.0;
        cout << temp << " Fahrenheit is equal to " << celsius << " Celsius." << endl;
    } else if (scale == 'k') {
        double celsius = temp - 273.15;
        cout << temp << " Kelvin is equal to " << celsius << " Celsius." << endl;
    } else {
        cout << "Invalid scale entered for conversion to Celsius." << endl;
    }
}

// Function to convert to Fahrenheit
void convertToFahrenheit(double temp, char scale) {
    scale = tolower(scale);
    if (scale == 'c') {
        double fahrenheit = (temp * 9.0 / 5.0) + 32;
        cout << temp << " Celsius is equal to " << fahrenheit << " Fahrenheit." << endl;
    } else if (scale == 'k') {
        double fahrenheit = (temp - 273.15) * 9.0 / 5.0 + 32;
        cout << temp << " Kelvin is equal to " << fahrenheit << " Fahrenheit." << endl;
    } else {
        cout << "Invalid scale entered for conversion to Fahrenheit." << endl;
    }
}

// Function to convert to Kelvin
void convertToKelvin(double temp, char scale) {
    scale = tolower(scale);
    if (scale == 'c') {
        double kelvin = temp + 273.15;
        cout << temp << " Celsius is equal to " << kelvin << " Kelvin." << endl;
    } else if (scale == 'f') {
        double kelvin = (temp - 32) * 5.0 / 9.0 + 273.15;
        cout << temp << " Fahrenheit is equal to " << kelvin << " Kelvin." << endl;
    } else {
        cout << "Invalid scale entered for conversion to Kelvin." << endl;
    }
}

int main() {
    double temperature;
    char scale;
    char convertTo;
    char choice;

    cout << "Temperature Converter\n";
    cout << "Enter 'C' for Celsius, 'F' for Fahrenheit, or 'K' for Kelvin.\n";

    do {
        cout << "\nEnter the temperature scale to convert from (C/F/K): ";
        cin >> scale;
        cout << "Enter the temperature value: ";
        cin >> temperature;

        cout << "\nWhich scale would you like to convert to?\n";
        cout << "C - Celsius\nF - Fahrenheit\nK - Kelvin\n";
        cin >> convertTo;

        convertTo = tolower(convertTo);
        scale = tolower(scale);

        if (convertTo == 'c') {
            convertToCelsius(temperature, scale);
        } else if (convertTo == 'f') {
            convertToFahrenheit(temperature, scale);
        } else if (convertTo == 'k') {
            convertToKelvin(temperature, scale);
        } else {
            cout << "Invalid conversion scale selected." << endl;
        }

        cout << "\nDo you want to perform another conversion? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    cout << "Thank you for using the Temperature Converter!\n";

    return 0;
}