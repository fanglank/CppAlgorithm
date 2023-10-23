#include <vector>
using namespace std;
bool areAllZero(vector<int> counts)
{
    for (int count : counts)
    {
        if (count != 0)
        {
            return false;
        }
    }

    return true;
}

bool checkInclusion(string &s1, string &s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }
    vector<int> counts(26, 0);

    for (int i = 0; i < s1.length(); i++)
    {
        counts[s1[i] - 'a']++;
        counts[s2[i] - 'a']--;
    }

    for (int i = s1.length(); i < s2.length(); i++)
    {
        counts[s2[i] - 'a']--;
        counts[s2[i - s1.length()] - 'a']++;
        if (areAllZero(counts))
        {
            return true;
        }
    }
    return false;
}

vector<int> findAnagrams(string s1, string s2)
{
    vector<int> indices;
    if (s1.length() < s2.length())
    {
        return indices;
    }

    vector<int> counts(26, 0);
    int i = 0;
    for (; i < s2.length(); i++)
    {
        counts[s2[i] - 'a']++;
        counts[s1[i] - 'a']--;
    }

    if (areAllZero(counts))
    {
        indices.push_back(0);
    }
    for (; i < s1.length(); i++)
    {
        counts[s1[i] - 'a']--;
        counts[s1[i - s2.length()] - 'a']++;
        if (areAllZero(counts))
        {
            indices.push_back(i - s2.length() + 1);
        }
    }
}