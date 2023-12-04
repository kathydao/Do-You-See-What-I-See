#include "SpeakerView.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
    SpeakerView sv(argv[1], 'd');
    sv.ShowHeights();
    return 0;
} 