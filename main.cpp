#include "AnimationWindow.h"
#include <iostream>
#include <fstream>
#include "readFile.h"
#include "GUI.h"
using namespace std;


int main(){
/*
    std::cout << "hello";
    

    ofstream MyFile;
    cout << MyFile.is_open() << "\n"; // Displays 0 because the file is not open
    MyFile.open("questions.txt");
    cout << MyFile.is_open() << "\n"; // Displays 1 because the file is open
*/  
/*
    q.setQuestionOptionsAnswer(inputStream);

    string question12 = q.getQuestion(); 
    string option12 = q.getOptions()[0];
    string option22 = q.getOptions()[1]; 
    string option32 = q.getOptions()[2]; 
    string option42 = q.getOptions()[3];  

    cout << question12 << " " << option12 << " " << option22 << " " << option32 << " " << option42 << "\n";
    */

    ifstream inputStream{"questions.txt"};
    questions q;
    
    q.openFile(inputStream);
    q.setQuestionOptionsAnswer(inputStream);      
    
    GUI wm({300,100}, 1100, 700, "Quiz", q);
    wm.displayQuestion();
    
    while(!wm.should_close()){
        wm.next_frame();

        if(wm.nextFrame){
            if(q.isFinished(inputStream)){
                cout << "siste spørsmål";
                wm.wait_for_close();
            }
            else{
                q.setQuestionOptionsAnswer(inputStream);
                wm.updateOptions();
                wm.nextFrame= false;
        
            }
        }
        wm.displayQuestion();
    }
    return 0;
}