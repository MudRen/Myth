//Cracked by Roath

// renshen-guo.c �˲ι�
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "�˲ι�" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "�װ����ֵ�һö�˲ι�����ǧ��һ��������ǧ��һ���������ǧ��ŵ��죬ʵ����ؼ���鱦��\n");
                set("value", 4000);
		set("drug_type", "��Ʒ");
            set("fake",1);
	}
  
        set("no_sell",1);
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

    if( me->query("sen")<100) return notify_fail("���޾���ɵ����ʲô��\n");
         me->add("sen",50);
	if(environment(me)->query("alternative_die"))
	    return notify_fail("�㲻���������"+name()+"��\n");

	message_vision(HIW "$N���˲ι�������һ�����̲�ס���һ�����˲ι����˲ι����������˲ι��� \n˵���˷ܵö�������������\n" NOR, me);  	

//������Ӧ����ʧ�������һֱ��"sen",�����ͳ��� bug��   modified by seng@2005-1-26
      destruct(this_object()); 
         return 1;
}

