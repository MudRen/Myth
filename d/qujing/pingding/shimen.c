// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

ɽ�ҵ����棬��һͻ���ľ�ʯ����������һ�㡣ʯ�ŵ�һ����
�ſ���һ�����֣�����д�ţ�ѹ��ɽѹ������ʯ�ŵĶ��Ϸ���
һ���ͨ�����档

LONG);

  set("exits", ([
        "northeast"   : __DIR__"yalong2",
        "southeast"   : __DIR__"shilang1",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 2,
      ]));

  setup();
}



