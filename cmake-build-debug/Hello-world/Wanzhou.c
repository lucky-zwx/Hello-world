//
// Created by ZHUWX on 2018/1/29.
//

#include "Hand.h"

int Wanzhou (char poststr[])
{
    char wz1[50]={0};
    char wz2[50]={0};
    char noodles[50]={0};
    char name[100]={0};
    char name2[100]={0};
    char louhao[5]={0};
    char sushehao[5]={0};
    char dianhua[12]={0};
    char yaoqiu[100]={0};
    int sum=1;
    char QR[]="<img src=\"http://www.xiaoyuan666.com/images/1511877467620.jpg\" width=\"567px\" height=\"992px\">";
    printf("Content-Type:text/html;charset=GB2312\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >֧������</TITLE>\n</HEAD>\n");
    printf("<BODY>\n");
    printf("<div style = \"color:blue;text-align:center\">\n");
    sscanf(poststr,"zhi%[^&]&wz1=%[^&]&wz2=%[^&]&noodles=%[^&]&name=%[^&]&louhao=%[^&]&sushehao=%[^&]&dianhua=%[^&]&name2=%[^&]&yaoqiu=%[^&]",&zhi,&wz1,&wz2,&noodles,&name,&louhao,&sushehao,&dianhua,&name2,&yaoqiu);
    if(wz1[0]=='1')
        sum=+9;
    if (wz1[0]=='2' || wz1[0]=='3' || wz1[0]=='4' || wz1[0]=='5')
        sum+=8;
    if (wz1[0]=='6' || wz1[0]=='7' || wz1[0]=='8' || wz1[0]=='9')
        sum+=7;
    if (wz1[0]=='0' || wz1[0]=='a' || wz1[0]=='b' || wz1[0]=='c')
        sum+=6;
    if (wz1[0]=='d' || wz1[0]=='e' || wz1[0]=='f')
        sum+=5;
    if(wz2[0]=='1')
        sum+=9;
    if(wz2[0]=='2')
        sum+=8;
    if(wz2[0]=='3' || wz2[0]=='4' || wz2[0]=='5')
        sum+=7;
    if(wz2[0]=='6' || wz2[0]=='7')
        sum+=6;
    urldecode(name2); //�����
    urldecode(name);
    urldecode(wz1);
    urldecode(wz2);
    urldecode(noodles);
    urldecode(yaoqiu);
    printf("<div>������֣�%s</div>",name);
    printf("<div>���֧�����˺ţ�%s</div>",name2);
    printf("<div>���Ĳͣ�%s</div>",wz1);
    printf("<div>���Ĳͣ�%s %s</div>",wz2,noodles);
    printf("<div>���¥�ţ�%s</div>",louhao);
    printf("<div>�������ţ�%s</div>",sushehao);
    printf("<div>��ĵ绰��%s</div>",dianhua);
    printf("<h1>����Ҫ֧����%dԪ(����1Ԫ�����) �˶��Ϸ�������ȷ�������ɨ��֧����</h1>",sum);
    time_t timep;
    time (&timep);

    FILE *fp;
    if ((fp = fopen("C:\\Program Files\\Apache Software Foundation\\Apache2.2\\htdocs\\WANZHOU.txt","aw")) == NULL)	//Write
    {
        printf ("ERROR\n");
        exit (0);
    }

    fputc('\n',fp);
    fprintf(fp,"%s",wz1);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",wz2);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",noodles);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",name);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",louhao);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",sushehao);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",dianhua);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",name2);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",yaoqiu);
    fprintf(fp,"%s","   ");
    fprintf(fp,"��Ҫ֧����%dԪ",sum);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",ctime(&timep));
    fprintf(fp,"%s","   ");
    fputs("<div></div>",fp);
    fclose(fp);

    printf ("%s",QR);                   //�����ά��
    printf("</div>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
    fflush(stdout);
    return 0;
}