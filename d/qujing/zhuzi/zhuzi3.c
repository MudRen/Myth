// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "���Ͻ�");
  set ("long", @LONG

���Ϲ������Ĵ�����ɸ���ɽ����������ʯ�̳ɣ���ͨ����������
�����Ƿ����Ľֿ��뱱ϼ�����������������Ϲ��ĳ����Ĺ�¥����
���Ͽɼ����Ϲ��ʹ���

LONG);

  set("exits", ([ 
    "north" : __DIR__"jiekou",
    "south" : __DIR__"gulou",
    "west" : __DIR__"mianguan",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
