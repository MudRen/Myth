#include <ansi.h>
inherit F_CLEAN_UP;

int main()
{
        string day,season,time;
       mapping date;      
       int hour;
          
       date=XYJTIME_D->check_time(time());
       season=XYJTIME_D->check_season();
       day=date["YEAR"]+date["MONTH"]+date["DAY"]+date["HOUR"]+date["QUARTER"];
       time="�������ʱ����"+day+" "+season+" \n"NOR;
       write( time );

       return 1;
}

int help()
{
        write("

ָ���ʽ��xyjtime 

�����������鿴�������μ��������������е�����!

�����Ϣ��time��uptime
");
        return 1;
}

