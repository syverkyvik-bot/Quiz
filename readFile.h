#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



class questions{

private:

    string fullQuestion;
    string question;
    vector<string> options;
    
    size_t answer;
        
    void setFullQuestion(ifstream& inputStream);
    void setQuestion();
    void setOptionsAndAnswer();
    

public:
    //questions();
    void openFile(ifstream& inputStream); 
    void setQuestionOptionsAnswer(ifstream& inputStream);
    
    string getQuestion();
    vector<string> getOptions();
    size_t getAnswer();
    bool isFinished(ifstream& inputStream);
    friend ostream& operator<<(std::ostream& os, const questions& p);
};

