// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;
inherit F_UNIQUE;
void init();
int do_blow(string arg);
void create()
{
  set_name(HIG "�������" NOR, ({ "yu xiao"})); 
  set_weight(10000);
        set("unique", 1);
  set("long","����һ֧����������������������������ࡣ\n���˰�������,����Դ���(blow)��\n");
  set("unit", "��");
  setup();
}

init ()
{
  add_action ("do_blow", "blow");
}

int do_blow (string arg)
{
  object me, where;
  int sen_cost, gain;
  
//  object xiao = this_object();
  string *msgs = ({
    "$N��ִ��ߣ�һ����÷����Ū������������������\n",
    "$Nһ��������÷���������������� �����ڶ���\n",
    "$N��˼Ƭ���漴һ������ɽ��ˮ�����������\n",
    "$N��Ŀ����һ�������񳯷����������������С�\n",
    "$Nһ����꼻��֡��ϣ�������������\n",
    "$Nһ���������ơ���������Ϊ֮һ��\n",
  });
  me = this_player();
  where=environment(me);
        if( me->is_busy() )
                        return notify_fail("������æ���أ������������´���...\n");
        if( me->is_fighting() )
                        return notify_fail("̫�����˰ɣ����ʱ������...\n");
        if( where->query("no_fight") )
                        return notify_fail("������˺���ϲ������˳���ѽ......\n");
//        if( (int)me->query_skill("xiao",1)<50 )
//                return notify_fail("����Ҵ��˼��£����û�д��������ˣ���Ȼ�㻹û�����򵽴���֮����\n")
        if( (int)me->query_skill("xiao",1)>250 )
                return notify_fail("���������Ȼ¯���࣬���Խ����ﴵ������������\n");

        sen_cost = 20 + (35-(int)me->query("int"));
        if( (int)me->query("sen")<sen_cost )
                return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n"); 
        me->receive_damage("sen", sen_cost);

        gain = (int)me->query_skill("xiao", 1)/5+(int)me->query("int")+1;
        me->improve_skill("xiao", gain);
        message_vision (msgs[random(sizeof(msgs))],me);


  
  return 1;
}


