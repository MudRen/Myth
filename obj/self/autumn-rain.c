// Created by waiwai@2001/03/23
// ��֮ɪ��(autumn-rain)
// [1;31m���ļ���ֹ���ĺ��ƶ�[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "��֮ɪ��" NOR, ({ "autumn rain", "autumn", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ξ�Ө����֮ɪ�����Ρ�\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // dropʱ��ʧ��־
		set("material", "water");//ˮ�������־
    };
	// dropʱ���ض������Ϣ
	set_temp("drop_msg", this_object()->query("name")+CYN" �����ţ���ʧ�ڿ����в����ˡ�����\n"NOR);

	setup();
}

void init() 
{	
	if( this_player()==environment() )
	add_action("do_combine","combine"); 
}

int do_combine()
{
	object me, a, b, c, d, item;

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

       if ( !(b=present("summer rain",me)))
                return notify_fail(CYN"�㽫���� "HIY"��֮ɪ�� "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(c=present("spring rain",me)))
                return notify_fail(CYN"�㽫���� "HIY"��֮ɪ�� "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

       if ( !(d=present("winter rain",me)))
                return notify_fail(CYN"�㽫���� "HIY"��֮ɪ�� "NOR CYN"��Ū�˼��£�ȴһ�㷴ӦҲû�С�\n"NOR);

	if( item=new("/obj/self/item/4season")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("��ĸ��ع��߲��ܺϲ���Ʒ��\n");
		destruct(b);
		destruct(c);
		destruct(d);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N�����е��ĵ�����ں���һ��ֻ������ҫ��ϼ���ӹ�,��Ȼ�ϲ���һ���ļ����顣\n"NOR,me);

	destruct(a);
	}
	return 1;
}

