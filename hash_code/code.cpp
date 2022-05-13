#include <bits/stdc++.h>
using namespace std;
#define ll long long


// function to get skills of a particular person
int skillLevel(map<string, map<string, int>>& players, string name, string skill) {
    int level=0;
    if(players[name].count(skill)) {
        level=players[name][skill];
    }

    return level;
}


vector<string> canBeAssinged(map<string, map<string, int>>& players, vector<pair<string, int>>& projectRequirement) {
    int n=players.size();
    vector<string> ans;     // vector to string the names of the players assigned a project
    vector<string> playerEngaged;
    for(auto skillRqrd: projectRequirement) {
        // bool thisSkill=false;
        for(auto player: players) {
            auto skillName=player.second;
            if(skillLevel(players, player.first, skillRqrd.first) > 0) {
                if(find(playerEngaged.begin(), playerEngaged.end(), player.first) != playerEngaged.end()) {
                    ans.push_back(player.first);
                    playerEngaged.push_back(player.first);
                }

            }
        }
    }
    return ans;
}

// vector<string> canBeAssinged(map<string, map<string, int>>& players, vector<pair<string, int>>& projectRequirement) {
//     int n=players.size();
//     vector<string> ans;     // vector to string the names of the players assigned a project
//     for(auto skillRqrd: projectRequirement) {
//         bool thisSkill=false;
//         for(auto player: players) {
//             if(player.second==skillRqrd.first) {
//                 thisSkill=true;
//                 ans.push_back(player.first);
//             }
//         }
//     }
//     return ans;
// }



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // INPUT SECTION

    int c=0, p=0;
    cin >> c >> p;

    // PLAYER INPUT
    map<string, map<string, int>> players;
    for(int i=0; i < c; ++i) {
        string name;
        cin >> name;
        int noOfSkills=0;
        cin >> noOfSkills;
        map<string, int> skills;
        for(int j=0; j < noOfSkills; ++j) {
            string skill;
            cin >> skill;
            int skillLevel=0;
            cin >> skillLevel;
            skills[skill]=skillLevel;
        }
        players[name]=skills;
    }

    // PROJECT INPUT
    map<string, vector<int>> projects;
    map<string, vector<pair<string, int>>> projectRequirement;
    for(int i=0; i < p; ++i) {
        string name;
        cin >> name;
        vector<int> temp;
        for(int j=0; j < 4; ++j) {
            int x=0;
            cin >> x;
            temp.push_back(x);
        }
        projects[name]=temp;
        for(int i=0; i < temp[3]; ++i) {
            string skill; cin >> skill;
            int level; cin >> level;
            projectRequirement[name].push_back({ skill, level });
        }
    }

    // Checking project requirement input
    // for(auto it: projectRequirement) {
    //     cout << it.first << endl;
    //     for(auto it1: it.second) {
    //         cout << it1.first << " " << it1.second << endl;
    //     }
    // }


    // ALGORITHM SECTION
    // map<string, int> projectAssigned;
    // map<string, int> playerAssigned;
    // for(auto it: projects) {
    //     projectAssigned[it.first]=-1;
    // }

    // for(auto it: players) {
    //     playerAssigned[it.first]=-1;
    // }

    // for(auto it: projects) {
    //     projectAssigned[it.first]=1;
    //     recursiveHelper(projectAssigned, playerAssigned, projects, players, 0, ans);
    //     projectAssigned[it.first]=0;
    // }

    // vector<string> ch=canBeAssinged(players, projectRequirement["WebServer"]);
    // for(auto ele: ch)cout<<ele<<" ";
    unordered_map<string, vector<string>> ans; // to store answer
    // int completed=0;
    // while(projects.size()) {
    //     cout<<projects.size()<<" ";
    for(auto project: projects) {
        vector<string> temp=canBeAssinged(players, projectRequirement[project.first]);
        if(!temp.empty()) {
            // completed++;
            ans[project.first]=temp;
            // projects.erase(project.first);
        }
    }
    // }





    // OUTPUT SECTION


    int projectsExecuted=ans.size();
    cout << projectsExecuted << endl;
    for(auto it: ans) {
        cout << it.first << endl;
        for(int i=0; i < it.second.size(); ++i) {
            if(i == 0)
                cout << it.second[i];
            else
                cout << " " << it.second[i];
        }
        cout << endl;
    }
    return 0;

}