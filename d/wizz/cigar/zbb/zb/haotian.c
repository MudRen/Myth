// ���쾵 by Calvin

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
        set_name(HIG"���쾵"NOR, ({"haotian jing","jing","zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�˱���춿��У�����ɫ���⣬��Ȼ���ɣ���֮������Ӧ֮������\n");
                set("unit", "ֻ");
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

   if( sscanf(arg, "%s on %s", item, ji_ob)!=2 ) return notify_fail("�����˭��ʲô��\n");
                
   if(item!="haotian jing"&&item!="jing") return notify_fail("�����˭��ʲô? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+huluname+"��\n");
    return notify_fail("������쾵ʧ�ܡ�\n");
  }
if(uptime()-me->query_temp("last_ji") < 6) return notify_fail("����æ����......\n");

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("������쾵ʧ�ܡ�\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "��������˲������\n");
            return notify_fail("������쾵ʧ�ܡ�\n");
    }
 if(environment(me) && (environment(me)->query("no_fight") || environment(me)->query("no_magic")))    return notify_fail("���ﲻ�ܼ����쾵��\n"); 
    
  message_vision (HIG"\nֻ��$N"+HIG"�ͺ��쾵�������д��һ��: ��������\n",me);
  
 msg = HIG"ֻ�����쾵�Ľ�����ִ��,����Ƿ���\n"NOR;
 message_vision(msg,me);
  
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = (int)me->query("daoxing")/1000;
        dp = (int)target->query("daoxing")/1000;
 if( random(ap) < dp/2 ) success = 0;

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
          
          message_vision (HIG"\n$N"+HIG"Ӧ��̧ͷ�����п�ȥ,ɲʱ����ɫ����ֱ��˫Ŀ,ʲô���������ˡ�\n",target,me);
          target->start_busy(4+random(6));
          target->receive_damage("kee",me->query("mana_factor")/2);
          COMBAT_D->report_status(target);
           message_vision (HIG"\n$N"+HIG"��������,���쾵����ʧ�������ˣ�\n",me,target);
          target->kill_ob(me);
          me->start_busy(1);
       }else{
    
          message_vision (HIG"\n$N"+HIG"�������,ר��ս����\n",target);
          message_vision (HIG"\n$N"+HIG"��������,���쾵����ʧ�������ˣ�\n",me);
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
        tell_object(env, HIY"ֻ��ž��һ��,���쾵����������ﻯΪˮ�鲻���ˣ���\n");
    destruct(this_object());
}