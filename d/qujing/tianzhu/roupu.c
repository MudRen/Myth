// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�������������һ����ľ����������һ����塣���Ӻ�����
��ľ�裬�������Ǵ��������⡣����һ�߹���һֻ��ͷ
һ�߹���һֻţͷ��

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao75",
      ]));
  set("objects", ([
        __DIR__"npc/qiao"   : 1,
      ]));

  setup();
}


