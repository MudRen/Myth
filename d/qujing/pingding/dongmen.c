// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������ɽ��������ɽ��֮����һʯ�����ţ�һͷͨ���⣬
��һͷ�ڶ�������ߴ����ߴ��м�����С��ͬ��ͨ�����ֱ�
�򶴵�����ش���

LONG);

  set("exits", ([
        "northwest"   : __DIR__"dongwai",
        "northeast"   : __DIR__"beidong",
        "south"   : __DIR__"nandong",
        "east"   : __DIR__"qianting",
      ]));
  set("objects", ([
        __DIR__"npc/hu"   : 1,
        __DIR__"npc/long"   : 1,
      ]));

  setup();
}



