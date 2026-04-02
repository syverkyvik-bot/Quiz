#include "GUI.h"


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
    for(int i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setButtonColor(TDT4102::Color::purple);
        optionButtons[i].setCallback(std::bind(&GUI::checkAnswer, this, i+1));
        add(optionButtons[i]);
    }
    
    nextQuestionButton.setCallback(std::bind(&GUI::nextQuestion,this));
    nextQuestionButton.setButtonColor(TDT4102::Color::yellow);
    add(nextQuestionButton);

    /*
    option1.setCallback(std::bind(&GUI::checkAnswer1,this));
    option2.setCallback(std::bind(&GUI::checkAnswer2,this));
    option3.setCallback(std::bind(&GUI::checkAnswer3,this));
    option4.setCallback(std::bind(&GUI::checkAnswer4,this));
    

    option1.setButtonColor(TDT4102::Color::purple);
    option2.setButtonColor(TDT4102::Color::purple);
    option3.setButtonColor(TDT4102::Color::purple);
    option4.setButtonColor(TDT4102::Color::purple);
    

    add(option1);
    add(option2);
    add(option3);
    add(option4);
    

    */
}

void GUI::displayQuestion(){
    draw_rectangle({90, 70}, 900, 120, TDT4102::Color::gray);
    
    TDT4102::Point location {100, 100};
    std::string message = quiz.getQuestion();
    TDT4102::Color textColor = TDT4102::Color::blue;
    int fontSize = 35;
    TDT4102::Font font = TDT4102::Font::arial;
    draw_text(location, message, textColor, fontSize, font);
}

void GUI::dummy(){}

void GUI::addScore(){
    GUI::score += 1;
}

int GUI::getScore(){
    return GUI::score;
}

void GUI::checkAnswer(int buttonNumber){
    /*
    TDT4102::Button* buttonName;
    switch (buttonNumber) {
        case 1:
            buttonName = &option1;
            break;
        case 2:
            buttonName = &option2;
            break;
        case 3:
            buttonName = &option3;
            break;
        case 4:
            buttonName = &option4;
            break;
    }
*/
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
    /*
    option1.setCallback(std::bind(&GUI::dummy,this));
    option2.setCallback(std::bind(&GUI::dummy,this));
    option3.setCallback(std::bind(&GUI::dummy,this));
    option4.setCallback(std::bind(&GUI::dummy,this));
*/

}
void GUI::checkAnswer1(){
    checkAnswer(1);
}
void GUI::checkAnswer2(){
    checkAnswer(2);
}
void GUI::checkAnswer3(){
    checkAnswer(3);
}
void GUI::checkAnswer4(){
    checkAnswer(4);
}

void GUI::nextQuestion(){
    GUI::nextFrame=true;
}

void GUI::updateOptions(){

    for (int i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setLabel(quiz.getOptions()[i]);
        optionButtons[i].setCallback(std::bind(&GUI::checkAnswer, this, i+1));
        optionButtons[i].setButtonColor(TDT4102::Color::purple);
    }
/*
    option1.setLabel(quiz.getOptions()[0]);
    option2.setLabel(quiz.getOptions()[1]);
    option3.setLabel(quiz.getOptions()[2]);
    option4.setLabel(quiz.getOptions()[3]);

    option1.setCallback(std::bind(&GUI::checkAnswer1, this));
    option2.setCallback(std::bind(&GUI::checkAnswer2, this));
    option3.setCallback(std::bind(&GUI::checkAnswer3, this));
    option4.setCallback(std::bind(&GUI::checkAnswer4, this));

    option1.setButtonColor(TDT4102::Color::purple);
    option2.setButtonColor(TDT4102::Color::purple);
    option3.setButtonColor(TDT4102::Color::purple);
    option4.setButtonColor(TDT4102::Color::purple);
*/
    }

void GUI::displayScore(){
    for (int i = 0; i < optionButtons.size(); i++){
        optionButtons[i].setVisible(false);
    }
    /*
    option1.setVisible(false);
    option2.setVisible(false);
    option3.setVisible(false);
    option4.setVisible(false);
    */
    nextQuestionButton.setVisible(false);
    
    this->next_frame();


    TDT4102::Point location {250, 300};
    std::string message = "your score is: " + std::to_string(GUI::getScore());
    TDT4102::Color textColor = TDT4102::Color::blue;
    int fontSize = 35;
    GUI::draw_text(location, message, textColor, fontSize);    
}

