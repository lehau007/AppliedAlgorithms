#include <stdio.h> 
using namespace std;

const int MAX_VAL = 100000;

int frequency[MAX_VAL + 1];
int min_val = MAX_VAL + 1;   

int main() {
    char operation[5];              
    
    while (true) {
        scanf("%s", operation);       
        
        if (operation[0] == '#') break; 

        if (operation[0] == 'P' && operation[1] == 'U') { 
            int e;
            scanf("%d", &e);         
            frequency[e]++;             
            if (e < min_val) {           
                min_val = e;
            }
        } 
        else if (operation[0] == 'P' && operation[1] == 'O') { 
            printf("%d\n", min_val); 
            frequency[min_val]--;    

            while (min_val <= MAX_VAL && frequency[min_val] == 0) {
                min_val++;
            }
        }
    }

    return 0;
}
