// ����ʥ�� by Calvin
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
int do_wield(string arg);
int do_unwield(string arg);

object offensive_target(object me);
void create()
{
        set_name(HIW"����ʥ��"NOR, ({"lingyue sword", "sword"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѵ���ɫ���ὣ���������ǳ��Ļ�����\n");
                set("value", 30000);
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("material", "blacksteel");
                set("sheenness", 20);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        set("weapon_prop/int", 2);
        }

        init_sword(50);
        setup();

}

void init()
{
        add_action("do_wield","wield");
        add_action("do_unwield", "unwield");
        unique::init();
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
  object sword = this_object();
  string name = sword->query("name");
  string msg;

if(arg!="all"&&arg != "wuchen jian" )
    return notify_fail("��Ҫװ��ʲô��\n");
  msg = "$N����һ��"+name+"������ǰһ����\n"; 
  sword->set("wield_msg",msg);
remove_call_out("conditions");
call_out("conditions",1,me,sword);
  return 0;
}
int do_unwield (string arg)
{
  object me = this_player();
  object sword = this_object();
  string name = sword->query("name");
  string msg;

if ( arg!= "all" && arg != "wuchen jian")
    return notify_fail("��Ҫж��ʲô��\n");

  msg = "$N��"+name+"���˻�ȥ����\n"; 
  sword->set("unwield_msg",msg);
remove_call_out("conditions");
  return 0;
}
void conditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;

string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIW"�����ɽ�ͻȻ���ַɳ�,�ڿ��з���һ�ܣ�\n"NOR;

                ap = 10000000;
                dp = target->query("combat_exp");

                if( random(ap + dp) > dp )
                 {
                        damage = 600+random(500);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 10);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ������������ɽ����Ķ�����������Ϊ���ء�\n" NOR;
                                target->receive_damage("sen", damage*2);
                                target->receive_wound("sen", damage);
                                target->receive_damage("kee", damage*2);
                                target->receive_wound("kee", damage);
                        } 
            else
                msg += HIC "\n˭֪$nӲ��һ�����������ˡ�\n" NOR;   
                }
                else
                        msg += "���Ǳ�$n�㿪�ˡ�\n";
                message_vision(msg, who, target); 
        }
call_out("conditions",7,who,ob);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int damage;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damage = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("sen",damage*2);
        victim->receive_damage("kee",damage*2);
        victim->start_busy(3);
        return HIW "�����ɽ��ϰ׹�һ����\n" NOR;
        }
}


