#include "generator.ih"

bool Generator::grep(string const &fileName, string const &regex) const
{
    ifstream in(fileName);
    FBB::Pattern pattern(regex);    
    string line;

    while (getline(in, line))
    {
        if (pattern << line)
            return true;
    }
    return false;
}
