#include "interval.ih"

Interval Interval::exact(std::string const &text)
{
    size_t value = stoul(text);

    Interval ret(value, value);
    return ret;
}
