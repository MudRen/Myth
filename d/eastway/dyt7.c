// create by snowcat.c 4/20/1997
// room: /d/eastway/dyt7.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

�������ڽṹ����������ڲ��þ������������徲����
֮�С����ܿ����贰��������¥��ֱͨ���¡������ƺ���
��ͬѰ���ĳ�����

LONG);

  set("exits", ([
        "down"    : __DIR__"dyt6",
      ]));

        set("objects", 
        ([ //sizeof() == 1
     "/d/quest/longzhu/npc/leping" : 1,
        ]));
  setup();
}






