// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ܴ���������������һ��ľ�������Σ�һǶ����ʯ��
�����õĶ�����һ�߸ߵ��ඦ��������һ�ŵ�ľ���ñ�
��ͨ�����⡣

LONG);

  set("exits", ([
        "north"   : __DIR__"fumen",
      ]));
  set("objects", ([
        __DIR__"npc/guan"   : 2,
        __DIR__"npc/fuling"   : 1,
      ]));

  setup();
}


