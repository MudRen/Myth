#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"����ͨ��֤"NOR, ({ "passport III","passport" }) );
        set_weight(100);
                set("unit", "��");
                set("material", "paper");
                set("pass_level",3);
                set("long", "����һ�Ž����������̽�ܵ�ͨ��֤��\n");
        setup();
}
