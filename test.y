%{
    // T -> TT
    // T -> (T)
    // T -> ()

    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror (char *s);
%}

%start S
%token END

%%
S : St G
    ;
St : "main" "(" ")" "{" statements "}"
	;
statements : %empty ;
statements : statement ";" statements ;
statement : dec_st | math_st | io | if_st | %empty ;
dec_st : "dtype" d_prod ;
d_prod : d_nat | d_prod "," d_nat ;
d_nat : "ID" | math_st ;
math_st : "ID" "equ" VALUE | "ID" "equ" math_st ;
io : "input" "i_cas" "ID" | "output" "o_cas" VALUE ;
if_st : "if_token" "(" comp_st ")" "then_token" "{" statements "}" CONT ;
CONT : "else_token" "{" statements "}" | %empty ;
// VALUE : VALUE "math_op" VALUE | "ID" | "NUMBER" | "character" | "NULL" | "(" VALUE ")" ;
comp_st : VALUE "comp_op" VALUE | "(" comp_st ")" "r_o" "(" comp_st ")" ;
VALUE : VALUE "+" TERM | VALUE "-" TERM | "+" TERM | "-" TERM | TERM ;
TERM : TERM "*" FAC | TERM "/" FAC | TERM "%" FAC | FAC ;
FAC : "ID" | "NUMBER" |	"(" VALUE ")" ;


G : END   {printf("Parsed Successfully."); exit(0);}
    ;
%%

void yyerror (char *s) 
{
    fprintf (stderr, "%s\n", s);
}

int main()
{
    return yyparse();
}

int yylex()
{
    int c;
    c = getchar();
    if (c==EOF || c=="\n")
    {
        return END;
    }
    return c;
}
