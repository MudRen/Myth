// Room: /changan/xiaoqiu.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "С����");
  set ("long", @LONG

��ˮ�ӱߵ�һ��С���𣬲�֪����ݳɡ�΢���ӹ������ϴ�
��ɳɳ��������������һСͤ��ͤ�����ҡ�Ʒ��ͤ��������
��д�������˰�Ȼ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"eside2",
  "enter" : __DIR__"pinqiting",
]));
  set("outdoors", 1);

  setup();
}






