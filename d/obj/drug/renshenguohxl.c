//Cracked by Roath

// renshen-guo.c �˲ι�
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void disappear(object me);


void create()
{
	set_name(HIW "�˲ι�" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "�װ����ֵ�һö�˲ι�����ǧ��һ��������ǧ��һ���������ǧ��ŵ��죬ʵ����ؼ���鱦��\n");
		set("value", 0);
		set("no_give",1);
		set("no_drop",1);
		set("no_put",1);
		set("no_get",1);
		set("drug_type", "��Ʒ");
	}
  
	set("is_monitored",1);
	setup();
}
void init()
{
	
        object me=this_object();
        add_action("do_eat","eat");
        if (!me->query("start_time"))
          {
           me->set("start_time",1);
           remove_call_out("disappear");
           call_out("disappear",180,me);
           return ;
          }
         return ;
}                  


int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	// mon 7/14/99
	// will have problem if eat in those rooms.
	if(environment(me)->query("alternative_die"))
	    return notify_fail("�㲻���������"+name()+"��\n");

	message_vision(HIW "$N���˲ι�������һ�����̲�ס���һ�����˲ι����˲ι����������˲ι��� \n˵���˷ܵö������˹�ȥ��\n" NOR, me);  

	me->unconcious();

	me->set("food", (int)me->max_food_capacity());

        if( howmany <= 100 ) me->add_maximum_force(20);
	if( howmany <= 100 ) me->add_maximum_mana(20);

	howmany = (int)me->query("rsg_eaten");
	me->set("rsg_eaten", howmany+1);
	me->set("obstacle/wuzhuang","done");

        //for live forever...
        if( me->query("rsg_eaten") >= 36 )
        {
                me->announce_live_forever( me->query("name")+"��ֲ�и�س��˲ι��������޳��˲����ֻأ��Ӵ����������⣬���������У��������������ˣ�" );
        }

	destruct(this_object());

	return 1;
}

void disappear(object me)
{
   if (!me) return ;
   message_vision("$NͻȻ������ﲻ����.:-(\n",me);
   destruct (me);
}
   
    
