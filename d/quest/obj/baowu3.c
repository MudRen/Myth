//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
        set_name(HIR"������"NOR, ({"huolong biao","biao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ֻ�������ߴ���֣��ų����⣬�����Ŀ����Ի�����Ķ�����\n");
                set("unit", "��");
                set("unique", 1);
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_put",1);
                set("no_drop", 1);
                set("no_give", 1);
                set("is_monitored",1);
                set("baowu",1);

        }
}

void init ()
{
  check_owner();
  add_action ("do_ji", "ji");
  if(userp(this_player())) 
     call_out("self_dest",7200+random(600));
}

int do_ji (string arg)
{
  string msg,ji_ob,item;
  int ap, dp,success;
  object target;
  object hulu = this_object ();
  object me = this_player();
  string huluname = hulu->query("name");
  object victim;

   if( !arg || sscanf(arg, "%s on %s", item, ji_ob)!=2 ) return notify_fail("�����˭��ʲô��\n");
                
   if(item!="biao"&&item!="huolong biao") return notify_fail("�����˭��ʲô? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+huluname+"��\n");
    return notify_fail("���������ʧ�ܡ�\n");
  }
if(uptime()-me->query_temp("last_ji") < 6) return notify_fail("����æ����......\n");

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("���������ʧ�ܡ�\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "��������˲������\n");
            return notify_fail("���������ʧ�ܡ�\n");
    }
    
   message_vision (HIR"\nֻ��$N"+HIR"�䲻���ͳ������ڻ���һ����",me);

  
       message_vision (HIR"\nֻ���������ڿ��л�����֣������Ŀ,ֱ��$N"+HIR"���ش�ȥ\n"NOR,target,me);  
       me->add("mana", -400);
       me->receive_damage("sen", 30);    
       success = 1;

        ap = (int)me->query("daoxing")/1000;
        dp = target->query("daoxing")/1000;
 if( random(ap+dp) < dp/4 ) success = 0;
 
     

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
     
          message_vision (HIR"\n$N"+HIR"��������,���һ��������͸�ض�����\n"NOR,target,me);
          target->receive_damage("sen",100+me->query("mana_factor"));
          COMBAT_D->report_status(target);
          message_vision (HIR"\n������һ������,��ص�$N"+HIR"������\n"NOR,me,target);
          target->kill_ob(me);
          me->start_busy(1);
          target->start_busy(1);
       }else{
          message_vision(HIR"\n$N"+HIR"һת��,������$n"+HIR"��һ��,�������о���һ���亹��\n"NOR,target,me);         
          message_vision (HIR"\n������һ������,��ص�$N"+HIR"������\n"NOR,me,target);
          target->kill_ob(me);
          me->start_busy(1);
      
      } 
   me->set_temp("last_ji",uptime());
  if (interactive(me)) hulu->add("interactive_usage",1);
  return 1;
}

void self_dest()
{
    object env=environment(this_object());
    if(env)
	tell_object(env, HIY"ֻ��ž��һ��,�������ڿն����ڿ���ը�˸����飡��\n");
    destruct(this_object());
}
