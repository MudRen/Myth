// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhaifang.c

inherit ROOM;

void create ()
{
  set ("short", "ի��");
  set ("long", @LONG

ի��������һ���������֧��һ�ڴ����������������ˮͰ��
һЩ�ɲ�ľ̨�Ϸ���һЩ�ִ��룬���м�ֻľ�ʡ��ϱ���һ��
ͨ��Ժ�ӡ�

LONG);

  set("exits", ([
        "south"         : __DIR__"beiyuan",
      ]));

  set("objects", ([
         __DIR__"obj/rice"    : 1,
         __DIR__"obj/kang"    : 1,
      ]));
  setup();
}

