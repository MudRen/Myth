// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ����ǽ���ܵ���¥��������ǰ����¥����һ���ȡ�������
���ʯ��˫���̻������������Ǹ��ֻ�����ʯ��������һ
��ڣ��������ٽ֡�

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie4",
        "south"   : __DIR__"datang",
        "north"   : __DIR__"jitan",
      ]));
  set("objects", ([
        __DIR__"npc/guan"   : 1,
      ]));

  setup();
}


