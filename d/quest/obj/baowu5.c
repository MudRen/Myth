//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"���Լ�"NOR, ({"jinjiao jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�˼�������������������������������¾��������ڿ��У��������£�\n���ƻ��壬ͷ��ͷ�����β��β��ɣ�������õ����ɣ�һ�����Ρ�\n");
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
                
   if(item!="jinjiao jian"&&item!="jian") return notify_fail("�����˭��ʲô? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+huluname+"��\n");
    return notify_fail("������Լ�ʧ�ܡ�\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("������Լ�ʧ�ܡ�\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "��������˲������\n");
            return notify_fail("������Լ�ʧ�ܡ�\n");
    }
if(uptime()-me->query_temp("last_ji") < 6) return notify_fail("����æ����......\n");
    
  message_vision (HIR"\n$N"+HIY"�ͳ����Լ�������һ����",me);

  
 message_vision (HIY"\nֻ�����Լ��ڿ��л�������������$N"+HIY"��ȥ\n"NOR,target,me);  
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = (int)me->query("daoxing");
        dp = target->query("daoxing");
       if( random(ap) < dp ) success = 0;
 
     

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
     
          message_vision (HIY"\n$N"+HIY"��������,����������������,��㱻��Ϊ���Ρ�\n"NOR,target,me);
          target->receive_damage("sen",me->query("mana_factor"));
          target->receive_damage("kee",me->query("mana_factor"));
          COMBAT_D->report_status(target);
          message_vision (HIY"\n����һ������,�ֻ�Ϊ�����ص�$N"+HIY"������\n"NOR,me,target);
          target->kill_ob(me);
          me->start_busy(1);
          target->start_busy(1);
       }else{
          message_vision(HIR"\n$N"+HIY"һ����,�����˽�����������һ��\n"NOR,target,me);         
          message_vision (HIY"\n����һ������,�ֻ�Ϊ�����ص�$N"+HIR"������\n"NOR,me,target);
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
	tell_object(env, name()+HIY"ͻȻ���Լ��ڿն���,���������������ƶ�ȥ����\n");
    destruct(this_object());
}
