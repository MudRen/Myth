// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shatan5.c

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
        "northeast"    : __DIR__"shatan4",
        "southwest"    : "/d/qujing/tongtian/xiaolu3",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

