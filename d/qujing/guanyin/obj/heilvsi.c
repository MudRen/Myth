// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
inherit HEAD;

void create()
{
          set_name("����˿", ({ "heilu si", "si" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
       set("long", "һ����˿����˿�Ƴɵ�˿��������������\n");
                set("value", 300);
                set("material", "cloth");
                set("armor_prop/armor", 1);
     set("armor_prop/personality", 1);
        }
        setup();
}

