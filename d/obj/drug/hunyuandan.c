// hunyuandan.c ��Ԫ�� 
#include <ansi.h>

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(YEL"��Ԫ��"NOR, ({"hunyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("base_unit", "��");
                set("long", "һ���Դ�������ҩ�裮\n");
set("value", 600);
                                set("drug_type", "��ҩ");
        }
     set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        else {
                this_player()->receive_curing("sen", 40);
                message_vision("$N����һ�Ż�Ԫ������ɫ�������ö��ˣ�\n",
this_player());
         add_amount(-1);
                return 1;
        }
}
