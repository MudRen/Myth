// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("����",({"jin nao", "nao"}));
  set_weight(9000000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 100000);
    set("material","gold");
    set("long", "һֻ���ɰѸߵľ޴����\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
} 

void init ()
{
  add_action ("do_out", "out");
}

int do_out ()
{
  object me = this_object ();
  object who = this_player();
  object where = environment (who);
  object room = environment (me);

  if (where != me)
    return 0;

  if (who->query_temp("no_move") ||
      who->is_busy())
  {
    tell_object (who, "���ںڰ���������������������һ��ײ�ڽ����ϡ�\n");
    return 1;
  }
  if (random (10))
  {
    tell_object (who, "���ͷ����һ��ײ�ڽ�����ϡ�\n");
    return 1;
  }
  tell_object (who, "�㽫��������һ���죬������ȥ��\n",who,me);
  if (room->is_character())
    room = environment (room);
  who->move(room);
  message_vision ("���󱻶���������$N��������������˳�����\n",who,me);
  return 1;
}


