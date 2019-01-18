// Room: /u/mes/cave2.c

inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG
      
���Ǿ��µ���һ�档�����������󾫵��������ˡ�
LONG);
  set("exits", ([ /* sizeof() == 1 */
		 "west" : __DIR__"gongshi",
		 ]));
  set("outdoors", 0);
  set("no_clean_up", 0);
  
  setup();
}
void init()
{
  add_action("do_leap", "leap");
  add_action("do_leap", "jump");
  add_action("do_leap", "tiao");
  add_action("do_push", "push");
  add_action("do_push", "tui");
}
int do_leap()
{
  object me, corpse;
  int mydodge,mykar,factor,mypot,mylp,mynewpot;

  me=this_player();
  mydodge=(int)me->query_skill("dodge");
  mykar=(int)me->query_kar();
  factor=mydodge+mykar*4;
  if ( random(factor) < random(mydodge) )
    {
      message_vision("$Nһ��ûվ�ȣ����¾��£�������ǣ�����ȥ�ˣ�\n", me);
      me->delete_temp("last_damage_from");
      me->set_temp("death_msg", "ˤ���ˡ�\n");
      me->die();
      me->save();
      corpse=present("corpse");
      if (corpse) destruct(corpse);
      return 1;
    }
  else
    {
      message_vision("$N�ڿ�������������ȥ�ˡ�\n", me);
      me->move(__DIR__"cave1");
      return 1;
    }
}
