//Creat by aeddy@2001/03/22
//Last modified by aeddy@2001/04/18

#include <ansi.h>
inherit COMBINED_ITEM;
int do_eat(string);

void init()
{
      add_action("do_eat", "eat");
}

void create()
{
	set_name(HIM "����" NOR, ({ "hua ban","hua", "ban" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
          set("long", HIM"һƬ����ӣ�������ķ�ɫ�Ļ��꣡\n" NOR);
		set("base_unit", "Ƭ");
              set("unit", "Щ");
		set("value", 1);
		set("no_sell",1);
		set("no_put",1);
	       set("drug_type", "��Ʒ");
	}
       set_amount(1);
	setup();
}

int do_eat(string arg)
{
       object me = this_player();
	int howmany;

	howmany = (int)me->query("huaban_eaten");

	 if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        if (arg!="hua" && arg!="ban")	return 0;

        message_vision("$N������һƬ "HIM"ӣ������ \n"NOR, me);
        tell_object(me, HIG "����û���һ������֮����Ȼ����鼰ȫ��\n"NOR);
        me->set("huaban_eaten", howmany+1);

        if (me->query("per") >= 40) {
                message_vision(CYN"$N��Ȼ�����ۡ���������ǳ��Ŀ࣬����һ�ء�\n"NOR, me);
                     me->set("huaban_eaten", 0);
        } else 
        if( me->query("huaban_eaten") >= 200 ) {
                tell_object(me, HIR "����û���һ�ɻ�����Ȼ�����沿������������ࡣ\n"NOR);
                me->add("per", 1);
                me->set("huaban_eaten", 0);
         }

        add_amount(-1);
        return 1;
}

