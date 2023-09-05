%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"


typedef enum {false,true} bool;


	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;


  typedef struct Function 
	{
        char * name;
		struct Variables * arguments;
        char *returnType; 
		int argNum;
		bool findreturn;
    } Function;
	

	typedef struct Variables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * len;
	}Variables;

		typedef struct SCOPE
	{	
		char *name;
		Variables * var;
		int VarCount;
		int Checkcount;
		Function ** func;
		struct SCOPE * nextScope;
		struct SCOPE * preScope;
	}SCOPE;
	static int scope=0;

	char* getExpType(node *,SCOPE*);
	Variables* mkArguments(node *,int *);
	void addFunc(char * name,Variables * arguments,node *returnType,int argNum,SCOPE*);
	void addVar(Variables * arguments,int,int,SCOPE * TheScope);
	SCOPE* mkcode(char *);
	SCOPE* findScope(SCOPE * scopes);
	SCOPE* globalScope=NULL;
	node* mknode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTabs(int n);
	int yylex();
	int yyerror(char *e);
	void pushScopes(SCOPE* from,char*);
	int printlevel=0;
	SCOPE* mycode=NULL;
	void Analyzer(node *tree,SCOPE * scope);
	char* findFuncInScopes(node * tree,SCOPE * TheScope);
	char* findVar(node * tree,SCOPE * TheScope);
	Variables* callFuncArguments(SCOPE *,node *tree,int * count);
	
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
%token <string>  REAL_LTL CHAR_LTL NULLL
%token <string> MAIN IDENTIFIER SEMICOLON COMMA OPAREN CPAREN OBRACKET CBRACKET OBRACE CBRACE
%token <string> DECIMAL_LTL HEX_LTL STRING_LTL TRUE FALSE  REAL REALPTR FUNCTION COLON  ETOILE 

%left PLUS MINUS RETURN
%left ETOILE DIV
%left EQUAL NOTEQUAL LESS LESSEQUAL GREATEREQUAL GREATER OR AND
%left SEMICOLON 
%right NOT CBRACE

%nonassoc IDENTIFIER 
%nonassoc OPAREN
%nonassoc IF
%nonassoc ELSE COMMA


%type <node> address_expr address_exprs stmnts stmnt_block derefrence_expr  expr_list call_func 
%type <node> expr lhs ass_stmnt new_block var_dec
%type <node> stmnt func_type id_type varident declaration paren_expr
%type <node> body parameters_lst parameters function functions
%type <node> main prog project declarations RET
%%



 //Main project
project: comments prog { Printtree($2); Analyzer($2,globalScope);};

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
	| DECIMAL_LTL {$$=mknode($1,mknode("INT",NULL,NULL),NULL);}
	| HEX_LTL {$$=mknode($1,mknode("HEX", NULL, NULL),NULL);}
	| CHAR_LTL {$$=mknode($1,mknode("CHAR", NULL, NULL),NULL);}
	| REAL_LTL {$$=mknode($1,mknode("REAL", NULL, NULL),NULL);}
	| STRING_LTL {$$=mknode($1,mknode("STRING", NULL, NULL),NULL);}
| FALSE {$$=mknode($1,mknode("BOOLEAN", NULL, NULL),NULL);}
	|TRUE {$$=mknode($1,mknode("BOOLEAN", NULL, NULL),NULL);}
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
	int res = yyparse();
	if(res==0)
		printf("The Syntax and Semantics Are Valid\n"); 
	return res;	
}

void addVar(Variables * arguments,int countvars,int isArg,SCOPE * TheScope){
	if(countvars==0)
	return;
	Variables* tmp;
	SCOPE * scopes=TheScope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("There is the same var %s in one declare",arguments[i].name);
		SCOPE * t=scopes->preScope;
		while(t->preScope!=NULL && t->preScope->Checkcount==0)
			t=t->preScope;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->Checkcount-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(scopes->var==NULL)
	{ 
		scopes->var=(Variables*) malloc(sizeof(Variables)*countvars);
	}
	else
	{
		tmp=scopes->var;
		scopes->var=(Variables*) malloc(sizeof(Variables)*(scopes->VarCount+countvars));
		for(int i=0;i<scopes->VarCount;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(tmp[i].name,arguments[j].name)==0 )
				{
					printf("There can't be the same var %s in same scope",tmp[i].name);
					SCOPE * t=scopes->preScope;
					while(t->preScope!=NULL && t->preScope->Checkcount==0)
						t=t->preScope;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->Checkcount-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			scopes->var[i]=tmp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{

		scopes->var[scopes->VarCount].name=arguments[j].name;
		scopes->var[scopes->VarCount].value=NULL;
		scopes->var[scopes->VarCount].isArg=isArg;
		scopes->var[scopes->VarCount].len=arguments[j].len;
		scopes->var[(scopes->VarCount)++].type=arguments[j].type;
	}

}


char* getExpType(node* tree, SCOPE* TheScope) {
	{   printf("#####################");

    char* msg = (char*)malloc(sizeof(char) * 7);
    strcpy(msg, "");

    if (strcmp(tree->token, "null") == 0)
        strcpy(msg, "NULL");
    else if (tree->left != NULL) {
        if (strcmp(tree->left->token, "INT") == 0)
            strcpy(msg, "int");
        else if (strcmp(tree->left->token, "HEX") == 0)
            strcpy(msg, "hex");
        else if (strcmp(tree->left->token, "CHAR") == 0)
            strcpy(msg, "char");
        else if (strcmp(tree->left->token, "REAL") == 0)
            strcpy(msg, "real");
        else if (strcmp(tree->left->token, "STRING") == 0)
            strcpy(msg, "string");
        else if (strcmp(tree->left->token, "BOOLEAN") == 0)
            strcpy(msg, "boolean");
        else if (strcmp(tree->token, "!") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), "boolean") == 0)
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can use operator ! only on boolean type");
                exit(1);
            }
        } else if (strcmp(tree->token, "|") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), "string") == 0)
                strcpy(msg, "int");
            else {
                printf("ERROR, you can use operator | only on string type in the function %s", globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "==") == 0 || strcmp(tree->token, "!=") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->right, TheScope), "string") != 0)
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, ">=") == 0 || strcmp(tree->token, ">") == 0 || strcmp(tree->token, "<=") == 0 || strcmp(tree->token, "<") == 0) {
            if ((strcmp(getExpType(tree->left, TheScope), "int") == 0 || strcmp(getExpType(tree->left, TheScope), "real") == 0) && (strcmp(getExpType(tree->right, TheScope), "int") == 0 || strcmp(getExpType(tree->right, TheScope), "real") == 0))
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "&&") == 0 || strcmp(tree->token, "||") == 0) {
            if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->right, TheScope), "boolean") == 0)
                strcpy(msg, "boolean");
            else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "-") == 0 || strcmp(tree->token, "+") == 0) {
            if ((strcmp(getExpType(tree->left, TheScope), "int") == 0 || strcmp(getExpType(tree->left, TheScope), "real") == 0) && (strcmp(getExpType(tree->right, TheScope), "int") == 0 || strcmp(getExpType(tree->right, TheScope), "real") == 0)) {
                if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->left, TheScope), "int") == 0)
                    strcpy(msg, "int");
                else
                    strcpy(msg, "real");
            } else if (strcmp(getExpType(tree->right, TheScope), "int") == 0 && (strcmp(getExpType(tree->left, TheScope), "char*") == 0 || strcmp(getExpType(tree->right, TheScope), "int*") == 0 || strcmp(getExpType(tree->right, TheScope), "real*") == 0)) {
                strcpy(msg, getExpType(tree->left, TheScope));
            } else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "*") == 0 || strcmp(tree->token, "/") == 0) {
            if ((strcmp(getExpType(tree->left, TheScope), "int") == 0 || strcmp(getExpType(tree->left, TheScope), "real") == 0) && (strcmp(getExpType(tree->right, TheScope), "int") == 0 || strcmp(getExpType(tree->right, TheScope), "real") == 0)) {
                if (strcmp(getExpType(tree->left, TheScope), getExpType(tree->right, TheScope)) == 0 && strcmp(getExpType(tree->left, TheScope), "int") == 0)
                    strcpy(msg, "int");
                else
                    strcpy(msg, "real");
            } else {
                printf("ERROR, you can't use operator %s between %s and %s in the function %s\n\n", tree->token, getExpType(tree->left, TheScope), getExpType(tree->right, TheScope), globalScope->func[globalScope->Checkcount - 1]->name);
                exit(1);
            }
        } else if (strcmp(tree->token, "&") == 0) {
            if (strcmp(tree->left->token, "(") == 0)
                strcpy(msg, getExpType(tree->left->left, TheScope));
            else {
                strcpy(msg, getExpType(tree->left, TheScope));
            }
            if (strcmp(msg, "char") == 0)
                strcpy(msg, "char*");
            else if (strcmp(msg, "int") == 0)
                strcpy(msg, "int*");
            else if (strcmp(msg, "real") == 0)
                strcpy(msg, "real*");
            else {
                printf("ERROR, you can't use %s on %s \n", tree->token, msg);
                exit(1);
            }
        } else if (strcmp(tree->token, "*") == 0) {
            if (strcmp(tree->left->token, "(") == 0)
                strcpy(msg, getExpType(tree->left->left, TheScope));
            else
                strcpy(msg, getExpType(tree->left, TheScope));

            if (strcmp(msg, "char*") == 0)
                strcpy(msg, "char");
            else if (strcmp(msg, "int*") == 0)
                strcpy(msg, "int");
            else if (strcmp(msg, "real*") == 0)
                strcpy(msg, "real");
            else {
                printf("ERROR, you can't use %s on %s \n", tree->token, msg);
                exit(1);
            }
        } else if (strcmp(tree->token, "(") == 0)
            strcpy(msg, getExpType(tree->left, TheScope));
        else if (strcmp(tree->token, "Call function") == 0)
            strcpy(msg, findFuncInScopes(tree, TheScope));
    }
    if (strcmp(msg, "") == 0)
        strcpy(msg, findVar(tree, TheScope));

    return msg;
}

SCOPE* mkScope(char* name)
{   
    SCOPE* newScope = (SCOPE*)malloc(sizeof(SCOPE));
    newScope->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(newScope->name, name);
    newScope->var = NULL;
    newScope->VarCount = 0;
    newScope->func = NULL;
    newScope->Checkcount = 0;
    newScope->nextScope = NULL;
    newScope->preScope = NULL;
    return newScope;
}

void addFunc(char * name,Variables * arguments,node *returnType,int argNum,SCOPE * TheScope){
	Function** tmp;
	SCOPE * scopes = TheScope;
	for(int i=0;i<argNum;i++)
		for(int j=0;j<argNum;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("ERROR, there are identicles arguments %s in func %s\n",arguments[i].name,name);
		exit(1);
	}
	if(scopes->func==NULL)
	{ 
		scopes->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		tmp=scopes->func;
		scopes->func=(Function**) malloc(sizeof(Function*)*(scopes->Checkcount+1));
		for(int i=0;i<scopes->Checkcount;i++)
		{
				if(strcmp(tmp[i]->name,name)==0 )
				{
					printf("ERROR, there's already function %s in same scope \n",tmp[i]->name);
					exit(1);
				}
				scopes->func[i]=tmp[i];
		}
	}
		scopes->func[scopes->Checkcount]=(Function*) malloc(sizeof(Function));
		scopes->func[scopes->Checkcount]->name=name;
		scopes->func[scopes->Checkcount]->arguments=arguments;
		if(returnType==NULL)
		scopes->func[scopes->Checkcount]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type function %s can't be string\n",name);
				exit(1);
			}
		scopes->func[scopes->Checkcount]->returnType=returnType->token;
		}
		scopes->func[scopes->Checkcount]->argNum=argNum;
		scopes->func[scopes->Checkcount]->findreturn=false;
		++(scopes->Checkcount); 

}



node* mknode(char* token, node* left, node* right)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->left = left;
    newnode->right = right;
    newnode->token = token;
    return newnode;
}


void printTabs(int n)
{
	int i;
	for(i=0;i<n/9;i++)
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

SCOPE* findScope(SCOPE * scopes){
	SCOPE * TheScope=scopes;
	if(TheScope!=NULL)
	while(TheScope->nextScope!=NULL)
		TheScope=TheScope->nextScope;
	return TheScope;
}


void Analyzer(node *tree,SCOPE * TheScope){
	int flagNew=0;
	if(strcmp(tree->token, "=") == 0 )
	{
		if(!(strcmp(getExpType(tree->right,TheScope),"NULL")==0&& (strcmp(getExpType(tree->left,TheScope),"real*")==0||strcmp(getExpType(tree->left,TheScope),"int*")==0||strcmp(getExpType(tree->left,TheScope),"char*")==0)))
		if(strcmp(getExpType(tree->left,TheScope),getExpType(tree->right,TheScope))!=0)
		{
			printf("ERORR, you can't do = between %s and %s in scope %s in the function %s\n",getExpType(tree->left,TheScope),getExpType(tree->right,TheScope),TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int VarCount=0;
		Variables * var=mkArguments(tree,&VarCount);
		addVar(var,VarCount,0,TheScope);
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(getExpType(tree->left->left,TheScope),"boolean")!=0)
		{
			printf("ERROR, the condition in if statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(TheScope,tree->token);
			if (tree->left) 
				Analyzer(tree->left,findScope( TheScope->nextScope));
	
			if (tree->right)
				Analyzer(tree->right,findScope( TheScope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(getExpType(tree->left->left,TheScope),"boolean")!=0)
		{
			printf("ERROR, the condition in while statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(TheScope,tree->token);
			if (tree->left) 
				Analyzer(tree->left,findScope( TheScope->nextScope));
	
			if (tree->right)
				Analyzer(tree->right,findScope( TheScope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{

	 if(strcmp(getExpType(tree->left->left->right,TheScope),"boolean")!=0)
		{
			printf("ERROR, the condition in for statement has to be boolean\n");
			exit(1);
		}

		Analyzer(tree->left->left->left,TheScope);

		Analyzer(tree->left->right->left,TheScope);

		if(strcmp(tree->right->token,"{")!=0)
		{

			pushScopes(TheScope,tree->token);

			if (tree->left) 
				Analyzer(tree->left,findScope( TheScope->nextScope));
	
			if (tree->right)
				Analyzer(tree->right,findScope( TheScope->nextScope));
        	scope--;
			return;
		}

		
		
	}
	else if(strcmp(tree->token, "function") == 0)
	{
        int count=0;
		Variables * arg=mkArguments(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,TheScope);
		pushScopes(TheScope,tree->token);
		addVar(arg,count,1,findScope(TheScope));
	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));

	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
		if(TheScope->func[TheScope->Checkcount-1]->findreturn==false)
		{
			printf("ERORR, there is no Return in func %s\n",tree->left->token); // ######## GALIT: here it's the problem
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "function") == 0)
	{
		
        int count=0;
		Variables * arg=mkArguments(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,TheScope);
		pushScopes(TheScope,tree->token);
		addVar(arg,count,1,findScope(TheScope));
	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));
	
	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
		scope--;	
		return;
    }


	else if(strcmp(tree->token, "Call function") == 0)
	{
		findFuncInScopes(tree,TheScope);
		//printf("(%s \n",tree->token);
		
		
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{
		pushScopes(NULL,tree->token);
	if (tree->left) 
		Analyzer(tree->left,globalScope);
	
	if (tree->right)
		Analyzer(tree->right,globalScope);
		scope--;
		return;
	}

    else if(strcmp(tree->token, "Main") == 0)
	{
		addFunc(tree->token,NULL,NULL,0,TheScope);
		pushScopes(TheScope,tree->token);

	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));
	
	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
        scope--;
		return;
               
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(getExpType(tree->left->left,TheScope),"boolean")!=0)
		{
			printf("ERORR, if condition must be of type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			pushScopes(TheScope,tree->token);
			Analyzer(tree->right->left,findScope( TheScope->nextScope));
			scope--;
			pushScopes(TheScope,tree->token);
			Analyzer(tree->right->right->left,findScope( TheScope->nextScope));
        	scope--;
			return;
		}
	}

	else if(strcmp(tree->token, "return") == 0)
	{
		SCOPE * tmp= TheScope;
		int flag=true;
		while(strcmp(tmp->name,"function")!=0&&strcmp(tmp->name,"PROC")!=0&&strcmp(tmp->name,"CODE")!=0)
		{
			tmp=tmp->preScope;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType))
			{
			printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
			printf("%s ,%s %s\n",getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType,tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
			exit(1);
			}
		}
		else
		{
			if (strcmp(tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType, "void")==0) 
				flagNew=1; 
			if(tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType!=NULL && flagNew==0)
			{
				if(0==strcmp(getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType))
				{
					tmp->preScope->func[tmp->preScope->Checkcount-1]->findreturn=true;
				}
				else 
				{
					printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
					printf("%s ,%s %s\n",getExpType(tree->left,TheScope),tmp->preScope->func[tmp->preScope->Checkcount-1]->returnType,tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR, there can't be return in function '%s', because it's void type\n",tmp->preScope->func[tmp->preScope->Checkcount-1]->name);
				exit(1);
			}  
		}  
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    pushScopes(TheScope,tree->token);
	if (tree->left) 
		Analyzer(tree->left,findScope( TheScope->nextScope));
	
	if (tree->right)
		Analyzer(tree->right,findScope( TheScope->nextScope));
        scope--;
		return;			
	}
	else if(strcmp(tree->token, "solovar") == 0 )
	{
		findVar(tree->left,TheScope);
	}
	if (tree->left) 
		Analyzer(tree->left,TheScope);
	
	if (tree->right)
		Analyzer(tree->right,TheScope);
}


void pushScopes(SCOPE* from,char* name)
{
	SCOPE * point;
	if(globalScope==NULL)
		globalScope=mkScope(name);
	else{
	point=globalScope;
	while(point->nextScope!=NULL)
		point=point->nextScope;
	point->nextScope=mkScope(name);
	point->nextScope->preScope=from;
	}
}

char* findFuncInScopes(node * tree,SCOPE * TheScope)
{
	SCOPE* tmp=TheScope;
	Variables* arguments;
	bool find = false, flag = true;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->Checkcount;i++)
		if(strcmp(tree->left->token,tmp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			arguments=callFuncArguments(TheScope,tree->right->left,&count);
			if(count==tmp->func[i]->argNum)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(arguments[j].type,tmp->func[i]->arguments[t].type)!=0)
						flag=false;
				}
				if(flag==true)
					return tmp->func[i]->returnType;
			}
		}
		tmp=tmp->preScope;
	}
	printf("ERROR,func %s not find call in scope %s in the function %s\n",tree->left->token,TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
	if(find==true)
		printf("There is a function with the same name that accepts different arguments\n");
		exit(1);
}

char *findVar(node * tree,SCOPE * TheScope)
{
	SCOPE* tmp = TheScope;
	if(strcmp(tree->token,"solovar")==0)
		tree=tree->left;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->VarCount;i++)
		if(strcmp(tree->token,tmp->var[i].name)==0)
		{
			
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(tmp->var[i].type,"string")==0)
					if(strcmp(getExpType(tree->left->left,TheScope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in the function %s\n",TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) in scope %s in the function %s\n",TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
					exit(1);
				}

			}
			else
			return tmp->var[i].type;

		}
		tmp=tmp->preScope;
	}
	printf("ERORR, var %s wasn't found in scope %s in the function %s\n ",tree->token,TheScope->name,globalScope->func[globalScope->Checkcount-1]->name);
	exit(1);	
}

Variables * mkArguments(node *tree,int *count){
	Variables  *arr=NULL,arr2[50];
	char* type, *len ;
	if(tree!=NULL)
	{
		node * temp1=tree,*tmp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			tmp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
			{
				type=tmp->left->token;
				if(tmp->left->left!=NULL)
					len=tmp->left->left->left->token;
				node * tmptree;
				tmptree=tmp->right->left;
				do{
				arr2[*count].name=tmptree->token;
				arr2[*count].type=type;
				arr2[*count].len=len;
				(*count)++;
				if(tmptree->left==NULL)
					tmptree=NULL;
				else
					tmptree=tmptree->left->left;
				}while(tmptree!=NULL);
			}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(tmp->token, "var")!=0);
		tmp=temp1;
		if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
		{
			type=tmp->left->token;
			node * tmptree;
			if(strcmp(tmp->token, "var")==0)
			tmptree=tmp->right;
			else
			tmptree=tmp->right->left;
			if(tmp->left->left!=NULL)
			len=tmp->left->left->left->token;
			do{
			arr2[*count].name=tmptree->token;
			arr2[*count].type=type;
			arr2[*count].len=len;
			(*count)++;
			if(tmptree->left==NULL)
				tmptree=NULL;
			else
				tmptree=tmptree->left->left;
			}while(tmptree!=NULL);
		}
		arr=(Variables*)malloc(sizeof(Variables)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=arr2[i].name;
			arr[i].type=arr2[i].type;
		}
	}
	return arr;
}


Variables* callFuncArguments(SCOPE * TheScope,node *tree,int * count)
{
	Variables  *arr=NULL,arr2[50];
	char* type,*len;
	while(tree!=NULL)
	{
	arr2[*count].type = getExpType(tree->left, TheScope);
	(*count)++;
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;

	}
	arr=(Variables*)malloc(sizeof(Variables)*(*count));
	for(int i = 0; i<*count; i++)
		arr[i].type=arr2[i].type;
	return arr;
}
