// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <armor.h>

inherit CLOTH;

void create()
{
          set_name("��������", ({"jinshan"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}


