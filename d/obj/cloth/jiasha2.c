//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;31m��[32m��[35m֯[33m��[37m��[36m��[m", ({"wucai jiasha", "jia sha"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long", "������������֮���ģ�\n");
                set("material", "cloth");
                set("no_drop",1);
                set("no_sell",1);
//                  set("value", 300);
                  set("value", 20000000);
                set("unit", "��");
                set("armor_prop/armor", 10);
        }
        setup();
}

int query_autoload() { return 1; }
