//modifyed by stey steywen@21cn.com
// shuijingxie.c

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name("ˮ��Ь", ({"shuijing xie"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "˫");
                set("armor_prop/armor", 1);
        }
        setup();
}

