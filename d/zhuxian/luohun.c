#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIW "�����" NOR);   
  set ("long", @LONG   
ʫԻ������ֽҡ��������������͸��ӯ���������������壬������������㡣��
�˱����ţ����������в������������۶��ɣ����а�ֽһ�ף��ϻ���ӡ����������
���ڣ����չ����������ɢ����̶��𣬲������ɣ���������
LONG);

    set("exits", ([ 
               "north" : __DIR__"lie",
               "west" : __DIR__"hanbing",
               "south" : __DIR__"hongshui",
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
 tell_object(this_object(), HIW "\n\n���а��չ��������Ȼ�е�겻�����ˡ�\n\n" NOR);
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
