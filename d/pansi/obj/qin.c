// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;
void init();
int do_play(string arg);
void create()
{
  set_name(HIB "������" NOR, ({ "wuxian qin"})); 
  set_weight(10000);
  set("long","һ�ܹ�ɫ�����������,�����Ѿ����������ҡ�\n");
  set("unit", "��");
  setup();
}

void init ()
{
  add_action ("do_play", "play");
}

int do_play (string arg)
{
  object me, where;
  int sen_cost, gain;
  
//  object qin = this_object();
  string *msgs = ({
    "$N�����ָ�������Ღ��һ�£��������������ˡ�\n",
    "$N�Ღ��һ�����ң���ɫ糺졣\n",
    "$N������˼��������һ������Ĭ������\n",
    "$N�����٣�����ס�������¡�\n",
    "$N����ص����٣���ɫ�����\n",
    "$NС�ĵص������ң��͵͵س���������\n",
    "$N�߳��ߵ���һ���������ĳ���\n",
  });
  me = this_player();
  where=environment(me);
	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����ϥ�ϵ���\n");
    	if( me->is_busy() )
        		return notify_fail("������æ���أ������������µ���...\n");
   	if( me->is_fighting() )
        		return notify_fail("̫�����˰ɣ����ʱ������...\n");
	if( where->query("no_fight") )
			return notify_fail("�˴����˴���������\n");
	if( (int)me->query_skill("qin",1)<50 )
		return notify_fail("�������ò��˼������ң�Ҫʹ����ҵ�������������Ȼ���ջ�û���š�\n");
	if( (int)me->query_skill("qin",1)>100 )
		return notify_fail("��������Ѿ�¯���࣬����������϶�Ϊһ��\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("qin", 1)/5+(int)me->query("int")+1;
	me->improve_skill("qin", gain);
	message_vision (msgs[random(sizeof(msgs))],me);


  
  return 1;
}

