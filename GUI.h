#pragma once
#include <iostream>
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "readFIle.h"

using namespace std;

class GUI : public TDT4102::AnimationWindow{
    
    private:
    int buttonWidth = 300;
    int buttonHeight = 100; 
    
    TDT4102::Point button1Location {100, 300};
    TDT4102::Point button2Location {500, 300};
    TDT4102::Point button3Location {100, 500};
    TDT4102::Point button4Location {500, 500};
    TDT4102::Point nextQuestionLocation {850, 500};

    TDT4102::Button option1;
    TDT4102::Button option2;
    TDT4102::Button option3;
    TDT4102::Button option4;
    TDT4102::Button nextQuestionButton;
    
    int score;
    questions& quiz;

    public:
    GUI(TDT4102::Point position, int width, int height, const string& title, questions& obj);
    
    bool nextFrame = false;
    /*
    void addScore();
    int getScore();
*/  
    void updateOptions();
    void displayQuestion();
        
    void checkAnswer1();
    void checkAnswer2();
    void checkAnswer3();
    void checkAnswer4();
    void dummy();

    void nextQuestion();
};

