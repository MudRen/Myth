// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����¥��Ϊ���ɫ�����ڵ���ǽ���о޴������ש����Ϸ�飬
¥������ĵ������Ű���ɫ�Ļ�ʯ������������һ��������
�廨��̺��

LONG);

  set("exits", ([
        "east"   : __DIR__"yuhua",
        "north"   : __DIR__"hou2",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


