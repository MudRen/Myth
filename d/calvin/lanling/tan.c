// ������ by Calvin

#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","��Ԩ��ˮ̶");
set ("long",@LONG

���������Ԩ��ˮ̶��,����Կ�����ð�Ű�����̶ˮ����ô�Ľྻ,
�������������������ˮ�����е����⸴�湦�ܵĹ�Ч�ˡ�

LONG);

set("exits",([
"west" : __DIR__"tan3",
]));

set("chat_room",1);
set ("no_pk", 1);
set("valid_startroom", 1);
setup();
}

void init()
{
object who=this_player();
if( (string)who->query("gender")=="����" || (string)who->query("gender")=="Ů��" )
// add_action("do_stop", "exert");
// add_action("do_stop", "cast");
// add_action("do_stop", "kill");
// add_action("do_stop", "fight");
// add_action("do_stop", "perform");
add_action("do_stop", "apply");
add_action("do_stop", "sleep");
add_action("do_stop", ({"exercise","cast chunqiao","cast","kill","perform,"}));
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
HIG"һ�󵭵��İ����ӳ��渡��\n"NOR,
"���������������������塣\n"NOR,
HIW"���Ȼ�о��������!\n"NOR,
HIC"����֮������һ������ĸо���\n"NOR,
});

tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}

who->set("eff_gin", (int)who->query("max_gin"));
who->set("eff_kee", (int)who->query("max_kee"));
who->set("eff_sen", (int)who->query("max_sen"));
message_vision(HIW"����~~~~���淺����һ��ˮ��,������һЩ������$N���ϣ�$Nһ����������ࡣ\n"NOR, who);
write(YEL"�㷢���Լ��ƺ�������ˡ�\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
who->delete_temp("rent_paid");//added by stey �������޸ģ�
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIR"���ϴ���"NOR+HIC"����Ů��"NOR+HIR"һ��ŭ������˭��$N�����ⱦ�ص�,�������ҹ���ȥ����\n"NOR,who);
return 1;
}
