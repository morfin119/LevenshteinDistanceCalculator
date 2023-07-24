#include <iostream>
#include <string>
#include <algorithm>

// Function to calculate the Levenshtein distance between two strings
// Parameters:
//   str1: The first input string.
//   str2: The second input string.
// Returns:
//   The Levenshtein distance between str1 and str2.
size_t levenshteinDistance(const std::string& str1, const std::string& str2)
{
    const size_t lengthStr1 = str1.length();
    const size_t lengthStr2 = str2.length();

    const size_t rows = lengthStr1 + 1;
    const size_t columns = lengthStr2 + 1;

    std::vector<size_t> distanceMatrix(rows * columns);
    size_t cost;

    for (size_t i = 0; i < rows; i++)
    {
        distanceMatrix[i * columns] = i;
    }
    for (size_t j = 0; j < columns; j++)
    {
        distanceMatrix[j] = j;
    }

    for (size_t i = 1; i < rows; i++)
    {
        for (size_t j = 1; j < columns; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                cost = 0;
            else
                cost = 1;

            distanceMatrix [i * columns + j] = std::min(std::min(
                distanceMatrix[(i - 1) * columns + j] + 1,
                distanceMatrix[i * columns + (j - 1)] + 1),
                distanceMatrix[(i - 1) * columns + (j - 1)] + cost);
        }
    }

    return distanceMatrix[lengthStr1 * columns + lengthStr2];
}

int main(int argc, char** argv)
{
    // Ensure that the user's input is valid, and display a straightforward help message if it is invalid.
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
        std::cout << "This program calculates the Levenshtein distance between two strings." << std::endl;
        return -1;
    }

    std::cout << levenshteinDistance(argv[1], argv[2]);

    return 0;
}
