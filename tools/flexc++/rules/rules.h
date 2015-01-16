#ifndef INCLUDED_RULES_
#define INCLUDED_RULES_

#include <iosfwd>
#include <vector>
#include <string>

#include <bobcat/linearmap>

#include "../startconditions/startconditions.h"
#include "../rule/rule.h"
#include "../flextypes/flextypes.h"

class States;
class Block;
class Pattern;

class Rules: public FlexTypes
{
    friend std::ostream &operator<<(std::ostream &out, Rules const &rules);

    typedef std::pair<size_t, size_t> Pair; // 1st: start-, 2nd: final-state

    States &d_states;

    std::vector<Rule> d_rules;
    FBB::LinearMap<size_t, size_t>  d_finalToRule;  // from FINAL state to
                                                        // Rule index
    FBB::LinearMap<size_t, size_t>  d_lopToRule;// key is lop rule,
                                                    // value is rule to use
                                                    // while in user SCs

    StartConditions d_startConditions;

    Rule d_catchAll;
    bool d_userSC = true;
    bool d_hasFixedTailLOPrules = false;      
    bool d_hasVariableTailLOPrules = false;      
    size_t d_nUserRules = 0;

    public:
        typedef StartConditions::const_iterator const_iterator;
        typedef std::vector<Rule>::const_iterator rule_const_iterator;

        Rules(States &states);
        void add(bool bol, Pattern const &pattern, Block const &block,
                RuleType type);

        Rule const &operator[](size_t idx) const;
        Rule &operator[](size_t idx);

        
        size_t ruleFromFinalState(size_t stateIdx) const;

        void setType(StartConditions::Type type);
        void defineStartCondition(std::string const &name);

        void resetStartConditions();        // clear the set of active start
                                            // conditions. 
        void useAll();
        void addStartCondition(std::string const &name);

        std::vector<size_t> const &operator()   // vector of rule nrs
                                    (std::string const &startCondition) const;

        const_iterator begin() const;
        const_iterator end() const;
        const_iterator endUserSC() const;

        rule_const_iterator ruleBegin() const;
        rule_const_iterator ruleEnd() const;

        size_t size() const;                    // # of rules

        void setOrAction();         // set the previous rule's action to '|'

        void assignBlock(Block const &block);   // assign 'block' to the last
                                                // rule

        void noActions();                       // clear previous actions's
                                                // 'orAction' states

        StartConditions const &startConditions() const;

        void handleLopRules();

        void setEndUserSC();
        void setNuserRules();

        void processCatchAllRule();

        void checkUserSC(size_t scIndex);

        void setFixedTailLOPrules();
        void setVariableTailLOPrules();

        bool hasLOPrules() const;
        bool hasFixedTailLOPrules() const;
        bool hasVariableTailLOPrules() const;
        size_t nUserRules() const;

    private:
        void setRule(size_t state, size_t index);

        void setLopBlocks();
        size_t handleLopRule(size_t idx);
        void handleFixedTailLopRule(Rule &rule);

        void addIndex(size_t index);

        void addCatchAll(size_t scIndex, size_t catchAllRuleIndex);

//        static bool nonViable(Rule const &rule);
};

inline void Rules::setNuserRules()
{
    d_nUserRules = d_rules.size();
}

inline void Rules::setFixedTailLOPrules()
{
    d_hasFixedTailLOPrules = true;
}

inline void Rules::setVariableTailLOPrules()
{
    d_hasVariableTailLOPrules = true;
}

inline bool Rules::hasFixedTailLOPrules() const
{
    return d_hasFixedTailLOPrules;
}

inline bool Rules::hasVariableTailLOPrules() const
{
    return d_hasVariableTailLOPrules;
}

inline bool Rules::hasLOPrules() const
{
    return hasFixedTailLOPrules() || hasVariableTailLOPrules();
}

inline void Rules::addIndex(size_t index)
{
    d_startConditions.add(index);
}

inline void Rules::checkUserSC(size_t idx)
{
    d_userSC = d_userSC && idx < d_startConditions.nUserSCs();
}

inline void Rules::setEndUserSC()
{
    d_startConditions.setEndUserSC();
}

inline StartConditions const &Rules::startConditions() const
{
    return d_startConditions;
}

inline void Rules::setOrAction()
{
    d_rules[d_rules.size() - 2].setOrAction();
}

inline size_t Rules::size() const
{
    return d_rules.size();
}
        
inline size_t Rules::nUserRules() const
{
    return d_nUserRules;
}

inline Rules::const_iterator Rules::begin() const
{
    return d_startConditions.begin();
}
        
inline Rules::const_iterator Rules::end() const
{
    return d_startConditions.end();
}
        
inline Rules::const_iterator Rules::endUserSC() const
{
    return d_startConditions.endUserSC();
}
        
inline Rules::rule_const_iterator Rules::ruleBegin() const
{
    return d_rules.begin();
}
        
inline Rules::rule_const_iterator Rules::ruleEnd() const
{
    return d_rules.end();
}
        
inline Rule const &Rules::operator[](size_t idx) const
{
    return d_rules[idx];
}

inline Rule &Rules::operator[](size_t idx)
{
    return d_rules[idx];
}

inline void Rules::setType(StartConditions::Type type)
{
    d_startConditions.setType(type);
}

inline void Rules::defineStartCondition(std::string const &name)
{
    d_startConditions.define(name);
}

inline void Rules::resetStartConditions()
{
    d_startConditions.reset();
}

inline void Rules::useAll()
{
    d_startConditions.useAll();
}

inline void Rules::addStartCondition(std::string const &name)
{
    d_startConditions.addSC(name);
}

inline void Rules::assignBlock(Block const &block)
{
    d_rules.back().assignBlock(block);    
}

inline std::vector<size_t> const &Rules::operator() 
                                    (std::string const &startCondition) const
{
    return d_startConditions(startCondition);
}

#endif
