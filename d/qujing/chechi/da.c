// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/da.c

inherit ROOM;

void create ()
{
  set ("short", "���ฮ");
  set ("long", @LONG

���ฮ����ԫʯ���ɡ���������߹ң����ڿ����������ûʡ�
һ����֪�ǳ�͢���˵�סլ�����������Ȱ�ͭ���Ž��գ������
ͨ���ฮ����Ժ��

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi3",
      ]));
  set("objects", ([
        __DIR__"npc/daguan"  : 1,
      ]));

  setup();
}

