//Cracked by Roath
// Room: /moon/xiaolu3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

С·�쳣���С�ʱ�����ϸ�ɽ��ʱ�������ȡ�һ·������
ϡ�٣�ֻ��һЩ���㾪��ķ������ޡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  //"east" : "/d/changan/broadway1",
  "southwest" : "/d/westway/jincheng",
  "northwest" : __DIR__"xiaolu2",
]));
  set("outdoors", 1);

  setup();
}






