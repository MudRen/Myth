//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�Է�");
  set ("long", @LONG

һ�䵭����ɫ�ķ���, ���������, ��������������Ӱ˵��飬�Ժ���һ
�濪��һ����, ��ǰ����һ�������٣�ǽ����һ������ɫ�����(bed)�
�
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "һ������ɫ����齣������ܵ�����Ҷ�񣬿���ȥ��Ϊ����(gosleep,gobed,bed)�� 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"rain",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
                return 1;
}


