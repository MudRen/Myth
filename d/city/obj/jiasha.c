#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"��������"NOR, ({ "jia sha", "cloth" }) );
        set("long","һ�����ӲӵĻ������ġ�");
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}

