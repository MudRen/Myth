// shoeshine.c Ь��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "Ь��" NOR, ({"shoeshine", "xie you"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "֧");
                set("value", 90);
        }
        set("count", 10);
        setup();
}

string long()
{
        int c;

        c = query("count");
        if (c < 1)
        {
                set("count", 1);
                c = 1;
        }

        return "����һ��Ь�ͣ�����ȥ������" + chinese_number(c) + "�Ρ�\n";
}

void cost()
{
        if (add("count", -1) < 1)
        {
                message_vision("$N��$n�����ˣ������ӵ���һ�ߡ�\n",
                               this_player(), this_object());
                destruct(this_object());
        }
}


