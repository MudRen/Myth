// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "���Ͻ�");
  set ("long", @LONG

���Ϲ������Ĵ�����ɸ���ɽ����������ʯ�̳ɣ���ͨ����������
����ͨ�����Ϲ��ı��������ţ�����ͨ�����Ϲ��ĳ����ģ�������
���ǻʹ����ڵء�

LONG);

  set("exits", ([ 
    "north" : __DIR__"zhuzi1",
    "south" : __DIR__"jiekou",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
