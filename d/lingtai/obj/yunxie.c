// shoe.c
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("����", ({ "shoes" }) );
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", "һ˫ǧ��׵����ģ��ǵ�ʿ�ǵ�һ��װ����\n");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}


