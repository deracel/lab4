/*
strdup--
strlen--
strtok--
strcmpy--
strncpy--
strsmpy--
*/

#include <stdio.h>
#include <stdlib.h>


char* mystrncpy(char* s, char* c, int n){
    int i = 0;
    while(i < n && c[i] != '\0'){
        s[i] = c[i];
        i++;
    }
    if (n > 0)
        s[n] = '\0';
    return s;
}

char* mystrcpy(char* s, const char* c){
    int i = 0;
    while(c[i] != '\0'){
        s[i] = c[i];
        i++;
    }
    s[i] = '\0';
    return s;
}

int mystrlen(char* s){
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char* mystrdup(char* s2){
    char* dup = malloc((mystrlen(s2) + 1) * sizeof(char));
    if (dup != 0){
        mystrcpy(dup, s2);
    }
    return dup;
}


char* mystrchr(const char * s, const char c) {
    while ( *s && *s != c )
        ++s;
    /*return ( *s ) ? (char*) s : NULL;*/
    if (*s)
        return (char *) s; 
    else
        return NULL;

}
 
char* mystrtok(char * str, const char * delim) {
    static char * next;
    
    if ( str ) {
        next = str;
        while ( *next && mystrchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! mystrchr(delim, *next) )
        ++next;
    while ( *next && mystrchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}