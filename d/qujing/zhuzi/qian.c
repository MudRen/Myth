// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "ǰ��");
  set ("long", @LONG

ǰ��Ϊʮ���������������н����ʷ�����Ϲ������壬����
����������������ϲ������������ɫ���ƶ�����ƣ���������
����ǧ����

LONG);
  set("exits", ([ 
    "north" : __DIR__"gongmen",
    "southwest" : __DIR__"yuhua",
    "south" : __DIR__"zheng",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 2,
    __DIR__"npc/girl" : 2,
  ]));

  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "north")
    return 0;
  return ::valid_leave(who, dir);
}
