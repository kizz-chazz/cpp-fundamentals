#include <iostream>
#include <iomanip>
#include <limits>

// Function 1: Ohm's Law (V = I * R)
void calculateOhmsLaw() {
    int subChoice;
    double v, i, r;

    std::cout << "\n--- Ohm's Law (V = I * R) ---\n";
    std::cout << "1. Calculate Voltage (V)\n";
    std::cout << "2. Calculate Current (I)\n";
    std::cout << "3. Calculate Resistance (R)\n";
    std::cout << "Select unknown quantity (1-3): ";
    std::cin >> subChoice;

    if (subChoice == 1) {
        std::cout << "Enter Current I (Amps): ";
        std::cin >> i;
        std::cout << "Enter Resistance R (Ohms): ";
        std::cin >> r;
        std::cout << "Voltage (V) = " << (i * r) << " V\n";
    } 
    else if (subChoice == 2) {
        std::cout << "Enter Voltage V (Volts): ";
        std::cin >> v;
        std::cout << "Enter Resistance R (Ohms): ";
        std::cin >> r;
        if (r == 0) {
            std::cout << "Error: Resistance cannot be zero (short circuit).\n";
        } else {
            std::cout << "Current (I) = " << (v / r) << " A\n";
        }
    } 
    else if (subChoice == 3) {
        std::cout << "Enter Voltage V (Volts): ";
        std::cin >> v;
        std::cout << "Enter Current I (Amps): ";
        std::cin >> i;
        if (i == 0) {
            std::cout << "Error: Current cannot be zero.\n";
        } else {
            std::cout << "Resistance (R) = " << (v / i) << " Ohms\n";
        }
    } 
    else {
        std::cout << "Invalid option.\n";
    }
}

// Function 2: Series & Parallel Equivalent Resistance
void calculateResistors() {
    int mode, count;
    double value;

    std::cout << "\n--- Equivalent Resistance ---\n";
    std::cout << "1. Series Connection\n";
    std::cout << "2. Parallel Connection\n";
    std::cout << "Select connection type (1 or 2): ";
    std::cin >> mode;

    std::cout << "How many resistors? ";
    std::cin >> count;

    if (count <= 0) {
        std::cout << "Error: Number of resistors must be at least 1.\n";
        return;
    }

    if (mode == 1) {
        double totalSeries = 0.0;
        for (int n = 1; n <= count; ++n) {
            std::cout << "Enter R" << n << " (Ohms): ";
            std::cin >> value;
            totalSeries += value;
        }
        std::cout << "Total Series Resistance = " << totalSeries << " Ohms\n";
    } 
    else if (mode == 2) {
        double reciprocalSum = 0.0;
        for (int n = 1; n <= count; ++n) {
            std::cout << "Enter R" << n << " (Ohms): ";
            std::cin >> value;
            if (value <= 0) {
                std::cout << "Error: Resistor value must be greater than zero.\n";
                return;
            }
            reciprocalSum += (1.0 / value);
        }
        std::cout << "Total Parallel Resistance = " << (1.0 / reciprocalSum) << " Ohms\n";
    } 
    else {
        std::cout << "Invalid connection type.\n";
    }
}

int main() {
    int choice = 0;

    // Format all floating-point results to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    while (true) {
        std::cout << "\n====================================\n";
        std::cout << "  Circuit & Ohm's Law Calculator\n";
        std::cout << "====================================\n";
        std::cout << "1. Ohm's Law (V, I, R)\n";
        std::cout << "2. Series / Parallel Resistors\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            calculateOhmsLaw();
        } 
        else if (choice == 2) {
            calculateResistors();
        } 
        else if (choice == 3) {
            std::cout << "\nExiting calculator. Press Enter to close...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            break;
        } 
        else {
            std::cout << "Invalid selection. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
