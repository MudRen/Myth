// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��Ƥͤ");
  set ("long", @LONG

��Ƥͤ��������ɭ��ͤ���Ĵ��������������ͤ�Ϲ��Ÿ�ʽ��С��
һ����Ƥ��ͷ���м����һ��꨽�Ľ��Ρ�������һЩ��������
�ֱ�������վ����

LONG);

  set("exits", ([ 
    "west" : __DIR__"dongnei",
    "northwest" : __DIR__"piangong",
  ]));
  set("objects", ([
    __DIR__"npc/nanyao" : 2,
    __DIR__"npc/yaowang" : 1,
  ]));
  setup();
}
