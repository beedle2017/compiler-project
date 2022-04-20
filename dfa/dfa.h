#include<iostream>
#include<vector>

using namespace std;

void testing(){
    cout<<"testing"<<endl;
}

class State {
    int stateId;
    string tokenClass;
    vector<pair<char, int>> nextStates;    // each element will look like <char, nextStateID>
    int isFinal;

    public:
        State(int id){
            stateId = id;
            tokenClass = "";
            isFinal = false;
        }

        int getIsFinal(){
            return isFinal;
        }

        void setFinal() {
            isFinal = true;
        }

        void unSetFinal() {
            isFinal = false;
        }

        void setTokenClassForFinalState(string token){
            tokenClass = token;
        }

        string getTokenClassForFinalStates(){
            return tokenClass;
        }

        int getId(){
            return stateId;
        }

        void setId(int id){
            stateId = id;
        }

        void setNextStates(char ch, State nextState){    
            nextStates.push_back(make_pair(ch, nextState.getId()));
        }

        vector<pair<char, int>> getNextStates(){
            return nextStates;
        }

        State next(char ch){
            for(auto item:nextStates){
                if(item.first == ch){
                    return item.second;
                }
            }
            return State(-1);
        }

        friend ostream& operator<<(ostream &out, State state){
            out << state.getId() << " " << state.getIsFinal() << " " << state.getTokenClassForFinalStates();
            return out;
        }
};


class DFA {
    int startId;
    vector<State> statesList;

    public:
        DFA(){
            startId = 0;
        }

        void setStartID(int id){
            startId = id;
        }

        int getStartID(){
            return startId;
        }

        int addNewStateToDFA(int final, string t_class){
            State *newState = new State(statesList.size());
            if(final){
                newState->setFinal();
            }
            newState->setTokenClassForFinalState(t_class);

            statesList.push_back(*newState);
            return newState->getId();
        }

        void addNextStateForAState(int fromState, int toState, vector <char> v)
        {
            for(char c:v)   addNextStateForAState(fromState, toState, c);
        }

        void addNextStateForAState(int fromState, int toState, char ch){
            statesList[fromState].setNextStates(ch, statesList[toState]);
        }

        State* getStateById(int id){
            return &statesList[id];
        }

        // checks if there is any next state for a particular id on given input
        bool isNextStatePresentForGivenInput(int id, char ch){
            State state = statesList[id];
            for(auto item:state.getNextStates()){
                if(item.first == ch){
                    return true;
                }
            }
            return false;
        }

        vector<State> getStateList(){
            return statesList;
        }
};