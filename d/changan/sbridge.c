// Room: /changan/sbridge.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ����");
  set ("long", @LONG

�Ѿ�������ˮ���ϡ�������һ��������ֱ�Ĺٵ�������ݵ�
��ʮ���ۡ������������Ρ�룬���Ǵ��ƹ��������ǡ���
������������֮�������С����ݻ��ƽ�����ˮ�Ƴ�����֮�ơ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"broadway1",
  "north" : __DIR__"bridge",
]));

  setup();
}






