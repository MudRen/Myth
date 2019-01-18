//restroom.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "ɽ�º�");
	set ("long", @LONG

��ѩɽ�Ṧ�ھ����¡�����ʦ��Ϊ���õ��ӿ̿���ϰ
�Ṧ�����������ܵ��ž����رգ�������ƾ�Ƿ��Ṧ
�ſɷ�Ծ���ȣ�ȴ��֪�ĸ���͵����ͽ������˩����
����(rope)���ٺ٣������нݾ��ˡ�
LONG);

	set("item_desc", (["rope" : 
"һ�����������Ӳ�֪ͨ�������������(climb)���ԡ�\n", 
                         ]));

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"shanpo",
		"north" : __DIR__"xuejie-3",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();

}


void init()
{
        add_action("do_climb", "climb");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move("/d/gao/bed_yashi");
            message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
                return 1;
}

int do_climb(string arg)
{
   object me=this_player();
   if(!arg || arg != "rope") return notify_fail("��ʲô��\n");

   message_vision(HIY "$N����Χû��ע�⣬˳������������ȥ��\n\n" NOR, me);
   me->move(__DIR__"xueshan2");
   message_vision(HIY "\nֻ��$N��֪���Ļ���������\n" NOR, me);

   return 1;

}

