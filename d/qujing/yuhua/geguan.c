// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�����Ǵ˵������ĸ�ݣ����ſ�����һ�����ң�����������
���������������̨�ߴ�������ϡ���ʱ�и�Ů������ʲô
������

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie3",
      ]));
  set("objects", ([
        __DIR__"npc/genu"  : 1,
      ]));

  setup();
}



