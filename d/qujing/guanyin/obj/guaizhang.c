// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hammer.c

#include <weapon.h>

inherit STAFF;

void create()
{
          set_name("����", ({"staff", "zhang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                 set("long", "����һ����̴ľ���ɵ����ȣ�\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(25);
        setup();
}

