// Room: /d/jjf/son_shufang.c

inherit ROOM;

void create ()
{
  set ("short", "�鷿");
  set ("long", @LONG
�ؽ��������Ľ���������ס���������һ�Ŵ��ͼ�������֮
�⣬�������ֻ�м���������ˡ���ϸ����������Ͼ��Ǳ�������
�����顣�����ع�����Ҫ�ӳи�ҵ�ˡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"son_cabinet",
]));

  setup();
}
