#include "readFile.h"

using namespace std;

void questions::openFile(ifstream& inputStream){
   
    if (!inputStream){
        cout << "kunne ikke åpne filen" << "\n";
    }
    else{
        cout << "filen er åpen" << "\n";
    }
    
}

// gets the whole next line
void questions::setFullQuestion(ifstream& inputStream){
    questions::fullQuestion.clear();
    getline(inputStream, questions::fullQuestion);
    
    //cout << questions::fullQuestion << "\n"; for debuging
}

// gets the questions
void questions::setQuestion(){
    questions::question.clear();
    size_t i = 0;
    
    while(i < questions::fullQuestion.size() && questions::fullQuestion[i] != '?'){
        questions::question += questions::fullQuestion[i];
        i +=1;
    }
    questions::question += "?";
    //cout << questions::question << "\n"; for debuging
}

// gets the options and the answer
void questions::setOptionsAndAnswer(){
    
    questions::options.clear();

    string nextOption;
    size_t i = questions::question.size()+1; // +1 to not include ?
    
    while(i < questions::fullQuestion.size()-1) { // -1 to exclude the answer
        if(questions::fullQuestion[i] != ';'){
            nextOption += questions::fullQuestion[i];
        }
        else{
            questions::options.push_back(nextOption);
            nextOption.clear();
        }
        i +=1;
    }
    questions::answer = fullQuestion[i]-48; // -48 to get char to int
}

// put it all togheter, less in main
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

size_t questions::getAnswer(){
    return questions::answer;
}

// overload for printing the question, options and answer, for debuging
ostream& operator << (ostream& os, const questions& p){
    
    os << "question: " << p.question << "options: " << "\n";
    
    for(size_t i = 0; i < p.options.size(); i++){
        cout << p.options[i] << " ";
    }
    return os;
}

// checks if the file is finished, by checking next char with peek
bool questions::isFinished(ifstream& inputStream){
    return inputStream.peek() == EOF;
}
