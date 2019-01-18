// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("�ɰײ����",({"da bao", "bao", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 100000);
    set("material","cloth");
    set("long","һֻ�ƾɵİײ������\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
  set("no_sell", "�ɰײ�����˷���û�˸���Ҳ��\n");
  //set("no_drop", "�ɰײ�����˷�����������Ҳ��\n");
  set("no_give", "�ɰײ�����˷�����������Ҳ��\n");
  set("is_monitored",1);
  setup();
} 

void init ()
{
  add_action ("do_out", "out");
}

int do_out ()
{
  object me = this_object ();
  object who = this_player();
  object where = environment (who);
  object room = environment (me);

  if (where != me)
    return 0;

  if (who->query_temp("no_move") ||
      who->is_busy())
  {
    tell_object (who, "���ȥ����ϧ�����ڶ��������ˡ�\n");
    return 1;
  }
  tell_object (who, "���ƿ��ɰײ�����ڣ��������˳�ȥ��\n");
  if (room->is_character())
    room = environment (room);
  who->move(room);
  message_vision ("$N�Ӿɰײ�������ﹰ�˳�����\n",who);
  return 1;
}

int ji_ob (object victim)
{
  object bao = this_object ();
  object me = environment(bao);
  string baoname = bao->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "���޷�æ��͵�м�"+baoname+"��\n");
    return notify_fail("����æ���ء�\n");
  }

  if (sizeof(all_inventory(bao))>0)
  {
    tell_object (me, baoname+"����������޷��ټ�"+baoname+"��\n");
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }

  if (!victim)
  {
    tell_object (me, "��������˲������\n");
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"�Ѿ����޵ֿ����������ؼ��ˡ�\n");
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+baoname+"��\n");
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }

  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+baoname+"��\n");
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }

  if( (int)me->query("sen") < 500)
  {
    tell_object (me, "���޷����о��������\n");
  }

  message_vision ("\n$N�����������৵�����"+baoname+"��\n",me,victim);
  if (bao->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("ֻ��"+baoname+"ͻȻ�ڰ���б����Ƭ����Ůɢ����Ʈ�䡣\n",me);
    destruct (bao);
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }
  message_vision (baoname+"�����ڰ���У�ֻ��һ�ɰ������һ�㵹����ȥ��\n",me,victim);
  me->start_busy(60/mykar);
  victimkar=victim->query("kar");
  myspells=me->query_skill("spells")/10;
  myexp=me->query("combat_exp")/1000;
  victimspells=victim->query_skill("spells")/10;
  victimexp=victim->query("combat_exp")/1000;
  ap=(myexp+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
  ap=ap*mykar/1000;
  dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
  dp=dp*victimkar/1000;
  if (wizardp(me) && me->query("env/combat")=="verbose")
    tell_object(me, GRN "������"+ap+"�����أ�"+dp+"��\n" NOR);

  if(random(ap+dp)>dp ||
     (!interactive(me) && 
      (!victim->query_temp("obstacle/xiaoxitian_entered") ||
       strsrch(victim->query("nickname")+" ","��")==-1)))
  {
     message_vision ("$n�ٸ�ͷ�ؽ��ᣬ���ɼ���Ʈ��������\n",me,victim);
     message_vision ("һ˲�䣬$n�ѱ�"+baoname+"װ�˽�ȥ��\n",me,victim);
     victim->move(bao);
     if (! interactive(me))
     {
       object room;
       object nao;

       victim->move("/d/qujing/xiaoxitian/chanfang");
       room = environment(victim);
       message_vision ("$N�����˹�����\n",victim);
       nao = present ("jin nao",room);
       if (nao)
       {
         message_vision ("�ϵ�һ����$N���ؽ���һֻ�޴�Ľ���\n",victim,nao);
         victim->set_temp("obstacle/xiaoxitian_entered", 1);
         victim->move(nao);
       }
     }
     duration = (50-victim->query("kar"))*10;
     if (duration < 60)
       duration = 60;
     victim->set_temp("no_move",1);
     victim->start_busy(duration,1);
     victim->unconcious();
     call_out ("releasing",duration,victim);
     me->add("mana", -400);
  }
  else
  {
    message_vision ("$nһת��ܿ���"+baoname+"������һ�У�\n",me,victim);
    me->add("mana", -200);
  }
  if (victim)
    victim->kill_ob(me);
  if (interactive(me))
    bao->add("interactive_usage",1);
  return 1;
}

void releasing (object who)
{
  object me = this_object();
  object room = environment(me);

  if (room->is_character())
    room = environment(room);

  if (! who)
    return;

  who->set_temp("no_move",0);
  who->interrupt_me();
  if (! who ||
      interactive (who))
    return;
  if (environment(who) != me)
      return;
  who->move(room);
  message_vision ("$N�Ӿɰײ�������ﹰ�˳�����\n",who);
}

int ji (string target)
{
  object bao = this_object ();
  object me = this_player();
  string baoname = bao->query("name");
  object victim;

  if (interactive (me))
  {
    tell_object (me, baoname+"ʲô����Ҳû�У������Ǹ��ٻ���\n");
    return notify_fail("���"+baoname+"ʧ�ܡ�\n");
  }

  if (!target)
    return notify_fail("�����˭��"+baoname+"��\n");

  victim=present(target,environment(me));
  bao->ji_ob(victim);
  return 1;
}

