// Room: /u/mimi/zhuziguo/eaststreet  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "��Ԫ��");
  set ("long", @LONG

��Ԫ�����ڼ��������һ���֡������������ò����֡�������һ
�Ҳ�ݣ��ϱ���һ��ˮ���ꡣ
LONG);

  set("exits", ([ /* sizeof() == 3 */
      "west" : __DIR__"estreet2.c",
    "south" : __DIR__"fruit.c",
    "east" : __DIR__"eastgate",
  ]));
  set("objects", ([
      __DIR__"npc/people" : 3,
  ]));
  set("outdoors", __DIR__"");

  setup();
}

