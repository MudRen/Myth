#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIY "�����" NOR);   
  set ("long", @LONG   
������ͭ�ַǽ𣬲���¯�л���Ѱ���������ɷ���������λ����ѽ���
ƶ��������ڣ�������֮���������֮�������ж�ʮһ�汦���ö�ʮһ���ߣ�
ÿһ��Ӧ�ڸ߶��ϣ�һ������һ�ס���������;�󣬽�����ק�������𶯾��ӣ�
ֻһ��ת������������ס�������̻�ΪŨѪ���ݻ��;�ڣ���Խ����
LONG);

    set("exits", ([ 
               "south" : __DIR__"dilie",
               "northwest" : __DIR__"juexian",
               "east" : __DIR__"huaxue",
                 ]));
    set("objects",([
        __DIR__"npc/monpc" : 1,
                 ]));
    setup();
}
void init()
{object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(20) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIY "\n\nǧ�����������㣬��һ��ͷ�Ρ�\n\n" NOR);
 ob->receive_damage("sen", random(100)+50);
 COMBAT_D->report_sen_status(ob);
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
