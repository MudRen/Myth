// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/eastriver2.c

inherit ROOM;

void create ()
{
  set ("short", "��ĸ�Ӷ���");
  set ("long", @LONG

��ĸ���������ԵñȽ�����һ�㡣����Ͽ�ˮ��ƽ������
�԰�������Ů��ԶԶ�ؿ��Կ���һ�������ˡ�

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eastriver3",
  "north" : __DIR__"eastriver1",
]));
  set("outdoors", __DIR__"");

  setup();
}
