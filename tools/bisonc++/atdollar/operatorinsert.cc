#include "atdollar.ih"

std::ostream &operator<<(std::ostream &out, AtDollar const &atd)
{
    out << "At line " << atd.d_lineNr << ", block pos. " << atd.d_pos <<
            ", length: " << atd.d_length << ": " << 
            (atd.d_type == AtDollar::AT ? '@' : '$');

    if (atd.d_id.length())
        out << '<' << atd.d_id << '>';

    if (atd.d_nr == numeric_limits<int>::max())
        out << '$';
    else
        out << atd.d_nr;

    
    if (atd.d_member)
        out << ". (member call)";

    return out;
}
