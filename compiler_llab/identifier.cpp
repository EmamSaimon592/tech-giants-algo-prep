#include<iostream>
using namespace std;

// Keyword check function
bool isKeyword(string str){
    string keywords[] = {
        "int", "float", "double", "char", "if", "else",
        "while", "for", "return", "void", "class"
    };

    int n = sizeof(keywords)/sizeof(keywords[0]);
    for(int i = 0; i < n; i++){
        if(str == keywords[i]){
            return true;
        }
    }
    return false;
}

bool isValid(string str){
    int n = str.length();

    // First character check
    if((str[0]>='a' && str[0]<='z') || 
       (str[0]>='A' && str[0]<='Z') || 
       str[0]=='_'){

        for(int i=1;i<n;i++){
            if((str[i]>='a' && str[i]<='z') || 
               (str[i]>='A' && str[i]<='Z') || 
               str[i]=='_' || 
               (str[i]>='0' && str[i]<='9')){
                continue;
            }
            else{
                return false;
            }
        }

        //  Keyword check
        if(isKeyword(str)){
            return false;
        }

        return true;
    }
    else{
        return false;
    }
}

int main(){
    string str;
    getline(cin,str);

    bool flag = isValid(str);

    if(flag){
        cout<<"Valid Identifier";
    }
    else{
        cout<<"Invalid Identifier";
    }

    return 0;
}