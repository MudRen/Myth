// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

����������ǧ�����Ʒ��������ֻ������ܰ���ש�����ߣ�����
��ǽ�Ͻ�������������裬�����ǽ����������������Ա�ֱ��ſ�
��Ȼ������

LONG);
  set("exits", ([ 
    "north" : __DIR__"qian",
    "west" : __DIR__"yuhua",
    "east" : __DIR__"neiyuan",
    "south" : __DIR__"zhaoyang",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 2,
    __DIR__"npc/girl" : 2,
  ]));

  setup();
}

