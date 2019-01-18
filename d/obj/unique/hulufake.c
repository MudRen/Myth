// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("�Ͻ���«",({"hu lu", "hu", "lu", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 100000);
    set("material","cloth");
    set("long","һֻ����͸�ϵĽ��«��\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
  set("no_sell", "�Ͻ���«�˷���û�˸���Ҳ��\n");
  //set("no_drop", "�Ͻ���«�˷�����������Ҳ��\n");
  set("no_give", "�Ͻ���«�˷�����������Ҳ��\n");
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
    tell_object (who, "�����������������ȥ��ȴŲ���������ӡ�\n");
    return 1;
  }
  tell_object (who, "���þ�ȫ���������ס��«�ڣ�������ȥ��\n");
  if (room->is_character())
    room = environment (room);
  who->move(room);
  message_vision ("$N���Ͻ���«��̽���Դ����κ��������˳�����\n",who);
  return 1;
}

int ji_ob (object victim)
{
  object hulu = this_object ();
  object me = environment(hulu);
  string huluname = hulu->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "���޷�æ��͵�м�"+huluname+"��\n");
    return notify_fail("����æ���ء�\n");
  }

  if (sizeof(all_inventory(hulu))>0)
  {
    tell_object (me, huluname+"����������޷��ټ�"+huluname+"��\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  if (!victim)
  {
    tell_object (me, "��������˲������\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"�Ѿ����޵ֿ����������ؼ��ˡ�\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+huluname+"��\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "��ķ������㣬������"+huluname+"��\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  if( (int)me->query("sen") < 500)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  message_vision ("\n$N������������ͳ�"+huluname+"�׶����ϣ��䲻���ض�$nһ������"+
                  victim->query("name")+"����\n",me,victim);
  if (hulu->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("ֻ�����С���һ��"+huluname+"ͻȻ������ȥ��������Ƭɢ���ڵء�\n",me);
    destruct (hulu);
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
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
     message_vision ("\n$n˳�ڴ�������ڣ���\n",me,victim);
     message_vision ("���֮��$n��"+huluname+"�ȵ�һ��������˽�ȥ��\n",me,victim);
     victim->move(hulu);
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
    message_vision ("\n$n֪����թ���տڲ�����ʲô��û������\n",me,victim);
    me->add("mana", -200);
  }
  if (victim)
    victim->kill_ob(me);
  if (interactive(me))
    hulu->add("interactive_usage",1);
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
  message_vision ("$N���Ͻ���«��̽���Դ����κ��������˳�����\n",who);
}

int ji (string target)
{
  object hulu = this_object ();
  object me = this_player();
  string huluname = hulu->query("name");
  object victim;

  if (interactive (me))
  {
    tell_object (me, huluname+"ʲô����Ҳû�У������Ǹ��ٻ���\n");
    return notify_fail("���"+huluname+"ʧ�ܡ�\n");
  }

  if (!target)
    return notify_fail("�����˭��"+huluname+"��\n");

  victim=present(target,environment(me));
  hulu->ji_ob(victim);
  return 1;
}

