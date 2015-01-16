#include "generator.ih"

void Generator::lexFunctionDecl(std::ostream &out) const
{
    key(out);
    out << indent << "int " << d_options.lexFunctionName() << "();\n";
}
