
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;
int effect();

void create()
{
        set_name("��̳", ({"jiu tan", "jiutan", "tan"}));
        set_weight(50000);
        set("no_get","��̳�������̫���ˡ�\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("max_liquid", 500);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": YEL"�ɾ�"NOR,
                "remaining": 50,
                "drunk_apply": 5,
                "drink_func":(:effect:),
        ]));
}
int effect() {
  object me=this_player();
  int max=(int)me->query("max_force")*2;
  this_player()->apply_condition("drunk",
     (int)this_player()->query_condition("drunk")+5);
  message_vision(HIG"$N�е�������������������ԴԴ������\n"NOR,me);
  
  me->add("force",100+random(100));
  if (me->query("force")>max) me->set("force",max);

  return 1;
}



