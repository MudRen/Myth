// sanjie tianyifood.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������������ڣ���һ���ֵ�ʿ��������һ��ķ�ʳ�����
����ˣ�������������ԵĶ���������ӡ��Ǹ����Ӻ���
��������Ү����
LONG);

  set("exits", ([
  "south" : __DIR__"tianyilang4",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bowl" : "�����Ǹո����Ĺ��⣬��Ҫ����Ҳ������Щȥ�ԡ�",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoyuanzi" : 1,
  "/d/sanjie/obj/shuibei" :1,
]));
  set("clean_up", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
int valid_leave()
{
        if((present("gou rou", this_player())))
            return notify_fail("���깷������������ʦ��֪���˿ɲ����ˡ�\n");
	if((present("shui bei", this_player())))
	    return notify_fail("�㲻�ܰ�ˮ��Ҳ���ߣ��������˱�����ʲô��ˮ��\n");
    return ::valid_leave();
}

