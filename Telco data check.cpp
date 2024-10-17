
#include<bits/stdc++.h>
using namespace std;
bool checkPhone (string s){
    if(s.length() != 10) return false;
    for (int i = 0; i < s.length(); i++){
        if(!(s[i] >= '0') && s[i] <= '9') return false;
    }
    return true;
}

int countTime (string stime, string etime){
    int starttime = 3600*(10*(stime[0]-'0') + (stime[1]-'0')) + 60*(10*(stime[3]-'0') + (stime[4]- '0')) + 10*(stime[6]-'0') + (stime[7]-'0');
    int endtime = 3600*(10*(etime[0]-'0') + (etime[1]-'0')) + 60*(10*(etime[3]-'0') + (etime[4]- '0')) + 10*(etime[6]-'0') + (etime[7]-'0');
    return endtime - starttime;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    int totalCalls = 0;
    int incorrectPhone = 0;
    map<string, long int> numberCalls, timeCall; 
    do {
        cin >> input;
        if(input == "#") continue;
        ++totalCalls;
        string fnum, tnum, date, stime, etime;
        cin >> fnum >> tnum >> date >> stime >> etime;
        if (!checkPhone(fnum) || !checkPhone(tnum)) ++incorrectPhone;
        timeCall[fnum] += countTime(stime,etime);
        numberCalls[fnum] ++;
    } while (input != "#");

    do {
        string phone;
        cin >> input;
        if (input == "#") continue;
        if (input == "?check_phone_number"){
            if (incorrectPhone == 0) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (input == "?number_calls_from"){
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        } else if (input == "?number_total_calls")
            cout << totalCalls << endl;
        else if (input == "?count_time_calls_from"){
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    } while (input != "#");
    return 0;
}


