#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("��", ({"jin dao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѽ��������Բͷ��������������Ƕ�а���\n");
                set("value", 2500);
                set("material", "gold");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У����������\n");
                set("unwield_msg", "$N�����е�$n�����ɫ���ʡ�\n");
        set("weapon_prop/courage", 15);
			set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
				set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
				set("no_get","�����ܹ�һҶ֪�﷢��װ�������ΰ�!\n");

        }
        init_blade(50);
        setup();
}

