//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��������", ({"cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long",
"�����ɫ��ëƤ�Ƴɣ����滹����һ����ߡ���\n");
                set("material", "cloth");
                set("unit", "��");
                set("value", 400);
                set("armor_prop/armor", 85);

        }
        setup();
}

