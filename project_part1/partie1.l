/*Scanner*/
%{
#include<stdio.h>
#include "y.tab.h"
%}
 /*%x comment*/

%%
bool {return BOOL;}
char {return CHAR;}
int {return INT;}
void {return VOID;}
real {return REAL;}
string {return STRING;}
int* {return INTPTR;}
char* {return CHARPTR;}
real* {return REALPTR;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
for {return FOR;}
do {return DO;}
var {return VARIABLE;}
function {return FUNCTION;}
arg-> {return ARROW;}
null {return NULLL;}
Main {
    fprintf(stderr, "Syntax error: 'Main' is not allowed.\n");
    exit(1);
}

 
"&&" {return AND;}
"/" {return DIV;}
"=" {return ASSIGN;}
"==" {return EQUAL;}
">" {return GREATER;}
">=" {return GREATEREQUAL;}
"<" {return LESS;}
"<=" {return LESSEQUAL;}
"-" {return MINUS;}
"!" {return NOT;}
"!=" {return NOTEQUAL;}
"||" {return OR;}
"+" {return PLUS;}
"&" {return ADDRESS;}
"*"         { return ETOILE; }
"|" {return LENGTH;}
";" {return SEMICOLON;}
":" {return COLON;}
"," {return COMMA;}
"{" {return OBRACE;}
"}" {return CBRACE;}
"(" {return OPAREN;}
")" {return CPAREN;}
"[" {return OBRACKET;}
"]" {return CBRACKET;}
 
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]  { /*comment*/}{return COMMENT;}

  /*Literl*/
return {return RETURN;}
true {return TRUE;}
false {return FALSE;}

[a-zA-Z][a-zA-Z0-9_]* { yylval.string= strdup(yytext);return IDENTIFIER;}
"\""[^"]*"\"" {yylval.string= strdup(yytext);return STRING_LTL;}
\'.\' {yylval.string= strdup(yytext);return CHAR_LTL;}
[+-]?[1-9][0-9]*|[0-9] {yylval.string= strdup(yytext);return DECIMAL_LTL;}
0(x|X)[0-9A-F]+ {yylval.string= strdup(yytext);return HEX_LTL;}
[-+]?[0-9]*\.?[0-9]*[eE]?[-+]?[0-9]+ {yylval.string= strdup(yytext);return REAL_LTL;}

[\n] {yylineno++;} //line , do yylineo+=1
[ \t]+ ;
. return yytext[0];
%%

