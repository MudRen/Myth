// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

����ʮ�ֿ�������ʯ��ϼ���������������������ݣ�ǰ���ǹŰ�
���ɣ�������ȼ��յյ���͵ƣ���Ѭ���ǡ�����վ��Щ��С����ɭ
ɭ���С�

LONG);

  set("exits", ([ 
    "east" : __DIR__"bopi",
    "southwest" : __DIR__"dongkou",
    "northwest" : __DIR__"dinglu",
    "northeast" : __DIR__"piangong",
  ]));
  set("objects", ([
    __DIR__"npc/nanyao" : 6,
  ]));
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "southwest")
    return 0;
  return ::valid_leave(who,dir);
}
