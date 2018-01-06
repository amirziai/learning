#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://www.hackerrank.com/challenges/magic-spells/problem

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	if (Fireball* s = dynamic_cast<Fireball*>(spell))
        s->revealFirepower();
    else if (Frostbite* s = dynamic_cast<Frostbite*>(spell))
        s->revealFrostpower();
    else if (Waterbolt* s = dynamic_cast<Waterbolt*>(spell))
        s->revealWaterpower();
    else if (Thunderstorm* s = dynamic_cast<Thunderstorm*>(spell))
        s->revealThunderpower();
    else {
        string name = spell->revealScrollName();
        string journal = SpellJournal::read();

        vector<vector<int> > data(name.size() + 1, vector<int>(journal.size() + 1, 0));
        for (int i=1; i <= name.size(); i++) {
            for (int j=1; j <= journal.size(); j++) {
                if (name[i - 1] == journal[j - 1])
                    data[i][j] = data[i - 1][j - 1] + 1;
                else
                    data[i][j] = max(data[i - 1][j], data[i][j - 1]);
            }
        }
        cout << data[name.size()][journal.size()] << endl;
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
