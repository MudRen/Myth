// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����Ī���ɽ����������ǰ�����������ವ�Ϫˮ�����
������������̦�º����٣�������д���������֣���ͷɽ����
����

LONG);

  set("exits", ([
        "north"   : __DIR__"qiandong",
        "southeast"   : __DIR__"dongwai",
      ]));
  set("outdoors", __DIR__);
  set("objects", ([
        __DIR__"npc/yao"  : 3,
      ]));

  setup();
}



