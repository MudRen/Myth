inherit ROOM;

void create ()
{
  set ("short", "ƽ����·");
  set ("long", @LONG

������һ����ֱ�Ĵ�·���Ϸ�����������һƬ�������������
�����ཻ�Ĺ���š�����ȴ���������֣��������󱯸������
�ǣ���������ȴ������֮��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"guidaomen",
  "north" : __DIR__"bidouya",
]));
  set("hell", 1);

  setup();
}
