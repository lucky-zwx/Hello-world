//
// Created by ZHUWX on 2018/3/8.
//
#include "Hand.h"

int Yipin (char postrstr[])
{
    int sum = 1;
    char soup[700]={0};
    char noodle[700]={0};
    char name[500]={0};
    char name2[500]={0};
    char louhao[50]={0};
    char sushehao[50]={0};
    char dianhua[120]={0};
    char yaoqiu[1000]={0};
    char QR[]="<img src=\"http://www.xiaoyuan666.com/images/1511877467620.jpg\" width=\"567px\" height=\"992px\">";

    sscanf(postrstr,"zhi=%[^&]&soup=%[^&]&noodle=%[^&]&name=%[^&]&louhao=%[^&]&sushehao=%[^&]&dianhua=%[^&]&name2=%[^&]&yaoqiu=%[^&]",&zhi,&soup,&noodle,&name,&louhao,&sushehao,&dianhua,&name2,&yaoqiu);

    if (soup[0]=='1') sum+=10;

    if ((soup[0]=='2') || (soup[0]=='3')) sum+=8;

    if (noodle[0]== '1' ) sum+=6;

    if ((noodle[0]== '2') || (noodle[0]=='3')) sum+=5;

    if (noodle[0]== '4') sum+=3;

    soup[0]=' ';
    noodle[0]=' ';


    urldecode(soup);
    urldecode(noodle);
    urldecode(name);
    urldecode(name2);
    urldecode(yaoqiu);

    printf("Content-Type:text/html;charset=GBK\n\n");
    printf("<HTML>\n");
    printf("<HEAD>\n<TITLE >支付界面</TITLE>\n</HEAD>\n");
    printf("<BODY>\n");
    printf("<div style = \"color:blue;text-align:center\">\n");
    printf("<div>（づ￣3￣）づ</div>");
    printf("<div>你的名字：%s</div>",name);
    printf("<div>你的支付宝账号：%s</div>",name2);
    printf("<div>你点的餐：%s  和  %s</div>",soup,noodle);
    printf("<div>你的楼号：%s</div>",louhao);
    printf("<div>你的宿舍号：%s</div>",sushehao);
    printf("<div>你的电话：%s</div>",dianhua);
    printf("<h1>你需要支付：%d元(包含1元服务费) 核对上方数据请确保无误后扫码支付！</h1>",sum);

    time_t timep;
    time (&timep);

    FILE *fp;
    if ((fp = fopen("C:\\Program Files\\Apache Software Foundation\\Apache2.2\\htdocs\\Yipin.txt","aw")) == NULL)	//Write
    {
        printf ("ERROR\n");
        exit (0);
    }


    fputc('\n',fp);
    fprintf(fp,"餐馆：上品牛肉汤 |");
    fprintf(fp,"点餐：%s  |%s  |",soup,noodle);
    fprintf(fp,"姓名：%s  |",name);
    fprintf(fp,"楼号：%s  |",louhao);
    fprintf(fp,"宿舍号：%s  |",sushehao);
    fprintf(fp,"电话：%s  |",dianhua);
    fprintf(fp,"支付宝账号：%s  |",name2);
    fprintf(fp,"要求：%s  |",yaoqiu);
    fprintf(fp,"需要支付：%d元  |",sum);
    fprintf(fp,"订单时间：%s   <div></div>",ctime(&timep));
    fclose(fp);

    printf ("%s",QR);                   //输出二维码
    printf("</div>\n");
    printf("</BODY>\n");
    printf("</HTML>\n");
    fflush(stdout);
    return 0;
}
