// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "blade" }) );
   set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"һ�Ѵ󿳵���\n");
                set("unit", "��");
                set("value", 1000);
        }
        init_blade(20);
        setup();
}

