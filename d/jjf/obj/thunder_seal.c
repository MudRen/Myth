#include <skill.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�����׷���", ({"thunder seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","һ�Ż����˷�����ҷ�ֽ�������и����ġ��ס��֡�\n");
        set("unit", "��");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N���е�$nͻ����⣬���佥����ȥ�����ˡ�\n",where,me);
        destruct(me);
}

void invocation(object who)
{
	int i,a,b,c;
	
	a=who->query("combat_exp");
	b=(int)who->query_skill("spells")*(int)who->query_skill("spells");
	c=(int)who->query("mana_factor")*(int)who->query("mana_factor")*(int)who->query("mana_factor");
	i=a+b+c;

	this_object()->set("ap",i);
	return;
}
// modify by bird
int shot_ob(object victim)
{
	object seal=this_object();
	object me=this_player();
	object where=environment(me);

        int success_adj, damage_adj;
	success_adj = 75;
	damage_adj = 75;

	if(me->is_busy())
		return notify_fail("����æ���أ��޷��������׷�����\n");
	if( !victim)
		return notify_fail("��������˲������\n");
	if( where->query("no_magic"))
		return notify_fail("���ﲻ�ܼ������׷�����\n");
	if( !me->is_fighting())
		return notify_fail("ֻ��ս���в��ܼ������׷�����\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ������ܿ��������׷�����\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬���Ѽ�Ԧ�����׷�����\n");

        me->add("mana", -50);
	SPELL_D->attacking_cast(
		me, 
			//attacker 
		victim, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "\n$N��һ�����š�����һ�ӣ�������һ�������׷�����\n�����׷�����������һ�·ɵ���գ�ֻ������ͻ�䣬����������$n����է��\n" NOR,
			//initial message
		HIR "\n$n�����������ð���ǣ����񲻶����������ڵأ�\n" NOR, 
			//success message
		HIC "\n˭֪$n���޷�Ӧ��\n" NOR, 
			//fail message
		HIC "����$n��ָһ�������������������׷�������$N��ȥ��\n" NOR, 
			//backfire initial message
		HIR "����ˣ���һ�������׷�����$n��������������\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

        me->start_busy(2+random(2));
	destruct(seal);  
	return 1;
}

int shot (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+name+"��\n");

  victim=present(target,environment(me));
   seal->shot_ob(victim);
  return 1;
}

