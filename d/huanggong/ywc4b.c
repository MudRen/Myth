// Room: /d/huanggong/ywc4b
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
    "west" : __DIR__"ywc4a.c",
    "east" : __DIR__"ywc4c.c",
    "north" : __DIR__"ywc3b",
    "south" : __DIR__"ywc5b",
  ]));
  set("objects",([
    __DIR__"npc/wu41":1,
  ]));
  set("outdoors", "/d/huanggong");

  setup();
}
