#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", RED "��Ѫ��" NOR);   
  set ("long", @LONG   
�Ʒ�����ɳ�ɣ�����޹⶯ɱ�����������Ŵ������丵�Ѫ�����¡�
��������������������з��ף��ڲ�������ɳ���������������촦����ɳ��
Щ���Ŵ�������Ѫˮ��������������������
LONG);

    set("exits", ([ 
               "west" : __DIR__"jinguang",
               "south" : __DIR__"hanbing",
               "east" : __DIR__"lie",
               "north" : __DIR__"hongsha",
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
 tell_object(this_object(), CYN "\n\nһ������ź�ɳ���㴵����\n\n" NOR);
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
