//��ﵡ���¾��junhyunר�ã�
//by junhyun@SK
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIW"��ﵡ���¾"NOR, ({ "shen mace","mace","mace" }) );
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
                set("long", HIC"ħ���˽ܼ�֮һ����ﵡ���¾\n"NOR);
                set("wield_msg", HIY"$N����һ�ӣ������Զ���һ������������ﵣ�\n");
        //      set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
   init_blade(200);
        setup();
}

