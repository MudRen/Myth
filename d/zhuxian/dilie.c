#include <ansi.h>
#include <room.h>

inherit ROOM;                                                        

void create ()
{
  set ("short", HIB "������" NOR);   
  set ("long", @LONG   
���ҳɷ��Ǻ������»�̫���飻��������Ǭ���壬���ӹǻ������㡣
    �в�����֮�壬������Ծ֮��仯��ˣ�����һ�׺죬�ж��л���
    �����ɽ��������޸���֮�������������������Ӵ˶�
LONG);

    set("exits", ([ 
               "south" : __DIR__"tianjue",
               "east" : __DIR__"hanbing",
               "north" : __DIR__"jinguang",
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
 tell_object(this_object(), HIB "\n\n����ͻȻð�������һ�\n\n" NOR);
 ob->receive_damage("kee", random(100)+50);
 COMBAT_D->report_status(ob);
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
