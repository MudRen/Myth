// dymo.c ����ĥ

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "����ĥ" NOR, ({ "danyu mo", "mo" }));
        set_weight(1200);
        set_max_encumbrance(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ����ĥ�ɵ�С�룬��Ϊ���أ�������������ʵأ�������
����ҩ���Ի�ø��õ�Ч����\n");
                set("value", 20000);
                set("item_prop/medical", 100);
        }
}

int is_container() { return 1; }

int can_make_medicine() { return 1; }

