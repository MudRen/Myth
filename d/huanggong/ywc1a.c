// Room: /d/huanggong/ywc1a
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
    "east" : __DIR__"ywc1b.c",
  ]));
  set("objects",([
    __DIR__"npc/wu12":1,
  ]));
  set("outdoors", "/d/huanggong");

  setup();
}
