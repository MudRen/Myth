//Cracked by Roath
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG "�������Ӹ�" NOR, ({"sanhua gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����Ʒ�ɳ������Ч��ҩƬ��\n");
                set("base_unit", "Ƭ");
                set("value", 5000);
                set("weight", 50);
                set("unit","Ƭ");
        }
	        set("no_sell",1);
        setup();
}
int init()
{
        add_action("do_eat", "apply");
}

int do_eat(string arg)
{
        object me=this_player();

        if(! arg || arg!="sanhua gao")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/sanhua") < 100)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }



        if ( !(me->query_condition("eyeill")) )
         {
                write("��û�е÷�ɳ�ۣ��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/sanhua", time());

        message_vision(HIW "$N" HIW "����һƬ" + name() +HIW "֮���۾�������ˡ�\n" NOR, me);

        me->apply_condition("eyeill", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
