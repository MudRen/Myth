// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����ƻ�ͨ����������ľ����������ſ������Ŵ��м������
�����Σ�������һ�ػ����硣������������������ͨ������
���ҡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie6",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));

  setup();
}



