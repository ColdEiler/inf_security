
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string f(string s, vector<string> d)
{
    string g = " ";
    int y = 0;
    if (s.size() == 1) {
        for (int i = 0; i < d.size(); i++)
            if (d[i].size() == 1)
                y++;
    }
    string h = " ", b = " ", word = " ", word_2 = " ", ans = "";
    for (int i = 0; i < d.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            h = s;
            if (s.size() > 1) {
                h = h.erase(j, 1);
            }
            for (int k = 0; k < d.size(); k++)
                if (h == d[i])
                {
                    word = d[i];
                    y++;
                    break;
                }
            for (int k = 0; k < d[i].size(); k++)
            {
                b = d[i];
                b = b.erase(k, 1);

                if (h == b)
                {
                    word_2 = d[i];
                    y++;
                    if (i == d.size() - 1)
                        break;
                    else i++;
                }
            }
        }
    }

    if (word == " ")
        ans = word_2;
    else ans = word;

    if (y == 0 || y > 1)
        g += s + " " + to_string(y);
    else
        g += s + " " + to_string(y) + " " + ans;

    return g;
}

int main()
{
    /*vector<string>dict;
    vector<string>text;
    int n, m;
    ifstream g("input.txt");
    g >> n; g >> m;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        g >> s;
        dict.push_back(s);
    }
    for (int i = 0; i < m; i++)
    {
        g >> s;
        text.push_back(s);
    }
    g.close();

    s = "";
    ofstream y("output.txt");
    for (int i = 0; i < text.size(); i++)
    {
        s = f(text[i], dict);
        y << s << endl;
    }*/
    cout << " RRR" << endl;

}
