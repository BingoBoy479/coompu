#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3 != 0) {
        printf("Usage: %s -o input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *fp_input , *fp_output;
    char line[1024];
    int c;
    fp_input=fopen(argv[1],"r");
    fp_output=fopen(argv[2],"w");
    if(fp_input==NULL){
        printf("Input file not opened");
        exit(0);
    }
    if(fp_output==NULL){
        printf("Output file not opened");
        exit(0);
    }
    while ((c=fgetc(fp_input)) != EOF) {
        if (c != '\n' && c != '\r') {
            fputc(c, fp_output);
        }
        
    }
    fclose(fp_input);
    fclose(fp_output);
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main(){
//     FILE *fp,*fp1;
//     char line[1024];
//     int c;
//     fp=fopen("g.txt","r");
//     fp1=fopen("g2.txt","w");
//     if(fp==NULL)  {
//         printf("Some problem in opening the file");
//         exit(0);
//     }
//     else  {
//          while (fscanf(fp, "%[^;]s", line) == 1) { 
            
//             while (c == '\n'|| c=='\r') {
                
//             }
//             ungetc(c,fp);
//             fprintf(fp,"%s\n",line);
//             if(feof(fp)){
//                 break;
//             }
//         }
//     }
//     fclose(fp);
//     fclose(fp1);
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     FILE *fp, *fp1;
//     char line[1024];
//     int c;

//     fp = fopen("g.txt", "r");
//     fp1 = fopen("g2.txt", "w");

//     if (fp == NULL || fp1 == NULL) {
//         printf("Some problem in opening the file");
//         exit(1);
//     } else {
//         while ((c = fgetc(fp)) != EOF) {
//             if (c != ';') {
//                 ungetc(c, fp);
//                 fgets(line, sizeof(line), fp);
//                 fprintf(fp1, "%s", line);
//             } else {
//                 fprintf(fp1, "%c", c); // Write the semicolon
//             }
//         }
//     }

//     fclose(fp);
//     fclose(fp1);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     FILE *fp, *fp1;
//     char line[1024];
//     int c;

//     fp = fopen("g.txt", "r");
//     fp1 = fopen("g2.txt", "w");

//     if (fp == NULL || fp1 == NULL) {
//         printf("Some problem in opening the file");
//         exit(1);
//     } else {
//         while ((c = fgetc(fp)) != EOF) {
//             if (c == '\n' || c == '\r') {
//                 continue; // Skip '\n' and '\r'
//             } else if (c != ';') {
//                 ungetc(c, fp);
//                 fgets(line, sizeof(line), fp);
//                 fprintf(fp1, "%s", line);
//             } else {
//                 fprintf(fp1, "%c", c); // Write the character
//             }
//         }
//     }

//     fclose(fp);
//     fclose(fp1);

//     return 0;
// }