// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һƫ���Ķ�ǽ����һ��ľ���ӣ����������ź�ǩ����
��̨����һǩͲ��һľ��һľ颡�����һ��С��¯������δ��
����㡣����ı����Ǵ��۱��

LONG);

  set("exits", ([
        "north"   : __DIR__"daxiong",
      ]));

  set("objects", ([
        __DIR__"npc/tong"   : 3,
    ]));

  setup();
}



