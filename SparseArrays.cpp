#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<string> s = strings;
    vector<string> q = queries;
    int count = 0;
    vector<int> results;                  //Vector to hold the count for each query
        
    for(int i=0; i<q.size(); i++){        //For every string in q
        for(int j = 0; j<s.size(); j++){  //Comapre it to every string in s

            if(q[i] == (s[j])){           //Compare the two string
                count = count + 1;        //If it is a match increment the count
            }
        }
        results.insert(results.begin()+i, count);   
        count = 0;                        //Reset count for next comparison
    }
    return results;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}