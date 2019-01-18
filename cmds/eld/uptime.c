//CMDS USR uptime.c
//Created by waiwai@2000/11/13

#include <localtime.h>
#include <mudlib.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(int i)
{
        int t, y, mo, d, h, m, s;
        mixed *ltime;
        string time;

        ltime = localtime(time());
        s = ltime[LT_SEC];
        m = ltime[LT_MIN];
        h = ltime[LT_HOUR];
        d = ltime[LT_MDAY];
        mo = ltime[LT_MON]+1;
        y = ltime[LT_YEAR];
//      time = "����������";
        
/*
        if (!intp(i)){
                write(CHINESE_MUD_NAME+"�ϴε���ԭ��"+read_file("/log/static/LASTCRASH") );

        }
*/
        
        while (y) {
                time = chinese_number(y%10) + time;
                y /= 10;
        }
        time += chinese_number(mo) + "��";
        time += chinese_number(d) + "��";
        time += chinese_number(h) + "ʱ";
        time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        write(CHINESE_MUD_NAME+"�Ѿ�����������" + time + "\n");
        
        return 1;
}

int help(object me)
{
        write(
"\nָ���ʽ : uptime\n\n"
"���ָ���������" CHINESE_MUD_NAME "�������Ϸ�Ѿ�����ִ���˶�á�\n"
    );
    return 1;
}


