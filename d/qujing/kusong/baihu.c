//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�׻�̶");
  set ("long", @LONG

̶�е�ˮ��Ө͸����Զ��ǡ��һֻ��ɫ�Ļ�צ��̶��ż���д�
��Ծ��������ƬƬ��ˮ����̶�Ķ�����һ�����£�������Լ��
��һ��С��ɽ����
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wangyue",
]));


  set("outdoors", 1);
  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me = this_player();

message_vision(HIY
"$N����һԾ������̶�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε���̶�Ķ԰���\n" NOR,
me);
        me->move("/d/qujing/kusong/xuanjing");
        message_vision(HIY "ֻ��$N����ʪ�����ش�ˮ������������\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

