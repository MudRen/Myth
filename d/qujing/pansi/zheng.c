// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����Ϊһ���ã�������������������ʥ�����ķ���һ��ľ��
�Ĺ������������޽�ͭ¯һֻ�����������ȼ�̡����õ�����
��������˫���š�

LONG);

  set("exits", ([
        "north"    : __DIR__"yuannei",
        "west"    : __DIR__"pian",
        "east"    : __DIR__"cha",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong"    : 1,
      ]));
  setup();
}

