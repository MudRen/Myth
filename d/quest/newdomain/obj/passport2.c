#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"����ͨ��֤"NOR, ({ "passport II","passport" }) );
        set_weight(100);
                set("unit", "��");
                set("material", "paper");
                set("pass_level",2);
                set("long", "����һ�Ž���ħ�������ͨ��֤��\n");
        setup();
}
