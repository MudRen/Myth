// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ����ʯɽ��ͤ������컨��䣬ͤ����ˮ������ˮ�ߴ���
����������һ�㡣Ժ��һ��ʯ·��������һ����Ժ�ӵı�
��ͨ�����⣬���Ͻ���һ��԰��

LONG);

  set("exits", ([
        "north"   : __DIR__"simen",
        "southwest"   : __DIR__"caiyuan",
        "east"   : __DIR__"daxiong",
      ]));
  set("objects", ([
         __DIR__"npc/tong"   : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}



