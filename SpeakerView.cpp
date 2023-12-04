#include "SpeakerView.h"
#include <sstream>
#include <iostream>
#include <algorithm> 

//SpeakerView class constructor 
SpeakerView::SpeakerView(){
    m_columnLen = 0;
    m_rowLen = 0;
    m_speakerViewString = "";
}

//SpeakerView class overloaded constructor, reading the string from the input file and the monotonic direction 
SpeakerView::SpeakerView(std::string fileName, char descendingOrder){
    fp = new FileProcessor(fileName);
    m_speakerViewString = fp->processFile();
    m_rowLen = fp->getNumberofLines();
    
    m_descendingOrder = descendingOrder;
    
    istringstream text(m_speakerViewString);
    string line;
    getline(text, line);
    m_columnLen = countSpaces(line) + 1;
}

//Count the spaces
int SpeakerView::countSpaces(const string & str){
    int count = 0;
    for (char c : str){
        if (c == ' ') {
            count++;
        }
    }
    return count;
}


//SpeakerView class destructor
SpeakerView::~SpeakerView(){
    if(stack != NULL){
        delete[] stack;
    }

    if(fp != NULL){
        delete fp;
    }
}

//Process the input file, store and manage height values in each column of a monostack 
void SpeakerView::ShowHeights(){
    try {
        std::string toReplace("\n");
        for (int i = 0; i < m_rowLen; i++) {
            size_t pos = m_speakerViewString.find(toReplace);
            if (pos != std::string::npos){
                m_speakerViewString.replace(pos, toReplace.length(), " ");
            } else {
                throw std::runtime_error("Error: '\n' not found in the input string.");
            }
        }

        int startingIndex = 0;
        int currCol = 0;

        for (int i = 0; i < m_columnLen; i++){
            istringstream text(m_speakerViewString);
            std::string del;

            int currentIndex = -1;
            stack = new MonoStack<double>(m_rowLen, m_descendingOrder);

            while (getline(text, del, ' ')){
                currentIndex++;

                if (currentIndex > m_columnLen - 1){
                    currentIndex = 0;
                }

                if (currentIndex != currCol){
                    continue;
                } else if (currentIndex == currCol){
                    stack->push(stod(del));
                }
            }

            cout << "There are: ";
            cout << stack->getTopCount() + 1;
            cout << " person(s) that can see in column: " + to_string(i) + ". Their heights are: ";
            int iterations = stack->getTopCount();

            if (stack->size() > 0){
                for (int j = 0; j < iterations; j++){
                    cout << stack->getStackArr()[j];
                    cout << ", ";
                }
                cout << stack->getStackArr()[iterations] << ".\n";
            } else {
                cout << to_string(stack->pop());
                cout << ".\n";
            }

            currCol++;

            delete stack;
            stack = nullptr;
        }
    } catch (const std::exception& e){
        cerr << "Error: " << e.what() << endl;
    }
}
