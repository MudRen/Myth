//Cracked by Roath
// Room: /moon/kunlun.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����ɽ��");
  set ("long", @LONG

��ã���أ�����ǧ�������ȥ������νǧ����⣬����ѩƮ���������
���ƣ���������������Ů�塣��˵����ĸ����������Ů���������
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/xueshan/xueshan1",
  "southeast" : __DIR__"xiaolu1",
  "west" : __DIR__"yunu1",
]));

  setup();
}






