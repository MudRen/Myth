// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ��ɽ���ӽ���������������������ˮ����ɽ����ȥ����һƬ
��ɫ��ľ����ľ�ĺ�����һɽ��������������һ��ƽ��ʯ�ڣ�
������ţ�ƽ��ɽ��������

LONG);

  set("exits", ([
        "northwest"   : __DIR__"ping3",
        "southeast"   : __DIR__"dongmen",
      ]));
  set("objects", ([
    __DIR__"npc/chong"   : 1,
    __DIR__"npc/gui"   : 1,
  ]));
  set("outdoors", __DIR__);

  setup();
}



