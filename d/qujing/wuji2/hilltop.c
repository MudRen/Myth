// Room: /u/mimi/zhuziguo/hilltop  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ��ɽ��ʯ�������Ա���һƬϡϡ���������֡��ϱ��Ƕ��͵�����
ֱ�ڣ���·���С��˴�ɽ�߷��䣬�չȻ�����

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
    "northdown" : __DIR__"road5",
  ]));
  set("objects", ([
     __DIR__"npc/prince" : 1,
     __DIR__"npc/siwei" : 2,
  ]));

  set("outdoors", __DIR__"");
  setup();
}

