//Cracked by Roath
// parrybook2.c,level 100-140
// by pickle
inherit ITEM;

void create()
{
  set_name("�����ֲ����ؾ���", ({"mi jue", "parry book", "mijue", "book", "shu", "jue","parry"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "
����ɮ�����Ƴ�ս���������˲���ս����Ҳ�в���������
ս���У��������ֵ��书����Ҳ�����ʧ���⡣�Ȿ����
�ؾ���˵��ξ�ٹ����ȵ�һλ���ָ�ɮ�������ġ�\n");
    set("material", "paper");
    set("value", 0);
  }
}

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
    set("no_drop",1);
    set("no_sell",1);
    set("no_give",1);
  }
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,lev,exp;

  if( !book->id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
  if( environment(book)!=me ) return notify_fail("��Ҫ����������\n");
  if(me->is_busy()) return notify_fail("������æ���أ����ǵȾ��������ٶ���ɣ�\n");
  if(me->is_fighting()) return notify_fail("����ĥǹ������������\n");
  if( (int)me->query_skill("parry",1)<100 )
    return notify_fail("����������ϸ���˰��죬����ôҲ��������\n");
  if( (int)me->query_skill("parry",1)>140 )
    return notify_fail("�����ⷽ���Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");
  exp=(int)me->query("combat_exp");
  lev=(int)me->query_skill("parry", 1);
  if(exp*10 < lev*lev*lev)
    return notify_fail("��ĵ��в���������ô��Ҳû�á�\n");
  sen_cost=10+(40-(int)me->query_int())+(35-(int)me->query_kar())+(int)lev/5;
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate",1)/5;
  gain -= random(me->query_int());
  gain +=random(me->query_kar());
  if(gain < 0) gain=0;
  me->improve_skill("parry", gain);

  message_vision("$N��ר�ĵ��ж�"+book->query("name")+"��\n", me);
  tell_object(me, "���ж��йز���ж��֮���ļ��ɣ��ƺ��е��ĵá�\n");

  return 1;
}





