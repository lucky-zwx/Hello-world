//
// Created by ZHUWX on 2018/1/29.
//

#include "Hand.h"

int Kaorou (char poststr[])
{
    char kr1[50]={0};
    char kr2[50]={0};
    char kr3[50]={0};
    char kr4[50]={0};
    char kr5[50]={0};
    char kr6[50]={0};
    char number1[50]={0};
    char number2[50]={0};
    char name[100]={0};
    char name2[100]={0};
    char louhao[5]={0};
    char sushehao[5]={0};
    char dianhua[12]={0};
    char yaoqiu[100]={0};
    double sum;
    sum = 1.0;
    char QR[]="<img src=\"http://www.xiaoyuan666.com/images/1511877467620.jpg\" width=\"567px\" height=\"992px\">";
    printf("Content-Type:text/html;charset=GB2312\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >֧������</TITLE>\n</HEAD>\n");
    printf("<BODY>\n");
    printf("<div style = \"color:blue;text-align:center\">\n");
    sscanf(poststr, "zhi=%[^&]&kr1=%[^&]&kr2=%[^&]&kr3=%[^&]&kr4=%[^&]&number1=%[^&]&kr5=%[^&]&kr6=%[^&]&number2=%[^&]&name=%[^&]&louhao=%[^&]&sushehao=%[^&]&dianhua=%[^&]&name2=%[^&]&yaoqiu=%[^&]",&zhi, &kr1, &kr2, &kr3, &kr4, &number1, &kr5, &kr6, &number2, &name, &louhao, &sushehao, &dianhua, &name2, &yaoqiu);
    if (kr3[0]=='1')
        sum+=8.0;
    if (kr3[0]=='2')
        sum+=10.0;
    if (kr4[0]=='1')
        sum=sum+5.5*((number1[0]-'0')*1.0);
    if (kr4[0]=='2')
        sum=sum+5*((number1[0]-'0')*1.0);
    if (kr5[0]=='1')
        sum=sum+((number2[0]-'0')*1.0);
    if (kr5[0]=='2')
        sum=sum+2.5*((number2[0]-'0')*1.0);
    if (kr5[0]=='3')
        sum=sum+3.0*((number2[0]-'0')*1.0);
    urldecode(name2); //�����
    urldecode(name);
    urldecode(kr1);
    urldecode(kr2);
    urldecode(kr3);
    urldecode(kr4);
    urldecode(kr5);
    urldecode(kr6);
    urldecode(yaoqiu);

    kr1[0]=' ';
    kr2[0]=' ';
    kr3[0]=' ';
    kr4[0]=' ';
    kr5[0]=' ';
    kr6[0]=' ';

    printf("<div>������֣�%s</div>",name);
    printf("<div>���֧�����˺ţ�%s</div>",name2);
    printf("<div>���Ĳͣ�%s %s %s </div>", kr1, kr2, kr3);
    printf("<div>���Ĳͣ�%s ������%s��</div>", kr4, number1);
    printf("<div>���Ĳͣ�%s %s ������%s��</div>", kr5, kr6, number2);
    printf("<div>���¥�ţ�%s</div>",louhao);
    printf("<div>�������ţ�%s</div>",sushehao);
    printf("<div>��ĵ绰��%s</div>",dianhua);
    printf("<h1>����Ҫ֧����%.2fԪ(����1Ԫ�����) �˶��Ϸ�������ȷ�������ɨ��֧����</h1>",sum);

    FILE *fp;
    if ((fp = fopen("C:\\Program Files\\Apache Software Foundation\\Apache2.2\\htdocs\\KAOROU.txt","aw")) == NULL)	//Write
    {
        printf ("ERROR\n");
        exit (0);
    }

    fputc('\n',fp);
    fprintf(fp, "%s", kr1);
    fprintf(fp,"%s","   ");
    fprintf(fp, "%s", kr2);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",kr3);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",kr4);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",number1);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",kr5);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",kr6);
    fprintf(fp,"%s","   ");
    fprintf(fp,"%s",number2);
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
    fprintf(fp,"��Ҫ֧����%.2fԪ",sum);
    fprintf(fp,"%s","   ");
    time_t timep;
    time (&timep);
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