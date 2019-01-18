// forcebook2, level 100-140

inherit ITEM;
void init();

void create()
{
  set_name("����ħɽ�ľ���", ({"fumo book", "fumo", "book", "forcebook", "shu", "xinjing"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���Ͳ�Ƥ��С���ӣ�ǰһ��ȴ��֪ʲôԭ�򱻳����ˡ�\n");
    set("material", "cloth");
      set("value", 0);
    set("value", 500000);
      set("no_paimai", 1);
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
  int sen_cost, gain,forcelev,exp;

  if( !book->id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
  if( environment(book)!=me ) return notify_fail("��Ҫ����������\n");
  if(me->is_busy()) return notify_fail("������æ���أ����ǵȾ��������ٶ���ɣ�\n");
  if(me->is_fighting()) return notify_fail("����ĥǹ������������\n");
  if( (int)me->query_skill("force",1)<100 )
    return notify_fail("����������ϸ���˰��죬����ôҲ��������\n");
  if( (int)me->query_skill("force",1)>140 )
    return notify_fail("�����ⷽ���Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");
  exp=(int)me->query("combat_exp");
  forcelev=(int)me->query_skill("force", 1);
  if(exp*10 < forcelev*forcelev*forcelev)
    return notify_fail("��ĵ��в���������ô��Ҳû�á�\n");
  sen_cost=20+(40-(int)me->query_int())+(35-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/5;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("force", gain);

  message_vision("$N��ר�ĵ��ж�"+book->query("name")+"��\n", me);
  tell_object(me, "���ж��й��ڹ��ķ��ļ��ɣ��ƺ��е��ĵá�\n");

  return 1;
}

