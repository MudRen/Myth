#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�޺�����", ({"nihong yuyi", "yuyi", "skirt"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long",
"һ���ɼ�������ëһƬƬ�Ĵ��ɵ����ѣ��ڵ���ӥë���׵������ᣬ\n
�³���ϥ����֪���˼�ǧ���������ÿ����ë�ĸ���������һ��ϸ\n
�ף�����ͷ���ϵĽ��δ̳������д��˵��Ƶ�˿�ߡ�\n");
                set("value", 3000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
		set("armor_prop/dodge", 20);
                set("armor_prop/personality", 3);
                set("female_only", 1);
             }
        setup();
}

