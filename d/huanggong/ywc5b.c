// Room: /d/huanggong/ywc5b
// created by snowcat 10/05/1997

inherit ROOM;

void create ()
{
  set ("short", "���䳡");
  set ("long", @LONG

������������ʯ���ƣ���������һ�˷���̨���м�������ɫ
������ÿ�������������ʿǰ��Ͷ״Ӧ����䣬���ֽ�����
ͭ���������������ÿ�����һ����������Ի��״Ԫ����
���ۡ���̽����

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"ywc5a.c",
    "east" : __DIR__"ywc5c.c",
    "north" : __DIR__"ywc4b",
    "south" : __DIR__"fst",
  ]));
  set("objects",([
    __DIR__"npc/wu51":1,
  ]));
  set("outdoors", "/d/huanggong");

  setup();
}
