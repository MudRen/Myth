//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/enter.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ֻ�����������ĸ����֣�

                  �ԡԡԡԡԡԡԡԡԡ�
                  �ԡ�            �ԡ�
                  �ԡ�  [1;33m������Ժ[m  �ԡ�
                  �ԡ�            �ԡ�
                  �ԡԡԡԡԡԡԡԡԡ�


LONG);

  set("exits", ([
        "south"    : __DIR__"fzroom",
        "north"  : __DIR__"sleeproom",
        "out"    : __DIR__"shanmen",
      ]));
  set("objects", ([
        __DIR__"npc/monk1" :1,
        __DIR__"npc/monk_gz":1,
        ]));
  setup();

}
