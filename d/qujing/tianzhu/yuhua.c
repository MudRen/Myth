// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

����԰����������ǽ��԰���д�С���ƻ�̳�������������ź�
�����滨��ݣ�ɢ����Ũ��������ζ����԰���ϱ��ǽ��ǵ꣬
����Ϊ����ͤ�󣬱�����һ�Ź��

LONG);

  set("exits", ([
        "east"   : __DIR__"feng",
        "west"   : __DIR__"long",
        "south"   : __DIR__"jinluan",
        "north"   : __DIR__"hou3",
      ]));
  set("objects", ([
        __DIR__"npc/girl"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


