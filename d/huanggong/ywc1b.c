// Room: /d/huanggong/ywc1b
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
    "west" : __DIR__"ywc1a.c",
    "east" : __DIR__"ywc1c.c",
    "south" : __DIR__"ywc2b",
  ]));
  set("objects",([
    __DIR__"npc/wu11":1,
  ]));
  set("outdoors", "/d/huanggong");

  setup();
}
