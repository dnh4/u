#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];
    std::ifstream inputFile(inputFileName);

    if (!inputFile)
    {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return 1;
    }

    // Read the content of the input file
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // Convert the content to uppercase
    std::transform(content.begin(), content.end(), content.begin(), ::toupper);

    // Create the output file name with "_UPPER" appended
    size_t dotIndex = inputFileName.find_last_of(".");
    std::string outputFileName = inputFileName.substr(0, dotIndex) + "_UPPER" + inputFileName.substr(dotIndex);

    // Write the uppercase content to the output file
    std::ofstream outputFile(outputFileName);
    if (!outputFile)
    {
        std::cerr << "Error creating output file: " << outputFileName << std::endl;
        return 1;
    }
    outputFile << content;

    std::cout << "File converted and saved to: " << outputFileName << std::endl;

    return 0;
}
