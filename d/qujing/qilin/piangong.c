// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "ƫ��");
  set ("long", @LONG

ƫ����������գ�������������ô����ϱ���һͨ������
�ڴ��������ϱ���һ����ͨ����Ƥͤ����������������һ��������
���µĴ��ã������߿ɼ�һ����š�

LONG);

  set("exits", ([ 
    "west" : __DIR__"dinglu",
    "northeast" : __DIR__"hougong",
    "southeast" : __DIR__"bopi",
  ]));
  set("objects", ([
    __DIR__"npc/nuyao" : 3,
  ]));
  setup();
}
