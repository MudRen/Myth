//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

void create()
{
        set_name(HIM"�����ƹ���"NOR, ({"yunguang po", "po"}));
        set_weight(80);
        set("long", "�п������֮������������֮��\n");
        set("unit", "��");
        set("unique", 1);
        set("no_sell", 1);
        set("no_steal", 1);
        set("no_put",1);
        set("no_drop", 1);
        set("no_give", 1);
        set("is_monitored",1);
        set("baowu",1);
        setup();
}
/*
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
                
   if(item!="po"&&item!="yunguang po") return notify_fail("�����˭��ʲô? \n");
  
  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+huluname+"��\n");
    return notify_fail("��������ƹ���ʧ�ܡ�\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("��������ƹ���ʧ�ܡ�\n");
  }
 
  
  message_vision (HIY"\n$N������������ͳ������ƹ���������һ�������ƽ���ʿ���ڣ�",me);

  
  if(!objectp(target = find_living(ji_ob))||!environment(target)){
            tell_room(environment(me),"\n������ֳ�һ���ɫ�Ʋʣ�һ���ƽ���ʿ�����������������Ҳ�������ˣ�\n"NOR);
            return 1;
    }
 msg = HIY"��ȥ��"+target->query("name")+"ץ����\n������ֳ�һ���ɫ�Ʋʣ�һ�������׵Ļƽ���ʿ�ֳ����Σ��ǣ�Ȼ��ͷ�۵糸���ȥ�ˡ�\n"NOR;
 message_vision(msg,me);
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
 
        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared max_mana.

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
          tell_room(environment(target),HIY"ͻȻ���н�ɫ�Ʋʶ���,һλ�ƽ���ʿƽ�ս�"+target->query("name")+"��ȥ�ˡ�\n"NOR);       
          target->move(environment(me));
          msg =  HIY "��һ�������ɫ�Ʋʶ��֣��ƽ���ʿ��$n������һ�ӣ���$nˤ�˸�ͷ������\n" NOR;
message_vision(msg,me,target);
me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(1+random(5));
       }else{
      msg =  HIY "��һ�������մ����ƽ���ʿ��У����������ץ����"+target->query("name")+"��\n" NOR;
           message_vision(msg,me);         
           me->start_busy(2);
      
      } 
  if (interactive(me)) hulu->add("interactive_usage",1);
  return 1;
}

void self_dest()
{
    object env=environment(this_object());
    if(env)
        tell_object(env, HIY"ֻ������һ��,�����ƹ������Ʈ���ˣ�\n");
    destruct(this_object());
}
*/

