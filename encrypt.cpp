#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int index(char letter, vector<char> key){
    for(int i=0; i<key.size(); i++){
        if(key.at(i) == letter){
            return i;
        }
    }
    return -1;
}

int main(){
    string plain_text = "";
    string cipher_text = "";
    string decrpyt = "";
    int ind = 0;
    bool random_key = true;

    std::random_device rd;
    std::mt19937 g(rd());

    vector<char> chars = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',',
                          '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']',
                          '^', '_', '`', '{', '|', '}', '~', '0', '1', '2', '3', '4', '5',
                          '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                          'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                          'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                          'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                          'W', 'X', 'Y', 'Z'};

    vector<char> key = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',',
                          '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']',
                          '^', '_', '`', '{', '|', '}', '~', '0', '1', '2', '3', '4', '5',
                          '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                          'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                          'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                          'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                          'W', 'X', 'Y', 'Z'};

    if(random_key){
        shuffle(key.begin(), key.end(), g);
    }
    else{
        key = {'m','d',',','>','f','Y','W','<','$','@','e','0','?','&',' ','h','`','Z','i',':',
               'J','Q','H','5',')','r','B','#','w','K','y','P','\'','g','x','l','7','{','[','=',
               ';','u','/','"','~','k','F','q','O','c','|','X','\\','1','4','U','o','t','v','(',
               'T','I','L','b','3','9','M','A','6','+','^','%','.',']','E','C','j','V','a','S',
               'n','8','_','G','s','2','!','R','p','D','N','z','-','}','*',};
    }

    //for(const auto n:key) cout<<'\''<<n<<'\''<<','; cout<<'\n';

    cout<<"Message to encrypt: ";
    getline(cin, plain_text);

    cipher_text = ""; 

    for(char n:plain_text){
           ind = index(n, chars);
           cipher_text += key[ind];
    }

    cout<<"\noriginal message: "<<plain_text<<'\n';
    cout<<"encrypted message: "<<cipher_text<<"\n\n";

    cout<<"Message to decrypt: ";
    getline(cin, decrpyt);

    plain_text = "";


    for(char n:decrpyt){
        ind = index(n, key);
        if(ind < 0){
            cout<<"Invalid\n";
            break;
        }
        plain_text += chars[ind];
    }

    cout<<"\nentered message: "<<decrpyt<<'\n';
    cout<<"encrypted message: "<<plain_text<<'\n';
    

    return 0;
}
