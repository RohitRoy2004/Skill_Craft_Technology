// Temperature Converter in C++
// Converts between Celsius, Fahrenheit, and Kelvin

#include <iostream>
using namespace std;

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float c) {
    return (c * 9/5) + 32;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float c) {
    return c + 273.15;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float f) {
    return (f - 32) * 5/9;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float f) {
    return (f - 32) * 5/9 + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float k) {
    return k - 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float k) {
    return (k - 273.15) * 9/5 + 32;
}

int main() {
    int choice;
    float inputTemp, result;

    cout << "----------------------------------------------\n";
    cout << "Choose a conversion option:\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Celsius to Kelvin\n";
    cout << "3. Fahrenheit to Celsius\n";
    cout << "4. Fahrenheit to Kelvin\n";
    cout << "5. Kelvin to Celsius\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    if (choice < 1 || choice > 6) {
        cout << "Invalid choice! Please run the program again.\n";
        return 1; 
    }

    cout << "Enter the temperature to convert: ";
    cin >> inputTemp;

    switch (choice) {
        case 1:
            result = celsiusToFahrenheit(inputTemp);
            cout << inputTemp << "°C = " << result << "°F\n";
            break;
        case 2:
            result = celsiusToKelvin(inputTemp);
            cout << inputTemp << "°C = " << result << "K\n";
            break;
        case 3:
            result = fahrenheitToCelsius(inputTemp);
            cout << inputTemp << "°F = " << result << "°C\n";
            break;
        case 4:
            result = fahrenheitToKelvin(inputTemp);
            cout << inputTemp << "°F = " << result << "K\n";
            break;
        case 5:
            result = kelvinToCelsius(inputTemp);
            cout << inputTemp << "K = " << result << "°C\n";
            break;
        case 6:
            result = kelvinToFahrenheit(inputTemp);
            cout << inputTemp << "K = " << result << "°F\n";
            break;
    }

    cout << "----------------------------------------------\n";
    
    return 0;
}
