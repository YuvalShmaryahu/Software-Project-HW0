#include <stdio.h>
#include <math.h>

int source_base = 0;
int target_base = 0;
int source_num;
int final_number = 0;
int i = 0;
int sum = 0;
int booler = 0;

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

void reverse(void)
{
    char c;
    if((c = getchar()) != '\n'&& c != EOF){
    reverse();
    int curr_num = 0;
    if (source_base<11){
        if ((c-'0')>(source_base-1)||(c-'0')<0){
            booler = 1;
        }
        else {
            curr_num = c-'0';
        }
    }
    else {
        if ((c- '0')<0 || (c- '0')>9){
            if (c<97 || c>102){
                booler = 1;
            }
            if ((c-'a')> (source_base-10)-1){
                booler = 1;
            }
        }
        if (c-'0'<10){
                curr_num = c-'0';
            }
            else {
                curr_num = c-'a'+10;
            }
    }
    printf("curr_num is %d\n",curr_num);
    sum += (curr_num)*pow(source_base,i);
    i++;
}
return;
}

int main(void)
{
    printf("enter the source base:\n");
    int chara;
    int cnt = 0;
    while((chara = getchar()) != '\n' && chara != EOF)
        {
        if (cnt ==0){
            source_base = chara - '0';
            cnt +=1;
        }
        else {
            source_base = concatenate(source_base,chara-'0');
        }
        }
    cnt = 0;
    if (source_base <2 || source_base>16){
        printf("Invalid source base!\n");
                return 0;
    }


    printf("enter the target base:\n");

    while((chara = getchar()) != '\n' && chara != EOF)
        {
        if (cnt ==0){
            target_base = chara - '0';
            cnt +=1;
        }
        else {
            target_base = concatenate(target_base,chara-'0');
        }
        }

    if (target_base <2 || target_base>16){
        printf("Invalid target base!\n");
                return 0;
    }

    
    printf("enter a number in base %d:\n",source_base);
    reverse();
    if (booler ==1){
        printf("Invalid input number!\n");
        return 0;
    };

    printf("The Decimal is: %d\n",sum);
    return 0;
}
