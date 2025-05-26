#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Important for std::numeric_limits

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int targetNumber = rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100. Try to guess it.\n";

    while (userGuess != targetNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input! Please enter a number.\n";
        } else {
            if (userGuess < targetNumber) {
                std::cout << "Too low! Try again.\n";
            } else if (userGuess > targetNumber) {
                std::cout << "Too high! Try again.\n";
            } else {
                std::cout << "Congratulations! You guessed the correct number: " << targetNumber << "\n";
            }
        }
    }

    return 0;
}
