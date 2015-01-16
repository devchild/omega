/* 
 * File:   code_ir_block_statement.hh
 * Author: mario
 *
 * Created on September 21, 2014, 8:57 PM
 */

#ifndef CODE_IR_BLOCK_STATEMENT_HH
#define	CODE_IR_BLOCK_STATEMENT_HH

namespace mlang {
    class CodeScope;
    class CodeExpression;
    class CodeStatement;
    class CodeObjectVisitor;
    
    class CodeIrBlockStatement : public CodeStatement {
    public:
        using CodeObject::scope;
        CodeIrBlockStatement();
        ~CodeIrBlockStatement();
        virtual void accept(CodeObjectVisitor* visitor);
        

        void content(std::string value);
        std::string content();
        
        virtual bool type_of(CodeObjectKind kind);
        void scope(CodeScope* scope) override;
    private:
        std::string m_content;
    };
}


#endif	/* CODE_IR_BLOCK_STATEMENT_HH */

