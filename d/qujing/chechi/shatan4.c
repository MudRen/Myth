// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shatan4.c

inherit ROOM;

void create ()
{
  set ("short", "ɳ̲");
  set ("long", @LONG

�������������ع��ѡ��м���һƬɳ̲�����˲ȳ�һ����·��
·��ѹ�м�����������������ۼ���·������ɢ��һЩ����
��שʯľ�ϡ��������������ع��ѡ�

LONG);

  set("exits", ([
        "east"         : __DIR__"ximen",
        "southwest"    : __DIR__"shatan5",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

