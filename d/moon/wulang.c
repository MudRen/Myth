//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�㺮������");
  set ("long", @LONG

������Ļ���������ܣ�˵�����ǹ�ҡ�컧���̵أ�ѩ����������������
�ʻ��������ݷҷ������Ǹ������ڡ��������ӽ��Ǻ������ѣ�����Ʈ��
�������������������¡����������¹�����ѱ�֮����ƽ��Ҳ�������賡
����
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/fairy.c" : 1,
   "/obj/zhangmen/moon.c" : 1,
  __DIR__"npc/fairy1.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"backyard.c",
  "north" : __DIR__"junkroom.c",
  "west" : __DIR__"ghg_zhengdian.c",
]));

  setup();
}
