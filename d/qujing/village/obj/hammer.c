//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("�˱�ͭ��", ({ "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ��ص�ͭ����������൱��ʵ��û��ǧ���������ò���ġ�\n");
                set("value", 1200);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(55);
        setup();
}

