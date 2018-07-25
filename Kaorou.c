//
// Created by ZHUWX on 2018/1/29.
//

#include "Hand.h"

int Kaorou (char poststr[])
{
    char kr1[200]={0};
    char kr2[200]={0};
    char kr3[200]={0};
    char kr4[200]={0};
    char kr5[200]={0};
    char kr6[200]={0};
    char number1[200]={0};
    char number2[200]={0};
    char name[200]={0};
    char name2[200]={0};
    char louhao[200]={0};
    char sushehao[200]={0};
    char dianhua[200]={0};
    char yaoqiu[9999]={0};
    double sum=1.0;
    time_t timep;
    time (&timep);
    char QR[]="<img src=\"http://www.xiaoyuan666.com/images/1511877467620.jpg\" width=\"567px\" height=\"992px\">";
    printf("Content-Type:text/html;charset=GBK\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >支付界面</TITLE>\n</HEAD>\n");
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
    urldecode(name2); //解码后
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

    printf("<div>（づ￣3￣）づ</div>");
    printf("<div>你的名字：%s</div>",name);
    printf("<div>你的支付宝账号：%s</div>",name2);
    printf("<div>你点的餐：%s %s %s </div>", kr1, kr2, kr3);
    printf("<div>你点的餐：%s 份数：%s份</div>", kr4, number1);
    printf("<div>你点的餐：%s %s 份数：%s份</div>", kr5, kr6, number2);
    printf("<div>你的楼号：%s</div>",louhao);
    printf("<div>你的宿舍号：%s</div>",sushehao);
    printf("<div>你的电话：%s</div>",dianhua);
    printf("<h1>你需要支付：%.2f元(包含1元服务费) 核对上方数据请确保无误后扫码支付！</h1>",sum);

    FILE *fp;
    if ((fp = fopen("C:\\Program Files\\Apache Software Foundation\\Apache2.2\\htdocs\\KAOROU.txt","aw")) == NULL)	//Write
    {
        printf ("ERROR\n");
        exit (0);
    }

    fputc('\n',fp);
    fprintf(fp,"餐馆：烤肉拌饭  |");
    fprintf(fp,"%s  |", kr1);
    fprintf(fp,"%s  |", kr2);
    fprintf(fp,"%s  |", kr3);
    fprintf(fp,"%s  |", kr4);
    fprintf(fp,"份数：%s  |", number1);
    fprintf(fp,"%s  |", kr5);
    fprintf(fp,"%s  |", kr6);
    fprintf(fp,"份数：%s  |", number2);
    fprintf(fp,"姓名：%s  |", name);
    fprintf(fp,"楼号：%s  |", louhao);
    fprintf(fp,"宿舍号：%s  |", sushehao);
    fprintf(fp,"电话：%s  |", dianhua);
    fprintf(fp,"支付宝账号：%s  |", name2);
    fprintf(fp,"要求：%s  |", yaoqiu);
    fprintf(fp,"需要支付：%.2f元  订单时间：%s  <div></div>",sum,ctime(&timep));
    fclose(fp);

    printf ("%s",QR);                   //输出二维码
    printf("</div>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
    fflush(stdout);
    return 0;
}