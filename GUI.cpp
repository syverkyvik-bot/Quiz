#include "GUI.h"


GUI::GUI(TDT4102::Point position, int width, int height, const string& title, questions& obj):
    
    AnimationWindow{position.x, position.y, width, height, title},
    quiz{obj},
    //questionBox{{100, 100}, 500, 100, ""},
    option1{button1Location,buttonWidth,buttonHeight, obj.getOptions()[0]},
    option2{button2Location,buttonWidth,buttonHeight, obj.getOptions()[1]},
    option3{button3Location,buttonWidth,buttonHeight, obj.getOptions()[2]},
    option4{button4Location,buttonWidth,buttonHeight, obj.getOptions()[3]},
    nextQuestionButton{nextQuestionLocation,buttonWidth-100,buttonHeight-20, "Next"}
    
{
    option1.setCallback(std::bind(&GUI::checkAnswer1,this));
    option2.setCallback(std::bind(&GUI::checkAnswer2,this));
    option3.setCallback(std::bind(&GUI::checkAnswer3,this));
    option4.setCallback(std::bind(&GUI::checkAnswer4,this));
    nextQuestionButton.setCallback(std::bind(&GUI::nextQuestion,this));

    option1.setButtonColor(TDT4102::Color::purple);
    option2.setButtonColor(TDT4102::Color::purple);
    option3.setButtonColor(TDT4102::Color::purple);
    option4.setButtonColor(TDT4102::Color::purple);
    nextQuestionButton.setButtonColor(TDT4102::Color::yellow);

    //add(questionBox);
    add(option1);
    add(option2);
    add(option3);
    add(option4);
    add(nextQuestionButton);
}

void GUI::displayQuestion(){
    draw_rectangle({90, 70}, 900, 120, TDT4102::Color::gray);
    
    TDT4102::Point location {100, 100};
    std::string message = quiz.getQuestion();
    TDT4102::Color textColor = TDT4102::Color::blue;
    int fontSize = 50;
    TDT4102::Font font = TDT4102::Font::arial;
    draw_text(location, message, textColor, fontSize, font);
    
    //questionBox.setText(quiz.getQuestion());
    
}

void GUI::dummy(){}

void GUI::addScore(){
    GUI::score += 1;
}

int GUI::getScore(){
    return GUI::score;
}

void GUI::checkAnswer1(){
    int number = 1;
    if (number == GUI::quiz.getAnswer()){
        option1.setButtonColor(TDT4102::Color::green);
        GUI::addScore();
        cout << "riktig " << GUI::getScore() <<"\n";
    }
    else{
        cout << "feil" << "\n";
        option1.setButtonColor(TDT4102::Color::red);
    }
    option1.setCallback(std::bind(&GUI::dummy,this));
    option2.setCallback(std::bind(&GUI::dummy,this));
    option3.setCallback(std::bind(&GUI::dummy,this));
    option4.setCallback(std::bind(&GUI::dummy,this));
}
void GUI::checkAnswer2(){
    int number = 2;
    if (number == GUI::quiz.getAnswer()){
        option2.setButtonColor(TDT4102::Color::green);
        GUI::addScore();
        cout << "riktig " << GUI::getScore() <<"\n";
    }
    else{
        cout << "feil" << "\n";
        option2.setButtonColor(TDT4102::Color::red);
    }
    option1.setCallback(std::bind(&GUI::dummy,this));
    option2.setCallback(std::bind(&GUI::dummy,this));
    option3.setCallback(std::bind(&GUI::dummy,this));
    option4.setCallback(std::bind(&GUI::dummy,this));
}
void GUI::checkAnswer3(){
    int number = 3;
    if (number == GUI::quiz.getAnswer()){
        option3.setButtonColor(TDT4102::Color::green);
        GUI::addScore();
        cout << "riktig " << GUI::getScore() <<"\n";
    }
    else{
        cout << "feil" << "\n";
        option3.setButtonColor(TDT4102::Color::red);
    }
    option1.setCallback(std::bind(&GUI::dummy,this));
    option2.setCallback(std::bind(&GUI::dummy,this));
    option3.setCallback(std::bind(&GUI::dummy,this));
    option4.setCallback(std::bind(&GUI::dummy,this));
}
void GUI::checkAnswer4(){
    int number = 4;
    if (number == GUI::quiz.getAnswer()){
        option4.setButtonColor(TDT4102::Color::green);
        GUI::addScore();
        cout << "riktig " << GUI::getScore() <<"\n";
    }
    else{
        cout << "feil" << "\n";
        option4.setButtonColor(TDT4102::Color::red);
    }
    option1.setCallback(std::bind(&GUI::dummy,this));
    option2.setCallback(std::bind(&GUI::dummy,this));
    option3.setCallback(std::bind(&GUI::dummy,this));
    option4.setCallback(std::bind(&GUI::dummy,this));
}

void GUI::nextQuestion(){
    GUI::nextFrame=true;
}

void GUI::updateOptions(){
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
}

void GUI::displayScore(){
    option1.setVisible(false);
    option2.setVisible(false);
    option3.setVisible(false);
    option4.setVisible(false);
    nextQuestionButton.setVisible(false);
    
    this->next_frame();


    TDT4102::Point location {250, 300};
    std::string message = "your score is: " + std::to_string(GUI::getScore());
    TDT4102::Color textColor = TDT4102::Color::blue;
    int fontSize = 80;
    GUI::draw_text(location, message, textColor, fontSize);    
}

