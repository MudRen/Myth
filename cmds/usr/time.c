// time.c
// rewritten by mudring

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int age;
    int exp;
    int dx;
    int time;
    object ob;
/*
    //Add By Aeddy 2004-1-9
    string season, weather;
    season=XYJTIME_D->check_weather_season();
    weather=NATURE_D->check_weather();
*/
    seteuid(getuid(me));

    if (!arg) ob = me;
    else if (wizardp(me))
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    } 
    else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");

    age  = (ob->query("mud_age") - ob->query_temp("logon_mudage"));
    time = (time()-ob->query_temp("logon_time"));

    if (age < 60)  age = 60;

    exp = (ob->query("combat_exp") - ob->query_temp("logon_exp")) * 60 / age;
    dx  = (ob->query("daoxing") - ob->query_temp("logon_daoxing")) * 60 / age;


//    write("������"HIY"������"HIG"���߿ڡ�վ"NOR + NATURE_D->game_time() + "��\n");
    write("������" + CHINESE_D->chinese_date(time()) + "��\n");
// 43      write("������" + NATURE_D->game_time() +" "+season+weather+ " \n"NOR);
    write(ob->name(1) + "����Ѿ���������" + CHINESE_D->chinese_time(time) + "��\n");
    if (wizardp(me))
        write(ob->name(1) + "�����������" + CHINESE_D->chinese_time(age) + "��\n");
if (age > 300)
{
    write(ob->name(1) + "�ϴξ��飺" + ob->query_temp("logon_exp") 
          + "�����ھ��飺" + ob->query("combat_exp") + "��ƽ��ÿ����" + exp + "�㡣\n" );
    write(ob->name(1) + "�ϴε��У�" + ob->query_temp("logon_daoxing")
          + "�����ڵ��У�" + ob->query("daoxing") + "��ƽ��ÿ����" + dx + "�㡣\n" );
}
    return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: time

���ָ������(��)֪�����ڵ�ʱ����

HELP
    );
    return 1;
}
