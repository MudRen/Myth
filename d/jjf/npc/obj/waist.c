#include <armor.h>

inherit WAIST;

void create()
{
        set_name("���ľ�", ({ "huxin jing", "mirror","huxinjing",  "jing", "huxin", "waist" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ���ͭ���Ļ��ľ���\n");
                set("material", "copper");
		set("value", 100);
                set("armor_prop/armor", 5);
        }
        setup();
}
