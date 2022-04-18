#include<iostream>
#include<vector>

using namespace std;

class State {
    int stateId;
    string tokenClass;     
    vector<pair<char, State>> nextStates;    // each element will look like <char, nextState>
    bool isFinal;

    public:
        State(int id){
            stateId = id;
            tokenClass = "";
            isFinal = false;
        }

        bool getIsFinal(){
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
            nextStates.push_back(make_pair(ch, nextState));
        }

        vector<pair<char, State>> getNextStates(){
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

        int addNewStateToDFA(bool final, string t_class){
            State *newState = new State(statesList.size());
            if(final){
                newState->setFinal();
            }   
            newState->setTokenClassForFinalState(t_class);

            statesList.push_back(*newState);
            return newState->getId();
        }

        void addNextStateForAState(int fromState, int toState, char ch){
            statesList[fromState].setNextStates(ch, statesList[toState]);
        }

        State getStateById(int id){
            return statesList[id];
        }

        bool isNextStatePresentForGivenInput(int id, char ch){
            State state = statesList[id];
            for(auto item:state.getNextStates()){
                if(item.first == ch){
                    return true;
                }
            }
            return false;
        }
};


// tokens = ["EOF", "VALUE", "relational_op", "ID", .....]
// b = [[2, 3, "y"], [], []]

// tokens = [tokenClasses]
// 
// b = [[fromStateId, toStateId, readCharacter]]

// andy

// i -> 