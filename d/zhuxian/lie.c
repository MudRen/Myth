#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIR "����" NOR);   
  set ("long", @LONG   
ʫԻ�������˷��п��л�����ɰ¯�ڲأ������빬Ϊ���죬���ж�����������
�ڲ������������𣬿��л�ʯ�л�����Ϊһ�����������׺�,�����ɽ������ڣ�
��չ����������ɣ�����Ϊ�ҽ������бܻ����ԣ��Ѷ��������
LONG);

    set("exits", ([ 
               "west" : __DIR__"huaxue",
               "northeast" : __DIR__"zhuxian",
               "south" : __DIR__"luohun",
                 ]));
    set("objects",([
                   __DIR__"npc/xiannpc" : 1,
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
 tell_object(this_object(), HIR "\n\nһ�������������ϱ�ը��\n\n" NOR);
 ob->receive_damage("kee", random(100)+50);
 ob->receive_damage("sen", random(100)+50);
 COMBAT_D->report_status(ob);
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
