// yashi.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "��������¥");
  set ("long", @LONG

���뱦���ĵ��޹��������Ĵ�Ʈɢ�ŵ����Ļ��㣬������
���б��������˯���޹��м���һ��������(bed)��
LONG);

set("item_desc",(["bed":"һ��������������̶��ɵĴ�(gosleep,gobed,bed)�� \n", ]));
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"moon5",
]));

create_door("east", "��������", "west", DOOR_CLOSED);
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
        message_vision(HIY "$N�ƿ�˿�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move(__DIR__"bed_qingong");
            message_vision(HIY "\n˿������һ����$N���˽�����\n" NOR, me);
                return 1;
}

