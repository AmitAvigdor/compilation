%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;
	node* mknode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	
	int printlevel=0;
%}
%union
{
	int i;
    struct node *node;
    char *string;
}



%token <string> COMMENT DO WHILE IF ELSE FOR 
%token <string> RETURN
%token <string> BOOL ARROW STRING CHARPTR VOID CHAR INT INTPTR 
%token <string> AND ADDRESS EQUAL ASSIGN OR LENGTH GREATEREQUAL GREATER LESSEQUAL LESS NOTEQUAL NOT
%token <string> DIV PLUS MINUS  VARIABLE
%token <string> STRING_LTL REAL_LTL CHAR_LTL NULLL
%token <string> MAIN IDENTIFIER SEMICOLON COMMA OPAREN CPAREN OBRACKET CBRACKET OBRACE CBRACE
%token <string> DECIMAL_LTL HEX_LTL TRUE FALSE  REAL REALPTR FUNCTION COLON  ETOILE 

// priority of the side of the operand

%left PLUS MINUS RETURN
%left ETOILE DIV
%left EQUAL NOTEQUAL LESS LESSEQUAL GREATEREQUAL GREATER OR AND
%left SEMICOLON 
%right NOT CBRACE

// doesnt care  

%nonassoc IDENTIFIER 
%nonassoc OPAREN
%nonassoc IF
%nonassoc ELSE COMMA

// all the rules that can be node

%type <node> address_expr address_exprs stmnts stmnt_block derefrence_expr  expr_list call_func 
%type <node> expr lhs ass_stmnt new_block var_dec
%type <node> stmnt func_type id_type varident declaration paren_expr
%type <node> body parameters_lst parameters function functions
%type <node> main prog project declarations RET
%%

// prog is all the optiones that we can get, function and main

 //Main project
project: comments prog { Printtree($2); printf("The syntax is accepted \n");};

prog: functions main {$$=mknode("CODE ",$1,$2);}

 //comments
comments: COMMENT comments| ;

 //main func 
main: FUNCTION MAIN OPAREN parameters CPAREN OBRACE body CBRACE
{
$$=mknode("function",
mknode("Main",mknode("\n",NULL,NULL),NULL),
mknode("ARGS",NULL,$7));
}	| {$$=NULL;};

//functions
functions: functions  function {$$=mknode("",$1,$2);}
	| {$$=NULL;};

//function type or void

function: FUNCTION IDENTIFIER OPAREN  parameters  CPAREN  COLON func_type comments OBRACE  body RET CBRACE
{ 
  $$=mknode("function",mknode($2,mknode("\n",NULL,NULL),mknode("ARGS",$4,mknode("return",$7,NULL))),mknode("",$10,$11));	
}
| FUNCTION IDENTIFIER OPAREN parameters CPAREN COLON VOID OBRACE  body CBRACE
{
  $$=mknode("function",mknode($2,mknode("\n",NULL,NULL),NULL),mknode("ARGS",$4,$9));
};


// Params 

parameters: parameters_lst {$$=$1;}
| {$$=NULL;};

parameters_lst: ARROW varident COLON id_type {$$=mknode("(",$4,mknode("",$2,mknode(")",NULL,NULL)));}
| parameters_lst SEMICOLON ARROW varident COLON id_type {$$=mknode("",$1,mknode("",$4,mknode("(",$6,mknode(")",NULL,NULL))));} ;
        


 //Body of functions
body: comments  functions declarations stmnts 
{
	$$=mknode("(BODY\n    ", mknode("",$2,NULL),mknode("",$3,mknode("",$4,mknode("}",NULL,NULL))));
};


//list of declarations
declarations: declarations declaration  {$$=mknode("",$1,$2);} | {$$=NULL;}  ;

//declaration of variables/ 
declaration: VARIABLE varident  COLON id_type  SEMICOLON comments
{
    $$=mknode("var", $4,$2);
}
| STRING expr_list ASSIGN expr SEMICOLON comments
{
    $$ = mknode("str", $2, $4);
}
| STRING expr_list SEMICOLON comments
{
    $$ = mknode("str", $2, NULL);
}
| VARIABLE varident  ASSIGN expr var_dec COLON  id_type SEMICOLON comments
{
    $$ = mknode("var" ,mknode("", $5,mknode("=", $2, $4)),$7);
};


var_dec :{$$=NULL;}
 | COMMA  varident  ASSIGN expr var_dec 
{
    $$ = mknode("var", mknode("=", $2, $4),$5);
}
| COMMA  varident   var_dec {
    $$ = mknode("var", mknode("", $2, NULL),$3);
};



//list of id like a,b,c/

varident: IDENTIFIER COMMA varident {$$=mknode($1, mknode(" ", $3, NULL),NULL);}
	| IDENTIFIER {$$=mknode($1, NULL, NULL);} ;


//types without string/
id_type: BOOL {$$=mknode("bool", NULL, NULL);}
	| STRING OBRACKET DECIMAL_LTL CBRACKET {$$=mknode("string", NULL, NULL);}
	| CHAR {$$=mknode("char", NULL, NULL);}
	| INT {$$=mknode("int", NULL, NULL);}
	| REAL {$$=mknode("real", NULL, NULL);}
	| INTPTR {$$=mknode("int*", NULL, NULL);}
	| CHARPTR {$$=mknode("char*", NULL, NULL);}
	| REALPTR {$$=mknode("real*", NULL, NULL);};



//type for returning from a function
func_type: BOOL {$$=mknode("boolean", NULL, NULL);}
 	| STRING {$$=mknode("string", NULL, NULL);}
	| CHAR {$$=mknode("char", NULL, NULL);}
	| INT {$$=mknode("int", NULL, NULL);}
	| REAL {$$=mknode("real", NULL, NULL);}
	| INTPTR {$$=mknode("int*", NULL, NULL);}
	| CHARPTR {$$=mknode("char*", NULL, NULL);}
	| REALPTR {$$=mknode("real*", NULL, NULL);};
	

//Statments
stmnts: stmnts stmnt declarations {$$=mknode("",$1,$2);} | {$$=NULL;};

//stmnt_block
stmnt_block: stmnt {$$=$1;}|RETURN expr SEMICOLON {$$=mknode("return",$2,NULL);};

//new block in stmnts
new_block: OBRACE comments declarations stmnts RET CBRACE comments
{
	$$=mknode("{",$3,mknode("", $4, mknode("",$5,mknode("}",NULL,NULL))));
};


RET: RETURN expr SEMICOLON comments {$$=mknode("return",$2,NULL);}| {$$=NULL;};

//Statment
stmnt: IF OPAREN expr CPAREN  stmnt_block 
{
	$$=mknode("if",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),$5);
}%prec IF
| IF OPAREN expr CPAREN   stmnt_block    ELSE  stmnt_block  
{
	$$=mknode("if-else",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),
	mknode("",$5,
	mknode("",$7,NULL)));
}
| WHILE comments OPAREN expr CPAREN  stmnt_block  
{
	$$=mknode("while",
	mknode("(", $4, 
	mknode(")",NULL,NULL)),$6);
}
| FOR comments OPAREN ass_stmnt  SEMICOLON expr SEMICOLON  ass_stmnt  CPAREN stmnt_block 
{
		$$= mknode("for",
			mknode("(",
			mknode("",$4,$6),
			mknode("",$8,
			mknode(")",NULL,NULL))),$10);		
}
|DO   stmnt_block    WHILE expr SEMICOLON
{
	$$=mknode("do-while",
	mknode("DO", $2, 
	mknode(")",NULL,NULL)),
	mknode("WHILE",$4,NULL));
}
| ass_stmnt SEMICOLON comments {$$=mknode("",$1,NULL);}
| expr SEMICOLON comments {$$=$1;}
| new_block {$$=$1;};




//assiment statment
ass_stmnt: lhs ASSIGN expr 
{
	$$=mknode("=",$1,$3);
};


//lefd hand side id
lhs: IDENTIFIER OBRACKET expr CBRACKET 
{
	$$=mknode($1, mknode("[",$3,mknode("]",NULL,NULL)), NULL);
} 
| IDENTIFIER {$$=mknode($1,NULL,NULL);}
| derefrence_expr{$$=$1;} ;


	
//Expresion
expr:  OPAREN expr CPAREN {$$=mknode("(",$2,mknode(")",NULL,NULL));}|
    expr EQUAL expr {$$=mknode("==",$1,$3);}
	| expr NOTEQUAL expr {$$=mknode("!=",$1,$3);}
	| expr GREATEREQUAL expr {$$=mknode(">=",$1,$3);}
	| expr GREATER expr {$$=mknode(">",$1,$3);}
	| expr LESSEQUAL expr {$$=mknode("<=",$1,$3);}
	| expr LESS expr {$$=mknode("<",$1,$3);}
	| expr AND expr {$$=mknode("&&",$1,$3);}
	| expr OR expr {$$=mknode("||",$1,$3);}
	| expr PLUS expr {$$=mknode("+",$1,$3);}
	| expr MINUS expr {$$=mknode("-",$1,$3);}
	| expr ETOILE expr {$$=mknode("*",$1,$3);}
	| expr DIV expr {$$=mknode("/",$1,$3);}
	| NOT expr {$$=mknode("!",$2,NULL);}
	| address_exprs {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func comments {$$=$1;}
	| DECIMAL_LTL {$$=mknode($1,NULL,NULL);}
	| HEX_LTL {$$=mknode($1,NULL,NULL);}
	| CHAR_LTL {$$=mknode($1,NULL,NULL);}
	| REAL_LTL {$$=mknode($1,NULL,NULL);}
	| STRING_LTL {$$=mknode($1,NULL,NULL);}
	| FALSE {$$=mknode("false",NULL,NULL);}
	| TRUE {$$=mknode("true",NULL,NULL);}
	| LENGTH IDENTIFIER LENGTH 
	{
		$$=mknode("|",
		mknode($2,NULL,NULL),
		mknode("|",NULL,NULL));
	}
	| IDENTIFIER OBRACKET expr CBRACKET 
	{$$=mknode($1,mknode("[",$3,mknode("]",NULL,NULL)),NULL);}
	|IDENTIFIER{$$=mknode($1,NULL,NULL);};
	| NULLL {$$=mknode("null",NULL,NULL);};



address_exprs:ADDRESS address_exprs {$$=mknode($1,$2,NULL);} | address_expr {$$=$1;};

address_expr: ADDRESS IDENTIFIER {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
	| ADDRESS OPAREN IDENTIFIER CPAREN {$$=mknode("&",mknode("(",mknode($3,NULL,NULL),NULL),mknode(")",NULL,NULL));}
	| ADDRESS IDENTIFIER OBRACKET expr CBRACKET 
	{$$=mknode("&", mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));}
	| ADDRESS OPAREN IDENTIFIER OBRACKET expr CBRACKET CPAREN 
	{
		$$=mknode("&",
		mknode("(", 
		mknode($3,NULL,NULL),
		mknode("[",$5,NULL)), 
		mknode("]",NULL,mknode(")",NULL,NULL)));
	};




derefrence_expr: ETOILE IDENTIFIER {$$=mknode("*",mknode($2,NULL,NULL),NULL);}
	| ETOILE OPAREN expr CPAREN {$$=mknode("*",mknode("(",$3,NULL),mknode(")",NULL,NULL));}
	| ETOILE IDENTIFIER OBRACKET expr CBRACKET 
	{$$=mknode($1, mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));};

	//list of expreession
expr_list: expr COMMA expr_list {$$=mknode("",$1,mknode(",",$3,NULL));} 
	| expr {$$=mknode("",$1,NULL);}
	| {$$=NULL;};


paren_expr:OPAREN expr_list CPAREN {$$=$2;};

//call func rul 
call_func: IDENTIFIER paren_expr {$$=mknode("Call function",mknode($1,NULL,NULL),mknode("ARGS",$2,NULL));} ;
%%



int main()
{
	return yyparse();	
}

/* allocation for node*/
node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

void printTabs(int n)
{
	int i;
	for(i=0;i<n/3;i++)
		printf(" ");
}



void Printtree(node* tree)
{
	int step = 4;
	printTabs(printlevel); 


	
	if(strcmp(tree->token, "var") == 0)
	{
		
		printf("DECLARE : ");
		step =3;

	}
	else if(strcmp(tree->token, "if") == 0)
	{
		printf("(IF\n");
		step = 1;
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		printf("(WHILE\n");
		step = 1;
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{
		printf("(FOR\n");
		step = 1;
		
		
	}
		else if(strcmp(tree->token, "function") == 0 ||strcmp(tree->token, "CODE") == 0||strcmp(tree->token, "Call function") == 0)
	{
		printf("(%s \n",tree->token);
		step=2;
		
	}
		else if(strcmp(tree->token, "ARGS") == 0)
	{
		printf("ARGS : ");
		if(tree->left)
		{
			step = 1;
			
		}
		else{
			printf(" NONE)\n"); 
		}
	}
		else if(strcmp(tree->token, "if-else") == 0)
	{
		printf("(IF-ELSE\n");
		printlevel--;
		
		step = 1;
	}
		else if(strcmp(tree->token, "do-while") == 0)
	{
		printf("(DO-WHILE\n");
		printlevel--;
		
		step = 1;
	}
			else if(strcmp(tree->token, "return") == 0)
	{
		printf("(RETURN ");
		step = 2;
	}
	else if(strcmp(tree->token, "{") == 0)
	{
                printf("(BLOCK\n");
				
				
	}
	else if(strcmp(tree->token, "}") == 0)
	{
		printf(")\n");
	}
	else if(strcmp(tree->token, "") == 0);
	else if(strcmp(tree->token, "(") == 0)
			printf("(");
	else if(strcmp(tree->token, "\n") == 0)
			printf("\n");
	else if(strcmp(tree->token, ")") == 0)
			printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
			printf(",");
	else if(strcmp(tree->token, ";") == 0)
			printf("\n");
	else if(strcmp(tree->token, "&&") == 0 ||strcmp(tree->token, "||") == 0 || strcmp(tree->token, "!=") == 0 || strcmp(tree->token, "!") == 0 )
	{
			printf("(%s",tree->token);
			step=1;
			if(strcmp(tree->token, "=") == 0)
				step=2;
				
	}
	else if (strcmp(tree->token, "/") == 0 || strcmp(tree->token, "+") == 0 || strcmp(tree->token, "*") == 0 || strcmp(tree->token, "-") == 0 ) 
	{
			printf("(%s",tree->token);
			step=1;
			if(strcmp(tree->token, "=") == 0)
				step=2;
				
	}
	else if (strcmp(tree->token, "=") == 0 || strcmp(tree->token, "==") == 0 || strcmp(tree->token, ">") == 0 || strcmp(tree->token, ">=") == 0 || strcmp(tree->token, "<") == 0 || 
	strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "/") == 0  ||strcmp(tree->token, "&") == 0 || strcmp(tree->token, "|") == 0 || strcmp(tree->token, ",") == 0)
 	{
			printf("(%s",tree->token);
			step=1;
			if(strcmp(tree->token, "=") == 0)
				step=2;
				
	}
	else
	{
		if(tree && (!tree->left && !tree->right)
		||strcmp(tree->token, "Main") == 0)
		{
			printf("%s ", tree->token);
			
		}
		else
		{
			printlevel++;
			printf("%s", tree->token);
			printlevel--;
		
		}
	}
	if (tree->left) 
	{
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}
	
	if (tree->right)
	{
		printlevel++;
		Printtree(tree->right);
		printlevel--;
		
	}
	if(step == 3)
		printf("\n");
	if(step == 2)
		printf(")\n");
	
	if(step == 1)
		printf(")");
	if(step == 0)
		printf("\n)");

}
int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"You have a %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "The language does not accept '%s'\n",yytext);
	
	return 0;
}