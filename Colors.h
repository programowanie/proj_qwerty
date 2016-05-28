#include <ostream>

namespace Color 
{
    enum Code
    {
        FG_RED      = 91,
        FG_GREEN    = 32,
        FG_YELLOW   = 93,
        FG_BLUE     = 94,
        FG_MAGENTA  = 95,
        FG_CYAN     = 96,
        FG_BLACK    = 30,
        
        FG_DEFAULT  = 39,

    };
    class Modifier 
    {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator << (std::ostream& os, const Modifier& mod)
        {
            return os << "\033[" << mod.code << "m";
        };
    };
}

    Color::Modifier static red      (Color::FG_RED);
    Color::Modifier static green    (Color::FG_GREEN);
    Color::Modifier static yellow   (Color::FG_YELLOW);    
    Color::Modifier static blue     (Color::FG_BLUE);
    Color::Modifier static magenta  (Color::FG_MAGENTA);
    Color::Modifier static cyan     (Color::FG_CYAN);
    Color::Modifier static black    (Color::FG_BLACK);
    Color::Modifier static def      (Color::FG_DEFAULT);
