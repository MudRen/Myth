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
        "up"   : __DIR__"shanjian",
      ]));
  set("objects", ([
        __DIR__"npc/niujiao"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  object who = this_player();
        
  message_vision ("$N��������ţ�����һ������\n",who);
  who->move(__DIR__"jian2");
  return 1;
}

