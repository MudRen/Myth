// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��ͤ��");
  set ("long", @LONG

����Ŀ�������һ����ʯ��ͤ�ӣ�ͤ���������˸��ָ�������
����ݣ�ɢ�������㡣ͤ����һԲʯ������ֻԲʯ�ʣ���ͤ��
�Ķ������ڹ���

LONG);

  set("exits", ([
        "north"   : __DIR__"dongting",
        "east"   : __DIR__"neigong",
      ]));
  set("objects", ([
        __DIR__"obj/momo"   : 5,
        __DIR__"npc/yao"   : 5,
        __DIR__"npc/xiezi"   : 1,
      ]));

  setup();
}



