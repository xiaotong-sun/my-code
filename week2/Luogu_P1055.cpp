#include <stdio.h>

#define zero 48

int main() {
    char isbn[14];
    int total = 0, j = 1, end_num;
    scanf("%s", isbn);                                  //read data as a string
    for(int i = 0; i < 11; i ++) {
        if(isbn[i] != '-') {
            total += (isbn[i] - zero) * j;
            j ++;
        }
    }
    end_num = total % 11;
    /* when end_num is 10 */
    if(end_num == 10) {
        end_num = 88;
        if(end_num == isbn[12]) {
            printf("Right");
        } else {
            isbn[12] = 'X';
            printf("%s", isbn);
        }
    } 
    /* when end_num is not 10 */
    else {
        if (end_num == isbn[12] - zero) {
            printf("Right");
        } else {
            isbn[12] = end_num + zero;
            printf("%s", isbn);
        }
    }
    return 0;
}