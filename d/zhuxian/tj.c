#include <ansi.h>
#include <room.h>

inherit ROOM;                                                        

void create ()                                                       
{
  set ("short", HIB "�����" NOR);   
  set ("long", @LONG   
�������ߵ��ƣ�����������Ѳ£�����������������֫�廯�ɻҡ�
����������ڣ�������֮���������ҳ����ɵ�����˴���֫����Ϊ���顣
LONG);

    set("exits", ([ 
               "north" : __DIR__"dilie",
               "east" : __DIR__"fenghou",
]));
    set("objects",([
        __DIR__"npc/xiannpc" : 1,
       ]));
    setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(10) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIR "\n\nһ�����������������һ��ѣ�Ρ�\n\n" NOR);
 COMBAT_D->report_sen_status(ob,1);
 ob->receive_damage("sen", random(50)+50);
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
