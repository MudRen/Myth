// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

������λ�ڳǶ����д�С��ջҩ����ݣ������������ӡ�Ҳ��һЩ
Զ��������·���ڽ���Ѱ����Ϣס����żȻ�ɼ�����ͣ��·�ߡ�
���ϱ߿��Լ���һ�ҹ��ҵĻ�ݣ���������ǲȥ���������ݡ�

LONG);

  set("exits", ([ 
    "west" : __DIR__"tian1",
    "east" : __DIR__"tian3",
    "north" : __DIR__"douxi",
    "south" : __DIR__"huitong",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
