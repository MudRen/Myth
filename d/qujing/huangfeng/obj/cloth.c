//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "Ƥ��", ({ "pi yi", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long", "һ������Ƥ�Ƴɵ��·���\n");
                set("unit", "��");
                set("value", 400);
                set("material", "leather");
                set("armor_prop/armor", 6);
        }
        setup();
}

