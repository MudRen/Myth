// yashi.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

��С����Է���������Է��𣮣���Ȼ����Ϣ�ĵط��ˣ���
������һ���ؾ��Ĵ���(bed)�����յ����ز���һ����Ӱ������
LONG);

set("item_desc",(["bed":"˯���õĴ���(gosleep,gobed,bed)�� \n", ]));
set("exits", ([ /* sizeof() == 4 */
"down" : __DIR__"guige",
]));

create_door("down", "������", "up", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
      	message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
  	me->move("/d/gao/bed_yashi");
            message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
         	return 1;
}
