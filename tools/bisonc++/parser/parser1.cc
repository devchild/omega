#include "parser.ih"

Parser::Parser(Rules &rules)
:
    d_arg(Arg::instance()),
    d_options(Options::instance()),
    d_scanner(d_arg[0]),
    d_matched(d_scanner.matched()),
    d_rules(rules),
    d_typeDirective(false),
    d_semType(SINGLE),
    d_negativeDollarIndices(false)
{
    d_options.setMatched(d_matched);
    setDebug(d_arg.option(0, "own-debug"));
    d_scanner.setDebug(d_arg.option(0, "scanner-debug"));

    predefine(Rules::errorTerminal());
    predefine(Rules::eofTerminal());
}

