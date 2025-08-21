#include <iostream>
#include <string>
#include <vector>

// Function to check if a string is valid UTF-8
bool isValidUTF8(const std::string &input) {
    int expectedBytes = 0;
    for (unsigned char c : input) {
        if (expectedBytes == 0) {
            if ((c >> 5) == 0b110) expectedBytes = 1;
            else if ((c >> 4) == 0b1110) expectedBytes = 2;
            else if ((c >> 3) == 0b11110) expectedBytes = 3;
            else if ((c >> 7)) return false; // invalid 1-byte char
        } else {
            if ((c >> 6) != 0b10) return false;
            expectedBytes--;
        }
    }
    return expectedBytes == 0;
}

// Test helper
void runTest(const std::string &name, const std::string &input, bool expected) {
    bool result = isValidUTF8(input);
    std::cout << "[TEST] " << name << " => " 
              << (result == expected ? "PASSED ✅" : "FAILED ❌") << "\n";
}

int main() {
    std::cout << "UTF-8 Validator Test Suite\n\n";

    // ✅ Valid UTF-8 cases
    runTest("Simple ASCII", "Hello", true);
    runTest("Euro sign (€)", u8"€", true);
    runTest("Japanese (日本語)", u8"日本語", true);

    // ❌ Invalid UTF-8
    std::string bad1 = "\xC3\x28";      // Invalid 2-byte sequence
    std::string bad2 = "\xA0\xA1";      // Continuation without start
    std::string bad3 = "\xE2\x28\xA1";  // Invalid 3-byte sequence
    runTest("Invalid sequence 1", bad1, false);
    runTest("Invalid sequence 2", bad2, false);
    runTest("Invalid sequence 3", bad3, false);

    std::cout << "\nAll tests completed.\n";
    return 0;
}
