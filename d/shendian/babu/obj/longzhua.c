#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
  set_name(HIB"����"+HIR"֮צ"NOR, ({ HIR"xiuluo zhua"NOR, "zhua" }) );
  init_dagger(25);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
                set("is_monitored", 1);
        set("no_put", 1);
    set("value", 0);
    set("no_get", 1);
    set("no_give", 1);
    set("no_put", 1);
    set("material", "bone");
  }
   set("wield_msg","$N����$n��������о��������޵�������\n");
  setup();
}
int init()
{
        add_action("do_wield","wield");
        add_action("do_unwield", "unwield");
        unique::init();
        return 1;
}
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wield (string arg)
{
  object me = this_player();
  object zhua = this_object();
  string name = zhua->query("name");
  string msg;

if (arg = "zhua" ||  arg = "xiuluo zhua" )
  {
  msg = "$Nװ����"+name+"�����ɵ��������١�\n"; 
  zhua->set("wield_msg",msg);
  // remove_call_out("longzhua");
 call_out("longzhua",5,me,zhua);
  }
  return 0;
}
int do_unwield (string arg)
{
  object me = this_player();
  object zhua = this_object();
  string name = zhua->query("name");
  string msg;

if (arg = "zhua" || arg = "long zhua")
{
  msg = "$N��"+name+"�������������ж�ʱ������࡭��\n"; 
  zhua->set("unequip_msg",msg);
  remove_call_out("longzhua");
}
  return 0;
}

void longzhua(object who,object ob)
{
     object target;
        string msg;
        object thing,*inv;
        target = offensive_target(who);
     if( who->is_fighting() &&target) 
     {
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        inv=all_inventory(target);
        if(!sizeof(inv))        {
 message_vision(HIR"\n$N"+HIY"�����Ѿ�û�ж�������\n"NOR,target);
    }
        else    {
                thing=inv[random(sizeof(inv))];
     if (!thing->query("no_give"))
                thing->move(who);
message_vision(HIB"\n����"+HIR"֮צ"+HIW"���˳�ȥ����"+HIR"$N"+HIW"�����ѵ�"+thing->query("unit")+HIY+" " +thing->query("name")+HIW" "+"��\n"NOR,target);
        }
call_out("longzhua",7,who,ob);
}
}
