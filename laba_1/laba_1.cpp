// laba_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include<vector>
#include <fstream>
using namespace std;
class Alph
{
public: vector <char> a = { 't', 'f' };
      char last = 'f';
      char first = 't';
      char Change(char v)
      {
          if (v == last)
              v = first;
          else
          {
              for (int i = 0; i < a.size() - 1; i++)

                  if (a[i] == v)
                  {
                      v = a[i + 1];
                      break;
                  }
          }
          return v;
      }
};

vector<char> nextCombobj(vector<char> comb, Alph a)
{
    for (int i = comb.size() - 1; i >= 0; i--)
    {
        if (comb[i] == a.last)
            comb[i] = a.first;
        else
        {
            comb[i] = a.Change(comb[i]);
            break;
        }
    }
    return comb;
}

bool hasnextCombobj(vector<char> comb)
{
    string s = "";
    for (int i = 0; comb.size() > i; i++)
        s += comb[i];
    if (s == "ffffffffff")
        return false;
    else return true;
}

vector<int> num_arr(vector<string>a)
{
    vector<int>b;
    string s = "";
    for (int i = 0; i < a.size(); i++)
    {
        s = a[i];
        int n = s[10] - '0';
        b.push_back(n);
    }
    return b;
}
vector<string> str_arr(vector<string>a)
{
    vector<string>b;
    string s = "";
    for (int i = 0; i < a.size(); i++)
    {
        s = s.append(a[i], 0, 10);
        b.push_back(s);
        s = "";
    }
    return b;
}
int cong(string s, string g) {
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == g[i])
            k++;
    return k;
}
bool check(vector<string>arr, string s) {
    vector<string>str = str_arr(arr);
    vector<int>num = num_arr(arr);
    int y = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        y = cong(s, str[i]);
        if (y != num[i])
            return false;
    }
    return true;
}
int main()
{
    vector<char> word = { 't','t','t','t','t','t','t','t', 't','t' };
    Alph a = Alph();
    bool f = true;


    ifstream g("input.txt");
    int n = 0;
    g >> n;
    vector<string>arr;
    while (!g.eof())
    {
        string s = "";
        g >> s;
        if (s != "") {
            arr.push_back(s);
        }
    }
    g.close();

    vector<string>ans;
    string word2 = "";
    while (f)
    {
        if (hasnextCombobj(word) == false)
            f = false;

        for (int i = 0; i < word.size(); i++)
            word2 += word[i];
        if (check(arr, word2))
        {
            ans.push_back(word2);
        }
        word2 = "";
        word = nextCombobj(word, a);
    }

    ofstream h("output.txt");
    if (ans.size() == 1)
    {
        h << "ONE SOLUTION" << endl;
        h << ans[0];
    }
    else {
        h << "POSSIBLE SOLUTION" << endl;
        for (int i = 0; i < ans.size(); i++)
            h << ans[i] << endl;
    }
    h.close();
    system("pause");
    //ура сделал..
}
