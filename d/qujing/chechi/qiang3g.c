// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiang3g.c

inherit ROOM;

void create ()
{
  set ("short", "��ǽ");
  set ("long", @LONG

�ߴ�ĳ�ǽ�������ɶ�ߣ��ɻ��Ҽл������ɡ���ǽ�ϰ߲߰�����������
�Ѿ���Щ����ˣ����ų�����ǽ����һ����ʵ����ʯ·�����������߳���

LONG);

  set("outdoors", "/d/qujing/chechi");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dongmen",
  "north" : __DIR__"qiang2g",
]));

  setup();
}
