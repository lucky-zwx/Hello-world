//
// Created by ZHUWX on 2018/3/8.
//

#include "Hand.h"

int Hundun (char poststr[])
{
    char checkbox1[200]={0};
    char hund[500]={0};
    char name[500]={0};
    char name2[500]={0};
    char louhao[50]={0};
    char sushehao[50]={0};
    char dianhua[120]={0};
    char yaoqiu[1000]={0};
    double sum=1.0;
    char QR[]="<img src=\"http://www.xiaoyuan666.com/images/1511877467620.jpg\" width=\"567px\" height=\"992px\">";

    sscanf(poststr,
               "zhi=%[^&]&hund=%[^&]&ch1=%[^&]&name=%[^&]&louhao=%[^&]&sushehao=%[^&]&dianhua=%[^&]&name2=%[^&]&yaoqiu=%[^&]",
               &zhi, &hund, &checkbox1, &name, &louhao, &sushehao, &dianhua, &name2, &yaoqiu);

    printf("Content-Type:text/html;charset=GBK\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >支付界面</TITLE>\n</HEAD>\n");
    printf("<BODY>\n");
    printf("<div style = \"color:blue;text-align:center\">\n");


    if (hund[0] == '1') sum+=5.0;
    if (hund[0] == '2') sum+=6.0;
    if (hund[0] == '3') sum+=7.0;

    if (checkbox1[0]=='1') sum+=4.0;
    if (checkbox1[0]=='2') sum+=4.5;
    if (checkbox1[0]=='3') sum+=4.5;
    if (checkbox1[0]=='4') sum+=5.0;
    if (checkbox1[0]=='5') sum+=5.0;
    if (checkbox1[0]=='6') sum+=5.5;
    if (checkbox1[0]=='7') sum+=6.5;
    if (checkbox1[0]=='8') sum+=7.0;


    urldecode(checkbox1); //解码后

    urldecode(name);
    urldecode(name2);
    urldecode(hund);
    urldecode(yaoqiu);

    hund[0]=' ';
    checkbox1[0]=' ';


    printf("<div>（づ￣3￣）づ</div>");
    printf("<div>你的名字：%s</div>",name);
    printf("<div>你的支付宝账号：%s</div>",name2);
    if (checkbox1[0]!=0)
        printf("<div>已选择煎饼</div>");
    if (hund[0]!=0)
        printf("<div>你点的餐：%s </div>",hund);
    printf("<div>你的楼号：%s</div>",louhao);
    printf("<div>你的宿舍号：%s</div>",sushehao);
    printf("<div>你的电话：%s</div>",dianhua);
    printf("<h1>你需要支付：%.2f元(包含1元服务费) 核对上方数据请确保无误后扫码支付！</h1>",sum);

    time_t timep;
    time (&timep);

    FILE *fp;
    if ((fp = fopen("C:\\Program Files\\Apache Software Foundation\\Apache2.2\\htdocs\\Hundun.txt","aw")) == NULL)	//Write
    {
        printf ("ERROR\n");
        exit (0);
    }


    fputc('\n',fp);
    fprintf(fp,"餐馆：混沌杂粮煎饼 |");
    fprintf(fp,"点餐：%s  |%s  |%s  |",checkbox1,hund);
    fprintf(fp,"姓名：%s  |",name);
    fprintf(fp,"楼号：%s  |",louhao);
    fprintf(fp,"宿舍号：%s  |",sushehao);
    fprintf(fp,"电话：%s  |",dianhua);
    fprintf(fp,"支付宝账号：%s  |",name2);
    fprintf(fp,"要求：%s  |",yaoqiu);
    fprintf(fp,"需要支付：%.2f元  |",sum);
    fprintf(fp,"订单时间：%s   <div></div>",ctime(&timep));
    fclose(fp);

    printf ("%s",QR);                   //输出二维码
    printf("</div>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
    fflush(stdout);
    return 0;
}