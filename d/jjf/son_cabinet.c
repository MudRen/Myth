// Room: /d/jjf/son_cabinet.c

inherit ROOM;

void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG
�������ع��ӵ�ס��������ļҽ̼��ϣ��ع�������Ҫ������
����Ҫ���顣��������û�и��ҵ��ݻ���ǽ�Ϲ���һ����װﵣ�
���Ϸ����������飬�����ʶ�ֻ���಼�ġ�
LONG);

  set("outdoors", 0);
  set("if_bed", 1);
  set("sleep_room", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"son_shufang",
  "northwest" : __DIR__"se_garden",
]));

  setup();
}
