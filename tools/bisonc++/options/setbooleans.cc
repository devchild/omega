#include "options.ih"

void Options::setBooleans()
{
    if (d_arg.option(0, "debug"))
        d_debug = true;

    if (d_arg.option('t'))
    {
        d_warnOptions.insert("print-tokens");
        d_printTokens = true;
    }

    if (d_arg.option(0, "error-verbose"))
        d_errorVerbose = true;

    if (d_arg.option(0, "flex"))
        d_flex = d_scannerInclude.size();

    if (d_arg.option(0, "no-lines"))
        d_lines = false;
}
