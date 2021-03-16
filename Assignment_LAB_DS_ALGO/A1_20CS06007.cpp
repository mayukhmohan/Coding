#include<bits/stdc++.h>
using namespace std;
bool dfa_acc(string s, vector<vector<int>> DFA, set<int> final_set_DFA){
    int row = 0;
    for(char c:s){
        row = DFA[row][c-'0'];
    }
    if(final_set_DFA.find(row) != final_set_DFA.end()) return true;
    return false;
}
vector<int> get_states(vector<vector<vector<int>>> NFA, map<int, string> m, int row, int NFA_col){
    string rows = m[row];
    vector<int> ans;
    set<int> s;
    for(int i = 0; i < rows.length(); i++){
        int NFA_row = rows[i] - '0';
        vector<int> temp = NFA[NFA_row][NFA_col];
        for(int state:temp){
            if(s.find(state) == s.end()){
                s.insert(state);
                ans.push_back(state);
            }
        }
    }
    return ans;
}
string equiv_no(vector<int> states_to){
    string temp = "";
    for(int i = 0; i < states_to.size(); i++){
        temp += states_to[i] + '0'; 
    }
    return temp;
}
int main(){
    cout<<"Enter No of States: ";
    int no_of_states_nfa;
    cin>>no_of_states_nfa;
    cout<<"Enter Alphabet Size: ";
    int alphabet_no;
    cin>>alphabet_no;
    cout<<"Enter No of Final States: ";
    int no_of_final_state_nfa;
    cin>>no_of_final_state_nfa;
    set<int> final_state_nfa;
    for(int i = 0; i < no_of_final_state_nfa; i++){
        int temp;
        cout<<"Enter Final State No-"<<i+1<<": ";
        cin>>temp;
        final_state_nfa.insert(temp);
    }
    vector<vector<vector<int>>> NFA(no_of_states_nfa, vector<vector<int>>(alphabet_no, vector<int>(0)));
    for(int i = 0; i < alphabet_no; i++){
        cout<<"Input Transition Function for "<<i<<": ";
        for(int j = 0; j < no_of_states_nfa; j++){
            int no_of_transaction_to;
            cin>>no_of_transaction_to;
            for(int k = 0; k < no_of_transaction_to; k++){
                int temp;
                cin>>temp;
                NFA[j][i].push_back(temp);
            }
        }
    }
    vector<vector<int>> DFA;
    queue<int> q;
    set<string> s;
    set<int> final_state_dfa;
    map<int, string> m1;
    map<string, int> m2;
    int counter = 0;
    q.push(0);
    s.insert("0");
    m1[counter] = "0";
    m2["0"] = counter;
    while(!q.empty()){
        int row = q.front();
        q.pop();
        DFA.push_back({});
        for(int i = 0; i < alphabet_no; i++){
            vector<int> states_to = get_states(NFA, m1, row, i);
            string states_num = equiv_no(states_to);
            if(s.find(states_num) == s.end()){
                s.insert(states_num);
                m1[++counter] = states_num;
                m2[states_num] = counter;
                q.push(counter);
            }
            DFA[row].push_back(m2[states_num]);
        }
    }
    for(int i = 0; i < alphabet_no; i++){
        cout<<"DFA Transition Function for "<<i<<": ";
        for(int j = 0; j < DFA.size(); j++){
            cout<<DFA[j][i]<<"  ";
        }
        cout<<endl;
    }
    cout<<"MAPPINGS:"<<endl;
    for(auto it : m1){
        cout<<it.first<<" == "<<it.second<<endl;
        string states = it.second;
        for(char c:states){
            if(final_state_nfa.find(c - '0') != final_state_nfa.end() && final_state_dfa.find(it.first) == final_state_dfa.end()){
                final_state_dfa.insert(it.first);
            }
        }
    }
    cout<<"Final States in DFA: "<<endl;
    for(int it:final_state_dfa){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"DFA ACCEPTANCE CHECK:"<<endl;
    string check;
    bool flag = true;
    while(flag){
        cout<<"Enter String: ";
        cin>>check;
        if(dfa_acc(check, DFA, final_state_dfa)) cout<<"Accept"<<endl;
        else cout<<"Reject"<<endl;
        cout<<"Press y to continue n to finish......."<<endl;
        cin>>check;
        if(check == "y") continue;
        else if(check == "n") flag = false;
    }
    return 0;
}