//����������
//by junhyun@SK

#include <ansi.h>
inherit ROOM;
void create()
{
set ("short","����������");
set ("long",@LONG

��ɽ��ѩ�ڻ���۵���ˮ�����϶��ѩ�����������[����
������]��˵��ԡ�����ˮ�У�������ҽ���˲������ܷ���
��ͯ��

LONG);

        set("objects", ([ /* sizeof() == 1 */ 
        "/d/moon/obj/xuelian" : 2, 
      ])); 


set("exits",([
"west" : __DIR__"moon5",
]));

set("chat_room",1);
set("no_clean_up", 1);
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
HIW"�㱻���浭��ˮ���Χ�š���\n"NOR,
HIW"�㽫��ˮ�������������ϡ���\n"NOR,
HIW"������һ����ˮ�������ϡ���\n"NOR,
HIW"������������Լ��ı۰򡭡�\n"NOR,
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
message_vision(HIW"һ��ѩ��������У��������ڻ��ˣ�$Nһ���泩�ĸо�����\n"NOR, who);
write(WHT"�㷢���Լ��������ƺ��ָ��ˡ�\n"NOR);
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
message_vision(HIW"���ϴ���"NOR+HIG"���뱦��"NOR+HIW"һ�����ȣ������ʲô�����¹���������Ұ�ĵط�����\n"NOR,who);
return 1;
}

