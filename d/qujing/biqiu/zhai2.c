// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "լԺ");
  set ("long", @LONG

����������լԺ��ʯ��ǽľդ�ţ�Ժ��������һЩ������ѣ�
�м���һ�ڹ���ʯĥ������ɹ��һЩ��ʳ����ֻ��������Ϸ�
����͵����ʳ��

LONG);

  set("exits", ([
        "north"    : __DIR__"zhai1",
        "west"    : __DIR__"jie7",
      ]));
  set("objects", ([
        __DIR__"obj/elong"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

