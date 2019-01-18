#include <weapon.h>

inherit HAMMER;
int do_read(string arg);

void create()
{
        set_name("�˰�÷����", ({ "meihua hammer", "hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѷְ˰��÷��״��ͭ�����������Щ��׭��\n");
                set("value", 5000);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(60);
        setup();
}

void init()
{
 object me = this_object();
  object where = environment();

  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
	me->set("transferred", 1);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }

        add_action("do_read", "read");
}

int do_read(string arg)
{	int gain;
	object me=this_player();
	object ob=this_object();
	
	if(! ob->query("OK_to_STUDY"))
		return notify_fail("���޷�������������ѧ���κζ�����\n");
	if( ob->query("transferred"))
		return notify_fail("���޷�������������ѧ���κζ�����\n");
    	if(environment(me)->query("no_fight") || 
       	environment(me)->query("no_magic") )
          return notify_fail("��ȫ���ڽ�ֹ������\n");

	if( (int)me->query_skill("hammer", 1) >= 60)
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˡ�\n");
	if( (int)me->query_skill("spells", 1) < 20)
		return notify_fail("�������㷨���������޷��������ķ��䡣\n");

	if( (int)me->query_skill("spells", 1) < (int)me->query_skill("hammer", 1) )
		return notify_fail("�������㷨����ỹ�����ʱ�����򲻳�����һ��Ĵ�����\n");

	if( (int)me->query("kee") < 30)
		return notify_fail("��̫���ˣ�ЪЪ�����ɡ�\n");
	if( (int)me->query("sen") < 30)
		return notify_fail("��̫ƣ���ˣ�ЪЪ�����ɡ�\n");

	gain= (int)me->query_skill("spells", 1)/3 + 1 + random((int)me->query_int());

	me->improve_skill("hammer", gain);
	me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

	write("�����洧Ħ�Ű˰�÷�����ϵ�������Ӱ���ƺ��ԡ������������������˽⡣\n");
	tell_room( environment(me), me->name() +"˫�۶��Ű˰�÷���������ﻹ��֪�ڱȻ�ʲô��\n", ({me}));
	return 1;
}

