# Number Guessing Game in Python
# Description: A simple game where the user guesses a number between 1 and 100

import random   # For generating random numbers
import time     # For seeding the random number generator

# This function runs the guessing game
def guess_the_number():
    # Seed the random number generator using current time
    random.seed(time.time())

    # Generate a random number between 1 and 100
    number_to_guess = random.randint(1, 100)

    # Initialize variables
    attempts = 0  # Number of attempts made

    # Display welcome message
    print("--------------------------------------------")
    print(" Welcome to the Number Guessing Game! ")
    print(" I'm thinking of a number between 1 and 100.")
    print(" Try to guess it!")
    print("--------------------------------------------")

    # Start the guessing loop
    while True:
        try:
            guess = int(input("Enter your guess: "))
        except ValueError:
            # Handle invalid input (e.g., letters instead of numbers)
            print("Invalid input! Please enter a number.")
            continue  # Go back to start of loop

        # Count the attempt
        attempts += 1

        # Check the guess and give feedback
        if guess < number_to_guess:
            print("Too low! Try again.")
        elif guess > number_to_guess:
            print("Too high! Try again.")
        else:
            # Correct guess
            print("--------------------------------------------")
            print(" 🎉 Congratulations! You guessed the number! ")
            print(f" It took you {attempts} attempts.")
            print("--------------------------------------------")
            break

# Main function
if __name__ == "__main__":
    # Call the game function
    guess_the_number()
