#include <iostream>
#include <thread>
#include <vector>

using namespace std;

string addSpaces(string str){
    for (int i = 0; i < 100; i++){
        str += ' ';
    }
    return str;
}

string toLowerCase(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str[i]>='A' && str[i]<='Z'){
            str[i] = str[i] + 32;
        }
    }
    return str;
}

string deletePunctuation(string str){
    string newstr = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i]!='.' && str[i]!=','
            && str[i]!='?' && str[i]!='!' && str[i]!=';'){
            newstr = newstr + str[i];
        }
    }
    return newstr;
}

string numbersToText(string str){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1'){
            str[i] = 'u';
            char second = 'n';
            for(int j = i + 1; j < str.length() ; j++){
                char c = str[j];
                str[j] = second;
                second = c;
            }
        i += 2;
        }
        if (str[i] == '2'){
            str[i] = 'd';
            char fourth = 'x';
            for(int j = i + 1; j < str.length() ; j++){
                char c = str[j];
                str[j] = fourth;
                fourth = c;
            }
            char third = 'u';
            for(int j = i + 1; j < str.length() ; j++){
                char c = str[j];
                str[j] = third;
                third = c;
            }
            char second = 'e';
            for(int j = i + 1; j < str.length() ; j++){
                char c = str[j];
                str[j] = second;
                second = c;
            }
        i += 4;
        }
    }
    return str;
}

string deleteDoubleSpaces(string str){
    for(int i=str.length()-1; i >= 0; i-- ){
        if(str[i]==' '&&str[i]==str[i-1])
        {
            str.erase( str.begin() + i );
        }
    }
    return str;
}

int main(int ac, char** av){
    string s = "Hello, 1 2, WoRld?!";
    cout << "String before: "<<endl<< s << endl;
    s = addSpaces(s);
    s = toLowerCase(s);
    s = numbersToText(s);
    s = deletePunctuation(s);
    s = deleteDoubleSpaces(s);
    cout << "String after: "<<endl<< s << endl;
}