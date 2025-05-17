#include <iostream>
#include <map>
using namespace std;

int main() {
    int n,m;
    map<string,int> pokemon;
    map<int,string> pokemonnum;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        pokemon.insert({s,i});
        pokemonnum.insert({i,s});
    }
    while(m--) {
        string s;
        cin >> s;
        if(pokemon.find(s)!=pokemon.end())
            cout << pokemon.find(s)->second << '\n';
        
        else {
            int u=stoi(s);
            cout << pokemonnum.find(u)->second << '\n';
        }
    }
}