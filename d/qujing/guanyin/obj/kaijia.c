// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tongjia.c
#include <armor.h>

inherit ARMOR;

void create()
{
          set_name("�ڽ�����", ({"gold armor","jia","armor"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
         set("long", "һ����Ӳӵ��ڽ����ס�\n");
                set("value", 5000);
                set("material", "steel");
                set("armor_prop/armor", 45);
     set("armor_prop/dodge", -15);
             }
         setup();
}

