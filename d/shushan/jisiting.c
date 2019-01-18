// modified by vikee 2000.11
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;
#include <ansi.h>
string chinese_daoxing(int gain);
void create()
{
set("short","������");
        set("long", @LONG
      ������ɽ���ɼ���ĵط������м�ֻ��һ����¯��������Ŷമ���顣
¯ǰ�м����������湩�����������ʳ������򣬹�����ɽ�������ȡ������
�շ������֣��������ǰ����(jibai)���������ȱ�����õ����ɡ�
LONG
        );
        set("item_desc", ([
                "����¯": @TEXT
�����Ը��͵���ħ��¯���͵���ħ���������棬����һ��ʱ�����ͻᾡʧ���У�
����������ﻯ����ֻҪ������(putin)���Ϳ�������
TEXT        ]));
        set("exits", ([
                "south" : __DIR__"houdian",
        ]));
        set("objects", ([
                "/d/shushan/npc/laodao" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_jibai", "jibai");
}

int do_jibai(string arg)
{
        object room, ob;
        object me = this_player();
        message_vision("$N������������ɽ���ȼ��ݡ�\n",me);
        if((int)me->query("shushan/reward") > 0){
        tell_object(me,HIW"��Ϊ��ĳ��ĺͻ��£���ʦү������"+ chinese_daoxing((int)me->query("shushan/reward",1) * 3)+"���к�"
        +chinese_number((int)me->query("shushan/reward",1))+"��Ǳ�ܣ�\n���ʱ�������г�ʵ����࣡\n"NOR);
        me->add("daoxing",(int)me->query("shushan/reward",1) * 3);
        me->add("potential",(int)me->query("shushan/reward",1));
        me->add("shushan/reward_got",(int)me->query("shushan/reward",1));
        me->set("shushan/reward",0);
        }
        else tell_object(me,HIY"ֻҪ������ƻ��£���ʦүһ���ά���㡣\n"NOR);
        return 1;
}                

string chinese_daoxing(int gain)
{
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"��";
             if(day) str=str+chinese_number(day)+"��";
             if(hour) str=str+chinese_number(hour)+"ʱ��";

             return str;
}
