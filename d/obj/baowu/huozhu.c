
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
int do_amalgamation();
object offensive_target(object me);

void create()
{
        set_name(HIR "������" NOR, ({"huo lingzhu", "huozhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "crystal");
set("no_steal",1);
                set("value",10000);
                set("no_drop", "��˱���ı����������󰡡�\n");
                set("no_give", "����ϡ��֮����ô������������?\n");
                set("no_sell", "��?����ϡ��֮��˭�����!\n");
                set("no_put", "����ϡ��֮����ô�ܴ����?\n");
                set("no_fang", "����ϡ��֮����ô�ܴ����?\n");
                set("long","��˵�е����б���֮һ����֮�ɱܻ��գ����ɷ�����ϵ������\nΪ����������֮�");
                set("replace_file", "/d/obj/flower/rose");
                set("bb",1);
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
        }
        setup();
}

int init()
{
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        //�������ˮ����ϱ�
        add_action("do_amalgamation", "wuzhuhebi");
        return 1;
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

if (arg == "all") arg ="huozhu";
if (arg != "huozhu" &&  arg != "huo lingzhu" )
    return notify_fail("��Ҫ���ʲô��\n");
  msg = "$N����һ��"+name+"�������������ʡ�\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("conditionhuozhu");
call_out("conditionhuozhu",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

  if (arg!= "all" && arg != "huozhu" && arg != "huo lingzhu")
    return notify_fail("��Ҫժ��ʲô��\n");

  msg = "$N��"+name+"�����ժ��������\n"; 
  zhu->set("unequip_msg",msg);
  remove_call_out("conditionhuozhu");
  return 0;
}

void conditionhuozhu(object who,object ob)
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

        msg = HIR"��������Ȼ������䣬����и��ֳ�һ�����Ļ���ף�ڣ�ֻ��ף��˫��һȦ��\n
һ��˶��Ļ������$n��ȥ��\n"NOR;
//divid by 10;

                ap = 2000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp )
                 {
                        damage = 500+random(300);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ�����������ײ�����ţ��뷢������\n" NOR;

                                target->receive_damage("sen", damage*4/5);
                                target->receive_wound("sen", damage/3);
                                target->receive_damage("kee", damage*4/5);
                                target->receive_wound("kee", damage/4);
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
call_out("conditionhuozhu",7,who,ob);
}

int do_amalgamation()
{
        //��ű���
        object wind,water,thunder,earth;
        object who = this_player();
        object shengzhu;

        if(who->is_fighting())
           return notify_fail("���������أ���������\n");
        if(who->is_busy())
           return notify_fail("����æ����!\n");
        if(!wind = present("fengzhu",who))
           return notify_fail("�㻹ȱ��"+HIG "������" NOR +"��!��ô����ϱ���?\n");
        if(!thunder = present("leizhu",who))
           return notify_fail("�㻹ȱ��"+HIB "������" NOR +"��!��ô����ϱ���?\n");
        if(!earth = present("tuzhu",who))
           return notify_fail("�㻹ȱ��"+HIY "������" NOR +"��!��ô����ϱ���?\n");
        if(!water = present("shuizhu",who))
           return notify_fail("�㻹ȱ��"+HIW "ˮ����" NOR +"��!��ô����ϱ���?\n");
if ((water->query("equipped")!="worn") && (wind->query("equipped")!="worn") && (thunder->query("equipped")!="worn") && (earth->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
{        
        message_vision("$N����ű������һ��ֻ����ű���ȽȽ����һʱ�����ʢ��ֱ��������\n
���꣬"+HIG "������" NOR+"���������ų�����̹⣻"+HIR "������" NOR +"�����Ϸ�������Ŀ��⣻"+HIB "������" NOR +"������������������\n
�����������⣻"+HIW "ˮ����" NOR +"ȴͨ��Ө�ף�����������"+HIY "������" NOR +"ֱ����񷣬к������ƹ⡣\n
�ִ�Ƭ�̣��������һ����$N����ȴ����һ��˶���͸�����飬��ʱ������ʺ��⡣\n",who);

        message("channel:rumor",RED+"��ҥ�ԡ�ĳ�ˣ�"+who->query("name")+"�õ�ʥ�����ˣ�\n"+NOR,users() );
        
         shengzhu = new("/d/obj/baowu/shengzhu");
        shengzhu->move(who);
        destruct(wind);
        destruct(water);
        destruct(earth);
        destruct(thunder);
        destruct(this_object());
        return 1;
}
return notify_fail("�������ժ�²��ܺ�赣�\n");
}
