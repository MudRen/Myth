// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shatan2.c

inherit ROOM;

void create ()
{
  set ("short", "ɳ̲");
  set ("long", @LONG

�������������ع��ѡ��м���һƬɳ̲�����˲ȳ�һ����·��·��ѹ
�м�����������������ۼ���·������ɢ��һЩ���Ƶ�שʯľ�ϡ���
�����������ع��ѡ�
LONG);

  set("outdoors", "/d/qujing/chechi");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shatan1",
  "south" : __DIR__"shatan3",
]));

  setup();
}
