inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"��"HIC"��"HIY"��"HIG"�"NOR, ({"chan"}));
        set("unit", "ֻ");
        set("value", 100000);
        set("long", "����һǧ���ѵ�һ�����쾦���, ͨ��͸��,
Ω�۳ʳ�ɫ, �ܽ�ٶ���\n");
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if(arg=="chan") 
        {
                message_vision(HIG"$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me);
                if (me->query_condition("drunk"))
                        me->apply_condition("drunk",0);
                if (me->query_condition("flower"))
                        me->apply_condition("flower",0);
                if (me->query_condition("ice_poison"))
                        me->apply_condition("ice_poison",0);
                if (me->query_condition("bat_poison"))
                        me->apply_condition("bat_poison",0);
                if (me->query_condition("rose_poison"))
                        me->apply_condition("rose_poison",0);
                if (me->query_condition("bp_poison"))
                        me->apply_condition("bp_poison",0);
                if (me->query_condition("chuanchang_poison"))
                        me->apply_condition("chuanchang_poison",0);
                if (me->query_condition("double_ice_poison"))
                        me->apply_condition("double_ice_poison",0);
                if (me->query_condition("snake_poison"))
                        me->apply_condition("snake_poison",0);
                if (me->query_condition("hell_zhua"))
                        me->apply_condition("hell_zhua",0);
                if (me->query_condition("moon_poison"))
                        me->apply_condition("moon_poison",0);
                if (me->query_condition("zhizhu_poison"))
                        me->apply_condition("zhizhu_poison",0);
                if (me->query_condition("zhushang"))
                        me->apply_condition("zhushang",0);
                if (me->query_condition("xiangsi"))
                        me->apply_condition("xiangsi",0);
                if (me->query_condition("ziwuliuzhu_poison"))
                        me->apply_condition("ziwuliuzhu_poison",0);
                destruct(this_object());
        }
        me->start_busy(2);
        return 1;
}

