#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", RED "��ˮ��" NOR);   
  set ("long", @LONG   
ʫԻ����¯�������������ɹ���߲أ��ľ����ǽ���壬��ˮ������������
��ˮ���ڣ����ɹ�֮������̫��֮����Ī�⣻����һ����̨������һ������«
�����������󣬽���«����һ���������ˮ�������޼ʡ�����ˮ����һ�㣬������ϣ�
��̻�ΪѪˮ���������ɣ��������ӡ�
LONG);

    set("exits", ([ 
               "west" : __DIR__"fenghou",
               "southeast" : __DIR__"xianxian",
               "north" : __DIR__"luohun",
                 ]));
    set("objects",([
                    __DIR__"npc/monpc" : 1,
                 ]));
    setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(20) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), RED "\n\n�㲻С��մ��һ���ˮ��\n\n" NOR);
 COMBAT_D->report_status(ob);
 ob->receive_damage("kee", random(50)+50);
 ob->receive_wound("kee", 20);
 if( environment(ob) == this_object())
 call_out("blowing",random(20)+1, ob);
}
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
}
