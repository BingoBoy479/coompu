#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//needed this one for isaplha and isdigit
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

char *operator[3]={"==","<",">","!="};
typedef enum
/*if u write name here then u are naming the enum but 
when u write name at line19 aka end of curly bracket then
we are haveing name for the refrence pointer*/
{
    Equals,
    Less_than,
    Greater_than,
    Not_Equals
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

FILE* removing_new_line(char* in, char* out){
    FILE* fp_input; 
    FILE* fp_output;
    int c;
    fp_input=fopen(in,"r");
    if(fp_input==NULL){
        printf("Input file not opened");
        exit(1);
    }
    fp_output=fopen(out,"w");
    if(fp_output==NULL){
        printf("Output file not opened");
        exit(1);
    }
    
    while ((c=fgetc(fp_input)) != EOF) {
        // checking for comments 
        if (c == '/') {
            // case in point the condition where we encounter a comment
            int next_char = fgetc(fp_input);
            if (next_char == '/') {
                // single-line comment
                while ((c=fgetc(fp_input)) != '\n' && c != EOF);
                continue;  // continue to the next character after newline
            } else if (next_char == '*') {
                // multi-line comment
                int prev_char = 0;
                while ((c=fgetc(fp_input)) != EOF) {
                    if (prev_char == '*' && c == '/') {
                        break;  // end of multi-line comment
                    }
                    prev_char = c;
                }
                continue;  // continue to the next character after comment
            } else {
                // not a comment, put back the character and continue
                ungetc(next_char, fp_input);
            }
        }
        // write the character to the output file if it's not a newline
        if (c != '\n' && c != '\r') {
            fputc(c, fp_output);
        }
    }

    fclose(fp_input);
    fclose(fp_output);
    return fp_output;
}
char *current = 0;
int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Usage: %s -o input_file output_file\n", argv[0]);
        return 1;
    }
    
    FILE* fp=removing_new_line(argv[1],argv[2]);
    /* fp is the outputed intermediate */    
    
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    current = malloc(sizeof(char) * length+1);
    fread(current, 1, length, fp);

    fclose(fp);

    current[length] = '\0';//ensures no buffer overflow occurs
    int current_index = 0;


    
    printf("Hi!\n");
    printf("%d\n",sizeof(int));
    Token *mytoken = malloc(sizeof(Token));
    assignTokenValue(mytoken,"separator","#");
    printf("%s\n",mytoken->name);
    printf("%d\n",(int)mytoken->t.to);
    for (int i = 0; i < 31; i++)
    {
        resize_and_add(mytoken);
    }
    for (int i = 0; i < 31; i++)
    {
        printf("%d\n",i);
        printf("%s\n",main_array[i].name);
        printf("%d\n",(int)main_array[i].t.to);
    }
    free(mytoken);
    free(main_array);
    return 0;
}