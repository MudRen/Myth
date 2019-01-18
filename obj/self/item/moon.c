// Created by aeddy@2002/12/05

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLINK HIW "����" NOR, ({ "moon", "yueliang" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "��յ����������ڶ����ǵĹ�â��ӳ���ɡ�\n" NOR);
               set("value", 10000);
		set("can_auction", 1);
		 set("unit", "��");
	}
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

       if ( !(b=present("winter snow",me)))
                return notify_fail(CYN"����ȱ "HIW"��Өѩ�� "NOR CYN"�޷��ϳ������顣\n"NOR);

       if ( !(c=present("five-needle",me)))
                return notify_fail(CYN"����ȱ "HIM"����֮�� "NOR CYN"�޷��ϳ������顣\n"NOR);

	if( item=new("/obj/self/item/tuzhu")){
		if( me->query_encumbrance() + item->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("��ĸ��ع��߲��ܺϲ���Ʒ��\n");
		destruct(b);
		destruct(c);

	item->move(me);
	me->start_busy(3);
	message_vision(WHT"$N�����е� "HIW"��Өѩ�� "HIM"����֮��"NOR WHT
	"��"HIW"����"NOR WHT"����һ��ֻ������ҫ��ϼ���ӹ�,��Ȼ�ϲ���һ�������顣\n"NOR,me);

        message("channel:rumor",
	WHT"��"HIR"С����Ϣ"NOR WHT"����˵��"+log_id(me)+"�ϳ���"HIY"������"NOR WHT"�ˣ�\n"NOR,users() );

	destruct(a);
	}
	return 1;
}


