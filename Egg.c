//
// Created by ZHUWX on 2018/3/17.
//
#include "Hand.h"

int Egg(char poststr[])
{
    char noodles[200]={0};
    char ch1[200]={0};
    char name[200]={0};
    char name2[200]={0};
    char louhao[100]={0};
    char sushehao[100]={0};
    char dianhua[100]={0};
    char yaoqiu[999]={0};
    double sum=1.0;
    time_t timep;
    time (&timep);
    char QR[]="<img src=\"http://www.xiaoyuan666.com/images/1511877467620.jpg\" width=\"567px\" height=\"992px\">";

    sscanf(poststr,
               "zhi=%[^&]&noodles=%[^&]&ch1=%[^&]&name=%[^&]&louhao=%[^&]&sushehao=%[^&]&dianhua=%[^&]&name2=%[^&]&yaoqiu=%[^&]",
               &zhi, &noodles, &ch1, &name, &louhao, &sushehao, &dianhua, &name2, &yaoqiu);

    if (noodles[0]=='1' || noodles[0]=='2' || noodles[0]=='3')
    {
        sum+=6.0;
    }

    if (ch1[0]=='1') sum+=3.5;
    if (ch1[0]=='2') sum+=4.0;
    if (ch1[0]=='3') sum+=5.0;
    if (ch1[0]=='4') sum+=6.0;
    if (ch1[0]=='5') sum+=7.0;
    if (ch1[0]=='6') sum+=8.0;
    if (ch1[0]=='7') sum+=9.0;
    if (ch1[0]=='8') sum+=10.0;

    urldecode(name);
    urldecode(name2);
    urldecode(noodles);
    urldecode(ch1);
    urldecode(yaoqiu);

    ch1[0]=' ';
    noodles[0]=' ';

    printf("Content-Type:text/html;charset=GBK\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >支付界面</TITLE>\n</HEAD>\n");
    printf("<BODY>\n");
    printf("<div style = \"color:blue;text-align:center\">\n");

    printf("<div>（づ￣3￣）づ</div>");
    printf("<div>你的名字：%s</div>",name);
    printf("<div>你的支付宝账号：%s</div>",name2);
    if (ch1[0]!=0)
        printf("<div>已选择灌饼</div>");
    ch1[0]=' ';
    printf("<div>你点的餐：%s</div>",noodles);
    printf("<div>你的楼号：%s</div>",louhao);
    printf("<div>你的宿舍号：%s</div>",sushehao);
    printf("<div>你的电话：%s</div>",dianhua);
    printf("<h1>你需要支付：%.2f元(包含1元服务费) 核对上方数据请确保无误后扫码支付！</h1>",sum);
    printf ("%s",QR);                   //输出二维码
    printf("</div>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");


    FILE *fp;
    if ((fp = fopen("C:\\Program Files\\Apache Software Foundation\\Apache2.2\\htdocs\\Egg.txt","aw")) == NULL)	//Write
    {
        printf ("ERROR\n");
        exit (0);
    }


    fputc('\n',fp);
    fprintf(fp,"餐馆：鸡蛋灌饼 |");
    fprintf(fp,"点餐：%s  |%s  |",ch1,noodles);
    fprintf(fp,"姓名：%s  |",name);
    fprintf(fp,"楼号：%s  |",louhao);
    fprintf(fp,"宿舍号：%s  |",sushehao);
    fprintf(fp,"电话：%s  |",dianhua);
    fprintf(fp,"支付宝账号：%s  |",name2);
    fprintf(fp,"要求：%s  |",yaoqiu);
    fprintf(fp,"需要支付：%.2f元  |",sum);
    fprintf(fp,"订单时间：%s   <div></div>",ctime(&timep));
    fclose(fp);

    fflush(stdout);
    return 0;
}
