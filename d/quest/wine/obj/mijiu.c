// by kuku@sjsh 2002/12
// mijiu.c �׾�

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(WHT "�׾�" NOR, ({"mi jiu", "jiu"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���׾ơ�\n");
    set("value", 0);
   }
  setup();
}

void init()
{
    object me = this_object();
    object who = this_player();
    object where = environment();
   if (!wizardp(this_player())) {
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
    set("no_put",1);
    }         
    if (! me->query("my_owner") && interactive (who))
    me->set("my_owner",who->query("id"));
     if (userp(where))
     {
        if (me->query("owned"))
        {
            if (me->query("owned")!=where->query("id"))
            {call_out("destruct_me",1,where,me);}
        }
        else
        {
           me->set("owned",where->query("id"));
         }
     }
}

void destruct_me(object where, object me)
{
    message_vision("ǧ��ֹ�����������$n���ž���,��׷!\n",where,me);
    destruct (me);
}
