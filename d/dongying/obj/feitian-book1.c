// feitian-jian.c  ���콣
// Modified by Cody May.2001
// Write by Cody

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( MAG "����������" NOR , ({ "feitian book1","book1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long" ,HIG
        "����һ�����콣�ɵ���, ��糴彣����д�ġ�
       ����д�ŷ��콣��---����ƪ��\n "NOR,
        );
                set("value", 0);
                set("material", "paper");
        }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�����������ܸ��ˡ�\n");
                set("no_get", "����������������\n");
                set("no_put", "�������������ҷš�\n");
}
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,feitianlev,exp;

  if( !book->id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
  if(me->is_busy()) return notify_fail("������æ���أ����ǵȾ��������ٶ���ɣ�\n");
  if(me->is_fighting()) return notify_fail("����ĥǹ������������\n");
  if( (int)me->query_skill("feitian-jian",1)>50 )
    return notify_fail("���Ѿ��ѷ��콣�Ļ���ƪ��ȫ�����ˣ��ٶ�Ҳ�������㳤�����١�\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("feitian-jian", 1);
  if(exp*10 < feitianlev*feitianlev*feitianlev)
    return notify_fail("�����ѧ����������ô��Ҳû�á�\n");
  sen_cost=20+(40-(int)me->query_int())+(35-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("�����ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/5;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("feitian-jian", gain);

  message_vision("$N��ר�ĵ��ж�"+book->query("name")+"��\n", me);
  tell_object(me, "���ж����콣(����ƪ)�ļ��ɣ��ƺ��е��ĵá�\n");

  return 1;
}
