inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��̶���");
        set("long", HIG @LONG  
ǰ��������̶����ȥǰ����˼���������ֹ���������ü�����Ҫ
��ͷ�������back�������棬��һ�����µ�ͨ���������ƺ��൱�
LONG);

        set("exits", ([ 
              "north" : "/d/quest/tulong/dragoncave",               "westdown" : "/d/quest/tulong/spirit7",            ]));

        setup();
}

void init()
{
        add_action("do_back", "back");
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$N����Ӱ��ʧ��һ���â�С�\n"NOR,me); 
        me->set_temp("mark/diary", 0);
        me->set_temp("m_success/����",0);  
        me->set_temp("m_success/��Ӱ",0);  
        me->set_temp("m_success/����",0);  
        me->move("/d/city/enter");
        return 1;
}


