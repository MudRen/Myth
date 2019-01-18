//***************************************
//MUDLIB��Biographies         ����մ���   
//VERSION��Test 1.6.28   
//ENCODING��GB  
//Created Admin��By Waiwai           
//Admin Email��wkzstory@21cn.com         
//***************************************
//CMDS USR bjtime.c
//Created by waiwai@ 2000/11/13 ���½���
//By waiwai@ 2000/12/15 �Ż�
//���ļ���ֹ�ƶ������ļ���

#include <ansi.h>

#include <localtime.h>
inherit F_CLEAN_UP;

/*
 * if like chinese's time show ,can list here type to return
 * type = 5 , return string like ������������¶�ʮ���� ���� ʮһ����ʮ�˷�ʮ���� ������
 * type = 2 , return string like ������һ�����¶�ʮ���� ���� ʮһ����ʮ�߷ֶ�ʮ��
 * type = 3 , return string like ���¶�ʮ���� ���� ʮһ����ʮ�߷���ʮ���� ������
 * type = 4 , return string like ���¶�ʮ���� ���� ʮһ����ʮ�˷ֶ���
 * type = 1 , return string like 1998��10��31�� ���� 11��20��23��
 * type = 6 , return string like 3��28��11��38��
 * type = 7 , return string like 2001/03/28 11:38
 * type = 8 , return string like 2001��03��28�� 11:39
 * type = 9 , return string like 3��28��
 * if not define type, default return string like define type =1
 * if need conversion time not now() can define string get_time
 * but get_time must like "Sun May  3 00:52:12 1998"
 * example chinese_time(1,ctime(time())
*/

string chinese_time(int type,string get_time)
{
        string e_time, week, month, year,time99;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);

        c_month = chinese_number(member_array(month, month_name) + 1);
      
        if(week=="Mon") c_week=HIC" ����һ"; 
        else if(week=="Tue") c_week=HIC" ���ڶ�";  
        else if(week=="Wed") c_week=HIC" ������";      
        else if(week=="Thu") c_week=HIC" ������";        
        else if(week=="Fri") c_week=HIC" ������";      
        else if(week=="Sat") c_week=HIR" ������";      
        else if(week=="Sun") c_week=HIR" ������";


          if(hour<6 && hour>0)               time99=HIW" �賿 "HIC;  
             else if(hour<8 && hour >=6)     time99=HIM" ���� "HIC;    
             else if(hour<12 && hour>=8)     time99=HIY" ���� "HIC;   
             else if(hour==12)               time99=HIR" ���� "HIC;     
             else if(hour<19 && hour>12)     time99=HIC" ���� "HIC;    
             else if(hour<24 && hour>=19)    time99=HIB" ���� "HIC;    
             else if (hour==24 || hour==0)   time99=HIR" ��ҹ "HIC;   
    
          if(hour>12) {               
            if(hour==13)            hour=1;      
            else    if(hour==14)            hour=2;     
            else    if(hour==15)            hour=3;    
            else    if(hour==16)            hour=4;    
            else    if(hour==17)            hour=5;     
            else    if(hour==18)            hour=6;      
            else    if(hour==19)            hour=7;      
            else    if(hour==20)            hour=8;    
            else    if(hour==21)            hour=9;   
            else    if(hour==22)            hour=10;     
            else    if(hour==23)            hour=11;    
            else    if(hour==24)            hour=0;    
             }

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "��";
        c_month  = c_month + "��";

        c_time = chinese_number(day) + "��";
        c_time += time99;
        c_time += chinese_number(hour) + "��";
        c_time += chinese_number(minute) + "��";
        // maybe not need srcond to show
        c_time += chinese_number(second) + "��";

        if (type) {
                switch( type ) {
                        case 5: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 1: return NOR WHT+year+"��"+(member_array(month, month_name) + 1)+
                                "��"+day+"��"+time99+NOR WHT+hour+"��"+minute+"��"+second+"��"NOR;
                        case 6: return (member_array(month, month_name) + 1)+
                                "��"+day+"��"+hour+"��"+minute+"��";
                        case 7: 
                                return replace_string(sprintf("%s/%2d/%2d",
 year, (member_array(month, month_name) + 1), day), " ", "0") 
                                       + " " + e_time[11..15]; 
                        case 8: 
                                return replace_string(sprintf("%s��%2d��%2d��",
 year, (member_array(month, month_name) + 1), day), " ", "0") 
                                       + " " + e_time[11..15]; 
                        case 9: return (member_array(month, month_name) + 1)+
                                "��"+day+"��";

                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int main(object me, string arg)
{
        int i;

        if(!arg||sscanf(arg,"%d",i)!=1)
                write(HIC"���ڱ�׼����ʱ�䣺" + chinese_time(5,(string)localtime(time())) + "\n"NOR);
        else
                write(NOR WHT"���ڱ�׼����ʱ�䣺" + chinese_time(i,(string)localtime(time())) + "\n"NOR);
        return 1;
}

int help(object me)
{
     write(@HELP

ָ���ʽ: bjtime

���ָ������(��)֪�����ڵ�ʵ��ʱ�䡣
���Դ�����1-9�Բ�ͬ�ĸ�ʽ��ʾ��

HELP
    );
    return 1;
}

