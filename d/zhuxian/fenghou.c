#include <ansi.h>
#include <room.h>


inherit ROOM;

void create ()
{
  set ("short", HIC "�����" NOR);   
  set ("long", @LONG   
ʫԻ����������б����ѣ��������������죻���˲��������壬��������Ѫ��ࡣ��
�������в��������ˮ���֮�������з�𣬴˷��������֮����������𣬰������
���ж����������ɽ����󣬷�������������ܣ���֫����촷ۣ������е�����ɽ֮������
�������廯��ŧѪ��
LONG);

    set("exits", ([ 
               "west" : __DIR__"tianjue",
               "north" : __DIR__"hanbing",
               "east" : __DIR__"hongshui",
//               "south" : __DIR__"entrance",
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
 tell_object(this_object(), HIC "\n\nһ���紵����������۾����������ˡ�\n\n" NOR);
 ob->receive_damage("sen", random(50)+50);
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
