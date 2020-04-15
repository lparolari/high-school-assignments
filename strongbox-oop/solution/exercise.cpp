#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

hash<string> hasher;

class Cassaforte {
   private:
    string username = "admin";
    string password = codifica("admin");
    string segretissimo = "***********\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n***********";
    bool sbloccata = false;  // cosa succede se questo campo viene messo pubblico?

    string codifica(string s) {
        string ss;
        for (int i = 0; i < s.size(); i++) {
            ss.push_back(s[i] + 1);
        }
        return ss;
    }

   public:
    Cassaforte() {
        cout << "DEBUG: (username=" << username << ", password=" << password << ")" << endl;
    }
    void sblocca(string username, string password) {
        if (this->username == username && this->password == codifica(password)) {
            sbloccata = true;
            cout << "Cassaforte sbloccata" << endl;
        } else
            cout << "Credenziali errate" << endl;
    }
    void blocca() {
        if (!sbloccata)
            cout << "Cassaforte già bloccata" << endl;
        else
            cout << "Cassaforte bloccata" << endl;
        sbloccata = false;
    }
    void segreto() {
        if (sbloccata)
            cout << segretissimo << endl;
        else
            cout << "La cassaforte non è sbloccata" << endl;
    }
    void impostaSegreto(string nuovoSegreto) {
        if (sbloccata) {
            segretissimo = nuovoSegreto;
        } else
            cout << "La cassaforte non è sbloccata" << endl;
    }
    void cambiaPassword(string nuovaPassowrd) {
        if (sbloccata)
            password = codifica(nuovaPassowrd);
        else
            cout << "Impossibile cambiare password con la cassaforte bloccata" << endl;
    }
};

int main() {
    Cassaforte cassaforte;

    int op;

    do {
        cout << "Operazione: [1=sblocca, 2=blocca, 3=segreto, 4=cambia segreto, 5=cambia pw,  0=esci]: ";
        cin >> op;
        if (op == 1) {
            string username, password;
            cout << "Username e password: ";
            cin >> username >> password;
            cassaforte.sblocca(username, password);
        }
        if (op == 2) {
            cassaforte.blocca();
        }
        if (op == 3) {
            cassaforte.segreto();
        }
        if (op == 4) {
            string nuovoSegreto;
            cout << "Nuova segreto: ";
            cin >> nuovoSegreto;
            cassaforte.impostaSegreto(nuovoSegreto);
        }
        if (op == 5) {
            string nuovaPw;
            cout << "Nuova pw: ";
            cin >> nuovaPw;
            cassaforte.cambiaPassword(nuovaPw);
        }
    } while (op != 0);

    return 0;
}