// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ·�ƹ�һ����Ȼ�����ɽ����������Ƶ�ƽ��������ʯ�½�
ˮ���ٵس��ߣ�����һƬ�װ׵���������������һ��ɽ������
����һ��ɽ��б�¡�

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shanlu4",
        "northwest"   : __DIR__"dongshan",
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
//  if (dir == "northwest")
//    return notify_fail ("ɽ�����ѽ�ͨ��ɽ����·��û���ܾþ�û���ܹ����ˡ�\n");
  return ::valid_leave(who,dir);
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  string *rooms = ({
    "jian1",
    "jian2",
  });

  object who = this_player();
  
  message_vision ("$N��������ţ�����һ������\n",who);
  who->move(__DIR__+rooms[random(sizeof(rooms))]);
  return 1;
}

