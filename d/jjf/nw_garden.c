// Room: /d/jjf/nw_garden.c

inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG
һ��С��԰����Ȼ�Ȳ��ϸ�����Ժ�������ǧ�죬��Ҳ���õ�
���¿��ˡ��ظ�����Ȼ��������֮ʿ���������һ�ʢ�������ճ���
��ɻ����������ջ����ޣ���������һƬ��ѩ����
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"se_garden",
  "south" : __DIR__"sw_garden.c",
  "east" : __DIR__"ne_garden",
  "northwest" : __DIR__"pavillion",
]));

  setup();
}
