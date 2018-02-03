#include "Hand.h"

int main(){
    char *lenstr,poststr[500];
    int len=99999;
    lenstr=getenv("CONTENT_LENGTH");
    if(lenstr == NULL)
        printf("<DIV style = \"color:blue;text-align:center\">您的输入信息为空！！！</DIV>\n");
    fgets(poststr,len+1,stdin);
    sscanf(poststr,"zhi=%[^&]",zhi);
    if (zhi[0]=='1')
        Wanzhou (poststr);
    else
    if (zhi[0]=='2')
        Kaorou (poststr);
    return 0;
}