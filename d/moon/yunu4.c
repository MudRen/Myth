//Cracked by Roath
// Room: /moon/yunu4.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "��Ů��");
  set ("long", @LONG

��ѩ���硣���������û��·������ǿ��סһЩͻ�����ı��飬�����ҳ�
һ��·��������һ�������ɵ�ͷ��Ŀѣ����Ͻ������۾�������һ������
��ˤ�÷�����ǡ�
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"yunu3",
  "westup" : __DIR__"yunu5",
]));

  setup();
}






