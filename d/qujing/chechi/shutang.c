// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shutang.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����м���һ��������������̯���ľ��顣ǽ�����м���������
�ֻ���������������������ܷ����˲���ձ��Բ���ţ���������
���������ϸ���Զ����һ�����ż�������ͭ�����롣

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi6",
      ]));
  set("objects", ([
        __DIR__"npc/shulao"   : 1,
      ]));

  setup();
}

