//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����֯������", ({"luo yi", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "һ�������������·���ʮ��ů�ͣ�\n");
                set("unit", "��");
                set("value", 200);
                set("armor_prop/armor", 5);

        }
        setup();
}

