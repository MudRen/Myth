#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("սѥ", ({ "zhan xue","xue", "feet", "zhanxue", "boots" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long",
"һ˫Ƥѥ���ϵ�ţƤ�Ƴɡ�ѥ����ܽ�ʵ��������ս��ʱ���ǳ��������á�\n");
                set("value", 800);
                set("material", "leather");
                set("armor_prop/armor", 5);
        }
        setup();
}
