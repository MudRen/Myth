//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��ɽ֮��");
        set ("long", @LONG

�����ǻ�ɽ���֮�������¿�ȥ�����ɴ�أ�����ɽ�;����۵ף�
��������ʤ�գ����������п�ʯͷ�Ƚ�����----�ָ��ִ�����
�������и����ڡ���˵����ѹ����ʥĸ��������ҵ��񸫲���
����pi����ʯͷ�ȳ�������
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "southdown" : __DIR__"shanlu7",
        ]));

        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_pi", "pi");
}

int do_pi(string arg)
{       
        object me=this_player();
        object axe;

        if(!(axe=present("shen fu", me)))
        return notify_fail("��û"+HIR"��"NOR+"��ô��ɽ�� \n");

        if (me->query("bld/done") ==1)
        return notify_fail("��������ɽ��ɽ������ٻ��ˣ� \n");
     
        if (me->query("bld/erlang") !=1 || me->query("bld/dog") !=1)
        return notify_fail("û�ط����ˣ��Ա���ȥ�� \n");
        
        if (arg!= "stone")
        return notify_fail("��Ҫ��ʲô�� \n");

        message_vision(HIR"��"NOR+"����һ����⳯��ʯ��ȥ�� \n",me);
        message_vision("ֻ�������䡱��һ����"+HIR"��"NOR+"û��ʯͷ��ʯͷҲ�ֿ��ˣ�¶����һ�����������˽�ȥ�� \n",me);
        message_vision("��ս�ȥ�����ǡ��䡱��һ����ʯͷ�ָ�ԭ�ˣ� \n",me);
        me->set("bld/pi",1);
        destruct(present("shen fu", me));
me->move("/d/quest/bld/shandong");
        return 1;
}

