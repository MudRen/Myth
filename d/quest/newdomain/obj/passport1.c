#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"һ��ͨ��֤"NOR, ({ "passport I","passport" }) );
        set_weight(100);
                set("unit", "��");
                set("material", "paper");
                set("pass_level",1);
                set("long", "����һ�Ž�����������ͨ��֤��\n");
        setup();
}
