// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����԰");
  set ("long", @LONG

���������ϼ����滨�����԰�������������ޡ�԰����һԲ����ˮ
������С���´���������һ����ͤ���;�����ͤ�ⴹ��ƮȻ������
������

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zheng",
    "northeast" : __DIR__"qian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}


