// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

������ɫ���㣬����һ��������������һ��������齣���
��һ����������������һ���Ӻ�һ�����ӡ����ߵ���ֱͨ����
���

LONG);

  set("exits", ([
        "west"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/tong"   : 3,
      ]));
  set("sleep_room",1);
  set("if_bed",1);

  setup();
}



