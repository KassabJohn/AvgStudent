#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    map <string, vector<int>> notes;
    int i;
    notes.begin();
    while(1){
        char tmpNom[256];
        char tmpNote[10];

        vector<int>marks;
        cout << "Entrer un nom d'eleve (ne rien rentrer pour quitter) : " << endl;
        cin.getline(tmpNom,256);

        if (string(tmpNom).size()==0){
            break;
        }

        while(1){
            cout << "Entrer une note (ne rien rentrer pour rentrer les notes d'un nouvel eleve) : " << endl;
            cin.getline(tmpNote,10);
            string str(tmpNote);

            if (str.size()==0){
                break;
            }

            try {
                 i = stoi(str);
                if (i > 0 && i <20)
                {
                marks.push_back(i);
                }
                else
                   {
                    cout << "Entrez une note comprise entre 0 et 20 " << endl;
                }
            }  catch (invalid_argument e) {
                cout << "Veuillez saisir un nombre " << endl;
            }
        }
        notes.insert(pair<string, vector<int>>(tmpNom, marks));
    }

    for (const pair<string, vector<int>> paire : notes) {
        cout << paire.first << " : ";
        int sum = 0;
        for (auto n : paire.second)
        {
            cout << " " << n << " ; ";
            sum += n;
        }

        cout << endl << "Moyenne : "<< sum / paire.second.size() << endl;
    }
}
