// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "�跿");
  set ("long", @LONG

�跿��¹���������һ�������ǽ���ţ��������һЩ�����
յ���̲��֮��Ĳ�߲�㡣һ˫����ͨ������ĵ��ã�����
��һƫ��ͨ��������ϱ���һ�ͷ���

LONG);

  set("exits", ([
        "west"    : __DIR__"zheng",
        "northeast"    : __DIR__"chu",
        "south"    : __DIR__"ke",
      ]));
  set("objects", ([
        __DIR__"obj/tea"    : 2,
        __DIR__"npc/xiaotong"    : 1,
      ]));
  setup();
}

