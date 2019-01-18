// Created by waiwai@2001/03/23
// ��Ҷ(Fallen leaves)
// [1;31m���ļ���ֹ���ĺ��ƶ�[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "��Ҷ" NOR, ({ "fallen leaves", "leaves", "fallen" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", "����һƬ���紵�����Ҷ��͸����Ȼ�����ˡ�\n");
		set("value", 100);
		set("des", 1);
		set("can_auction", 1);
    };
	set_temp("drop_msg", "Ʈ�䲻���ˣ�\n");//dropʱ�������Ϣ

	setup();
}

void init() 
{	
	if( this_player()==environment() )
	add_action("do_combine","combine"); 
}

int do_combine()
{
	object me, a, b, c, item;

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

       if ( !(b=present("magic jade",me)))
                return notify_fail(CYN"����ȱ "HIG"��֮��� "NOR CYN"�޷��ϳɻ����顣\n"NOR);

       if ( !(c=present("lan crystal",me)))
                return notify_fail(CYN"����ȱ "HIM"���� "NOR CYN"�޷��ϳɻ����顣\n"NOR);

	if( item=new("/obj/self/item/huozhu")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("��ĸ��ع��߲��ܺϲ���Ʒ��\n");
		destruct(b);
		destruct(c);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N�����е� "HIG"��֮��� "HIM"����"NOR WHT
	"��"NOR YEL"��Ҷ"NOR WHT"����һ��ֻ������ҫ��ϼ���ӹ�,��Ȼ�ϲ���һ�Ż����顣\n"NOR,me);
        message("channel:rumor",
	WHT"��"HIR"С����Ϣ"NOR WHT"����˵��"+log_id(me)+"�ϳ���"HIR"������"NOR WHT"�ˣ�\n"NOR,users() );

	destruct(a);
	}
	return 1;
}

