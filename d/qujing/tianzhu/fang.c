// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������������ϱ���һ������������һľ�ƾ��������Ϸ�
�ž���ľ��ľ��֮�ࡣ������һС���������ϼ���ľ��ľ�ʡ�
������һ��ͨ�򱦵��¡�

LONG);

  set("exits", ([
        "east"   : __DIR__"baodian",
      ]));
  set("objects", ([
        __DIR__"npc/fang"   : 1,
      ]));

  setup();
}


