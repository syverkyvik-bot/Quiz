#include "readFIle.h"

using namespace std;

void questions::openFile(ifstream& inputStream){
   
    if (!inputStream){
        cout << "kunne ikke åpne filen" << "\n";
    }
    else{
        cout << "filen er åpen" << "\n";
    }
    
}

void questions::setFullQuestion(ifstream& inputStream){
    questions::fullQuestion.clear();
    getline(inputStream, questions::fullQuestion);
    
    //cout << questions::fullQuestion << "\n"; for debuging
}

void questions::setQuestion(){
    questions::question.clear();
    int i = 0;
    
    while(i < questions::fullQuestion.size() && questions::fullQuestion[i] != '?'){
        questions::question += questions::fullQuestion[i];
        i +=1;
    }
    questions::question += "?";
    //cout << questions::question << "\n"; for debuging
}

void questions::setOptionsAndAnswer(){
    
    questions::options.clear();

    string nextOption;
    int i = questions::question.size(); // +1 for å ikke ta med ?
    
    while(i < questions::fullQuestion.size()-1) { // -1 for å ikke ta med svaret
        if(questions::fullQuestion[i] != ';'){
            nextOption += questions::fullQuestion[i];
        }
        else{
            questions::options.push_back(nextOption);
            nextOption.clear();
        }
        i +=1;
    }
    questions::answer = fullQuestion[i]-48;
}

void questions::setQuestionOptionsAnswer(ifstream& inputStream){
    questions::setFullQuestion(inputStream);
    questions::setQuestion();
    questions::setOptionsAndAnswer();
}

string questions::getQuestion(){
    questions::setQuestion();
    return questions::question;
}

vector<string> questions::getOptions(){
    questions::setOptionsAndAnswer();
    return questions::options;
}

int questions::getAnswer(){
    return questions::answer;
}

ostream& operator << (ostream& os, const questions& p){
    
    os << "question: " << p.question << "options: " << "\n";
    
    for(int i = 0; i < p.options.size(); i++){
        cout << p.options[i] << " ";
    }
    return os;
}

bool questions::isFinished(ifstream& inputStream){
    return inputStream.peek() == EOF;
}
