#include "Hand.h"

int main(){
    char *lenstr,poststr[500];
    char *ptr;
    lenstr=getenv("CONTENT_LENGTH");
    long len=strtol(lenstr,&ptr,10)+1;
    if(lenstr == NULL && len<0 && len>9999)
        printf("<DIV style = \"color:blue;text-align:center\">您的输入信息为空！！！</DIV>\n");
    fgets(poststr,len,stdin);
    sscanf(poststr,"zhi=%[^&]",&zhi);

    switch (zhi[0])
    {
        case '1':
            Wanzhou(poststr);
            break;
        case '2':
            Kaorou(poststr);
            break;
        case '3':
            Tujia(poststr);
            break;
        case '4':
            Smnoodles(poststr);
            break;
        case '5':
            Yangrou(poststr);
            break;
        case '6':
            Yipin(poststr);
            break;
        case '7':
            Egg(poststr);
            break;
        case '8':
            Hundun(poststr);
            break;
        case '9':
            English(poststr);
            break;
        default:
            printf("ERROR");
    }
    return (0);
}
