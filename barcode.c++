#include <iostream>
#include <string>

// Simple Caesar Cipher Encryption function
std::string encryptData(const std::string& input, int shift) {
    std::string encrypted = input;
    for (char& c : encrypted) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (c - offset + shift) % 26 + offset;
        } else if (isdigit(c)) {
            c = (c - '0' + shift) % 10 + '0';
        }
    }
    return encrypted;
}

void generateBarcode(const std::string& input) {
    std::cout << "Barcode for: " << input << std::endl;
    for (char c : input) {
        // Convert each character to ASCII and then to binary
        int value = static_cast<int>(c);
        for (int i = 7; i >= 0; --i) {
            if (value & (1 << i)) {
                std::cout << "|"; // Dark block for 1
            } else {
                std::cout << " "; // Space for 0
            }
        }
        std::cout << " "; // Space between characters
    }
    std::cout << std::endl;
}

bool isValidInput(const std::string& input) {
    if (input.empty()) {
        return false; // Input should not be empty
    }
    for (char c : input) {
        if (!isalnum(c)) { // Only allow letters and digits
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;
    int shift = 3; // Shift value for Caesar Cipher encryption

    std::cout << "Enter text to generate barcode: ";
    std::getline(std::cin, input);

    // Validate input
    if (!isValidInput(input)) {
        std::cerr << "Invalid input! Please enter only alphanumeric characters." << std::endl;
        return 1; // Exit with an error code
    }

    // Encrypt the input data before generating the barcode
    std::string encryptedData = encryptData(input, shift);
    std::cout << "Encrypted data: " << encryptedData << std::endl;

    // Generate barcode for encrypted data
    generateBarcode(encryptedData);

    return 0;
}
