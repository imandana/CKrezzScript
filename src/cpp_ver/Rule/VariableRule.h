#ifndef __VARIABLE_RULE_H__
#define __VARIABLE_RULE_H__

typedef struct VariableRule VariableRule;
struct VariableRule
{
    pid_t pid;
    char password[TAM_MAX]; // -> 50 chars
    pno next;

    bool (*Processing)(const char *text); 
    
    bool (*VarFilter)(const char *text);  
    bool (*NameFilter)(const char *text);
    bool (*OperatorFilter)(const char *text);
    bool (*ValueFilter)(const char *text);
    bool (*EndingFilter)(const char *text);
};

bool VariableRule_Processing(const char *text) 
{ 

}
bool VariableRule_VarFilter(const char *text) 
{ 

}
bool VariableRule_NameFilter(const char *text) 
{ 

}
bool VariableRule_OperatorFilter(const char *text) 
{ 

}
bool VariableRule_ValueFilter(const char *text) 
{ 

}
bool VariableRule_EndingFilter(const char *text) 
{ 

}

VariableRule vr;
vr.AddClient = client_t_AddClient;

#endif //__VARIABLE_RULE_H__
