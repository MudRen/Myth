// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/wufeng.c

inherit ROOM;

void create ()
{
  set ("short", "���¥");
  set ("long", @LONG

¥����������Ϊ���������ɫ����̬��������������������
¥�ϴ���˿��֮�����������ƣ����ռ�Ϊ����ޱȡ�����ͨ����
�ǵ����ͨ��̳����

LONG);

  set("exits", ([
        "north"        : __DIR__"jinluan",
        "south"        : __DIR__"tan",
      ]));
  set("objects",([
        __DIR__"npc/girl"     : 5,
      ]));

  setup();
}

