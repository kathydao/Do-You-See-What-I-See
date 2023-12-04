#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.cpp"
#include "FileProcessor.h"

using namespace std;

class SpeakerView{
    public:
    SpeakerView();
    SpeakerView(std::string inputFileName, char descendingOrder);
    virtual ~SpeakerView();
    int countSpaces(const string & str);
    void ShowHeights();

    private:
    FileProcessor* fp;
    MonoStack<double>* stack;
    std::string m_speakerViewString;
    int m_columnLen;
    int m_rowLen;
    char m_descendingOrder;
    double** seats;
    
};

#endif