// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С���Ӹ�");
  set ("long", @LONG

С���Ӹ������Ž��ɫ�ĵ��������ߵ�ǽ�߷���һ�����¯��
¯���������ơ�������һ����ľ������������һЩ���飬����
һ����ʯ��̨��

LONG);

  set("exits", ([
        "west"   : __DIR__"er",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince3"  : 1,
      ]));

  setup();
}



