// Room: /changan/southgate.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "�ϳ���");
  set ("long", @LONG

���Ž��ա�������һ�Ű����ʾ�����飺
���������ݱ����ա�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nbridge",
]));

  setup();
}






