//Cracked by Roath
// Room: /moon/yunu1.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "��Ů���");
  set ("long", @LONG

��������Ů��ס���ͷ��ȥ����ѩ�ķ���̵����۶���������������ʹ��
������ֻ��ͷ����Զ���������ƣ����￴�������
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kunlun",
  "westup" : __DIR__"yunu2",
]));

  setup();
}






