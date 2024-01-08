#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char separators[12]={'{','}','(',')',';',',','#','/','"','\\','\'','='};
typedef enum 
/*if u write name here then u are naming the enum but 
when u write name at line19 aka end of curly bracket then
we are haveing name for the refrence pointer*/
{
    Open_curly_bracket,//int value 0
    Close_curly_bracket,
    Open_parenthesis,
    Close_parenthesis,
    Semicolon,
    Comma,
    Hashtag,
    Forward_slash,
    Double_cotation,
    Backward_slash,
    Single_cotation,
    Assignment//int value 11
}Type_Separators;

char *keywords[11]={"start","char","int","float","if","elif","else","for","while","break","exit"};
typedef enum 
/*if u write name here then u are naming the enum but 
when u write name at line19 aka end of curly bracket then
we are haveing name for the refrence pointer*/
{
    Begin,//int 0
    Character,
    Integer,
    Floating,
    IF,
    ELIF,
    ELSE,
    For,
    While,
    Break,
    End//int 10
} Type_Keyword;

char *operator[3]={"==","<",">"};
typedef enum
/*if u write name here then u are naming the enum but 
when u write name at line19 aka end of curly bracket then
we are haveing name for the refrence pointer*/
{
    Equals,
    Less_than,
    Greater_than
}Type_Operator;


typedef union
/*if u write name here then u are naming the enum but 
when u write name at line19 aka end of curly bracket then
we are haveing name for the refrence pointer*/
{
    Type_Separators ts;
    Type_Keyword tk;
    Type_Operator to;
}TypeUnion;

typedef struct 
/*if u write name here then u are naming the enum but 
when u write name at line19 aka end of curly bracket then
we are haveing name for the refrence pointer*/
{
    const char* name;
    TypeUnion t;

}Token;

void assignTokenValue(Token *t,char *info,char *dis){
    if(strcmp(info,"separator")==0){
        int a=-1;
        for(int i = 0; i<12;i++){
            if(dis[0]==separators[i]){
                a=i;
                break;
            }
        }
        if(a!=-1){
            t->name="separator";
            t->t.ts=a;
        }
        else{
            t->name="Invalid";
            
        }    
    }
    else if(strcmp(info,"keyword")==0){
        int a=-1;
        for(int i = 0; i<12;i++){
            if(dis[0]==separators[i]){
                a=i;
                break;
            }
        }
        if(a!=-1){
            t->name="keyword";
            t->t.tk=a;
        }
        else{
            t->name="Invalid";
            
        }    
    }
    else if(strcmp(info,"operator")==0){
        int a=-1;
        for(int i = 0; i<12;i++){
            if(dis[0]==separators[i]){
                a=i;
                break;
            }
        }
        if(a!=-1){
            t->name="operator";
            t->t.to=a;
        } 
        else{
            t->name="Invalid";
            
        }   
    }
    else{
        t->name="Invalid";
        
    }
}

Token * main_array = 0;
int allocator_pointer=0;
int new_size=10;

void resize_and_add(Token *t) {
    if (main_array == NULL) {
        main_array = malloc(new_size * sizeof(Token));
        if (main_array == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    if (allocator_pointer >= new_size) {
        new_size += 10;
        Token* temp = realloc(main_array, new_size * sizeof(Token));
        if (temp == NULL) {
            printf("Memory reallocation failed!\n");
            return;
        }
        main_array = temp;
    }
    main_array[allocator_pointer] = *t;
    allocator_pointer++;
}

int main(){
    printf("Hi!\n");
    Token *mytoken = malloc(sizeof(Token));
    assignTokenValue(mytoken,"separator","#");
    printf("%s\n",mytoken->name);
    printf("%d\n",(int)mytoken->t.to);
    resize_and_add(mytoken);
    printf("%s\n",main_array[0].name);
    printf("%d\n",(int)main_array[0].t.to);
    free(mytoken);
    free(main_array);
    return 0;
}