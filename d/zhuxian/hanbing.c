#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIW "������" NOR);   
  set ("long", @LONG   
ʫ�ƣ��������ͺź�����һ����ɽ���������������ɷ������Ƥ���Ǿ���ƾ����
��Ϊ��ˮ��ʵΪ��ɽ���ڲ�������з��ף����б�ɽ�����������б����絶����
����������󣬷��׶���������һ�ģ���֫����촷ۣ�����������������ѡ�
LONG);

    set("exits", ([ 
               "east" : __DIR__"luohun",
               "west" : __DIR__"dilie",
               "north" : __DIR__"huaxue",
               "south" : __DIR__"fenghou",
                 ]));
    set("objects",([
//                    __DIR__"npc/xiannpc" : 1,
                    __DIR__"npc/monpc" : 1,
                 ]));
    setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(30) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIW "\n\n�㱻�����ö������á�\n\n" NOR);
 ob->start_busy(3);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
}
