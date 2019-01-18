
#include <ansi.h>

inherit ITEM;
void self_destruct() {
  object target=query("target");
  if (target && (!userp(target)))
    target->set("chat_chance_combat",target->query_temp("chat_chance_combat"));
  destruct(this_object());
}

void create()
{
     set_name("����",({"qing wang"}));     
     set("env/invisibility",1);
     set_weight(10000000);
     set("no_get",1);
     seteuid(getuid());
     if( clonep() )
                set_default_object(__FILE__);
     else {
           set("unit", "��");
           set("no_sell", 1);
           set("no_get",1);
           set("no_give",1);
           set("no_drop",1);
           set("expired",0);
     }    
     setup();

}

void init() {
   object target=query("target");
   if (!target) return;
   if (this_player()==query("target")) 
     add_action("do_cast",({"surrender","cast","perform","exert"}));
   if (time()>query("time_expired") || (!present(target,environment(this_object()))))
     self_destruct();
}


int do_cast() {
    object me=this_player();
    object who=query("owner");
    object weapon=query("weapon");

    if (time()>query("time_expired") || who->query_temp("weapon")!=weapon) {
      self_destruct();
    }    
    write(MAG"����һ�˹�����ǰ���̳�����������Ϥ����Ӱ�������ϣ����ң��������ķ����\n"NOR);
    return 1;
}
