// �����ɽ� by Calvin
#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","�����ɽ�");
set ("long",@LONG


           �˼䷳���� ����ֻ����

                         ��į��ն� �ɽ�����ң


LONG);
set("exits",([
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/quest/longzhu/npc/buma" : 1,
        ]));

set("outdoors", 0);
set("no_clean_up", 1);
set("valid_startroom", 1);
setup();
}
void init()
{
object who=this_player();
if( (string)who->query("gender")=="����" || (string)who->query("gender")=="Ů��" )
add_action("do_stop", "exert");
add_action("do_stop", "cast");
add_action("do_stop", "kill");
add_action("do_stop", "fight");
add_action("do_stop", "perform");
add_action("do_stop", "apply");
add_action("do_stop", "sleep");
add_action("do_stop", "exercise");
add_action("do_stop", "meditate");
{
call_out("heal_up", 9, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
string *msgs=({
HIG"��ֻ���������������ǰ�ɹ���\n"NOR,
HIY"Զ��Ʈ�����������Ĳ��ơ�\n"NOR,
HIY"��˿���Ʈ�����������,���������\n"NOR,
HIC"������Ʈ��,����ζ��������\n"NOR,
});
tell_room (where,msgs[random(sizeof(msgs))]);
}
int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}
who->set("eff_gin", (int)who->query("max_gin")*50/100);
who->set("eff_kee", (int)who->query("max_kee")*50/100);
who->set("eff_sen", (int)who->query("max_sen")*50/100);
message_vision(HIW"����ָ��$N˵��:ʲô���$N�������������ɽ�����!\n"NOR, who);
write(YEL"���������ĸ�����,�����ޱ�Ư����\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIR"ԶԶ����"NOR+HIC"����"NOR+HIR"�Ľ���������˭��$N�������ҿ�����̣��,��$N��ȥ��!��\n"NOR,who);
return 1;
}

