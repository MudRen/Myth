#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("������", ({"baipao", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",
"һ����ɫ�Ĵֲ��ۣ���Ȼ�ʵĲ����ã����ü���ϸ�����������з��ˣ�\n");
                set("material", "cloth");
                set("unit", "��");
                set("value", 400);
                set("armor_prop/armor", 15);

        }
        setup();
}

