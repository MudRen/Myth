//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������Ũ�ܺ���纣��Զ�紵��������������ӽ�����������һ��
�޼������ɴ��Ʈ�����̲����ϡ�

LONG);

  set("exits", ([
        "west" : __DIR__"yuwang5",
      ]));
  set("no_fight",1);
  set("no_magic",1);
  set("no_mieyao",1); // mon 7/9/99
  set("alternative_die",1);
  set("outdoors", __DIR__);

  setup();
}

void alternative_die(object who)
{
  if (! userp(who) ||
      ! who->query_temp("ymdh/entered") ) {
    set("alternative_die",0);
    who->die();
    set("alternative_die",1);
    return;
  }
  __DIR__"yuwang5"->die(who);
}
void die(object who)
{
    if (! objectp(who)) return;
    alternative_die(who);
}

void init()
{
    // so can't leave immediately. prevent possible
    // another death if move out of this room.
this_player()->delete_temp("last_fainted_from");
    this_player()->start_busy(2);
}

