// based on http://www.stroustrup.com/dc.c
// by Bjarne Stroustrup
// The desk calculator
// pp 107-117, sec 6.1, A Desk calculator
// No guarantees offered. Constructive comments to bs@research.att.com


/*
 expr_list:
	expression PRINT	   // PRINT is \n
	expression PRINT expr_list
 
 expression:
	expression + term
	expression - term
	term
 
 term:
	term / power
	term * power
	power
 
 power:
    power # primary         // char '^' produces problems with terminal input
    primary
 
 
 primary:
	NUMBER
	( expression )
 
 
while statt for
erweitern um o,i oder HexaDezimal mit &, |, x,
 */


#include <string>
#include <cctype>
#include <iostream>

using namespace std;

int no_of_errors;	// note: default initialized to 0
bool doPrintCalculations = true;


unsigned int error(const char* s)
{
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}

enum Token_value {
    NUMBER, // '0' ... '9'
    PLUS='+',	MINUS='-',	MUL='*',	DIV='/',
    PRINT='\n',	POWER='#',	LP='(',		RP=')'
};

Token_value global_token = PRINT;
unsigned int number_value;

unsigned int asciToInt(string string_value){
    unsigned int result = 0;
    for(size_t i=0; i<string_value.length();i++){
        result *= 10;
        result += string_value[i] - 48;
    }
    return result;
}

Token_value get_token()
{
    char ch;
    
    do {	// skip whitespace except '\n'
        if(!cin.get(ch)) {error("EOF"); exit(1);} //return curr_tok = END;
    } while (ch!='\n' && isspace(ch));

    switch (ch) {
        //case ';':
        case '\n':
            return global_token=PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '#':
            return global_token=Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':{
            // the easy way: cin.putback(ch);
            // the easy way: cin >> number_value;
            string string_value;
            string_value = ch;
            while (cin.get(ch) && isdigit(ch))
                string_value += ch;	// string_value.push_back(ch); // to work around library bug
            cin.putback(ch);
            number_value = asciToInt(string_value);
            return global_token=NUMBER;
        }
        default:
            error("bad token");
            return global_token=PRINT;
    }
}


unsigned int expression();	// cannot do without (indirect recursion)


unsigned int primary()		// handle primaries
{
    Token_value current_token = get_token();
    
    switch (current_token) {
        case NUMBER:{
            unsigned int v = number_value;
            get_token();        // proceed global_token to next token (i.e. operator or '\n')
            return v;
        }
        case LP:{
            unsigned int e = expression();
            if (global_token != RP) return error(") expected");
            get_token();		// eat ')' in order to proceed global_token to next token
            return e;
        }
        default:
            return error("primary expected");
    }
}

unsigned int power()		// 2 ^ 3
{
    unsigned int left = primary();
    unsigned int right = 0;
    
    for (;;)
        switch (global_token) {
            case POWER:{
                right = primary();
                if (doPrintCalculations) printf("%u # %u\n", left, right);
                unsigned int base = left;
                left = 1;
                for (int i=0; i<right; i++)
                    left *= base;
                break;
            }
            default:
                return left;
        }
}


unsigned int term()		// multiply or divide
{
    unsigned int left = power();
    unsigned int right = 0;
    
    for (;;)
        switch (global_token) {
            case MUL:{
                right = power();
                if (doPrintCalculations) printf("%u * %u\n", left, right);
                left *= right;
                break;
            }
            case DIV:{
                if ((right = power())) {
                    if (doPrintCalculations) printf("%u / %u\n", left, right);
                    left /= right;
                    break;
                }
                return error("divide by 0");
            }
            default:
                return left;
        }
}

/*
unsigned int ops_level_a()		        // e.g. add or subtract
{
    unsigned int left = ops_level_b();  // e.g. multiply or divide (which in turn calls ops_level_c() immediately)
    unsigned int right = 0;
    
    for (;;)
        switch (global_token) {
            case TOKEN_LEVELA_1:{
                right = ops_level_b();  // e.g. multiply or divide
                left = left TOKEN_LEVELA_1 right;
                break;
            }
            case TOKEN_LEVELA_2:{
                right = ops_level_b();  // e.g. multiply or divide
                left = left TOKEN_LEVELA_1 right;
                break;
            }
            default:                   // an operator of another (lower) level, or \n
                return left;           // there is no further operator (and operands) of this level
        }
}
*/

unsigned int expression()		// add or subtract
{
    unsigned int left = term();
    unsigned int right = 0;
    
    for (;;)				// ``forever''
        switch (global_token) {
            case PLUS:{
                right = term();
                if (doPrintCalculations) printf("%u + %u\n", left, right);
                left += right;
                break;
            }
            case MINUS:{
                right = term();
                if (doPrintCalculations) printf("%u - %u\n", left, right);
                left -= right;
                break;
            }
            default:
                return left;
        }
}

int main()
{
    while (cin){
        //cout << " > ";
        cout << expression() << '\n';
    }
    return no_of_errors;
}
