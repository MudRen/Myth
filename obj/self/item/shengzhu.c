//Last modified by aeddy@2001/03/26

#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIR"ʥ"HIG"��"HIW"��"NOR, ({"sheng-lingzhu", "shengzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("Fmaterial", "gem");
                set("value",100000000);
                set("can_putin",1);
                set("no_all", 1);
                set("no_drop", "��˱���ı����������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");
                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("long","��س���ʱ�����߹����ϣ����߹����£���һ�ְ�����ǹ����У���Ϊ�˱���\n
������н�Ϊ���ӡ�\n");
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
                set("spells/thunder",1);
                set("spells/water",1);
                set("spells/wind",1);
                set("spells/earth",1);
        }
        setup();
}

int init()
{
        object who = this_player();

        if ( interactive(environment()) && !wizardp(who) &&
        environment()->query("combat_exp") < 1000000 )
        this_object()->move("/obj/empty"); 

        add_action("do_wear","wear");
        add_action("do_remove", "remove");
}

// This function selects a random target for offensive spells/functions.
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

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "sheng lingzhu" )
    return notify_fail("��Ҫ���ʲô��\n");
  msg = "$N����һ��"+name+"���ٸ�������ˬ��\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "sheng lingzhu")
    return notify_fail("��Ҫժ��ʲô��\n");

  msg = "$N��"+name+"�����ժ��������\n"; 
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
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
        msg = HIR"ʥ������ʺ�����Ȼ���䣬ɲʱ�����׵�������ɽ�����ѣ�\n"NOR;

                ap = 2000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp ) {
                        damage = 200+random(100);//By aeddy@2001/03/26
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) {
                                msg += HIC "���$n��ܲ��������׵��������ţ��ֱ��ػ��յ�Ƥ�����á�\n
��ɽʯ�ҵ�Ƥ��Ѫ��������������˫�ۣ��ֱ�ˮ����͸�������������ѡ�\n" NOR;

                                target->receive_damage("sen", damage*8/5);
                                target->receive_wound("sen", damage*2/3);
                                target->receive_damage("kee", damage*8/5);
                                target->receive_wound("kee", damage/2);
                                target->start_busy(3);//By aeddy@2001/03/26
                        } 
            else
                msg += HIC "\n˭֪$n���޷�Ӧ��\n" NOR;   
                }
                else
                        msg += "���Ǳ�$n�㿪�ˡ�\n";

                message_vision(msg, who, target); 
        }
	call_out("shengzhuconditions",7,who,ob);
}
