#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIR "��" HIY "ɰ��" NOR);   
  set ("long", @LONG   
ʫ�ƣ�����ɰһ����������¯��������������Ϊһ������֪�ؽ��к��ɡ���
��ɳ����ʮ��֮�ף������������ڰ���������磬�з��������ڲغ�ɰ���������ƺ�ɰ��
�������У��ϲ�֪�죬�²�֪�أ��в�֪�ˣ������ɳ�����󣬷����˴�����ɰ���ˣ�
���̺��Ǿ�;��촷ۣ��������ɷ�����ˣ��ٲ����ӡ�
LONG);

    set("exits", ([ 
               "south" : __DIR__"huaxue",
               "north" : __DIR__"gate",
                 ]));
  set("objects", ([ 
  __DIR__"npc/guard" : 2,
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
 tell_object(this_object(), HIR "\n\n�����ɰ���㴵����\n\n" NOR);
 ob->receive_damage("kee", random(100)+100);
 ob->receive_damage("sen", random(100)+100);
 COMBAT_D->report_status(ob);
 COMBAT_D->report_sen_status(ob);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
int valid_leave(object me, string dir)
{
        object a;
        if (dir == "north") {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
                return
notify_fail("���˰ɣ�����������������ȥ�ġ�\n");
        }
        return 1;
}
