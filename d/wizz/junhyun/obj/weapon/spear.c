//��ǹ�����㣨junhyunר�ã�
//by junhyun@SK
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIW"��ǹ����Ӱ"NOR, ({ "yao qiang","qiang","spear" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "wood");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("long", HIC"ħ���˽ܼ�֮һ����ǹ������\n"NOR);
                set("wield_msg", HIY"$N����һ�ӣ������Զ���һ������������ǹ��\n");
        //      set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
   init_spear(200);
        setup();
}

