// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

��·������խ��ɽɫãã�������죬���Ϸ�����۷����ռ�أ���
ס��ǣ���ͷ��������·������ʯ���׸��ʣ���������ңң������
�Ϲ��ǳء�

LONG);

  set("exits", ([ 
    "southeast" : __DIR__"polu4",
    "westdown" : __DIR__"polu2",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
