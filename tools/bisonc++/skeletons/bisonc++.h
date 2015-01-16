#ifndef \@$_h_included
#define \@$_h_included

$insert baseclass
$insert scanner.h

$insert namespace-open

#undef \@
class \@: public \@Base
{
$insert 4 scannerobject
        
    public:
        int parse();

    private:
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
        void exceptionHandler__(std::exception const &exc);
};

$insert namespace-close

#endif
