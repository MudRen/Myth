// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ���ϳ��Ź������٣�·�Ͽ�֦��Ҷ��أ��±߸߸ߵ͵ͳ���
��ľ��ݣ�������һЩ���СС����ʯ���������������ʱ
�ɼ�������Ѩ��

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanpo8",
        "southwest"   : __DIR__"shanpo12",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  add_action ("do_enter", "enter");
}

int do_enter ()
{
  object who = this_player();
  string location = "/d/qujing/maoying/tuxue1";

  location[strlen(location)-1] = '1'+random(3);

  message_vision ("$N�����ʯ���аǿ�һ���������˽�ȥ��\n",who);
  who->move(location);
  return 1;
}


