#include "GUI.h"
#include "Color.h"
#include <cstddef>

//constructor for GUI, initializes the buttons and sets their dimentions, locations and labels
GUI::GUI(TDT4102::Point position, int width, int height, const string& title, questions& obj):
    
    AnimationWindow{position.x, position.y, width, height, title},
    quiz{obj},
    nextQuestionButton{nextQuestionLocation,buttonWidth-100,buttonHeight-20, "Next"},
    optionButtons{
    TDT4102::Button{button1Location,buttonWidth,buttonHeight, obj.getOptions()[0]},
    TDT4102::Button{button2Location,buttonWidth,buttonHeight, obj.getOptions()[1]},
    TDT4102::Button{button3Location,buttonWidth,buttonHeight, obj.getOptions()[2]},
    TDT4102::Button{button4Location,buttonWidth,buttonHeight, obj.getOptions()[3]},
    }
{
    //Sets the color, label color and callback for each button, and adds them to the window
    for(size_t i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setButtonColor(TDT4102::Color::dark_orange);
        optionButtons[i].setCallback(std::bind(&GUI::checkAnswer, this, i+1));
        optionButtons[i].setLabelColor(TDT4102::Color::black);
        add(optionButtons[i]);
    }
    
    nextQuestionButton.setCallback(std::bind(&GUI::nextQuestion,this));
    nextQuestionButton.setButtonColor(TDT4102::Color::yellow);
    nextQuestionButton.setLabelColor(TDT4102::Color::black);
    add(nextQuestionButton);
}

// displays questions from question.txt
void GUI::displayQuestion(){
    draw_rectangle({90, 70}, 900, 120, TDT4102::Color::dark_cyan);
    
    TDT4102::Point location {100, 100};
    std::string message = quiz.getQuestion();
    TDT4102::Color textColor = TDT4102::Color::white;
    int fontSize = 35;
    TDT4102::Font font = TDT4102::Font::arial;
    draw_text(location, message, textColor, fontSize, font);
}

// used for dissabling the buttons
void GUI::dummy(){}

void GUI::addScore(){
    GUI::score += 1;
}

int GUI::getScore(){
    return GUI::score;
}

// compares the answer in question class, with number of the button clicked, and changes color
void GUI::checkAnswer(size_t buttonNumber){

    if (buttonNumber == GUI::quiz.getAnswer()){
        optionButtons[buttonNumber-1].setButtonColor(TDT4102::Color::green);
        GUI::addScore();
        cout << "riktig " << GUI::getScore() <<"\n";
    }
    else{
        cout << "feil" << "\n";
        optionButtons[buttonNumber-1].setButtonColor(TDT4102::Color::red);
    }
    for (int i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setCallback(std::bind(&GUI::dummy,this));
    }

}

void GUI::nextQuestion(){
    GUI::nextFrame=true;
}

// updates the options for the next question
void GUI::updateOptions(){
    for (size_t i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setLabel(quiz.getOptions()[i]);
        optionButtons[i].setCallback(std::bind(&GUI::checkAnswer, this, i+1));
        optionButtons[i].setButtonColor(TDT4102::Color::dark_orange);
    }
}

// displays the score at the end of the quiz
void GUI::displayScore(){
    for (size_t i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setVisible(false);
    }
    
    nextQuestionButton.setVisible(false);
    
    this->next_frame();

    TDT4102::Point location {400, 300};
    std::string message = "your score is: " + std::to_string(GUI::getScore());
    TDT4102::Color textColor = TDT4102::Color::blue;
    int fontSize = 35;
    GUI::draw_text(location, message, textColor, fontSize);
    
    if (GUI::getScore() > 8){
        message = "you are a quiz master!";
    }else{
        message = "you need some more practice!";
    }
    
    location.y += 50;
    location.x -= 50;
    GUI::draw_text(location, message, textColor, fontSize);
    
}

