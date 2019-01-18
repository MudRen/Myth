#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name("ʥ����", ({"sheng lingzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
                set("value",10000);
set("no_steal",1);
                set("no_drop", "��˱���ı����������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");
//                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("long","��س���ʱ�����߹����ϣ����߹����£���һ�ְ�����ǹ����У���Ϊ�˱���\n
������н�Ϊ���ӡ�\n");
                set("replace_file", "/d/obj/flower/rose");
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
                set("spells/thunder",1);
                set("spells/water",1);
                set("spells/wind",1);
                set("spells/earth",1);
        }
        setup();
}
void init()
{
        object who = this_player();

        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 800000 )

        this_object()->move("/obj/empty"); 

}
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        add_action("do_combine","combine");
        unique::init();
}
int do_combine()
{
        object me,a,b,c,d,e,real;
        me=this_player();
        a=this_object();

        if( (int)me->query("force") < 3000)
                return notify_fail("����������㡣\n");
        if( (int)me->query("mana") < 3000)
                return notify_fail("��ķ������㡣\n");

        if ( !(b=present("zhuxian jian",me))) 
                return notify_fail("���Ż�û���ռ����㹻�Ķ�����\n");
        if ( !(c=present("xianxian jian",me)))
                return notify_fail("���Ż�û���ռ����㹻�Ķ�����\n");
        if ( !(d=present("juexian jian",me)))
                return notify_fail("���Ż�û���ռ����㹻�Ķ�����\n");
        if ( !(e=present("luxian jian",me)))
                return notify_fail("���Ż�û���ռ����㹻�Ķ�����\n");
        if( real=new("/d/zhuxian/obj/wuchen")){
                destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
        real->move(me);
        message_vision(HIW "$N������ʥ����������У����İѱ���ͬʱ����ʥ���顣�İѱ�����Ȼ��Ϊһ�壡\n" NOR,me);
        destruct(a);
        }
        return 1;
}

/*int init()
{
        object who = this_player();
        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 800000 )
        this_object()->move("/obj/empty"); 
         }
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        unique::init();
} */

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
//divid by 10;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp )
                 {
                        damage = 500+random(300);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ��������׵��������ţ��ֱ��ػ��յ�Ƥ�����á�\n
��ɽʯ�ҵ�Ƥ��Ѫ��������������˫�ۣ��ֱ�ˮ����͸�������������ѡ�\n" NOR;

                                target->receive_damage("sen", damage*8/5);
                                target->receive_wound("sen", damage*2/3);
                                target->receive_damage("kee", damage*8/5);
                                target->receive_wound("kee", damage/2);
                                target->start_busy(5);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n˭֪$n���޷�Ӧ��\n" NOR;   
                }
                else
                        msg += "���Ǳ�$n�㿪�ˡ�\n";

                message_vision(msg, who, target); 
        }
call_out("shengzhuconditions",7,who,ob);
}
