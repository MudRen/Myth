// Room: /d/huanggong/ywc3b
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

  set("exits", ([ 
    "west" : __DIR__"ywc3a.c",
    "east" : __DIR__"ywc3c.c",
    "north" : __DIR__"ywc2b",
    "south" : __DIR__"ywc4b",
  ]));
  set("objects",([
    __DIR__"npc/wu31":1,
  ]));
  set("outdoors", "/d/huanggong");

  setup();
}
