// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "˧����");
  set ("long", @LONG

˧�����������������������ǽ�Ϲ���������ͷ�޹ǣ������̿���
Ƥ��Ƥ���м�һ��ʯ��������������һ�������޴������Ϸ�����һ
����ͨ��¯����

LONG);

  set("exits", ([ 
    "southeast" : __DIR__"dinglu",
  ]));
  set("objects", ([
    __DIR__"npc/nanyao" : 2,
  ]));
  setup();
}
