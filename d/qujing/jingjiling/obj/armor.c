#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("�����ȼ�", ({"smoky armor","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long", "һ��Ů�Ӵ��ĺ�ɫ��ס�\n");
                set("value", 8000);
                set("material", "wood");
                set("armor_prop/armor", 25);
		set("armor_prop/personality", 3);
		set("armor_prop/dodge", 5);
		set("female_only", 1);
             }
                         setup();
}

