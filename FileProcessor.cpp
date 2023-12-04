#include "FileProcessor.h"
#include <fstream>

using namespace std;

//FileProcessor class constructor
FileProcessor::FileProcessor(){
    m_inputfileName = "";
}

//FileProcessor class overloaded constructor
FileProcessor::FileProcessor(std::string fileName){
    m_inputfileName = fileName;
}

//FileProcessor class destructor
FileProcessor::~FileProcessor(){  
}

// Takes the string of the text in the input file, handle exceptions, and read each line
std::string FileProcessor::processFile() {
    std::ifstream inputFile(m_inputfileName);
    if (!inputFile.is_open()) {
        return "Error: Unable to open the file.";
    }

    std::string text;
    std::string line;

    while (std::getline(inputFile, line)) {
        text += line + '\n';
    }

    inputFile.close();
    return text;
}

//Take the integer of the number of lines in the input file, and increment the count
int FileProcessor::getNumberofLines(){
    std::ifstream inputFile(m_inputfileName);
    if (!inputFile.is_open()){
        return -1;
    }

    int count = 0;
    std::string line;

    while (std::getline(inputFile, line)){
        count++;
    }

    inputFile.close();
    return count;
}
