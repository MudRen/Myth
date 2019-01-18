// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
 
void create()
{
  set_name("�����",({"jingang zhuo", "jingang", "zhuo", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(5000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 100000);
    set("material","jade");
    set("long","һֻ��ɭɭ��Ȧ�ӡ�\n");
  }
  set("unique", 1);
  set("no_sell", "������˷���û�˸���Ҳ��");
  set("no_drop", "������˷�����������Ҳ��");
  set("no_give", "������˷�����������Ҳ��");
  set("replace_file", "/d/qujing/jindou/obj/zhuofake.c");
  set("is_monitored",1);
  setup();
} 

int ji_ob (object victim)
{
  object zhuo = this_object ();
  object me = environment(zhuo);
  string zhuoname = zhuo->query("name");
  object ob;
  int damage, ap, dp, myspells, myexp, victimspells, victimexp;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "���޷�æ��͵�м�"+zhuoname+"��\n");
    return notify_fail("����æ���ء�\n");
  }

  if (sizeof(all_inventory(zhuo))>0)
  {
    tell_object (me, zhuoname+"����������޷��ټ�"+zhuoname+"��\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  if (!victim)
  {
    tell_object (me, "��������˲������\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"�Ѿ����޵ֿ������ˡ�\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+zhuoname+"��\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  if ((int)me->query("mana") < 300)
  {
    tell_object (me, "��ķ������㣬������"+zhuoname+"��\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  ob = victim->query_temp("weapon"); 
  if(!ob)
  {
    tell_object (me, "�Է�û��ʹ���������ס�\n");
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }

  message_vision ("\n$N��������"+zhuoname+"�����������дʡ�\n",me,victim);
  if (zhuo->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("ֻ�������ꡱһ����"+zhuoname+"�ڰ��Ť��һŤ�����˸����顣\n",me);
    destruct (zhuo);
    return notify_fail("���"+zhuoname+"ʧ�ܡ�\n");
  }
  message_vision ("ɲ�Ǽ�"+zhuoname+"�ڿ���һ�Σ�����һ�ɰ���\n",me,victim);
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
     message_vision ("$n���е�"+ob->name()+"�ѳֲ�����\n",me,victim);
     message_vision ("˵ʱ����ʱ�죬"+ob->name()+"�ѱ�"+zhuoname+"��ȥ��\n",me,victim);
     ob->unequip();
     if (ob->query_weight()>zhuo->query_max_encumbrance())
     {
        message_vision (ob->name()+"��"+zhuoname+"�ﻯ��һ����ɢ�ˣ�\n",me,victim);
        destruct(ob);
      }
      else ob->move(zhuo);
      me->add("mana", -250);
  }
  else
  {
    message_vision ("$nһ�����ƿ��˿��е�"+zhuoname+"��\n",me,victim);
    me->add("mana", -125);
  }
  victim->kill_ob(me);
  if (interactive(me))
    zhuo->add("interactive_usage",1);
  return 1;
}

int ji (string target)
{
  object zhuo = this_object ();
  object me = this_player();
  string zhuoname = zhuo->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+zhuoname+"��\n");

  victim=present(target,environment(me));
  zhuo->ji_ob(victim);
  return 1;
}

