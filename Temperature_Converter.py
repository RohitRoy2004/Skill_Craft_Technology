# Temperature Converter in Python
# Converts between Celsius, Fahrenheit, and Kelvin

# Conversion functions
def celsius_to_fahrenheit(c):
    return (c * 9/5) + 32

def celsius_to_kelvin(c):
    return c + 273.15

def fahrenheit_to_celsius(f):
    return (f - 32) * 5/9

def fahrenheit_to_kelvin(f):
    return (f - 32) * 5/9 + 273.15

def kelvin_to_celsius(k):
    return k - 273.15

def kelvin_to_fahrenheit(k):
    return (k - 273.15) * 9/5 + 32

# Main program
def main():
    print("----------------------------------------------")
    print("Choose a conversion option:")
    print("1. Celsius to Fahrenheit")
    print("2. Celsius to Kelvin")
    print("3. Fahrenheit to Celsius")
    print("4. Fahrenheit to Kelvin")
    print("5. Kelvin to Celsius")
    print("6. Kelvin to Fahrenheit")
    
    try:
        choice = int(input("Enter your choice (1-6): "))
    except ValueError:
        print("Invalid input! Please enter a number.")
        return

    if choice < 1 or choice > 6:
        print("Invalid choice! Please run the program again.")
        return

    try:
        input_temp = float(input("Enter the temperature to convert: "))
    except ValueError:
        print("Invalid temperature! Please enter a number.")
        return

    if choice == 1:
        result = celsius_to_fahrenheit(input_temp)
        print(f"{input_temp}°C = {result}°F")
    elif choice == 2:
        result = celsius_to_kelvin(input_temp)
        print(f"{input_temp}°C = {result}K")
    elif choice == 3:
        result = fahrenheit_to_celsius(input_temp)
        print(f"{input_temp}°F = {result}°C")
    elif choice == 4:
        result = fahrenheit_to_kelvin(input_temp)
        print(f"{input_temp}°F = {result}K")
    elif choice == 5:
        result = kelvin_to_celsius(input_temp)
        print(f"{input_temp}K = {result}°C")
    elif choice == 6:
        result = kelvin_to_fahrenheit(input_temp)
        print(f"{input_temp}K = {result}°F")

    print("----------------------------------------------")

if __name__ == "__main__":
    main()
