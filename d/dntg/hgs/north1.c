// Room: /d/4world/north1.c
inherit ROOM;

void create ()
{
  set ("short", "���ҽ�");
  set ("long", @LONG

���ǰ�����������һ���֣��������������еĸ����̼Ҷ����
�ˣ���ׯ�̺ţ����ݿ�ջ���ϡ��ϱ��ǳ����ģ�ż������۹���
�������ǳ����������Ĵ���¥��Ʈ������ζ�������˴�����ˮ��
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"north2",
  "south" : __DIR__"center.c",
  "east" : __DIR__"cuixiang.c",
]));
  set("outdoors", __DIR__"");

  setup();
}
