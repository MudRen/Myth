// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
 
void create()
{
  set_name("�Ͻ���",({"huangjin sheng", "sheng", "fabao"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","��");
    set("value", 100000);
    set("material","cloth");
    set("long","һ���ɳ��ɶ̵ĻϽ�����\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("unique", 1);
  set("no_sell", "�Ͻ����˷���û�˸���Ҳ��\n");
  set("no_drop", "�Ͻ����˷�����������Ҳ��\n");
  set("no_give", "�Ͻ����˷�����������Ҳ��\n");
  set("replace_file", "/d/qujing/pingding/obj/shengfake.c");
  set("is_monitored",1);
  setup();
} 

void init()
{ check_owner();
}

int ji_ob (object victim)
{
  object sheng = this_object ();
  object me = environment(sheng);
  string shengname = sheng->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "���޷�æ��͵�м�"+shengname+"��\n");
    return notify_fail("����æ���ء�\n");
  }

  if (!victim)
  {
    tell_object (me, "��������˲������\n");
    return notify_fail("���"+shengname+"ʧ�ܡ�\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"�Ѿ����޵ֿ����������ؼ��ˡ�\n");
    return notify_fail("���"+shengname+"ʧ�ܡ�\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+shengname+"��\n");
    return notify_fail("���"+shengname+"ʧ�ܡ�\n");
  }

  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+shengname+"��\n");
    return notify_fail("���"+shengname+"ʧ�ܡ�\n");
  }

  if ((int)me->query("sen") < 500)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("���"+shengname+"ʧ�ܡ�\n");
  }

  if (sheng->query_temp("being_used"))
  {
    object ob = sheng->query_temp("victim");

    if (ob &&
        environment(me) == environment(ob))
    {
      tell_object (me, shengname+"�Ѿ����˳�ȥ��\n");
      return notify_fail("���"+shengname+"ʧ�ܡ�\n");
    }
  }

  message_vision ("\n$N������������ͳ�"+shengname+"��$n�׽���ȥ��\n",me,victim);
  if (sheng->query("interactive_usage") > (me->query("kar")/3))
  {
    message_vision ("ֻ��"+shengname+"��������ɢ��һ�ɹ����������紵ɢ�ˡ�\n",me);
    destruct (sheng);
    return notify_fail("���"+shengname+"ʧ�ܡ�\n");
  }
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

  if(random(ap+dp)>dp)
  {
     message_vision ("\nͻȻ֮��$nһ�����ֲ�������æ�����ϧ����\n",me,victim);
     message_vision ("$n��"+shengname+"���������������������������ã�\n",me,victim);
     duration = (50-victim->query("kar"))/2;
     if (duration < 10)
       duration = 10;
     victim->set_temp("no_move",1);
     victim->start_busy(duration,1);
     sheng->set_temp("being_used",1);
     sheng->set_temp("victim",victim);
     call_out ("releasing",duration,me,victim,sheng);
     me->add("mana", -400);
  }
  else
  {
    message_vision ("\n$n���һ�������˹�ȥ��\n",me,victim);
    me->add("mana", -200);
  }
  victim->kill_ob(me);
  if (interactive(me))
    sheng->add("interactive_usage",1);
  return 1;
}

void releasing (object me, object who, object sheng)
{
  object victim = sheng->query_temp("victim");

  if (victim && who && me &&
      victim == who &&
      environment(me) == environment(who))
    message_vision ("\n$Nһ���֣����������˻�����\n",me);
  if (who)
  {
    who->set_temp("victim",0);
    who->set_temp("no_move",0);
    who->interrupt_me();
  }
  if (sheng)
    sheng->set_temp("being_used",0);
}

int ji (string target)
{
  object sheng = this_object ();
  object me = this_player();
  string shengname = sheng->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+shengname+"��\n");

  victim=present(target,environment(me));
  sheng->ji_ob(victim);
  return 1;
}

