// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/tangchi.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ɢ�������ڵ������������в��̵�ζ�������ܵ�ʯǽ�ѱ�
Ѭ���е㷢�ڣ�ǽ�Ǽ���һ�Ŵ�������������ľ���ӹ������½�
�����������һЩë�߸�ԡ��

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi2",
      ]));

  set("objects", ([ 
        __DIR__"obj/yujin" : 1,
      ]));

  setup();
}

