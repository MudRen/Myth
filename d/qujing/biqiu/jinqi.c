// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����һ��רӪ�����Ľ����꣬�ڱ����ʮ�����������ڸ��ֽ�
�����ͭ��������Ŀ������ˣ�ͬʱҲ��������������������
����Ŷ���

LONG);

  set("exits", ([
        "northwest"    : __DIR__"jie9",
      ]));
  set("objects", ([
        __DIR__"npc/lasulusi"    : 1,
      ]));
  setup();
}

