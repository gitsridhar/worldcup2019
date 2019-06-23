#include <iostream>
#include <vector>

using namespace std;

#define WIN 0
#define ENG 1
#define SOA 2
#define AUS 3
#define NZL 4
#define AFG 5
#define PAK 6
#define IND 7
#define BAN 8
#define SLA 9

string country(int n) {
    switch(n) {
        case 0: return "WIN";
        case 1: return "ENG";
        case 2: return "SOA";
        case 3: return "AUS";
        case 4: return "NZL";
        case 5: return "AFG";
        case 6: return "PAK";
        case 7: return "IND";
        case 8: return "BAN";
        case 9: return "SLA";
    }
    return NULL;
}

int index(string str) {
   if (str == "WIN") return 0;
   if (str == "ENG") return 1;
   if (str == "SOA") return 2;
   if (str == "AUS") return 3;
   if (str == "NZL") return 4;
   if (str == "AFG") return 5;
   if (str == "PAK") return 6;
   if (str == "IND") return 7;
   if (str == "BAN") return 8;
   if (str == "SLA") return 9;
   return -1;
}

vector<string> printremainingmatches(vector<string> remainingmatches, string team, vector<string> sortedpoints) {
    vector<string> retval;
    string pointval;
    for(int i=0; i<10; i++) {
        string point = sortedpoints[i];
        if (team == point.substr(2,3)) {
            pointval = point.substr(0,2);
            break;
        }
    }

    cout << "Team : " << team << " Points : " << pointval << endl;
    for(int i=0; i<remainingmatches.size(); i++) {
        string match = remainingmatches[i];
        //cout << match << " " << match.substr(0,3) << " " << match.substr(3,3) << endl;
        if (team == match.substr(0,3) || team == match.substr(3,3)) {
            if (team == match.substr(0,3)) {
                cout << match.substr(0,3) << " vs " << match.substr(3,3) << endl;
            } else {
                cout << match.substr(3,3) << " vs " << match.substr(0,3) << endl;
            }
            retval.push_back(match);
        }
    }
    return retval;
}

int main() {
    int tournament[10][10];

    // 0 West Indies
    tournament[0][WIN] = 0; //self
    tournament[0][ENG] = 0;
    tournament[0][SOA] = 1;
    tournament[0][AUS] = 0;
    tournament[0][NZL] = 0;
    tournament[0][AFG] = -1;
    tournament[0][PAK] = 2;
    tournament[0][IND] = -1;
    tournament[0][BAN] = 0;
    tournament[0][SLA] = -1;
    
    // 1 England
    tournament[1][WIN] = 2;
    tournament[1][ENG] = 0; //self
    tournament[1][SOA] = 2;
    tournament[1][AUS] = -1;
    tournament[1][NZL] = -1;
    tournament[1][AFG] = 2;
    tournament[1][PAK] = 0;
    tournament[1][IND] = -1;
    tournament[1][BAN] = 2;
    tournament[1][SLA] = 0;
    
    // 2 South Africa
    tournament[2][WIN] = 1;
    tournament[2][ENG] = 0;
    tournament[2][SOA] = 0; //self
    tournament[2][AUS] = -1;
    tournament[2][NZL] = 0;
    tournament[2][AFG] = 2;
    tournament[2][PAK] = -1;
    tournament[2][IND] = 0;
    tournament[2][BAN] = 0;
    tournament[2][SLA] = -1;
    
    // 3 Australia 
    tournament[3][WIN] = 2;
    tournament[3][ENG] = -1;
    tournament[3][SOA] = -1;
    tournament[3][AUS] = 0; //self
    tournament[3][NZL] = -1;
    tournament[3][AFG] = 2;
    tournament[3][PAK] = 2;
    tournament[3][IND] = 0;
    tournament[3][BAN] = 2;
    tournament[3][SLA] = 2;
    
    // 4 NewZealand
    tournament[4][WIN] = 2;
    tournament[4][ENG] = -1;
    tournament[4][SOA] = 2;
    tournament[4][AUS] = -1;
    tournament[4][NZL] = 0; //self
    tournament[4][AFG] = 2;
    tournament[4][PAK] = -1;
    tournament[4][IND] = 1;
    tournament[4][BAN] = 2;
    tournament[4][SLA] = 2;
    
    // 5 Afganistan
    tournament[5][WIN] = -1;
    tournament[5][ENG] = 0;
    tournament[5][SOA] = 0;
    tournament[5][AUS] = 0;
    tournament[5][NZL] = 0;
    tournament[5][AFG] = 0; //self
    tournament[5][PAK] = -1;
    tournament[5][IND] = 0;
    tournament[5][BAN] = -1;
    tournament[5][SLA] = 0;
    
    // 6 Pakistan
    tournament[6][WIN] = 0;
    tournament[6][ENG] = 2;
    tournament[6][SOA] = -1;
    tournament[6][AUS] = 0;
    tournament[6][NZL] = -1;
    tournament[6][AFG] = -1;
    tournament[6][PAK] = 0; //self
    tournament[6][IND] = 0;
    tournament[6][BAN] = -1;
    tournament[6][SLA] = 1;
    
    // 7 India
    tournament[7][WIN] = -1;
    tournament[7][ENG] = -1;
    tournament[7][SOA] = 2;
    tournament[7][AUS] = 2;
    tournament[7][NZL] = 1;
    tournament[7][AFG] = 2;;
    tournament[7][PAK] = 2;
    tournament[7][IND] = 0; //self
    tournament[7][BAN] = -1;
    tournament[7][SLA] = -1;
    
    // 8 Bangladesh
    tournament[8][WIN] = 2;
    tournament[8][ENG] = 0;
    tournament[8][SOA] = 2;
    tournament[8][AUS] = 0;
    tournament[8][NZL] = 0;
    tournament[8][AFG] = -1;
    tournament[8][PAK] = -1;
    tournament[8][IND] = -1;
    tournament[8][BAN] = 0; //self
    tournament[8][SLA] = 1;
    
    // 9 SriLanka
    tournament[9][WIN] = -1;
    tournament[9][ENG] = 2;
    tournament[9][SOA] = -1;
    tournament[9][AUS] = 0;
    tournament[9][NZL] = 0;
    tournament[9][AFG] = 2;
    tournament[9][PAK] = 1;
    tournament[9][IND] = -1;
    tournament[9][BAN] = 1;
    tournament[9][SLA] = 0; //self
    

tournament[WIN][AFG] = 2;
tournament[AFG][WIN] = 0;

tournament[WIN][IND] = 2;
tournament[IND][WIN] = 0;

tournament[WIN][SLA] = 2;
tournament[SLA][WIN] = 0;

tournament[ENG][AUS] = 0; // imp.
tournament[AUS][ENG] = 2;

tournament[ENG][NZL] = 0; // imp.
tournament[NZL][ENG] = 2;

tournament[ENG][IND] = 0; // imp.
tournament[IND][ENG] = 2;

tournament[SOA][AUS] = 2; // ok
tournament[AUS][SOA] = 0;

tournament[SOA][PAK] = 0; // ok
tournament[PAK][SOA] = 2;

tournament[SOA][SLA] = 0; // ok
tournament[SLA][SOA] = 2;

tournament[AUS][NZL] = 2;
tournament[NZL][AUS] = 0;

tournament[NZL][PAK] = 2;
tournament[PAK][NZL] = 0;

tournament[AFG][PAK] = 0;
tournament[PAK][AFG] = 2;

tournament[AFG][BAN] = 0;
tournament[BAN][AFG] = 2;

tournament[PAK][BAN] = 2;
tournament[BAN][PAK] = 0;

tournament[IND][BAN] = 2;
tournament[BAN][IND] = 0;

tournament[IND][SLA] = 2;
tournament[SLA][IND] = 0;


    vector<string> sortedpoints;
    vector<string> remainingmatches;

    for(int i=0; i<10; i++) {
        int points = 0;

        for(int j=0; j<10; j++) {
            if (tournament[i][j] != -1) {
                points += tournament[i][j];
            } else {
                vector<string>::iterator it1 = find(remainingmatches.begin(), remainingmatches.end(), country(i)+country(j));
                vector<string>::iterator it2 = find(remainingmatches.begin(), remainingmatches.end(), country(j)+country(i));
                if (it1 == remainingmatches.end() && it2 == remainingmatches.end()) {
                    remainingmatches.push_back(country(i)+country(j));
                }
            }
        }

        char buffer[256]; sprintf(buffer, "%02d", points);
        string str(buffer);
        string value = str + country(i);
        sortedpoints.push_back(value);
    }

    sort(sortedpoints.rbegin(), sortedpoints.rend());

    //cout << "Remaining matches" << endl;

    //for(int i=0; i<remainingmatches.size(); i++) {
    //    cout << remainingmatches[i] << endl;
    //}

    vector<string> winmatches = printremainingmatches(remainingmatches, "WIN", sortedpoints);
    vector<string> engmatches = printremainingmatches(remainingmatches, "ENG", sortedpoints);
    vector<string> soamatches = printremainingmatches(remainingmatches, "SOA", sortedpoints);
    vector<string> ausmatches = printremainingmatches(remainingmatches, "AUS", sortedpoints);
    vector<string> nzlmatches = printremainingmatches(remainingmatches, "NZL", sortedpoints);
    vector<string> afgmatches = printremainingmatches(remainingmatches, "AFG", sortedpoints);
    vector<string> pakmatches = printremainingmatches(remainingmatches, "PAK", sortedpoints);
    vector<string> indmatches = printremainingmatches(remainingmatches, "IND", sortedpoints);
    vector<string> banmatches = printremainingmatches(remainingmatches, "BAN", sortedpoints);
    vector<string> slamatches = printremainingmatches(remainingmatches, "SLA", sortedpoints);

    cout << "-----" << endl;
    for(int i=0; i<10; i++) {
        cout << sortedpoints[i].substr(2,3) << " " << sortedpoints[i].substr(0,2) << endl;
        if (i == 3) {
            cout << "-----" << endl;
        }
    }

    cout << "-----" << endl;
    return(0);
}

