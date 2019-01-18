// Created by waiwai@2001/03/23

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "��ɫ��ʯ" NOR, ({ "cyan stone", "stone" }) );
	set_weight( 10000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɫ����ʯ�����溬��һЩϡ�е����ʣ�����������(combine)��\n");
		set("value", 100);
		set("can_auction", 1);
    };
}

void init() 
{	
	if( this_player()==environment() )
	add_action("do_combine","combine"); 
}

int do_combine()
{
	object me, a, b, c, d, e, f, g, item;

	me=this_player();
	a=this_object();

	if( !wizardp(me) && userp(me) ) {
       if(!environment(me)->query("cold"))
             return notify_fail("�˵������������޷��ϲ���Ʒ��\n");

	if( (int)me->query("force") < (int)me->query("max_force") )
		return notify_fail("����������㣬���ѽ���Ʒ�ϲ���\n");

	if( (int)me->query("mana") < (int)me->query("max_mana") )
		return notify_fail("��ķ���������֧�ֺϲ���Ʒ��\n");
       }

       if ( !(b=present("blue stone",me)))
                return notify_fail(CYN"�㽫���� "HIC"��ɫ��ʯ "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(c=present("green stone",me)))
                return notify_fail(CYN"�㽫���� "HIC"��ɫ��ʯ "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(d=present("magenta stone",me)))
                return notify_fail(CYN"�㽫���� "HIC"��ɫ��ʯ "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(e=present("red stone",me)))
                return notify_fail(CYN"�㽫���� "HIC"��ɫ��ʯ "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(f=present("silver stone",me)))
                return notify_fail(CYN"�㽫���� "HIC"��ɫ��ʯ "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(g=present("gold stone",me)))
                return notify_fail(CYN"�㽫���� "HIC"��ɫ��ʯ "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

	if( item=new("/obj/self/item/7stone")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("��ĸ��ع��߲��ܺϲ���Ʒ��\n");
		destruct(b);
		destruct(c);
		destruct(d);
		destruct(e);
		destruct(f);
		destruct(g);

	item->move(me);
//	me->save();
	me->start_busy(3);
	message_vision(WHT"$N�����е��߿���ɫ����ʯ����һ��ֻ������ҫ��ϼ���ӹ�,��Ȼ�ϲ���һ����ɫ��ʯ��\n"NOR,me);

	destruct(a);
	}
	return 1;
}
