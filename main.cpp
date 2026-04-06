#include "AnimationWindow.h"
#include <iostream>
#include <fstream>
#include "readFile.h"
#include "GUI.h"
using namespace std;


int main(){

    // opens the file, and sets the first question, options and answer
    ifstream inputStream{"questions.txt"};
    questions q;
    
    q.openFile(inputStream);
    q.setQuestionOptionsAnswer(inputStream);      
    
    // creates the window, and displays the first question
    GUI wm({300,100}, 1100, 700, "Quiz", q);
    wm.displayQuestion();
    
    // main loop, checks for events and displays the next question when nextFrame is true, which happens when the next question button is clicked
    while(!wm.should_close()){
        wm.next_frame();
        wm.displayQuestion();

        if(wm.nextFrame){
            if(q.isFinished(inputStream)){
                wm.displayScore();
                wm.wait_for_close();
            }
            else{
                q.setQuestionOptionsAnswer(inputStream);
                wm.updateOptions();
                wm.nextFrame= false;
                wm.displayQuestion();
            }
        }
    }
    return 0;
}