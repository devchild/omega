#include "pattern.ih"

Pattern Pattern::escape(States &states, std::string const &ch)
{
    Pair pair = states.next2();

    states[pair.first] = 
        State(
            static_cast<unsigned char>(String::unescape(ch)[0]), 
            pair.second
        );

    Pattern ret(pair);
    ret.d_length = 1;
    return ret;
}
