#include <iostream>
#include <unordered_map>
#include<fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Attribute
{
    string d_type;
    //int lineno;
    int scope_level;
    
    public:

    Attribute()
    {  }
    
    Attribute(string dtype)
    {
        d_type = dtype;
        //lineno = line;
    }
    void print()
    {
        cout << d_type;
    }
    friend class Symtable;
};

class Symtable
{
    vector<unordered_map<string,Attribute>> hashtabs;
    int current_scope_level;

    bool check_level(string id_name, int level)
    {
        unordered_map<string, Attribute>:: iterator itr;
        for (itr = hashtabs[level].begin(); itr != hashtabs[level].end(); itr++)
        {
            if(itr -> first == id_name)
            {
                return true;
            }
        }
        return false;
    }

    public:

    Symtable()
    {
        current_scope_level = -1;
    }
    
    void create()
    {
        ++current_scope_level;
        hashtabs.push_back(unordered_map<string, Attribute>());
    }
    
    void delet()
    {
        if(current_scope_level >= 0)
        {
            for(auto item: hashtabs[current_scope_level])
            {
                cout << item.first << "\t" ;
                item.second.print();
                cout<<"\t"<<current_scope_level<<endl;
            }
            cout<<endl<<endl;
            --current_scope_level;
            hashtabs.pop_back();
        }
    }
    
    int lookup_table(string id_name)
    {
        for (int level = current_scope_level; level >= 0; --level)
        {
            if(check_level(id_name, level))
               return 1;
        }
        
        return 0;
    }
    
    int insert_into_table(string id_name, string data_type)
    {
        if(check_level(id_name,current_scope_level))
        {
            cerr << "Multiple declarations..";
            return 0;
        }
        else
        {
            hashtabs[current_scope_level][id_name] = Attribute(data_type);
            return 1;
        }
    }
};

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

int main()
{
    ifstream fin;
    int k=0;
    string word;
    vector<string> all_token;
    vector<string> select; 
    int flag = 0;
    Symtable st;
    
    unordered_set <string> keywordSet;
    
    keywordSet.insert("main");
    keywordSet.insert("(");
    keywordSet.insert(")");
    // keywordSet.insert("{");
    // keywordSet.insert("}");
    keywordSet.insert("cout");
    keywordSet.insert("cin");
    keywordSet.insert("<<");
    keywordSet.insert(">>");
    keywordSet.insert("<");
    keywordSet.insert(">");
    keywordSet.insert("<=");
    keywordSet.insert(">=");
    keywordSet.insert("==");
    keywordSet.insert("!=");
    // keywordSet.insert("int");
    // keywordSet.insert("real");
    // keywordSet.insert("char");
    keywordSet.insert("+");
    keywordSet.insert("-");
    keywordSet.insert("*");
    keywordSet.insert("/");
    keywordSet.insert("%");
    keywordSet.insert("=");
    keywordSet.insert("if");
    keywordSet.insert("then");
    keywordSet.insert("else");
    keywordSet.insert("and");
    keywordSet.insert("or");
    keywordSet.insert("not");
    // keywordSet.insert(";");
    keywordSet.insert(",");
    keywordSet.insert("VALUE");
    
    
    fin.open("output.txt");
 
    while (fin) {
 
        while(fin >> word)
        {
            if(flag ==1)
            {
                all_token.push_back(word);
                flag = 0;
            }
            
            if(word == "->")
            {
                flag = 1;
            }
            
        }
 
        cout<<all_token;
    }
    cout<<endl<<endl;
    fin.close();
    
    for(unsigned int i = 0; i <all_token.size(); i++)
    {
        // if(str[i] == "{")
        //   st.create();
        
        // if(str[i] == "}")
        //   st.delet();
        
        if (keywordSet.find(all_token[i]) == keywordSet.end())
        {
            //cout<< all_token[i] << " ";
            select.push_back(all_token[i]);
        }
    }
    
    cout<<select<<endl<<endl;
    for(unsigned int i = 0; i <select.size(); i++)
    {
        if(select[i] == "{")
          st.create();
        
        else if(select[i] == "}")
          st.delet();
         
        else if(select[i] == "int" || select[i] == "real" || select[i] == "char")
        {
            int j = i + 1;
            while(select[j]!= ";")
            {
                flag = st.insert_into_table(select[j], select[i]);
                if(flag == 1)
                  cout << "Symbol: "<<select[j]<<" inserted into table successfully!\n";
                j++;
            }
        }
        
        else if(select[i] == ";")
          continue;
        
        else 
        {
            flag = st.lookup_table(select[i]);
            if(flag == 1)
              continue;
            else
              cout << "Error in code.. Usage of "<<select[i]<<" without declaration..\n";
        }
    }
    
    //cout<< select;
    return 0;
    
}