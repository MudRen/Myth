// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

������λ�ڳǶ����д�С��ջҩ����ݣ������������ӡ�Ҳ��һЩ
Զ��������·���ڽ���Ѱ����Ϣס����żȻ�ɼ�����ͣ��·�ߡ�
������һ����ջ��

LONG);

  set("exits", ([ 
    "west" : __DIR__"tian2",
    "east" : __DIR__"tian4",
    "north" : __DIR__"mazhan",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
